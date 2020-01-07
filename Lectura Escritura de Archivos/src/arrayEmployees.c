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

/** \brief To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
Employee* new_Empleado()
{

Employee* empleado = (Employee*)malloc( sizeof(Employee));

if(empleado != NULL){
    empleado->id = 0;
    strcpy(empleado->name,"");
    strcpy(empleado->lastName,"");
    empleado->salary = 0;
    empleado->sector = 0;
    empleado->isEmpty = 0;

}
return empleado;
}

/** \brief add in a existing list of employees the values received as parameters
*		   in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
Employee* addEmployee(int id, char *name, char *lastName,float salary,int sector)
{
	Employee* empleado;
	empleado = new_Empleado();
	if(empleado != NULL)
	{
		empleado->id = id;
		strcpy(empleado->name,name);
		strcpy(empleado->lastName,lastName);
		empleado->salary = salary;
		empleado->sector = sector;
		empleado->isEmpty = 1;
	}
	return empleado;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee *arrayEmployees, int len,int id)
{
	int i;
	if(arrayEmployees != NULL && len > 0)
	{
		for (i = 0; i != id; i++)
		{
			if ((arrayEmployees+i)->id == id)
			{
				return i;
			}
		}
	}
	return -1;
}

int searchEmpty(Employee *arrayEmployees, int len, int *pUbicacionEmpty)
{
	int retorno = ERROR;
	int i;
	if(arrayEmployees != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if ((arrayEmployees+i)->isEmpty == 0)
			{
				*pUbicacionEmpty = i;
				retorno = CORRECTO;
				break;
			}
		}
	}
	return retorno;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee *arrayEmployees, int length)
{
	int retorno = ERROR;
	int i;
	int flag = 0;
	if(arrayEmployees != NULL && length > 0)
	{
		for(i=0; i < length; i++)
		{
			if((arrayEmployees+i)->isEmpty == 1)
			{
				   printf("ID empleado: %d\n Nombre:%s\n Apellido:%s\n Salario:%.2f\n Sector:%d\n",
				   (arrayEmployees+i)->id,
				   (arrayEmployees+i)->name,
				   (arrayEmployees+i)->lastName,
				   (arrayEmployees+i)->salary,
				   (arrayEmployees+i)->sector);
				   retorno = CORRECTO;
				   flag = 1;
			}
		}
			if(flag == 0)
			{
				printf("No hay empleados para modificar\n");
			}
	}
return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee *arrayEmployees, int len, int id)
{
	int retorno = ERROR;
	int i;
	if(arrayEmployees != NULL && len > 0)
	{
		for(i=0; i < len; i++)
			{
				if((arrayEmployees+i)->id == id)
				{
					   (arrayEmployees+i)->isEmpty = 0;
					   retorno = CORRECTO;
				}
			}
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployeeByName(Employee *arrayEmployees, int len, int order)
{
    int retorno = ERROR;
    int i;
    int j;
    Employee auxiliar;

    if(arrayEmployees != NULL && len > 0)
    {
        switch(order)
        {
            case 0:
                if(len > 0 && arrayEmployees != NULL)
                {
                    for(i=0; i<len - 1; i++)
                    {
                        for(j=i+1; j<len; j++)
                        {
                            if(strcmp((arrayEmployees+j)->lastName, (arrayEmployees+i)->lastName) < 0)
                            {
                                auxiliar = (arrayEmployees+i);
                                (arrayEmployees+i) = (arrayEmployees+j);
                                (arrayEmployees+j) = auxiliar;
                            }
                            else if(strcmp((arrayEmployees+j)->lastName, (arrayEmployees+i)->lastName) == 0 && (arrayEmployees+j)->sector < (arrayEmployees+i)->sector)
                            {
                                auxiliar = (arrayEmployees+i);
                                (arrayEmployees+i) = (arrayEmployees+j);
                                (arrayEmployees+j) = auxiliar;
                            }
                        }
                    }
                retorno = 0;
                break;
            case 1:
                for(i = 0; i < len - 1; i++)
                {
                    for(j = i + 1; j < len; j++)
                    {
                        if(strcmp((arrayEmployees+j)->lastName, (arrayEmployees+i)->lastName) > 0)
                        {
                            auxiliar = (arrayEmployees+i);
                            (arrayEmployees+i) = (arrayEmployees+j);
                            (arrayEmployees+j) = auxiliar;
                        }
                        else if(strcmp((arrayEmployees+j)->lastName, (arrayEmployees+i)->lastName) == 0 && (arrayEmployees+j)->sector > (arrayEmployees+i)->sector)
                        {
                            auxiliar = (arrayEmployees+i);
                            (arrayEmployees+i) = (arrayEmployees+j);
                            (arrayEmployees+j) = auxiliar;
                        }
                    }
                }
                retorno = CORRECTO;
                break;
            }
        }
    }
    return retorno;
}


