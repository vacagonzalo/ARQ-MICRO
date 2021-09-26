.syntax unified
.thumb
.text

.global zeros

.thumb_func
zeros:
	mov r2,0
	.next_zero:
		str r2,[r0],4
		subs r1,1
		bne .next_zero
	bx lr
