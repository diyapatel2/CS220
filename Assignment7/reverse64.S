.intel_syntax noprefix
.text
.global reverse_asm_64

reverse_asm_64:
	pushq rdi
	pushq rsi
	pushq rbx
	movq rax, 0x0
	movq rbx, rax
	movq rcx, rax
	movq rdx, rax 
	
	movq rax, rdi
	cmp rax, 0 
	je null_ret

	addq rax, rsi
	movq rbx, rax

while_start:
	cmp rbx, 0x0
	je while_done

	movq rcx, [rbx]
	movq [rbx], rdx
	movq rdx, rbx
	movq rbx, rcx
	jmp while_start

while_done:
	movq rax, rdx
	subq rax, rsi

null_ret:	
	popq rbx
	popq rsi
	popq rdi
	retq
