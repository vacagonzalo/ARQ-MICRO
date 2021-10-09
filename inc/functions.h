#ifndef PROGRAMS_VACA_ARQ_INC_FUNCTIONS_H_
#define PROGRAMS_VACA_ARQ_INC_FUNCTIONS_H_

#include <stdint.h>

// Ejercicio 01
extern void zeros(uint32_t * vector, uint32_t longitud);
void c_zeros(uint32_t * vector, uint32_t longitud);

// Ejercicio 02
extern void productoEscalar32(uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar);
void c_productoEscalar32(uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar);

// Ejercicio 03
extern void productoEscalar16(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);
void c_productoEscalar16(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);

// Ejercicio 04
extern void productoEscalar12(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);
void c_productoEscalar12(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);

// Ejercicio 05
extern void filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);
void c_filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);

// Ejercicio 06
extern void pack32to16(int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);
void c_pack32to16(int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);
#endif /* PROGRAMS_VACA_ARQ_INC_FUNCTIONS_H_ */
