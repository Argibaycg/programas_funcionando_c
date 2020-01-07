#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int cantidadLeida;
	char id[1024],nombre[1024],horasTrabajadas[1024],sueldo[1024];
	Employee* pEmpleado;
	cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

	do {
			cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
			if (cantidadLeida == 4)
			{
				pEmpleado =	employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				ll_add(pArrayListEmployee,pEmpleado);
				retorno = 0;
			}else
			{
				printf("Error en la lectura de datos.\n");
				retorno = -1;
				break;
			}
		} while (!feof(pFile));
		return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int cantidad = 0;
	int auxId;
    char auxNombre[50];
    int auxHoras;
	int auxSueldo;
    Employee* pEmployee;

    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        do
        {
        	pEmployee = employee_new();
            cantidad = fread(pEmployee,sizeof(Employee),1,pFile);
            if(cantidad==1)
            {
				if(employee_getId(pEmployee,&auxId)==0 && employee_getNombre(pEmployee,auxNombre)==0 &&
				   employee_getHorasTrabajadas(pEmployee,&auxHoras)==0 && employee_getSueldo(pEmployee,&auxSueldo)==0)
				{
					ll_add(pArrayListEmployee,pEmployee);
					retorno = 0;
				}
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
    return retorno;
}
