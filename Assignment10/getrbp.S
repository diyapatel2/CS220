.intel_syntax noprefix
.text
.global getrbp

getrbp:
	mov rax, rbp
	ret
