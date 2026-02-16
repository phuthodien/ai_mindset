# CLAUDE.md — AI Control Panel

> File này là entry point cho AI. Đọc file này TRƯỚC KHI đọc bất kỳ thứ gì khác trong project.

## Project Overview

- **Tên**: ai_mindset
- **Mục đích**: Project mẫu (teaching example) minh họa quy trình phát triển phần mềm theo triết lý AI-first. Trọng tâm là **phương pháp làm việc với AI**, không phải bất kỳ tech stack cụ thể nào.
- **Ngôn ngữ tài liệu**: Tiếng Việt

Các folder trong `examples/` là sản phẩm minh họa của quy trình AI-first:
- Tạo tài liệu training cho AI (hw-docs, Windows Internals)
- Gen code thông qua AI đã được train (eBPF EDR agent, GPIO driver)

## Thứ tự đọc (Learning Order)

Khi tiếp cận project này, AI PHẢI đọc theo thứ tự:

1. `CLAUDE.md` (file này) — rules, constraints, context
2. `examples/` — ví dụ minh họa quy trình AI-first
3. `conversations/` — lịch sử thảo luận (nếu cần thêm context)

> **Nguyên tắc**: Code là source of truth. Khi document và code mâu thuẫn → tin code.

## Rules

### Quy tắc chung

- **Explicit > Implicit**: Không đoán. Nếu không rõ, hỏi lại.
- **Rationale matters**: Mọi quyết định phải kèm lý do (WHY, không chỉ WHAT).
- **Text-first**: Dùng Markdown, Mermaid cho tài liệu. Không dùng binary formats.
- **Không tự ý thêm feature** ngoài scope được yêu cầu.
- **Commit messages**: Viết bằng tiếng Việt.

### Quy tắc code (C / Kernel)

Áp dụng khi làm việc với code trong `examples/`:

- Tuân thủ [Linux Kernel Coding Style](https://www.kernel.org/doc/html/latest/process/coding-style.html).
- Indent bằng TAB (không dùng spaces).
- Tên biến, hàm: `snake_case`.
- Tên macro: `UPPER_SNAKE_CASE`.
- Mỗi function tối đa ~50 dòng. Nếu dài hơn, tách ra.
- Comment giải thích WHY, không giải thích WHAT (code phải tự giải thích WHAT).
- Luôn kiểm tra return value của các hàm có thể fail (kmalloc, copy_from_user, ...).

### Constraints đặc thù System Programming

AI **KHÔNG THỂ** compile hay chạy kernel code. Workflow bắt buộc:

1. **Human** chạy/debug trên máy thật → cung cấp output (dmesg, stack trace, error log)
2. **AI** phân tích output → đề xuất fix/giải pháp
3. **Human** verify và apply

Khi cần debug, AI phải yêu cầu human cung cấp:
- `dmesg` output
- Stack trace (nếu có)
- Steps to reproduce
- Kernel version (`uname -r`)

## Cấu trúc Project

```
ai_mindset/
├── .gitignore
├── CLAUDE.md                 # AI entry point (file này)
├── conversations/            # AI chat logs
└── examples/                 # Ví dụ minh họa quy trình AI-first
    ├── beaglebone-black/     # Training AI về hardware BBB
    │   ├── hw-docs/          # Tài liệu phần cứng AM335x + Device Tree
    │   └── src/              # Code gen từ AI (GPIO driver)
    ├── edr_agent/            # Gen code eBPF EDR qua AI
    │   ├── docs/             # Tài liệu thiết kế (architecture, API, ADRs)
    │   ├── src/              # Source code (kernel module + user-space agent)
    │   └── tests/            # Test cases
    └── windows_os/           # Training AI về Windows Internals
```

## Conversation Logs

AI PHẢI lưu lại cuộc hội thoại vào `conversations/`.

- **Đặt tên file**: `YYYY-MM-DD_mô-tả-ngắn.md`
- **Thời điểm lưu** (AI tự quyết định, tối thiểu ở các thời điểm sau):
  - Cuối session (trước khi kết thúc)
  - Khi có quyết định quan trọng (architecture, thay đổi rules)
  - Khi chuyển sang phase mới trong workflow
- **Nội dung**: Tóm tắt bối cảnh, các quyết định, lý do, và commits liên quan
- **Lưu ý**: AI chỉ tạo/cập nhật file. Việc commit conversation logs do human tự thực hiện.

## Workflow AI-First

1. **Brainstorm**: Thảo luận requirement với AI → lưu vào `conversations/`
2. **Vibe coding**: Prototype nhanh với AI (chất lượng thấp, tốc độ cao)
3. **Review**: Demo + review sequence diagram
4. **Production coding**: Code lại chuẩn — developer PHẢI hiểu từng dòng
5. **Testing**: Bàn giao docs + conversation logs cho tester
