.syntax unified
.thumb
.text

.global zeros
.global productoEscalar32
.global productoEscalar16
.global productoEscalar12
.global filtroVentana10
.global pack32to16


@ void zeros(uint32_t * vector, uint32_t longitud)
.thumb_func
zeros:
	mov r2,0
	.next_zero:
		str  r2,[r0],4
		subs r1,1
		bne  .next_zero
	bx lr


@ void productoEscalar32(uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar)
.thumb_func
productoEscalar32:
	push {r4-r5}
	.nextProductoEscalar32:
		ldr  r5, [r0], 4
		mul  r4, r5, r3
		str  r4, [r1], 4
		subs r2, 1
		bne  .nextProductoEscalar32
	pop {r4-r5}
	bx  lr


@ void productoEscalar16(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar)
.thumb_func
productoEscalar16:
	push {r4-r5}
	.nextProductoEscalar16:
		ldrh r5, [r0], 2
		mul  r4, r5, r3
		strh r4, [r1], 2
		subs r2, 1
		bne .nextProductoEscalar16
	pop {r4-r5}
	bx  lr


@ void productoEscalar12(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar)
.thumb_func
productoEscalar12:
	push {r4-r5}
	.nextProductoEscalar12:
		ldrh r5, [r0], 2
		mul  r4, r5, r3
		usat r4, 12, r4 @ breakpoint
		strh r4, [r1], 2
		subs r2, 1
		bne .nextProductoEscalar12
	pop {r4-r5}
	bx  lr


@ void filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn)
filtroVentana10:
	push {r4-r10}
	mov r3, r1
	mov r4, r2
	mov r5, 0
	.fv10L1: @ n veces (inicio en 0 vectorOut)
		strh r5, [r3], 2
		subs r4, 1
		bne .fv10L1
	mov r3, r0
	mov r4, r1
	mov r5, r2
	mov r6, 10
	mov r9, 2
	mov r10, 1
	.fv10L2: @ 10 veces
		.fv10L3: @ acumulo vectorIn en vectorOut
			ldrh r7, [r3], 2
			udiv r8, r7, r6
			strh r8, [r4], 2
			subs r5, 1
			bne .fv10L3
		@ Preparo los vectores para una nueva acumulación
		@ "muevo" vectorIn a la izquierda y limito en 1 la longitud
		mov r4, r1
		mov r4, r0
		add r4, r9
		add r9, 2
		mov r5, r2
		sub r5, r10
		add r10, 1
		subs r6, 1
		bne .fv10L2
	pop {r4-r10}
	bx lr


@pack32to16(int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud)
.thumb_func
pack32to16:
	push {r4}
	.packL1:
		ldr  r4, [r0], 4
		ror  r4, 16
		and  r4, 0x00ff
		strh r4, [r1], 2
		subs r2, 1
		bne .packL1
	pop {r4}
	bx lr
