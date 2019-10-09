#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "funciones.h"
#define ERROR -1
#define CORRECTO 0

int main(void) {
	float numeroUno = 0;
	float numeroDos = 0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	double resultadoFactorialNumeroUno;
	double resultadoFactorialNumeroDos;
	int opcionElegida = 0;
	int eligioNumero = 0;
	do
	{
		__fpurge(stdin);
		printf("1. El 1er operando es: (A=%.2f)\n", numeroUno);
		printf("2. El 2do operando es: (B=%.2f)\n", numeroDos);
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultado\n");
		printf("5. Salir\n");
		opcionElegida = 0;
		funciones_eleccionDeOpcionMenu(&opcionElegida,"Elija una opcion con el numero de la misma:");
		if(opcionElegida == 1 || opcionElegida == 2)
		{
			eligioNumero = 1;
		}
		switch(opcionElegida)
			{
				case 1: funciones_pideUnNumero(&numeroUno, 2,"Ingrese el primer operando:");
					break;
				case 2: funciones_pideUnNumero(&numeroDos, 2,"Ingrese el primer operando:");
					break;
				case 3:
						if(eligioNumero == 0)
						{
							printf("Realize la eleccion de al menos un numero antes de calcular.\n");
						}else
						{
						funciones_sumarDosNumeros(numeroUno, numeroDos, &resultadoSuma);
						funciones_restarDosNumeros(numeroUno, numeroDos, &resultadoResta);
						funciones_multiplicarDosNumeros(numeroUno, numeroDos, &resultadoMultiplicacion);
						funciones_dividirDosNumeros(numeroUno, numeroDos, &resultadoDivision);
						funciones_calcularFactorial(&numeroUno, &resultadoFactorialNumeroUno);
						funciones_calcularFactorial(&numeroDos, &resultadoFactorialNumeroDos);
						printf("1. El 1er operando es: (A=%.2f)\n", numeroUno);
						printf("2. El 2do operando es: (B=%.2f)\n", numeroDos);
						printf("3. Calcular todas las operaciones\n");
						printf("   a) Calcular la suma (A+B)\n");
						printf("   b) Calcular la resta (A-B)\n");
						printf("   c) Calcular la division (A/B)\n");
						printf("   d) Calcular la multiplicacion (A*B)\n");
						printf("   e) Calcular el factorial (A!)\n");
						printf("4. Informar resultado\n");
						printf("5. Salir\n");
						}
					break;
				case 4:
						if(eligioNumero == 0)
						{
							printf("Realize la eleccion de al menos un numero antes de mostrar los resultados.\n");
						}else
						{
						printf("a) El resultado de A+B es: %.2f\n", resultadoSuma);
						printf("b) El resultado de A-B es: %.2f\n", resultadoResta);
						if(funciones_dividirDosNumeros(numeroUno, numeroDos, &resultadoDivision)==ERROR)
						{
							printf("c) No se puede dividir por cero.\n");
						}else
						{
							printf("c) El resultado de A/B es: %.2f\n", resultadoDivision);
						}
						printf("d) El resultado de A*B es: %.2f\n", resultadoMultiplicacion);
						if(funciones_calcularFactorial(&numeroUno,&resultadoFactorialNumeroUno)==ERROR)
						{
							printf("e) No se puede calcular factorial de un numero negativo.\n");
						}else
						{
							printf("e) El factorial de A es: %.0f\n", resultadoFactorialNumeroUno);
						}
						if(funciones_calcularFactorial(&numeroDos,&resultadoFactorialNumeroDos)==ERROR)
						{
							printf("e) No se puede calcular factorial de un numero negativo.\n");
						}else
						{
							printf("e) El factorial de B es: %.0f\n", resultadoFactorialNumeroDos);
						}
						}
					break;
				case 5: return CORRECTO;
					break;
				default:
						printf("No ingreso una opcion valida.\n");
				}
	}while(opcionElegida != 5);
	return CORRECTO;
}
