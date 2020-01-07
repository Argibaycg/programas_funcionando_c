#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


/*
int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


enum colors {lets,find,course};
int main()
{
	printf("%d %d %d",course,lets,find);
	return 0;
}
*/


int main()
{
    int option;
    int bufferId;
    LinkedList* listaEmpleados = ll_newLinkedList();



    do{
    	 printf("Menu:\n"
    	    	   "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    	    	   "2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
    			   "3. Alta de empleado\n"
    			   "4. Modificar datos de empleado\n"
    			   "5. Baja de empleado\n"
    			   "6. Listar empleados\n"
    			   "7. Ordenar empleados\n"
    			   "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    			   "9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
    			   "10. Salir.\n");
    	 utn_getInt(&option);

        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==-1)
				{
                	printf("Error en la carga del archivo.\n");
				}else{
					bufferId = controller_getMaxId(listaEmpleados);
				}
                break;
            case 2:
            	if(controller_loadFromBinary("dataGuardado.bin",listaEmpleados)==-1)
            	{
            		printf("Error en la carga del archivo.\n");
            	}else{
            		bufferId = controller_getMaxId(listaEmpleados);
            	}
            	break;
            case 3:
            	if(controller_addEmployee(listaEmpleados,bufferId)==0)
            	{
            		bufferId++;
            	}
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	controller_saveAsText("dataGuardado.csv",listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary("dataGuardado.bin",listaEmpleados);
            	break;
            case 10:

            	break;
        }
    }while(option != 10);

    return 0;

}
