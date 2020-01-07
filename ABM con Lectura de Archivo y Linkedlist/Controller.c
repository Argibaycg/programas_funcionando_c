#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFileTexto;
	pFileTexto = fopen(path, "r");
	if (pFileTexto == NULL)
	{
		printf("El archivo no existe");
	}else
	{
		if(parser_EmployeeFromText(pFileTexto,pArrayListEmployee)==0)
		{
			fclose(pFileTexto);
			printf("Correcta lectura del archivo, el mismo se cerro.\n");
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFileBinario;

	if ((pFileBinario = fopen(path, "rb"))==NULL)
	{
		printf("El archivo no existe");
	}else
	{
		if(parser_EmployeeFromBinary(pFileBinario,pArrayListEmployee)==0)
		{
			fclose(pFileBinario);
			printf("Correcta lectura del archivo, el mismo se cerro.\n");
			retorno = 0;
		}
	}

	return retorno;
}

int controller_getMaxId(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int largoLinkedlist;
    int i;
    int bufferId;
	int idMaximo =0;
    Employee* pEmpleado;

    if(pArrayListEmployee != NULL)
    {
        largoLinkedlist=ll_len(pArrayListEmployee);
        for(i=0;i<largoLinkedlist;i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);
            if(idMaximo<bufferId)
            {
            	idMaximo=bufferId;
            }
        }
        retorno=idMaximo;
    }
    return retorno;
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
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id)
{
	int i;
	int largoLinkedlist;
	Employee* pEmpleado;
	if(pArrayListEmployee != NULL)
	{
		 largoLinkedlist = ll_len(pArrayListEmployee);
		 for(i=0;i==id;i++)
		 {
			 pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
			 employee_getId(pEmpleado,&id);
			 return i;
		 }
	}
	return -1;
}
/** \brief Alta de empleados
 * \param int id
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
    char bufferName[1024];
    int bufferHoras;
    int bufferSueldo;
    Employee* pEmpleado;
    if(pArrayListEmployee != NULL)
    {
		if(utn_getString("Ingrese el nombre del empleado\n","Nombre no valido.\n",bufferName)==0 &&
		   utn_getNumber(&bufferHoras,1000,1,2,"Ingrese las horas trabajadas.\n","Horas no validas.\n")== 0 &&
	   	   utn_getNumber(&bufferSueldo,90000,1,2,"Ingrese el sueldo.\n","Sueldo no valido.\n")== 0)
		{
			id++;
			pEmpleado =	employee_new();
			employee_setId(pEmpleado,id);
			employee_setNombre(pEmpleado,bufferName);
			employee_setHorasTrabajadas(pEmpleado,bufferHoras);
			employee_setSueldo(pEmpleado,bufferSueldo);
			ll_add(pArrayListEmployee,pEmpleado);
			retorno = 0;
		}

    }
    return retorno;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int largoLinkedlist;
    int i;
    char bufferName[1024];
    int bufferHoras;
    int bufferSueldo;
    int bufferId;
    int auxId;
    char respuesta;
    Employee* pEmpleado;

    if(pArrayListEmployee!= NULL)
    {

        largoLinkedlist=ll_len(pArrayListEmployee);
        utn_getNumber(&auxId,largoLinkedlist+1,0,2,"Ingrese el id del empleado a modificar.\n","No ingreso un id valido.\n");

        for(i=0; i<largoLinkedlist ;i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);

            employee_getNombre(pEmpleado,bufferName);
            employee_getHorasTrabajadas(pEmpleado,&bufferHoras);
            employee_getSueldo(pEmpleado,&bufferSueldo);

            if(bufferId==auxId)
            {
            	printf("Se modificara el empleado con estos datos: Nombre : %s  Horas trabajadas: %d  Sueldo: %d,\n",bufferName,bufferHoras,bufferSueldo);

            	utn_getString("Desea continuar modificando los datos? %d s / n?","Ingreso erroneo.\n",&respuesta);
            	if(respuesta == 's')
            	{
					if(respuesta == 's' && utn_getString("Ingrese el nombre del empleado\n","Nombre no valido.\n",bufferName)==0 &&
					   utn_getNumber(&bufferHoras,1000,1,2,"Ingrese las horas trabajadas.\n","Horas no validas.\n")== 0 &&
					   utn_getNumber(&bufferSueldo,90000,1,2,"Ingrese el sueldo.\n","Sueldo no valido.\n")== 0)
					{
						employee_setNombre(pEmpleado,bufferName);
						employee_setHorasTrabajadas(pEmpleado,bufferHoras);
						employee_setSueldo(pEmpleado,bufferSueldo);
						retorno = 0;
						break;
					}
            	}else{
            		printf("No se modifico ningun dato.\n");
            		break;
            	}
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int largoLinkedlist;
    int i;
    int bufferId;
    int auxId;
    char respuesta;
    Employee* pEmpleado;

    if(pArrayListEmployee!= NULL)
    {
        largoLinkedlist=ll_len(pArrayListEmployee);
    	utn_getNumber(&auxId,largoLinkedlist+1,0,2,"Ingrese el id del empleado a remover.\n","No ingreso un id valido.\n");

    	for(i=0; i<largoLinkedlist ;i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);

            if(bufferId==auxId)
            {
            	utn_getString("Se removera el empleado con el id s / n?","Ingreso erroneo",&respuesta);
            	if(respuesta == 's')
            	{
					ll_remove(pArrayListEmployee,i);
					retorno=0;
					break;
            	}
            }
        }
    }

    return retorno;
}

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int largoLinkedlist;
	int i;
	int id;
	char nombre[1024];
	int horasTrabajadas;
	int sueldo;
	Employee* pEmpleado;
	if(pArrayListEmployee != NULL)
	{
		largoLinkedlist = ll_len(pArrayListEmployee);

		for(i = 0; i < largoLinkedlist; i++)
		{
			pEmpleado = ll_get(pArrayListEmployee,i);
			employee_getId(pEmpleado,&id);
			employee_getNombre(pEmpleado,nombre);
			employee_getHorasTrabajadas(pEmpleado,&horasTrabajadas);
			employee_getSueldo(pEmpleado,&sueldo);
			printf("ID: %d    Nombre: %s   	Horas Trabajadas: %d  	 Sueldo: %d\n",id,nombre,horasTrabajadas,sueldo);

		}
	}

    return 1;
}

/** \brief compara por nombre
 * \param void* paramOne
 * \param void* paramTwo
 * \return int
 */
int controller_sortByName(void* paramOne, void* paramTwo)
{
    char bufferNameA[1024];
    char bufferNameB[1024];
    int retorno = -1;

    if(paramOne!=NULL && paramTwo!=NULL)
    {
		employee_getNombre(paramOne,bufferNameA);
		employee_getNombre(paramTwo,bufferNameB);

		if(strcmp(bufferNameA,bufferNameB)>0)
		{
			retorno = 1;
		}
    }

    return retorno;
}

/** \brief compara por horas trabajadas
 * \param void* paramOne
 * \param void* paramTwo
 * \return int
 */
int controller_sortByHours(void* paramOne, void* paramTwo)
{
    int retorno = -1;
    Employee* pEmpleadoOne;
    Employee* pEmpleadoTwo;

    if(paramOne!=NULL && paramTwo!=NULL)
    {
    	pEmpleadoOne = (Employee*)paramOne;
    	pEmpleadoTwo = (Employee*)paramTwo;
        if(pEmpleadoOne->horasTrabajadas > pEmpleadoTwo->horasTrabajadas)
        {
        	retorno = 1;
        }

    }
    return retorno;
}

/** \brief compara por salario
 * \param void* paramOne
 * \param void* paramTwo
 * \return int
 */
int controller_sortBySalary(void* paramOne, void* paramTwo)
{
    int retorno = -1;
    Employee* pEmpleadoOne;
    Employee* pEmpleadoTwo;

    if(paramOne!=NULL && paramTwo!=NULL)
    {
    	pEmpleadoOne = (Employee*)paramOne;
    	pEmpleadoTwo = (Employee*)paramTwo;
        if(pEmpleadoOne->sueldo > pEmpleadoTwo->sueldo)
        {
        	retorno = 1;
        }

    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int opcion;
    char respuesta;
    if(pArrayListEmployee!=NULL)
    {
    	do
    	{
    		printf("1.Ordenar por Nombre.\n");
    		printf("2.Ordenar por Salario.\n");
    		printf("3.Ordenar por Horas de trabajo.\n");
    		printf("4.Imprimir listado de empleados.\n");
    		printf("5.Volver al menu principal.\n");

    		utn_getInt(&opcion);
    		switch(opcion)
    		{
    		case 1:
    			if(ll_sort(pArrayListEmployee,controller_sortByName,1)==0)
    			{
    				printf("Se ordeno la nomina por nombre\n");
    			}
    			utn_getString("Desea imprimir la nomina? s / n?","Ingreso erroneo",&respuesta);
    			if(respuesta == 's')
    			{
    				controller_ListEmployee(pArrayListEmployee);
    			}
    			break;
    		case 2:
    			if(ll_sort(pArrayListEmployee,controller_sortBySalary,1)==0)
    			{
    				printf("Se ordeno la nomina por salario\n");
    			}
    			utn_getString("Desea imprimir la nomina? s / n?","Ingreso erroneo",&respuesta);
    			if(respuesta == 's')
    			{
    				controller_ListEmployee(pArrayListEmployee);
    			}
    			break;
    		case 3:
    			if(ll_sort(pArrayListEmployee,controller_sortByHours,1)==0){
    				printf("Se ordeno la nomina por horas trabajadas\n");
    			}
    			utn_getString("Desea imprimir la nomina? s / n?","Ingreso erroneo",&respuesta);
    			if(respuesta == 's')
    			{
    				controller_ListEmployee(pArrayListEmployee);
    			}
    			break;
    		case 4:
    			controller_ListEmployee(pArrayListEmployee);
    			break;
    		case 5:
    			break;
    		default:
    			printf("Opcion Incorrecta\n");
    			break;
    		}
    	}while(opcion != 5);
    	retorno=0;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int len = 0;
	int auxId;
	char auxNombre[1024];
	int auxHoras;
	int auxSueldo;

	FILE* pFileTexto;
	pFileTexto = fopen(path, "w");
	Employee* pEmployee=NULL;

	if(pArrayListEmployee!=NULL && path != NULL)
	{
		len = ll_len(pArrayListEmployee);

		if(pFileTexto != NULL)
		{
			for(i=0; i < len; i++)
			{
				pEmployee = ll_get(pArrayListEmployee,i);
				employee_getId(pEmployee,&auxId);
				employee_getNombre(pEmployee,auxNombre);
				employee_getHorasTrabajadas(pEmployee,&auxHoras);
				employee_getSueldo(pEmployee,&auxSueldo);
				fprintf(pFileTexto,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
			}
			printf("EL archivo se guardo exitosamente\n");
			retorno = 0;
	        }else
	        {
	        	printf("Hubo un error al guardar el archivo\n");
	        }
	}
		fclose(pFileTexto);
	    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int len;

	FILE* pFileBin=NULL;
	Employee* pEmployee=NULL;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		len = ll_len(pArrayListEmployee);
		pFileBin = fopen(path, "wb");

		if(pFileBin != NULL)
		{
			for(i=0; i < len; i++)
			{
				pEmployee = (Employee*)ll_get(pArrayListEmployee,i);

				if(pEmployee!=NULL)
				{
					fwrite(pEmployee,sizeof(Employee),1,pFileBin);
				}
			}
			retorno = 0;
			printf("El archivo se guardo exitosamente.\n");
		}else
		{
			printf("Error en el guardado de el archivo binario.\n");
		}
			fclose(pFileBin);
	}
	return retorno;
}

