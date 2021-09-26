#include "VACA_ARQ.h"
#include "sapi.h"

#include "functions.h"

#define EJER01_LONGITUD 1000

int main( void )
{
	boardInit();
	tick_t timestamp_start;
	tick_t timestamp_end;
	tick_t time;

	///////////////////////////////////////////////////////////////////////////
	printf("\n\rEjercicio 1\n\r");
	uint32_t vector[EJER01_LONGITUD];
	uint32_t longitud = EJER01_LONGITUD;

	timestamp_start = tickRead();
	c_zeros(vector, longitud);
	timestamp_end = tickRead();
	time = timestamp_end - timestamp_start;
	printf("zeros C: %dms\n\r", time);

	timestamp_start = tickRead();
	zeros(vector, longitud);
	timestamp_end = tickRead();
	time = timestamp_end - timestamp_start;
	printf("zeros ASM: %dms\n\r", time);
	///////////////////////////////////////////////////////////////////////////
	printf("\n\rEjercicio 2\n\r");
	uint32_t vector2[EJER01_LONGITUD];

	timestamp_start = tickRead();
	c_productoEscalar32(vector, vector2, EJER01_LONGITUD, 5);
	timestamp_end = tickRead();
	time = timestamp_end - timestamp_start;
	printf("Prod esc 32 C: %dms\n\r", time);

	timestamp_start = tickRead();
	productoEscalar32(vector, vector2, EJER01_LONGITUD, 5);
	timestamp_end = tickRead();
	time = timestamp_end - timestamp_start;
	printf("Prod esc 32 ASM: %dms\n\r", time);
	while( true ) {
		gpioToggle(LED1);
		delay(500);
	}
	return 0;
}
