#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn_gets.h"
#include "arrayEmployees.h"
#include "functions.h"
#include "informes.h"
#define CORRECTO 0
#define ERROR -1
#define EMPLOYEES 1000

/** \brief Display menu for the user can choose what data want to show
*
* \param list Employee*
* \param int lentgh
* \return int Return (-1) if Error [Invalid length or NULL pointer or if the values given by the user are incorrect] - (0) if Ok
*
*/
int menuOrderEmployees(Employee arrayEmployees[], int lentgh)
{
	int retorno = ERROR;
	int opcionMenu = 0;
	int opcionOrdenamiento;
	float totalSalary;
	float averageSalary;
	int qtyEmployeesWhitSalaryMoreThanAverage;
	if(arrayEmployees != NULL && lentgh > 0)
	{
		printf("Que desea informar?\n");
		printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
		printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
		printf("Elija una opcion por numero: \n");
		__fpurge(stdin);
		utn_getInt(&opcionMenu);
		switch(opcionMenu)
		{
			case 1:
			printf("Ingrese 0 para ascendente o 1 para descendente:\n");
			__fpurge(stdin);
			utn_getInt(&opcionOrdenamiento);
			sortEmployeeByName(arrayEmployees,EMPLOYEES,opcionOrdenamiento);
			printEmployees(arrayEmployees, EMPLOYEES);
			retorno = CORRECTO;
				break;
			case 2:reportTotalSalary(arrayEmployees,EMPLOYEES,&totalSalary);
				   printf("El salario total es:%.2f\n",totalSalary);
				   countEmployeesAndAverageSalary(arrayEmployees,EMPLOYEES,totalSalary,&averageSalary);
				   printf("El salario promedio es:%.2f\n",averageSalary);
				   employeesWhitSalaryMoreThanAverageSalary(arrayEmployees,EMPLOYEES,averageSalary,&qtyEmployeesWhitSalaryMoreThanAverage);
				   printf("La cantidad de trabajadores por encima del salario promedio es:%.d\n",qtyEmployeesWhitSalaryMoreThanAverage);
				   retorno = CORRECTO;
				break;
			default:printf("Opcion no valida.\n");
				break;
		}
	}
	return retorno;
}

/** \brief Calculate the total amount of salary for all the employees
*
* \param list Employee*
* \param int lentgh
* \param float* pTotalSalary
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't calculate the total salary] - (0) if Ok
*
*/
int reportTotalSalary(Employee arrayEmployees[], int len, float *pTotalSalary)
{
	int retorno = ERROR;
	float auxTotalSalary = 0;
	int i;
		if(arrayEmployees != NULL && len > 0)
		{
			for(i=0; i < len; i++)
				{
					auxTotalSalary += arrayEmployees[i].salary;
				}
			*pTotalSalary = auxTotalSalary;
			retorno = CORRECTO;
		}
	return retorno;
}

/** \brief Count the employees and calculate the average salary
*
* \param list Employee*
* \param int lentgh
* \param float totalSalary
* \param float* pAverageSalary
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't calculate the total salary] - (0) if Ok
*
*/
int countEmployeesAndAverageSalary(Employee arrayEmployees[], int len, float totalSalary, float* pAverageSalary)
{
	int retorno = ERROR;
	int quantityEmployees = 0;
	float auxAverageSalary;
	int i;
	if(arrayEmployees != NULL && len > 0)
	{
		for(i=0; i < len; i++)
		{
			if(arrayEmployees[i].isEmpty == 1)
			{
				quantityEmployees++;
			}
		}
		auxAverageSalary = totalSalary / quantityEmployees;
		*pAverageSalary = auxAverageSalary;
			retorno = CORRECTO;
	}
	return retorno;
}


/** \brief Count how many employees have more salary than the average salary
*
* \param list Employee*
* \param int lentgh
* \param float averageSalary
* \param int* qtyEmployeesWhitSalaryMoreThanAverage
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't calculate the employees whit more salary tha the average] - (0) if Ok
*
*/
int employeesWhitSalaryMoreThanAverageSalary(Employee arrayEmployees[], int len, float averageSalary, int* qtyEmployeesWhitSalaryMoreThanAverage)
{
	int retorno = ERROR;
	int auxQtyEmployeesWhitSalaryMoreThanAverage = 0;
	int i;
			if(arrayEmployees != NULL && len > 0)
			{
				for(i=0; i < len; i++)
					{
						if(arrayEmployees[i].salary > averageSalary)
						{
							auxQtyEmployeesWhitSalaryMoreThanAverage++;
						}
					}
				*qtyEmployeesWhitSalaryMoreThanAverage = auxQtyEmployeesWhitSalaryMoreThanAverage;
				retorno = CORRECTO;
			}


	return retorno;
}
