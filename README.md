# Arquitectura de microprocesadores

CESE15 - LSE FIUBA - 2021

Gonzalo Nahuel Vaca

## Preguntas orientadoras

1. Describa brevemente los diferentes perfiles de familias de microprocesadores/microcontroladores de ARM. Explique alguna de sus diferencias características.

Existen 3 perfiles de familias: M, R y A.

* M: es la familia diseñada para microcontroladores. Tienen la misión de reemplazar los integrados de 8 y 16 bits.
* R: es el perfil de tiempo real, se suelen usar en sistemas de control de disco rígido, control de motores de automóviles y despositivos médicos.
* A: este perfil se diseñó como un procesador de aplicaciones. Tienen la capacidad de correr sistemas operativos como WinRT y Linux. Se utilizan en electrónica de consumo como smart phones, tables y computadoras.

## Cortex M

1. Describa brevemente las diferencias entre las familias de procesadores Cortex M0, M3 y M4.

* M0: Implementación mínima para bajo consumo y bajo costo. Busca reemplazar las arquitecturas de 8 bits.
* M3: Mayor performance frente a M0.
* M4: Se agregan funcionalidades para el procesamiento digital de señales.

2. ¿Por qué se dice que el set de instrucciones Thumb permite mayor densidad de código? Explique

El set de intrucciones Thumb fué diseñado para crear una huella pequeña en la memoria. Esto se logra porque todas las instrucciones son de 16 bits, mientras que las instrucciones de ARM son todas de 32 bits. La solución final fué crear el set Thumb-2 que combina instrucciones de los 2 sets anteriores.

3. ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este tipo de arquitectura?

Es una arquitectura que no puede operar directamente sobre la memoria. Solo puede leer el valor de una posición de memoria y copiarla en un registro o volcar el valor de un registro en una posición de memoria. La arquetectura no posee instrucciones que modifiquen directamente una posición de memoria.

4. ¿Cómo es el mapa de memoria de la familia?

Tiene un mapa de memoria plano de 4 GB.

5. ¿Qué ventajas presenta el uso de los “shadowed pointers” del PSP y el MSP?

Permite la conmutación por hardware de los punteros de pila para códigos corriendo en distintos niveles de privilegio. Esto es particularmente útil para la implementación de un sistema operativo.

6. Describa los diferentes modos de privilegio y operación del Cortex M, sus relaciones y como se conmuta de uno al otro. Describa un ejemplo en el que se pasa del modo privilegiado a no priviligiado y nuevamente a privilegiado.

Existen 2 modos de privilegios: *privileged* y *non-privileged (user state)*.
Inicialmente y por defecto, los dispositivos comienzan en el modo *privileged*.

Para pasar de *privileged* a *non- privileged* se modifica por software el registro *CONTROL*.
No es posible regresar al modo *privileged* por software.

Para realizar el cambio se utilizan los modos de operación: *Thread* y *Handler*.
Es el *Handler* de una interrupción quién puede regresar al modo *privileged*.

Un ejemplo de pasar desde modo privilegiado a no privilegiado y de regreso es el flujo que genera un sistema operativo.

7. ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo

Significa que el set de instrucciones y los registros varian de de forma independiente. Esto quiere decir que las instrucciones son comunes para todos los registros. Un ejemplo es aplicar una máscara con *AND*, se puede operar con cualquier registro.

8. ¿Qué ventajas presenta el uso de intrucciones de ejecución condicional (IT)? Dé un ejemplo

La principal ventaja es no destruir el pipeline al eliminar los saltos. Por elemplo: *ADDNE*, el "NE" significa que la función *ADD* solo se ejecuta si el "Z" del registro *PSR* es 1.

9. Describa brevemente las excepciones más prioritarias (reset, NMI, Hardfault).

* reset: reinicia el core, prioridad 3.
* NMI: Non-Maskable Interrupt, prioridad 2.
* HardFault: cuando no se pudo llamar al handler de error correspondiente, prioridad 1.

10. Describa las funciones principales de la pila. ¿Cómo resuelve la arquitectura el llamado a funciones y su retorno?

La función principal de la pila es guardar el "contexto" cuando se realiza el llamado a una función, con el fin de reestablecer los valores al regresar.

El llamado a funciones se resuelve colocando los argumentos y el valor retornado en los registros de trabajo.

11. Describa la secuencia de reset del microprocesador.

* Se obtiene el valor del *Main Stack Pointer*
* Se obtiene el vector de reset.
* Se obtiene la 1ra instrucción indicada por el vector de reset.

12. ¿Qué entiende por “core peripherals”? ¿Qué diferencia existe entre estos y el resto de los periféricos?

Son los periféricos que forman parte del procesador y se diferencian del resto porque son necesarios para el funcionamiento de la arquitectura.

13. ¿Cómo se implementan las prioridades de las interrupciones? Dé un ejemplo

Se utiliza el vector de interrupciones programables *NVIC*. Por ejemplo, una interrupción por timer con una prioridad de 5.

14. ¿Qué es el CMSIS? ¿Qué función cumple? ¿Quién lo provee? ¿Qué ventajas aporta?
15. Cuando ocurre una interrupción, asumiendo que está habilitada ¿Cómo opera el microprocesador para atender a la subrutina correspondiente? Explique con un ejemplo
16. ¿Cómo cambia la operación de stacking al utilizar la unidad de punto flotante?
17. Explique las características avanzadas de atención a interrupciones: tail chaining y late arrival.
18. ¿Qué es el systick? ¿Por qué puede afirmarse que su implementación favorece la portabilidad de los sistemas operativos embebidos?
19. ¿Qué funciones cumple la unidad de protección de memoria (MPU)?
20. ¿Cuántas regiones pueden configurarse como máximo? ¿Qué ocurre en caso de haber solapamientos de las regiones? ¿Qué ocurre con las zonas de memoria no cubiertas por las regiones definidas?
21. ¿Para qué se suele utilizar la excepción PendSV? ¿Cómo se relaciona su uso con el resto de las excepciones? Dé un ejemplo
22. ¿Para qué se suele utilizar la excepción SVC? Expliquelo dentro de un marco de un
sistema operativo embebido.

## ISA

1. ¿Qué son los sufijos y para qué se los utiliza? Dé un ejemplo
2. ¿Para qué se utiliza el sufijo ‘s’? Dé un ejemplo
3. ¿Qué utilidad tiene la implementación de instrucciones de aritmética saturada? Dé un ejemplo con operaciones con datos de 8 bits.
4. Describa brevemente la interfaz entre assembler y C ¿Cómo se reciben los argumentos de las funciones? ¿Cómo se devuelve el resultado? ¿Qué registros deben guardarse en la pila antes de ser modificados?
5. ¿Qué es una instrucción SIMD? ¿En qué se aplican y que ventajas reporta su uso? Dé un ejemplo.