#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn_gets.h"
#include "arrayEmployees.h"
#include "functions.h"

#define CORRECTO 0
#define ERROR -1
#define EMPLOYEES 1000


/** \brief Gets data by user input and store the values
*
* \param list Employee*
* \param char* pName
* \param char* pLastname
* \param char* pLastname
* \param float salary
* \param int sector
* \param char* pMesaggeError
* \return int Return (-1) if Error [Invalid length or NULL pointer or if the values given by the user are incorrect] - (0) if Ok
*
*/
int getEmployeesData(char* pName,char* pLastName,float* pSalary,int* pSector, char* pMesaggeError)
{
	int retorno = ERROR;
	if(utn_getString("Ingrese el nombre: \n", "Nombre no valido.\n",pName)==-1)
	{
		printf("%s", pMesaggeError);
	}
	else if(utn_getString("Ingrese el Apellido: \n", "Apellido no valido.\n", pLastName)==-1)
	{
		printf("%s", pMesaggeError);
	}
	else if(utn_getFloat(pSalary, 50000, 15000, 2, "Ingrese el salario entre 15000 y 50000\n", "Salario incorrecto\n")==-1)
	{
		printf("%s", pMesaggeError);
	}
	else if(utn_getNumber(pSector, 5, 1, 2, "Ingrese el sector del 1 al 5.\n", "Sector no valido\n")==-1)
	{
		printf("%s", pMesaggeError);
	}else
	{
		retorno=CORRECTO;
	}

	return retorno;
}

/** \brief Display a menu for the user can modify some field of the employee
*
* \param list Employee*
* \param int lentgh
* \return int Return (-1) if Error [Invalid length or NULL pointer or if the values given by the user are incorrect] - (0) if Ok
*
*/
int menuModifyEmployee(Employee *arrayEmployees, int lentgh)
{
	int retorno = ERROR;
	int opcionMenu = 0;
	char opcionBorrar;
	int idParaModificar;
	int index;
	char auxName[1024];
	char auxLastName[1024];
	float auxSalary;
	int auxSector;
	__fpurge(stdin);
	if(arrayEmployees != NULL && lentgh > 0)
	{
		if(utn_getChar("Desea modificar un empleado? s/n.\n","Ingreso no valido", &opcionBorrar)==0)
		{
			if(opcionBorrar == 's')
			{
				printEmployees(arrayEmployees, lentgh);
				utn_getNumber(&idParaModificar,1000,100,2,"Ingrese el ID del empleado que desea modificar","ID no valido");
				index = findEmployeeById(arrayEmployees, EMPLOYEES, idParaModificar);
				printf("Que desea modificar?\n");
				printf("1. NOMBRE\n");
				printf("2. APELLIDO:\n");
				printf("3. SALARIO:\n");
				printf("4. SECTOR:\n");
				printf("Elija una opcion por numero: \n");
				utn_getInt(&opcionMenu);
				switch(opcionMenu)
				{
					case 1:utn_getString("Ingrese nuevo nombre:","Nombre no valido", auxName);
						   strcpy(arrayEmployees[index].name, auxName);
						   retorno = CORRECTO;
						break;
					case 2:utn_getString("Ingrese nuevo Apellido:","Apellido no valido", auxLastName);
					   strcpy(arrayEmployees[index].name, auxLastName);
					   retorno = CORRECTO;
						break;
					case 3:utn_getFloat(&auxSalary,50000,15000,2,"Ingrese nuevo salario: ", "Salario incorrecto");
						   arrayEmployees[index].salary = auxSalary;
						   retorno = CORRECTO;
						break;
					case 4:utn_getNumber(&auxSector,5,1,2,"Ingrese nuevo sector 1 / 2 / 3 / 4 / 5: ","Sector no valido");
						   arrayEmployees[index].sector = auxSector;
						   retorno = CORRECTO;
						break;
					default:printf("Opcion no valida.\n");
						break;
				}
			}else
			{
				printf("No se modificara ningun empleado.\n");
			}
			}
	}
	return retorno;
}


/** \brief Get's the is of the employee that the user wants to remove
*
* \param list Employee*
* \param int lentgh
* \param int* pIdParaRemover
* \return int Return (-1) if Error [Invalid length or NULL pointer or if the values given by the user are incorrect] - (0) if Ok
*
*/
int getIdToRemoveEmployee(Employee arrayEmployees[], int lentgh, int* pIdParaRemover)
{
	int retorno = ERROR;
	char opcionBorrarEmployee;
	int auxIdParaDarDeBaja;
	if(arrayEmployees != NULL && lentgh > 0)
	{
		if(utn_getChar("Desea dar de baja un empleado? s/n.\n","Ingreso no valido", &opcionBorrarEmployee)==0)
		{
			if(opcionBorrarEmployee == 's')
			{
				printEmployees(arrayEmployees, EMPLOYEES);
				if(utn_getNumber(&auxIdParaDarDeBaja,1000,100,2,"Ingrese el ID del empleado que desea dar de baja","ID no valido")==0)
				{
				*pIdParaRemover = auxIdParaDarDeBaja;
				retorno = CORRECTO;
				}
			}
	}
	}
	return retorno;
}
