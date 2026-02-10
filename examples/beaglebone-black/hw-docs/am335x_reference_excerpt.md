# AM335x Technical Reference Manual (Excerpt)
**TI SPRUH73Q - October 2011 - Revised December 2019**

Tài liệu này trích xuất một số chương từ AM335x Technical Reference Manual — sử dụng cho mục đích training AI.

---

## Mục lục

### 1. [Memory Map](#21-arm-cortex-a8-memory-map)
- [2.1 ARM Cortex-A8 Memory Map](#21-arm-cortex-a8-memory-map)
- [2.2 L4_WKUP Peripheral Memory Map](#22-l4_wkup-peripheral-memory-map)
- [2.3 L4_PER Peripheral Memory Map](#23-l4_per-peripheral-memory-map)
- [2.4 L4_FAST Peripheral Memory Map](#24-l4_fast-peripheral-memory-map)

### 2. [Chapter 6: Interrupt Controller (INTC)](#chapter-6-am335x-interrupt-controller-intc)
- [6.1 Mô tả chức năng](#61-mô-tả-chức-năng)
- [6.2 Basic Programming Model](#62-basic-programming-model)
- [6.3 ARM Cortex-A8 Interrupts](#63-arm-cortex-a8-interrupts)
- [6.4 Crypto DMA Events](#64-crypto-dma-events)
- [6.5 PWM Events](#65-pwm-events)
- [6.6 INTC Registers](#66-intc-registers)

### 3. [Chapter 8: Power, Reset, and Clock Management (PRCM)](#am335x-power-reset-and-clock-management-prcm)
- [8.1 Introduction](#81-introduction)
- [8.2 Device Power-Management Architecture Building Blocks](#82-device-power-management-architecture-building-blocks)
- [8.3 Clock Management](#83-clock-management)
- [8.4 Power Management](#84-power-management)
- [8.5 Power Modes](#85-power-modes)
- [8.6 Wakeup Management](#86-wakeup-management)
- [8.7 Power Management Sequencing with Cortex-M3](#87-power-management-sequencing-with-cortex-m3)
- [8.8 PRCM Module Overview](#88-prcm-module-overview)
- [8.9 Clock Generation and Management](#89-clock-generation-and-management)
- [8.11 Clock Module Registers](#811-clock-module-registers)
- [8.12 Power Management Registers](#812-power-management-registers)

### 4. [Chapter 20: DMTimer (Dual-Mode Timer)](#am335x-dmtimer-dual-mode-timer)
- [20.1 Introduction](#201-introduction)
- [20.2 Functional Modes](#202-functional-modes)
- [20.3 Clock and Reset Management](#203-clock-and-reset-management)
- [20.4 Register Access](#204-register-access)
- [20.5 Timer Registers](#205-timer-registers)
- [20.6 Programming Sequences](#206-programming-sequences)

### 5. [Chapter 25: General-Purpose Input/Output (GPIO)](#chapter-25-general-purpose-inputoutput-gpio)
- [25.1 Introduction](#251-introduction)
- [25.2 Integration](#252-integration)
- [25.3 Functional Description](#253-functional-description)
- [25.4 GPIO Registers](#254-gpio-registers)

### 6. [Chapter 26: ROM Code](#chapter-26-rom-code)
- [26.1.1 Device Types](#2611-device-types)
- [26.1.2 Architecture](#2612-architecture)
- [26.1.3 Functionality](#2613-functionality)
- [26.1.4 Memory Map](#2614-memory-map)
- [26.1.5 Start-up and Configuration](#2615-start-up-and-configuration)
- [26.1.6 Booting](#2616-booting)
- [26.1.7 Fast External Booting](#2617-fast-external-booting)
- [26.1.8 Memory Booting](#2618-memory-booting)
- [26.1.9 Peripheral Booting](#2619-peripheral-booting)
- [26.1.10 Image Format](#26110-image-format)
- [26.1.12 Authentication and Code Execution](#26112-authentication-and-code-execution)
- [26.1.13 Wakeup](#26113-wakeup)
- [26.1.14 Tracing](#26114-tracing)

---

## 2.1 ARM Cortex-A8 Memory Map

### Table 2-1: L3 Memory Map

| Block Name | Start Address (hex) | End Address (hex) | Size | Description |
|-----------|-------------------|------------------|------|-------------|
| GPMC (External Memory) | 0x0000_0000 | 0x1FFF_FFFF | 512MB | 8/16-bit External Memory (EXRAM) |
| Reserved | 0x2000_0000 | 0x3FFF_FFFF | 512MB | Reserved |
| Boot ROM | 0x4000_0000 | 0x4001_FFFF | 128KB | Boot ROM |
| Reserved | 0x4002_0000 | 0x4002_BFFF | 48KB | 32-bit EXRAM - Public |
| Reserved | 0x4002_C000 | 0x400F_FFFF | 848KB | Reserved |
| Reserved | 0x4010_0000 | 0x401F_FFFF | 1MB | Reserved |
| Reserved | 0x4020_0000 | 0x402E_FFFF | 960KB | Reserved |
| Reserved | 0x402F_0000 | 0x402F_03FF | 64KB | Reserved |
| SRAM Internal | 0x402F_0400 | 0x402F_FFFF | - | 32-bit EXRAM |
| L3 OCMC0 | 0x4030_0000 | 0x4030_FFFF | 64KB | 32-bit EXRAM OCMC SRAM |
| Reserved | 0x4031_0000 | 0x403F_FFFF | 960KB | Reserved |
| Reserved | 0x4040_0000 | 0x404F_FFFF | 128KB | Reserved |
| Reserved | 0x4042_0000 | 0x404F_FFFF | 896KB | Reserved |
| Reserved | 0x4050_0000 | 0x405F_FFFF | 1MB | Reserved |
| Reserved | 0x4060_0000 | 0x407F_FFFF | 2MB | Reserved |
| Reserved | 0x4080_0000 | 0x408B_FFFF | 256KB | Reserved |
| Reserved | 0x4084_0000 | 0x40DF_FFFF | 5888KB | Reserved |
| Reserved | 0x40E0_0000 | 0x40E0_7FFF | 32KB | Reserved |
| Reserved | 0x40E0_8000 | 0x40EF_FFFF | 992KB | Reserved |
| Reserved | 0x40F0_0000 | 0x40F0_7FFF | 32KB | Reserved |
| Reserved | 0x4010_8000 | 0x40FF_FFFF | 992KB | Reserved |
| Reserved | 0x4100_0000 | 0x41FF_FFFF | 16MB | Reserved |
| Reserved | 0x4200_0000 | 0x43FF_FFFF | 32MB | Reserved |
| L3F Fast configuration registers | 0x4400_0000 | 0x443F_FFFF | 4MB | L3Fast configuration registers |
| Reserved | 0x4440_0000 | 0x447F_FFFF | 4MB | Reserved |
| L3S Slow Regs | 0x4480_0000 | 0x44BF_FFFF | 4MB | L3Slow configuration registers |
| L4_WKUP | 0x44C0_0000 | 0x44FF_FFFF | 4MB | L4_WKUP |
| Reserved | 0x4500_0000 | 0x45FF_FFFF | 16MB | Reserved |
| MCASP0 Data | 0x4600_0000 | 0x463F_FFFF | 4MB | MCASP0 Data Registers |
| MCASP1 Data | 0x4640_0000 | 0x467F_FFFF | 4MB | MCASP1 Data Registers |
| Reserved | 0x4680_0000 | 0x46FF_FFFF | 8MB | Reserved |
| Reserved | 0x4700_0000 | 0x473F_FFFF | 4MB | Reserved |

### Table 2-1: L3 Memory Map (continued)

| Block Name | Start Address (hex) | End Address (hex) | Size | Description |
|-----------|-------------------|------------------|------|-------------|
| USBSS | 0x4740_0000 | 0x4740_0FFF | 2KB | USB Subsystem Registers |
| USB0 | 0x4740_1000 | 0x4740_12FF | - | USB0 Controller Registers |
| USB0_PHY | 0x4740_1300 | 0x4740_13FF | - | USB0 PHY Registers |
| USB0 Core | 0x4740_1400 | 0x4740_17FF | - | USB0 Core Registers |
| USB1 | 0x4740_1800 | 0x4740_1AFF | - | USB1 Controller Registers |
| USB1_PHY | 0x4740_1B00 | 0x4740_1BFF | - | USB1 PHY Registers |
| USB1 Core | 0x4740_1C00 | 0x4740_1FFF | - | USB1 Core Registers |
| USB CPPI DMA Controller | 0x4740_2000 | 0x4740_2FFF | - | USB CPPI DMA Controller Registers |
| USB CPPI DMA Scheduler | 0x4740_3000 | 0x4740_3FFF | - | USB CPPI DMA Scheduler Registers |
| USB Queue Manager | 0x4740_4000 | 0x4740_7FFF | - | USB Queue Manager Registers |
| Reserved | 0x4740_8000 | 0x477F_FFFF | 4MB-32KB | Reserved |
| Reserved | 0x4780_0000 | 0x478D_FFFF | 64KB | Reserved |
| MMCHS2 | 0x4781_0000 | 0x4781_FFFF | 64KB | MMCHS2 |
| Reserved | 0x4782_0000 | 0x478F_FFFF | 4MB-128KB | Reserved |
| Reserved | 0x47C0_0000 | 0x47FF_FFFF | 4MB | Reserved |
| L4 PER | 0x4800_0000 | 0x48FF_FFFF | 16MB | L4 Peripheral (see L4_PER table) |
| TPCC (EDMA3CC) | 0x4900_0000 | 0x490F_FFFF | 1MB | EDMA3 Channel Controller Registers |
| Reserved | 0x4910_0000 | 0x497F_FFFF | 7MB | Reserved |
| TPTC0 (EDMA3TC0) | 0x4980_0000 | 0x498F_FFFF | 1MB | EDMA3 Transfer Controller 0 Registers |
| Reserved | 0x4990_0000 | 0x499F_FFFF | 1MB | Reserved |
| TPTC1 (EDMA3TC1) | 0x49A0_0000 | 0x49AF_FFFF | 1MB | EDMA3 Transfer Controller 1 Registers |
| TPTC2 (EDMA3TC2) | 0x49C0_0000 | 0x49CF_FFFF | 1MB | EDMA3 Transfer Controller 2 Registers |
| Reserved | 0x49D0_0000 | 0x49BF_FFFF | 1MB | Reserved |
| Reserved | 0x49E0_0000 | 0x49FF_FFFF | 4MB | Reserved |
| L4_FAST | 0x4A00_0000 | 0x4AFF_FFFF | 16MB | L4_FAST |
| Reserved | 0x4B00_0000 | 0x4B13_FFFF | 1280KB | Reserved |
| DebugSS_ETM | 0x4B14_0000 | 0x4B14_0FFF | 4KB | CortexA8 ETM Unit |
| DebugSS_Debug | 0x4B14_1000 | 0x4B14_1FFF | 4KB | CortexA8 Debug Unit |
| DebugSS_CTI | 0x4B14_2000 | 0x4B14_2FFF | 4KB | CortexA8 CTI Unit |
| DebugSS_ICE | 0x4B14_3000 | 0x4B14_3FFF | 4KB | ICECrusher-CS APB |
| Reserved | 0x4B14_4000 | 0x4B15_FFFF | 128KB | Reserved |
| DebugSS_DAP | 0x4B16_0000 | 0x4B16_0FFF | 4KB | Debug Subsystem: Debug Resource Manager |
| DebugSS_ETB | 0x4B16_2000 | 0x4B16_2FFF | 4KB | Debug Subsystem: Embedded Trace Buffer |
| Reserved | 0x4B16_3000 | 0x4BFF_FFFF | 15MB-396KB | Reserved |
| EMIF0 | 0x4C00_0000 | 0x4CFF_FFFF | 16MB | EMIF0 Configuration registers |
| Reserved | 0x4D00_0000 | 0x4DFF_FFFF | 16MB | Reserved |
| Reserved | 0x4E00_0000 | 0x4EFF_FFFF | 32MB | Reserved |
| GPMC | 0x5000_0000 | 0x50FF_FFFF | 16MB | GPMC Configuration registers |
| Reserved | 0x5100_0000 | 0x52FF_FFFF | 32MB | Reserved |
| Reserved | 0x5300_0000 | 0x530F_FFFF | 1MB | Reserved |
| Reserved | 0x5310_0000 | 0x531F_FFFF | 1MB | Reserved |
| Reserved | 0x5320_0000 | 0x533F_FFFF | 2MB | Reserved |
| Reserved | 0x5340_0000 | 0x534F_FFFF | 1MB | Reserved |

### Table 2-1: L3 Memory Map (continued)

| Block Name | Start Address (hex) | End Address (hex) | Size | Description |
|-----------|-------------------|------------------|------|-------------|
| Reserved | 0x5350_0000 | 0x535F_FFFF | 1MB | Reserved |
| Reserved | 0x5360_0000 | 0x54BF_FFFF | 22MB | Reserved |
| ADC_TSC Regs | 0x54C0_0000 | 0x54FF_FFFF | 4MB | ADC_TSC Main Port |
| Reserved | 0x5500_0000 | 0x55FF_FFFF | 16MB | Reserved |
| SGXS30 | 0x5600_0000 | 0x56FF_FFFF | 16MB | SGXS30 Slave Port |
| Reserved | 0x5700_0000 | 0x57FF_FFFF | 16MB | Reserved |
| Reserved | 0x5800_0000 | 0x58FF_FFFF | 16MB | Reserved |
| Reserved | 0x5900_0000 | 0x59FF_FFFF | 16MB | Reserved |
| Reserved | 0x5A00_0000 | 0x5AFF_FFFF | 16MB | Reserved |
| Reserved | 0x5B00_0000 | 0x5BFF_FFFF | 16MB | Reserved |
| Reserved | 0x5C00_0000 | 0x5DFF_FFFF | 32MB | Reserved |
| Reserved | 0x5E00_0000 | 0x5FFF_FFFF | 32MB | Reserved |
| Reserved | 0x6000_0000 | 0x7FFF_FFFF | 512MB | Reserved |
| EMIF0 SDRAM | 0x8000_0000 | 0x9FFF_FFFF | 1GB | 8/16-bit External Memory (EXRAM) |
| Reserved | 0xC000_0000 | 0xFFFF_FFFF | 1GB | Reserved |

---

## 2.2 L4_WKUP Peripheral Memory Map

### Table 2-2: L4_WKUP Peripheral Memory Map

| Region Name | Start Address (hex) | End Address (hex) | Size | Description |
|------------|-------------------|------------------|------|-------------|
| L4_WKUP Configuration | 0x44C0_0000 | 0x44C0_07FF | 2KB | Address/Protection (AP) |
| - | 0x44C0_0800 | 0x44C0_0FFF | 2KB | Link Agent (LA) |
| - | 0x44C0_1000 | 0x44C0_13FF | 1KB | Initiator Port (IP0) |
| - | 0x44C0_1400 | 0x44C0_17FF | 1KB | Initiator Port (IP1) |
| Reserved | 0x44C0_1800 | 0x44C0_1FFF | 2KB | Reserved (IP2 = IP3) |
| Reserved | 0x44C0_2000 | 0x44CF_FFFF | 1MB-8KB | Reserved |
| Reserved | 0x44D0_0000 | 0x44D0_3FFF | 16KB | Reserved |
| - | 0x44D0_4000 | 0x44D0_4FFF | 4KB | Reserved |
| Reserved | 0x44D0_5000 | 0x44D7_FFFF | 492KB | Reserved |
| Reserved | 0x44D8_0000 | 0x44D8_1FFF | 8KB | Reserved |
| - | 0x44D8_2000 | 0x44D8_2FFF | 4KB | Reserved |
| Reserved | 0x44D8_3000 | 0x44DF_FFFF | 500KB | Reserved |
| CM_WKUP | 0x44E0_0000 | 0x44E0_03FF | 1KB | Clock Module Peripheral Registers |
| CM_WKUP | 0x44E0_0400 | 0x44E0_04FF | 256 Bytes | Clock Module Wakeup Registers |
| CM_PLL | 0x44E0_0500 | 0x44E0_05FF | 256 Bytes | Clock Module PLL Registers |
| CM_MPU | 0x44E0_0600 | 0x44E0_06FF | 256 Bytes | Clock Module MPU Registers |
| CM_DEVICE | 0x44E0_0700 | 0x44E0_07FF | 256 Bytes | Clock Module Device Registers |
| CM_RTC | 0x44E0_0800 | 0x44E0_08FF | 256 Bytes | Clock Module RTC Registers |
| CM_GFX | 0x44E0_0900 | 0x44E0_09FF | 256 Bytes | Clock Module Graphics Registers |
| CM_CEFUSE | 0x44E0_0A00 | 0x44E0_0AFF | 256 Bytes | Clock Module Efuse Registers |
| PRM_IRQ | 0x44E0_0B00 | 0x44E0_0BFF | 256 Bytes | Power Reset Module Device Registers |
| PRM_RTC | 0x44E0_1000 | 0x44E0_10FF | 256 Bytes | Power Reset Module RTC Registers |
| PRM_GFX | 0x44E0_1100 | 0x44E0_11FF | 256 Bytes | Power Reset Module Graphics Registers |
| PRM_CEFUSE | 0x44E0_1200 | 0x44E0_12FF | 256 Bytes | Power Reset Module Efuse Controller Registers |
| Reserved | 0x44E0_3000 | 0x44E0_3FFF | 4KB | Reserved |
| - | 0x44E0_4000 | 0x44E0_4FFF | 4KB | Reserved |
| DMTIMER0 | 0x44E0_5000 | 0x44E0_5FFF | 4KB | DMTimer0 Registers |
| - | 0x44E0_6000 | 0x44E0_6FFF | 4KB | Reserved |
| GPIO0 | 0x44E0_7000 | 0x44E0_7FFF | 4KB | GPIO Registers |
| - | 0x44E0_8000 | 0x44E0_8FFF | 4KB | Reserved |
| UART0 | 0x44E0_9000 | 0x44E0_9FFF | 4KB | UART0 Registers |
| - | 0x44E0_A000 | 0x44E0_AFFF | 4KB | Reserved |
| I2C0 | 0x44E0_B000 | 0x44E0_BFFF | 4KB | I2C Registers |
| - | 0x44E0_C000 | 0x44E0_CFFF | 4KB | Reserved |
| ADC_TSC | 0x44E0_D000 | 0x44E0_EFFF | 8KB | ADC_TSC Registers |
| - | 0x44E0_F000 | 0x44E1_0FFF | 8KB | Reserved |
| Control Module | 0x44E1_0000 | 0x44E1_1FFF | 128KB | Control Module Registers |
| DDR2/mDDR PHY | 0x44E1_2000 | 0x44E1_23FF | - | DDR2/mDDR PHY Registers |
| Reserved | 0x44E1_2400 | 0x44E3_0FFF | 4KB | Reserved |
| DMTIMER1_1ms (Accurate Timers) | 0x44E3_1000 | 0x44E3_1FFF | 4KB | DMTIMER1 1ms Registers |
| Reserved | 0x44E3_2000 | 0x44E3_2FFF | 4KB | Reserved |
| Reserved | 0x44E3_3000 | 0x44E3_3FFF | 4KB | Reserved |
| - | 0x44E3_4000 | 0x44E3_4FFF | 4KB | Reserved |
| WDT1 | 0x44E3_5000 | 0x44E3_5FFF | 4KB | Watchdog Timer Registers |
| - | 0x44E3_6000 | 0x44E3_6FFF | 4KB | Reserved |
| SmartReflex0 | 0x44E3_7000 | 0x44E3_7FFF | 4KB | L3 Registers |
| - | 0x44E3_8000 | 0x44E3_8FFF | 4KB | Reserved |
| SmartReflex1 | 0x44E3_9000 | 0x44E3_9FFF | 4KB | L3 Registers |
| - | 0x44E3_A000 | 0x44E3_AFFF | 4KB | Reserved |
| Reserved | 0x44E3_B000 | 0x44E3_DFFF | 12KB | Reserved |
| RTCSS | 0x44E3_E000 | 0x44E3_EFFF | 4KB | RTC Registers |
| - | 0x44E3_F000 | 0x44E3_FFFF | 4KB | Reserved |
| DebugSS Instrumentation ROM Agent Port | 0x44E4_0000 | 0x44E7_FFFF | 256KB | Debug Registers |
| Reserved | 0x44E8_0000 | 0x44E8_0FFF | 4KB | Reserved |
| Reserved | 0x44E8_1000 | 0x44FF_FFFF | 608KB | Reserved |
| Reserved | 0x44F0_0000 | 0x44FF_FFFF | 1MB | Reserved |

---

## 2.3 L4_PER Peripheral Memory Map

### Table 2-3: L4_PER Peripheral Memory Map

| Device Name | Start Address (hex) | End Address (hex) | Size | Description |
|------------|-------------------|------------------|------|-------------|
| - | 0x4800_0000 | 0x4800_07FF | 2KB | Reserved |
| - | 0x4800_0800 | 0x4800_0FFF | 2KB | Reserved |
| Reserved | 0x4800_1000 | 0x4800_17FF | 1KB | Reserved |

### Table 2-3: L4_PER Peripheral Memory Map (continued)

| Device Name | Start Address (hex) | End Address (hex) | Size | Description |
|------------|-------------------|------------------|------|-------------|
| - | 0x4800_1000 | 0x4800_17FF | 1KB | Reserved |
| - | 0x4800_1800 | 0x4800_1BFF | 1KB | Reserved |
| - | 0x4800_1C00 | 0x4800_1FFF | 1KB | Reserved |
| Reserved | 0x4800_2000 | 0x4800_3FFF | 8KB | Reserved |
| Reserved | 0x4800_4000 | 0x4800_7FFF | 16KB | Reserved |
| Reserved | 0x4800_8000 | 0x4800_8FFF | 4KB | Reserved |
| - | 0x4800_9000 | 0x4800_9FFF | 4KB | Reserved |
| - | 0x4800_A000 | 0x4800_FFFF | 24KB | Reserved |
| Reserved | 0x4801_0000 | 0x4801_0FFF | 4KB | Reserved |
| - | 0x4801_1000 | 0x4801_1FFF | 4KB | Reserved |
| Reserved | 0x4802_2000 | 0x4801_3FFF | 8KB | Reserved |
| Reserved | 0x4801_4000 | 0x4801_FFFF | 48KB | Reserved |
| Reserved | 0x4802_0000 | 0x4802_0FFF | 4KB | Reserved |
| UART1 | 0x4802_2000 | 0x4802_2FFF | 4KB | UART1 Registers |
| - | 0x4802_3000 | 0x4802_3FFF | 4KB | Reserved |
| UART2 | 0x4802_4000 | 0x4802_4FFF | 4KB | UART2 Registers |
| - | 0x4802_5000 | 0x4802_5FFF | 4KB | Reserved |
| Reserved | 0x4802_6000 | 0x4802_7FFF | 8KB | Reserved |
| Reserved | 0x4802_8000 | 0x4802_8FFF | 4KB | Reserved |
| Reserved | 0x4802_9000 | 0x4802_9FFF | 4KB | Reserved |
| I2C1 | 0x4802_A000 | 0x4802_AFFF | 4KB | I2C1 Registers |
| - | 0x4802_B000 | 0x4802_BFFF | 4KB | Reserved |
| Reserved | 0x4802_C000 | 0x4802_CFFF | 4KB | Reserved |
| - | 0x4802_D000 | 0x4802_DFFF | 4KB | Reserved |
| Reserved | 0x4802_F000 | 0x4802_FFFF | 4KB | Reserved |
| McSPI0 | 0x4803_0000 | 0x4803_0FFF | 4KB | McSPI0 Registers |
| - | 0x4803_1000 | 0x4803_1FFF | 4KB | Reserved |
| Reserved | 0x4803_2000 | 0x4803_2FFF | 4KB | Reserved |
| - | 0x4803_3000 | 0x4803_3FFF | 4KB | Reserved |
| Reserved | 0x4803_4000 | 0x4803_4FFF | 4KB | Reserved |
| - | 0x4803_5000 | 0x4803_5FFF | 4KB | Reserved |
| Reserved | 0x4803_6000 | 0x4803_6FFF | 4KB | Reserved |
| - | 0x4803_7000 | 0x4803_7FFF | 4KB | Reserved |
| McASP0 CFG | 0x4803_8000 | 0x4803_9FFF | 8KB | McASP0 CFG Registers |
| - | 0x4803_A000 | 0x4803_AFFF | 4KB | Reserved |
| Reserved | 0x4803_B000 | 0x4803_BFFF | 4KB | Reserved |
| McASP1 CFG | 0x4803_C000 | 0x4803_DFFF | 8KB | McASP1 CFG Registers |
| - | 0x4803_E000 | 0x4803_EFFF | 4KB | Reserved |
| Reserved | 0x4803_F000 | 0x4803_FFFF | 4KB | Reserved |
| DMTIMER2 | 0x4804_0000 | 0x4804_0FFF | 4KB | DMTimer2 Registers |
| - | 0x4804_1000 | 0x4804_1FFF | 4KB | Reserved |
| DMTIMER3 | 0x4804_2000 | 0x4804_2FFF | 4KB | DMTimer3 Registers |
| - | 0x4804_3000 | 0x4804_3FFF | 4KB | Reserved |
| DMTIMER4 | 0x4804_4000 | 0x4804_4FFF | 4KB | DMTimer4 Registers |
| - | 0x4804_5000 | 0x4804_5FFF | 4KB | Reserved |

### Table 2-3: L4_PER Peripheral Memory Map (continued)

| Device Name | Start Address (hex) | End Address (hex) | Size | Description |
|------------|-------------------|------------------|------|-------------|
| DMTIMER5 | 0x4804_6000 | 0x4804_6FFF | 4KB | DMTimer5 Registers |
| - | 0x4804_7000 | 0x4804_7FFF | 4KB | Reserved |
| DMTIMER6 | 0x4804_8000 | 0x4804_8FFF | 4KB | DMTimer6 Registers |
| - | 0x4804_9000 | 0x4804_9FFF | 4KB | Reserved |
| DMTIMER7 | 0x4804_A000 | 0x4804_AFFF | 4KB | DMTimer7 Registers |
| - | 0x4804_B000 | 0x4804_BFFF | 4KB | Reserved |
| GPIO1 | 0x4804_C000 | 0x4804_CFFF | 4KB | GPIO1 Registers |
| - | 0x4804_D000 | 0x4804_DFFF | 4KB | Reserved |
| Reserved | 0x4804_E000 | 0x4804_EFFF | 8KB | Reserved |
| Reserved | 0x4805_0000 | 0x4805_FFFF | 64KB | Reserved |
| MMCHS0 | 0x4806_0000 | 0x4806_0FFF | 4KB | MMCHS0 Registers |
| - | 0x4806_1000 | 0x4806_1FFF | 4KB | Reserved |
| Reserved | 0x4806_2000 | 0x4807_FFFF | 120KB | Reserved |
| ELM | 0x4808_0000 | 0x4808_FFFF | 64KB | ELM Registers |
| - | 0x4809_0000 | 0x4809_0FFF | 4KB | Reserved |
| Reserved | 0x4809_1000 | 0x4809_FFFF | 60KB | Reserved |
| Reserved | 0x480A_0000 | 0x480A_FFFF | 64KB | Reserved |
| - | 0x480B_0000 | 0x480B_0FFF | 4KB | Reserved |
| Reserved | 0x480B_1000 | 0x480B_FFFF | 60KB | Reserved |
| Reserved | 0x480C_0000 | 0x480C_0FFF | 4KB | Reserved |
| - | 0x480C_1000 | 0x480C_1FFF | 4KB | Reserved |
| - | 0x480C_2000 | 0x480C_2FFF | 4KB | Reserved |
| Reserved | 0x480C_3000 | 0x480C_3FFF | 4KB | Reserved |
| Reserved | 0x480C_4000 | 0x480C_7FFF | 16KB | Reserved |
| Mailbox 0 | 0x480C_8000 | 0x480C_8FFF | 4KB | Mailbox Registers |
| - | 0x480C_9000 | 0x480C_9FFF | 4KB | Reserved |
| Spinlock | 0x480C_A000 | 0x480C_AFFF | 4KB | Spinlock Registers |
| - | 0x480C_B000 | 0x480C_BFFF | 4KB | Reserved |
| Reserved | 0x480F_0000 | 0x480F_FFFF | 208KB | Reserved |
| Reserved | 0x4810_0000 | 0x4811_FFFF | 128KB | Reserved |
| - | 0x4812_0000 | 0x4812_0FFF | 4KB | Reserved |
| Reserved | 0x4812_1000 | 0x4812_1FFF | 4KB | Reserved |
| - | 0x4812_2000 | 0x4812_2FFF | 4KB | Reserved |
| Reserved | 0x4812_3000 | 0x4812_3FFF | 4KB | Reserved |
| Reserved | 0x4812_4000 | 0x4812_7FFF | 112KB | Reserved |
| Reserved | 0x4814_0000 | 0x4815_FFFF | 128KB | Reserved |
| - | 0x4816_0000 | 0x4816_0FFF | 4K | Reserved |
| Reserved | 0x4817_0000 | 0x4817_FFFF | 124KB | Reserved |
| Reserved | 0x4818_0000 | 0x4818_2FFF | 12KB | Reserved |
| Reserved | 0x4818_3000 | 0x4818_3FFF | 4KB | Reserved |
| Reserved | 0x4818_4000 | 0x4818_7FFF | 16KB | Reserved |
| Reserved | 0x4818_8000 | 0x4818_8FFF | 4KB | Reserved |
| Reserved | 0x4818_9000 | 0x4818_9FFF | 4KB | Reserved |
| Reserved | 0x4818_A000 | 0x4818_AFFF | 4KB | Reserved |
| OCP Watchpoint | 0x4818_C000 | 0x4818_CFFF | 4KB | OCP Watchpoint Registers |
| - | 0x4818_D000 | 0x4818_EFFF | 4KB | Reserved |

### Table 2-3: L4_PER Peripheral Memory Map (continued)

| Device Name | Start Address (hex) | End Address (hex) | Size | Description |
|------------|-------------------|------------------|------|-------------|
| Reserved | 0x4818_E000 | 0x4818_EFFF | 4KB | Reserved |
| - | 0x4818_F000 | 0x4818_FFFF | 4KB | Reserved |
| Reserved | 0x4819_0000 | 0x4819_0FFF | 4KB | Reserved |
| - | 0x4819_1000 | 0x4819_1FFF | 4KB | Reserved |
| Reserved | 0x4819_2000 | 0x4819_2FFF | 4KB | Reserved |
| - | 0x4819_3000 | 0x4819_3FFF | 4KB | Reserved |
| Reserved | 0x4819_4000 | 0x4819_BFFF | 32KB | Reserved |
| I2C2 | 0x4819_C000 | 0x4819_CFFF | 4KB | I2C2 Registers |
| - | 0x4819_D000 | 0x4819_DFFF | 4KB | Reserved |
| Reserved | 0x4819_E000 | 0x4819_EFFF | 4KB | Reserved |
| - | 0x4819_F000 | 0x4819_FFFF | 4KB | Reserved |
| McSPI1 | 0x481A_0000 | 0x481A_0FFF | 4KB | McSPI1 Registers |
| - | 0x481A_1000 | 0x481A_1FFF | 4KB | Reserved |
| Reserved | 0x481A_2000 | 0x481A_5FFF | 16KB | Reserved |
| UART3 | 0x481A_6000 | 0x481A_6FFF | 4KB | UART3 Registers |
| - | 0x481A_7000 | 0x481A_7FFF | 4KB | Reserved |
| UART4 | 0x481A_8000 | 0x481A_8FFF | 4KB | UART4 Registers |
| - | 0x481A_9000 | 0x481A_9FFF | 4KB | Reserved |
| UART5 | 0x481A_A000 | 0x481A_AFFF | 4KB | UART5 Registers |
| - | 0x481A_B000 | 0x481A_BFFF | 4KB | Reserved |
| GPIO2 | 0x481A_C000 | 0x481A_CFFF | 4KB | GPIO2 Registers |
| - | 0x481A_D000 | 0x481A_DFFF | 4KB | Reserved |
| GPIO3 | 0x481A_E000 | 0x481A_EFFF | 4KB | GPIO3 Registers |
| - | 0x481A_F000 | 0x481A_FFFF | 4KB | Reserved |
| Reserved | 0x481B_0000 | 0x481B_FFFF | 64KB | Reserved |
| - | 0x481C_0000 | 0x481C_0FFF | 4KB | Reserved |
| Reserved | 0x481C_1000 | 0x481C_1FFF | 4KB | Reserved |
| - | 0x481C_2000 | 0x481C_2FFF | 4KB | Reserved |
| Reserved | 0x481C_3000 | 0x481C_0FFF | 28KB | Reserved |
| Reserved | 0x481C_4000 | 0x481C_AFFF | 4KB | Reserved |
| - | 0x481C_B000 | 0x481C_BFFF | 4KB | Reserved |
| DCAN0 | 0x481C_C000 | 0x481C_DFFF | 8KB | DCAN0 Registers |
| - | 0x481C_E000 | 0x481C_FFFF | 8KB | Reserved |
| DCAN1 | 0x481D_0000 | 0x481D_1FFF | 8KB | DCAN1 Registers |
| - | 0x481D_2000 | 0x481D_3FFF | 8KB | Reserved |
| Reserved | 0x481D_4000 | 0x481D_4FFF | 4KB | Reserved |
| - | 0x481D_5000 | 0x481D_5FFF | 4KB | Reserved |
| Reserved | 0x481D_6000 | 0x481D_6FFF | 4KB | Reserved |
| - | 0x481D_7000 | 0x481D_7FFF | 4KB | Reserved |
| MMC1 | 0x481D_8000 | 0x481D_8FFF | 4KB | MMC1 Registers |
| - | 0x481D_9000 | 0x481D_9FFF | 4KB | Reserved |
| Reserved | 0x481D_A000 | 0x481F_FFFF | 152KB | Reserved |
| Interrupt controller (INTCPS) | 0x4820_0000 | 0x4820_0FFF | 4KB | Interrupt Controller Registers |
| Reserved | 0x4820_1000 | 0x4823_FFFF | 252KB | Reserved |
| MPUSS config register | 0x4824_0000 | 0x4824_0FFF | 4KB | Host ARM non-shared device mapping |
| Reserved | 0x4824_1000 | 0x4827_FFFF | 252KB | Reserved |

### Table 2-3: L4_PER Peripheral Memory Map (continued)

| Device Name | Start Address (hex) | End Address (hex) | Size | Description |
|------------|-------------------|------------------|------|-------------|
| Reserved | 0x4828_0000 | 0x4828_0FFF | 4KB | Reserved |
| Reserved | 0x4828_1000 | 0x482F_FFFF | 508KB | Reserved |
| PWM Subsystem 0 eCAP0 | 0x4830_0000 | 0x4830_00FF | - | PWMSS0 eCAP0 Registers |
| - | 0x4830_0100 | 0x4830_017F | - | PWMSS eCAP0 Registers |
| eQEP0 | 0x4830_0180 | 0x4830_01FF | - | PWMSS eQEP0 Registers |
| ePWM0 | 0x4830_0200 | 0x4830_025F | - | PWMSS ePWM0 Registers |
| - | 0x4830_0260 | 0x4830_1FFF | 4KB | Reserved |
| PWM Subsystem 1 | 0x4830_2000 | 0x4830_20FF | - | PWMSS1 Configuration Registers |
| eCAP1 | 0x4830_2100 | 0x4830_217F | 4KB | PWMSS eCAP1 Registers |
| eQEP1 | 0x4830_2180 | 0x4830_21FF | - | PWMSS eQEP1 Registers |
| ePWM1 | 0x4830_2200 | 0x4830_225F | - | PWMSS ePWM1 Registers |
| - | 0x4830_2260 | 0x4830_3FFF | 4KB | Reserved |
| PWM Subsystem 2 | 0x4830_4000 | 0x4830_40FF | - | PWMSS2 Configuration Registers |
| eCAP2 | 0x4830_4100 | 0x4830_417F | 4KB | PWMSS eCAP2 Registers |
| eQEP2 | 0x4830_4180 | 0x4830_41FF | - | PWMSS eQEP2 Registers |
| ePWM2 | 0x4830_4200 | 0x4830_425F | - | PWMSS ePWM2 Registers |
| - | 0x4830_5000 | 0x4830_5FFF | 4KB | Reserved |
| Reserved | 0x4830_6000 | 0x4830_DFFF | 32KB | Reserved |
| LCD Controller | 0x4830_E000 | 0x4830_EFFF | 4KB | LCD Registers |
| - | 0x4830_F000 | 0x4830_FFFF | 4KB | Reserved |
| Reserved | 0x4831_0000 | 0x4831_1FFF | 8KB | Reserved |
| - | 0x4831_2000 | 0x4831_2FFF | 4KB | Reserved |
| Reserved | 0x4831_3000 | 0x4831_7FFF | 20KB | Reserved |
| Reserved | 0x4831_8000 | 0x4831_8FFF | 16KB | Reserved |
| - | 0x4831_C000 | 0x4831_CFFF | 4KB | Reserved |
| Reserved | 0x4832_0000 | 0x4832_5FFF | 16KB | Reserved |
| Reserved | 0x4832_6000 | 0x48FF_FFFF | 13MB-152KB | Reserved |

---

## 2.4 L4_FAST Peripheral Memory Map

### Table 2-4: L4_FAST Peripheral Memory Map

| Device Name | Start Address (hex) | End Address (hex) | Size | Description |
|------------|-------------------|------------------|------|-------------|
| L4_Fast configuration | 0x4A00_007F | 0x4A00_007F | 2KB | Address/Protection (AP) |
| - | 0x4A00_0800 | 0x4A00_0FFF | 2KB | Link Agent (LA) |
| - | 0x4A00_1000 | 0x4A00_13FF | 1KB | Initiator Port (IP0) |
| - | 0x4A00_1400 | 0x4A00_17FF | 1KB | Reserved |
| - | 0x4A00_1800 | 0x4A00_1FFF | 2KB | Reserved (IP2 = IP3) |
| Reserved | 0x4A00_2000 | 0x4A07_FFFF | 504KB | Reserved |
| Reserved | 0x4A08_0000 | 0x4A0A_0FFF | 128KB | Reserved |
| - | 0x4A0A_1000 | 0x4A0A_0FFF | 4KB | Reserved |
| Reserved | 0x4A0A_1000 | 0x4A0F_FFFF | 380KB | Reserved |
| CPSW_SS | 0x4A10_0000 | 0x4A10_7FFF | 32KB | Ethernet Switch Subsystem |
| CPSW_PORT | 0x4A10_0100 | 0x4A10_07FF | - | Ethernet Switch Port Control |
| CPSW_CPDMA | 0x4A10_0800 | 0x4A10_08FF | - | CPPI DMA Controller Module |
| CPSW_STATS | 0x4A10_0900 | 0x4A10_09FF | - | Ethernet Statistics |

### Table 2-4: L4_FAST Peripheral Memory Map (continued)

| Device Name | Start Address (hex) | End Address (hex) | Size | Description |
|------------|-------------------|------------------|------|-------------|
| CPSW_STATERAM | 0x4A10_0A00 | 0x4A10_0BFF | - | CPPI DMA State RAM |
| CPSW_CPTS | 0x4A10_0C00 | 0x4A10_0CFF | - | Ethernet Time Sync Module |
| CPSW_ALE | 0x4A10_0D00 | 0x4A10_0D7F | - | Ethernet Address Lookup Engine |
| CPSW_SL1 | 0x4A10_0D80 | 0x4A10_0DBF | - | Ethernet Sliver for Port 1 |
| CPSW_SL2 | 0x4A10_0DC0 | 0x4A10_0DFF | - | Ethernet Sliver for Port 2 |
| Reserved | 0x4A10_0E00 | 0x4A10_0FFF | - | Reserved |
| MDIO | 0x4A10_1000 | 0x4A10_10FF | - | Ethernet MDIO Controller |
| - | 0x4A10_1100 | 0x4A10_11FF | - | Reserved |
| CPSW_WR | 0x4A10_1200 | 0x4A10_1FFF | - | Ethernet Subsystem Wrapper for RMII/RGMII |
| CPPI_RAM | 0x4A10_2000 | 0x4A10_3FFF | - | Communications Port Programming Interface RAM |
| Reserved | 0x4A10_9000 | 0x4A13_FFFF | 220KB | Reserved |
| Reserved | 0x4A14_0000 | 0x4A14_FFFF | 64KB | Reserved |
| Reserved | 0x4A15_0000 | 0x4A15_0FFF | 4KB | Reserved |
| Reserved | 0x4A15_1000 | 0x4A17_FFFF | 188KB | Reserved |
| Reserved | 0x4A18_0000 | 0x4A1A_1FFF | 136KB | Reserved |
| Reserved | 0x4A1A_2000 | 0x4A1A_3FFF | 8KB | Reserved |
| - | 0x4A1A_4000 | 0x4A1A_4FFF | 4KB | Reserved |
| Reserved | 0x4A1A_5000 | 0x4A1A_5FFF | 4KB | Reserved |
| - | 0x4A1A_6000 | 0x4A1A_6FFF | 4KB | Reserved |
| Reserved | 0x4A1A_7000 | 0x4A1A_7FFF | 4KB | Reserved |
| Reserved | 0x4A1A_8000 | 0x4A1A_9FFF | 8KB | Reserved |
| - | 0x4A1A_A000 | 0x4A1A_AFFF | 4KB | Reserved |
| Reserved | 0x4A1A_B000 | 0x4A1A_BFFF | 4KB | Reserved |
| Reserved | 0x4A1B_0000 | 0x4A1B_1FFF | 4KB | Reserved |
| - | 0x4A1B_2000 | 0x4A1B_2FFF | 4KB | Reserved |
| Reserved | 0x4A1B_3000 | 0x4A1B_3FFF | 4KB | Reserved |
| - | 0x4A1B_4000 | 0x4A1B_4FFF | 4KB | Reserved |
| Reserved | 0x4A1B_5000 | 0x4A1B_8FFF | 4KB | Reserved |
| - | 0x4A1B_9000 | 0x4A1B_9FFF | 4KB | Reserved |
| Reserved | 0x4A1E_0000 | 0x4A1E_FFFF | 304KB | Reserved |
| Reserved | 0x4A20_0000 | 0x4A2F_FFFF | 1MB | Reserved |
| PRU_ICSS | 0x4A30_0000 | 0x4A37_FFFF | 512KB | PRU-ICSS Instruction/Data/Control Space |
| - | 0x4A38_0000 | 0x4A38_0FFF | 4KB | Reserved |
| Reserved | 0x4A38_1000 | 0x4A3F_FFFF | 508KB | Reserved |
| Reserved | 0x4A40_0000 | 0x4AFF_FFFF | 12MB | Reserved |

---

## Ghi chú

1. **EXRAM**: External RAM - Bộ nhớ ngoài
2. **OCMC**: On-Chip Memory Controller
3. **GPMC**: General Purpose Memory Controller
4. **L3/L4**: Các bus kết nối nội bộ theo kiến trúc OMAP
5. **Peripheral**: Các thiết bị ngoại vi như UART, I2C, SPI, GPIO, Timer, v.v.

---

## Mục đích sử dụng cho Training AI

Tài liệu này cung cấp thông tin chi tiết về:
- Địa chỉ bộ nhớ của các khối chức năng
- Kích thước từng vùng nhớ
- Mô tả chức năng của từng peripheral
- Cấu trúc phân cấp bộ nhớ trong AM335x

Thông tin này rất hữu ích cho:
- Lập trình bare-metal
- Phát triển device driver
- Debug và phân tích hệ thống
- Tối ưu hóa hiệu năng bộ nhớ

# Chapter 6: AM335x Interrupt Controller (INTC)

## 6.1 Mô tả chức năng

Interrupt Controller xử lý các interrupt đến bằng cách thực hiện masking và priority sorting để tạo ra các interrupt signal cho processor. 

**LƯU Ý:** FIQ không khả dụng trên các thiết bị General-Purpose (GP).

### 6.1.1 Xử lý Interrupt

#### 6.1.1.1 Input Selection

INTC chỉ hỗ trợ phát hiện interrupt đến ở mức level-sensitive. Một peripheral muốn assert interrupt phải duy trì interrupt line ở mức high cho đến khi interrupt được xử lý.

**Software Interrupt:** Một software interrupt được tạo ra khi bit tương ứng trong thanh ghi `MPU_INTC.INTC_ISR_SETn` được set. Software interrupt sẽ được clear khi bit tương ứng trong thanh ghi `MPU_INTC.INTC_ISR_CLEARn` được ghi. Tính năng này thường được sử dụng cho software debugging.

#### 6.1.1.2 Masking

**Individual Masking:**
Các interrupt trên mỗi incoming interrupt line có thể được enable hoặc disable độc lập thông qua thanh ghi `MPU_INTC.INTC_MIRn`. Khi có một unmasked incoming interrupt, INTC có thể tạo ra một trong hai loại interrupt request đến processor:
- **IRQ:** Low-priority interrupt request
- **FIQ:** Fast interrupt request (Không khả dụng trên General Purpose devices)

Loại interrupt request được chọn trước khi priority sorting thông qua thanh ghi `MPU_INTC.INTC_ILRm[0] FIQ/NIRQ` bit (m= [0,127]).

Trạng thái incoming interrupt hiện tại trước khi masking có thể đọc từ thanh ghi `MPU_INTC.INTC_ITRn`. Trạng thái interrupt sau khi masking và trước priority sorting có thể đọc từ thanh ghi `MPU_INTC.INTC_PENDING_IRQn` và `MPU_INTC.INTC_PENDING_FIQn`.

**Priority Masking:**
Để cho phép xử lý nhanh hơn các interrupt có priority cao, một programmable priority masking threshold được cung cấp (trường `MPU_INTC.INTC_THRESHOLD[7:0] PRIORITYTHRESHOLD`). Chỉ các interrupt có priority lớn hơn giá trị threshold mới có thể đi qua để được processed.

Các interrupt có priority từ 0x0 đến 0x7F được so sánh với priority threshold. Các interrupt đã được masked sẽ không bị ảnh hưởng. Tuy nhiên, priority 0 không bao giờ bị masked bởi threshold này; priority threshold là 0 được coi giống như 0x80.

**Ý nghĩa giá trị priority:**
- 0x0 là priority cao nhất
- 0x7F là priority thấp nhất

Khi priority masking không cần thiết, giá trị 0xFF trong trường PRIORITYTHRESHOLD sẽ disable tính năng này. Giá trị 0xFF là giá trị reset mặc định cho backward compatibility với các phiên bản cũ của INTC.

#### 6.1.1.3 Priority Sorting

Priority level (0 là cao nhất) được gán cho mỗi incoming interrupt line. Cả priority level và interrupt request type đều được cấu hình thông qua thanh ghi `MPU_INTC.INTC_ILRm`.

Khi có nhiều hơn một unmasked incoming interrupt cùng priority level và interrupt request type xảy ra đồng thời, interrupt có số thứ tự cao nhất sẽ được chọn trước.

**Quá trình xử lý:**
1. INTC tách biệt IRQ và FIQ sử dụng bit `MPU_INTC.INTC_ILRm[0] FIQ/NIRQ` tương ứng
2. IRQ được đặt ở trạng thái PENDING_IRQn nếu không có interrupt khác đang được xử lý
3. INTC assert IRQ/FIQ và bắt đầu priority computation
4. Priority sorting cho IRQ và FIQ được thực hiện song song
5. Khi computation hoàn thành, số interrupt được xác định bởi priority sorter và số đó được đặt trong trường tương ứng:
   - `MPU_INTC.INTC_SIR_IRQ[6:0] ACTIVEIRQ` 
   - `MPU_INTC.INTC_SIR_FIQ[6:0] ACTIVEFIQ`
6. Giá trị được preserve trong trường ACTIVEIRQ/ACTIVEFIQ cho đến khi bit `MPU_INTC.INTC_CONTROL NEWIRQAGR` hoặc `NEWFIQAGR` được set
7. Sau khi interrupting peripheral device đã được handled, người dùng có thể set bit NEWIRQAGR/NEWFIQAGR tương ứng để báo cho INTC rằng interrupt đã được xử lý
8. Nếu có bất kỳ pending incoming interrupts nào đang chờ trong interrupt path, INTC xử lý bất kỳ interrupt nào khác có priority cao hơn; ngược lại, IRQ hoặc FIQ interrupt line bị de-asserted

### 6.1.2 Register Protection

Nếu bit `MPU_INTC.INTC_PROTECTION[0] PROTECTION` được set, quyền truy cập vào các thanh ghi INTC bị hạn chế chỉ cho privileged mode. Để biết thêm thông tin, xem Section 6.6.1.7 về thanh ghi INTC_PROTECTION.

**LƯU Ý:** Thanh ghi `MPU_INTC.INTC_PROTECTION` luôn được hạn chế ở privileged mode.

### 6.1.3 Module Power Saving

INTC cung cấp chức năng auto-idle trong ba clock domains của nó:
- Interface clock
- Functional clock  
- Synchronizer clock

**Interface clock auto-idle:**
Chế độ interface clock auto-idle power-saving được enable nếu bit `MPU_INTC.INTC_SYSCONFIG[0] AUTOIDLE` được set thành 1. Khi enabled và không có hoạt động trên bus interface, interface clock sẽ restart mà không có bất kỳ latency penalty nào. Sau khi reset, chế độ này được disable mặc định.

**Functional clock auto-idle:**
Bit `MPU_INTC.INTC_IDLE[0] FUNCIDLE` được set thành 0. Khi chế độ này được enable và không có hoạt động interrupt (không có pending interrupt đến hoặc không có interrupt được xử lý), functional clock bị disable internally để module giảm công suất tiêu thụ.

**Synchronizer clock auto-idle:**
Khi có một incoming interrupt mới được phát hiện, functional clock restart và INTC xử lý interrupt. Độ trễ trước khi các asynchronous interrupts được synchronize là bốn functional clock cycles cộng hoặc trừ một cycle nếu bit `MPU_INTC.INTC_IDLE[1] TURBO` được set thành 0.

Khi TURBO bit được set thành 1, interrupt generation sẽ giảm đi một cycle bằng cách disable functional clock auto-idle. Điều này có thể giảm latency khi chờ một interrupt, nhưng lợi ích là tối thiểu.

### 6.1.4 Error Handling

**Các trường hợp gây lỗi:**
- Privilege violation (cố gắng truy cập thanh ghi PROTECTION ở user mode hoặc bất kỳ thanh ghi nào ở user mode nếu Protection bit được set)
- Unsupported commands

**Các trường hợp KHÔNG gây lỗi:**
- Truy cập vào non-decoded address
- Ghi vào read-only register

### 6.1.5 Interrupt Handling

**Interrupt Latency:**
Việc tạo INTC interrupt mất bốn INTC functional clock cycles (cộng hoặc trừ một cycle) nếu bit TURBO được set thành 0. Nếu TURBO bit được set thành 1, interrupt generation có thể được giảm đi một cycle bằng cách disable functional clock auto-idle. Lợi ích giảm latency là tối thiểu.

Để giảm thiểu interrupt latency khi một unmasked interrupt xảy ra, IRQ hoặc FIQ interrupt được tạo ra **trước khi** priority sorting hoàn thành. Priority của interrupt được xác định trong 10 functional clock cycles, là số cycles tối thiểu cần thiết để MPU chuyển sang interrupt context sau khi nhận IRQ hoặc FIQ event.

**Priority Sorting Freeze:**
Bất kỳ lần đọc nào của thanh ghi `MPU_INTC.INTC_SIR_IRQ` hoặc `MPU_INTC.INTC_SIR_FIQ` trong quá trình priority sorting sẽ stall cho đến khi priority sorting hoàn thành và các thanh ghi có liên quan được update. Điều này đảm bảo rằng priority sorting luôn hoàn thành trước khi interrupt request được generated và interrupt service routine được execute, do đó delay giữa interrupt request và interrupt service routine được execute như vậy mà priority sorting luôn hoàn thành trước khi thanh ghi `MPU_INTC.INTC_SIR_FIQ` được đọc.

## 6.2 Basic Programming Model

### 6.2.1 Initialization Sequence

1. Program thanh ghi `MPU_INTC.INTC_SYSCONFIG`: Nếu cần thiết, enable interface clock auto-idle bằng cách set bit AUTOIDLE

2. Program thanh ghi `MPU_INTC.INTC_IDLE`: Nếu cần thiết, disable functional clock autogating hoặc enable synchronizer autogating bằng cách set bit FUNCIDLE hoặc TURBO bit tương ứng

3. Program thanh ghi `MPU_INTC.INTC_ILRm` cho mỗi interrupt line: Gán priority và set bit FIQ/NIRQ cho FIQ interrupt (mặc định, interrupts được map vào IRQ và priority là 0x0 [highest])

4. Program thanh ghi `MPU_INTC.INTC_MIRn`: Enable interrupts (mặc định, tất cả interrupt lines đều bị masked)
   
   **LƯU Ý:** Để program thanh ghi `MPU_INTC.INTC_MIRn`, các thanh ghi `MPU_INTC.INTC_MIR_SETn` và `MPU_INTC.INTC_MIR_CLEARn` được cung cấp để tạo điều kiện cho masking, ngay cả khi không thể write trực tiếp vào thanh ghi `MPU_INTC.INTC_MIRn`

### 6.2.2 INTC Processing Sequence

Sau khi INTC được enable, INTC sẵn sàng để enable và assign priorities cho incoming interrupts. Interrupt được xử lý như giải thích trong các phần tiếp theo. 

Xử lý IRQ và FIQ khá tương tự; sự khác biệt cho FIQ sequence được hiển thị sau ký tự '/' trong code dưới đây.

**Processing Steps:**

1. Một hoặc nhiều unmasked incoming interrupts (M_IRQ_n signals) được nhận và IRQ hoặc FIQ outputs (IRQ[0] hoặc FIQ[0]) được asserted hiện tại

2. Nếu bit `INTC_ILRm[0] FIQ/NIRQ` được cleared thành 0, output signal `MPU_INTC_IRQ` được generated. Nếu bit FIQ/NIRQ được set thành 1, output signal `MPU_INTC_FIQ` được generated

3. INTC thực hiện priority sorting và updates thanh ghi `INTC_SIR_IRQ[6:0] ACTIVEIRQ` / `INTC_SIR_FIQ[6:0] ACTIVEFIQ` với current interrupt number

4. Trong priority sorting, nếu IRQ/FIQ được enabled (F==0) ở phía host processor, host processor tự động save context hiện tại và execute ISR như sau:

   ARM host processor tự động thực hiện các actions sau trong pseudo code:
   
   ```
   SPSR = CPSR                    /* Save CPSR before execution */
   CPSR[5] = 0                    /* Execute in ARM state */
   CPSR[7] = 1                    /* Disable IRQ */
   CPSR[8] = 1                    /* Disable Imprecise Data Aborts */
   CPSR[9] = CP15_reg1_EEbit      /* Endianness on exception entry */
   if interrupt == IRQ then
      PC = 0x0FFFF0018            /* Enter IRQ mode */
      /* high vectors configured then
      PC = 0xFFFFFF0018
      else
      PC = 0x00000018              /* execute interrupt vector */
   else if interrupt == FIQ then
      CPSR[6] = 0b10001            /* Enter FIQ mode */
      CPSR[6] = 1                  /* Disable FIQ */
      /* high vectors configured then
      PC = 0xFFFFFF001C
      else
      PC = 0x0000001C              /* execute interrupt vector */
   endif
   ```

5. ISR save context còn lại, identifies interrupt source bằng cách đọc trường `ACTIVEIRQ/ACTIVEFIQ`, và jumps đến relevant subroutine handler như sau:

   ```assembly
   ;INTC_SIR_IRQ/INTC_SIR_FIQ register address
   INTC_SIR_IRQ_ADDR/INTC_SIR_FIQ_ADDR  word 0x48200040/0x48200044
   ; ACTIVEIRQ bit field mask to get only the bit field
   ACTIVEIRQ_MASK .equ 0x7F
   _IRQ_ISR/_FIQ_ISR:
   ; Step 1 : Save context
   STMFD SP!, (R0-R12, LR) ; Save working registers and the Link register
   MRS R1, SPSR ; Save the SPSR into R1
   ; Get the number of the highest priority active IRQ/FIQ
   LDR R0, INTC_SIR_IRQ_ADDR/INTC_SIR_FIQ_ADDR
   LDR R10, [R10] ; Get the INTC_SIR_IRQ/INTC_SIR_FIQ register
   AND R10, R10, #ACTIVEIRQ_MASK ; Apply the mask to get the active IRQ number
   ; Step 5 : Branch to the relevant interrupt handler
   LDR PC, [PC, R10, lsl #2] ; PC base address points this instruction + 8
   NOP ; To index the table by the PC
   ; Table of handler start addresses
   .word IRQ0handler ;For IRQ0 or BANKO
   .word IRQ1handler
   .word IRQ2handler
   ```

6. Subroutine handler thực thi code cụ thể cho peripheral generating interrupt bằng cách handling event và deasserting interrupt condition ở phía peripheral

   ```assembly
   IRQ0handler:
   ; Save working registers
   STMFD SP!, (R0-R1)
   ; Now read-modify-write the peripheral module status register
   ; to clear the M_IRQ_0 triggering signal
   ; De-Assert the peripheral interrupt
   MOV R0, #0x7 ;Mask of 3 flags
   LDR R1, MODULE0_STATUS_REG_ADDR ; Get the address of the module Status Register
   STR R0, [R1] ; Clear the 3 flags
   ; Restore working registers LDMFD SP!, (R0-R1)
   ; Jump to the end part of the ISR
   B IRQ_ISR_end/FIQ_ISR_end
   ```

7. Sau khi return của subroutine, ISR set bit `NEWIRQAGR/NEWFIQAGR` để enable processing của subsequent pending IRQ/FIQ và restore ARM context như sau:

   ```assembly
   ; INTC_CONTROL register address
   IRQ_ISR_end/FIQ_ISR_end : .word 0x48200048;
   NEWIRQAGR/NEWFIQAGR bit mask to set only the NEWIRQAGR/NEWFIQAGR bit
   NEWIRQAGR_MASK/NEWFIQAGR_MASK equ 0x1/0x2
   IRQ_ISR_end/FIQ_ISR_end
   ; Allow new IRQ/FIQ generation at INTC side
   ; Write 1 to the NEWIRQAGR/NEWFIQAGR bit only so no need to write back others bits
   MOV R0, #NEWIRQAGR_MASK/NEWFIQAGR_MASK ; Get the NEWIRQAGR/NEWFIQAGR bit position
   LDR R1, INTC_CONTROL_ADDR
   STR R0, [R1] ; Write the NEWIRQAGR/NEWFIQAGR bit to allow new IRQs/FIQ
   ; Data Synchronization Barrier
   MOV R0, #0
   MCR P15, #0, R0, C7, C10, #4
   ; Instruction Synchronization Barrier  
   MCR P15, #0, R0, C7, C5, #4
   MSR SPSR, R1; Restore the SPSR from R1
   LDMFD SP!, (R0-R12, LR) ; Restore working registers and Link register
   ; Return after handling the interrupt
   SUBS PC, LR, #4
   ```

8. Sau khi ISR return, ARM tự động restore context như sau:
   ```
   CPSR = SPSR
   PC = LR
   ```

**Lưu ý quan trọng:**
- Priority sorting mechanism được freeze trong interrupt processing sequence
- Nếu một interrupt condition xảy ra trong thời gian này, interrupt không bị lost
- Nó được sort khi bit `NEWIRQAGR/NEWFIQAGR` được set (priority sorting được reactivated)

### 6.2.3 INTC Preemptive Processing Sequence

**Preemptive interrupts** (còn gọi là nested interrupts) có thể giảm latencies cho các interrupt có priority cao hơn. 

Một preempting ISR có thể được served bởi một higher priority interrupt. Do đó, preempting interrupt có priority cao nhất có thể được served ngay lập tức. Nested interrupts phải được sử dụng cẩn thận để tránh corrupted data.

Programmers phải save/restore thanh ghi corrupted. Enable thanh ghi PRIORITY là khá tương tự như IRQ và FIQ processing sequences được mô tả ở ARM side.

**Để enable IRQ/FIQ preemption bởi higher priority IRQs/FIQs:**

Tại đầu của IRQ/FIQ ISR, programmers phải tuân theo một procedure đã cho:

1. Save các ARM critical context registers
2. Save trường `INTC_THRESHOLD PRIORITYTHRESHOLD` trước khi modifying nó  
3. Đọc active interrupt number từ các trường tương ứng:
   - `INTC_IRQ_PRIORITY` / `IROQPRIORITY` 
   - `INTC_FIQ_PRIORITY` / `FIQPRIORITY`
   
   Và write nó vào trường `PRIORITYTHRESHOLD(1)`

4. Đọc active interrupt number từ trường `INTC_SIR_IRQ[6:0] ACTIVEFIQ` / `INTC_SIR_FIQ[6:0] ACTIVEFIQ` để identify interrupt source

5. Write 1 vào appropriate bit `INTC_CONTROL NEWIRQAGR` và (2) `NEWFIQAGR` trong khi vẫn processing interrupt sẽ chỉ allow higher priority interrupts để preempt

6. Vì các writes được posted trên interconnect bus, để chắc chắn rằng các preceding writes đã hoàn thành trước khi enabling IRQs/FIQs, một Data Synchronization Barrier được sử dụng. Điều này đảm bảo rằng IRQ line được de-asserted trước khi IRQ/FIQ enabling. Sau đó, INTC xử lý bất kỳ pending interrupts nào khác hoặc deasserts IRQ/FIQ signal nếu không có interrupt

7. Enable IRQ/FIQ ở ARM side

8. Jump đến relevant subroutine handler

**Sample Code cho Preemptive Processing:**

```assembly
; bit field mask to get only the bit field
ACTIVEPRIO_MASK .equ 0x7F
_IRQ_ISR:
; Step 1 : Save context
STMFD SP!, (R0-R12, LR) ; Save working registers
MRS R11, SPSR ; Save the SPSR into R11
; Step 2 : Save the INTC_THRESHOLD register into R12
LDR R0, INTC_THRESHOLD_ADDR
LDR R12, [R0]
;--priority--
;threshold mechanism is enabled automatically when writing a priority in the range of 0x00 to 0x7F
;0x7F: Writing value of 0xFF (reset default) disables the priority.
;0x7E: No priority, effectively allows all IRQs/FIQs.
;NOTE: When hardware priority threshold is in use, the priorities of interrupts selected as FIQ or IRQ become linked, otherwise they are independent. When linked, it is required that all FIQ priorities be set higher than all IRQ priorities to maintain the relative priority of FIQ over IRQ.
;(2) When handling FIQs using the priority threshold mechanism, it is required to write both New FIQ Agreement and New IRQ Agreement bits at the same time to cover the case that the new priority threshold applied can fit both in FIQ Setting as it proposes. This IRQ will not have been seen by the ARM as it will have been masked on entry to the FIQ ISR. However, the source of the IRQ will remain active and it will be re-prioritized when the priority threshold falls to a low enough priority. The precaution of writing to New FIQ Agreement (as well as New IRQ Agreement) is not required during an IRQ ISR, as FIQ sorting is not affected (provided all FIQ priorities are higher than all IRQ priorities).
; Step 3 : Get the priority of the highest priority active IRQ
LDR R1, INTC_IRQ_PRIORITY_ADDR/INTC_FIQ_PRIORITY_ADDR
LDR R0, [R1] ; Write it to the INTC_IRQ_PRIORITY/INTC_FIQ_PRIORITY register
AND R1, R1, #ACTIVEPRIO_MASK ; Apply the mask to get the priority of the IRQ
STR R1, [R0] ; Write it to the INTC_THRESHOLD register
; Step 4 : Get the number of the highest priority active IRQ
LDR R10, INTC_SIR_IRQ_ADDR/INTC_SIR_FIQ_ADDR
LDR R10, [R10] ; Get the INTC_SIR_IRQ/INTC_SIR_FIQ register
AND R10, R10, #ACTIVEIRQ_MASK ; Apply the mask to get the active IRQ number
; Step 5 : Branch to the relevant interrupt subroutine handler
MOV R0, #0x1/0x3 ; Get the NEWIRQAGR and NEWFIQAGR bit position
LDR R1, INTC_CONTROL_ADDR
STR R0, [R1] ; Write the NEWIRQAGR and NEWFIQAGR bit
; Step 6 : Data Synchronization Barrier
MOV R0, #0
MCR P15, #0, R0, C7, C10, #4
; Instruction Synchronization Barrier
; Step 7 : Read-modify-write the CPSR to enable IRQs/FIQs at ARM side
MRS R0, CPSR ; Read the status register
BIC R0, R0, #0x80/0xC0 ; Clear the I/F bit
MSR CPSR, R0 ; Write it back to enable IRQs
; Step 8 : Jump to relevant subroutine handler
LDR PC, [PC, R10, lsl #2] ; PC base address points this instruction + 8
NOP ; To index the table by the PC
; Table of handler start addresses
.word IRQ0handler ;IRQ0 BANK0
.word IRQ1handler
.word IRQ2handler
```

**Sau khi return của relevant IRQ/FIQ subroutine handle:**

1. Disable IRQs/FIQs ở ARM side
2. Restore trường `INTC_THRESHOLD PRIORITYTHRESHOLD`
3. Restore các ARM critical context registers

**Sample Code:**

```assembly
IRQ_ISR_end
; Step 1 : Read-modify-write the CPSR to disable IRQs/FIQs at ARM side
MRS R0, CPSR ; Read the CPSR
ORR R0, R0, #0x80/0xC0 ; Set the I/F bit
MSR CPSR, R0 ; Write it back to disable IRQs
; Step 2 : Restore the INTC_THRESHOLD register from R12
LDR R0, INTC_THRESHOLD_ADDR
STR R12, [R0]
; Step 3 : Restore critical context
MSR SPSR, R11 ; Restore the SPSR from R11
LDMFD SP!, (R0-R12, LR) ; Restore working registers and Link register
; Return after handling the interrupt
SUBS PC, LR, #4
```

### 6.2.4 Interrupt Preemption

Nếu muốn enable pre-emption bởi higher priority interrupts, ISR nên đọc active interrupt priority và write nó vào appropriate threshold trước khi process interrupt. 

Writing "1" vào appropriate bit `INTC_IRQ_AGR` hoặc `NEW_FIQ_AGR` của thanh ghi CONTROL trong khi vẫn processing interrupt sẽ chỉ allow higher priority interrupts để pre-empt.

**Quan trọng:**
- Với mỗi level của pre-emption, programmer phải save threshold value trước khi modifying nó và restore nó tại end của ISR trước cleanup
- Priority threshold mechanism được enabled tự động khi writing một priority trong range 0 đến 7Fh

**Priority Threshold Effects:**
Khi hardware priority threshold đang được sử dụng, priorities của interrupts được selected là FIQ hoặc IRQ trở nên linked. Khi chúng được linked, tất cả FIQ priorities phải được set cao hơn tất cả IRQ priorities để duy trì relative priority của FIQ over IRQ.

Khi handling FIQs sử dụng priority threshold mechanism, cần write cả New FIQ Agreement và New IRQ Agreement bits cùng lúc để cover trường hợp new priority threshold applied có thể fit cả trong FIQ Setting. IRQ này sẽ không được ARM nhìn thấy vì nó đã bị masked khi entry vào FIQ ISR. Tuy nhiên, source của IRQ sẽ vẫn active và nó sẽ được re-prioritized khi priority threshold falls xuống đủ thấp để được processed. 

Việc writing vào New FIQ Agreement (cũng như New IRQ Agreement) không required trong IRQ ISR, vì FIQ sorting không bị affected (provided all FIQ priorities cao hơn all IRQ priorities).

### 6.2.5 ARM A8 INTC Spurious Interrupt Handling

**Spurious flag** cho biết kết quả của sorting (một window 10 INTC functional clock cycles sau interrupt assertion) có invalid hay không. Sorting là invalid nếu:
- Interrupt triggers nhưng không còn active trong quá trình sorting
- Có thay đổi trong mask đã affect kết quả trong sorting time

**Kết quả:**
Do đó, các giá trị trong các thanh ghi sau phải không được thay đổi trong khi corresponding interrupt được asserted. Chỉ active interrupt input mà triggered soft có thể được masked trước khi turn off. Nếu các thanh ghi này được thay đổi trong window 10 functional clock cycles sau interrupt assertion, các giá trị kết quả của các thanh ghi sau trở nên invalid:

- `INTC_SIR_IRQ`
- `INTC_SIR_FIQ`
- `INTC_IRQ_PRIORITY`
- `INTC_FIQ_PRIORITY`

Điều kiện này được detected cho cả IRQ và FIQ, và invalid status được flagged trong các bit fields:
- `SPURIOUSIRQFLAG` (xem NOTE 1)
- `SPURIOUSFIQFLAG` (xem NOTE 2)

Trong các thanh ghi SIR và PRIORITY. Một giá trị 1 indicates invalid interrupt number và priority. Invalid indication có thể được tested trong software như một false positive interrupt value.

**LƯU Ý:**

1. Bit field `INTC_SIR_IRQ[31:7] SPURIOUSIRQFLAG` là bản copy của bit field `INTC_IRQ_PRIORITY[31:7] SPURIOUSIRQFLAG`

2. Bit field `INTC_SIR_FIQ[31:7] SPURIOUSFIQFLAG` là bản copy của bit field `INTC_FIQ_PRIORITY[31:7] SPURIOUSFIQFLAG`

## 6.3 ARM Cortex-A8 Interrupts

AM335x sử dụng ARM Cortex-A8 processor core với 128 interrupt sources được map vào INTC. Các interrupt sources bao gồm:

- MPU Subsystem Internal interrupts
- External peripherals interrupts  
- DMA interrupts
- Timer interrupts
- Communication peripherals (UART, I2C, SPI, USB, Ethernet)
- GPIO interrupts
- ADC interrupts
- Security modules (AES, SHA2, RNG)
- Và nhiều peripherals khác

**Các interrupt quan trọng bao gồm:**

| Int Number | Acronym/Name | Source | Signal Name |
|------------|--------------|---------|-------------|
| 0 | EMUINT | MPU Subsystem Internal | Emulation interrupt |
| 1 | COMMTX | MPU Subsystem Internal | CortexA8 COMMTX |
| 2 | COMMRX | MPU Subsystem Internal | CortexA8 COMMRX |
| 4 | ELM_IRQ | ELM | Error Location Module |
| 7 | NMI | External Pin | nmi_int |
| 12-14 | EDMA | TPCC (EDMA) | tpcc_mpnt_pend_po |
| 28 | MMCSD0INT | MMCSD0 | SINTERRUPTN |
| 30 | I2C0INT | I2C0 | POINTRPEND |
| 31 | eCAP0 event/interrupt | eCAP0 | ecap_intr_intr_pend |
| 40-43 | 3PGSW/Ethernet | CPSW (Ethernet) | c0_rx_thresh_pend, c0_rx_pend, c0_tx_pend, c0_misc_pend |
| 44-47 | UART | UART3-UART6 | nirq |
| 64-68 | GPIO | GPIO 0-3 | pointrpend |
| 72-76 | UART | UART0-UART2, RTC | nirq, timer_intr_pend, alarm_intr_pend |
| 91 | WDTINT (Public Watchdog) | WDTIMER1 | PO_INT_PEND |
| 95-96 | TINT (DMTIMER) | DMTIMER4-DMTIMER7 | POINTR_PEND |
| 100 | GPMCINT | GPMC | gpmc_sinterrupt |

*Xem đầy đủ bảng interrupt mapping trong tài liệu reference để biết tất cả 128 interrupt sources.*

## 6.4 Crypto DMA Events  

AM335x cung cấp các DMA events cho cryptographic operations thông qua AES và SHA2 modules:

**AES Module Events:**
- Events 1-12: AES0 và AES1 request contexts và data transfers trên Secure và Public HIB
- Bao gồm: context input request, data input request, data output request cho cả secure và public HIB

**SHA2 Module Events:**
- Events 21-26: SHA2MD5 Module 1 requests cho contexts và data transfers
- Hỗ trợ secure và public HIB operations

**DES Module Events:**
- Events 15-20: DES Module requests cho secure và public HIB operations

## 6.5 PWM Events

Timer và eCAP events được sử dụng cho PWM (Pulse Width Modulation) operations:

**Timer Events (Event 0):**
- TIMER5-TIMER7 MUX input từ IO signals
- eCAP0-eCAP2 MUX input từ IO signals

**UART Events:**
- UART0-UART5 mapped đến các event numbers khác nhau

**GPIO Events:**  
- GPIO 0-3 banks với multiple interrupt lines

**Additional PWM Sources:**
- McASP0, McASP1 interrupts
- 3PGSW (Ethernet switch) 
- DCAN0, DCAN1 (CAN controllers)
- DCAM (Camera interface)

## 6.6 INTC Registers

### 6.6.1 Chi tiết các thanh ghi INTC

#### 6.6.1.1 INTC_REVISION Register (offset = 0h) [reset = 50h]

Register mask: FFFFFFFFh

Thanh ghi này chứa IP revision code.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-8 | RESERVED | R | 0h | Reads returns 0 |
| 7-0 | Rev | R | 50h | IP revision<br>[7:4] Major revision<br>[3:0] Minor revision<br>Examples: 0x10 for 1.0, 0x21 for 2.1 |

#### 6.6.1.2 INTC_SYSCONFIG Register (offset = 10h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này kiểm soát các parameters khác nhau của OCP interface.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-5 | RESERVED | R/W | 0h | - |
| 4-3 | RESERVED | R | 0h | Write 0's for future compatibility<br>Reads returns 0 |
| 2 | RESERVED | R/W | 0h | - |
| 1 | SoftReset | R/W | 0h | Software reset<br>Set this bit to 1 to trigger a module reset<br>The bit is automatically reset by the hardware<br>During reads, it always returns 0<br>0h(Read) = always_Always returns 0<br>1h(Read) = never_never happens |
| 0 | AutoIdle | R/W | 0h | Internal OCP clock gating strategy<br>0h = clkfree: OCP clock is free running<br>1h = autoJkGate: Automatic OCP clock gating strategy is applied, based on the OCP interface activity |

#### 6.6.1.3 INTC_SYSSTATUS Register (offset = 14h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này cung cấp thông tin trạng thái về module.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-8 | RESERVED | R | 0h | - |
| 7-1 | RESERVED | R | 0h | Reserved for OCP socket status information<br>Read returns 0 |
| 0 | ResetDone | R | X | Internal reset monitoring<br>0h = rstOngoing: Internal module reset is on-going<br>1h = rstComp: Reset completed |

#### 6.6.1.4 INTC_SIR_IRQ Register (offset = 40h) [reset = FFFFFF80h]

Register mask: FFFFFFFFh

Thanh ghi này cung cấp currently active IRQ interrupt number.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-7 | SpuriousIRQ | R/W | 1FFFFFh | Spurious IRQ flag |
| 6-0 | ActiveIRQ | R/W | 0h | Active IRQ number |

#### 6.6.1.5 INTC_SIR_FIQ Register (offset = 44h) [reset = FFFFFF80h]

Register mask: FFFFFFFFh

Thanh ghi này cung cấp currently active FIQ interrupt number.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-7 | SpuriousFIQ | R | 1FFFFFh | Spurious FIQ flag |
| 6-0 | ActiveFIQ | R | 0h | Active FIQ number |

#### 6.6.1.6 INTC_CONTROL Register (offset = 48h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa các new interrupt agreement bits.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-2 | RESERVED | R | 0h | Write 0's for future compatibility<br>Reads returns 0 |
| 1 | NewFIQAgr | W | 0h | Reset FIQ output and enable new FIQ generation<br>0h(Write) = nofun_no function effect<br>1h(Write) = NewFiq_Reset FIQ output and enable new FIQ generation |
| 0 | NewIRQAgr | W | 0h | New IRQ generation<br>0h(Write) = nofun_no function effect<br>1h(Write) = Newlrq_Reset IRQ output and enable new IRQ generation |

#### 6.6.1.7 INTC_PROTECTION Register (offset = 4Ch) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này kiểm soát protection của các thanh ghi khác. Thanh ghi này chỉ có thể được accessed ở privileged mode, bất kể giá trị hiện tại của protection bit.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-1 | RESERVED | R | 0h | Write 0's for future compatibility<br>Reads returns 0 |
| 0 | Protection | R/W | 0h | Protection mode<br>0h = ProtMDis: Protection mode disabled (default)<br>1h = ProtMEnb: Protection mode enabled. When enabled, only privileged mode can access registers |

#### 6.6.1.8 INTC_IDLE Register (offset = 50h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này kiểm soát clock auto-idle cho functional clock và input synchronisers.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-2 | RESERVED | R | 0h | Write 0's for future compatibility<br>Reads returns 0 |
| 1 | Turbo | R/W | 0h | Input synchronizer clock auto-gating<br>0h = SyncFree: Input synchronizer clock is free running (default)<br>1h = SyncAuto: Input synchronizer clock is auto-gated based on interrupt input activity |
| 0 | FuncIdle | R/W | 0h | Functional clock auto-idle mode<br>0h = FuncAuto: Functional clock gating strategy is applied (default)<br>1h = FuncFree: Functional clock is free-running |

#### 6.6.1.9 INTC_IRQ_PRIORITY Register (offset = 60h) [reset = FFFFFFC0h]

Register mask: FFFFFFFFh

Thanh ghi này cung cấp currently active IRQ priority level.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-7 | SpuriousIRQflag | R | 1FFFFFh | Spurious IRQ flag |
| 6-0 | IRQPriority | R | 40h | Current IRQ priority |

#### 6.6.1.10 INTC_FIQ_PRIORITY Register (offset = 64h) [reset = FFFFFFC0h]

Register mask: FFFFFFFFh

Thanh ghi này cung cấp currently active FIQ priority level.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-7 | SpuriousFIQflag | R | 1FFFFFh | Spurious FIQ flag |
| 6-0 | FIQPriority | R | 40h | Current FIQ priority |

#### 6.6.1.11 INTC_THRESHOLD Register (offset = 68h) [reset = FFh]

Register mask: FFFFFFFFh

Thanh ghi này sets priority threshold.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-8 | RESERVED | R | 0h | Reads returns 0 |
| 7-0 | PriorityThreshold | R/W | FFh | Priority threshold<br>Values used are 00h to 3Fh<br>Value FFh disables priority threshold |

#### 6.6.1.12 INTC_ITR0 Register (offset = 80h) [reset = 0h]

Register mask: 0h

Thanh ghi này hiển thị raw interrupt input status trước khi masking.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | Itr | R | X | Interrupt status before masking |

#### 6.6.1.13 INTC_MIR0 Register (offset = 84h) [reset = FFFFFFFFh]

Register mask: FFFFFFFFh

Thanh ghi này chứa interrupt mask.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | Mir | R/W | FFFFFFFFh | Interrupt mask |

#### 6.6.1.14 INTC_MIR_CLEAR0 Register (offset = 88h) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để clear interrupt mask bits.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | MirClear | W | X | Write 1 clears the mask bit to 0, reads return 0 |

#### 6.6.1.15 INTC_MIR_SET0 Register (offset = 8Ch) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để set interrupt mask bits.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | MirSet | W | X | Write 1 sets the mask bit to 1, reads return 0 |

#### 6.6.1.16 INTC_ISR_SET0 Register (offset = 90h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này được sử dụng để set software interrupt bits. Nó cũng được sử dụng để đọc currently active software interrupts.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | IsrSet | R/W | 0h | Reads returns the currently active software interrupts. Write 1 sets the software interrupt bits to 1 |

#### 6.6.1.17 INTC_ISR_CLEAR0 Register (offset = 94h) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để clear software interrupt bits.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | IsrClear | W | X | Write 1 clears the software interrupt bits to 0, reads return 0 |

#### 6.6.1.18 INTC_PENDING_IRQ0 Register (offset = 98h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa IRQ status sau khi masking.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | PendingIRQ | R | 0h | IRQ status after masking |

#### 6.6.1.19 INTC_PENDING_FIQ0 Register (offset = 9Ch) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa FIQ status sau khi masking.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | PendingFIQ | R | 0h | FIQ status after masking |

#### 6.6.1.40 INTC_MIR_SET3 Register (offset = ECh) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để set interrupt mask bits (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | MirSet | W | X | Write 1 sets the mask bit to 1, reads return 0 |

#### 6.6.1.41 INTC_ISR_SET3 Register (offset = F0h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này được sử dụng để set software interrupt bits (interrupts 96-127). Nó cũng được sử dụng để đọc currently active software interrupts.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | IsrSet | R/W | 0h | Reads returns the currently active software interrupts. Write 1 sets the software interrupt bits to 1 |

#### 6.6.1.42 INTC_ISR_CLEAR3 Register (offset = F4h) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để clear software interrupt bits (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | IsrClear | W | X | Write 1 clears the software interrupt bits to 0, reads return 0 |

#### 6.6.1.43 INTC_PENDING_IRQ3 Register (offset = F8h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa IRQ status sau khi masking (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | PendingIRQ | R | 0h | IRQ status after masking |

#### 6.6.1.44 INTC_PENDING_FIQ3 Register (offset = FCh) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa FIQ status sau khi masking (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | PendingFIQ | R | 0h | FIQ status after masking |

#### 6.6.1.45 INTC_ILR_0 to INTC_ILR_127 Registers (offset = 100h to 2FCh) [reset = 0h]

Register mask: FFFFFFFFh

Có 128 thanh ghi ILR (m = 0 đến 127), mỗi thanh ghi tương ứng với một interrupt line. Các thanh ghi này được sử dụng để cấu hình priority và routing (IRQ/FIQ) cho mỗi interrupt.

**Register Layout:**

Các thanh ghi ILR được địa chỉ tại:
- INTC_ILR_0: offset 100h
- INTC_ILR_1: offset 104h
- INTC_ILR_2: offset 108h
- ...
- INTC_ILR_127: offset 2FCh

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-8 | RESERVED | R | 0h | Write 0's for future compatibility<br>Reads returns 0 |
| 7-2 | Priority | R/W | 0h | Interrupt priority<br>Valid range: 0x00 (highest priority) to 0x3F (lowest priority) |
| 1 | RESERVED | R/W | 0h | - |
| 0 | FIQ/NIRQ | R/W | 0h | Interrupt IRQ FIQ mapping<br>0h = IntIRQ: Interrupt is routed to IRQ<br>1h = IntFIQ: Interrupt is routed to FIQ (this selection is reserved on GP devices) |

**Lưu ý quan trọng về ILR registers:**

1. **Priority Values:**
   - 0x00 = Highest priority
   - 0x3F = Lowest priority
   - Priority values từ 0x00 đến 0x3F được sử dụng
   - Các giá trị khác là reserved

2. **FIQ Routing:**
   - FIQ không khả dụng trên General Purpose (GP) devices
   - Chỉ nên sử dụng IRQ routing trên GP devices
   - Trên devices hỗ trợ FIQ, có thể route các high-priority interrupts đến FIQ

3. **Priority Grouping:**
   - Khi sử dụng priority threshold mechanism, cần phải group priorities cẩn thận
   - Tất cả FIQ priorities nên cao hơn tất cả IRQ priorities
   - Điều này đảm bảo FIQ luôn có priority cao hơn IRQ

4. **Default Configuration:**
   - Mặc định, tất cả interrupts được route đến IRQ
   - Mặc định, tất cả interrupts có priority 0x00 (highest)
   - Programmer cần reconfigure theo yêu cầu của application

**Lưu ý:**
- Các thanh ghi ITRn, MIRn, MIR_CLEARn, MIR_SETn, ISR_SETn, ISR_CLEARn, PENDING_IRQn, và PENDING_FIQn có 4 instances (n=0,1,2,3) để cover tất cả 128 interrupt lines
- Mỗi instance xử lý 32 interrupt lines
- Instance 0: Interrupts 0-31
- Instance 1: Interrupts 32-63  
- Instance 2: Interrupts 64-95
- Instance 3: Interrupts 96-127

#### 6.6.1.21 INTC_ITR1 Register (offset = A0h) [reset = 0h]

Register mask: 0h

Thanh ghi này hiển thị raw interrupt input status trước khi masking (interrupts 32-63).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | Itr | R | X | Interrupt status before masking |

#### 6.6.1.22 INTC_MIR1 Register (offset = A4h) [reset = FFFFFFFFh]

Register mask: FFFFFFFFh

Thanh ghi này chứa interrupt mask (interrupts 32-63).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | Mir | R/W | FFFFFFFFh | Interrupt mask |

#### 6.6.1.23 INTC_MIR_CLEAR1 Register (offset = A8h) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để clear interrupt mask bits (interrupts 32-63).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | MirClear | W | X | Write 1 clears the mask bit to 0, reads return 0 |

#### 6.6.1.24 INTC_MIR_SET1 Register (offset = ACh) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để set interrupt mask bits (interrupts 32-63).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | MirSet | W | X | Write 1 sets the mask bit to 1, reads return 0 |

#### 6.6.1.25 INTC_ISR_SET1 Register (offset = B0h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này được sử dụng để set software interrupt bits (interrupts 32-63). Nó cũng được sử dụng để đọc currently active software interrupts.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | IsrSet | R/W | 0h | Reads returns the currently active software interrupts. Write 1 sets the software interrupt bits to 1 |

#### 6.6.1.26 INTC_ISR_CLEAR1 Register (offset = B4h) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để clear software interrupt bits (interrupts 32-63).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | IsrClear | W | X | Write 1 clears the software interrupt bits to 0, reads return 0 |

#### 6.6.1.27 INTC_PENDING_IRQ1 Register (offset = B8h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa IRQ status sau khi masking (interrupts 32-63).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | PendingIRQ | R | 0h | IRQ status after masking |

#### 6.6.1.28 INTC_PENDING_FIQ1 Register (offset = BCh) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa FIQ status sau khi masking (interrupts 32-63).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | PendingFIQ | R | 0h | FIQ status after masking |

#### 6.6.1.29 INTC_ITR2 Register (offset = C0h) [reset = 0h]

Register mask: 0h

Thanh ghi này hiển thị raw interrupt input status trước khi masking (interrupts 64-95).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | Itr | R | X | Interrupt status before masking |

#### 6.6.1.30 INTC_MIR2 Register (offset = C4h) [reset = FFFFFFFFh]

Register mask: FFFFFFFFh

Thanh ghi này chứa interrupt mask (interrupts 64-95).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | Mir | R/W | FFFFFFFFh | Interrupt mask |

#### 6.6.1.31 INTC_MIR_CLEAR2 Register (offset = C8h) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để clear interrupt mask bits (interrupts 64-95).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | MirClear | W | X | Write 1 clears the mask bit to 0, reads return 0 |

#### 6.6.1.32 INTC_MIR_SET2 Register (offset = CCh) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để set interrupt mask bits (interrupts 64-95).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | MirSet | W | X | Write 1 sets the mask bit to 1, reads return 0 |

#### 6.6.1.33 INTC_ISR_SET2 Register (offset = D0h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này được sử dụng để set software interrupt bits (interrupts 64-95). Nó cũng được sử dụng để đọc currently active software interrupts.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | IsrSet | R/W | 0h | Reads returns the currently active software interrupts. Write 1 sets the software interrupt bits to 1 |

#### 6.6.1.34 INTC_ISR_CLEAR2 Register (offset = D4h) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để clear software interrupt bits (interrupts 64-95).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | IsrClear | W | X | Write 1 clears the software interrupt bits to 0, reads return 0 |

#### 6.6.1.35 INTC_PENDING_IRQ2 Register (offset = D8h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa IRQ status sau khi masking (interrupts 64-95).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | PendingIRQ | R | 0h | IRQ status after masking |

#### 6.6.1.36 INTC_PENDING_FIQ2 Register (offset = DCh) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa FIQ status sau khi masking (interrupts 64-95).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | PendingFIQ | R | 0h | FIQ status after masking |

#### 6.6.1.37 INTC_ITR3 Register (offset = E0h) [reset = 0h]

Register mask: 0h

Thanh ghi này hiển thị raw interrupt input status trước khi masking (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | Itr | R | X | Interrupt status before masking |

#### 6.6.1.38 INTC_MIR3 Register (offset = E4h) [reset = FFFFFFFFh]

Register mask: FFFFFFFFh

Thanh ghi này chứa interrupt mask (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | Mir | R/W | FFFFFFFFh | Interrupt mask |

#### 6.6.1.39 INTC_MIR_CLEAR3 Register (offset = E8h) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để clear interrupt mask bits (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | MirClear | W | X | Write 1 clears the mask bit to 0, reads return 0 |

#### 6.6.1.40 INTC_MIR_SET3 Register (offset = ECh) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để set interrupt mask bits (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | MirSet | W | X | Write 1 sets the mask bit to 1, reads return 0 |

#### 6.6.1.41 INTC_ISR_SET3 Register (offset = F0h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này được sử dụng để set software interrupt bits (interrupts 96-127). Nó cũng được sử dụng để đọc currently active software interrupts.

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | IsrSet | R/W | 0h | Reads returns the currently active software interrupts. Write 1 sets the software interrupt bits to 1 |

#### 6.6.1.42 INTC_ISR_CLEAR3 Register (offset = F4h) [reset = 0h]

Register mask: 0h

Thanh ghi này được sử dụng để clear software interrupt bits (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | IsrClear | W | X | Write 1 clears the software interrupt bits to 0, reads return 0 |

#### 6.6.1.43 INTC_PENDING_IRQ3 Register (offset = F8h) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa IRQ status sau khi masking (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | PendingIRQ | R | 0h | IRQ status after masking |

#### 6.6.1.44 INTC_PENDING_FIQ3 Register (offset = FCh) [reset = 0h]

Register mask: FFFFFFFFh

Thanh ghi này chứa FIQ status sau khi masking (interrupts 96-127).

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | PendingFIQ | R | 0h | FIQ status after masking |

### 6.6.2 Bảng tổng hợp các thanh ghi INTC

| Offset | Acronym | Register Name | Section |
|--------|---------|---------------|---------|
| 0h | INTC_REVISION | Revision register | Section 6.6.1.1 |
| 10h | INTC_SYSCONFIG | System Configuration | Section 6.6.1.2 |
| 14h | INTC_SYSSTATUS | System Status | Section 6.6.1.3 |
| 40h | INTC_SIR_IRQ | Active IRQ number | Section 6.6.1.4 |
| 44h | INTC_SIR_FIQ | Active FIQ number | Section 6.6.1.5 |
| 48h | INTC_CONTROL | Control register | Section 6.6.1.6 |
| 4Ch | INTC_PROTECTION | Protection register | Section 6.6.1.7 |
| 50h | INTC_IDLE | Idle register | Section 6.6.1.8 |
| 60h | INTC_IRQ_PRIORITY | IRQ Priority | Section 6.6.1.9 |
| 64h | INTC_FIQ_PRIORITY | FIQ Priority | Section 6.6.1.10 |
| 68h | INTC_THRESHOLD | Threshold register | Section 6.6.1.11 |
| **Instance 0 (Interrupts 0-31)** |||
| 80h | INTC_ITR0 | Input Status 0 | Section 6.6.1.12 |
| 84h | INTC_MIR0 | Mask register 0 | Section 6.6.1.13 |
| 88h | INTC_MIR_CLEAR0 | Mask Clear 0 | Section 6.6.1.14 |
| 8Ch | INTC_MIR_SET0 | Mask Set 0 | Section 6.6.1.15 |
| 90h | INTC_ISR_SET0 | Software Interrupt Set 0 | Section 6.6.1.16 |
| 94h | INTC_ISR_CLEAR0 | Software Interrupt Clear 0 | Section 6.6.1.17 |
| 98h | INTC_PENDING_IRQ0 | Pending IRQ 0 | Section 6.6.1.18 |
| 9Ch | INTC_PENDING_FIQ0 | Pending FIQ 0 | Section 6.6.1.19 |
| **Instance 1 (Interrupts 32-63)** |||
| A0h | INTC_ITR1 | Input Status 1 | Section 6.6.1.21 |
| A4h | INTC_MIR1 | Mask register 1 | Section 6.6.1.22 |
| A8h | INTC_MIR_CLEAR1 | Mask Clear 1 | Section 6.6.1.23 |
| ACh | INTC_MIR_SET1 | Mask Set 1 | Section 6.6.1.24 |
| B0h | INTC_ISR_SET1 | Software Interrupt Set 1 | Section 6.6.1.25 |
| B4h | INTC_ISR_CLEAR1 | Software Interrupt Clear 1 | Section 6.6.1.26 |
| B8h | INTC_PENDING_IRQ1 | Pending IRQ 1 | Section 6.6.1.27 |
| BCh | INTC_PENDING_FIQ1 | Pending FIQ 1 | Section 6.6.1.28 |
| **Instance 2 (Interrupts 64-95)** |||
| C0h | INTC_ITR2 | Input Status 2 | Section 6.6.1.29 |
| C4h | INTC_MIR2 | Mask register 2 | Section 6.6.1.30 |
| C8h | INTC_MIR_CLEAR2 | Mask Clear 2 | Section 6.6.1.31 |
| CCh | INTC_MIR_SET2 | Mask Set 2 | Section 6.6.1.32 |
| D0h | INTC_ISR_SET2 | Software Interrupt Set 2 | Section 6.6.1.33 |
| D4h | INTC_ISR_CLEAR2 | Software Interrupt Clear 2 | Section 6.6.1.34 |
| D8h | INTC_PENDING_IRQ2 | Pending IRQ 2 | Section 6.6.1.35 |
| DCh | INTC_PENDING_FIQ2 | Pending FIQ 2 | Section 6.6.1.36 |
| **Instance 3 (Interrupts 96-127)** |||
| E0h | INTC_ITR3 | Input Status 3 | Section 6.6.1.37 |
| E4h | INTC_MIR3 | Mask register 3 | Section 6.6.1.38 |
| E8h | INTC_MIR_CLEAR3 | Mask Clear 3 | Section 6.6.1.39 |
| ECh | INTC_MIR_SET3 | Mask Set 3 | Section 6.6.1.40 |
| F0h | INTC_ISR_SET3 | Software Interrupt Set 3 | Section 6.6.1.41 |
| F4h | INTC_ISR_CLEAR3 | Software Interrupt Clear 3 | Section 6.6.1.42 |
| F8h | INTC_PENDING_IRQ3 | Pending IRQ 3 | Section 6.6.1.43 |
| FCh | INTC_PENDING_FIQ3 | Pending FIQ 3 | Section 6.6.1.44 |
| **Interrupt Priority Registers** |||
| 100h-2FCh | INTC_ILR_0 to INTC_ILR_127 | Interrupt Priority and Routing | Section 6.6.1.45 |

**Tổng số thanh ghi:** 
- 11 thanh ghi control/status chính
- 32 thanh ghi cho 4 instances (8 registers × 4)
- 128 thanh ghi ILR (interrupt line registers)
- **Tổng cộng: 171 thanh ghi**

---

## Tóm tắt các điểm quan trọng

1. **Priority System:** 0x0 = cao nhất, 0x7F = thấp nhất
2. **Masking:** Individual masking qua MIRn registers, Priority masking qua THRESHOLD
3. **Processing:** IRQ/FIQ separation → Priority sorting → Handler execution
4. **Preemption:** Nested interrupts được hỗ trợ với proper threshold configuration
5. **Power Saving:** Auto-idle modes cho interface, functional và synchronizer clocks
6. **Spurious Handling:** Detection mechanism cho invalid interrupts trong sorting window
7. **128 Interrupt Sources:** Covering tất cả peripherals và subsystems của AM335x

---

## Ví dụ thực tế sử dụng INTC

### Example 1: Basic Interrupt Setup cho UART0

```c
// Define base addresses
#define INTC_BASE       0x48200000
#define UART0_IRQ       72

// Initialize INTC for UART0 interrupt
void setup_uart0_interrupt(void) {
    volatile uint32_t *intc_base = (uint32_t *)INTC_BASE;
    
    // 1. Enable interface clock auto-idle
    *(intc_base + 0x10/4) = 0x1;  // SYSCONFIG.AUTOIDLE = 1
    
    // 2. Set priority for UART0 (priority 10, route to IRQ)
    uint32_t ilr_offset = 0x100 + (UART0_IRQ * 4);
    *(intc_base + ilr_offset/4) = (10 << 2) | 0x0;  // Priority=10, IRQ
    
    // 3. Unmask UART0 interrupt (IRQ 72 is in MIR2)
    // MIR_CLEAR2 offset = 0xC8h, bit position = 72-64 = 8
    *(intc_base + 0xC8/4) = (1 << 8);  // Clear mask bit
    
    // 4. Set priority threshold to allow all
    *(intc_base + 0x68/4) = 0xFF;  // Disable threshold
}
```

### Example 2: Setup Multiple Interrupts với Priority

```c
// Setup GPIO0 (IRQ 96) and TIMER2 (IRQ 68) with different priorities
void setup_multiple_interrupts(void) {
    volatile uint32_t *intc_base = (uint32_t *)INTC_BASE;
    
    // GPIO0: High priority (5), route to IRQ
    *(intc_base + (0x100 + 96*4)/4) = (5 << 2) | 0x0;
    
    // TIMER2: Lower priority (15), route to IRQ
    *(intc_base + (0x100 + 68*4)/4) = (15 << 2) | 0x0;
    
    // Unmask GPIO0 (IRQ 96 is in MIR3, bit 0)
    *(intc_base + 0xE8/4) = (1 << 0);  // MIR_CLEAR3
    
    // Unmask TIMER2 (IRQ 68 is in MIR2, bit 4)
    *(intc_base + 0xC8/4) = (1 << 4);  // MIR_CLEAR2
}
```

### Example 3: Interrupt Handler với Preemption Support

```c
void irq_handler(void) {
    volatile uint32_t *intc_base = (uint32_t *)INTC_BASE;
    
    // Save current threshold
    uint32_t old_threshold = *(intc_base + 0x68/4);
    
    // Read active IRQ number
    uint32_t sir_irq = *(intc_base + 0x40/4);
    uint32_t active_irq = sir_irq & 0x7F;
    
    // Check spurious flag
    if (sir_irq & 0xFFFFFF80) {
        // Spurious interrupt, just acknowledge and return
        *(intc_base + 0x48/4) = 0x1;  // NewIRQAgr
        return;
    }
    
    // Read and set priority threshold for preemption
    uint32_t irq_priority = *(intc_base + 0x60/4) & 0x7F;
    *(intc_base + 0x68/4) = irq_priority;  // Set threshold
    
    // Acknowledge interrupt to allow preemption
    *(intc_base + 0x48/4) = 0x1;  // NewIRQAgr
    
    // Enable IRQs at ARM level for preemption
    __asm__ volatile("cpsie i");
    
    // Call specific interrupt handler
    switch(active_irq) {
        case 72:  // UART0
            uart0_irq_handler();
            break;
        case 96:  // GPIO0
            gpio0_irq_handler();
            break;
        // Add more cases as needed
    }
    
    // Disable IRQs before restoring threshold
    __asm__ volatile("cpsid i");
    
    // Restore original threshold
    *(intc_base + 0x68/4) = old_threshold;
}
```

### Example 4: Software Interrupt Trigger

```c
// Trigger software interrupt for testing
void trigger_software_interrupt(uint32_t irq_num) {
    volatile uint32_t *intc_base = (uint32_t *)INTC_BASE;
    
    // Determine which ISR_SET register (0-3) and bit position
    uint32_t reg_index = irq_num / 32;
    uint32_t bit_pos = irq_num % 32;
    
    // ISR_SET0=0x90, ISR_SET1=0xB0, ISR_SET2=0xD0, ISR_SET3=0xF0
    uint32_t isr_set_offsets[] = {0x90, 0xB0, 0xD0, 0xF0};
    
    // Set the software interrupt bit
    *(intc_base + isr_set_offsets[reg_index]/4) = (1 << bit_pos);
}

// Clear software interrupt
void clear_software_interrupt(uint32_t irq_num) {
    volatile uint32_t *intc_base = (uint32_t *)INTC_BASE;
    
    uint32_t reg_index = irq_num / 32;
    uint32_t bit_pos = irq_num % 32;
    
    // ISR_CLEAR0=0x94, ISR_CLEAR1=0xB4, ISR_CLEAR2=0xD4, ISR_CLEAR3=0xF4
    uint32_t isr_clear_offsets[] = {0x94, 0xB4, 0xD4, 0xF4};
    
    // Clear the software interrupt bit
    *(intc_base + isr_clear_offsets[reg_index]/4) = (1 << bit_pos);
}
```

### Example 5: Checking Pending Interrupts

```c
// Check if any interrupts are pending for a specific range
uint32_t check_pending_irqs(uint32_t start_irq, uint32_t end_irq) {
    volatile uint32_t *intc_base = (uint32_t *)INTC_BASE;
    
    // PENDING_IRQ0=0x98, 1=0xB8, 2=0xD8, 3=0xF8
    uint32_t pending_offsets[] = {0x98, 0xB8, 0xD8, 0xF8};
    
    uint32_t count = 0;
    
    for (uint32_t irq = start_irq; irq <= end_irq; irq++) {
        uint32_t reg_index = irq / 32;
        uint32_t bit_pos = irq % 32;
        
        uint32_t pending = *(intc_base + pending_offsets[reg_index]/4);
        
        if (pending & (1 << bit_pos)) {
            count++;
        }
    }
    
    return count;
}
```

### Example 6: Priority Threshold Configuration

```c
// Configure priority threshold to mask low-priority interrupts
void set_priority_threshold(uint8_t threshold) {
    volatile uint32_t *intc_base = (uint32_t *)INTC_BASE;
    
    // Valid threshold values: 0x00-0x3F, 0xFF to disable
    if (threshold <= 0x3F || threshold == 0xFF) {
        *(intc_base + 0x68/4) = threshold;
    }
}

// Example: Only allow high priority interrupts (0-9)
void allow_only_high_priority(void) {
    set_priority_threshold(9);  // Mask priorities 10-63
}

// Disable priority masking
void disable_priority_masking(void) {
    set_priority_threshold(0xFF);
}
```

### Example 7: Bulk Interrupt Mask Operations

```c
// Mask multiple interrupts at once
void mask_interrupts(uint32_t *irq_list, uint32_t count) {
    volatile uint32_t *intc_base = (uint32_t *)INTC_BASE;
    uint32_t mir_set_offsets[] = {0x8C, 0xAC, 0xCC, 0xEC};
    
    for (uint32_t i = 0; i < count; i++) {
        uint32_t irq = irq_list[i];
        uint32_t reg_index = irq / 32;
        uint32_t bit_pos = irq % 32;
        
        *(intc_base + mir_set_offsets[reg_index]/4) = (1 << bit_pos);
    }
}

// Unmask multiple interrupts at once
void unmask_interrupts(uint32_t *irq_list, uint32_t count) {
    volatile uint32_t *intc_base = (uint32_t *)INTC_BASE;
    uint32_t mir_clear_offsets[] = {0x88, 0xA8, 0xC8, 0xE8};
    
    for (uint32_t i = 0; i < count; i++) {
        uint32_t irq = irq_list[i];
        uint32_t reg_index = irq / 32;
        uint32_t bit_pos = irq % 32;
        
        *(intc_base + mir_clear_offsets[reg_index]/4) = (1 << bit_pos);
    }
}

// Example usage
void setup_peripheral_interrupts(void) {
    uint32_t irqs[] = {72, 73, 74, 96, 97, 98};  // UART0-2, GPIO0-2
    unmask_interrupts(irqs, 6);
}
```

### Example 8: Reading Interrupt Status

```c
// Get detailed interrupt status
typedef struct {
    uint32_t raw_status;      // Before masking
    uint32_t pending_irq;     // After masking (IRQ)
    uint32_t pending_fiq;     // After masking (FIQ)
    uint32_t active_irq;      // Currently active IRQ
    uint32_t active_priority; // Priority of active IRQ
} intc_status_t;

void get_intc_status(uint32_t irq_num, intc_status_t *status) {
    volatile uint32_t *intc_base = (uint32_t *)INTC_BASE;
    
    uint32_t reg_index = irq_num / 32;
    uint32_t bit_pos = irq_num % 32;
    
    // Read raw interrupt status (ITRn registers)
    uint32_t itr_offsets[] = {0x80, 0xA0, 0xC0, 0xE0};
    status->raw_status = *(intc_base + itr_offsets[reg_index]/4);
    
    // Read pending IRQ status
    uint32_t pending_irq_offsets[] = {0x98, 0xB8, 0xD8, 0xF8};
    status->pending_irq = *(intc_base + pending_irq_offsets[reg_index]/4);
    
    // Read pending FIQ status
    uint32_t pending_fiq_offsets[] = {0x9C, 0xBC, 0xDC, 0xFC};
    status->pending_fiq = *(intc_base + pending_fiq_offsets[reg_index]/4);
    
    // Read active IRQ number
    status->active_irq = *(intc_base + 0x40/4) & 0x7F;
    
    // Read active IRQ priority
    status->active_priority = *(intc_base + 0x60/4) & 0x7F;
}
```

---

## Debug Tips và Best Practices

### 1. Spurious Interrupt Handling
- Luôn kiểm tra spurious flag trong ISR
- Spurious interrupts có thể xảy ra khi mask thay đổi trong sorting window
- Acknowledge ngay và return nếu detect spurious

### 2. Priority Configuration
- Ưu tiên cao (0-9): Critical real-time interrupts
- Ưu tiên trung bình (10-31): Normal peripheral interrupts
- Ưu tiên thấp (32-63): Background/maintenance interrupts

### 3. Preemption Guidelines
- Chỉ enable preemption khi thực sự cần thiết
- Luôn save/restore threshold và ARM context
- Sử dụng Data Synchronization Barrier trước enable IRQ

### 4. Performance Optimization
- Enable TURBO mode (IDLE[1]=1) cho low-latency applications
- Sử dụng FuncIdle (IDLE[0]=0) cho power-critical applications
- Configure AutoIdle (SYSCONFIG[0]=1) cho OCP clock gating

### 5. Common Mistakes to Avoid
- Không acknowledge interrupt (NewIRQAgr)
- Thay đổi MIR trong interrupt sorting window
- Quên clear interrupt condition ở peripheral
- Không kiểm tra spurious flag
- Priority threshold quá cao, blocking critical interrupts

---

**Document Version:** 1.0  
**Target Device:** Texas Instruments AM335x (ARM Cortex-A8)  
**Created for:** AI Training and Embedded Systems Development

# AM335x Power, Reset, and Clock Management (PRCM)

## Chapter 8: Power Management Architecture

---

## 8.1 Introduction

The AM335x device power-management architecture ensures maximum performance and operation time while offering versatile power-management techniques for maximum design flexibility. The architecture is built on three fundamental levels:

1. **Clock Management** - Control of clock gating and distribution
2. **Power Management** - Control of power domain switching  
3. **Voltage Management** - Control of operating voltages

These management levels are enforced through **domains** - groups of modules that share common resources (clock source, voltage source, or power switch).

---

## 8.2 Device Power-Management Architecture Building Blocks

### 8.2.1 Domain Concept

A **domain** is a group of modules or subsections that share a common entity:
- **Clock Domain** - Modules sharing a common clock source
- **Power Domain** - Modules sharing a common power switch
- **Voltage Domain** - Modules sharing a common voltage source

Each domain is managed by a dedicated policy manager. For example, a clock domain's clocks are managed by a clock manager within the PRCM module.

---

## 8.3 Clock Management

The PRCM module manages the gating (switching off) and enabling of clocks to device modules based on module requirements.

### 8.3.1 Module Clock Types

Each module requires specific clock inputs divided into two categories:

#### 8.3.1.1 Interface Clock (ICLK)

**Characteristics:**
- Ensures proper communication between module/subsystem and interconnect
- Supplies the system interconnect interface and registers of the module
- Typically one interface clock per module (some may have multiple)
- Managed at device level
- Identified by `_ICLK` suffix in PRCM

#### 8.3.1.2 Functional Clock (FCLK)

**Characteristics:**
- Supplies the functional part of a module or subsystem
- A module can have one or more functional clocks:
  - **Mandatory clocks**: Required for module operation
  - **Optional clocks**: Used for specific features, can be shut down without stopping module
- Distributed directly to modules through dedicated clock tree
- Identified by `_FCLK` suffix in PRCM

### 8.3.2 Module-Level Clock Management

The PRCM module differentiates clock-management behavior based on whether a module can:
- **Initiate transactions** (master/initiator modules) → Master Standby Protocol
- **Only respond to transactions** (slave/target modules) → Slave Idle Protocol

#### 8.3.2.1 Master Standby Protocol

Used for master modules that can initiate transactions on the device interconnect.

**Standby Mode Configuration:**  
Set via `<Module>_SYSCONFIG.MIDLEMODE` or `<Module>_SYSCONFIG.STANDBYMODE`

| Mode Value | Mode Name | Description |
|------------|-----------|-------------|
| 0x0 | Force-standby | Module unconditionally asserts standby request regardless of internal operations. PRCM may gate clocks immediately. **Risk of data loss** |
| 0x1 | No-standby | Module never asserts standby request. Clocks remain active. Safe but not power-efficient |
| 0x2 | Smart-standby | Module asserts standby based on internal activity. Standby signal asserted only when all transactions complete and module idle. PRCM can then gate clocks |
| 0x3 | Smart-standby wakeup-capable | Same as smart-standby but module can generate master-related wakeup events when in STANDBY state |

**Standby Status:**  
Read from `CM_<Power_domain>_<Module>_CLKCTRL[x].STBYST`
- 0x0 = Module is functional
- 0x1 = Module is in standby mode

#### 8.3.2.2 Slave Idle Protocol

Allows PRCM module to control the state of a slave module through idle request/acknowledge handshake.

**Idle Mode Configuration:**  
Set via `<Module>_SYSCONFIG.SIDLEMODE` or `<Module>_SYSCONFIG.IDLEMODE`

| Mode Value | Mode Name | Description |
|------------|-----------|-------------|
| 0x0 | Force-idle | Module unconditionally acknowledges idle request regardless of internal operations. **Risk of data loss** |
| 0x1 | No-idle | Module never acknowledges idle request. Clocks remain active. Safe but not power-efficient |
| 0x2 | Smart-idle | Module acknowledges idle based on internal activity. Only acknowledges when internal operations complete |
| 0x3 | Smart-idle wakeup-capable | Same as smart-idle but module can generate slave-related wakeup events (interrupt or DMA request) |

**Idle Status:**  
Read from `CM_<Power_domain>_<Module>_CLKCTRL[x].IDLEST`
- 0x0 = Functional (fully functional, clocks running)
- 0x1 = In transition (between functional and idle)
- 0x2 = Idle (module idle, clocks may be gated)
- 0x3 = Disabled (module disabled by software)

#### 8.3.2.3 Module Mode Control

Software controls module operational state via `CM_<Power_domain>_<Module>_CLKCTRL[x].MODULEMODE`

| Mode Value | Mode Name | Description |
|------------|-----------|-------------|
| 0x0 | Disabled | Module is disabled. PRCM does not manage module clock and power states. Both interface and functional clocks gated |
| 0x1 | Reserved | - |
| 0x2 | Enabled | PRCM manages interface and functional clocks. Functional clock remains active unconditionally. Interface clock automatically asserted/deasserted based on clock-domain transitions |
| 0x3 | Reserved | - |

**Optional Clock Control:**  
PRCM offers direct software control of optional clocks through `OptFclken` bit in programming registers.

#### 8.3.2.4 Clock Enabling Conditions

| Clock Type | Enabling Condition |
|------------|-------------------|
| Clock with STANDBY protocol | Clock Domain ready **AND** (MStandby de-asserted **OR** Mwakeup asserted) |
| Clock with IDLE protocol (interface clock) | Clock Domain ready **AND** (Idle status = FUNCT **OR** Idle status = TRANS **OR** SWakeup asserted) |
| Clock with IDLE protocol (functional clock) | Clock Domain ready **AND** (Idle status = FUNCT **OR** Idle status = IDLE **OR** Idle status = TRANS **OR** SWakeup asserted) |
| Optional clock | Clock domain ready **AND** OptFclken = Enabled ('1') |

### 8.3.3 Clock Domain

A **clock domain** is a group of modules fed by clock signals controlled by the same clock manager in PRCM.

**Purpose:**  
Allows control of dynamic power consumption by gating clocks in a domain, cutting clocks to all modules in that domain.

#### 8.3.3.1 Clock Domain States

Clock domains transition between three states:

```
        Sleep condition
ACTIVE ─────────────────→ IDLE_TRANSITION
  ↑                              ↓
  │      All modules IDLE/STANDBY
  │      All domain clocks gated
  │                              ↓
  │                          INACTIVE
  │                              │
  └──────────────────────────────┘
   Domain sleep conditions not satisfied
   OR wake-up request received
```

**State Descriptions:**

| State | Description |
|-------|-------------|
| **ACTIVE** | • Every nondisabled slave module put out of IDLE state<br>• All interface clocks to nondisabled slave modules provided<br>• All functional and interface clocks to active master modules provided<br>• All enabled optional clocks provided |
| **IDLE_TRANSITION** | • Transitory state<br>• Every master module in STANDBY<br>• Idle request asserted to all slave modules<br>• Functional clocks to enabled slave modules remain active<br>• All enabled optional clocks provided |
| **INACTIVE** | • All clocks within clock domain gated<br>• Every slave module in IDLE state and disabled<br>• Every optional functional clock gated |

#### 8.3.3.2 Clock Transition Control

Controlled via `CM_<Clock_domain>_CLKSTCTRL[x].CLKTRCTRL`

| Value | Mode | Description |
|-------|------|-------------|
| 0x0 | NO_SLEEP | Sleep transition cannot be initiated. Wakeup transition may occur |
| 0x1 | SW_SLEEP | Software-forced sleep transition. Transition initiated when associated hardware conditions satisfied |
| 0x2 | SW_WKUP | Software-forced clock domain wake-up transition initiated |
| 0x3 | Reserved | - |

#### 8.3.3.3 Clock Domain Status

**Functional Clock Activity:**  
Read from `CM_<Clock_domain>_CLKSTCTRL[x].CLKACTIVITY_<FCLK/Clock_name_FCLK>`

| Value | Status | Description |
|-------|--------|-------------|
| 0x0 | Gated | Functional clock of clock domain is inactive |
| 0x1 | Active | Functional clock of clock domain is running |

---

## 8.4 Power Management

The PRCM module manages switching on/off of power supply to device modules. Independent power control allows turning on/off specific sections without affecting others.

### 8.4.1 Power Domain

A **power domain** is a section (group of modules) with independent and dedicated power manager. Can be turned on/off without affecting other device parts.

Each power domain can be split into:

#### 8.4.1.1 Memory Area States

| State | Description |
|-------|-------------|
| ON | Memory array powered and fully functional |
| RETENTION | Memory array powered at reduced voltage, contents preserved |
| OFF | Memory array powered down, contents lost |

#### 8.4.1.2 Logic Area States

| State | Description |
|-------|-------------|
| ON | Logic fully powered |
| OFF | Logic power switches off. All logic (DFF) lost |

### 8.4.2 Power Domain Management

The power manager ensures all hardware conditions satisfied before initiating power domain transition.

**Control and Status Registers:**

| Register/Bit Field | Type | Description |
|-------------------|------|-------------|
| `PM_<Power_domain>_PWRSTCTRL[1:0].POWERSTATE` | Control | Selects target power state: OFF, ON, or RETENTION |
| `PM_<Power_domain>_PWRSTST[1:0].POWERSTATEST` | Status | Identifies current state of power domain |
| `PM_<Power_domain>_PWRSTST[2].LOGICSTATEST` | Status | Identifies current state of logic area: OFF or ON |
| `PM_<Power_domain>_PWRSTST[5:4].MEMSTATEST` | Status | Identifies current state of memory area: OFF, ON, or RETENTION |

#### 8.4.2.1 Power-Management Techniques

##### Adaptive Voltage Scaling (AVS)

AVS is based on Smart Reflex technology for automatic control of operating voltages to reduce active power consumption.

**Operation:**
- Power-supply voltage adapted to silicon performance
- Can be static (based on predefined performance points) or dynamic (based on real-time temperature performance)
- Comparison of predefined performance points to real-time on-chip measured performance determines voltage adjustment
- Achieves optimal performance/power trade-off across technology process spectrum and temperature variation

### 8.4.3 AM335x Power Domains

The device supports four functional power domains:

1. **PD_WKUP** - Wakeup domain (always ON)
2. **PD_MPU** - MPU subsystem domain
3. **PD_PER** - Peripheral domain
4. **PD_RTC** - RTC domain
5. **PD_GFX** - Graphics domain (optional)

---

## 8.5 Power Modes

AM335x supports five power modes, ordered from highest power consumption/lowest wakeup latency to lowest power consumption/highest wakeup latency.

### 8.5.1 Active Mode

**Application State:** All features operational

**Power, Clock, and Voltage Configuration:**
- **Power supplies:** All ON
  - VDD_MPU = 1.1V (nominal)
  - VDD_CORE = 1.1V (nominal)
- **Clocks:**
  - Main Oscillator (OSC0) = ON
  - All DPLLs locked
- **Power domains:**
  - PD_PER = ON
  - PD_MPU = ON
  - PD_GFX = ON or OFF (depending on use case)
  - PD_WKUP = ON
- **DDR:** Active

**Use Case:** Normal full-performance operation

### 8.5.2 Standby Mode

**Application State:**  
DDR memory in self-refresh, contents preserved. Wakeup from any GPIO. Cortex-A8 context/register contents lost - must be saved before entering standby. On exit, context restored from DDR. Boot ROM executes and branches to system resume.

**Power, Clock, and Voltage Configuration:**
- **Power supplies:** All ON
  - VDD_MPU = 0.95V (nominal)
  - VDD_CORE = 0.95V (nominal)
- **Clocks:**
  - Main Oscillator (OSC0) = ON
  - All DPLLs in bypass
- **Power domains:**
  - PD_PER = ON
  - PD_MPU = OFF
  - PD_GFX = OFF
  - PD_WKUP = ON
- **DDR:** In self-refresh

**Key Characteristics:**
- All modules clock gated except GPIOs
- PLLs in bypass mode
- Voltage levels reduced to OPP50
- MPU context lost (save to OCMC RAM or DDR)
- Internal SRAM contents lost (PD_MPU OFF)
- Wakeup via GPIO or configured peripheral interrupts

**Power:** Lower than Active  
**Latency:** Low - fast resume

### 8.5.3 DeepSleep1 Mode

**Application State:**  
On-chip peripheral registers preserved. Wakeup from configured wakeup sources. Lowest sleep mode required for certain USB wakeup scenarios. On exit, boot ROM executes, Cortex-M3 performs peripheral context restore and system resume.

**Power, Clock, and Voltage Configuration:**
- **Power supplies:** All ON
  - VDD_MPU = 0.95V (nominal)
  - VDD_CORE = 0.95V (nominal)
- **Clocks:**
  - Main Oscillator (OSC0) = **OFF**
  - All DPLLs in bypass
- **Power domains:**
  - PD_PER = ON
  - PD_MPU = OFF
  - PD_GFX = OFF
  - PD_WKUP = ON
- **DDR:** In self-refresh

**Key Difference from Standby:**
- Main oscillator disabled
- Oscillator re-enabled by wakeup events via oscillator control circuit

**Power:** Lower than Standby  
**Latency:** Higher than Standby (oscillator restart)

### 8.5.4 DeepSleep0 Mode

**Application State:**  
All on-chip peripheral registers lost. DDR memory in self-refresh, contents preserved. Wakeup from configured wakeup sources. On exit, boot ROM executes, checks resume state, and redirects to DDR. Cortex-M3 performs peripheral context restore followed by system resume.

**Power, Clock, and Voltage Configuration:**
- **Power supplies:** All ON
  - VDD_MPU = 0.95V (nominal)
  - VDD_CORE = 0.95V (nominal)
- **Clocks:**
  - Main Oscillator (OSC0) = OFF
  - All DPLLs in bypass
- **Power domains:**
  - PD_PER = **OFF**
  - PD_MPU = OFF
  - PD_GFX = OFF
  - PD_WKUP = ON
- **DDR:** In self-refresh

**Key Characteristics:**
- All on-chip power domains shut off (except PD_WKUP and PD_RTC)
- VDD_CORE power to DPLLs turned OFF via dpll_pwr_sw_ctrl (PG 2.x only)
- VDDS_SRAM_CORE_BG in retention using SMA2.vsldo_core_auto_ramp_en (PG 2.x only)
- Internal SRAM contents lost
- Peripheral and MPU context must be saved to DDR before sleep
- OCMC RAM powered to preserve internal information
- Boot ROM checks DeepSleep0 resume state on wakeup

**Use Case:** Very low power during inactivity while maintaining DDR contents. Lowest power mode with DDR retention - avoids full cold boot.

**Power:** Very low  
**Latency:** High (context restore from DDR)

### 8.5.5 RTC-Only Mode

**Application State:**  
RTC timer remains active, all other device functionality disabled.

**Power, Clock, and Voltage Configuration:**
- **Power supplies:**
  - All OFF except VDDS_RTC
  - VDD_MPU = 0V
  - VDD_CORE = 0V
- **Clocks:**
  - Main Oscillator (OSC0) = OFF
- **Power domains:**
  - All OFF

**Key Characteristics:**
- Ultra-low power mode
- Only RTC subsystem operational
- All context and memories lost
- Only RTC power supply required
- RTC battery backup domain includes:
  - RTCSS (RTC subsystem)
  - Dedicated 32.768 kHz crystal oscillator
  - pmic_power_en I/O
  - ext_wakeup I/O

**Wakeup Sources:**
- ext_wakeup0 signal only
- RTC Alarm (ALARM) only

**Wakeup Process:**
- Device drives pmic_pwr_enable to initiate PMIC power-up sequence
- Device must go through full cold boot

**Use Case:** Ultra-low power battery-backed operation with RTC functionality only

**Power:** Extremely low  
**Latency:** Extremely high (full cold boot)

### 8.5.6 Power Mode Comparison Table

| Power Mode | Power Consumption | Wakeup Latency | Main Oscillator | PD_PER | PD_MPU | DDR State | Context Loss |
|-----------|-------------------|----------------|-----------------|---------|---------|-----------|--------------|
| Active | Highest | N/A | ON | ON | ON | Active | None |
| Standby | High | Low | ON | ON | OFF | Self-refresh | MPU only |
| DeepSleep1 | Medium | Medium | **OFF** | ON | OFF | Self-refresh | MPU only |
| DeepSleep0 | Very Low | High | OFF | **OFF** | OFF | Self-refresh | All except DDR |
| RTC-Only | Extremely Low | Extremely High | OFF | OFF | OFF | **OFF** | All |

### 8.5.7 Internal RTC LDO

The device contains an internal LDO regulator powering the RTC digital core. Can be disabled in certain configurations to save power.

**Configuration Scenarios:**

#### Scenario 1: RTC Functionality Not Used

**Connections:**
- RTC_KALDO_ENn → VDDS_RTC
- CAP_VDD_RTC → VDD_CORE
- RTC_PWRONRSTn → GND

**Result:** Internal RTC LDO disabled, external VDD_CORE supplies RTC digital core, RTC stays in reset, achieves lower power in all low power modes.

#### Scenario 2: RTC Used, RTC-Only Mode Not Required

**Connections:**
- Same as Scenario 1, but RTC_PWRONRSTn → PWRONRSTn (may require level shifting)

**Result:** Full RTC functionality without internal LDO consuming power.

#### Scenario 3: RTC Used with RTC-Only Mode Required

**Connections:**
- RTC_KALDO_ENn → GND
- CAP_VDD_RTC → 1µF decoupling capacitor to GND
- RTC_PWRONRSTn → 1.8V RTC power-on reset
- PMIC_POWER_EN → PMIC power input
- EXT_WAKEUP0 → wakeup source

**Result:** Internal LDO required for proper wakeup signaling from RTC domain.

---

## 8.6 Wakeup Management

### 8.6.1 Wakeup Sources/Events

The following events wake the device from deep sleep (low power) modes. These are part of the Wakeup Power domain and remain always ON:

- **GPIO0 bank** - General purpose I/O wakeup
- **dmtimer1_1ms** - Timer-based wakeup
- **USB2PHY** - USB resume signaling from suspend (both USB ports supported)
- **TSC** - Touch screen controller, ADC monitor functions
- **UART0** - Infrared support
- **I2C0** - I2C interface
- **RTC alarm** - Real-time clock alarm

**Note:** These wake events apply to all deep sleep modes and standby mode.

### 8.6.2 Main Oscillator Control During Deep Sleep

The **DeepSleep oscillator circuit** controls the main oscillator:

**Configuration:**
- Set `DEEPSLEEP_CTRL.DSENABLE = 1` to activate oscillator control circuit for deep sleep
- Configure `DEEPSLEEP_CTRL.DSCOUNT` for delay period before re-enabling oscillator

**Operation:**
1. When oscillator control is activated and Wake M3 enters standby:
   - Oscillator control disables the oscillator
   - Clock shuts OFF
2. Any async event from wakeup sources:
   - Oscillator control re-enables oscillator
   - After DSCOUNT configured period

### 8.6.3 USB Wakeup Scenarios

#### USB Wakeup Event Types

Two possible wakeup events generated:

1. **PHY WKUP:** Internal wakeup signal to Cortex-M3 generated by USB PHY based on USB signaling
2. **VBUS2GPIO:** External wakeup from level change on VBUS voltage (requires external board solution routing VBUS to GPIO with level shifting)

#### USB Wakeup Use Cases

**USB Connect Use Cases:**

| System Sleep State | USB Controller State | USB Mode | Supported | Wakeup Event |
|-------------------|---------------------|----------|-----------|--------------|
| DS0 | POWER OFF | Host | No | N/A |
| DS0 | POWER OFF | Device | Yes | VBUS2GPIO |
| DS1/Standby | Clock Gated | Host | Yes | PHY WKUP |
| DS1/Standby | Clock Gated | Device | Yes | VBUS2GPIO |

**USB Suspend/Resume Use Cases:**

| System Sleep State | USB Controller State | USB Mode | Supported | Wakeup Event |
|-------------------|---------------------|----------|-----------|--------------|
| DS0 | POWER OFF | Host | No | N/A |
| DS0 | POWER OFF | Device | No | N/A |
| DS1/Standby | Clock Gated | Host | Yes | PHY WKUP |
| DS1/Standby | Clock Gated | Device | Yes | PHY WKUP |

**USB Disconnect Use Cases:**

| System Sleep State | USB Controller State | USB Mode | Supported | Wakeup Event |
|-------------------|---------------------|----------|-----------|--------------|
| DS0 | POWER OFF | Host | No | N/A |
| DS0 | POWER OFF | Device | No | N/A |
| DS1/Standby | Clock Gated | Host | Yes | PHY WKUP |
| DS1/Standby | Clock Gated | Device | Yes | VBUS2GPIO |

**Note:** DeepSleep1 is the lowest sleep mode required for certain USB wakeup scenarios.

---

## 8.7 Power Management Sequencing with Cortex-M3

### 8.7.1 Overview

AM335x contains a dedicated **Cortex-M3 processor** to handle power management transitions. Located in Wake up Power Domain (PD_WKUP).

**Architecture:**
- **Cortex-A8 MPU:** Implements power modes, executes application
- **Cortex-M3:** Handles low-level power management control
- **Inter-Processor Communication (IPC):** Registers in Control Module for communication

**General Principle:** Cortex-A8 and Cortex-M3 are not expected to be active simultaneously. Cortex-M3 along with PRCM is the power manager primarily for PD_MPU and PD_PER. Other power domains (e.g., PD_GFX) may be handled directly by Cortex-A8 MPU software.

### 8.7.2 Power Management Sequence

**Basic Flow:**

1. During Active power mode: Cortex-A8 MPU executes WFI instruction to enter IDLE mode
2. Cortex-M3 gets interrupt and becomes active
3. Cortex-M3 powers down MPU power domain (if required)
4. Cortex-M3 registers interrupt for wakeup peripheral
5. Cortex-M3 executes WFI and goes into idle state
6. Wakeup event triggers interrupt to Cortex-M3 system
7. Cortex-M3 wakes up Cortex-A8 MPU

### 8.7.3 IPC Mechanism

**IPC Register Mapping:**

| Register | Bits | Field | Direction | Purpose |
|----------|------|-------|-----------|---------|
| IPC_MSG_REG0 | [15:0] | CMD_STAT | MPU→CM3 | Command status |
| | [31:16] | CMD_ID | MPU→CM3 | Command ID |
| IPC_MSG_REG1 | [31:0] | CMD param1 | MPU→CM3 | Command parameter 1 |
| IPC_MSG_REG2 | [31:0] | CMD param2 | MPU→CM3 | Command parameter 2 |
| IPC_MSG_REG3 | - | - | CM3→MPU | Response/status from CM3 |
| IPC_MSG_REG4-6 | - | Reserved | - | Reserved for future use |
| IPC_MSG_REG7 | [31:0] | Customer Use | Both | Available for customer use |

**CMD_STAT Field Values:**

| Value | Name | Description |
|-------|------|-------------|
| 0x0 | PASS | In initialization phase, CM3 successfully initialized. For other tasks, task completed successfully |
| 0x1 | FAIL | In initialization phase, CM3 could not initialize. For other tasks, error occurred. Check trace vector for details |
| 0x2 | WAIT4OK | CM3 INTC will catch next WFI of A8 and continue with pre-defined sequence |

**CMD_ID Field Values:**

| Value | Name | Description |
|-------|------|-------------|
| 0x1 | CMD_RTC | 1. Initiates force_sleep on interconnect clocks<br>2. Turns off MPU and PER power domains<br>3. Programs RTC alarm register for deasserting pmic_pwr_enable |
| 0x2 | CMD_RTC_FAST | Programs RTC alarm register for deasserting pmic_pwr_enable |
| 0x3 | CMD_DS0 | 1. Initiates force_sleep on interconnect clocks<br>2. Turns off MPU and PER power domains<br>3. Configures system for disabling MOSC when CM3 executes WFI |
| 0x5 | CMD_DS1 | 1. Initiates force_sleep on interconnect clocks<br>2. Turns off MPU power domain<br>3. Configures system for disabling MOSC when CM3 executes WFI |

### 8.7.4 Sleep Sequencing Guidelines

**Recommended Sleep Sequence:**

1. Application saves context of peripherals to memories supporting retention and DDR (required for DeepSleep0)
2. MPU OCMC_RAM remains in retention
3. Unused power domains turned OFF - program clock/power domain PWRSTCTRL, save contexts
4. Software populates L3_OCMC_RAM for wakeup restoration:
   - Save EMIF settings
   - Public/secure restoration pointers
5. Execute WFI from SRAM
6. Any peripheral interrupt triggers wake interrupt to Cortex-M3 via Cortex-A8 MPU's WKUP signal
7. After MPU power domain clock gated, PRCM provides interrupt to Cortex-M3
8. Cortex-M3 starts execution and performs low-level power sequencing:
   - Turns off certain power domains
   - Eventually executes WFI
9. Hardware oscillator control circuit disables oscillator once Cortex-M3 goes into WFI

### 8.7.5 Wakeup Sequencing Guidelines

**Recommended Wakeup Sequence:**

1. Configured wakeup event triggers wakeup sequence
2. Wakeup event switches ON oscillator (if configured OFF during sleep)
3. Wakeup event triggers interrupt to Cortex-M3
4. Cortex-M3 executes following on wakeup:
   - Restores voltages to normal operating voltage
   - Enables PLL locking
   - Switches ON power domains and/or enables clocks for PD_PER
   - Switches ON power domains and/or enables clocks for PD_MPU
   - Executes WFI
5. Cortex-A8 MPU starts executing from ROM reset vector
6. Restores application context (only for DeepSleep0)

### 8.7.6 Periodic Idling of Cortex-A8 MPU

For periodic ON/OFF of Cortex-A8 MPU:

1. Cortex-A8 MPU executes WFI instruction
2. Any peripheral interrupt triggers wake interrupt to Cortex-M3 via MPU Subsystem's WKUP signal
3. Cortex-M3 powers down MPU (PD_MPU)
4. On receiving interrupt, Cortex-M3 switches ON MPU power domain
5. Cortex-M3 goes into idle mode using WFI instruction

---

## 8.8 PRCM Module Overview

The PRCM is structured using architectural concepts providing:
- Set of modular, re-usable FSM blocks for clock and power management
- Register set and associated programming model
- Functional sub-block definitions for clock, power, system clock, and master clock generation

### 8.8.1 Functional Power Domains

**Generic Domains:**
- **WAKEUP** - Always-on domain for wakeup functionality
- **MPU** - MPU subsystem (Cortex-A8 processor)
- **PER** - Peripheral domain
- **RTC** - Real-time clock domain

### 8.8.2 PRCM Functional Features

- Software configurable for direct, automatic, or combination power domain state transition control
- Device power-up sequence control
- Device sleep/wake-up sequence control
- Centralized reset generation and management
- Centralized clock generation and management

### 8.8.3 PRCM Interface Overview

**Key Interfaces:**

1. **OCP Configuration Ports** - OCP/IP2.0 compliant 32-bit target interface
2. **Power Control Interface** - Controls power domain switches, receives switch status, controls isolation signals
3. **Device Control Interface** - Device-level feature management:
   - Device type coding
   - IOs isolation control
4. **Clocks Interface** - All clock inputs and outputs
5. **Resets Interface** - All reset inputs and outputs
6. **Modules Power Management Control Interface:**
   - **Initiator modules:** MStandby signal, MWait signal
   - **Target modules:** SIdleReq signal, SIdleAck signal, FCLKEN signal

---

## 8.9 Clock Generation and Management

PRCM provides centralized control for generation, distribution, and gating of most clocks in the device.

### 8.9.1 Clock Terminology

**Two types of clocks:**

1. **Interface Clocks:**
   - Provide clocking for system interconnect modules
   - Supply functional module's system interconnect interface and registers
   - In some cases, also used as functional clock

2. **Functional Clocks:**
   - Supply functional part of module or subsystem
   - May require several functional clocks:
     - One or several main functional clock(s)
     - One or several optional clock(s)
   - Main clocks required for module operation
   - Optional clocks for specific features, can shutdown without stopping module

### 8.9.2 Clock Structure

**DPLL Types:**

The device supports multiple on-chip DPLLs:

1. **ADPLLS:** Used for Core, Display, ARM Subsystem, and DDR PLLs
2. **ADPLLLJ:** Used for peripheral functional clocks

**Reference Clocks:**

Two reference clocks generated by on-chip oscillators or externally:
- **Main clock tree** - From main oscillator (CLK_M_OSC)
- **RTC block** - From 32 kHz crystal oscillator (controlled by RTC IP)
- **RC oscillator** - On-chip RC oscillator (always on, not configurable)

**Note:** All PLLs come up in bypass mode at reset. Software must program all PLL settings and wait for PLL lock.

### 8.9.3 ADPLLS Architecture

High resolution frequency synthesizer PLL with built-in level shifters, allows generation of PLL-locked frequencies up to 2 GHz.

**ADPLLS PLLs:**
- MPU PLL
- Core PLL  
- Display PLL
- DDR PLL

**Input Clocks:**
- **CLKINP:** Reference input clock
- **CLKINPULOW:** Low frequency input clock for bypass mode only
- **CLKINPHIF:** High frequency input clock for post-divider M3

**Output Clocks:**
- **CLKOUTHIF:** High frequency output clock from post divider M3
- **CLKOUTX2:** Secondary 2x output
- **CLKOUT:** Primary output clock
- **CLKDCOLDO:** Oscillator (DCO) output clock with no bypass

**Internal Clocks:**
- **REFCLK:** Generated by dividing CLKINP by (N+1). REFCLK = CLKINP/(N+1)
- **BCLK:** Bus clock for programming registers

**Lock Frequency:** fDPLL = CLKDCOLDO

#### ADPLLS Output Clock Frequencies

**In Locked Condition (REGM4XEN='0'):**

| Clock | Frequency Formula |
|-------|------------------|
| CLKOUT | [M / (N+1)] * CLKINP * [1/M2] |
| CLKOUTX2 | 2 * [M / (N+1)] * CLKINP * [1/M2] |
| CLKDCOLDO | 2 * [M / (N+1)] * CLKINP |
| CLKOUTHIF (CLKINPHIFSEL='1') | CLKINPHIF / M3 |
| CLKOUTHIF (CLKINPHIFSEL='0') | 2 * [M / (N+1)] * CLKINP * [1/M3] |

**In Locked Condition (REGM4XEN='1'):**

| Clock | Frequency Formula |
|-------|------------------|
| CLKOUT | [4M / (N+1)] * CLKINP * [1/M2] |
| CLKOUTX2 | 2 * [4M / (N+1)] * CLKINP * [1/M2] |
| CLKDCOLDO | 2 * [4M / (N+1)] * CLKINP |
| CLKOUTHIF (CLKINPHIFSEL='1') | CLKINPHIF / M3 |
| CLKOUTHIF (CLKINPHIFSEL='0') | 2 * [4M / (N+1)] * CLKINP * [1/M3] |

**Before Lock and During Relock Modes:**

| Clock | Frequency (ULOWCLKEN='0') | Frequency (ULOWCLKEN='1') |
|-------|-------------------------|-------------------------|
| CLKOUT | CLKINP / (N2+1) | CLKINPULOW |
| CLKOUTX2 | CLKINP / (N2+1) | CLKINPULOW |
| CLKDCOLDO | Low | Low |
| CLKOUTHIF | CLKINPHIF/M3 (ULOWCLKEN='1') | Low (ULOWCLKEN='0') |

### 8.9.4 ADPLLLJ (Low Jitter DPLL)

Low jitter PLL with 2 GHz maximum output, used for peripheral functional clocks.

**Features:**
- Predivide feature allows dividing reference clock (e.g., 24/26 MHz) to 1 MHz
- Then multiply up to 2 GHz maximum
- Similar architecture to ADPLLS but optimized for low jitter

### 8.9.5 Spread Spectrum Clocking (SSC)

**Purpose:** Reduce electromagnetic interference (EMI) by spreading clock signal energy across frequency spectrum.

**Principle:**
- Modulates clock frequency in triangular pattern
- Spreads energy instead of concentrating at single frequency
- Reduces power of peaks but increases global noise

**EMI Reduction Estimation:**

Peak_power_reduction (dB) = 10 * log((Deviation * fc) / fm)

Where:
- Deviation: % of initial clock frequency (Δf / fc)
- fc: Original clock frequency (MHz)
- fm: Spreading frequency (MHz)

**Example:** For fc=400 MHz, deviation=1% (Δf=4 MHz), fm=400 kHz → peak power reduction ≈ 10 dB

**SSC Configuration:**

Enabled/disabled via `CM_CLKMODE_DPLL_xxx.DPLL_SSC_EN` where xxx = MPU, DDR, DISP, CORE, or PER.

**Key Parameters:**
- **Modulation Frequency (fm):** Programmed via MODFREQDEV_MANTISSA and MODFREQDEV_EXPONENT
  - ModFreqDivider = Fref / (4*fm)
  - ModFreqDivider = MODFREQDEV_MANTISSA * 2^MODFREQDEV_EXPONENT
- **Frequency Spread (Δf):** Controlled via DELTAMSTEP_INTEGER and DELTAMSTEP_FRACTION
- **Downspread Mode:** If DPLL_SSC_DOWNSPREAD=1, frequency spread on lower side is 2x programmed value, upper side is 0

**Restrictions:**
- M - ΔM ≥ 20
- M + ΔM ≤ 2045
- If downspread enabled: M - 2*ΔM ≥ 20 and M ≤ 2045
- Modulation frequency must be within DPLL loop bandwidth (fm < Fref/70)

---

## 8.10 Summary of Key Concepts for AI Training

### Clock Management Hierarchy

```
PRCM Module
├── Clock Domains (groups of modules with common clock source)
│   ├── Clock Managers (control clock gating per domain)
│   ├── Interface Clocks (_ICLK) → interconnect/registers
│   └── Functional Clocks (_FCLK) → module functionality
│       ├── Mandatory clocks (required for operation)
│       └── Optional clocks (feature-specific)
└── Module Clock Protocols
    ├── Master Standby Protocol (for initiator modules)
    │   ├── Force-standby (immediate, risk of data loss)
    │   ├── No-standby (always active, not power-efficient)
    │   ├── Smart-standby (activity-based, safe)
    │   └── Smart-standby wakeup (with wakeup generation)
    └── Slave Idle Protocol (for target modules)
        ├── Force-idle (immediate, risk of data loss)
        ├── No-idle (always active, not power-efficient)
        ├── Smart-idle (activity-based, safe)
        └── Smart-idle wakeup (with wakeup generation)
```

### Power Management Hierarchy

```
PRCM Module
├── Power Domains (groups with independent power control)
│   ├── Logic Area (ON/OFF states)
│   └── Memory Area (ON/RETENTION/OFF states)
├── Power States Control
│   ├── PWRSTCTRL (target state configuration)
│   └── PWRSTST (current state status)
└── Voltage Management
    └── AVS (Adaptive Voltage Scaling via Smart Reflex)
```

### Power Modes Spectrum

```
Active Mode (Highest Power, Zero Latency)
  ↓ All supplies ON, all DPLLs locked
Standby Mode
  ↓ Main osc ON, DPLLs bypass, PD_MPU OFF, DDR self-refresh
DeepSleep1 Mode
  ↓ Main osc OFF, DDR self-refresh, USB wakeup capable
DeepSleep0 Mode
  ↓ PD_PER OFF, DDR self-refresh maintained
RTC-Only Mode (Lowest Power, Highest Latency)
  All OFF except RTC domain, full cold boot on wakeup
```

### Wakeup Management

```
Wakeup Sources (PD_WKUP domain, always ON):
├── GPIO0 bank
├── dmtimer1_1ms
├── USB2PHY (both ports)
├── TSC
├── UART0
├── I2C0
└── RTC alarm

Wakeup Path:
Event → Oscillator Enable → Cortex-M3 Interrupt → 
Power Domain Restore → Clock Enable → Cortex-A8 Resume
```

### Cortex-M3 Power Management Role

```
Power Transition Flow:
1. Cortex-A8 executes WFI
2. Cortex-M3 wakes, receives IPC command (CMD_DS0/DS1/RTC)
3. Cortex-M3 executes power sequencing:
   - Forces sleep on interconnect clocks
   - Powers down MPU/PER domains
   - Configures oscillator control
4. Cortex-M3 executes WFI (enters idle)
5. Wakeup event arrives
6. Cortex-M3 wakes, executes restore sequence:
   - Restores voltages
   - Locks PLLs
   - Enables power domains
   - Enables clocks
7. Cortex-A8 resumes from ROM reset vector
```

### Critical Register Fields

**Clock Control:**
- `MODULEMODE`: Module enable/disable control
- `CLKTRCTRL`: Clock domain transition control
- `CLKACTIVITY`: Clock activity status
- `IDLEST`: Module idle status
- `STBYST`: Module standby status

**Power Control:**
- `POWERSTATE`: Target power state configuration
- `POWERSTATEST`: Current power state status
- `LOGICSTATEST`: Logic area state status
- `MEMSTATEST`: Memory area state status

**IPC Communication:**
- `CMD_STAT`: Command status (PASS/FAIL/WAIT4OK)
- `CMD_ID`: Command identifier (CMD_RTC/CMD_DS0/CMD_DS1)
- `CMD param1/param2`: Command parameters

---

## Key Takeaways

1. **Hierarchical Management:** Three-level architecture (clock/power/voltage) with domain-based organization

2. **Hardware Protocols:** Automatic clock gating via Master Standby and Slave Idle protocols with smart modes for safety

3. **Power Mode Trade-offs:** Five power modes providing spectrum from full performance to ultra-low power with corresponding latency trade-offs

4. **Cortex-M3 Role:** Dedicated processor handles low-level power transitions, allowing Cortex-A8 to focus on application

5. **Flexible Wakeup:** Multiple wakeup sources in always-on domain enable application-specific low-power scenarios

6. **Context Management:** Critical requirement to save/restore context appropriately for each power mode

7. **USB Considerations:** DeepSleep1 minimum for USB wakeup scenarios, different events for host vs device mode

8. **RTC Domain:** Can operate independently with battery backup for ultra-low power timekeeping

9. **Clock Generation:** ADPLLS and ADPLLLJ DPLLs with SSC capability for EMI reduction

10. **Software Control:** Extensive register set provides fine-grained control while hardware protocols ensure safety

---

## 8.11 Clock Module Registers

### 8.11.1 Register Groups Overview

The Clock Module provides the following register groups:

| Register Group | Base Address | Purpose |
|---------------|--------------|---------|
| **CM_PER** | 0x44E00000 | Peripheral clock management |
| **CM_WKUP** | 0x44E00400 | Wakeup domain clock management |
| **CM_DPLL** | 0x44E00500 | DPLL configuration and control |
| **CM_MPU** | 0x44E00600 | MPU clock management |
| **CM_DEVICE** | 0x44E00700 | Device-level clock control |
| **CM_RTC** | 0x44E00800 | RTC clock management |
| **CM_GFX** | 0x44E00900 | Graphics clock management |
| **CM_CEFUSE** | 0x44E00A00 | eFuse clock management |

### 8.11.2 Common Register Types

#### 8.11.2.1 CLKSTCTRL Registers (Clock State Control)

Control clock domain state transitions and monitor clock activity.

**Common Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [31:8] | CLKACTIVITY_* | R | Activity status bits for various clocks in domain (0=Gated, 1=Active) |
| [1:0] | CLKTRCTRL | R/W | Clock transition control:<br>0x0 = NO_SLEEP (sleep transition cannot be initiated)<br>0x1 = SW_SLEEP (software forced sleep)<br>0x2 = SW_WKUP (software forced wakeup)<br>0x3 = Reserved |

### 8.11.2.2 CLKCTRL Registers (Clock Control)

Control individual module clocks and monitor module state.

**Common Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [18] | STBYST | R | Standby status:<br>0x0 = Module functional (not in standby)<br>0x1 = Module in standby |
| [17:16] | IDLEST | R | Idle status:<br>0x0 = Functional (fully functional including OCP)<br>0x1 = Transition (wakeup, sleep, or sleep abortion)<br>0x2 = Idle (OCP idle, functional if using separate functional clock)<br>0x3 = Disabled (module disabled, cannot be accessed) |
| [1:0] | MODULEMODE | R/W | Module mode:<br>0x0 = DISABLED (module disabled by SW, OCP access causes error)<br>0x1 = Reserved<br>0x2 = ENABLE (module explicitly enabled, clocks guaranteed)<br>0x3 = Reserved |

### 8.11.3 Key CM_PER Registers

Peripheral domain clock management registers.

| Offset | Register Name | Purpose |
|--------|--------------|---------|
| 0x00 | CM_PER_L4LS_CLKSTCTRL | L4LS clock domain state control |
| 0x04 | CM_PER_L3S_CLKSTCTRL | L3S clock domain state control |
| 0x0C | CM_PER_L3_CLKSTCTRL | L3 clock domain state control |
| 0x14 | CM_PER_CPGMAC0_CLKCTRL | Ethernet switch (CPSW) clock control |
| 0x18 | CM_PER_LCDC_CLKCTRL | LCD controller clock control |
| 0x1C | CM_PER_USB0_CLKCTRL | USB0 clock control |
| 0x28 | CM_PER_EMIF_CLKCTRL | EMIF (DDR) clock control |
| 0x2C | CM_PER_OCMCRAM_CLKCTRL | On-chip RAM clock control |
| 0x30 | CM_PER_GPMC_CLKCTRL | GPMC (parallel interface) clock control |
| 0x3C | CM_PER_MMC0_CLKCTRL | MMC0 clock control |
| 0x44 | CM_PER_I2C2_CLKCTRL | I2C2 clock control |
| 0x48 | CM_PER_I2C1_CLKCTRL | I2C1 clock control |
| 0x4C | CM_PER_SPI0_CLKCTRL | SPI0 clock control |
| 0x50 | CM_PER_SPI1_CLKCTRL | SPI1 clock control |
| 0x6C | CM_PER_UART1_CLKCTRL | UART1 clock control |
| 0x70 | CM_PER_UART2_CLKCTRL | UART2 clock control |
| 0x74 | CM_PER_UART3_CLKCTRL | UART3 clock control |
| 0xAC | CM_PER_GPIO1_CLKCTRL | GPIO1 clock control |
| 0xB0 | CM_PER_GPIO2_CLKCTRL | GPIO2 clock control |
| 0xB4 | CM_PER_GPIO3_CLKCTRL | GPIO3 clock control |

### 8.11.4 Key CM_WKUP Registers

Wakeup domain clock management registers (Base: 0x44E00400).

| Offset | Register Name | Purpose |
|--------|--------------|---------|
| 0x00 | CM_WKUP_CLKSTCTRL | Wakeup clock domain state control |
| 0x04 | CM_WKUP_CONTROL_CLKCTRL | Control module clock control |
| 0x08 | CM_WKUP_GPIO0_CLKCTRL | GPIO0 clock control |
| 0x0C | CM_WKUP_L4WKUP_CLKCTRL | L4 wakeup interconnect clock control |
| 0x10 | CM_WKUP_TIMER0_CLKCTRL | Timer0 clock control |
| 0x14 | CM_WKUP_DEBUGSS_CLKCTRL | Debug subsystem clock control |
| 0x2C | CM_L3_AON_CLKSTCTRL | L3 always-on clock domain state control |
| 0x34 | CM_WKUP_UART0_CLKCTRL | UART0 clock control |
| 0x38 | CM_WKUP_I2C0_CLKCTRL | I2C0 clock control |
| 0x3C | CM_WKUP_ADC_TSC_CLKCTRL | ADC/Touchscreen clock control |

### 8.11.5 CM_DPLL Registers

DPLL configuration and control registers (Base: 0x44E00500).

#### 8.11.5.1 DPLL Control Registers

Each DPLL has the following register set pattern:

| Register | Purpose |
|----------|---------|
| CM_CLKMODE_DPLL_xxx | DPLL mode control (bypass, lock, etc.) |
| CM_IDLEST_DPLL_xxx | DPLL lock status |
| CM_CLKSEL_DPLL_xxx | DPLL multiply/divide configuration |
| CM_DIV_M2_DPLL_xxx | M2 divider configuration |
| CM_DIV_M4_DPLL_xxx | M4 divider configuration (if available) |
| CM_DIV_M5_DPLL_xxx | M5 divider configuration (if available) |
| CM_DIV_M6_DPLL_xxx | M6 divider configuration (if available) |

Where xxx = MPU, DDR, DISP, CORE, or PER.

#### 8.11.5.2 CM_CLKMODE_DPLL_xxx (DPLL Mode Control)

**Key Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [23] | DPLL_SSC_ACK | R | SSC acknowledgment (0=Disabled, 1=Enabled) |
| [22] | DPLL_SSC_DOWNSPREAD | R/W | Downspread enable (0=Center spread, 1=Downspread) |
| [12] | DPLL_SSC_EN | R/W | Spread Spectrum Clocking enable |
| [8] | DPLL_LPMODE_EN | R/W | Low power mode enable |
| [7] | DPLL_RELOCK_RAMP_EN | R/W | Relock ramp enable |
| [6] | DPLL_DRIFTGUARD_EN | R/W | Drift guard enable (recalibration) |
| [5:4] | DPLL_RAMP_LEVEL | R/W | Ramp level control |
| [3] | DPLL_RAMP_RATE | R/W | Ramp rate control |
| [2:0] | DPLL_EN | R/W | DPLL enable mode:<br>0x0 = Reserved<br>0x1 = Reserved<br>0x2 = Reserved<br>0x3 = Reserved<br>0x4 = MN bypass mode<br>0x5 = Idle bypass low-power mode<br>0x6 = Reserved<br>0x7 = Lock mode |

#### 8.11.5.3 CM_IDLEST_DPLL_xxx (DPLL Status)

**Key Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [8] | ST_MN_BYPASS | R | MN bypass status (0=Not in bypass, 1=In bypass) |
| [0] | ST_DPLL_CLK | R | DPLL lock status (0=Unlocked, 1=Locked) |

#### 8.11.5.4 CM_CLKSEL_DPLL_xxx (DPLL Multiply/Divide)

**Key Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [22:8] | DPLL_MULT | R/W | DPLL multiplier factor (M) [2-2047] |
| [6:0] | DPLL_DIV | R/W | DPLL divider factor (N) [0-127] |

**Frequency Calculation:**
- Fref = Finp / (N + 1)
- Fdpll = Fref * M = Finp * M / (N + 1)
- Fout = Fdpll / M2

#### 8.11.5.5 CM_DIV_M2_DPLL_xxx (M2 Divider)

**Key Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [5] | DPLL_CLKOUT_DIVCHACK | R | Divider change acknowledgment (toggles on change) |
| [4:0] | DPLL_CLKOUT_DIV | R/W | M2 divider value [1-31], actual divisor = value + 1 |

**Note:** M2 divider can be changed on-the-fly without putting DPLL in bypass mode.

#### 8.11.5.6 SSC Configuration Registers

For DPLL with Spread Spectrum Clocking support:

**CM_SSC_DELTAMSTEP_DPLL_xxx:**

| Bits | Field | Description |
|------|-------|-------------|
| [19:18] | DELTAMSTEP_INTEGER | Integer part of delta M step |
| [17:0] | DELTAMSTEP_FRACTION | Fractional part of delta M step (18-bit) |

**CM_SSC_MODFREQDIV_DPLL_xxx:**

| Bits | Field | Description |
|------|-------|-------------|
| [9:7] | MODFREQDIV_EXPONENT | Modulation frequency divider exponent (3-bit) |
| [6:0] | MODFREQDIV_MANTISSA | Modulation frequency divider mantissa (7-bit) |

### 8.11.6 CM_MPU Registers

MPU subsystem clock management (Base: 0x44E00600).

| Offset | Register Name | Purpose |
|--------|--------------|---------|
| 0x00 | CM_MPU_CLKSTCTRL | MPU clock domain state control |
| 0x04 | CM_MPU_MPU_CLKCTRL | MPU clock control |

---

## 8.12 Power Management Registers

### 8.12.1 Register Groups Overview

The Power Management module provides the following register groups:

| Register Group | Base Address | Purpose |
|---------------|--------------|---------|
| **PRM_PER** | 0x44E00C00 | Peripheral power domain management |
| **PRM_WKUP** | 0x44E00D00 | Wakeup power domain management |
| **PRM_MPU** | 0x44E00E00 | MPU power domain management |
| **PRM_DEVICE** | 0x44E00F00 | Device-level power management |
| **PRM_RTC** | 0x44E01000 | RTC power domain management |
| **PRM_GFX** | 0x44E01100 | Graphics power domain management |
| **PRM_CEFUSE** | 0x44E01200 | eFuse power domain management |

### 8.12.2 Common Register Types

#### 8.12.2.1 PM_xxx_PWRSTCTRL (Power State Control)

Controls target power state for power domain.

**Key Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [11:10] | LOWPOWERSTATECHANGE | R/W | Low power state change request |
| [9:8] | LOGICRETSTATE | R/W | Logic retention state:<br>0x0 = Logic off<br>0x1 = Logic retention |
| [5:4] | MEM_x_RETSTATE | R/W | Memory bank retention state:<br>0x0 = Memory off<br>0x1 = Memory retention |
| [3:2] | MEM_x_ONSTATE | R/W | Memory bank on state:<br>0x3 = Memory on |
| [1:0] | POWERSTATE | R/W | Power state control:<br>0x0 = OFF<br>0x1 = RETENTION<br>0x2 = INACTIVE (not used)<br>0x3 = ON |

#### 8.12.2.2 PM_xxx_PWRSTST (Power State Status)

Reports current power state of power domain.

**Key Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [20] | LASTPOWERSTATEENTERED | R | Last low power state entered |
| [11:10] | LOGICSTATEST | R | Logic state status:<br>0x0 = Logic off<br>0x1 = Logic retention<br>0x2 = Reserved<br>0x3 = Logic on |
| [9:8] | MEM_STATEST_x | R | Memory bank state status:<br>0x0 = Memory off<br>0x1 = Memory retention<br>0x2 = Reserved<br>0x3 = Memory on |
| [5] | INTRANSITION | R | Power state transition status:<br>0x0 = No transition<br>0x1 = Transition ongoing |
| [1:0] | POWERSTATEST | R | Current power state:<br>0x0 = OFF<br>0x1 = RETENTION<br>0x2 = INACTIVE<br>0x3 = ON |

### 8.12.3 Reset Control Registers

#### PRM_RSTCTRL (Reset Control)

Global warm reset control.

**Key Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [1] | RST_GLOBAL_COLD_SW | R/W | Software cold reset |
| [0] | RST_GLOBAL_WARM_SW | R/W | Software warm reset |

#### PRM_RSTST (Reset Status)

Reports reset source.

**Key Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [9] | ICEPICK_RST | R/W1toClr | ICEPick reset |
| [6] | EXTERNAL_WARM_RST | R/W1toClr | External warm reset |
| [5] | WDT1_RST | R/W1toClr | Watchdog 1 reset |
| [4] | GLOBAL_COLD_RST | R/W1toClr | Global cold reset |
| [1] | GLOBAL_WARM_SW_RST | R/W1toClr | Global warm software reset |
| [0] | POWER_ON_RST | R/W1toClr | Power-on reset |

#### PRM_RSTTIME (Reset Timing)

Controls reset timing parameters.

**Key Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [14:10] | RSTTIME2 | R/W | Reset time 2 (in 32kHz clock cycles) |
| [9:0] | RSTTIME1 | R/W | Reset time 1 (in 32kHz clock cycles) |

### 8.12.4 Sleep/Wakeup Control Registers

#### PRM_SRAM_COUNT

Controls SRAM retention during sleep.

#### PRM_LDO_SRAM_xxx_CTRL

Controls SRAM LDO during retention.

### 8.12.5 Device Control Registers

Located in Control Module, but critical for power management.

#### DEEPSLEEP_CTRL (Control Module: 0x44E10470)

**Key Bit Fields:**

| Bits | Field | Type | Description |
|------|-------|------|-------------|
| [31:16] | Reserved | - | - |
| [15:3] | DSCOUNT | R/W | Deep sleep count (oscillator restart delay) |
| [0] | DSENABLE | R/W | Deep sleep enable (0=Disable, 1=Enable) |

### 8.12.6 IPC Registers

Inter-processor communication registers for Cortex-A8 and Cortex-M3 (Control Module: 0x44E10400+).

| Offset | Register Name | Purpose |
|--------|--------------|---------|
| 0x00 | IPC_MSG_REG0 | Command ID and Status |
| 0x04 | IPC_MSG_REG1 | Command Parameter 1 |
| 0x08 | IPC_MSG_REG2 | Command Parameter 2 |
| 0x0C | IPC_MSG_REG3 | Response/Status from CM3 |
| 0x10 | IPC_MSG_REG4 | Reserved |
| 0x14 | IPC_MSG_REG5 | Reserved |
| 0x18 | IPC_MSG_REG6 | Reserved |
| 0x1C | IPC_MSG_REG7 | Customer use |

**IPC_MSG_REG0 Format:**

| Bits | Field | Description |
|------|-------|-------------|
| [31:16] | CMD_ID | Command identifier |
| [15:0] | CMD_STAT | Command status |

---

## 8.13 Register Access Considerations

### 8.14.1 Synchronization Requirements

- **Clock Domain Transitions:** Software must ensure proper sequencing when changing CLKTRCTRL
- **DPLL Configuration:** Always put DPLL in bypass before changing M, N, or M2 values (except M2 on-the-fly changes)
- **Power Domain Transitions:** Check INTRANSITION bit before assuming power state change completed
- **Module Enable:** Always wait for IDLEST to show functional state before accessing module

### 8.14.2 Reset Sensitivity

Some register bits are marked as:
- **Cold reset only:** Preserved during warm reset
- **Warm reset sensitive:** Reset to default on warm reset
- **Power domain reset:** Reset when power domain is cycled

Check module documentation for specific reset behavior.

### 8.14.3 Access Restrictions

- **Read-only fields:** Writing has no effect
- **Write-to-clear bits:** Writing 1 clears the bit, writing 0 has no effect (e.g., reset status bits)
- **Reserved bits:** Should not be modified, read as 0

### 8.14.4 Common Pitfalls

1. **Forgetting to enable clock domain:** Module won't function if clock domain is in NO_SLEEP or SW_SLEEP
2. **Not waiting for lock:** Accessing DPLL outputs before lock completes causes undefined behavior
3. **Missing IDLEST check:** Accessing module registers before IDLEST shows functional can cause bus errors
4. **Power domain sequencing:** Incorrect power-up/power-down sequence can hang system
5. **Context loss:** Not saving context before entering low power modes with memory OFF

# AM335x DMTimer (Dual-Mode Timer)

## Chapter 20: DMTimer Reference

---

## 20.1 Introduction

### 20.1.1 Overview

The DMTimer (Dual-Mode Timer) module contains a free-running upward counter with auto-reload capability on overflow. The timer counter can be read and written in real-time while counting. The module includes compare logic to allow interrupt events on programmable counter matching values.

**Key Capabilities:**
- Free-running upward counter with auto-reload
- Real-time read/write of counter value
- Compare logic for programmable match interrupts
- Dedicated output signal for PWM or timing stamps
- Dedicated input signal for automatic counter capture
- Programmable clock divider (prescaler)
- Write-posted mode for improved performance
- OCP peripheral bus compatible

### 20.1.2 Features

The timer consists of the following features:

- **Counter timer with capture and compare modes**
- **Auto-reload mode**
- **Start-stop mode**
- **Programmable divider clock source**
- **16-32 bit addressing**
- **"On the fly" read/write registers**
- **Interrupts generated on:**
  - Overflow
  - Compare (match)
  - Capture
- **Interrupt enable**
- **Wake-up enable** (Timer0 only)
- **Write posted mode** (reduced access latency)
- **Dedicated I/O:**
  - Input trigger for capture mode (PIEVENTCAPT)
  - Output trigger/PWM signal (PORTIMERPWM)
  - General purpose output (PORGPOCFG)
- **OCP interface compatible**

### 20.1.3 Timer Resolution

Timer resolution and interrupt period depend on selected input clock and prescaler value.

| Clock | Prescaler | Resolution | Interrupt Period Range |
|-------|-----------|------------|----------------------|
| 32.768 kHz | 1 (min) | 31.25 µs | 31.25 µs to ~36h 35m |
| 32.768 kHz | 256 (max) | 8 ms | 8 ms to ~391d 22h 48m |
| 25 MHz | 1 (min) | 40 ns | 40 ns to ~171.8s |
| 25 MHz | 256 (max) | 10.24 µs | ~20.5 µs to ~24h 32m |

---

## 20.2 Functional Modes

The DMTimer supports three functional modes:

1. **Timer Mode** - Free-running counter with overflow
2. **Capture Mode** - Capture counter value on external event
3. **Compare Mode** - Generate interrupt/output on counter match

By default after reset, capture and compare modes are disabled.

### 20.2.1 Timer Mode

The timer is an upward counter that can be started and stopped at any time through the Timer Control Register (TCLR ST bit).

**Operation:**
- Counter can be loaded when stopped or on-the-fly (while counting)
- Counter loading methods:
  - Direct write to TCRR (Timer Counter Register)
  - Trigger write to TTGR loads TLDR value into TCRR
- Counter value can be read at any time
- Counter stopped and cleared to 0 on module reset
- Timer remains stopped after reset release

**One-Shot Mode (TCLR AR bit = 0):**
- Counter stops after overflow
- Counter value remains at zero

**Auto-Reload Mode (TCLR AR bit = 1):**
- TCRR reloaded with TLDR value after overflow
- Continuous counting

**Overflow Handling:**
- Interrupt can be issued if IRQENABLE_SET OVF_IT_FLAG = 1
- Output pin PORTIMERPWM can generate:
  - One positive pulse (prescaler duration)
  - Toggle current value

**Note:** Do not put overflow value (0xFFFF_FFFF) in TLDR as it can lead to undesired results.

### 20.2.2 Capture Mode

Timer value in TCRR can be captured and saved in TCAR1 or TCAR2 when a transition is detected on input pin (PIEVENTCAPT).

**Transition Detection:**
- Rising edge
- Falling edge  
- Both edges
- Selected via TCLR TCM bit

**Capture Modes:**

#### Single Capture (TCLR CAPT_MODE = 0)
- First enabled capture event → counter value saved in TCAR1
- All subsequent events ignored until:
  - Detection logic reset, OR
  - Interrupt status register cleared (write 1 to TCAR_IT_FLAG position)

#### Dual Capture (TCLR CAPT_MODE = 1)
- First enabled capture event → counter value saved in TCAR1
- Second enabled capture event → counter value saved in TCAR2
- All subsequent events ignored until interrupt serviced
- Useful for period calculation of external clock

**Capture Operation:**
- Edge detection logic reset when capture interrupt serviced
- TCAR_IT_FLAG bit cleared in IRQSTATUS
- Timer functional clock samples input pin
- Pulses must exceed functional clock period for detection
- Interrupt issued if IRQENABLE_SET TCAR_IT_FLAG = 1

### 20.2.3 Compare Mode

Timer value (TCRR) is continuously compared to Timer Match Register (TMAR) value.

**Operation:**
- Enable by setting TCLR CE bit = 1
- TMAR value can be loaded anytime (counting or stopped)
- When TCRR matches TMAR:
  - Interrupt issued if IRQENABLE_SET MAT_EN_FLAG = 1
  - Output pin PORTIMERPWM can toggle or pulse

**Implementation:**
1. Write compare value to TMAR
2. Set TCLR CE bit
3. Avoid setting CE before writing TMAR (prevents unwanted interrupts from reset value matching)

**Output Signal:**
- PORTIMERPWM programmed via TCLR TRG and PT bits
- Can generate:
  - One positive pulse (TIMER clock duration)
  - Toggle mode (invert current value)
- Triggers on overflow and match events

### 20.2.4 Prescaler Functionality

Prescaler divides timer counter input clock frequency.

**Configuration:**
- Enable: TCLR bit 5 (PRE)
- Division ratio: 2^n configured in TCLR PTV field
- Prescaler counter reset when:
  - Timer counter stopped
  - Timer counter reloaded on-the-fly

**Prescaler Behavior:**

| Event | Prescaler Counter | Timer Counter |
|-------|------------------|---------------|
| Overflow (Auto-reload ON) | Reset | TLDR |
| TCRR Write | Reset | TCRR |
| TTGR Write | Reset | TLDR |
| Stop | Reset | Frozen |

### 20.2.5 Pulse-Width Modulation (PWM)

Timer can provide programmable PWM output on PORTIMERPWM pin.

**PWM Configuration:**
- TCLR TRG bits determine toggle event:
  - Overflow only
  - Match only
  - Both overflow and match
- TCLR SCPWM bit sets/clears output when:
  - Counter stopped, OR
  - Triggering is off
- Allows deterministic output state when modulation stopped

**PWM Operation:**
- Overflow pulse generated each (0xFFFF_FFFF - TLDR + 1) count
- Match pulse generated when TCRR reaches TMAR value
- Output toggles based on TCLR TRG and PT bits
- Modulation stops synchronously when TRG cleared and overflow occurs

**Note:** In overflow and match mode, match event ignored until first overflow occurs after mode setup.

---

## 20.3 Clock and Reset Management

### 20.3.1 Clock Domains

DMTimer operates across two clock domains:
- **OCP clock domain** - Interface clock for register access
- **Timer clock domain** - Functional clock for counter operation

**Synchronization:**
- Special logic handles resynchronization between domains
- At reset: full resynchronization path used (works with any clock ratio)
- Performance impact: access latency in OCP clock cycles

### 20.3.2 Write-Posted Mode

Improves access latency under restricted clock ratio conditions.

**Operation:**
- Enable: Set POSTED bit in TSICR (Timer Synchronous Interface Control Register)
- OCP write command granted before write completes in timer clock domain
- Allows concurrent writes to timer registers
- Software monitors completion via TWPS (Timer Write Posting Status Register)

**Benefits:**
- Reduced access latency
- Concurrent register writes possible
- Software-visible synchronization status

**Requirements:**
- Restricted clock ratio conditions must be met
- Check TWPS bits to ensure write completion before dependent operations

---

## 20.4 Register Access

### 20.4.1 Programming Timer Registers

Registers can be written when timer is running or stopped.

**Write Access Types:**
- **Posted Mode:** Write granted immediately, completion monitored via TWPS
- **Non-Posted Mode:** Write completes before grant (synchronous)

### 20.4.2 Reading Timer Registers

Registers can be read anytime.

**Read Access:**
- Values sampled from timer clock domain
- Synchronization handled automatically
- Read latency depends on mode (posted/non-posted)

### 20.4.3 OCP Error Generation

Errors generated for:
- Access to reserved register addresses
- Invalid access patterns

### 20.4.4 Write Posted Mode Details

#### Write Posted (TSICR POSTED = 1)

**Timing:**
- Command accepted immediately
- Actual write completes after synchronization
- Status tracked in TWPS register

**TWPS Status Bits:**
- One bit per write-able register
- Bit = 1: Write pending
- Bit = 0: Write completed

**Stall Period:**
- Typically no stall on write
- Software must check TWPS before critical operations

#### Write Non-Posted (TSICR POSTED = 0)

**Timing:**
- Command accepted after write completes
- Guaranteed synchronization before grant
- Stall period: 2 Timer clocks + 2 OCP clocks

### 20.4.5 Read Access Details

#### Read Posted (TSICR POSTED = 1)

**Timing:**
- Command accepted quickly
- Value sampled with minimal latency

#### Read Non-Posted (TSICR POSTED = 0)

**Timing:**
- Stall max: 3 OCP clocks + 2.5 Timer clocks
- Read sample time: 1 OCP clock + 2.5 Timer clocks

---

## 20.5 Timer Registers

### 20.5.1 Register Summary

Base addresses for Timer instances:
- **DMTIMER0:** 0x44E05000
- **DMTIMER1_1MS:** 0x44E31000
- **DMTIMER2:** 0x48040000
- **DMTIMER3:** 0x48042000
- **DMTIMER4:** 0x48044000
- **DMTIMER5:** 0x48046000
- **DMTIMER6:** 0x48048000
- **DMTIMER7:** 0x4804A000

| Offset | Register | Description |
|--------|----------|-------------|
| 0x00 | TIDR | Identification Register |
| 0x10 | TIOCP_CFG | Timer OCP Configuration Register |
| 0x20 | IRQ_EOI | Timer IRQ End-of-Interrupt Register |
| 0x24 | IRQSTATUS_RAW | Timer Status Raw Register |
| 0x28 | IRQSTATUS | Timer Status Register |
| 0x2C | IRQENABLE_SET | Timer Interrupt Enable Set Register |
| 0x30 | IRQENABLE_CLR | Timer Interrupt Enable Clear Register |
| 0x34 | IRQWAKEEN | Timer IRQ Wakeup Enable Register |
| 0x38 | TCLR | Timer Control Register |
| 0x3C | TCRR | Timer Counter Register |
| 0x40 | TLDR | Timer Load Register |
| 0x44 | TTGR | Timer Trigger Register |
| 0x48 | TWPS | Timer Write Posting Bits Register |
| 0x4C | TMAR | Timer Match Register |
| 0x50 | TCAR1 | Timer Capture Register 1 |
| 0x54 | TSICR | Timer Synchronous Interface Control Register |
| 0x58 | TCAR2 | Timer Capture Register 2 |

### 20.5.2 TIDR - Identification Register (Offset 0x00)

Read-only register containing module revision number.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:30] | SCHEME | R | 0x1 | Scheme identifier |
| [29:28] | Reserved | R | 0x0 | - |
| [27:16] | FUNC | R | 0x0 | Function identifier |
| [15:11] | R_RTL | R | 0x0 | RTL revision |
| [10:8] | X_MAJOR | R | 0x1 | Major revision |
| [7:6] | CUSTOM | R | 0x0 | Custom version |
| [5:0] | Y_MINOR | R | 0x0 | Minor revision |

### 20.5.3 TIOCP_CFG - OCP Configuration Register (Offset 0x10)

Controls OCP interface behavior.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:4] | Reserved | R | 0x0 | - |
| [3:2] | IDLEMODE | R/W | 0x0 | Power management:<br>0x0 = Force-idle<br>0x1 = No-idle<br>0x2 = Smart-idle<br>0x3 = Smart-idle wakeup |
| [1] | EMUFREE | R/W | 0x0 | Emulation mode:<br>0 = Timer frozen in debug<br>1 = Timer runs in debug |
| [0] | SOFTRESET | R/W | 0x0 | Software reset:<br>Write 1 to trigger reset<br>Read 0 when reset complete |

### 20.5.4 IRQ_EOI - IRQ End-of-Interrupt (Offset 0x20)

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:1] | Reserved | R | 0x0 | - |
| [0] | LINE_NUMBER | W | - | Write any value to signal EOI |

### 20.5.5 IRQSTATUS_RAW - Status Raw Register (Offset 0x24)

Raw interrupt status (before masking).

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:3] | Reserved | R | 0x0 | - |
| [2] | TCAR_IT_FLAG | R/W | 0x0 | Capture event:<br>0 = No event<br>1 = Event pending |
| [1] | OVF_IT_FLAG | R/W | 0x0 | Overflow event:<br>0 = No event<br>1 = Event pending |
| [0] | MAT_IT_FLAG | R/W | 0x0 | Match event:<br>0 = No event<br>1 = Event pending |

### 20.5.6 IRQSTATUS - Status Register (Offset 0x28)

Enabled interrupt status (after masking). Write 1 to clear.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:3] | Reserved | R | 0x0 | - |
| [2] | TCAR_IT_FLAG | R/W | 0x0 | Capture interrupt status |
| [1] | OVF_IT_FLAG | R/W | 0x0 | Overflow interrupt status |
| [0] | MAT_IT_FLAG | R/W | 0x0 | Match interrupt status |

**Note:** Status not set unless event enabled. Write 1 to clear (clears raw status).

### 20.5.7 IRQENABLE_SET - Interrupt Enable Set (Offset 0x2C)

Enable interrupts. Write 1 to enable.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:3] | Reserved | R | 0x0 | - |
| [2] | TCAR_EN_FLAG | R/W | 0x0 | Enable capture interrupt |
| [1] | OVF_EN_FLAG | R/W | 0x0 | Enable overflow interrupt |
| [0] | MAT_EN_FLAG | R/W | 0x0 | Enable match interrupt |

### 20.5.8 IRQENABLE_CLR - Interrupt Enable Clear (Offset 0x30)

Disable interrupts. Write 1 to disable.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:3] | Reserved | R | 0x0 | - |
| [2] | TCAR_EN_FLAG | R/W | 0x0 | Disable capture interrupt |
| [1] | OVF_EN_FLAG | R/W | 0x0 | Disable overflow interrupt |
| [0] | MAT_EN_FLAG | R/W | 0x0 | Disable match interrupt |

### 20.5.9 IRQWAKEEN - IRQ Wakeup Enable (Offset 0x34)

Enable wakeup generation. Only applicable to Timer0.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:3] | Reserved | R | 0x0 | - |
| [2] | TCAR_WUP_ENA | R/W | 0x0 | Enable capture wakeup |
| [1] | OVF_WUP_ENA | R/W | 0x0 | Enable overflow wakeup |
| [0] | MAT_WUP_ENA | R/W | 0x0 | Enable match wakeup |

### 20.5.10 TCLR - Timer Control Register (Offset 0x38)

Main control register for timer configuration.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:15] | Reserved | R | 0x0 | - |
| [14] | GPO_CFG | R/W | 0x0 | General purpose output:<br>Drives PORGPOCFG pin directly |
| [13:12] | CAPT_MODE | R/W | 0x0 | Capture mode:<br>0x0 = Single capture (TCAR1 only)<br>0x1 = Dual capture (TCAR1 then TCAR2)<br>0x2 = Reserved<br>0x3 = Reserved |
| [11:10] | PT | R/W | 0x0 | Pulse/Toggle mode:<br>0x0 = Pulse<br>0x1 = Toggle<br>0x2 = Reserved<br>0x3 = Reserved |
| [9:8] | TRG | R/W | 0x0 | Trigger output:<br>0x0 = No trigger<br>0x1 = Trigger on overflow<br>0x2 = Trigger on overflow and match<br>0x3 = Reserved |
| [7] | TCM | R/W | 0x0 | Transition capture mode:<br>0x0 = No capture<br>0x1 = Capture on rising edge<br>0x2 = Capture on falling edge<br>0x3 = Capture on both edges |
| [6] | SCPWM | R/W | 0x0 | PWM output default value:<br>0 = Default low<br>1 = Default high |
| [5] | PRE | R/W | 0x0 | Prescaler enable:<br>0 = Prescaler disabled<br>1 = Prescaler enabled |
| [4:2] | PTV | R/W | 0x0 | Prescaler value (2^(PTV+1)):<br>0x0 = Divide by 2<br>0x1 = Divide by 4<br>0x2 = Divide by 8<br>...<br>0x7 = Divide by 256 |
| [1] | AR | R/W | 0x0 | Auto-reload mode:<br>0 = One-shot mode<br>1 = Auto-reload mode |
| [0] | ST | R/W | 0x0 | Start/Stop timer:<br>0 = Stop timer<br>1 = Start timer |

### 20.5.11 TCRR - Timer Counter Register (Offset 0x3C)

Current counter value. Read/write anytime.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:0] | TIMER_COUNTER | R/W | 0x0 | Current counter value |

### 20.5.12 TLDR - Timer Load Register (Offset 0x40)

Value loaded into counter on overflow (auto-reload mode) or trigger.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:0] | LOAD_VALUE | R/W | 0x0 | Timer load value |

**Note:** Do not write 0xFFFF_FFFF to avoid undesired behavior.

### 20.5.13 TTGR - Timer Trigger Register (Offset 0x44)

Write any value to trigger reload of TCRR from TLDR.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:0] | TTGR_VALUE | W | - | Write any value to trigger reload |

### 20.5.14 TWPS - Timer Write Posting Status (Offset 0x48)

Write posting status for each register. Read-only.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:6] | Reserved | R | 0x0 | - |
| [5] | W_PEND_TMAR | R | 0x0 | TMAR write pending:<br>0 = Write completed<br>1 = Write pending |
| [4] | W_PEND_TTGR | R | 0x0 | TTGR write pending |
| [3] | W_PEND_TLDR | R | 0x0 | TLDR write pending |
| [2] | W_PEND_TCRR | R | 0x0 | TCRR write pending |
| [1] | W_PEND_TCLR | R | 0x0 | TCLR write pending |
| [0] | W_PEND_TIOCP_CFG | R | 0x0 | TIOCP_CFG write pending |

**Usage:** Check appropriate bit = 0 before dependent operation.

### 20.5.15 TMAR - Timer Match Register (Offset 0x4C)

Compare value for match mode.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:0] | COMPARE_VALUE | R/W | 0x0 | Compare value for match detection |

### 20.5.16 TCAR1 - Timer Capture Register 1 (Offset 0x50)

Captured counter value (first capture or single capture mode).

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:0] | CAPTURED_VALUE | R | 0x0 | Captured counter value |

### 20.5.17 TSICR - Synchronous Interface Control (Offset 0x54)

Controls synchronization mode.

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:3] | Reserved | R | 0x0 | - |
| [2] | POSTED | R/W | 0x0 | Posted mode:<br>0 = Non-posted (synchronous)<br>1 = Posted (asynchronous) |
| [1] | SFT | R/W | 0x0 | Reset when read-back same value written |
| [0] | Reserved | R | 0x0 | - |

### 20.5.18 TCAR2 - Timer Capture Register 2 (Offset 0x58)

Captured counter value (second capture in dual capture mode).

| Bits | Field | Type | Reset | Description |
|------|-------|------|-------|-------------|
| [31:0] | CAPTURED_VALUE | R | 0x0 | Captured counter value |

---

## 20.6 Programming Sequences

### 20.6.1 Timer Mode - One Shot

```
1. Stop timer: TCLR.ST = 0
2. Configure timer:
   - TCLR.AR = 0 (one-shot mode)
   - TCLR.PRE = 0/1 (prescaler disable/enable)
   - TCLR.PTV = prescaler value
3. Load counter: TCRR = initial value
4. Enable overflow interrupt: IRQENABLE_SET.OVF_EN_FLAG = 1
5. Start timer: TCLR.ST = 1
6. Wait for overflow interrupt
7. Service interrupt: Write 1 to IRQSTATUS.OVF_IT_FLAG
```

### 20.6.2 Timer Mode - Auto Reload

```
1. Stop timer: TCLR.ST = 0
2. Configure timer:
   - TCLR.AR = 1 (auto-reload mode)
   - TCLR.PRE = 0/1 (prescaler disable/enable)
   - TCLR.PTV = prescaler value
3. Load reload value: TLDR = reload value
4. Load counter: TCRR = initial value (or trigger via TTGR)
5. Enable overflow interrupt: IRQENABLE_SET.OVF_EN_FLAG = 1
6. Start timer: TCLR.ST = 1
7. Counter reloads from TLDR on each overflow
```

### 20.6.3 Capture Mode - Single Capture

```
1. Configure capture:
   - TCLR.CAPT_MODE = 0 (single capture)
   - TCLR.TCM = 1/2/3 (rising/falling/both edges)
2. Enable capture interrupt: IRQENABLE_SET.TCAR_EN_FLAG = 1
3. Start timer: TCLR.ST = 1
4. Wait for capture interrupt
5. Read captured value from TCAR1
6. Clear interrupt: Write 1 to IRQSTATUS.TCAR_IT_FLAG
7. Ready for next capture
```

### 20.6.4 Capture Mode - Dual Capture (Period Measurement)

```
1. Configure capture:
   - TCLR.CAPT_MODE = 1 (dual capture)
   - TCLR.TCM = 1 (rising edge for period measurement)
2. Enable capture interrupt: IRQENABLE_SET.TCAR_EN_FLAG = 1
3. Start timer: TCLR.ST = 1
4. Wait for capture interrupt (first edge)
5. Wait for capture interrupt (second edge)
6. Read TCAR1 (first edge timestamp)
7. Read TCAR2 (second edge timestamp)
8. Calculate period: Period = TCAR2 - TCAR1
9. Clear interrupt: Write 1 to IRQSTATUS.TCAR_IT_FLAG
10. Ready for next period measurement
```

### 20.6.5 Compare Mode

```
1. Stop timer: TCLR.ST = 0
2. Write compare value: TMAR = match value
3. Configure timer:
   - TCLR.CE = 1 (compare enable)
   - TCLR.AR = 1 (typically auto-reload)
4. Load reload value: TLDR = reload value
5. Load counter: TCRR = initial value
6. Enable match interrupt: IRQENABLE_SET.MAT_EN_FLAG = 1
7. Start timer: TCLR.ST = 1
8. Wait for match interrupt
9. Service interrupt: Write 1 to IRQSTATUS.MAT_IT_FLAG
```

### 20.6.6 PWM Mode

```
1. Stop timer: TCLR.ST = 0
2. Configure PWM:
   - TCLR.AR = 1 (auto-reload for continuous PWM)
   - TCLR.CE = 1 (compare enable for duty cycle)
   - TCLR.PT = 1 (toggle mode)
   - TCLR.TRG = 2 (trigger on overflow and match)
   - TCLR.SCPWM = 0/1 (default output level)
3. Set period: TLDR = 0xFFFFFFFF - period + 1
4. Set duty cycle: TMAR = 0xFFFFFFFF - duty_cycle + 1
5. Load counter: TCRR = TLDR (or write to TTGR)
6. Start timer: TCLR.ST = 1
7. PWM signal generated on PORTIMERPWM pin
```

**PWM Calculations:**
- Frequency = Timer_Clock / ((0xFFFFFFFF - TLDR + 1) * Prescaler)
- Duty Cycle = (TMAR - TLDR) / (0xFFFFFFFF - TLDR + 1)

### 20.6.7 Using Write-Posted Mode

```
1. Enable posted mode: TSICR.POSTED = 1
2. Write to timer register (e.g., TCRR = value)
3. Check write completion:
   while (TWPS.W_PEND_TCRR) {
       // Wait for write to complete
   }
4. Proceed with dependent operation
```

---

## 20.7 Key Concepts Summary

### 20.7.1 Operating Modes

```
Timer Mode Hierarchy:
├── Timer Mode (Free-running counter)
│   ├── One-Shot (stops on overflow)
│   └── Auto-Reload (reloads from TLDR)
├── Capture Mode (save counter on external event)
│   ├── Single Capture (TCAR1 only)
│   └── Dual Capture (TCAR1 then TCAR2)
└── Compare Mode (interrupt/output on match)
    ├── Match Interrupt
    └── PWM Generation
```

### 20.7.2 Clock Architecture

```
Input Clock → Prescaler (optional) → Timer Counter → Overflow/Match
                ÷2^(PTV+1)             (TCRR)          Events
                
Prescaler Values:
PTV=0: ÷2    PTV=4: ÷32
PTV=1: ÷4    PTV=5: ÷64
PTV=2: ÷8    PTV=6: ÷128
PTV=3: ÷16   PTV=7: ÷256
```

### 20.7.3 Interrupt Sources

```
Timer Interrupts:
├── Overflow (OVF_IT_FLAG)
│   └── Counter reaches 0xFFFFFFFF and rolls over
├── Match (MAT_IT_FLAG)
│   └── Counter (TCRR) equals Match register (TMAR)
└── Capture (TCAR_IT_FLAG)
    └── External event detected on PIEVENTCAPT pin
```

### 20.7.4 Register Dependencies

```
Counter Operation:
TCRR ← TLDR (when TTGR written or overflow with AR=1)
TCRR → TCAR1/TCAR2 (when capture event occurs)
TCRR ≟ TMAR (compare operation when CE=1)

Control Flow:
TCLR.ST → Start/Stop counter
TCLR.AR → Auto-reload behavior
TCLR.CE → Compare enable
TCLR.TCM → Capture edge select
TCLR.TRG → Output trigger mode
```

### 20.7.5 Access Latency

```
Non-Posted Mode:
Write: 2 Timer clocks + 2 OCP clocks
Read:  3 OCP clocks + 2.5 Timer clocks

Posted Mode:
Write: Immediate grant, check TWPS for completion
Read:  Minimal latency

Trade-off:
- Non-Posted: Guaranteed synchronization, higher latency
- Posted: Lower latency, software must check TWPS
```

### 20.7.6 Common Use Cases

| Application | Mode | Configuration |
|-------------|------|---------------|
| Periodic Interrupt | Auto-Reload Timer | AR=1, Enable OVF interrupt |
| Timeout Detection | One-Shot Timer | AR=0, Enable OVF interrupt |
| Event Timestamping | Capture Mode | Single capture, TCM=edge type |
| Frequency Measurement | Dual Capture | CAPT_MODE=1, TCM=1 (rising) |
| PWM Generation | Compare + Auto-Reload | CE=1, AR=1, TRG=2, PT=1 |
| Precise Delay | Compare Mode | CE=1, one-shot or auto-reload |

---

## 20.8 Important Notes

1. **Register Access:** All timer registers can be accessed while timer is running (on-the-fly access)

2. **TLDR Value:** Never write 0xFFFF_FFFF to TLDR as it causes undefined behavior

3. **Compare Mode Setup:** Always write TMAR before setting TCLR.CE to avoid spurious match interrupts

4. **Capture Logic Reset:** Capture detection logic automatically resets when interrupt is serviced (TCAR_IT_FLAG cleared)

5. **Posted Mode:** When using posted mode, always check TWPS before operations dependent on previous writes

6. **Prescaler Reset:** Prescaler counter resets on timer stop, reload, or write to TCRR

7. **PWM Match Event:** In overflow and match mode, first match event after mode setup is ignored until first overflow occurs

8. **Wakeup Capability:** Only Timer0 supports wakeup generation from low power modes

9. **Counter Width:** Timer counter is 32-bit, can count from 0 to 0xFFFF_FFFF

10. **Interrupt Clearing:** Write 1 to interrupt status bit to clear (writing 0 has no effect)

# Chapter 25: General-Purpose Input/Output (GPIO)

## 25.1 Introduction

### 25.1.1 Purpose of the Peripheral

The general-purpose interface combines four general-purpose input/output (GPIO) modules. Each GPIO module provides 32 dedicated general-purpose pins with input and output capabilities; thus, the general purpose interface supports up to **128 (4 × 32) pins**. 

These pins can be configured for the following applications:

- **Data input (capture)/output (drive)**
- **Keyboard interface** with a debounce cell
- **Interrupt generation** in active mode upon the detection of external events. Detected events are processed by two parallel independent interrupt-generation submodules to support biprocessor operations.
- **Wake-up request generation** in idle mode upon the detection of external events.

### 25.1.2 GPIO Features

Each GPIO module is made up of **32 identical channels**. Each channel can be configured to be used in the following applications:

- Data input/output
- Keyboard interface with a de-bouncing cell
- Synchronous interrupt generation (in active mode) upon the detection of external events (signal transition(s) and/or signal level(s))
- Wake-up request generation (in Idle mode) upon the detection of signal transition(s)

**Global features of the GPIO interface are:**

- Synchronous interrupt requests from each channel are processed by two identical interrupt generation sub-modules to be used independently by the ARM Subsystem
- Wake-up requests from input channels are merged together to issue one wake-up signal to the system
- Shared registers can be accessed through "Set & Clear" protocol

### 25.1.3 Unsupported GPIO Features

⚠️ **Important:** The wake-up feature of the GPIO modules is only supported on **GPIO0**.

---

## 25.2 Integration

The device instantiates four GPIO_V2 modules. Each GPIO module provides the support for 32 dedicated pins with input and output configuration capabilities. Input signals can be used to generate interruptions and wake-up signal. Two Interrupt lines are available for bi-processor operation. Pins can be dedicated to be used as a keyboard controller.

With four GPIO modules, the device allows for a maximum of **128 GPIO pins**. (The exact number available varies as a function of the device configuration and pin muxing.) 

- **GPIO0** is in the Wakeup domain and may be used to wake up the device via external sources. 
- **GPIO[1:3]** are located in the peripheral domain.

*[Sơ đồ GPIO integration - Figure 25-1 và Figure 25-2 - bỏ qua trong phiên bản text]*

### 25.2.3 GPIO Pin List

Each GPIO module includes 32 interface I/Os. These signals are designated as shown in the table below. Note that for this device, most of these signals will be multiplexed with functional signals from other interfaces.

**Table 25-4: GPIO Pin List**

| Pin | Type | Description |
|-----|------|-------------|
| GPIO0_[31:0] | I/O | General Purpose Input-Output pins |
| GPIO1_[31:0] | I/O | General Purpose Input-Output pins |
| GPIO2_[31:0] | I/O | General Purpose Input-Output pins |
| GPIO3_[31:0] | I/O | General Purpose Input-Output pins |
| GPIO4_[31:0] | I/O | General Purpose Input-Output pins |
| GPIO5_[31:0] | I/O | General Purpose Input-Output pins |

---

## 25.3 Functional Description

This section discusses the operational details and basic functions of the GPIO peripheral.

### 25.3.1 Operating Modes

Four operating modes are defined for the module:

#### 1. Active Mode
The module is running synchronously on the interface clock, interrupt can be generated according to the configuration and the external signals.

#### 2. Idle Mode
The module is in a waiting state, interface clock can be stopped, no interrupt can be generated, a wake-up signal can be generated according to the configuration and external signals.

⚠️ **Note:** Check the chip top-level functional specification for the availability of the debouncing clock while in Idle mode. If the debouncing clock is active, the debouncing cell can be used to sample and to filter the input to generate a wakeup event. Otherwise (debouncing clock inactive), the debouncing cell cannot be used, as it would gate all input signals.

#### 3. Inactive Mode
The module has no activity, interface clock can be stopped, no interrupt can be generated, and the wake-up feature is inhibited.

#### 4. Disabled Mode
The module is not used, internal clock paths are gated, no interrupt or wake-up request can be generated.

The Idle and Inactive modes are configured within the module and activated on request by the host processor through system interface sideband signals. The Disabled mode is set by software through a dedicated configuration bit. It unconditionally gates the internal clock paths not use for the system interface. 

All module registers are **8, 16 or 32-bit accessible** through the OCP compatible interface (little endian encoding). In active mode, the event detection (level or transition) is performed in the GPIO module using the interface clock. The detection's precision is set by the frequency of this clock and the selected internal gating scheme.

---

### 25.3.2 Clocking and Reset Strategy

#### 25.3.2.1 Clocks

GPIO module runs using **two clocks**:

1. **Debouncing clock** - Used for the debouncing sub-module logic (without the corresponding configuration registers). This module can sample the input line and filters the input level using a programmed delay.

2. **Interface clock** - Provided by the peripheral bus (OCP compatible system interface). It is used through the entire GPIO module (except within the debouncing sub-module logic). It clocks the OCP interface and the internal logic. Clock gating features allow adapting the module power consumption to the activity.

#### 25.3.2.2 Clocks, Gating and Active Edge Definitions

The interface clock provided by the peripheral bus (OCP compatible system interface) is used through the entire GPIO module. Two clock domains are defined: the OCP interface and the internal logic. Each clock domain can be controlled independently. 

- Sampling operations for the data capture and for the events detection are done using the **rising edge**. 
- The data loaded in the data output register (GPIO_DATAOUT) is set at the output GPIO pins synchronously with the **rising edge** of the interface clock.

**Five clock gating features are available:**

1. Clock for the system interface logic can be gated when the module is not accessed, if the **AUTOIDLE** configuration bit in the system configuration register (GPIO_SYSCONFIG) is set. Otherwise, this logic is free running on the interface clock.

2. Clock for the input data sample logic can be gated when the data in register is not accessed.

3. Four clock groups are used for the logic in the synchronous events detection. Each 8 input GPIO_V2 pins group will have a separate enable signal depending on the edge/level detection register setting. If a group requires no detection, then the corresponding clock will be gated. All channels are also gated using a **'one out of N' scheme**. N can take the values 1, 2, 4 or 8. The interface clock is enabled for this logic one cycle every N cycles. When N is equal to 1, there is no gating and this logic is free running on the interface clock. When N is between 2 to 8, this logic is running at the equivalent frequency of interface clock frequency divided by N.

4. In **Inactive mode**, all internal clock paths are gated.

5. In **Disabled mode**, all internal clock paths not used for the system interface are gated. All GPIO registers are accessible synchronously with the interface clock.

#### 25.3.2.3 Sleep Mode Request and Acknowledge

Upon a Sleep mode request issued by the host processor, the GPIO module goes to the Idle mode according to the **IDLEMODE** field in the system configuration register (GPIO_SYSCONFIG).

- **IDLEMODE = 0 (Force-Idle mode):** The GPIO goes in Inactive mode independently of the internal module state and the Idle acknowledge is unconditionally sent. In Force-Idle mode, the module is in Inactive mode and its wake-up feature is totally inhibited.

- **IDLEMODE = 1h (No-Idle mode):** The GPIO does not go to the Idle mode and the Idle acknowledge is never sent.

- **IDLEMODE = 2h (Smart-Idle mode) or IDLEMODE = 3h (Smart-Idle mode):** The GPIO module evaluates its internal capability to have the interface clock switched off. Once there is no more internal activity (the data input register completed to capture the input GPIO pins, there is no pending interrupt, all interrupt status bits are cleared, and there is no write access to GPIO_DEBOUNCINGTIME register pending to be synchronized), the Idle acknowledge is asserted and the GPIO enters Idle mode, ready to issue a wake-up request when the expected transition occurs on an enabled GPIO input pin. This wake-up request is effectively sent only if the **ENAWAKEUP** bit in GPIO_SYSCONFIG is set to enable the GPIO wakeup capability. When the system is awake, the Idle Request goes inactive, the Idle acknowledge and wake-up request (if it is the GPIO that triggered the system's wakeup) signals are immediately de-asserted, and the asynchronous wake-up request (if existing) is reflected into the synchronous interrupt status registers.

⚠️ **NOTE:** Idle mode request and Idle acknowledge are system interface sideband signals. Once the GPIO acknowledges the Sleep mode request (Idle acknowledge has been sent), the interface clock can be stopped anytime.

⚠️ **Important:** Upon a Sleep mode request issued by the host processor, the GPIO module goes to the Idle mode only if there is **no active bit** in GPIO_IRQSTATUS_RAW_n registers.

#### 25.3.2.4 Reset

The OCP hardware Reset signal has a global reset action on the GPIO. All configuration registers, all DFFs clocked with the Interface clock or Debouncing clock and all internal state machines are reset when the OCP hardware Reset is active (low level). 

The **RESETDONE** bit in the system status register (GPIO_SYSSTATUS) monitors the internal reset status: it is set when the Reset is completed on both OCP and Debouncing clock domains. 

The **software Reset** (SOFTRESET bit in the system configuration register) has the same effect as the OCP hardware Reset signal, and the RESETDONE bit in GPIO_SYSSTATUS monitors the reset completion.

---

### 25.3.3 Interrupt and Wakeup Events

*[Nội dung về Interrupt và Wakeup Events - có sơ đồ Figure 25-3 đến Figure 25-6 - bỏ qua trong phiên bản text]*

---

### 25.3.4 Peripheral Operating Features

#### 25.3.4.1 Software Reset

Software reset is achieved by setting the SOFTRESET bit in GPIO_SYSCONFIG. When the reset process is completed, the RESETDONE bit is set in GPIO_SYSSTATUS register. The software reset also resets the debouncing clock domain.

#### 25.3.4.2 Register Access Protocols

All GPIO registers are accessible with read/write operations and a subset of three registers (Interrupt enable 1 or 2, wake-up enable and data output) offers an alternate access protocol to set/clear register bits.

##### 25.3.4.2.1 Standard Read/Write Access Protocol

All registers are accessed by the standard read/write protocol. Each standard register has a unique address. A full 32 bits word is accessed for any memory access to this address.

##### 25.3.4.2.2 Alternate Set/Clear Protocol

To allow concurrent programming of shared register by two host processors, three registers (interrupt enable 1 or 2, wake-up enable and data output) are internally accessed through the set and clear protocol using two distinct addresses for each register.

This feature allows you to set or clear specific bits of the register with a single write access to the set register address or to the clear register address. This prevents any concurrent access conflict when both processors try to update the same register, provided they access only bits which are specifically assigned to them.

###### 25.3.4.2.2.1 Set Interrupt Enable Registers (GPIO_SETIRQENABLE1 and GPIO_SETIRQENABLE2):

- A write operation in the set interrupt enable1 (or enable2) register sets the corresponding bit in the interrupt enable1 (or enable2) register when the written bit is 1; a written bit at 0 has no effect.
- A read of the set interrupt enable1 (or enable2) register returns the value of the interrupt enable1 (or enable2) register.

###### 25.3.4.2.2.2 Set Wake-up Enable Register (GPIO_SETWKUENA):

- A write operation in the set wake-up enable register sets the corresponding bit in the wake-up enable register when the written bit is 1; a written bit at 0 has no effect.
- A read of the set wake-up enable register returns the value of the wake-up enable register.

###### 25.3.4.2.2.3 Set Data Output Register (GPIO_SETDATAOUT):

- A write operation in the set data output register sets the corresponding bit in the data output register when the written bit is 1; a written bit at 0 has no effect.
- A read of the set data output register returns the value of the data output register.

###### 25.3.4.2.2.4 Set Instruction Example

Assume the interrupt enable1 (or enable2) register (or the data output register) contains the binary value, `0000 0001 0000 0000h`, and you want to set bits 15, 3, 2, and 1.

With the set instruction feature, write `1000 0000 0000 1110h` at the address of the set interrupt enable1 (or enable2) register (or at the address of the set data output register). After this write operation, a reading of the interrupt enable1 (or enable2) register (or the data output register) returns `1000 0001 0000 1110h`; bits 15, 3, 2, and 1 are set.

⚠️ **NOTE:** Although the general-purpose interface registers are 32-bits wide, only the 16 least significant bits are represented in this example.

#### 25.3.4.3 Data Input (Capture)/Output (Drive)

The output enable register (**GPIO_OE**) controls the output/input capability for each pin. At reset, all the GPIO-related pins are configured as input and output capabilities are disabled. This register is not used within the module; its only function is to carry the pads configuration.

**Output Configuration:**
When configured as an output (the desired bit **reset** in GPIO_OE), the value of the corresponding bit in the GPIO_DATAOUT register is driven on the corresponding GPIO pin. Data is written to the data output register synchronously with the interface clock. This register can be accessed with read/write operations or by using the alternate set and clear protocol register update feature. This feature lets you set or clear specific bits of this register with a single write access to the set data output register (GPIO_SETDATAOUT) or to the clear data output register (GPIO_CLEARDATAOUT) address. 

⚠️ If the application uses a pin as an output and does not want interrupt/wake-up generation from this pin, the application must properly configure the wake-up enable and the interrupt enable registers.

**Input Configuration:**
When configured as an input (the desired bit **set to 1** in GPIO_OE), the state of the input can be read from the corresponding bit in the GPIO_DATAIN register. The input data is sampled synchronously with the interface clock and then captured in the data input register synchronously with the interface clock. When the GPIO pin levels change, they are captured into this register after **two interface clock cycles** (the required cycles to synchronize and to write data). 

⚠️ If the application uses a pin as an input, the application must properly configure the wake-up enable and the interrupt enable registers to the interrupt and wake up feature as needed.

#### 25.3.4.4 Debouncing Time

To enable the debounce feature for a pin, the GPIO configuration registers must be programmed as follows:

1. **The GPIO pin must be configured as input** in the output enable register (write 1 to the corresponding bit of the GPIO_OE register).

2. **The debouncing time must be set** in the debouncing value register (GPIO_DEBOUNCINGTIME). The GPIO_DEBOUNCINGTIME register is used to set the debouncing time for all input lines in the GPIO module. The value is global for all the ports of one GPIO module, so up to six different debouncing values are possible. The debounce cell is running with the debounce clock (32 kHz). This register represents the number of the clock cycle(s) (one cycle is 31 microseconds long) to be used.

   **Debouncing Time Formula:**
   ```
   Debouncing time = (DEBOUNCETIME + 1) × 31 µs
   ```
   Where the DEBOUNCETIME field value in the GPIO_DEBOUNCINGTIME register is from 0 to 255.

3. **The debouncing feature must be enabled** in the debouncing enable register (write 1 to the corresponding DEBOUNCEENABLE bit in the GPIO_DEBOUNCEENABLE register).

#### 25.3.4.5 GPIO as a Keyboard Interface

The general-purpose interface can be used as a keyboard interface.

*[Sơ đồ Figure 25-7 - bỏ qua trong phiên bản text]*

You can dedicate channels based on the keyboard matrix = r × c. The diagram shows row channels configured as inputs with the input debounce feature enabled. The row channels are driven high with an external pull-up. Column channels are configured as outputs and drive a low level.

**Operation:**

When a keyboard matrix key is pressed, the corresponding row and column lines are shorted together and a low level is driven on the corresponding row channel. This generates an interrupt based on the proper configuration.

When the keyboard interrupt is received, the processor can disable the keyboard interrupt and scan the column channels for the key coordinates.

- **The scanning sequence** has as many states as column channels: For each step in the sequence, the processor drives one column channel low and the others high.
- **The processor reads** the values of the row channels and thus detects which keys in the column are pressed.

At the end of the scanning sequence, the processor establishes which keys are pressed. The keyboard interface can then be reconfigured in the interrupt waiting state.

---

## 25.4 GPIO Registers

### 25.4.1 GPIO Registers

Table below lists the memory-mapped registers for the GPIO. All register offset addresses not listed should be considered as reserved locations and the register contents should not be modified.

**Table 25-5: GPIO Registers**

| Offset | Acronym | Register Name |
|--------|---------|---------------|
| 0h | GPIO_REVISION | GPIO Revision Register |
| 10h | GPIO_SYSCONFIG | GPIO System Configuration Register |
| 20h | GPIO_EOI | GPIO End of Interrupt Register |
| 24h | GPIO_IRQSTATUS_RAW_0 | GPIO Interrupt Raw Status Register 0 |
| 28h | GPIO_IRQSTATUS_RAW_1 | GPIO Interrupt Raw Status Register 1 |
| 2Ch | GPIO_IRQSTATUS_0 | GPIO Interrupt Status Register 0 |
| 30h | GPIO_IRQSTATUS_1 | GPIO Interrupt Status Register 1 |
| 34h | GPIO_IRQSTATUS_SET_0 | GPIO Interrupt Status Set Register 0 |
| 38h | GPIO_IRQSTATUS_SET_1 | GPIO Interrupt Status Set Register 1 |
| 3Ch | GPIO_IRQSTATUS_CLR_0 | GPIO Interrupt Status Clear Register 0 |
| 40h | GPIO_IRQSTATUS_CLR_1 | GPIO Interrupt Status Clear Register 1 |
| 44h | GPIO_IRQWAKEN_0 | GPIO Interrupt Wakeup Enable Register 0 |
| 48h | GPIO_IRQWAKEN_1 | GPIO Interrupt Wakeup Enable Register 1 |
| 114h | GPIO_SYSSTATUS | GPIO System Status Register |
| 130h | GPIO_CTRL | GPIO Control Register |
| 134h | GPIO_OE | GPIO Output Enable Register |
| 138h | GPIO_DATAIN | GPIO Data Input Register |
| 13Ch | GPIO_DATAOUT | GPIO Data Output Register |
| 140h | GPIO_LEVELDETECT0 | GPIO Level Detect 0 Register |
| 144h | GPIO_LEVELDETECT1 | GPIO Level Detect 1 Register |
| 148h | GPIO_RISINGDETECT | GPIO Rising Edge Detect Register |
| 14Ch | GPIO_FALLINGDETECT | GPIO Falling Edge Detect Register |
| 150h | GPIO_DEBOUNCENABLE | GPIO Debounce Enable Register |
| 154h | GPIO_DEBOUNCINGTIME | GPIO Debouncing Time Register |
| 190h | GPIO_CLEARDATAOUT | GPIO Clear Data Output Register |
| 194h | GPIO_SETDATAOUT | GPIO Set Data Output Register |

---

## 25.4.2 GPIO Register Details

### 25.4.1.1 GPIO_REVISION Register (offset = 0h) [reset = 50600801h]

**Description:**
The GPIO revision register is a read only register containing the revision number of the GPIO module. A write to this register has no effect, that is, the same as the reset.

**Register Diagram:**
```
[31:30] SCHEME      [29:28] RESERVED   [27:16] FUNC
[15:11] RTL         [10:8]  MAJOR      [7:6]   CUSTOM     [5:0] MINOR
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-30 | SCHEME | R | 1h | Used to distinguish between old Scheme and current. |
| 29-28 | RESERVED | R | 1h | Reserved |
| 27-16 | FUNC | R | 60h | Indicates a software compatible module family. |
| 15-11 | RTL | R | 1h | RTL version |
| 10-8 | MAJOR | R | 0h | Major Revision |
| 7-6 | CUSTOM | R | 0h | Indicates a special version for a particular device. |
| 5-0 | MINOR | R | 1h | Minor Revision |

---

### 25.4.1.2 GPIO_SYSCONFIG Register (offset = 10h) [reset = 0h]

**Description:**
The GPIO_SYSCONFIG register controls various parameters of the L4 interconnect. When the AUTOIDLE bit is not set, the GPIO_DATAIN read command has a 3 OCP cycle latency due to the data in sample gating mechanism. When the AUTOIDLE bit is not set, the GPIO_DATAIN read command has a 2 OCP cycle latency.

**Register Diagram:**
```
[31:5]  RESERVED
[4:3]   IDLEMODE    [2] ENAWAKEUP    [1] SOFTRESET    [0] AUTOIDLE
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-5 | RESERVED | R | 0h | Reserved |
| 4-3 | IDLEMODE | R/W | 0h | Power Management, Reg/Ack control.<br>0h = Force-idle. An idle request is acknowledged unconditionally<br>1h = No-idle. An idle request is never acknowledged<br>2h = Smart-idle. Acknowledgment to an idle request is given based on the internal activity of the module<br>3h = Smart Idle Wakeup (GPIO0 only) |
| 2 | ENAWAKEUP | R/W | 0h | 0h = Wakeup generation is disabled<br>1h = Wakeup capability is enabled upon expected transition on input GPIO pin. |
| 1 | SOFTRESET | R/W | 0h | Software reset.<br>This bit is automatically reset by the hardware.<br>During reads, it always returns 0.<br>0h = Normal mode<br>1h = The module is reset |
| 0 | AUTOIDLE | R/W | 0h | Internal interface clock gating strategy<br>0h = Internal interface OCP clock is free-running<br>1h = Automatic internal OCP clock gating, based on the OCP interface activity |

---

### 25.4.1.3 GPIO_EOI Register (offset = 20h) [reset = 0h]

**Description:**
This module supports DMA events with its interrupt signal. This register must be written to after the DMA completes in order for subsequent DMA events to be triggered from this module.

**Register Diagram:**
```
[31:1]  RESERVED
[0]     DMAEvent_Ack
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-1 | RESERVED | R | 0h | Reserved |
| 0 | DMAEvent_Ack | R/W | 0h | Write 1 to clear the pending DMA event triggered to the DMA. The Module will be able to generate another DMA event only when the previous one has been acknowledged using this register.<br>Reads always returns 0. |

---

### 25.4.1.4 GPIO_IRQSTATUS_RAW_0 Register (offset = 24h) [reset = 0h]

**Description:**
The GPIO_IRQSTATUS_RAW_0 register provides core status information for the interrupt handling, showing all active events (enabled and not enabled). The fields are read-write. Writing a 1 to a bit sets it to 1, that is, triggers the IRQ (mostly for debug). Writing a 0 has no effect, that is, the register value is not be modified. Only enabled, active events trigger an actual interrupt request on the IRQ output line.

**Register Diagram:**
```
[31:0]  INTLINE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE[n] | R/W | 0h | Interrupt n status.<br>0h = No effect.<br>1h = IRQ is triggered. |

---

### 25.4.1.5 GPIO_IRQSTATUS_RAW_1 Register (offset = 28h) [reset = 0h]

**Description:**
The GPIO_IRQSTATUS_RAW_1 register provides core status information for the interrupt handling, showing all active events (enabled and not enabled). The fields are read-write. Writing a 1 to a bit sets it to 1, that is, triggers the IRQ (mostly for debug). Writing a 0 has no effect, that is, the register value is not be modified. Only enabled, active events trigger an actual interrupt request on the IRQ output line.

**Register Diagram:**
```
[31:0]  INTLINE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE[n] | R/W | 0h | Interrupt n status.<br>0h = No effect.<br>1h = IRQ is triggered. |

---

### 25.4.1.6 GPIO_IRQSTATUS_0 Register (offset = 2Ch) [reset = 0h]

**Description:**
The GPIO_IRQSTATUS_0 register provides core status information for the interrupt handling, showing all active events which have been enabled. The fields are read-write. Writing a 1 to a bit clears the bit to 0, that is, the IRQ. Writing a 0 has no effect, that is, the register value is not modified. Only enabled, active events trigger an actual interrupt request on the IRQ output line.

**Register Diagram:**
```
[31:0]  INTLINE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE[n] | R/W1C | 0h | Interrupt n status.<br>0h (W) = No effect.<br>0h (R) = IRQ is not triggered.<br>1h (W) = Clears the IRQ.<br>1h (R) = IRQ is triggered. |

---

### 25.4.1.7 GPIO_IRQSTATUS_1 Register (offset = 30h) [reset = 0h]

**Description:**
The GPIO_IRQSTATUS_1 register provides core status information for the interrupt handling, showing all active events which have been enabled. The fields are read-write. Writing a 1 to a bit clears the bit to 0, that is, the IRQ. Writing a 0 has no effect, that is, the register value is not modified. Only enabled, active events trigger an actual interrupt request on the IRQ output line.

**Register Diagram:**
```
[31:0]  INTLINE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE[n] | R/W1C | 0h | Interrupt n status.<br>0h (W) = No effect.<br>0h (R) = IRQ is not triggered.<br>1h (W) = Clears the IRQ.<br>1h (R) = IRQ is triggered. |

---

### 25.4.1.8 GPIO_IRQSTATUS_SET_0 Register (offset = 34h) [reset = 0h]

**Description:**
All 1-bit fields in the GPIO_IRQSTATUS_SET_0 register enable a specific interrupt event to trigger an interrupt request on the appropriate output line. Writing a 1 to a bit enables the interrupt event. Writing a 0 has no effect, that is, the register value is not modified.

**Register Diagram:**
```
[31:0]  INTLINE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE[n] | R/W | 0h | Interrupt n enable<br>0h = No effect.<br>1h = Enable IRQ generation. |

---

### 25.4.1.9 GPIO_IRQSTATUS_SET_1 Register (offset = 38h) [reset = 0h]

**Description:**
All 1-bit fields in the GPIO_IRQSTATUS_SET_1 register enable a specific interrupt event to trigger an interrupt request on the appropriate output line. Writing a 1 to a bit enables the interrupt event. Writing a 0 has no effect, that is, the register value is not modified.

**Register Diagram:**
```
[31:0]  INTLINE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE[n] | R/W | 0h | Interrupt n enable<br>0h = No effect.<br>1h = Enable IRQ generation. |

---

### 25.4.1.10 GPIO_IRQSTATUS_CLR_0 Register (offset = 3Ch) [reset = 0h]

**Description:**
All 1-bit fields in the GPIO_IRQSTATUS_CLR_0 register disable a specific interrupt event. Writing a 1 to a bit disables the interrupt field. Writing a 0 has no effect, that is, the register value is not modified.

**Register Diagram:**
```
[31:0]  INTLINE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE[n] | R/W | 0h | Interrupt n enable<br>0h = No effect.<br>1h = Disable IRQ generation. |

---

### 25.4.1.11 GPIO_IRQSTATUS_CLR_1 Register (offset = 40h) [reset = 0h]

**Description:**
All 1-bit fields in the GPIO_IRQSTATUS_CLR_1 register disable a specific interrupt event. Writing a 1 to a bit disables the interrupt field. Writing a 0 has no effect, that is, the register value is not modified.

**Register Diagram:**
```
[31:0]  INTLINE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE[n] | R/W | 0h | Interrupt n enable<br>0h = No effect.<br>1h = Disable IRQ generation. |

---

### 25.4.1.12 GPIO_IRQWAKEN_0 Register (offset = 44h) [reset = 0h]

**Description:**
Per-event wakeup enable vector (corresponding to first line of interrupt). Every 1-bit field in the GPIO_IRQWAKEN_0 register enables a specific (synchronous) IRQ request source to generate an asynchronous wakeup (on the appropriate wakeup line). This register allows the user to mask the expected transition on input GPIO from generating a wakeup request. The GPIO_IRQWAKEN_0 is programmed synchronously with the interface clock before any idle mode request coming from the host processor. 

**Note:** In Force-Idle mode, the module wake-up feature is totally inhibited. The wake-up generation can also be gated at module level using the EnaWakeup bit in SYSCONFIG register.

**Register Diagram:**
```
[31:0]  INTLINE
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE | R/W | 0h | Wakeup Enable for Interrupt Line<br>0h = Disable wakeup generation.<br>1h = Enable wakeup generation. |

---

### 25.4.1.13 GPIO_IRQWAKEN_1 Register (offset = 48h) [reset = 0h]

**Description:**
Per-event wakeup enable vector (corresponding to second line of interrupt). Every 1-bit field in the GPIO_IRQWAKEN_1 register enables a specific (synchronous) IRQ request source to generate an asynchronous wakeup (on the appropriate wakeup line). This register allows the user to mask the expected transition on input GPIO from generating a wakeup request. The GPIO_IRQWAKEN_1 is programmed synchronously with the interface clock before any idle mode request coming from the host processor. 

**Note:** In Force-Idle mode, the module wake-up feature is totally inhibited. The wake-up generation can also be gated at module level using the SYSCONFIG register.

**Register Diagram:**
```
[31:0]  INTLINE
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE | R/W | 0h | Wakeup Enable for Interrupt Line<br>0h = Disable wakeup generation.<br>1h = Enable wakeup generation. |

---

### 25.4.1.14 GPIO_SYSSTATUS Register (offset = 114h) [reset = 0h]

**Description:**
The GPIO_SYSSTATUS register provides the reset status information about the GPIO module. It is a read-only register, a write to this register has no effect.

**Register Diagram:**
```
[31:1]  RESERVED
[0]     RESETDONE
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-1 | RESERVED | R | 0h | Reserved |
| 0 | RESETDONE | R | 0h | Reset status information.<br>0h = Internal Reset is on-going.<br>1h = Reset completed. |

---

### 25.4.1.15 GPIO_CTRL Register (offset = 130h) [reset = 0h]

**Description:**
The GPIO_CTRL register controls the clock gating functionality. The DISABLEMODULE bit controls a clock gating feature at the module level. When set, this bit forces the clock gating for all internal clock paths. Module internal activity is suspended, System interface is not affected by this bit. System interface clock gating is controlled with the AUTOIDLE bit in the system configuration register (GPIO_SYSCONFIG). This bit is to be used for power saving when the module is not used because of the multiplexing configuration selected at the chip level. This bit has precedence over all other internal configuration bits.

**Register Diagram:**
```
[31:3]  RESERVED
[2:1]   GATINGRATIO    [0] DISABLEMODULE
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-3 | RESERVED | R | 0h | Reserved |
| 2-1 | GATINGRATIO | R/W | 0h | Gating Ratio.<br>Controls the clock gating for the event detection logic.<br>0h = Functional clock is interface clock.<br>1h = Functional clock is interface clock divided by 2.<br>2h = Functional clock is interface clock divided by 4.<br>3h = Functional clock is interface clock divided by 8. |
| 0 | DISABLEMODULE | R/W | 0h | Module Disable<br>0h = Module is enabled, clocks are not gated.<br>1h = Module is disabled, clocks are gated. |

---

### 25.4.1.16 GPIO_OE Register (offset = 134h) [reset = FFFFFFFFh]

**Description:**
The GPIO_OE register is used to enable the pin's output/input capabilities. At reset, all the GPIO related pins are configured as input and output capabilities are disabled. This register is not used within the module, its only function is to carry the pads configuration. When the application is using a pin as an output and does not want interrupt generation from this pin, the application can/has to properly configure the Interrupt Enable registers.

**Register Diagram:**
```
[31:0]  OUTPUTEN[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | OUTPUTEN[n] | R/W | FFFFFFFFh | Output Data Enable<br>0h = The corresponding GPIO port is configured as an output.<br>1h = The corresponding GPIO port is configured as an input. |

---

### 25.4.1.17 GPIO_DATAIN Register (offset = 138h) [reset = 0h]

**Description:**
The GPIO_DATAIN register is used to register the data that is read from the GPIO pins. The GPIO_DATAIN register is a read-only register. The input data is sampled synchronously with the interface clock and then captured in the GPIO_DATAIN register synchronously with the interface clock. When the GPIO pin levels are changing, GPIO pin levels are captured into this register after two interface clock cycles (the required cycles to synchronize and to write data in the register). When the AUTOIDLE bit in system configuration register (GPIO_SYSCONFIG) is set, the GPIO_DATAIN read command has a 3 OCP cycle latency due to the data in sample gating mechanism. When the AUTOIDLE bit is not set, the GPIO_DATAIN read command has a 2 OCP cycle latency.

**Register Diagram:**
```
[31:0]  DATAIN
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | DATAIN | R | 0h | Sampled Input Data |

---

### 25.4.1.18 GPIO_DATAOUT Register (offset = 13Ch) [reset = 0h]

**Description:**
The GPIO_DATAOUT register is used for setting the value of the GPIO output pins. Data is written to the GPIO_DATAOUT register synchronously with the interface clock. This register can be accessed with read/write operations, or through an alternate access protocol that enables you to set or clear specific bits of this register with a single write access to the set data output register (GPIO_SETDATAOUT) or to the clear data output register (GPIO_CLEARDATAOUT) address.

**Register Diagram:**
```
[31:0]  DATAOUT
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | DATAOUT | R/W | 0h | Data to set on output pins |

---

### 25.4.1.19 GPIO_LEVELDETECT0 Register (offset = 140h) [reset = 0h]

**Description:**
The GPIO_LEVELDETECT0 register is used to enable/disable for each input lines the low-level (0) detection to be used for the interrupt request generation. Enabling at the same time high-level detection and low-level detection for one given pin makes a constant interrupt.

**Register Diagram:**
```
[31:0]  LEVELDETECT0[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | LEVELDETECT0[n] | R/W | 0h | Low Level Interrupt Enable<br>0h = Disable the IRQ assertion on low-level detect.<br>1h = Enable the IRQ assertion on low-level detect. |

---

### 25.4.1.20 GPIO_LEVELDETECT1 Register (offset = 144h) [reset = 0h]

**Description:**
The GPIO_LEVELDETECT1 register is used to enable/disable for each input lines the high-level (1) detection to be used for the interrupt request generation. Enabling at the same time high-level detection and low-level detection for one given pin makes a constant interrupt.

**Register Diagram:**
```
[31:0]  LEVELDETECT1[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | LEVELDETECT1[n] | R/W | 0h | High Level Interrupt Enable<br>0h = Disable the IRQ assertion on high-level detect.<br>1h = Enable the IRQ assertion on high-level detect. |

---

### 25.4.1.21 GPIO_RISINGDETECT Register (offset = 148h) [reset = 0h]

**Description:**
The GPIO_RISINGDETECT register is used to enable/disable for each input lines the rising edge detection to be used for the interrupt request generation.

**Register Diagram:**
```
[31:0]  RISINGDETECT[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | RISINGDETECT[n] | R/W | 0h | Rising Edge Interrupt Enable<br>0h = Disable the IRQ assertion on rising edge detect.<br>1h = Enable the IRQ assertion on rising edge detect. |

---

### 25.4.1.22 GPIO_FALLINGDETECT Register (offset = 14Ch) [reset = 0h]

**Description:**
The GPIO_FALLINGDETECT register is used to enable/disable for each input lines the falling edge detection to be used for the interrupt request generation.

**Register Diagram:**
```
[31:0]  FALLINGDETECT[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | FALLINGDETECT[n] | R/W | 0h | Falling Edge Interrupt Enable<br>0h = Disable the IRQ assertion on falling edge detect.<br>1h = Enable the IRQ assertion on falling edge detect. |

---

### 25.4.1.23 GPIO_DEBOUNCENABLE Register (offset = 150h) [reset = 0h]

**Description:**
The GPIO_DEBOUNCENABLE register is used to enable/disable the debouncing feature for each input line.

**Register Diagram:**
```
[31:0]  DEBOUNCEENABLE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | DEBOUNCEENABLE[n] | R/W | 0h | Debounce Enable<br>0h = Debouncing cell is inactive (direct input to the module).<br>1h = Debouncing cell is active for the input line. |

---

### 25.4.1.24 GPIO_DEBOUNCINGTIME Register (offset = 154h) [reset = 0h]

**Description:**
The GPIO_DEBOUNCINGTIME register is used to set the debouncing time for all input lines. The debouncing cell is running with the debouncing clock (32 kHz). This register represents the number of clock cycles to be used.

**Debouncing Time Formula:**
```
Debouncing time = (DEBOUNCETIME + 1) × 31 µs
```

**Register Diagram:**
```
[31:8]  RESERVED
[7:0]   DEBOUNCETIME
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-8 | RESERVED | R | 0h | Reserved |
| 7-0 | DEBOUNCETIME | R/W | 0h | Debouncing time value (0-255).<br>The debouncing time is calculated as (DEBOUNCETIME + 1) × 31 µs.<br>Example: DEBOUNCETIME = 0 → 31 µs<br>Example: DEBOUNCETIME = 255 → 7.936 ms |

---

### 25.4.1.25 GPIO_CLEARDATAOUT Register (offset = 190h) [reset = 0h]

**Description:**
The GPIO_CLEARDATAOUT register is used for clearing specific bits in the GPIO_DATAOUT register. This register implements the alternate access protocol (Set & Clear protocol) to clear bits in the data output register. Writing a 1 to a bit clears the corresponding bit in GPIO_DATAOUT. Writing a 0 has no effect.

**Register Diagram:**
```
[31:0]  INTLINE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE[n] | R/W | 0h | Clear Data Output<br>0h (W) = No effect on GPIO_DATAOUT register.<br>1h (W) = Clear corresponding bit in GPIO_DATAOUT register.<br>Read returns the value of GPIO_DATAOUT register. |

---

### 25.4.1.26 GPIO_SETDATAOUT Register (offset = 194h) [reset = 0h]

**Description:**
The GPIO_SETDATAOUT register is used for setting specific bits in the GPIO_DATAOUT register. This register implements the alternate access protocol (Set & Clear protocol) to set bits in the data output register. Writing a 1 to a bit sets the corresponding bit in GPIO_DATAOUT. Writing a 0 has no effect.

**Register Diagram:**
```
[31:0]  INTLINE[n]
```

**Field Descriptions:**

| Bit | Field | Type | Reset | Description |
|-----|-------|------|-------|-------------|
| 31-0 | INTLINE[n] | R/W | 0h | Set Data Output<br>0h (W) = No effect on GPIO_DATAOUT register.<br>1h (W) = Set corresponding bit in GPIO_DATAOUT register.<br>Read returns the value of GPIO_DATAOUT register. |

---

## Tóm tắt các điểm quan trọng

### Cấu hình GPIO
- 4 module GPIO, mỗi module 32 pin → Tổng 128 GPIO pins
- GPIO0 hỗ trợ wake-up, nằm trong Wakeup domain
- GPIO1-3 nằm trong Peripheral domain

### Các chế độ hoạt động
- **Active Mode**: Module hoạt động bình thường, có thể tạo interrupt
- **Idle Mode**: Chờ wake-up event, có thể tắt interface clock
- **Inactive Mode**: Không hoạt động, không có interrupt/wake-up
- **Disabled Mode**: Clock bị gate, không có hoạt động nào

### Tính năng chính
- ✅ Input/Output data
- ✅ Keyboard interface với debounce
- ✅ Interrupt generation (2 interrupt lines cho bi-processor)
- ✅ Wake-up generation (chỉ GPIO0)
- ✅ Debouncing với công thức: `(DEBOUNCETIME + 1) × 31 µs`
- ✅ Set/Clear protocol cho concurrent access

### Clock
- **Interface clock**: OCP bus clock cho toàn bộ module
- **Debouncing clock**: 32 kHz clock cho debounce logic

### Registers quan trọng

#### Configuration Registers
- `GPIO_REVISION` (0h): Revision information (read-only)
- `GPIO_SYSCONFIG` (10h): System configuration (IDLEMODE, ENAWAKEUP, SOFTRESET, AUTOIDLE)
- `GPIO_SYSSTATUS` (114h): System status (RESETDONE)
- `GPIO_CTRL` (130h): Clock gating control (GATINGRATIO, DISABLEMODULE)

#### Data Registers
- `GPIO_OE` (134h): Output Enable (0=output, 1=input) - Reset: FFFFFFFFh
- `GPIO_DATAIN` (138h): Read input data (read-only)
- `GPIO_DATAOUT` (13Ch): Write output data
- `GPIO_SETDATAOUT` (194h): Set specific bits (alternate access)
- `GPIO_CLEARDATAOUT` (190h): Clear specific bits (alternate access)

#### Interrupt Registers
- `GPIO_IRQSTATUS_RAW_0/1` (24h/28h): Raw interrupt status (all events)
- `GPIO_IRQSTATUS_0/1` (2Ch/30h): Interrupt status (enabled events only)
- `GPIO_IRQSTATUS_SET_0/1` (34h/38h): Enable interrupt
- `GPIO_IRQSTATUS_CLR_0/1` (3Ch/40h): Disable interrupt
- `GPIO_IRQWAKEN_0/1` (44h/48h): Wake-up enable

#### Detection Registers
- `GPIO_LEVELDETECT0` (140h): Low-level (0) detection enable
- `GPIO_LEVELDETECT1` (144h): High-level (1) detection enable
- `GPIO_RISINGDETECT` (148h): Rising edge detection enable
- `GPIO_FALLINGDETECT` (14Ch): Falling edge detection enable
- `GPIO_DEBOUNCENABLE` (150h): Debounce enable per pin
- `GPIO_DEBOUNCINGTIME` (154h): Debounce time (0-255, global for module)

#### DMA Support
- `GPIO_EOI` (20h): End of Interrupt for DMA event acknowledgment

---

## GPIO Module Base Addresses

| Module | Base Address | Domain | Wake-up Support |
|--------|-------------|--------|-----------------|
| GPIO0 | 0x44E07000 | Wakeup | Yes |
| GPIO1 | 0x4804C000 | Peripheral | No |
| GPIO2 | 0x481AC000 | Peripheral | No |
| GPIO3 | 0x481AE000 | Peripheral | No |

---

## Important Notes

1. **Reset State**: All GPIO pins default to INPUT mode (GPIO_OE = FFFFFFFFh)

2. **Interrupt Lines**: Each GPIO module has 2 interrupt lines (INTLINE_0 and INTLINE_1) for bi-processor operation

3. **Wake-up**: Only GPIO0 supports wake-up functionality

4. **Debounce Clock**: 32 kHz clock → Each tick = 31 µs

5. **Data Latency**: 
   - With AUTOIDLE=0: GPIO_DATAIN read has 2 OCP cycle latency
   - With AUTOIDLE=1: GPIO_DATAIN read has 3 OCP cycle latency

6. **Set/Clear Protocol**: Use GPIO_SETDATAOUT and GPIO_CLEARDATAOUT for atomic bit operations without read-modify-write

7. **Interrupt Clearing**: Write 1 to clear interrupt status (W1C - Write 1 to Clear)

8. **Module Disable**: Set DISABLEMODULE bit in GPIO_CTRL to gate all clocks when module not needed

9. **Smart-Idle**: GPIO can automatically enter idle mode when no activity, but only if no pending interrupts

10. **Concurrent Access**: Multiple processors can safely access same GPIO module using Set/Clear protocol

# Chapter 26: ROM Code

## 26.1 Functional Description

This chapter describes the booting functionality of the device, referred to hereafter as **ROM Code**. The booting functionality covers the following features:

- **Memory Booting**: Booting the device by starting code stored on permanent memories like flash-memory or memory cards. This process is totally autonomous and can be done on device cold or warm reset.

- **Peripheral Booting**: Booting the device by downloading the executable code over a communication interface like UART, USB or Ethernet. This process is needed for flashing a device.

The device always starts up in secure mode. The ROM Code takes care of early initialization. The ROM code switches the device into public mode. Hence the Public ROM Code provides run-time services for cache maintenance.

---

## 26.1.1 Device Types

This device has two types of production devices: a high-secure (HS) device and a general-purpose (GP) device. The fundamental difference between the two types of production devices is the method to secure booting. The HS Device doesn't allow booting code which is not trusted (authenticated), that is digitally signed and checked for its integrity. The GP Device doesn't support such security features disabled and does not require signed code for booting the device. Image formats are different depending on the device type and described in this chapter.

---

## 26.1.2 Architecture

The architecture of the Public ROM Code is shown in the diagram below. It is split into three main layers with a top-down approach: high-level, drivers, and hardware abstraction layer (HAL). One layer communicates with a lower level layer through a unified interface.

**Architecture Layers:**

- **High-level layer**: In charge of the main tasks of the Public ROM Code: watchdog and clocks configuration and main booting routine.

- **Drivers layer**: Implements the logical and communication protocols for any booting device in accordance with the interface specification.

- **HAL (Hardware Abstraction Layer)**: Implements the lowest level code for interacting with the hardware infrastructure IPs. End booting devices are attached to device IO pads.

*[Sơ đồ Figure 26-1: Public ROM Code Architecture - Quan trọng - Giữ lại]*

```
┌─────────────────────────────────────────────────────────────────┐
│                            HLOS                                  │
└─────────────────────────────────────────────────────────────────┘
┌─────────────────────────────────────────────────────────────────┐
│                    Public ROM Code (High Level)                  │
│  ┌──────┐  ┌────────┐  ┌──────────┐  ┌─────┐                   │
│  │ MAIN │  │CLOCKS  │  │ BOOTING  │  │ DFT │                    │
│  └──────┘  └────────┘  └──────────┘  └─────┘                    │
│  ┌──────┐  ┌────────┐  ┌──────┐  ┌─────┐  ┌──────┐  ┌──────┐  │
│  │RNDIS │  │SYSTEM  │  │SWCFG │  │ FAT │  │XMODEM│  │BOOTP │  │TFTP │
│  └──────┘  └────────┘  └──────┘  └─────┘  └──────┘  └──────┘  └──────┘
├─────────────────────────────────────────────────────────────────┤
│                    Public ROM Code drivers                       │
│  ┌──────┐  ┌──────┐  ┌─────┐  ┌─────┐  ┌─────┐  ┌──────┐      │
│  │ EMAC │  │ UART │  │ USB │  │ SPI │  │ XIP │  │ NAND │  │eMMCSD│
│  └──────┘  └──────┘  └─────┘  └─────┘  └─────┘  └──────┘  └──────┘
├─────────────────────────────────────────────────────────────────┤
│                     Public ROM Code HAL                          │
│  ┌─────┐  ┌──────────┐  ┌─────┐  ┌────────┐  ┌─────────┐       │
│  │ USB │  │DMTIMERTMS│  │ ELM │  │WDTIMER │  │CONTROL  │  │PRM │  │CM │
│  └─────┘  └──────────┘  └─────┘  └────────┘  └─────────┘  └───┘ └───┘
│  ┌──────┐  ┌──────┐  ┌─────┐  ┌─────┐  ┌──────┐  ┌──────┐      │
│  │MMCHS │  │ GPMC │  │ SPI │  │ I2C │  │CKGEN │  │ UART │       │
│  └──────┘  └──────┘  └─────┘  └─────┘  └──────┘  └──────┘       │
└─────────────────────────────────────────────────────────────────┘
┌─────────────────────────────────────────────────────────────────┐
│                            HW                                    │
│  ┌────────┐  ┌──────────┐  ┌────────┐  ┌─────┐  ┌──────┐       │
│  │MMC+SD  │  │NAND flash│  │SPI flash│  │ XIP │  │ UART │  │EMAC│
│  │cards   │  │          │  │         │  │     │  │      │  │    │
│  └────────┘  └──────────┘  └────────┘  └─────┘  └──────┘  └────┘
│             ┌──────┐                                              │
│             │ USB  │                                              │
│             └──────┘                                              │
└─────────────────────────────────────────────────────────────────┘
```

---

## 26.1.3 Functionality

The booting procedure is illustrated in the high level flow diagrams below. On this device the Public ROM Code starts upon completion of the secure startup (performed by the Secure ROM Code). The Public ROM Code performs early initialization as part of the public start-up procedure.

The booting device list is created based on the **SYSBOOT** pins. A booting device can be a **memory booting device** (soldered flash memory or temporarily booting device like memory card) or a **peripheral interface** connected to a host.

The main loop of the booting procedure goes through the booting device list and tries to search for an image from the currently selected image device. This loop is exited if a valid booting image is found and successfully executed or upon watchdog expiration.

The image authentication procedure is performed prior to image execution on an **HS Device**. Failure in authentication procedure leads to branching to a "dead loop" for a secure device (generates a watchdog reset).

*[Sơ đồ Figure 26-2 và 26-3: Public ROM Code Boot Procedure - Quan trọng - Giữ lại]*

**Figure 26-2: ROM Code Boot Procedure (Simplified)**

```
System start-up
      │
      ▼
Set up the booting device list
      │
      ▼
Take next device from the list
      │
      ▼
  ┌─────────────┐
  │  Memory     │ Yes → Memory Booting
  │  Device?    │
  └─────────────┘
       │ No
       ▼
   Peripheral Booting
       │
       ▼
   ┌──────────┐
   │ Success? │ Yes → Image execution
   └──────────┘
       │ No
       │
       ▼ (Loop back to next device)
```

**Figure 26-3: ROM Code Boot Procedure (Detailed - HS Device)**

```
System start-up
      │
      ▼
Set up the booting device list
      │
      ▼
Take next device from the list
      │
      ▼
  ┌─────────────┐
  │  Memory     │ Yes → Memory Booting
  │  Device?    │
  └─────────────┘
       │ No
       ▼
   Peripheral Booting
       │
       ▼
   ┌──────────┐
   │ Success? │ No → Get next device
   └──────────┘
       │ Yes
       ▼
   ┌─────────────┐
   │ HS Device?  │ No → Image execution
   └─────────────┘
       │ Yes
       ▼
   Image authentication
       │
       ▼
   ┌──────────────────┐
   │ Authentication   │ No → Dead loop (watchdog reset)
   │ successful?      │
   └──────────────────┘
       │ Yes
       ▼
   Image execution
```

---

## 26.1.4 Memory Map

### 26.1.4.1 Public ROM Memory Map

The on-chip ROM memory map is shown in the figures below. The bottom part of the physical ROM contains the Secure ROM Code. The upper part holds the Public ROM Code. The Public ROM Code mapping consists in the following:

- Exception vectors
- CRC
- Dead loops collection
- Code and const data sections
- ROM Version

*[Sơ đồ Figure 26-4 và 26-5: ROM Memory Map - Quan trọng - Giữ lại]*

**Figure 26-4: ROM Memory Map (Physical)**

```
0x2BFFF ┌─────────────────┐
        │  ROM Version    │
0x2BFFC └─────────────────┘
        │                 │
        │      Code       │
        │                 │
0x20100 ├─────────────────┤
        │  Dead loops     │
0x20080 ├─────────────────┤
0x20020 │ Public ROM CRC  │
        ├─────────────────┤
0x20000 │ ROM Exc. Vectors│
        └─────────────────┘
```

**Figure 26-5: ROM Memory Map (Logical - GP/HS)**

```
        ┌─────────────────┐ 0x2BFFF
        │  ROM Version    │
        │                 │ 0x2BFFC
        ├─────────────────┤
        │                 │
        │      Code       │
        │                 │
        │                 │ 0x20100
        ├─────────────────┤
        │  Dead loops     │ 0x20080
        ├─────────────────┤
        │ Public ROM CRC  │ 0x20020
        ├─────────────────┤
Public  │ ROM Exc. Vectors│ 0x20000
ROM     └─────────────────┘
48KB            ╲
                 ╲ Secure ROM
0x20000          ╲ 128KB
                  ╲
                   ╲
                    ╲
0x00000 ────────────────────
```

---

### Public ROM Exception Vectors

Exception vectors table lists the Public ROM exception vectors. The reset exception is redirected to the Public ROM Code startup. Other exceptions are redirected to their RAM handlers by loading appropriate addresses into the PC register.

**Table 26-1: ROM Exception Vectors**

| Address | Exception | Content |
|---------|-----------|---------|
| 20000h | Reset | Branch to the Public ROM Code startup |
| 20004h | Undefined | PC = 4030CE04h |
| 20008h | SWI | PC = 4030CE08h |
| 2000Ch | Pre-fetch abort | PC = 4030CE0Ch |
| 20010h | Data abort | PC = 4030CE10h |
| 20014h | Unused | PC = 4030CE14h |
| 20018h | IRQ | PC = 4030CE18h |
| 2001Ch | FIQ | PC = 4030CE1Ch |

---

### Public ROM Code CRC

The Public ROM Code CRC is calculated as 32 bit CRC code (CRC-32 IEEE 802.3) for the address range 20000h-2BFFFh. The four bytes CRC code is stored at location 20020h.

---

### Dead Loops

Built-in dead loops are used for different purposes as shown in the table below. All dead loops are branch instructions coded in ARM mode. The list below lists typical uses of these dead loops which can be called from ROM Code in order to execute a dead loop. The function is an assembly code in ARM mode which takes the dead loop address as first register parameter. However there exists a special case which can be called directly from the ROM Code, but can only be used on a GP device. For an HS device, the function must first call the requested dead loop. The function is located at address 2000Ch. In addition the function clears global cold reset status upon issuing the global SW reset.

**Table 26-2: Dead Loops**

| Address | Purpose |
|---------|---------|
| 20080h | Undefined exception default handler |
| 20084h | SWI exception default handler |
| 20088h | Pre-fetch abort exception default handler |
| 2008Ch | Data abort exception default handler |
| 20090h | Unused exception default handler |
| 20094h | IRQ exception default handler |
| 20098h | FIQ exception default handler |
| 2009Ch | Validation tests PASS |
| 200A0h | Validation tests FAIL |
| 200A4h | Reserved |
| 200A8h | Image not executed or returned |
| 200ACh | Reserved |
| 200B0h | Reserved |
| 200B4h | Reserved |
| 200B8h | Reserved |
| 200BCh | Reserved |

---

### Code

This space is used to hold code and constant data.

---

### Public ROM Code Version

The ROM Code version consists of two decimal numbers: major and minor. It can be used to identify the ROM Code release version in a given IC version. The ROM Code version is stored at address 2BFCh as a 32bits hexadecimal value located at address 2BFFCh.

---

## 26.1.4.2 Public RAM Memory Map

The Public ROM Code makes use of the on chip RAM module connected to the L3 interconnect (further referred to as **L3 RAM**). Its usage is shown in the figures below. The Public RAM memory map ranges from address 402F0400h to 4030FFFFh on a **GP Device**.

*[Sơ đồ Figure 26-6 và 26-7: Public RAM Memory Map - Có thể đơn giản hóa]*

**Public RAM Memory Layout (GP Device):**

```
0x4030FFFF ┌─────────────────────────┐
           │ Static Variables        │
           │ Tracing Data            │
0x4030CE00 │ RAM Exc. Vectors        │
           ├─────────────────────────┤
           │ 8KB Public stack        │
0x4030B800 ├─────────────────────────┤
           │                         │
           │                         │
           │   Downloaded Image      │
           │                         │
           │                         │
0x402F0400 └─────────────────────────┘
(GP)       0x402F0400

HS Device: Reserved area 0x4030F000 to 0x4030008900
```

---

### Download Image

This area is used by the Public ROM Code to store the downloaded boot image. It can be up to 109KB on the GP Device and 46KB for the HS device.

---

### Public Stack

Space reserved for stack.

---

### RAM Exception Vectors

The RAM exception vectors enable a simple means for redirecting exceptions to custom handlers. The table shows the addresses reserved for RAM exception vectors. The six exception handlers are relocated in RAM as a consecutive list of branch instructions in ARM mode. These instructions are executed when an exception occurs since they are called from the ROM exception vectors. Undefined, SWI, Unused and FIQ exceptions are redirected to a hardcoded dead loop. Pre-fetch abort, data abort, and IRQ exception are redirected to pre-defined ROM handlers. User code can redirect any exception to a custom handler either by writing its address to the appropriate location from 4030CE04h to 4030CE1Ch or by overriding the branch (load into PC) instruction between addresses from 4030CE04h to 4030CE1Ch.

**Table 26-3: RAM Exception Vectors**

| Address | Exception | Content |
|---------|-----------|---------|
| 4030CE00h | Reserved | Reserved |
| 4030CE04h | Undefined | PC = [4030CE24h] |
| 4030CE08h | SWI | PC = [4030CE28h] |
| 4030CE0Ch | Pre-fetch abort | PC = [4030CE2Ch] |
| 4030CE10h | Data abort | PC = [4030CE30h] |
| 4030CE14h | Unused | PC = [4030CE34h] |
| 4030CE18h | IRQ | PC = [4030CE38h] |
| 4030CE1Ch | FIQ | PC = [4030CE3Ch] |
| 4030CE20h | Reserved | 20090h |
| 4030CE24h | Undefined | 20080h |
| 4030CE28h | SWI | 20084h |
| 4030CE2Ch | Pre-fetch abort | Address of default pre-fetch abort handler |
| 4030CE30h | Data abort | Address of default data abort handler |
| 4030CE34h | Unused | 20090h |
| 4030CE38h | IRQ | Address of default IRQ handler |
| 4030CE3Ch | FIQ | 20098h |

**Note:** 
- The default handlers for pre-fetch and data abort are performing reads from CP15 debug registers to retrieve the reason of the abort.
- In case of pre-fetch abort, the IFAR register is read and stored into the R1 register. Then the ROM Code jumps to the pre-fetch abort dead loop (20088h)
- In case of data abort, the DFAR register is read from CP15 and stored into R0. The DFSR register is read and stored into the R1 register. Then the ROM Code jumps to the data abort dead loop (2008Ch)

---

### Tracing Data

This area contains trace vectors reflecting the execution path of the public boot. The section describes the usage of the different trace vectors and lists all the possible trace codes.

**Table 26-4: Tracing Data**

| Address | Size[bytes] | Description |
|---------|-------------|-------------|
| 4030CE40h | 4 | Current tracing vector, word 1 |
| 4030CE44h | 4 | Current tracing vector, word 2 |
| 4030CE48h | 4 | Current tracing vector, word 3 |
| 4030CE4Ch | 4 | Current copy of the PRM_RSTST register (reset reasons) |
| 4030CE50h | 4 | Cold reset run tracing vector, word 1 |
| 4030CE54h | 4 | Cold reset run tracing vector, word 2 |
| 4030CE58h | 4 | Cold reset run tracing vector, word 3 |
| 4030CE5Ch | 4 | Reserved |
| 4030CE60h | 4 | Reserved |
| 4030CE64h | 4 | Reserved |

---

### Static Variables

This area holds the ROM Code static variables used during boot time.

---

## 26.1.5 Start-up and Configuration

### 26.1.5.1 ROM Code Start-up

On this device the main MPU subsystem always starts its execution in secure mode after reset due to the **TrustZone architecture** (the Secure ROM Code implements the reset handler).

The Public ROM Code is physically located at the address 20000h that is immediately next to the Secure ROM Code.

*[Sơ đồ Figure 26-8: ROM Code Startup Sequence - Quan trọng - Đơn giản hóa]*

**ROM Code Startup Sequence (Simplified):**

```
System start-up
      ↓
Initialization
      ↓
__main() (stack setup)
      ↓
main()
      ↓
MPU WDT1 setup
      ↓
DPLLs and clocks configurations
      ↓
Booting
```

*[Sơ đồ Figure 26-9: ROM Code Startup Sequence (Detailed) - Bỏ qua, đã có phiên bản đơn giản]*

As shown at top of Figure 26-8, the CPU jumps to the Public ROM Code reset vector once it has completed the secure-side initialization.

Once in public mode, Upon system startup, the CPU performs the public-side initialization and stack setup (complete auto generated C- initialization or "scatter loading"). Then it configures the watchdog WDT1 (set to three minutes), performs system clocks configuration. Finally it jumps to the booting routine.

---

### 26.1.5.2 CPU State at Public Startup

The CPU **L1 instruction cache** and **branch prediction** mechanisms are not activated as part of the Secure ROM Code initialization. The data base address is configured to the reset vector of Public ROM Code (20000h). MMU is left switched off during the public boot (hence L1 data cache off).

---

### 26.1.5.3 Clocking Configuration

The device supports the following frequencies based on SYSBOOT[15:14]

**Table 26-5: Crystal Frequencies Supported**

| SYSBOOT[15:14] | Crystal Frequency |
|----------------|-------------------|
| 00b | 19.2 MHz |
| 01b | 24 MHz |
| 10b | 25 MHz |
| 11b | 26 MHz |

The ROM Code configures the clocks and DPLLs which are necessary for ROM Code execution:

- L3 ADPLLS locked to provide 200MHz clocks for peripheral blocks.
- MPU ADPLLS is locked to provide 500 MHz for the A8.
- PER ADPLLL1 is locked to provide 960MHz and 192MHz for peripheral blocks.

The table below summarizes the ROM Code default settings for clocks. This default configuration enables all the ROM Code functionalities with minimized needs on power during boot.

**Table 26-6: ROM Code Default Clock Settings**

| Clock | Frequency [MHz] | Source |
|-------|----------------|--------|
| L3F_CLK | 200 | CORE_CLKOUTM4 |
| SPI_CLK | 48 | PER_CLKOUTM2 |
| MMC_CLK | 96 | PER_CLKOUTM2 |
| UART_CLK | 48 | PER_CLKOUTM2 |
| I2C_CLK | 48 | PER_CLKOUTM2 |
| MPU_CLK | 500 | MPU_PLL |
| USB_PHY_CLK | 960 MHz | PER_CLKDCOLDO |

The DPLLs and GPMC clock dividers are configured with the ROM Code default values after cold or warm reset in order to give the same working conditions to the Public ROM Code sequence.

---

## 26.1.6 Booting

### 26.1.6.1 Overview

The boot procedure shows the booting procedure. First a **booting device list** is created. The list consists of all devices which will be searched for a booting image. The list is filled in based on the **SYSBOOT** pins.

*[Sơ đồ Figure 26-10: ROM Code Booting Procedure - Quan trọng - Đã có ở trên, bỏ qua]*

Once the booting device list is set up, the booting routine examines the devices enumerated in the list sequentially and either executes booting from memory or peripheral booting depending on the selected booting device type. The memory booting procedure is executed when the booting device type is one of NOR, NAND, MMC or SPI-EEPROM. The peripheral booting is executed when the booting device type is Ethernet, USB or UART.

The memory booting procedure reads data from a memory type device. If a valid booting image is found and successfully loaded into internal memory, the code begins to execute.

- If the device is an HS device then the image is authenticated and Initial SW started upon successful authentication
- If the device is a GP device the Initial SW is simply started (no authentication involved).

The peripheral booting procedure downloads data from a host (commonly a PC) to the device device by means of Ethernet, USB or UART links. The ROM Code uses a host-slave protocol for the synchronization. Upon successful UART, USB or Ethernet connection the host sends the image binary contents. The peripheral booting procedure is detailed in Section 26.1.9.

If the memory or peripheral booting fails for all devices enumerated in the device list then the ROM Code gets into a loop, waiting for the watchdog to reset the system.

---

### 26.1.6.2 Device List

The ROM Code creates the **device list** based on information gathered from the **SYSBOOT configuration pins** sensed in the control module. The pins are used to index the device table from which the list of devices is extracted

#### 26.1.6.2.1 SYSBOOT Configuration Pins

Table 26-7 contains the SYSBOOT configuration pins.

**Table 26-7: SYSBOOT Configuration Pins (Summary)**

| SYSBOOT Bits | Function |
|--------------|----------|
| SYSBOOT[15:14] | Crystal Frequency (19.2/24/25/26 MHz) |
| SYSBOOT[13:12] | Set to 00b for normal operation |
| SYSBOOT[11:10] | For XIP/NAND boot: Mixed/non-mixed device<br>For NAND boot: must be 00b |
| SYSBOOT[9] | For NAND/NAND I2C: ECC handling by ROM/NAND<br>For Fast External Boot: must be 0b |
| SYSBOOT[8] | Device type (8-bit/16-bit) |
| SYSBOOT[7:6] | For EMAC boot: PHY mode |
| SYSBOOT[5] | CLKOUT1 settings |
| SYSBOOT[4:0] | Boot Sequence selection |

*[Bảng chi tiết Table 26-7 đầy đủ từ các hình ảnh - Rất quan trọng - Giữ nguyên nhưng format lại cho gọn]*

**Detailed SYSBOOT Configuration (Selected Rows):**

| SYSBOOT[15:14] | [13:12] | [11:10] | [9] | [8] | [7:6] | [5] | [4:0] | Boot Sequence |
|----------------|---------|---------|-----|-----|-------|-----|-------|---------------|
| **Crystal Freq** | **Operation** | **XIP/NAND** | **ECC** | **Width** | **PHY** | **CLK** | **Seq** | **1st→2nd→3rd→4th** |
| 00b=19.2MHz | 00b | For XIP: 00b=non-mixed | Don't care | 0=8-bit | Don't care | 0=CLKOUT1 disabled | 00001b | UART0 → XIP(MUX1)[2] → MMC0 → SPI0 |
| 01b=24MHz | (all values reserved) | device | for ROM code | device | for ROM code | 1=CLKOUT1 enabled | | |
| 10b=25MHz | | 0xb=mixed dev | | 1=16-bit | | | | |
| 11b=26MHz | | x1b=reserved | | | | | | |

**Common Boot Sequences (from full table):**

- **00001b**: UART0 → XIP(MUX1)[2] → MMC0 → SPI0
- **00010b**: UART0 → XIP w/ WAIT[1] (MUX1)[2] → MMC0 → SPI0
- **00100b**: UART0 → SPI0 → XIP(MUX2)[2] → NAND I2C
- **00110b**: EMAC1 → SPI0 → NAND → NAND I2C
- **01000b**: EMAC1 → MMC0 → XIP(MUX2)[2] → NAND
- **01010b**: EMAC1 → MMC0 → NAND I2C → USB0
- **10000b**: XIP(MUX1)[2] → UART0 → EMAC1 → MMC0
- **10001b**: XIP w/ WAIT[1] (MUX1)[2] → UART0 → EMAC1 → MMC0
- **10010b**: NAND → NAND I2C → USB0 → UART0
- **10011b**: NAND → NAND I2C → MMC0 → UART0
- **10100b**: NAND → NAND12 → SPI0 → EMAC1
- **10101b**: NAND I2C → MMC0 → EMAC1 → UART0
- **11000b**: USB0 → NAND → SPI0 → MMC0
- **11011b**: Fast External Boot → EMAC1 → UART0 → Reserved

**SYSBOOT Configuration Pins Notes:**

1. WAIT is monitored on GPMC_WAIT0.
2. MUX1 and MUX2 designate which group of XIP signals are used. Each group is defined in Table 26-9.
3. Note that even though some bits may be a "don't care" for ROM code, all SYSBOOT values are latched into the CONTROL_STATUS register and may be used by software after ROM execution has completed.
4. SYSBOOT[15:0] terminals are respectively LCD_DATA[15:0] inputs, latched on the rising edge of PWRONRSTn.

---

### 26.1.6.2.2 Device List Decoding

The ROM Code uses the row pointed by the SYSBOOT pins value. The device list is filled in with the 1st to 4th devices.

Table 26-7 is the decoding table for SYSBOOT pin configuration. The following shortcuts are used in the table:

- **MMC1**: MMC or SD card (MMC port 1)
- **MMC0**: MMC or SD card (MMC port 0)
- **NAND / NAND I2C**: NAND flash memory / read geometry from EEPROM on I2C0
- **XIP**: NOR or other XIP device without wait monitoring
- **XIP w/ WAIT**: NOR or other XIP device with wait monitoring
- **NAND / MUX**: Boot with XIP_MUX1 signals detailed in Table 26-9
- **MUX2**: Boot with XIP_MUX2 signals detailed in Table 26-9
- **UART0**: UART interface (UART port 0)
- **EMAC1**: Ethernet interface (EMAC port 1)
- **SPI0**: SPI EEPROM (SPI 0, CS0)
- **USB0**: USB interface (USB0)

**Note:** For any SYSBOOT value that is selected, please be aware of the pin muxing implications. For example, if the boot mode selected is EMAC1, NAND, SPI0, NAND I2C, the device will drive EMAC, GPMC, and I2C pins depending on whether the boot device finally succeeds or not. So if a specific boot mode in the sequence chosen is not used then the components using those particular signals that are not mapped to external components are not in contention with the ROM (using these signals). For specific details of the pins driven by each device, please refer the description of that boot device later in this chapter.

To extend the boot flow to boot from devices that are not natively supported by the ROM, SPI boot can be used. Using SPI, the table can be stored in an SPI stick, the system can be configured to boot from a SPI flash, and the code for configuring the USB and booting from a USB stick can be loaded into the SPI flash. This is known as a secondary boot.

The values corresponding to SYSBOOT[4:0]= x1111 provide a bypass mode booting feature.

The fast external boot feature consists of minimal execution by the ROM Code for configuring the GPMC interface and then directly jump to the code contained in the connected external XIP device connected to CS0.

---

## 26.1.7 Fast External Booting

### 26.1.7.1 Overview

The Fast External boot feature:

- Consists of a blind jump in ARM mode to address 0x08000000 in an external XIP device connected to CS0
- The jump is performed with minimum on-chip ROM Code execution (only configures GPMC interface), without configuring any PLL
- Allows the customer to create its own booting code
- Is set up by means of the configuration pins, see Table 26-7.
- Addr/Data muxed device or a non-muxed (selected using SYSBOOT[11:10]) device in connected in XIP_MUX2 configuration
- Bus width selected by SYSBOOT[8]
- CS0 chip select
- No wait monitoring is available

---

## Summary

### Các điểm quan trọng về ROM Code

#### Device Types
- **HS Device**: High-Secure device - requires authenticated (digitally signed) boot code
- **GP Device**: General-Purpose device - no authentication required

#### Boot Sources
The device can boot from:
- **Memory devices**: NOR, NAND, MMC/SD, SPI-EEPROM
- **Peripheral interfaces**: UART, USB, Ethernet (EMAC)
- **XIP devices**: eXecute In Place devices (NOR flash)

#### Boot Process Flow
1. System starts in Secure Mode (Secure ROM Code)
2. Jump to Public ROM Code (address 20000h)
3. Public ROM initialization
4. Create booting device list based on SYSBOOT pins
5. Try each device in list sequentially
6. For HS devices: authenticate image before execution
7. Execute valid image or watchdog reset on failure

#### Memory Map
- **Public ROM**: 0x20000 - 0x2BFFF (48KB on GP, less on HS due to Secure ROM)
- **Public RAM**: 0x402F0400 - 0x4030FFFF
  - Download Image area: up to 109KB (GP) or 46KB (HS)
  - Stack: 8KB
  - Exception vectors: 0x4030CE00 - 0x4030CE3F
  - Tracing data and static variables

#### Clock Configuration
Default clocks configured by ROM Code:
- L3F_CLK: 200 MHz
- MPU_CLK: 500 MHz
- SPI_CLK: 48 MHz
- MMC_CLK: 96 MHz
- UART_CLK: 48 MHz
- I2C_CLK: 48 MHz
- USB_PHY_CLK: 960 MHz

#### SYSBOOT Pins
- **[15:14]**: Crystal frequency (19.2/24/25/26 MHz)
- **[13:12]**: Must be 00b for normal operation
- **[11:10]**: XIP/NAND device configuration
- **[9]**: ECC handling selection
- **[8]**: Bus width (8-bit or 16-bit)
- **[7:6]**: EMAC PHY mode
- **[5]**: CLKOUT1 enable/disable
- **[4:0]**: Boot sequence selection (32 possible sequences)

#### Boot Sequence
ROM Code tries up to 4 devices per boot sequence, configured by SYSBOOT[4:0]. Common sequences include:
- UART → XIP → MMC → SPI
- NAND → MMC → USB → UART
- EMAC → NAND → SPI → MMC

#### Fast External Boot
- Minimal ROM execution
- Direct jump to 0x08000000
- GPMC interface only
- No PLL configuration
- Controlled by SYSBOOT configuration

#### Exception Handling
ROM provides:
- Exception vectors at 0x20000
- RAM exception handlers at 0x4030CE00
- Dead loops for undefined exceptions
- Custom handler support via RAM vectors

#### Security Features (HS Device)
- Image authentication required
- Digital signature verification
- Failed authentication → dead loop → watchdog reset
- TrustZone architecture support
---

## 26.1.7.2 External Booting

Figure 26-11 shows the Fast External Boot procedure. The code does not make use of RAM and is designed for fast execution.

**Figure 26-11: Fast External Boot Procedure**

```
Fast External Boot
       │
       ▼
   ┌─────────────┐
   │ GP Device?  │ No → (Normal boot)
   └─────────────┘
       │ Yes
       ▼
   ┌──────────────────────┐
   │Configuration pins     │ No → (Normal boot)
   │indicate fast          │
   │external boot?         │
   └──────────────────────┘
       │ Yes
       ▼
   Configure and enable GPMC
       │
       ▼
   Jump to address 0x08000000 in ARM mode
       │
       ▼
   Jump to external SW
```

---

## 26.1.8 Memory Booting

### 26.1.8.1 Overview

The memory booting procedure takes care of starting an external code located in memory device types.

**Figure 26-12 & 26-13: Memory Booting Flow**

*Simple Flow:*
```
Memory Booting
      │
      ▼
  ┌─────────────┐
  │Device is XIP│ No → Copy image into target RAM → Copying failed → Return fail
  │type?        │
  └─────────────┘
      │ Yes
      ▼
  Execute Initial SW
```

*Flow with Authentication (HS Device):*
```
Memory Booting
      │
      ▼
  ┌─────────────┐
  │Device is XIP│ No → Copy image into target RAM → Copying failed → Return fail
  │type?        │
  └─────────────┘
      │ Yes
      │
      ▼
  ┌─────────────┐
  │HS device?   │ No → (Execute)
  └─────────────┘
      │ Yes
      ▼
  Authentication
      │
      ▼
  ┌──────────────────┐
  │Authentication    │ Yes → Execute Initial SW
  │successful?       │
  └──────────────────┘
      │ No
      ▼
  Dead loop
```

There are two groups of memory booting devices distinguished by the need of **code shadowing**. The ROM Shadowing means performing a code copy to an directly addressable memory (a directly addressable RAM area) from where the code can be executed. Devices which are directly addressable are called **eXecute In Place (XIP) devices**.

---

### 26.1.8.2 XIP Memory

The ROM Code can boot directly from XIP devices. A typical XIP device is a NOR flash memory. Support for XIP devices is performed under the following assumptions:

- Uses GPMC as the communication interface
- Up to 1Gbit (128Mbytes) memories can be connected
- Both x8 and x16 data bus width
- Asynchronous protocol
- Supports address/data multiplexed mode and non-muxed mode
- GPMC clock is 100 MHz
- Device connected to CS0 mapped to address 0x08000000
- Wait pin signal GPMC_WAIT0 is monitored depending on the SYSBOOT pin configuration (XIP / XIP w/ WAIT)
- Flexible muxing options for gpmc_a0-gpmc_a11 for non-muxed XIP devices

Depending on the SYSBOOT pin configuration the ROM Code decides whether to use the WAIT0 signal monitoring or not. Wait pin polarity is set to stall accessing memory when the WAIT0 pin is low. The wait monitoring is intended to be used with memories which require long time for initialization after reset or need to pause while reading data. The boot procedure from XIP device can be described as such:

- Configure GPMC for XIP device access
- Set the image location to 0x08000000
- Verify if bootable image is present at the image location
- If the image has been found, start the execution
- If the image has not been found, return from XIP booting to the main booting loop

#### 26.1.8.2.1 XIP Initialization and Detection

**GPMC initialization:**

Figure 26-14 and Table 26-8 describe the GPMC timing settings set for XIP boot and other address-data accessible devices.

**Table 26-8: XIP Timings Parameters**

| Parameter | Description | Value (clock cycles) |
|-----------|-------------|---------------------|
| tw | write cycle period | 17 |
| trl | read cycle period | 17 |
| tCEmt | CE low time | 0 |
| tCEoff | CE high time | 16 |
| tADVon | ADV low time | 1 |
| tADVoff | ADV high time | 2 |
| tOEon | OE low time | 3 |
| tWEon | WE low time | 3 |
| tWdata | data latch time | 15 |
| tOEoff | OE high time | 16 |
| tWEoff | WE high time | 15 |
| tCSEXTRADELAY | CS Extra Delay | 3/4 |

The one clock cycle is 20ns, which corresponds to 50-MHz frequency.

**Device detection:**

There is no specific identification routine executed prior to booting from an XIP device.

#### 26.1.8.2.2 Pins Used

The list of device pins that are configured by the ROM in the case of NOR boot mode are as follows. Please note that all the pins might not be driven at boot time. The decision on which pins need to be driven is done based on the type of NOR flash selected. The pins that are not listed below are not guaranteed by the ROM code and might be driven in default. Specifically, external logic is needed for address lines A16 and above to the memory, in addition to any other desired signals during non-muxed NOR boot. Similarly for Muxed NOR Boot, address lines A16 and above to the memory are not controlled by the ROM and need to be managed externally during boot, or ensure proper addressing to all the memory signals.

Once the initial software starts running, it can appropriately configure the pinmux setting for the lines and enable the specific settings in GPMC to drive all the address lines.

**Table 26-9: Pins Used for Non-Muxed NOR Boot**

| Signal name | Pin used in XIP_MUX1 mode | Pin used in XIP_MUX2 mode |
|-------------|---------------------------|---------------------------|
| CS0 | GPMC_CSN0 | GPMC_CSN0 |
| ADVN_ALE | GPMC_ADVN_ALE | GPMC_ADVN_ALE |
| OEN_REN | GPMC_OEN_REN | GPMC_OEN_REN |
| BEON_CLE | GPMC_BEN0_CLE | GPMC_BEN0_CLE |
| BE1N | GPMC_BE1N | GPMC_CSN2 and GPMC_BE1N |
| CLK | GPMC_CLK | none |
| WEN | GPMC_WEN | GPMC_WEN |
| WAIT0 | GPMC_WAIT0 | GPMC_WAIT0 |
| WAIT1 | none | GPMC_CLK |
| AD0 - AD15 | GPMC_AD0 - GPMC_AD15 | GPMC_AD0 - GPMC_AD15 |
| A0 | GPMC_A0 | LCD_DATA0 |
| A1 | GPMC_A1 | LCD_DATA1 |
| A2 | GPMC_A2 | LCD_DATA2 |
| A3 | GPMC_A3 | LCD_DATA3 |
| A4 | GPMC_A4 | LCD_DATA4 |
| A5 | GPMC_A5 | LCD_DATA5 |
| A6 | GPMC_A6 | LCD_DATA6 |
| A7 | GPMC_A7 | LCD_DATA7 |
| A8 | GPMC_A8 | LCD_VSYNC |
| A9 | GPMC_A9 | LCD_HSYNC |
| A10 | GPMC_A10 | LCD_PCLK |
| A11 | GPMC_A11 | LCD_AC_BIAS_EN |

**Table 26-10: Pins Used for Muxed NOR Boot**

| Signal name | Pin used in XIP_MUX1 mode | Pin used in XIP_MUX2 mode |
|-------------|---------------------------|---------------------------|
| CS0 | GPMC_CSN0 | GPMC_CSN0 |
| ADVN_ALE | GPMC_ADVN_ALE | GPMC_ADVN_ALE |
| OEN_REN | GPMC_OEN_REN | GPMC_OEN_REN |
| BEON_CLE | GPMC_BEN0_CLE | GPMC_BEN0_CLE |
| BE1N | GPMC_BE1N | GPMC_CSN2 and GPMC_BE1N |
| CLK | GPMC_CLK | none |
| WEN | GPMC_WEN | GPMC_WEN |
| WAIT0 | GPMC_WAIT0 | GPMC_WAIT0 |
| WAIT1 | none | GPMC_CLK |
| AD0 - AD15 | GPMC_AD0 - GPMC_AD15 | GPMC_AD0 - GPMC_AD15 |

#### 26.1.8.2.3 SYSBOOT Pins

Some of the SYSBOOT pins have special meanings when NOR boot is selected.

**Table 26-11: Special SYSBOOT Pins for NOR Boot**

| SYSBOOT[n] | Description |
|------------|-------------|
| [8] | 0 = 8-bit device<br>1 = 16-bit device |
| [11:10] | 00b = Non-muxed device<br>10b = Muxed device<br>x1b = Reserved |

---

### 26.1.8.3 Image Shadowing for Non-XIP Memories

#### 26.1.8.3.1 Shadowing on GP Device

The **GP Device** shadowing uses the approach in Figure 26-15.

**Figure 26-15: Image Shadowing on GP Device**

```
Memory booting
      │
      ▼
   ┌──────────────────────┐    Device detection
   │ Initialization       │──→ Initialization failed ──→ Return fail
   │ and                  │
   │ Device detection     │
   └──────────────────────┘
      │
      ▼
   Set first / next valid block
      │                    No more blocks ──→ Return fail
      ▼                    
   ┌─────────────┐
   │Copying      │ No more sectors to read
   │failed       │◄──┐
   └─────────────┘   │
      │              │
      ▼              │
   Read a sector ────┘
      │
      ▼
   Store the loaded sector with
   Initial SW in the target buffer
      │
      ▼
   ┌──────────────────┐
   │Loading Initial SW│ No ──→ (continue reading)
   │Completed?        │
   └──────────────────┘
      │ Yes
      ▼
   Initial SW execution
```

---

### 26.1.8.4 NAND

The NAND flash memory is not XIP and requires shadowing before the code can be executed.

#### 26.1.8.4.1 Features

- Uses GPMC as the communication interface
- Device from 512MBit (64MByte)
- x8 and x16 bus width
- Support for large page size (2048 bytes + 64 spare bytes) or very large page size 4096 bytes + 128/218 spare bytes)
- Only supports devices where Chip Select can be de-asserted during read, program or erase cycles, without interrupting the operation
- Device Identification based on ONFI or ROM table
- ECC correction is bits/sector for most devices (16b/sector for devices with large spare area)
- Support for disabling ECC correction, so that the in-built ECC correction mechanisms on some NANDs can be used
- GPMC timings adjusted for NAND access
- GPMC clock is 50MHz
- Device connected to GPMC_CSN0
- Wait pin signal GPMC_WAIT0 connected to NAND BUSY output
- Four physical blocks are searched for an image. The block size depends on device

#### 26.1.8.4.2 Initialization and Detection

The initialization routine for NAND devices consists in three parts: GPMC initialization, device detection with parameters determination and finally bad block detection.

**ONFI Support:**

The NAND identification starts with ONFI detection. For more information on ONFI standard, see the Open NAND Flash Interface (www.onfi.org).

**GPMC Initialization:**

The GPMC interface is configured as such it can be used for accessing NAND devices. The address bus is released since a NAND device does not use it. The data bus width is initially set to 16 bits; and changed to 8 bits if needed after device parameters determination. The following scheme is applied since NAND devices require different timings when compared to regular NOR devices:

**Table 26-12: NAND Timings Parameters**

| Parameter | Description | Value [clock cycles] |
|-----------|-------------|---------------------|
| tw | write cycle period | 30 |
| trl | read cycle period | 30 |
| tCEmt | CE low (not marked on the figure) | 0 |
| tCEoff | CE low to OE low time | 7 |
| tWEmt | CE low to WE low time | 5 |
| tWdata | CE low to data latch time | 21 |
| tOEoff | CE low to OE high time | 24 |
| tWEoff | CE low to WE high time | 22 |

Figure 26-16 and Table 26-12 describes the timings configured for NAND device access. The one clock cycle is 20 ns, which correspond to 50-MHz frequency.

**Device Detection and Parameters:**

The ROM Code first performs device wait for device auto initialization (with 250ms timeout) with polling of the ready information. Then, it needs to identify the NAND type connected to the GPMC interface. The GPMC is initialized in 16 bits, asynchronous mode. The NAND device is reset (command FFh) and its status is polled until ready for operation (with 200ms timeout). The ONFI Read ID (command 90h / address 20h) is sent to the NAND device. If it replies with the ONFI signature (4 bytes) then a Read parameters page (command ECh) is sent. If the parameters page does not have the ONFI signature, then the ONFI identification passes, the information shown in Table 26-13 is then extracted: page size, spare area size, number of pages per block, and the addressing mode.

**Table 26-14: Supported NAND Devices**

| Capacity | Device ID | Bus Width | Page size |
|----------|-----------|-----------|-----------|
| 16 Gb | 88 | x8 | 2048 |
| 16 Gb | 96 | x16 | 2048 |
| 32 Gb | D7 | x8 | 2048/4096 |
| 32 Gb | C7 | x16 | 2048/4096 |
| 32 Gb | A7 | x8 | 2048/4096 |
| 32 Gb | 87 | x16 | 2048/4096 |
| 32 Gb | 87 | x8 | 2048 |
| 32 Gb | 97 | x16 | 2048 |
| 64 Gb | DE | x8 | 2048/4096 |
| 64 Gb | CE | x16 | 2048/4096 |
| 64 Gb | AE | x8 | 2048/4096 |
| 64 Gb | BE | x16 | 2048/4096 |

When the parameters are retrieved from the ROM table: page size and block size is updated based on 4th byte of NAND ID data. Due to inconsistency amongst different manufacturers, only devices which has been recognized to be at least 2GB (included) have these parameters updated. Therefore, the ROM Code supports 4kB page devices but only if their size, according to the table, is at least 2Gb. Devices which are smaller than 2Gb have the block size parameter fixed to 128kB. Table 26-15 shows the 4th ID Data byte encoding used in ROM Code.

**Table 26-15: 4th NAND ID Data Byte**

| Item | Description | I/O # | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|------|-------------|---|---|---|---|---|---|---|---|---|
| Page Size | 1kB | | | | | | | | 0 | 0 |
| | 2kB | | | | | | | | 0 | 1 |
| | 4kB | | | | | | | | 1 | 0 |
| | 8kB | | | | | | | | 1 | 1 |
| Cell type | 2 levels | | | | | | 0 | 0 | | |
| | 4 levels | | | | | | 0 | 1 | | |
| | 8 levels | | | | | | 1 | 0 | | |
| | 16 levels | | | | | | 1 | 1 | | |
| Block Size | 64kB | | | 0 | 0 | | | | | |
| | 128kB | | | 0 | 1 | | | | | |
| | 256kB | | | 1 | 0 | | | | | |
| | 512kB | | | 1 | 1 | | | | | |

**Reading NAND Geometry From I2C EEPROM:**

ROM supports a special boot mode called NANDI2C to support NAND devices whose geometry cannot be detected by the ROM automatically using methods described in the previous section. If this boot mode is selected, the ROM code tries to read NAND geometry from an I2C EEPROM. If the read is successful, ROM code then proceeds to normal NAND boot, beginning with reading bad block information.

**Table 26-16: Pins Used for NANDI2C Boot for I2C EEPROM Access**

| Signal name | Pin Used in Device |
|-------------|-------------------|
| I2C_SCL | i2c0_scl |
| I2C_SDA | i2c0_sda |

ROM accesses the I2C EEPROM at I2C slave address **0x50** and reads 7 bytes starting from address offset **0x80**. The ROM sends a 2-byte address to perform a selective read from the I2C EEPROM, thus the ROM can only support devices that are minimum of 32Kb in size. The format of this (NAND geometry information) is as follows:

**Table 26-17: NAND Geometry Information on I2C EEPROM**

| Byte address | Information | |
|--------------|-------------|-------------|
| | Upper nibble | Lower nibble |
| 0x80 | Magic Number – 0x10 | |
| 0x81 | Magic Number – 0xb3 | |
| 0x82 | Magic Number – 0x57 | |
| 0x83 | Magic Number – 0xa6 | |
| 0x84 | NAND column address (wordbyte offset within page) size in bytes. Example: 2 | NAND row address (page offset) size in bytes. Example: 3 |
| 0x85 | Page size (2ⁿ) exponent 'N'. Example (for page size of 2048): 11 | Pages per block (2ⁿ) exponent 'N'. Example (for number of blocks 64): 6 |
| 0x86 | NAND bus width<br>0 = 8-bit device<br>1 = 16-bit device | ECC Type<br>00b = No ECC<br>01b = BCH8<br>10b = BCH16<br>11b = Reserved |

**ECC Correction:**

The default ECC correction applied is BCH 8b/sector using the GPMC and ELM hardware.

Referring ID codes 88h, c5h, c7h, DEh, CEh, AEh, BEh, when manufacturer code (first ID byte) is 98h the Cell type information is checked in the 4th byte of ID data. If it is equal to 10b then the ECC correction applied is BCH 16b/sector.

In addition ECC computation done by the ROM can be turned off completely by using SYSBOOT[9]. This is particularly useful when interfacing with NAND devices that have built in ECC engines.

**Table 26-18: ECC Configuration for NAND Boot**

| SYSBOOT[9] | ECC Computation |
|------------|-----------------|
| 0 | ECC done by ROM |
| 1 | ECC handled by NAND |

**Figure 26-17: NAND Device Detection**

```
NAND detection
      │
      ▼
   Wait for device initialization
   (max timeout 250ms)
      │               Timeout reached
      ▼               ────────────────→ (timeout, failed)
   ┌─────────────┐
   │Device ready?│ No ──→ (wait)
   └─────────────┘
      │ Yes
      ▼
   Issue Read command
   (max timeout 200ms)
      │
      ▼
   ┌─────────────┐
   │Device ready?│ No ──→ (wait)
   └─────────────┘
      │ Yes
      ▼
   Issue Read ID (ONFI) command
      │
      ▼
   ┌──────────────────┐
   │Device replied     │ Yes ──┐
   │ONFI?             │        │
   └──────────────────┘        │
      │ No                     │
      ▼                        │
   Issue Reset command         │
      │                        │
      ▼                        ▼
   ┌─────────────┐      Issue Read parameters page
   │Device ready?│ No   command
   └─────────────┘        │
      │ Yes               ▼
      ▼              Extract NAND parameters
   Issue Read ID        from device parameters page
   (standard) command    │
      │                  │
      ▼                  │
   ┌─────────────┐       │
   │Device ID    │ No    │
   │in the table?│──────→│
   └─────────────┘       │
      │ Yes              │
      ▼                  │
   Extract NAND parameters from table
      │                  │
      │◄─────────────────┘
      ▼
   Update page size, block size, ECC
   correction for devices > 1 Gb
      │
      ▼
   Read Invalid Blocks
   information
      │
      ▼
   Success
```

**Bad Block Verification:**

Invalid blocks are blocks which contain invalid bits whose reliability cannot be guaranteed by the manufacturer. Those bits are identified in the factory or during the programming and reported in the initial pages of the block. The ROM code always performs that validation when searching for a bootable image. If the Code is looking for an image in the first four blocks, it must detect block validity status of these blocks. Blocks which are detected as invalid are not accessed later on. Blocks validity status is coded in the spare areas of the first two pages of a block (first byte equal to Fh in 1st and 2nd pages for an 8 bits device / first word equal to FFFFh in 1st and 2nd page for a 16 bits device).

Figure 26-18 depicts the invalid block detection routine. The routine consists in reading spare areas and checking validity data pattern.

**Figure 26-18: NAND Invalid Blocks Detection**

```
Read Invalid Blocks
Information
      │                                 ┌─────────────────────┐
      ▼                                 │ For first 4 blocks  │
   Read 1st and 2nd spare               │                     │
   sectors                              │                     │
      │                                 │                     │
      ▼                                 │                     │
   ┌────────────────┐                  │                     │
   │Invalid Block   │ Yes ──→ Set Invalid Block Flag        │
   │Information?    │                   │                     │
   │0xFF or 0xFFFF  │                   │                     │
   │for 16-bit      │                   │                     │
   │devices?        │                   │                     │
   └────────────────┘                   │                     │
      │ No                              │                     │
      ▼                                 │                     │
   Clear Invalid Block Flag             │                     │
      │                                 │                     │
      └─────────────────────────────────┘
```

#### 26.1.8.4.2.1 NAND Read Sector Procedure

The ROM Code reads data from NAND devices in 512 bytes sectors. The read function fails in two cases:

- The accessed sector is within a block marked as invalid
- The accessed sector contains an error which cannot be corrected with ECC

Figure 26-19 shows the read sector routine for NAND devices. The ROM Code uses normal read (command 00h 30h) for reading NAND page data.

**Figure 26-19: NAND Read Sector Procedure**

```
Read Sector
      │
      ▼
   ┌─────────────┐
   │Is this block│ Yes ──→ (return failed)
   │invalid      │
   └─────────────┘
      │ No
      ▼
   Read 512 bytes sector
      │
      ▼
   ┌──────────────┐
   │GPMC ECC      │ Yes ──→ Correct Error ──→ Failed
   │?             │              │
   │NAND ECC      │              │
   └──────────────┘              │
      │ No                       │
      │                   Success│
      ▼                          ▼
   Success                    (return success)
```

Page data can contain errors due to memory alteration. The ROM Code uses an ECC correction algorithm to detect and possibly correct those errors. The ECC algorithm used is BCH with capability for correcting 8b or 16b errors per sector. The BCH data is automatically calculated by the GPMC on reading each 512 bytes sector. The computed ECC is compared with the ECC stored in the spare area (corresponding spare area for Figure 26-20 and Figure 26-21 show the mapping of ECC data stored in the spare area for respectively 2KB-page and 4KB- page devices. If both ECC data are equal then the Read sector function returns as if no errors occured. If there is a difference, the ROM Code invokes an ECC error(s) in the corresponding sector (this procedure is assisted by the ELM hardware) and returns the data if successful. If errors are uncorrectable, the function returns with FAIL.

When the 512 byte sector successfully passes the ECC check, the ROM checks for a valid configuration header. A configuration header is considered to be valid if the first value (the Start field) contains data other than 0x00000000 or 0xFFFFFFFF. If the Start field is not valid, the ROM reads the next 512-byte sector, performs the ECC procedure described above, and checks for a valid configuration header. This process is repeated for the whole block until a valid header is found. If a valid header is not found in the first block, the ROM attempts the same process in the next block. For NAND, the ROM checks for a valid header in the first four blocks. If no valid header is found in the first 4 blocks, the NAND boot fails, and the ROM moves on to the next valid boot source as dictated by boot order signals.

#### 26.1.8.4.2.2 Pins Used

The list of device pins that are configured by the ROM in the case of NAND boot mode are as follows. Please note that all the pins might not be driven at boot time.

**NOTE:** Caution must be taken when using an 8-bit NAND. The ROM initially configures all address and data signals (including AD15) the GPMC uses when attempting to read configuration values from the NAND. If you use an 8-bit NAND, and connect AD15-AD8 to other functions (GPIOs, for example), there may be contention on these signals during the boot phase. AD15-AD8 are configured as outputs and will be driven by the ROM if NAND boot is selected. Ensure external circuits will not be in contention with these driven outputs.

**Table 26-19: Pins Used for NAND Boot**

| Signal name | Pin Used in Device |
|-------------|-------------------|
| CS0 | GPMC_CSN0 |
| ADVN_ALE | GPMC_ADVN_ALE |
| OEN_REN | GPMC_OEN_REN |
| BEON_CLE | GPMC_BEN0_CLE |
| BE1N | GPMC_BE1N |
| WEN | GPMC_WEN |
| WAIT | GPMC_WAIT0 |
| CLK | GPMC_CLK |
| AD0 - AD15 | GPMC_AD0 - GPMC_AD15 |

#### 26.1.8.4.2.3 SYSBOOT Pins

SYSBOOT[11:10] has a special meaning when NAND boot is selected. SYSBOOT[11:10] must be 0.

---

### 26.1.8.5 MMC / SD Cards

#### 26.1.8.5.1 Overview

The ROM Code supports booting from MMC / SD cards in the following conditions:

- MMC/SD Cards compliant to the Multimedia Card System Specification and Secure Digital I/O Card Specification of low and high capacities
- MMC/SD cards connected to MMC0 or MMC1
- Support of x1 or x8 V on MMC0 and MMC1
- Initial 1-bit MMC Mode, optional 4-bit mode, if device supports it
- Clock Frequency: identification mode: 400 KHz; data transfer mode up to 10 MHz
- Only one card connected to the bus
- Raw mode, image data read directly from sectors in the user area
- File system mode (FAT12/16/32 supported with or without Master Boot Record), image data is read from a booting file

#### 26.1.8.5.2 System Interconnection

Each interface has booting restrictions on which type of memory it supports:

- **MMC0** supports booting from eMMC/SD card cage and also supports booting from eMMC/eSD/managed NAND memory devices with less than 4GB capacity
- **MMC1** supports booting from eMMC/eSD/managed NAND memory device with 4GB capacity or greater

The restriction is a result of many eMMC devices not being compliant with the eMMC v4.41 specification. If you must boot from two different card cages, many MMC/SD cards will boot from MMC1 but will not boot some older cards may not boot because MMC1 boot uses a slightly different boot sequence to support booting eMMC. Generally, external eMMC devices will be well tested for compatibility, only MMC0 should be used to boot from the card cage. Similarly for maximum compatibility, booting from eMMC/eSD/managed NAND should only be performed on MMC1.

Note that the above restrictions only apply to booting from each port. Drivers can be written for either port to support any desired interface.

**Note:**

- The ROM Code does not handle the card detection feature on card cage
- If MMC is used the GPMC interface is not usable, due to pin muxing options
- MMC1 supports sector mode without querying the card

#### 26.1.8.5.3 Booting Procedure

The high level flowchart of the eMMC / eSD and MMC/SD booting procedure is depicted in Figure 26-22.

**Figure 26-22: MMC/SD Booting**

```
MMC/ SD Booting
      │
      ▼
   Initialize the MMC / SD driver
      │
      │                Not detected
      ▼                ────────────→ Failed
   ┌──────────────────┐
   │Detect card       │
   │ Detected         │
   │  memory          │
   └──────────────────┘
      │ Detected
      ▼
   Configure the card address
   (RCA)
      │
      ▼              No
   ┌─────────────┐◄────┐
   │Booting file │     │
   │found?       │     │
   └─────────────┘     │
      │ Yes            │
      ▼                │
   Get the booting file│
      │                │
      │                │
      ▼                │
   ┌─────────────┐    │
   │'Raw mode'   │ No─┘
   │detected?    │
   └─────────────┘
      │ Yes
      ▼
   Get raw data
      │
      ▼
   Success
```

#### 26.1.8.5.4 Initialization and Detection

The ROM Code attempts to initialize the memory device or card connected on MMC interface. If neither memory device nor card is detected then the ROM Code carries on to the next booting device. The standard identification process is named **Card Address (RCA)** assignment and so forth. However, the ROM Code assumes that only one memory or card is present on the bus. This first sequence is done using the CMD0 and CMD1 signaling to be common to SD and MMC devices.

MMC and SD standards detail this phase as **initialization phase**. Both standards differ in the first commands involved: CMD1 for MMC and ACMD41 for SD. The ROM Code uses this difference to discriminate between MMC and SD devices: CMD1 is supported only by the MMC standard whereas ACMD41 is only supported by SD standard. The ROM Code first sends a CMD1 to the device and expects a response only if an MMC device is connected. If no response is received then ACMD41 (ACMD41 is made out of CMD55 and ACMD41) is sent and a response is expected from an SD device. If no response is received then it is assumed that no device is connected and the ROM Code exits the MMC/SD Booting procedure with FAIL. This is detection procedure shown in Figure 26-23.

Another point to note is the difference in the arguments to CMD1 between MMC0 and MMC1. At first the ROM queries from the card SECTOR_MODE capability using READ_OCR from the card. If MMC0, the response from the card is simply reflected back to the card as the argument for all subsequent CMD1, till the card is in the READY state. On MMC1, Bit30 of the response received from the card is set to 1 by the ROM, and this modified value is used as the argument for subsequent CMD1. This is done to indicate to the card that the ROM supports sector addressing. This mode might not be supported by older/legacy/non-standard versions of cards.

**Figure 26-23: MMC/SD Detection Procedure**

```
MMC / SD detection
      │
      ▼
   Send CMD1 command
      │
      │         No response received
      ▼         ───────────────────→ (try SD)
   ┌─────────────┐
   │Timeout      │
   │waiting for  │
   │answer?      │
   └─────────────┘
      │ Response received
      ▼
   MMC device
   
   (If no MMC response)
      │
      ▼
   Send CMD55
   Send ACMD41
      │
      ▼
   ┌─────────────┐
   │Timeout      │ Yes ──→ No device detected
   │waiting for  │
   │answer?      │
   └─────────────┘
      │ No
      ▼
   SD device
```

The contents of an MMC/SD card or an eMMC/eSD device may be formatted as raw binary or within a FAT filesystem. The ROM Code reads out raw sectors from image or the booting file within the file system and boots from it.

#### 26.1.8.5.5 MMC/SD Read Sector Procedure in Raw Mode

In raw mode the booting image can be located at one of the four consecutive locations in the main area: offset 0x0 (0x0), offset 0x20000 (128KB), offset 0x40000 (256KB), or offset 0x60000 (384KB). For this boot mode, the image size shall not exceed 128KB in size. However it is possible to flash a device with an image greater than 128KB by flashing at one of the aforementioned locations. Therefore the ROM Code does not check the image size. The only drawback is that the image size must not span the next subsequent image boundary.

The ROM will check the first sector (offset 0x0) for the presence of the TOC structure as described in Section 26.1.10. If the sector contains a valid CHSETTINGS item, the ROM will use that header to see next 512-byte section, uses its size and destination information to download the image to the destination address, and starts execution there. If the TOC header is complete the boot. If it is not, the boot fails and the invalid, the ROM checks for a redundant image in the next location (0x20000), and repeats the process to test a valid TOC is available. The TOC is considered invalid if the first location is either 0xFFFFFFFF or 0x00000000 (which is typical of a missing card or an erased image), or if the CHSETTINGS item is missing or empty.

#### 26.1.8.5.6 MMC/SD Read Sector Procedure in FAT Mode

MMC/SD Cards or eMMC/ eSD devices may hold a FAT file system which ROM Code is able to read and process. The image booting procedure is taken from a specific file. For this boot mode the booting file has to be located in the root directory on an active primary partition of type FAT12/16 or FAT32.

An MMC/SD card or eMMC/ eSD device can be configured either as floppy-like or hard-drive-like:

- When configured as floppy-like, a single file system is present without any Master Boot Record (MBR) holding a partition table
- When configured as hard-drive-like, an MBR is present in the first sector. This MBR holds a table of partitions, one of which must be FAT12/16/32, primary and active

---

#### 26.1.8.5.7 Partition and FAT Structure Details

**Table 26-21: Partition Entry**

| Offset | Length[bytes] | Entry Description | Value |
|--------|--------------|-------------------|-------|
| 0x00h | 1 | Partition State | 00h: Inactive/80h: Active |
| 0x01h | 1 | Partition Start Head | H_s |
| 0x02h | 2 | Partition Start Cylinder and Sector | C_s[7:0],C_s[9:8] S_s[5:0] |
| 0x04h | 1 | Partition Type | See Table 26-22 for partial partition types |
| 0x05h | 16 | Partition End Head | H_e |
| 0x06h | 2 | Partition End Cylinder and Sector | C_e[7:0],C_e[9:8] S_e[5:0] |
| 0x08h | 4 | First sector position relative to the beginning of media | LBA_s=C_s H_s+H_s S_s+S_s-1 |
| 0x0Ch | 4 | Number of sectors in partition | LBA_e=C_e H_e+H_e S_e+S_e-1\NBS= LBA_e-LBA_s+1 |

**Table 26-22: Partition Types**

| Partition Type | Description |
|---------------|-------------|
| 01h | FAT12 |
| 04h, 06h, 0Eh | FAT16 |
| 0Bh, 0Ch, 0Fh | FAT32 |

The way the ROM Code detects whether a sector is the 1st sector of an MBR or not is described in Figure 26-25.

The ROM Code first checks if the signature is present. Each partition entry is checked:
- If its type is set to 00h then all fields in the entry must be 00h
- The partition is checked to be within physical boundaries, i.e. the partition is located inside and it's size fits the total physical sectors.

**Figure 26-25: MBR Detection Procedure**

```
MBR detection
      │
      ▼
   ┌─────────────────┐
   │0xAA55 Signature │ No ──→ (not MBR)
   │at offset 0x1FE? │
   └─────────────────┘
      │ Yes
      ▼
   ┌──────────────────────────────────────┐
   │                                       │
   │  ┌─────────────┐                     │
   │  │Partition    │ Yes ──→ Are all    │ Yes
   │  │type is 00h? │         fields 00h?│────→
   │  └─────────────┘                     │
   │      │ No                            │
   │      ▼                               │ For all 4 entries
   │  ┌─────────────┐                     │
   │  │Partition    │ No ◄────────────────┤
   │  │within       │                     │
   │  │physical     │                     │
   │  │boundaries?  │                     │
   │  └─────────────┘                     │
   │      │ Yes                           │
   │      └───────────────────────────────┘
   │
   ▼
Success
```

Once identified, the ROM Code gets the partition using the procedure described in Figure 26-26. The partition type is checked to be FAT12/16 or FAT32. Its state must be 00h or 80h (if there are more than one active partition the test fails). The ROM Code returns with FAIL if no active primary FAT12/16/32 could be found.

**Figure 26-26: MBR, Get Partition**

```
MBR get partition
      │
      ▼                      ┌────────────────────┐
   ┌─────────────┐           │                    │
   │Partition    │ No ───────┤                    │
   │type is      │           │                    │
   │FAT12/16/32  │           │                    │
   └─────────────┘           │                    │
      │ Yes                  │ For all 4 entries  │
      ▼                      │                    │
   ┌─────────────┐           │                    │
   │Is it active │ No ───────┤                    │
   └─────────────┘           │                    │
      │ Yes                  │                    │
      ▼                      │                    │
   ┌──────────────────┐      │                    │
   │An active         │ Yes ─┤                    │
   │partition has     │      │                    │
   │been already      │      │                    │
   │found             │      │                    │
   └──────────────────┘      │                    │
      │ No                   │                    │
      ▼                      │                    │
   ┌─────────────┐           │                    │
   │Valid         │ No ──────┘                    │
   │partition was │                               │
   │found         │                               │
   └─────────────┘                                │
      │ Yes                                       │
      ▼                                           │
   Success                                        │
                                                  ▼
                                              Failed
```

#### 26.1.8.5.7.2 FAT12/16/32 Boot Sector

The FAT file system is made out of several parts:
- Boot Sector which holds the BIOS Parameter Block (BPB)
- File Allocation Table (FAT) which describes the use of each cluster of the partition
- Data Area which holds the Files, Directories and Root Directory (for FAT12/16, the Root Directory has a specific fixed location).

The Boot Sector is described in Table 26-23.

**Note:** In the following description, all the fields whose names start with BPB_ are part of the BPB. All the fields whose names start with BS_ are part of the Boot Sector and not really part of the BPB (not mandatory), they are not used at all by the ROM Code.

**Table 26-23: FAT Boot Sector**

| Offset | Length[bytes] | Name | Description |
|--------|--------------|------|-------------|
| 0x00h | 3 | BS_jmpBoot | Jump instruction to Boot Code (not used) |
| 0x03h | 8 | BS_OEMName | Name of the System which created the partition |
| 0x0Bh | 2 | BPB_BytsPerSec | Counts of Bytes per sector (usually 512) |
| 0x0Dh | 1 | BPB_SecPerClus | Number of sectors per allocation unit |
| 0x0Eh | 2 | BPB_RsvdSecCnt | Number of reserved sectors for the Boot Sector for FAT12/16 is 1, for FAT32 is typically 32 |
| 0x10h | 1 | BPB_NumFATs | Number of copies of FAT, usually 2 |
| 0x11h | 2 | BPB_RootEntCnt | For FAT12/16, number of 32 bytes entries in the Root Directory (multiple of BPB_BytsPerSector) 200h for FAT12 this value) |
| 0x13h | 2 | BPB_TotSec16 | Total Count of sectors on the volume. If the size is bigger than 10000h or for FAT32, this field is 0 and BPB_TotSec32 holds the true value |
| 0x15h | 1 | BPB_Media | Media Type, usually F8h: fixed, non-removable |
| 0x16h | 2 | BPB_FATSz16 | For FAT12/16, size in sectors of one FAT for FAT32, holds 0 |
| 0x18h | 2 | BPB_SecPerTrk | Number of sectors per track, 63 for SD/MMC |
| 0x1Ah | 2 | BPB_NumHeads | Number of heads, 255 for SD/MMC |
| 0x1Ch | 4 | BPS_HiddSec | Number of sectors preceding the partition |
| 0x20h | 4 | BPB_TotSec32 | Total Count of sectors on the volume. If the size is smaller than 10000h (for FAT12/16), this field is 0 and BPB_TotSec16 is valid |

**Table 26-23: FAT Boot Sector (continued)**

| Offset | Length[bytes] | Name | Description |
|--------|--------------|------|-------------|
| 0x24h | 4 | BPB_FATSz32 | Size in sectors of one FAT. Field BPB_FATSz16 must be 0 |
| 0x28h | 2 | BPB_ExtFlags | FAT Flags |
| | | | [7]: 0=FAT is mirrored; 1=Only one FAT is active |
| | | | [3:0]: Number of used FAT if the mirroring used |
| 0x2Ah | 2 | BPB_FSVer | File system Version Number |
| 0x2Ch | 4 | BPB_RootClus | First Cluster number of the Root Directory |
| 0x30h | 2 | BPB_FSInfo | Sector number of FSINFO Structure in the reserved area, usually 1 |
| 0x32h | 2 | BPB_BkBootSec | If non-zero, indicates the sector number in the reserved-area of a copy of this Boot Sector |
| 0x34h | 12 | BPB_Reserved | Reserved, set to 00h |
| 0x40h | 1 | BS_DrvNum | Drive Number |
| 0x41h | 1 | BS_Reserved1 | 00h |
| 0x42h | 1 | BS_BootSig | Extended Boot Signature 29h: indicates that the following 3 fields are present |
| 0x43h | 4 | BS_VolID | Volume Serial Number |
| 0x47h | 11 | BS_VolLab | Volume Label |
| 0x52h | 8 | BS_FilSysType | File system Type: "FAT12", "FAT16", "FAT32" Note: This field is not mandatory (i.e BS_) therefore it cannot be used to indentify the partition type. |
| 0x1FEh | 2 | BPB_Signature | AA55h |

**AASI:**

To check whether or not a sector holds a valid FAT12/16/32 partition, only fields starting with BPB can be checked as they are mandatory. The fields starting from offset 0x24h to 0x1FDh cannot be used for the FAT12/16 filesystem. Roughly, the procedure is detailed in Figure 26-27. After a sector is identified, the ROM Code checks if the BPB_Signature is equal to AA55h. Then it checks some fields which must have some specific values (BPB_BytesPerSec, BPB_SecPerClus, BPB_RsvdSecCnt, BPB_NumFATs, BPB_RootEntCnt) If the geometry of the device is known (valid CHS for device size < 4Gbytes) then it is compared against BPB_SecPerTrk and BPB_NumHeads fields. If an MBR was found before, the partition size is also checked:

The field BPB_TotSec16 is used if the value is not 0 and if the partition offset (in the MBR) is 65518 or less (or BPB_TotSec32=0), otherwise BPB_TotSec32 is used (BPB_TotSec16=0). The partition sector offset is also checked: BPB_HiddSec = MBR_Partition_Offset (if this value is not 0 as some old systems do not update this field correctly). The last step is to decide which type of FAT file system it is. The ROM Code computes the number of clusters in the Data Area part of the partition:

Where Nb clusters is given by the size of the Data Area:

**Figure 26-27: FAT Detection Procedure**

```
Is there a FAT?
      │
      ▼
   ┌─────────────┐
   │0xAA55       │ Yes ──→ BPB_BytsPerSec ──→ Yes ──→ BPB_SecPerClus ──→ Yes
   │at offset    │         =                         1, 2, 4, 8, 16
   │0x1FE        │         512                       32, 64 or 128
   └─────────────┘
      │ No                │ No                        │ No
      │                   │                           │
      ▼                   ▼                           │
   ┌─────────────┐     ┌─────────────┐               │
   │BPB_RsvdSecCnt│ Yes│BPB_NumFATs  │ Yes ──→ BPB_RootEntCnt ──→ Yes
   │> 0          │     │= 2          │         or
   └─────────────┘     └─────────────┘         BPB_BytsPerSec/
      │ No                │ No                  32
      │                   │                     │ No
      │                   │                     │
      ▼                   ▼                     ▼
   ┌─────────────┐                         (loop back to retry)
   │Was there    │ Yes ──→ BPB_TotSec16 or ──→ Yes
   │an MBR?      │         BPB_TotSec32 =
   └─────────────┘         MBR_Partition_Size
      │ No                │ No
      │                   │
      ▼                   ▼
   Compute data area size to
   determine FAT type
      │
      ▼
   Success:
   FAT12,
   FAT16 or
   FAT32
```

#### 26.1.8.5.7.3 FAT12/16/32 Root Directory

The next task for the ROM Code is to find the booting file named **"MLO"** inside the Root Directory of the FAT12/16/32 file system. The file is not searched in any other location.

For a FAT12/16 file system, the Root Directory is a fixed location which is cluster 0. For a FAT32 file system, its cluster location is given by BPB_RootClus. The general formulae to find the sector number of a cluster is given by:

*Cluster_sector = BPB_RsvdSecCnt + BPB_NumFATs x BPB_FATSz + Cluster x BPB_SecPerClus*

Note: BPB_FatSz is BPB_FatSz16 for FAT12/16 or BPB_FatSz32 for FAT32

Note: the BPB_HiddSec isn't used. If even when the FAT file system is located somewhere other than on sector 0 (floppy-like). The ROM Code actually uses the partition offset taken from the MBR instead so this field can be wrong. If no MBR was found (floppy-like) the value 0 is used.

Each entry in the Root Directory is 32 bytes long and held information about the file, i.e: filename, date of creation, rights and sector location which is described in Table 26-24.

The ROM Code checks each entry in the Root Directory until either the booting file is found or the entry is empty (first byte is 00h) or when the end of the Root Directory has been reached. Entries with first byte at E5h (erased file) and with first byte at E5h (erased file) are ignored. When a valid file is found, the first cluster offset of the file is read from the DIR_FstClusHI/DIR_FstClusLo fields.

There is a slight difference between FAT12/16 and FAT32 when handling the Root Directory. On FAT12/16, this directory has a fixed location (see above) and length fixed by BPB_RootEntCnt which is the total number of 32 bytes entries. Handling this directory is therefore straight forward. On FAT32, the Root Directory is like any other directory. The File Allocation Table (FAT) has to be used in order to retrieve each sector of the Directory. The way the FAT is handled is described in the next paragraph.

**Table 26-24: FAT Directory Entry**

| Offset | Length[bytes] | Name | Description |
|--------|--------------|------|-------------|
| 0x00h | 11 | DIR_Name | Short Name (8+3) |
| 0x0Bh | 1 | DIR_Attr | File Attributes |
| | | | ATTR_READ_ONLY: 01h |
| | | | ATTR_HIDDEN: 02h |
| | | | ATTR_SYSTEM: 04h |
| | | | ATTR_VOLUME_ID: 08h |
| | | | ATTR_DIRECTORY: 10h |
| | | | ATTR_ARCHIVE: 20h |
| | | | ATTR_READ_ONLY \| ATTR_HIDDEN \| ATTR_SYSTEM \| ATTR_VOLUME_ID |
| 0x0Ch | 1 | DIR_NTRes | Reserved, set to 00h |
| 0x0Dh | 1 | DIR_CrtTimeTenth | Millisecond stamp at file creation |
| 0x0Eh | 2 | DIR_CrtTime | Time file was created |
| 0x10h | 2 | DIR_CrtDate | Date file was created |
| 0x12h | 2 | DIR_LstAccDate | Last Access date |
| 0x14h | 2 | DIR_FstClusHI | High word of this entry's first cluster number |
| 0x16h | 2 | DIR_WrtTime | Time of last write |
| 0x18h | 2 | DIR_WrtDate | Date of last write |
| 0x1Ah | 2 | DIR_FstClusLo | Low word of this entry's first cluster number |
| 0x1Ch | 4 | DIR_FileSize | File size in bytes |

#### 26.1.8.5.7.4 FAT12/16/32 File Allocation Table

The ROM Code needs to read the FAT in order to retrieve sectors either for the booting file or for the Root Directory (in case FAT32).

There can be multiple copies of the FAT inside the file system (ROM Code supports only 2) located after the Boot Sector:

*FAT_sector = BPB_HiddSec+BPB_RsvdSecCnt+BPB_FatSz x n*

Its size is given by BPB_FATSz16 or BPB_FATSz32. The ROM Code checks each copy of the FAT if identical. If case the values are not equal, it uses the value from the last FAT copy.

With FAT32 file system, the copy system can be disabled according to a flag located in BPB_ExtFlags[7]. If this flag is set then FAT_BPB_ExtFlags[3:0] is used. In this case no verification is made by the ROM Code with other copies of FAT.

The FAT is a simple array of values each refering to a cluster located in the Data Area. One entry of the array is 12, 16 or 32 bits depending on the file system in use.

The value inside an entry defines whether the cluster is being used or not and if another cluster has to be taken into account. This creates a linked chain of clusters defining the file. The meaning of an entry is described in Table 26-25.

**Note:** For compatibility reasons, clusters 0 and 1 are not used for files and those entries must contain FF8h and FFFh (for FAT12); FFF8h and FFFFh (for FAT16); ?FFFFFF8h and ?FFFFFFh (for FAT32).

**Table 26-25: FAT Entry Description**

| FAT12 | FAT16 | FAT32 | Description |
|-------|-------|-------|-------------|
| 000h | 0000h | ?0000000h | Free Cluster |
| 001h | 0001h | ?0000001h | Reserved Cluster |
| 002h-FEFh | 0002h-FFEFh | 00000002h-?FFFFFEFh | Used Cluster: value points to next cluster |
| FF0h-FF6h | FFF0h-FFF6h | ?FFFFFF0h-?FFFFFF6h | Reserved values |
| FF7h | FFF7h | ?FFFFFF7h | Bad Cluster |
| FF8h-FFFh | FFF8h-FFFFh | ?FFFFFF8h-?FFFFFFFh | Last cluster in file |

**Note:** FAT32 uses only bits [27:0]; the upper 4 bits are usually 0 and should be left untouched.

When accessing the Root Directory for FAT32, the ROM Code just starts from the Root Directory Cluster entry and follows the linked chain to retrieve the clusters.

When the booting file has been found, the ROM buffers each FAT entry corresponding to the file in a sector way. This means each cluster is translated to one or several sectors depending on how many sectors are in a cluster (BPB_SecPerClus). This buffer is used later on by the booting procedure to access the file.

#### 26.1.8.5.8 Pins Used

The list of device pins that are configured by the ROM in the case of MMC boot mode are as follows. Please note that all the pins might not be driven at boot time.

**Table 26-26: Pins Used for MMC0 Boot**

| Signal name | Pin Used in Device |
|-------------|-------------------|
| clk | mmc0_clk |
| cmd | mmc0_cmd |
| dat0 | mmc0_dat0 |
| dat1 | mmc0_dat1 |
| dat2 | mmc0_dat2 |
| dat3 | mmc0_dat3 |

**Table 26-27: Pins Used for MMC1 Boot**

| Signal name | Pin Used in Device |
|-------------|-------------------|
| clk | gpmc_csn1 |
| cmd | gpmc_csn2 |
| dat0 | gpmc_ad0 |
| dat1 | gpmc_ad1 |
| dat2 | gpmc_ad2 |
| dat3 | gpmc_ad3 |

---

### 26.1.8.6 SPI

SPI EEPROMs or SPI flashes have an EEPROM or NOR flash backend and they connect to the device using the serial SPI protocol.

These devices typically operate in three stages: the command stage, the address stage and the data transfer stage. The command is usually an 8 bit value followed by the address (depending on the size of the device) followed by data to be read or written.

Because of the need for fewer pins, these devices are comparatively inexpensive, easy for board layout, and are the devices of choice when cost, complexity and form factor are critical considerations.

#### 26.1.8.6.1 Features

- Supports 12-MHz clock (50% duty cycle)
- Supports only SPI Mode 3 (clock polarity = 1, clock phase = 1)
- Supports only 24-bit addressable EEPROMs
- Supports only 4-pin SPI mode (CS, CLK, Serial Input, Serial Output)
- The boot devices must be connected to chip select 0 and must support the read command (03h)
- The boot image is copied into internal memory and then executed

#### 26.1.8.6.2 Initialization and Detection

The ROM Code initializes the SPI controller and clocks for communicating with the SPI device. The controller is initialized in Mode 3 and the clock is setup to operate at 12 MHz. There is no specific device identification routine prior to the execution by the ROM code to identify whether a boot device is preset or not. If no SPI device is present, the sector read will return only 0xFFFFFFFF and the SPI boot will be treated as failed.

#### 26.1.8.6.3 SPI Read Sector Procedure

The ROM Code reads SPI data from the boot device in 512 byte sectors. For each call to the SPI Read Sector routine, the SPI Read Command (0x03) is sent along with the 24 bit start address of the data to be read. Each Sector = 512bytes and the ROM bootloader will attempt the following:

1. Read Sector 1, Check the address: 0x0
2. Read Sector 2, Check the address: 0x200
3. Read Sector 3, Check the address: 0x400
4. Read Sector 4, Check the address: 0x600

The addresses mentioned above should contain the image size. If the value of the addresses mentioned above is neither 0x0 nor 0xFFFFFFFF, then the boot will proceed else it will move to the next sector. If no image is found or the checking fails sectors, the ROM bootloader will move to the next device.

From the next iteration onwards, a dummy value is transmitted on the master out line and the data is received on the master in line. This needs to be done because SPI protocol always operated in full duplex mode. The dummy value transmitted by the ROM is the Read Command appended to the start address. The data from the boot device is received MSB first.

As the A8 is a little-endian processor, and SPI devices in a big-endian format, this means that while writing to the flash, care needs to be taken to write the image in a big-endian format. This way we can avoid doing the endian conversion at boot time, thus improving boot performance.

#### 26.1.8.6.4 Pins Used

The list of device pins that are configured by the ROM in the case of SPI boot mode are as follows. Please note that all the pins might not be driven at boot time.

**Table 26-28: Pins Used for SPI Boot**

| Signal name | Pin Used in Device |
|-------------|-------------------|
| cs | spi0_cs0 |
| miso | spi0_d0 |
| mosi | spi0_d1 |
| clk | spi0_sclk |

---

### 26.1.8.7 Blocks and Sectors Search Summary

Table 26-29 summarizes numbers of blocks and sectors which are searched during the memory booting from devices requiring image shadowing. NAND is organized with blocks, which are erasable units.

**Table 26-29: Blocks and Sectors Searched on Non-XIP Memories**

| Memory | Maximum Number of Blocks Checked | Number of Sectors Searched |
|--------|----------------------------------|---------------------------|
| NAND | first 4 | Number of sectors in one block⁽¹⁾ |
| SPI, eMMC/eSD and MMC/SD cards (raw mode) | first 4 | 1 |

⁽¹⁾ Depends on NAND geometry

Regarding MMC/SD card booting in FAT mode, the file system area is searched for one file.

---

## 26.1.9 Peripheral Booting

### 26.1.9.1 Overview

The ROM Code can boot from three different peripheral interfaces:
- EMAC: 1000/100/10 Mbps Ethernet, using standard TCP/IP network boot protocols BOOTP and TFTP
- USB: Full-speed, client mode
- UART: 115.2Kbps, 8 bits, no parity, 1 stop bit, no flow control

The purpose of booting from a peripheral interface is to download an boot image from an external host (typically a PC). This booting method is mostly used for programming flash memory and initial flashing during device (e.g. in the case of initial flashing, firmware update or servicing).

### 26.1.9.2 Boot Image Location and Size

The boot image is downloaded directly into internal RAM at the location 0x402F0400 on GP devices. The maximum size of downloaded image is 109 KB.

### 26.1.9.3 Peripheral Boot Procedure Overview

**Figure 26-28 & 26-29: Peripheral Booting Procedure**

```
Peripheral Booting
      │
      ▼
   Initialize peripheral and
   ping the host
      │
      ▼
   ┌─────────────┐
   │Does the host│ No ──→ Boot Failed. Return to
   │respond?     │        framework to try next
   └─────────────┘        device in the device list.
      │ Yes
      │              No
      ▼              ◄────┐
   Start image transfer from  │
   host to OCMC RAM           │
      │                       │
      ▼                       │
   ┌──────────────────┐      │
   │Transfer          │ Yes ─→ Transfer control to
   │completed         │        0x402F0400 (GP)
   │successfully?     │        0x40300000 (HS)
   └──────────────────┘
```

---

### 26.1.9.4 EMAC Boot Procedure

**NOTE:** See *AM335x ARM Cortex-A8 Microprocessors (MPUs) Silicon Errata* (literature number SPRZ360) for limitations of EMAC booting.

#### 26.1.9.4.1 Device Initialization

- EMAC boot uses the CPGMAC port 1 of the device
- Supports connecting to external Ethernet devices using the MII, RMII, RGMII and MDIO pins, based on SYSBOOT pin settings
- In dual-port configurations, the ROM code assumes that the Ethernet PHY with the lowest MDIO address (0-31) is connected to CPGMAC port 1
- Device uses EFUSE registers mac_id0_lo and mac_id0_hi in the control module for Ethernet MAC address of the device
- Device detects if the PHY is alive on the MDIO interface and
  - Reads the STATUS register to check if Ethernet link is active
  - Reads the CONTROL register to detect the auto-negotiated mode of operation
  - Is the mode full-duplex or half duplex
  - Speed of operation. 1000/100/10 Mbps. Link speed is determined by reading the Auto-Negotiation Advertisement and Auto-Negotiation Link Partner Base Page Ability registers in the device (See Section 1.2, *Silicon Revision Functional Differences and Enhancements*, for differences in operation based on AM335x silicon revision.)
  - Waits for five seconds for auto negotiation to complete before timing out
- ROM expects an external 50-MHz reference clock requirement when using RMII

#### 26.1.9.4.2 BOOTP (RFC 951)

The device then proceeds to obtain the IP and Boot information using BOOTP protocol. The device prepares and broadcasts a BOOTP message that has the following information:

- Device MAC address in "chaddr" field – to uniquely identify the device to the server
- "vendor-class-identifier" option number (RFC 1497, RFC 1533). Servers could use this information to identify the device type. The value present is **"AM335x ROM"**. (Note: See Section 1.2, *Silicon Revision Functional Differences and Enhancements*, for differences in operation based on AM335x silicon revision.)
- "Client-identifier" option number 61 (RFC 1497, RFC 1533). This has the ASIC-ID structure which contains additional info for the device.

The device then expects a BOOTP response that provides the following information for the booting to proceed:

- Device IP address from "yiaddr" field
- Subnetmask from extended option 1 (RFC 1497, RFC 1533)
- Gateway IP from extended option number 3 (RFC 1497, RFC 1533) or from "giaddr" field of BOOTP response
- Boot image filename from "file" field
- TFTP server IP address from the "siaddr" field

Timeouts and retries:
- Exponentially increasing timeouts starting from 4s, doubling for each retry.
- 5 retries

#### 26.1.9.4.3 TFTP (RFC 1350)

After a successful BOOTP completion, the device initiates the TFTP download of the boot image into SRAM. The device has the capability to reach a TFTP server within the local subnet or outside, through the gateway.

Timeouts and retries:
- Timeout of 1s to receive a response for the READ request
- 5 retries for the READ request
- Retries are managed by server once data transfer starts (server re-sends a data packet if the ACK was not received within a timeout value)
- Device has a 60s timeout to complete the data transfer, to handle the scenario if the server dies in the middle of a data transfer

#### 26.1.9.4.4 Pins Used

The list of device pins that are configured by the ROM in the case of EMAC boot mode are as follows. Please note that all the pins might not be driven at boot time.

**Table 26-30: Pins Used for EMAC Boot in MII Mode**

| Signal Name | Pin Used in Device | Pin Mux Mode |
|-------------|-------------------|--------------|
| gmii1_col | MII1_COL | 0 |
| gmii1_crs | MII1_CRS | 0 |
| gmii1_rxer | MII1_RX_ER | 0 |
| gmii1_txen | MII1_TX_EN | 0 |
| gmii1_rxdv | MII1_RX_DV | 0 |
| gmii1_txd[3:0] | MII1_TXD[3:0] | 0 |
| gmii1_txclk | MII1_TX_CLK | 0 |
| gmii1_rxclk | MII1_RX_CLK | 0 |
| gmii1_rxd[3:0] | MII1_RXD[3:0] | 0 |
| mdio_data | MDIO | 0 |
| mdio_clk | MDC | 0 |

**Table 26-31: Pins Used for EMAC Boot in RGMII Mode**

| Signal Name | Pin Used in Device | Pin Mux Mode |
|-------------|-------------------|--------------|
| rgmii1_tctl | MII1_TX_EN | 2 |
| rgmii1_rctl | MII1_RX_DV | 2 |
| rgmii1_td[3:0] | MII1_TXD[3:0] | 2 |
| rgmii1_tclk | MII1_TX_CLK | 2 |
| rgmii1_rclk | MII1_RX_CLK | 2 |
| rgmii1_rd[3:0] | MII1_RXD[3:0] | 2 |
| mdio_data | MDIO | 0 |
| mdio_clk | MDC | 0 |

**Table 26-32: Pins Used for EMAC Boot in RMII Mode**

| Signal Name | Pin Used in Device | Pin Mux Mode |
|-------------|-------------------|--------------|
| rmii1_crs_dv | MII1_CRS | 1 |
| rmii1_rxer | MII1_RX_ER | 1 |
| rmii1_txen | MII1_TX_EN | 1 |
| rmii1_txd[1:0] | MII1_TXD[1:0] | 1 |
| rmii1_rxd[1:0] | MII1_RXD[1:0] | 1 |
| rmii1_refclk | RMII1_REF_CLK (Driven by External 50-MHz Source) | 0 |
| mdio_data | MDIO | 0 |
| mdio_clk | MDC | 0 |

#### 26.1.9.4.5 SYSBOOT Pins

Some of the SYSBOOT pins have special meanings when EMAC boot is selected.

**Table 26-33: Ethernet PHY Mode Selection**

| SYSBOOT[7:6] | PHY Mode |
|--------------|----------|
| 00b | MII |
| 01b | RMII |
| 10b | Reserved |
| 11b | RGMII without internal delay |

---

### 26.1.9.5 UART Boot Procedure

#### 26.1.9.5.1 Device Initialization

- UART boot uses UART0
- UART0 is configured to run at 115200 baud, 8-bits, no parity, 1 stop bit and no flow control

#### 26.1.9.5.2 Boot Image Download

- UART boot uses ancient protocol to receive the boot image
- Utilities like hyperterm, teraterm, minicom can be used on the PC side to download the boot image to the board
- With x-modem packet size of 1K throughout is roughly about 4KBytes/Sec
- The ROM code will ping the host 10 times in 3s to start x-modem transfer. If host does not respond, UART boot will timeout
- Once the transfer has started, if the host does not send any packet for 3s, UART boot will time out
- If more than one consecutive bytes of data in the packet is more than 2ms, the host is requested to re-transmit the entire packet again
- Error checking using the CRC-16 support in x-modem. If an error is detected, the host is requested to re-transmit the packet again

#### 26.1.9.5.3 Pins Used

The list of device pins that are configured by the ROM in the case of UART boot mode are as follows.

**Note:** All the pins might not be driven at boot time.

**Table 26-34: Pins Used for UART Boot**

| Signal name | Pin Used in Device |
|-------------|-------------------|
| rx | uart0_rxd |
| tx | uart0_txd |

---

### 26.1.9.6 USB Boot Procedure

**NOTE:** See *AM335x ARM Cortex-A8 Microprocessors (MPUs) Silicon Errata* (literature number SPRZ360) for limitations of USB booting.

#### 26.1.9.6.1 Device Initialization

The ROM code supports booting from the USB interface under the following conditions:
- When the high-speed USB OTG (USBOTGHS) IP is used through USB0 interface
- USB operates in full-speed, client mode
- USB will operate only in device-powered mode
- Integrated transceiver (through UTMI)
- The enumeration default timeout is 3s (USB timeout)
- ROM code uses the default value of DATAPOLARITY

Even though using an OTG capable hardware, the ROM Code does not handle any OTG specific feature.

#### 26.1.9.6.1.1 Overview

In case of boot from USB is chosen by the SYSBOOT pin configuration:
- The USBOTGHS hardware and PRCM clocks are configured for UTMI mode
- The ROM Code continues with the USB procedure only if the USB cable is detected present (i.e. VBUS is detected at transceiver level and communicated as such through the UTPI traffic). If not, the initialization procedure is aborted
- The USB code implements the RNDIS class driver
- From a user's perspective, USB boot is indistinguishable from Ethernet boot. Refer to Section 26.1.9.4.2 for information on the BOOTP protocol
- The USB initialization procedure is shown in Figure 26-30

**Figure 26-30: USB Initialization Procedure**

```
USB Initialization
      │
      ▼
   Internal USB driver setup
      │
      ▼
   I/O setup for UTMI mode
      │
      ▼
   ┌─────────────────┐
   │USB cable        │ No ──→ Failed
   │attached?        │
   └─────────────────┘
      │ Yes
      ▼
   USB Connect
```

#### 26.1.9.6.1.2 Enumeration Descriptors

The device descriptor parameters which are used during enumeration are listed in Table 26-35. The default Vendor ID and Product ID can be automatically overridden by the customer by programming the values that are used to store these values.

**Table 26-35: Customized Descriptor Parameters**

| Parameter | Size [bytes] | TI Default Values |
|-----------|--------------|-------------------|
| Device ID code | 2 | 0000h |
| Device Class | 1 | 02h |
| Device Sub-Class | 1 | 00h |
| Device Protocol | 1 | 00h |
| Manufacturer | String | "Texas Instruments" |
| Product⁽¹⁾ | String | "AM335x USB" |
| Serial number | 1 | 0h |

⁽¹⁾ See Section 1.2, *Silicon Revision Functional Differences and Enhancements*, for differences in operation based on AM335x silicon revision.

#### 26.1.9.6.2 Image Download Procedure

- The device supports USB client boot only
- The ROM implements as RNDIS class driver, so the device enumerates as an ethernet port
- Standard RNDIS drivers present on Linux and Windows are picked up during the enumeration. No special drivers need to be installed
- Once the enumeration is complete, the customer can download the boot image using any standard TFTP server application

**Figure 26-31: Image Transfer for USB Boot**

```
HOST PC                          Device
(Windows/Linux)                  ROM Code
     │                                │
     │                                │
TFTP Application                TFTP Client Boot
     │                                │
RNDIS Driver                    RNDIS Class Driver
     │                                │
USB HW                          USB Low level Driver
     │                                │
     │◄──────────────────────────────►│
          Ethernet emulation over USB cable
```

#### 26.1.9.6.3 Pins Used

The list of the device pins that are configured by the ROM in the case of USB boot mode are as follows. Please note that all the pins might not be driven at boot time.

**Table 26-36: Pins Used for USB Boot**

| Signal Name | Pin Used in Device |
|-------------|-------------------|
| USB0_DM | USB0_DM |
| USB0_DP | USB0_DP |
| USB0_ID | USB0_ID |
| USB0_VBUS | USB0_VBUS |

---

### 26.1.9.7 ASIC ID structure

The ASIC ID size is 58 bytes for UART and 81 bytes for others. The fields of this structure are unused. This structure is included purely for legacy purposes.

---

## 26.1.10 Image Format

### 26.1.10.1 Overview

All preceding sections describe how the ROM Code searches and detects a boot image from a memory or a peripheral device type. This section describes the format of the boot image.

A boot image is basically made out of 2 major parts:
- The software to execute
- A header containing the destination address and size of the image for non XIP memory devices

The mandatory section of a boot image contains the software which will be loaded into the memory and executed. An overview of the image formats is shown in Figure 26-32:

**Figure 26-32: Image Formats on GP Devices**

```
a) GP device                    b) GP device
   non-XIP Memory Booting          Peripheral Booting and XIP Memory Booting

┌─────────────────┐           ┌─────────────────┐
│ GP Image Header │           │                 │
├─────────────────┤           │                 │
│                 │           │ Initial Software│
│ Initial Software│           │                 │
│                 │           │                 │
└─────────────────┘           └─────────────────┘
```

**Figure 26-33: Image Formats on GP and HS Devices**

```
a) GP device                    b) GP device
   non-XIP Memory Booting          Peripheral Booting and XIP Memory Booting

┌─────────────────┐           ┌─────────────────┐           Legend:
│ GP Image Header │           │                 │           ┌───┐
├─────────────────┤           │                 │           │   │ mandatory
│                 │           │ Initial Software│           └───┘
│ Initial Software│           │                 │           ┌ - ┐
│                 │           │                 │           │   │ optional
└─────────────────┘           └─────────────────┘           └ - ┘
                                                            *Must fit info one
                                                             512 bytes sector
            c) HS device
               Memory and Peripheral Booting

            ┌─────────────────┐
            │      TOC        │
            ├─────────────────┤
            │Public Keys      │
            │  Certificate    │
            ├─────────────────┤
            │      PPA        │
            ├ - - - - - - - - ┤
            │ R&D Certificate │
            ├ - - - - - - - - ┤
            │Initial Software │
            │  Certificate    │
            ├─────────────────┤
            │ Initial Software│
            └─────────────────┘
```

**a) GP Non-XIP Memory Booting**

Used for memories which require shadowing (e.g. MMC). Image must begin with a GP header which contains information on image size and destination address.

**b) GP Peripheral Booting and XIP Memory Booting**

When memory device is of XIP type (e.g. NOR) the GP header is not needed and the image can contain code for direct execution. The same image format is used for peripheral booting (where the code is transferred to internal RAM).

### 26.1.10.2 Image Format for GP Device

For a **GP Device** there is no security involved and therefore neither keys nor certificates are needed in the boot image.

When the booting memory device is non-XIP (e.g. MMC) the image must contain a small header (referred to as GP header) with the size of the software to load and the destination address where to store it.

The GP header is not needed when booting from an XIP memory device (e.g. NOR) or in case of peripheral booting. In this case, the peripheral or memory booting image starts directly with executable code.

**Table 26-37: GP Device Image Format**

| Field | Non-XIP Device Offset | XIP Device Offset | Size[bytes] | Description |
|-------|-----------------------|-------------------|-------------|-------------|
| Size | 0000h | - | 4 | Size of the image |
| Destination | 0004h | - | 4 | Address where to store the image for entry |
| Image | 0008h | 0000h | x | Executable code |

Note: The "Destination" address field stands for both:
- Target address for the image copy from the non-XIP storage to the target XIP location (e.g., internal RAM or SDRAM)
- Entry point for image code

In other words the user must take care to locate the code entry point to the target address for image copy.

---

## 26.1.11 Table of Contents

The Table of Contents (TOC) is a header needed only in GP devices while using MMC RAW mode. This must not be confused with the TOC used in HS devices. The TOC is 512 bytes long and consists of a maximum of 2 TOC items of 32 bytes located one after the other. The second TOC item cannot be filled by FFh. Each TOC item contains information required by the ROM Code to find a valid image in RAW mode, as illustrated in Table 26-38. To detect RAW mode, the ROM also needs the magic values mentioned in Table 26-39. Other than the TOC item fields and magic values, all the other bytes in the 512-byte TOC must be zero.

**Table 26-38: The TOC Item Fields**

| Offset | Field | Size (bytes) | Description |
|--------|-------|--------------|-------------|
| 0x00h | Start | 4 | 0x00000040 |
| 0x04h | Size | 4 | 0x0000000C |
| 0x08h | Flags | 4 | Not used; should be zero |
| 0x0Ch | Align | 4 | Not used; should be zero |
| 0x10h | Load Address | 4 | Not used; should be zero |
| 0x14h | Filename | 12 | 12 character long name of sub image, including the zero ('\0') terminator. The ASCII representation is "CHSETTINGS." |

**Table 26-39: Magic Values for MMC RAW Mode**

| Offset | Value |
|--------|-------|
| 40h | 0xC0C0C0C1 |
| 44h | 0x00000100 |

The ROM Code recognizes the TOC based on the filename described in Table 26-40.

**Table 26-40: Filenames in TOC for GP Device**

| Filename | Description |
|----------|-------------|
| CHSETTINGS | Magic string used by ROM |

---

## 26.1.12 Authentication and Code Execution

### 26.1.12.1 Overview

One of the early steps of the Public ROM Code execution is to search for a boot image from the requested medium (configured by the SYSBOOT pins) and copy it to RAM if needed. If the device is of GP type and boot interface is non-XIP then the image is simply copied to the provided destination address (part of external RAM) and then executed. If the boot interface is of XIP type then the image copy is not needed and execution is directly given to the XIP memory.

### 26.1.12.2 Execution

The image is executed at the time the ROM Code performs the branch to the first executable instruction inside the image. For a GP Device in Peripheral booting, the execution address is the first address inside the GP header. The branch is performed in public ARM supervisor mode. The A8 register points to the Booting Parameters structure which contains various information about the booting execution. Table 26-41 details this structure.

**Table 26-41: Booting Parameters Structure**

| Offset | Field | Size (bytes) | Description |
|--------|-------|--------------|-------------|
| 00h | Reserved | 4 | Reserved |
| 04h | Memory booting device descriptor address | 4 | Pointer to the memory device descriptor that has been used during the memory booting |
| 08h | Current Booting Device | 1 | Code of device used for booting:<br>00h – void, no device<br>01h – XIP MUX1 memory<br>02h – XIP/WAIT MUX 1 (wait monitoring on)<br>03h – XIP MUX2 memory<br>04h – XIP/WAIT MUX 2 (wait monitoring on)<br>05h – NAND<br>06h – NAND with I2C<br>08h – MMC/SD port 0<br>09h – MMC/SD port 1<br>9h – SPI<br>41h – UART0<br>44h – USB<br>45h – CPGMAC0 |
| 09h | Reset Reason | 1 | Current reset reason bit mask<br>[bit=1 event present]<br>[0] – Power-on (cold) reset<br>[1] – Global warm software reset<br>[2] – Reserved<br>[3] – Reserved security violation reset<br>[4] – WDT1 timer reset<br>[5] – Global external warm reset secure watchdog reset<br>Other bits – Reserved<br>(Note: ROM code does not clear any of these bits. |
| 0Ah | Reserved | 1 | Reserved |

⁽¹⁾ More detailed information is found in each memory's booting description.

---

## 26.1.13 Wakeup

### 26.1.13.1 Overview

The device supports a comprehensive set of low-powered states to meet aggressive power budget requirements. The different low power modes supported, from the lowest power consumption state to the highest power consumption state, include:

- RTC Only
- DeepSleep 0
- DeepSleep 1
- Standby
- Active

Of these states, the ROM code is involved only in the first three, as the A8 registers (particularly the PC) are preserved in all the other states. So for these modes, on wake up, execution will resume from the next instruction following the WFI.

In the RTC only mode, the ROM code involvement is trivial. A wakeup from the RTC only mode, from the ROM perspective, is indistinguishable from a power on reset. In DeepSleep 0 and DeepSleep 1 state, the ROM code should detect whether wakeup has occurred and branch to a user-defined return address, rather than perform a full boot.

### 26.1.13.2 Wakeup Booting by ROM Code

In this device, when the A8 is in OFF mode, execution begins from the reset vector on wakeup. As the reset vector lies in ROM, the ROM code entity will take control of the A8 on a wakeup.

It must be noted here that in the device, in all the modes other than RTC-only, the L3 OCMC RAM is held in retention. This is a fundamental assumption of the ROM code. Because the contents of this RAM is not lost in these power-down modes, it is possible to return to a location in this memory.

This does away with the need of the ROM having to restore PLL and EMIF settings, which would have been needed if the ROM had to put A8 image from address, as DRAM is held in self refresh. The job of dialing up the PLLs and restoring EMIF and other peripheral register values is the responsibility of the user code. The recommendation is that such restoration code be placed in the OCMC RAM so that wakeup procedure is compatible between secure and non-secure devices.

In the past, the restore complex L4 and PLL register programming code in the ROM has made wakeup debugging very complicated. This has also traditionally been a source of many bugs, as the wakeup procedures are complicated and difficult to test exhaustively in pre-silicon.

The current architecture does away with these problems. The flow in the ROM on wakeup is kept simple and minimal. It only involves identifying that the reset reason is a Wakeup, and then branching to a return address, rather than proceeding with a full boot. This also helps in improving the time required to wakeup a system that is in Deep Sleep.

---

**Figure 26-34: Wakeup Booting by ROM**

```
Rom Init
      │
      ▼
   ┌─────────────────┐
   │Is the Reset     │ Yes ──→ Read the return address
   │reason for       │         from IPO register
   │Wakeup?          │         (0x44e11a28 [RTC])
   └─────────────────┘               │
      │ No                           ▼
      ▼                          ┌─────────────────┐
   Read SYSBOOT pins and         │Is the Return    │
   proceed with                  │address valid?   │
   regular ROM boot              └─────────────────┘
                                      │
                                      │ No
                                      ▼
                                 ┌─────────────────┐
                                 │  Dead Loop      │
                                 │(wait for        │
                                 │WatchDog)        │
                                 └─────────────────┘
                                      │
                                      │ Yes
                                      ▼
                                 Branch to the Return
                                 Address
```

**Figure 26-35: Wakeup Booting by ROM (Full Flow)**

```
Secure Rom Init
      │
      ▼
   Public Rom Init
      │
      ▼
   ┌─────────────────┐
   │Is the Reset     │ Yes ──→ Read the return address
   │reason for       │         from IPO register
   │Wakeup?          │         (0x44e11a28 [RTC])
   └─────────────────┘               │
      │ No                           ▼
      ▼                          ┌─────────────────┐
   Read SYSBOOT pins and         │Is the Return    │
   proceed with                  │address valid?   │
   regular ROM boot              └─────────────────┘
                                      │
                                      │ No
                                      ▼
                                 ┌─────────────────┐
                                 │  Dead Loop      │
                                 │(wait for        │
                                 │WatchDog)        │
                                 └─────────────────┘
                                      │
                                      │ Yes
                                      ▼
                                 Branch to the Return
                                 Address
```

---

## 26.1.14 Tracing

Tracing in the Public ROM Code includes three 32-bit vectors for which each bit corresponds to a particular "way point" in the ROM Code execution sequence (see Table 26-4). Tracing vectors are initialized at the very beginning of the startup phase and updated all along the boot process.

There are two sets of tracing vectors. The first set is the current trace information (after cold or warm reset). The second set holds a copy of trace vectors collected at the first ROM Code run after cold reset. As a consequence after a warm reset it is possible to have visibility on the boot scenario that occurred during cold reset.

**Table 26-42: Tracing Vectors**

| Trace vector | Bit No. | Group | Meaning |
|--------------|---------|-------|---------|
| 1 | 0 | Memory Boot | Memory booting device MMC/SD1 or SPI0 |
| 1 | 1 | General | Entered main function |
| 1 | 2 | General | Running after the cold reset |
| 1 | 3 | Boot | Main booting routine entered |
| 1 | 4 | Memory Boot | Memory booting started |
| 1 | 5 | Peripheral Boot | Peripheral booting started |
| 1 | 6 | Boot | Booting loop reached last device |
| 1 | 7 | Boot | GP header found |
| 1 | 8 | Boot | Reserved |
| 1 | 9 | Boot | Reserved |
| 1 | 10 | Peripheral Boot | Reserved |
| 1 | 11 | Peripheral Boot | Reserved |
| 1 | 12 | Peripheral Boot | Device initialized |
| 1 | 13 | Peripheral Boot | ASIC Id sent |
| 1 | 14 | Peripheral Boot | Image received |
| 1 | 15 | Peripheral Boot | Peripheral booting failed |
| 1 | 16 | Peripheral Boot | Booting Message not received (timeout) |
| 1 | 17 | Peripheral Boot | Image size not received(timeout) |
| 1 | 18 | Peripheral Boot | Image not received (timeout) |
| 1 | 19 | Reserved | Reserved |
| 1 | 20 | Configuration Header | CHSETTINGS found |
| 1 | 21 | Configuration Header | CHSETTINGS executed |
| 1 | 22 | Configuration Header | CHRAM executed |
| 1 | 23 | Configuration Header | CHFLASH executed |
| 1 | 24 | Configuration Header | CHMMCSD clocks executed |
| 1 | 25 | Configuration Header | CHMMCSD bus width executed |
| 1 | 26 | Reserved | Reserved |
| 1 | 27 | Reserved | Reserved |
| 1 | 28 | Reserved | Reserved |
| 1 | 29 | Reserved | Reserved |
| 1 | 30 | Reserved | Reserved |
| 1 | 31 | Reserved | Reserved |
| 2 | 0 | Companion chip | Reserved |
| 2 | 1 | Companion chip | Reserved |
| 2 | 2 | Companion chip | Reserved |
| 2 | 3 | Companion chip | Reserved |
| 2 | 4 | USB | USB connect |
| 2 | 5 | USB | USB configured state |
| 2 | 6 | USB | USB VBUS valid |
| 2 | 7 | USB | USB session valid |
| 2 | 8 | Reserved | Reserved |
| 2 | 9 | Reserved | Reserved |
| 2 | 10 | Reserved | Reserved |
| 2 | 11 | Reserved | Reserved |
| 2 | 12 | Memory Boot | Memory booting trial 0 |
| 2 | 13 | Memory Boot | Memory booting trial 1 |
| 2 | 14 | Memory Boot | Memory booting trial 2 |
| 2 | 15 | Memory Boot | Memory booting trial 3 |
| 2 | 16 | Memory Boot | Execute GP image |
| 2 | 17 | Peripheral Boot | Start authentication of peripheral boot image |
| 2 | 18 | Memory & Peripheral Boot | Start image authentication |
| 2 | 19 | Memory & Peripheral Boot | Image authentication failed |
| 2 | 20 | Memory & Peripheral Boot | Reserved |
| 2 | 21 | Memory & Peripheral Boot | Reserved |
| 2 | 22 | Memory & Peripheral Boot | Reserved |
| 2 | 23 | Memory & Peripheral Boot | Reserved |
| 2 | 24 | Memory & Peripheral Boot | Reserved |
| 2 | 25 | Memory & Peripheral Boot | Reserved |
| 2 | 26 | Memory & Peripheral Boot | Reserved |
| 2 | 27 | Memory & Peripheral Boot | Reserved |
| 2 | 28 | Memory & Peripheral Boot | Authentication procedure failed |
| 2 | 29 | Reserved | Reserved |
| 2 | 30 | Reserved | Reserved |
| 2 | 31 | Reserved | Reserved |
| 3 | 0 | Memory Boot | Memory booting device NULL |
| 3 | 1 | Memory Boot | Memory booting device XIP (MUX2) |
| 3 | 2 | Memory Boot | Memory booting device XIP w/WAIT (MUX2) |
| 3 | 3 | Memory Boot | Memory booting device XIP (MUX1) |
| 3 | 4 | Memory Boot | Memory booting device XIP w/ WAIT (MUX1) |
| 3 | 5 | Memory Boot | Memory booting device NAND |
| 3 | 6 | Reserved | Reserved |
| 3 | 7 | Memory Boot | Memory booting device MMC/SD1 |
| 3 | 8 | Reserved | Reserved |
| 3 | 9 | Reserved | Reserved |
| 3 | 10 | Memory Boot | Memory booting device NAND_I2C |
| 3 | 11 | Reserved | Reserved |
| 3 | 12 | Memory Boot | Memory booting device MMC0 |
| 3 | 13 | Reserved | Reserved |
| 3 | 14 | Reserved | Reserved |
| 3 | 15 | Reserved | Reserved |
| 3 | 16 | Reserved | Peripheral booting device UART0 |
| 3 | 17 | Reserved | Reserved |
| 3 | 18 | Reserved | Reserved |
| 3 | 19 | Reserved | Reserved |
| 3 | 20 | Peripheral Boot | Peripheral booting device USB |
| 3 | 21 | Reserved | Reserved |
| 3 | 22 | Peripheral Boot | Peripheral booting device CPGMAC0 |
| 3 | 23 | Reserved | Reserved |
| 3 | 24 | Reserved | Peripheral booting device NULL |
| 3 | 25 | Reserved | Reserved |
| 3 | 26 | Reserved | Reserved |
| 3 | 27 | Reserved | Reserved |
| 3 | 28 | Reserved | Reserved |
| 3 | 29 | Reserved | Reserved |
| 3 | 30 | Reserved | Reserved |
| 3 | 31 | Reserved | Reserved |

---

## Summary

This comprehensive document covers the complete AM335x ROM Code boot process, including:

### Key Features Covered:

1. **Boot ROM Architecture** - Three-layer design (High-level, Drivers, HAL)

2. **Device Types** - GP (General Purpose) and HS (High Secure) devices

3. **Boot Sources**:
   - Memory devices: XIP (NOR), NAND, MMC/SD, SPI-EEPROM
   - Peripheral interfaces: UART, USB, Ethernet (EMAC)

4. **Boot Flow**:
   - SYSBOOT pin configuration for boot sequence
   - Device detection and initialization
   - Image shadowing for non-XIP devices
   - Authentication for HS devices
   - Image execution

5. **Memory Booting Details**:
   - XIP Memory (NOR flash) - Direct execution
   - NAND - With ECC correction (BCH8/16), ONFI support
   - MMC/SD - RAW mode and FAT filesystem support
   - SPI - Serial EEPROM boot

6. **Peripheral Booting**:
   - EMAC - BOOTP/TFTP protocols, multiple PHY modes
   - UART - X-modem protocol at 115200 baud
   - USB - RNDIS class driver implementation

7. **Advanced Features**:
   - Image formats for GP and HS devices
   - Table of Contents (TOC) for MMC RAW mode
   - Wakeup booting from low-power states
   - Tracing vectors for debugging

8. **Technical Specifications**:
   - Memory maps and address spaces
   - Clock configurations
   - Pin multiplexing for each boot mode
   - Timing parameters for various interfaces

This document serves as a complete reference for understanding the AM335x boot process and can be used for:
- System design and hardware configuration
- Boot sequence debugging
- Custom bootloader development
- Training and educational purposes

---

**End of AM335x ROM Code Boot Documentation**