.intel_syntax noprefix
.text
.global toggle_bit

toggle_bit:
	mov ecx, esi
	mov esi, 1 
	shl rsi, cl
	xor rdi, rsi #xor the new mask and n 
	mov rax, rdi #mov into return register
	ret	
	
