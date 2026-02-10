# 2026-02-05 — Khởi tạo project và CLAUDE.md

## Người tham gia
- **Phú** (Developer, Vinalinux)
- **Claude** (AI Assistant)

## Bối cảnh

Phú muốn xây dựng một example project theo hướng AI-first development. Project dùng C/Linux Kernel Module làm tech stack, mục đích là teaching example.

## Các quyết định

### 1. Tạo CLAUDE.md
- **Quyết định**: Tạo CLAUDE.md làm AI entry point — file đầu tiên AI đọc khi vào project.
- **Nội dung chính**:
  - Project overview (tech stack, mục đích)
  - Learning order (thứ tự AI đọc files)
  - Rules: Linux Kernel Coding Style, explicit > implicit, rationale matters
  - Constraints: AI không chạy được kernel code → workflow Human↔AI
  - Cấu trúc project
  - Workflow AI-first 5 bước

### 2. Ngôn ngữ
- **Tài liệu**: Tiếng Việt
- **Commit messages**: Tiếng Việt (rule chung, ghi trong CLAUDE.md)

### 3. Quản lý conversation logs
- **Quyết định**: Lưu vào `conversations/` trong repo
- **Đặt tên**: `YYYY-MM-DD_mô-tả-ngắn.md`
- **Thời điểm lưu**: AI tự quyết định (cuối session, quyết định quan trọng, chuyển phase)
- **Commit**: Do human tự thực hiện, AI không commit conversation logs

### 4. Tách architecture.md
- **Lý do**: File gốc ~1400 dòng, trộn lẫn nhiều concerns
- **Quyết định**: Tách thành 8 files theo concern
- **Nguyên tắc**: architecture.md trả lời "Hệ thống gồm những gì, chúng kết nối ra sao"

### 5. Design review trước Vibe coding
- **Thực hiện**: Đọc toàn bộ 8 docs files, đánh giá tính đúng đắn
- **Phát hiện CRITICAL**:
  - Go interfaces trong C project (api.md) → **đã fix**: chuyển sang C function pointers
  - IPv6 dùng `__u32` thay vì 128-bit (data-format.md) → **đã fix**: dùng union v4/v6
  - Fixed-size buffers quá nhỏ (256 bytes cho path, 1024 cho argv) → **đã fix**: tăng lên PATH_MAX_LEN=4096, ARGV_MAX_LEN=4096
- **Phát hiện HIGH**: Offline buffer vô nghĩa khi rules ở server, CPU constraint vs all-events mâu thuẫn

### 6. Phân pha — bỏ server communication ở Phase 1
- **Lý do**: Giảm complexity, focus vào core functionality
- **Phase 1 scope**: Kernel hooks → Sensor → Normalizer → Console output (stdout)
- **Deferred sang Phase 2+**: gRPC, transport layer, offline buffer, server communication
- **Impact**: Loại bỏ phần lớn issues từ design review (AD-002, AD-003 tạm không cần)

## Commits trong session này
- `ce9f28f` — Thêm CLAUDE.md làm entry point cho AI trong quy trình AI-first
