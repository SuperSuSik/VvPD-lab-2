	.build_version macos, 26, 0	sdk_version 26, 5
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	adrp	x8, _global_runs@GOTPAGE
	ldr	x8, [x8, _global_runs@GOTPAGEOFF]
	ldr	x8, [x8]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	stur	wzr, [x29, #-8]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-8]
	subs	w8, w8, #5
	b.ge	LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	bl	_device_tick
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	w8, [x29, #-8]
	add	w8, w8, #1
	stur	w8, [x29, #-8]
	b	LBB0_1
LBB0_4:
	adrp	x8, _global_runs@GOTPAGE
	ldr	x8, [x8, _global_runs@GOTPAGEOFF]
	ldr	x8, [x8]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	bl	_device_internal_calls
	mov	x8, sp
	str	x0, [x8]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	mov	x8, #304                        ; =0x130
	stur	x8, [x29, #-16]
	mov	x9, sp
	str	x8, [x9]
	str	x8, [x9, #8]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	mov	x9, sp
	mov	x8, #11                         ; =0xb
	str	x8, [x9]
	adrp	x0, l_.str.6@PAGE
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	mov	x9, sp
	mov	x8, #25                         ; =0x19
	str	x8, [x9]
	adrp	x0, l_.str.7@PAGE
	add	x0, x0, l_.str.7@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.8@PAGE
	add	x0, x0, l_.str.8@PAGEOFF
	bl	_printf
	bl	_get_high_res_time
	stur	d0, [x29, #-24]
	stur	wzr, [x29, #-28]
	str	wzr, [sp, #32]
	b	LBB0_5
LBB0_5:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #32]
	mov	w9, #38528                      ; =0x9680
	movk	w9, #152, lsl #16
	subs	w8, w8, w9
	b.ge	LBB0_8
	b	LBB0_6
LBB0_6:                                 ;   in Loop: Header=BB0_5 Depth=1
	ldr	w9, [sp, #32]
	ldur	w8, [x29, #-28]
	add	w8, w8, w9
	stur	w8, [x29, #-28]
	b	LBB0_7
LBB0_7:                                 ;   in Loop: Header=BB0_5 Depth=1
	ldr	w8, [sp, #32]
	add	w8, w8, #1
	str	w8, [sp, #32]
	b	LBB0_5
LBB0_8:
	bl	_get_high_res_time
	str	d0, [sp, #24]
	ldur	d0, [x29, #-24]
	ldr	d1, [sp, #24]
	adrp	x0, l_.str.9@PAGE
	add	x0, x0, l_.str.9@PAGEOFF
	bl	_print_time_diff
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"=== 13.1. \320\223\320\273\320\276\320\261\320\260\320\273\321\214\320\275\321\213\320\265 \320\270 static \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\265 ===\n"

l_.str.1:                               ; @.str.1
	.asciz	"global_runs \320\264\320\276 \320\262\321\213\320\267\320\276\320\262\320\276\320\262: %lu\n"

l_.str.2:                               ; @.str.2
	.asciz	"global_runs \320\277\320\276\321\201\320\273\320\265 5 \320\262\321\213\320\267\320\276\320\262\320\276\320\262: %lu\n"

l_.str.3:                               ; @.str.3
	.asciz	"internal calls: %lu\n"

l_.str.4:                               ; @.str.4
	.asciz	"\n=== 14. const \320\270 #define ===\n"

l_.str.5:                               ; @.str.5
	.asciz	"BUFFER_SIZE = %d, buffer_size = %zu\n"

l_.str.6:                               ; @.str.6
	.asciz	"BAD_SQUARE(2 + 3) = %d\n"

l_.str.7:                               ; @.str.7
	.asciz	"GOOD_SQUARE(2 + 3) = %d\n"

l_.str.8:                               ; @.str.8
	.asciz	"\n=== 12. \320\230\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\265 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 (\320\262\321\213\321\201\320\276\320\272\320\276\321\202\320\276\321\207\320\275\321\213\320\271 \321\202\320\260\320\271\320\274\320\265\321\200) ===\n"

l_.str.9:                               ; @.str.9
	.asciz	"timer.c test"

.subsections_via_symbols
