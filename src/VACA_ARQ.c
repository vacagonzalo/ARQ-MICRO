#include "VACA_ARQ.h"
#include "sapi.h"

#include "functions.h"

#define EJER01_LONGITUD 100

int main( void )
{
	boardInit();
	uint32_t vector[EJER01_LONGITUD];
	uint32_t longitud = EJER01_LONGITUD;
	tick_t timestamp_start;
	tick_t timestamp_end;
	tick_t time;

	printf("Ejercicio 1\n\r");
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

	while( true ) {
		gpioToggle(LED);
		delay(500);
	}
	return 0;
}
