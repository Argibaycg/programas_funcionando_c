#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int funciones_sumarDosNumeros(float numeroUno, float numeroDos, float* pResultadoSuma);
int funciones_restarDosNumeros(float numeroUno, float numeroDos, float* pResultadoResta);
int funciones_multiplicarDosNumeros(float numeroUno, float numeroDos, float* pResultadoMultiplicacion);
int funciones_dividirDosNumeros(float numeroUno, float numeroDos, float* pResultadoDivision);
int funciones_calcularFactorial(float* pNumero,double* pResultadofactorial);
int funciones_pideUnNumero(float* pNumero,int reintentos, char mensajeNumero[]);
int funciones_menuOpcionesCalculadora(float numeroUno, float numeroDos);
int funciones_eleccionDeOpcionMenu(int *pOpcionElegida, char mensajeMenu[]);

#endif /* FUNCIONES_H_ */
