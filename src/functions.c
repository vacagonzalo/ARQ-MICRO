#include "functions.h"

void c_zeros(uint32_t * vector, uint32_t longitud)
{
	for(uint32_t i = 0; i < longitud; ++i)
	{
		vector[i] = 0;
	}
}

void c_productoEscalar32(uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar)
{
	for(uint32_t i = 0; i < longitud; ++i)
	{
		vectorOut[i] = vectorIn[i] * escalar;
	}
}

void c_productoEscalar16(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar)
{
	for(uint32_t i = 0; i < longitud; ++i)
	{
		vectorOut[i] = vectorIn[i] * escalar;
	}
}

void c_productoEscalar12(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar)
{
	const uint16_t mask = 0xF000;
	for(uint32_t i = 0; i < longitud; ++i)
	{
		vectorOut[i] = vectorIn[i] * escalar;
		if(vectorOut[i] & mask) vectorOut[i] = ~mask;
	}
}

// La ventana es más pequeña en los últimos 10 elementos
void c_filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn)
{
	uint16_t winSize = 0;
	for(uint32_t i = 0; i < longitudVectorIn; ++i)
	{
		winSize = longitudVectorIn - i;
		if(winSize > 10) winSize = 10;
		for(uint32_t j = 0; j < winSize; ++j)
		{
			vectorOut[i] += vectorIn[i + j];
		}
		vectorOut[i] = vectorOut[i] / winSize;
	}
}

void c_pack32to16 (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud)
{
	for(uint32_t i = 0; i < longitud; ++i)
	{
		vectorOut[i] = (uint16_t)(vectorIn[i]>>16);
	}
}

int32_t c_max(int32_t * vectorIn, uint32_t longitud)
{
	uint32_t pos = 0;
	for(uint32_t i = 0; i < longitud; ++i)
	{
		if(vectorIn[i] > vectorIn[pos])
		{
			pos = i;
		}
	}
	return (int32_t)pos;
}

void c_invertir(uint16_t * vector, uint32_t longitud)
{
	uint32_t leftIndx = 0;
	uint32_t rightIndx = longitud - 1;
	uint32_t aux = 0;
	while( leftIndx < rightIndx)
	{
		aux = vector[leftIndx];
		vector[leftIndx] = vector[rightIndx];
		vector[rightIndx] = aux;
		leftIndx++;
		rightIndx--;
	}
}

// 1000ms --- 44100 muestras
//   20ms --- x = 20 * 44100 / 1000
// => x = 882 muestras
void c_eco(int16_t * vector, uint32_t longitud)
{
	uint32_t i = 0;
	uint32_t j = 882;
	for(; j < longitud; ++i, ++j)
	{
		vector[j] += vector[i] / 2;
	}
}
