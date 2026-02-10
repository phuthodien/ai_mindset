// SPDX-License-Identifier: GPL-2.0
/*
 * gpio_led.c - Misc driver điều khiển LED trên GPIO0_31 (AM335x/BBB)
 *
 * Truy cập trực tiếp GPIO registers (không dùng GPIO subsystem)
 * để minh họa cách đọc tài liệu TRM và lập trình bare-metal GPIO.
 *
 * Sử dụng:
 *   echo 1 > /dev/gpio_led   # bật LED
 *   echo 0 > /dev/gpio_led   # tắt LED
 *   cat /dev/gpio_led         # đọc trạng thái
 */

#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/io.h>
#include <linux/uaccess.h>

/* AM335x GPIO0 registers - TI SPRUH73Q, Chapter 25 */
#define GPIO0_BASE		0x44E07000
#define GPIO0_SIZE		0x1000

#define GPIO_OE			0x134
#define GPIO_DATAOUT		0x13C
#define GPIO_CLEARDATAOUT	0x190
#define GPIO_SETDATAOUT		0x194

/* AM335x CM_WKUP registers - TI SPRUH73Q, Chapter 8 */
#define CM_WKUP_BASE		0x44E00400
#define CM_WKUP_SIZE		0x100
#define CM_WKUP_GPIO0_CLKCTRL	0x08

#define MODULEMODE_ENABLE	0x02

/* LED nằm trên GPIO0 pin 31 */
#define LED_PIN			31
#define LED_BIT			(1 << LED_PIN)

static void __iomem *gpio0_base;
static void __iomem *cm_wkup_base;

static void gpio_led_set(int on)
{
	if (on)
		writel(LED_BIT, gpio0_base + GPIO_SETDATAOUT);
	else
		writel(LED_BIT, gpio0_base + GPIO_CLEARDATAOUT);
}

static int gpio_led_get(void)
{
	return !!(readl(gpio0_base + GPIO_DATAOUT) & LED_BIT);
}

static ssize_t gpio_led_write(struct file *file, const char __user *buf,
			      size_t count, loff_t *ppos)
{
	char ch;

	if (count == 0)
		return 0;

	if (get_user(ch, buf))
		return -EFAULT;

	if (ch == '1')
		gpio_led_set(1);
	else if (ch == '0')
		gpio_led_set(0);
	else
		return -EINVAL;

	return count;
}

static ssize_t gpio_led_read(struct file *file, char __user *buf,
			     size_t count, loff_t *ppos)
{
	char status;

	if (*ppos > 0)
		return 0;

	status = gpio_led_get() ? '1' : '0';

	if (put_user(status, buf))
		return -EFAULT;

	*ppos += 1;
	return 1;
}

static const struct file_operations gpio_led_fops = {
	.owner	= THIS_MODULE,
	.read	= gpio_led_read,
	.write	= gpio_led_write,
};

static struct miscdevice gpio_led_misc = {
	.minor	= MISC_DYNAMIC_MINOR,
	.name	= "gpio_led",
	.fops	= &gpio_led_fops,
};

static int gpio_led_hw_init(void)
{
	u32 val;

	cm_wkup_base = ioremap(CM_WKUP_BASE, CM_WKUP_SIZE);
	if (!cm_wkup_base)
		return -ENOMEM;

	/* Enable GPIO0 clock: MODULEMODE = 0x2 (ENABLE) */
	val = readl(cm_wkup_base + CM_WKUP_GPIO0_CLKCTRL);
	val &= ~0x3;
	val |= MODULEMODE_ENABLE;
	writel(val, cm_wkup_base + CM_WKUP_GPIO0_CLKCTRL);

	gpio0_base = ioremap(GPIO0_BASE, GPIO0_SIZE);
	if (!gpio0_base) {
		iounmap(cm_wkup_base);
		return -ENOMEM;
	}

	/* Cấu hình pin 31 thành output: clear bit 31 trong GPIO_OE */
	val = readl(gpio0_base + GPIO_OE);
	val &= ~LED_BIT;
	writel(val, gpio0_base + GPIO_OE);

	/* Tắt LED ban đầu */
	gpio_led_set(0);

	return 0;
}

static void gpio_led_hw_cleanup(void)
{
	/* Tắt LED trước khi unload */
	gpio_led_set(0);

	/* Trả pin về input mode */
	u32 val = readl(gpio0_base + GPIO_OE);

	val |= LED_BIT;
	writel(val, gpio0_base + GPIO_OE);

	iounmap(gpio0_base);
	iounmap(cm_wkup_base);
}

static int __init gpio_led_init(void)
{
	int ret;

	ret = gpio_led_hw_init();
	if (ret) {
		pr_err("gpio_led: hardware init failed (%d)\n", ret);
		return ret;
	}

	ret = misc_register(&gpio_led_misc);
	if (ret) {
		pr_err("gpio_led: misc_register failed (%d)\n", ret);
		gpio_led_hw_cleanup();
		return ret;
	}

	pr_info("gpio_led: registered /dev/gpio_led (GPIO0_%d)\n", LED_PIN);
	return 0;
}

static void __exit gpio_led_exit(void)
{
	misc_deregister(&gpio_led_misc);
	gpio_led_hw_cleanup();
	pr_info("gpio_led: unregistered\n");
}

module_init(gpio_led_init);
module_exit(gpio_led_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ai_mindset");
MODULE_DESCRIPTION("Misc driver for GPIO0_31 LED on BeagleBone Black");
