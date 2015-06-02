	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	xorl	%eax, %eax
	movl	$40, %ecx
	movl	%ecx, %edx
	leaq	-96(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %r8
	movq	(%r8), %r8
	movq	%r8, -8(%rbp)
	movl	$0, -100(%rbp)
	movl	$0, -104(%rbp)
	movl	$0, -108(%rbp)
	movq	%rsi, -120(%rbp)        ## 8-byte Spill
	movl	%eax, %esi
	movq	%rdx, -128(%rbp)        ## 8-byte Spill
	movl	%eax, -132(%rbp)        ## 4-byte Spill
	callq	_memset
	movq	-120(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, %rdi
	movl	-132(%rbp), %esi        ## 4-byte Reload
	movq	-128(%rbp), %rdx        ## 8-byte Reload
	callq	_memset
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	leaq	L_.str(%rip), %rdi
	leaq	-96(%rbp), %rax
	leaq	-48(%rbp), %rcx
	movl	-104(%rbp), %edx
	movl	%edx, %esi
	addl	$1, %esi
	movl	%esi, -104(%rbp)
	movslq	%edx, %r8
	shlq	$2, %r8
	addq	%r8, %rcx
	movslq	-104(%rbp), %r8
	shlq	$2, %r8
	addq	%r8, %rax
	movq	%rcx, %rsi
	movq	%rax, %rdx
	movb	$0, %al
	callq	_scanf
	cmpl	$-1, %eax
	je	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_1
LBB0_3:
	movl	$0, -108(%rbp)
LBB0_4:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$10, -108(%rbp)
	jge	LBB0_7
## BB#5:                                ##   in Loop: Header=BB0_4 Depth=1
	leaq	L_.str1(%rip), %rdi
	movslq	-108(%rbp), %rax
	movl	-48(%rbp,%rax,4), %esi
	movslq	-108(%rbp), %rax
	movl	-96(%rbp,%rax,4), %edx
	movb	$0, %al
	callq	_printf
	movl	%eax, -136(%rbp)        ## 4-byte Spill
## BB#6:                                ##   in Loop: Header=BB0_4 Depth=1
	movl	-108(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -108(%rbp)
	jmp	LBB0_4
LBB0_7:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	jne	LBB0_9
## BB#8:                                ## %SP_return
	xorl	%eax, %eax
	addq	$144, %rsp
	popq	%rbp
	retq
LBB0_9:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d %d"

L_.str1:                                ## @.str1
	.asciz	"%d %d\n"


.subsections_via_symbols
