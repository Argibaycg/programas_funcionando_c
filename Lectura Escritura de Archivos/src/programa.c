#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn_gets.h"
#include "arrayEmployees.h"
#include "functions.h"
#include "informes.h"

#define CORRECTO 0
#define EMPLOYEES 1000

int menu(void) {

	Employee** arrayEmployees = (Employee**) malloc(sizeof(Employee*));
	int contador = 0;
	int opcion = 0;
	int id = 100;
	char auxName[1024];
	char auxLastName[1024];
	float auxSalary;
	int auxSector;
	int auxIdParaRemover;
	int flag = 0;
	do {
			printf("1. ALTAS:\n");
			printf("2. MODIFICAR:\n");
			printf("3. BAJA:\n");
			printf("4. INFORMAR:\n");
			printf("5) SALIR\n");
			printf("Elija una opcion por numero: \n");

			__fpurge(stdin);
			utn_getInt(&opcion);
			switch (opcion) {
			case 1:
				getEmployeesData(auxName,auxLastName,&auxSalary,&auxSector,"Error de ingreso de datos, reintente por favor\n");
				addEmployee(id, auxName, auxLastName, auxSalary,auxSector);
				id++;
				flag = 1;
				break;
			case 2:
				if(flag==0)
				{
					printf("Debe ingresar un usuario para poder antes de continuar.\n");
				}else
				{
				menuModifyEmployee(arrayEmployees, EMPLOYEES);
				}
				break;
			case 3:
				if(flag==0)
				{
					printf("Debe ingresar un usuario para poder antes de continuar.\n");
				}else
				{
				getIdToRemoveEmployee(arrayEmployees,EMPLOYEES,&auxIdParaRemover);
				   removeEmployee(arrayEmployees,EMPLOYEES,auxIdParaRemover);
				}
				break;
			case 4:
				if(flag==0)
				{
					printf("Debe ingresar un usuario para poder antes de continuar.\n");
				}else
				{
				menuOrderEmployees(arrayEmployees, EMPLOYEES);
				}
				break;
			case 5:return CORRECTO;
				break;
			default:
				printf("No ingreso una opcion valida.\n");
				break;
			}
		} while (opcion != 5);
	return CORRECTO;
}
