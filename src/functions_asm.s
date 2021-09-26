.syntax unified
.thumb
.text

.global zeros
.global productoEscalar32

@ void zeros(uint32_t * vector, uint32_t longitud)
.thumb_func
zeros:
	mov r2,0
	.next_zero:
		str r2,[r0],4
		subs r1,1
		bne .next_zero
	bx lr

.thumb_func
@ void productoEscalar32(uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar)
productoEscalar32:
	push {r4-r5}
	.nextProductoEscalar32:
		ldr r5, [r0], 4
		mul r4, r5, r3
		str r4, [r1], 4
		subs r2, 1
		bne .nextProductoEscalar32
		pop {r4-r5}
		bx lr
