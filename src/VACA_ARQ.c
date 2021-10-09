#include "VACA_ARQ.h"
#include "sapi.h"

#include "functions.h"
#include "cmsis.h"

#define LONGITUD 1000

int main( void )
{
	boardInit();
	DWT->CTRL |= 1 << DWT_CTRL_CYCCNTENA_Pos;
	uint32_t ciclos = 0;

	///////////////////////////////////////////////////////////////////////////
	// Resolución ejercicio 1
	///////////////////////////////////////////////////////////////////////////
	printf("\n\rEjercicio 1\n\r");
	uint32_t vector[LONGITUD];
	uint32_t longitud = LONGITUD;

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
	uint32_t vector2[LONGITUD];

	DWT->CYCCNT = 0;
	c_productoEscalar32(vector, vector2, LONGITUD, 5);
	ciclos = DWT->CYCCNT;
	printf("Prod esc 32 C  : %d ciclos\n\r", ciclos);

	DWT->CYCCNT = 0;
	productoEscalar32(vector, vector2, LONGITUD, 5);
	ciclos = DWT->CYCCNT;
	printf("Prod esc 32 ASM: %d ciclos\n\r", ciclos);


	///////////////////////////////////////////////////////////////////////////
	// Resolución ejercicio 3
	///////////////////////////////////////////////////////////////////////////
	printf("\n\rEjercicio 3\n\r");
	uint16_t vector16_1[LONGITUD] = {1};
	uint16_t vector16_2[LONGITUD] = {0};

	DWT->CYCCNT = 0;
	c_productoEscalar16(vector16_1, vector16_2, LONGITUD, 2);
	ciclos = DWT->CYCCNT;
	printf("Prod esc 16 C  : %d ciclos\n\r", ciclos);

	DWT->CYCCNT = 0;
	productoEscalar16(vector16_1, vector16_2, LONGITUD, 2);
	ciclos = DWT->CYCCNT;
	printf("Prod esc 16 ASM : %d ciclos\n\r", ciclos);


	///////////////////////////////////////////////////////////////////////////
	// Resolución ejercicio 4
	///////////////////////////////////////////////////////////////////////////
	printf("\n\rEjercicio 4\n\r");

	DWT->CYCCNT = 0;
	c_productoEscalar12(vector16_1, vector16_2, LONGITUD, 2);
	ciclos = DWT->CYCCNT;
	printf("Prod esc 12 C  : %d ciclos\n\r", ciclos);

	DWT->CYCCNT = 0;
	productoEscalar12(vector16_1, vector16_2, LONGITUD, 2);
	ciclos = DWT->CYCCNT;
	printf("Prod esc 12 ASM : %d ciclos\n\r", ciclos);

	///////////////////////////////////////////////////////////////////////////
	// Resolución ejercicio 5
	///////////////////////////////////////////////////////////////////////////
	printf("\n\rEjercicio 5\n\r");

	DWT->CYCCNT = 0;
	c_filtroVentana10(vector16_1, vector16_2, LONGITUD);
	ciclos = DWT->CYCCNT;
	printf("Filtro 10 C  : %d ciclos\n\r", ciclos);

	DWT->CYCCNT = 0;
	filtroVentana10(vector16_1, vector16_2, LONGITUD);
	ciclos = DWT->CYCCNT;
	printf("Filtro 10 ASM : %d ciclos\n\r", ciclos);

	while( true ) {
		gpioToggle(LED1);
		delay(500);
	}
	return 0;
}
