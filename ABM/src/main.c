#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Revelados.h"
#include "LinkedList.h"
#include "Parser.h"

int main()
{
	int totalRevelado;
	int cantidadMayor150;
	int cantidadMayor300;
	int cantidadPolaroid;
	int mayorPrecioVenta;

	LinkedList* listaRevelados = ll_newLinkedList();
	LinkedList* listaPolaroid = NULL;

    if(parser_parseRevelados("data.csv",listaRevelados)==1)
    {
        
        printf("Correcta Lectura de arhivos\n");

        totalRevelado = ll_count(listaRevelados,revelados_totalesCount);
        cantidadMayor150 = ll_count(listaRevelados,revelados_ventaMayor150);
        cantidadMayor300 = ll_count(listaRevelados,revelados_ventaMayor300);
        cantidadPolaroid = ll_count(listaRevelados,revelados_polaroid);
        mayorPrecioVenta = ll_findMaximo(listaRevelados,revelados_mayorPreciodeVenta);

        listaPolaroid = ll_filterPolaroid(listaRevelados,revelados_filtraPolaroid);

		if(generarInforme_saveAsText("informe.txt",listaRevelados,totalRevelado,cantidadMayor150,cantidadMayor300,cantidadPolaroid,mayorPrecioVenta)==0)
		{
			printf("Archivo informe generado correctamente\n");
		}else
		{
			printf("Error generando archivo\n");
		}

		if(generarArchivoFilter("listaPolaroid.csv",listaPolaroid)==1)
        {
        	printf("Se guardo la lista en un archivo nuevo\n");
        }else
        {
        	printf("No se puedo guardar la nueva lista\n");
        }

		if(generarArchivoBinario("ListaFiltrada.bin",listaPolaroid)==1)
		{
        	printf("Se guardo la lista en un archivo binario\n");
		}else
		{
			printf("Error generando archivo\n");
		}
    }else
    {
    	printf("Error leyendo revelados\n");

    }

    return 0;
}


