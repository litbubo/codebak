	.file	"pause.c"
	.text
	.section	.rodata
.LC0:
	.string	"int \344\277\241\345\217\267\346\235\245\344\272\206\345\211\215\n"
.LC1:
	.string	"int \344\277\241\345\217\267\346\235\245\344\272\206\345\220\216\n"
	.text
	.globl	working_int
	.type	working_int, @function
working_int:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	stdout(%rip), %rax
	movq	%rax, %rcx
	movl	$20, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rdi
	call	fwrite@PLT
	movl	$5, %edi
	call	sleep@PLT
	movq	stdout(%rip), %rax
	movq	%rax, %rcx
	movl	$20, %edx
	movl	$1, %esi
	leaq	.LC1(%rip), %rdi
	call	fwrite@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	working_int, .-working_int
	.section	.rodata
.LC2:
	.string	"qiut \344\277\241\345\217\267\346\235\245\344\272\206\345\211\215\n"
.LC3:
	.string	"qiut \344\277\241\345\217\267\346\235\245\344\272\206\345\220\216\n"
	.text
	.globl	working_qiut
	.type	working_qiut, @function
working_qiut:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	stdout(%rip), %rax
	movq	%rax, %rcx
	movl	$21, %edx
	movl	$1, %esi
	leaq	.LC2(%rip), %rdi
	call	fwrite@PLT
	movl	$5, %edi
	call	sleep@PLT
	movq	stdout(%rip), %rax
	movq	%rax, %rcx
	movl	$21, %edx
	movl	$1, %esi
	leaq	.LC3(%rip), %rdi
	call	fwrite@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	working_qiut, .-working_qiut
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	working_int(%rip), %rax
	movq	%rax, -160(%rbp)
	movl	$0, -24(%rbp)
	leaq	-160(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	sigfillset@PLT
	leaq	-160(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$2, %edi
	call	sigaction@PLT
	leaq	working_qiut(%rip), %rax
	movq	%rax, -160(%rbp)
	movl	$0, -24(%rbp)
	leaq	-160(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	sigfillset@PLT
	leaq	-160(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$3, %edi
	call	sigaction@PLT
.L4:
	jmp	.L4
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
