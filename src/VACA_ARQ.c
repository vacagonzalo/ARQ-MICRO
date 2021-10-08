#include "VACA_ARQ.h"
#include "sapi.h"

#include "functions.h"
#include "cmsis.h"

#define EJER01_LONGITUD 1000

int main( void )
{
	boardInit();
	DWT->CTRL |= 1 << DWT_CTRL_CYCCNTENA_Pos;
	uint32_t ciclos = 0;

	///////////////////////////////////////////////////////////////////////////
	// Resolución ejercicio 1
	///////////////////////////////////////////////////////////////////////////
	printf("\n\rEjercicio 1\n\r");
	uint32_t vector[EJER01_LONGITUD];
	uint32_t longitud = EJER01_LONGITUD;

	DWT->CYCCNT = 0;
	c_zeros(vector, longitud);
	ciclos = DWT->CYCCNT;
	printf("zeros C  : %d ciclos\n\r", ciclos);

	DWT->CYCCNT = 0;
	zeros(vector, longitud);
	ciclos = DWT->CYCCNT;
	printf("zeros ASM: %d ciclos\n\r", ciclos);


	///////////////////////////////////////////////////////////////////////////
	// Resolución ejercicio 2
	///////////////////////////////////////////////////////////////////////////
	printf("\n\rEjercicio 2\n\r");
	uint32_t vector2[EJER01_LONGITUD];

	DWT->CYCCNT = 0;
	c_productoEscalar32(vector, vector2, EJER01_LONGITUD, 5);
	ciclos = DWT->CYCCNT;
	printf("Prod esc 32 C  : %d ciclos\n\r", ciclos);

	DWT->CYCCNT = 0;
	productoEscalar32(vector, vector2, EJER01_LONGITUD, 5);
	ciclos = DWT->CYCCNT;
	printf("Prod esc 32 ASM: %d ciclos\n\r", ciclos);


	while( true ) {
		gpioToggle(LED1);
		delay(500);
	}
	return 0;
}
