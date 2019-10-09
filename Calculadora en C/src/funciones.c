#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define ERROR -1
#define CORRECTO 0

/**
 * \brief Suma dos numeros y guarda los resultado en la direccion apuntada
 * \param numeroUno lee por valor el primer numero
 * \param numeroUno lee por valor el segundo numero
 * \param *pResultadoSuma guarda en la variable resultadoSuma el resultado de la operacion
 * \return CORRECTO o ERROR para manejar errores
 *
 */
int funciones_sumarDosNumeros(float numeroUno, float numeroDos, float*pResultadoSuma)
{
	float resultadoSuma;
	int retorno = ERROR;

	resultadoSuma = numeroUno + numeroDos;
	*pResultadoSuma = resultadoSuma;

	retorno = CORRECTO;
	return retorno;
}

/**
 * \brief Resta dos numeros y guarda los resultado en la direccion apuntada
 * \param numeroUno lee por valor el primer numero
 * \param numeroUno lee por valor el segundo numero
 * \param *pResultadoSuma guarda en la variable resultadoSuma el resultado de la operacion
 * \return CORRECTO o ERROR para manejar errores
 *
 */
int funciones_restarDosNumeros(float numeroUno, float numeroDos, float* pResultadoResta){

	float resultadoResta;
	int retorno = ERROR;

	resultadoResta = numeroUno - numeroDos;
	*pResultadoResta = resultadoResta;
	retorno = CORRECTO;
	return retorno;
}

/**
 * \brief Multiplica dos numeros y guarda los resultado en la direccion apuntada
 * \param numeroUno lee por valor el primer numero
 * \param numeroUno lee por valor el segundo numero
 * \param *pResultadoSuma guarda en la variable resultadoSuma el resultado de la operacion
 * \return CORRECTO o ERROR para manejar errores
 *
 */
int funciones_multiplicarDosNumeros(float numeroUno, float numeroDos, float* pResultadoMultiplicacion){

	float resultadoMultiplicacion;
	int retorno = ERROR;

	resultadoMultiplicacion = numeroUno * numeroDos;
	*pResultadoMultiplicacion = resultadoMultiplicacion;
	retorno = CORRECTO;
	return retorno;
}

/**
 * \brief Divide dos numeros y guarda los resultado en la direccion apuntada
 * \param numeroUno lee por valor el primer numero
 * \param numeroUno lee por valor el segundo numero
 * \param *pResultadoSuma guarda en la variable resultadoSuma el resultado de la operacion
 * \return CORRECTO o ERROR para manejar errores
 *
 */
int funciones_dividirDosNumeros(float numeroUno, float numeroDos, float* pResultadoDivision){

	float resultadoDivision;
	int retorno = ERROR;

	if(numeroDos != 0)
	{
		resultadoDivision = numeroUno / numeroDos;
		*pResultadoDivision = resultadoDivision;
		retorno = CORRECTO;
	}
	return retorno;

}

/**
 * \brief Recibe la direccion de memoria de la variable numero y resultado y calcula el factorial
 * \param *pNumero recibe el valor de numero por puntero
 * \param *pResultadoFactorial guarda en la variable resultadoFactorial el resultado de la operacion
 * \return CORRECTO o ERROR para manejar errores
 *
 */
int funciones_calcularFactorial(float* pNumero,double* pResultadoFactorial)
{
	int i;
	int retorno = ERROR;
	double numeroDouble = *pNumero;
	double resultado = 1;
	if(numeroDouble >= 0)
	{
	for(i = 1; i <= numeroDouble; i++)
	{
		resultado = resultado * i;
		retorno = CORRECTO;
	}
	}
	if(numeroDouble==0)
	{
		retorno = CORRECTO;
	}
	*pResultadoFactorial = resultado;

	return retorno;
}

/**
 * \brief pide un numero al usuario y guarda su ingreso
 * \param pNumero guarda en la variable del main el numero que ingresa el usuario
 * \param reintentos que tiene el usuario para ingresar un numero valido
 * \param mensaje[] lee el mensaje que es pasado desde la llama en main
 * \return CORRECTO o ERROR para manejar errores
 *
 */
int funciones_pideUnNumero(float* pNumero,int reintentos,char mensajeNumero[])
{
	int i;
	float numero;
	int retorno = ERROR;
	for(i=0; i < reintentos; i++)
	{
		printf("%s", mensajeNumero);
		__fpurge(stdin);
		if(scanf("%f", &numero)==1)
		{
			*pNumero = numero;
			retorno = CORRECTO;
		break;
		}
		else
		{
			printf("Error ingrese un numero.\n");
			retorno = CORRECTO;
		}
	}
	return retorno;
}

/**
 * \brief Da a elejir al usuario una opcion de menu
 * \param *pOpcionElegida guarda la opcion elegida en la variable del main
 * \param mensaje[] lee el mensaje que es pasado desde la llama en main
 * \return Una nueva matriz C = AxB.
 *
 */
int funciones_eleccionDeOpcionMenu(int *pOpcionElegida,char mensajeMenu[])
{
	int retorno = ERROR;
	int opcionElegida = 0;

	printf("%s", mensajeMenu);
	__fpurge(stdin);
	if(scanf("%d", &opcionElegida)==1)
	{
	*pOpcionElegida = opcionElegida;
	retorno = CORRECTO;
	}
	retorno = ERROR;
	return retorno;
}
