.intel_syntax noprefix
.text
.global reverse_asm

reverse_asm:
	#Put ebx on the stack 
	push ebx
	#headptr = nextptr = new_headptr = NULL
	#We use eax as the scratch register
	mov eax, 0x0
	mov ebx, eax #headptr
	mov ecx, eax #nextptr
	mov edx, eax #new_headptr


	#This is equiv to if(head == NULL) return NULL;
	mov eax, [esp + 0x8]
	cmp eax, 0
	je null_ret

	add eax, [esp + 0xC] 
	#ebx is headptr
	mov ebx, eax

while_start:
	#while (headptr)
	cmp ebx, 0x0
	je while_done

	#nextptr =( void *)(*((unsigned long *)headptr));
	mov ecx, [ebx]

	# *(unsigned long *)headptr = (unsigned long) new_headptr;
	mov [ebx], edx

	# new_headptr = headptr
	mov edx, ebx

	#headptr = nextptr
	mov ebx, ecx
	#next iteration
	jmp while_start

while_done:
	mov eax, edx
	sub eax, [esp + 0xC]
	

null_ret:
	pop ebx
	ret 
