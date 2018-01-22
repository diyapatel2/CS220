.intel_syntax noprefix
.text
.global rotate


rotate:
	push rbp
	mov rbp, rsp
	cmp rdx, 1
	je shift_left
	shr rcx, cl
	mov rcx, rsi
	ror rdi, cl
	mov rax, rdi
	pop rbp
	ret
	
shift_left:
	dec rdx
	mov rcx, rsi
	xor rcx, rdx
	sub rcx, rdx
	mov rax, rdi
	rol rax, cl
	pop rbp
	ret
