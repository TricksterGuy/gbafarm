	.cpu arm7tdmi
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	mov	r2, #67108864
	mov	r3, #1024
	add	r3, r3, #3
	strh	r3, [r2, #0]	@ movhi
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L2
.L5:
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L3
.L4:
	ldr	r3, .L8
	ldr	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	mov	r3, r3, asl #4
	mov	r1, r3, asl #4
	rsb	r1, r3, r1
	ldr	r3, [fp, #-12]
	add	r3, r1, r3
	mov	r3, r3, asl #1
	add	r2, r2, r3
	ldr	r3, [fp, #-8]
	mov	r3, r3, asl #4
	mov	r1, r3, asl #4
	rsb	r1, r3, r1
	ldr	r3, [fp, #-12]
	add	r3, r1, r3
	ldr	r1, .L8+4
	mov	r3, r3, asl #1
	add	r3, r1, r3
	ldrh	r3, [r3, #0]
	strh	r3, [r2, #0]	@ movhi
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L3:
	ldr	r3, .L8+8
	ldr	r3, [r3, #0]
	mov	r2, r3
	ldr	r3, [fp, #-8]
	cmp	r2, r3
	bhi	.L4
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L2:
	ldr	r3, .L8+12
	ldr	r3, [r3, #0]
	mov	r2, r3
	ldr	r3, [fp, #-12]
	cmp	r2, r3
	bhi	.L5
.L6:
	b	.L6
.L9:
	.align	2
.L8:
	.word	videoBuffer
	.word	background
	.word	background_height
	.word	background_width
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.1"
