#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Revelados.h"
#include "LinkedList.h"
#include "Parser.h"

int parser_parseRevelados(char* fileName, LinkedList* listaRevelados)
{
	int retorno = -1;
	int cantidadLeida;
	char ID_Venta[1024],Fecha_Venta[1024],Tipo_Foto[1024],Cantidad[1024],Precio_Unitario[1024],CUIT_Cliente[1024];
	Revelado* pRevelado;
	FILE *pFile;

	pFile = fopen(fileName,"r");

	if(listaRevelados != NULL && pFile != NULL)
	{
		cantidadLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ID_Venta,Fecha_Venta,Tipo_Foto,Cantidad,Precio_Unitario,CUIT_Cliente);

		do {
				cantidadLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ID_Venta,Fecha_Venta,Tipo_Foto,Cantidad,Precio_Unitario,CUIT_Cliente);
				if (cantidadLeida == 6)
				{
					pRevelado =	revelado_newParametros(ID_Venta,Fecha_Venta,Tipo_Foto,Cantidad,Precio_Unitario,CUIT_Cliente);
					ll_add(listaRevelados,pRevelado);
					retorno = 1;
				}else
				{
					printf("Error en la lectura de datos.\n");
					retorno = -1;
					break;
				}
			} while (!feof(pFile));
	}
		return retorno;
}

int generarInforme_saveAsText(char* path , LinkedList* listaRevelados, int total, int mayorUno, int mayorDos, int polaroid,float mayorPrecio)
{
	int retorno = -1;
	FILE* pFileTexto;
	pFileTexto = fopen(path, "w");

	if(listaRevelados!=NULL && path != NULL)
	{

		if(pFileTexto != NULL)
		{
				fprintf(pFileTexto,"********************\n");
				fprintf(pFileTexto,"Informe de ventas\n");
				fprintf(pFileTexto,"********************\n");
				fprintf(pFileTexto,"- Cantidad de fotos reveladas totales: %d\n", total);
				fprintf(pFileTexto,"- Cantidad de ventas por un monto mayor a $150: %d\n", mayorUno);
				fprintf(pFileTexto,"- Cantidad de ventas por un monto mayor a $300: %d\n", mayorDos);
				fprintf(pFileTexto,"- Cantidad de fotos polaroids reveladas: %d\n",polaroid);
				fprintf(pFileTexto,"- Cantidad de fotos polaroids reveladas: %.2f\n",mayorPrecio);
				fprintf(pFileTexto,"********************\n");

			retorno = 0;
		}
	}
		fclose(pFileTexto);
	    return retorno;
}

int generarArchivoFilter(char* fileName,LinkedList* listaFiltrada)
{
	int retorno = -1;
	int i;
	int len = 0;
	int ID_Venta;
	char Fecha_Venta[1024];
	char Tipo_Foto[1024];
	int Cantidad;
	float Precio_Unitario;
	char CUIT_Cliente[1024];

	FILE* pFileTexto;
	pFileTexto = fopen(fileName, "w");
	Revelado* pRevelado = NULL;

	if(listaFiltrada!=NULL && pFileTexto != NULL)
	{
		len = ll_len(listaFiltrada);

		if(len >= 0)
		{
			for(i=0; i < len; i++)
			{
				pRevelado = ll_get(listaFiltrada,i);
				if(pRevelado != NULL)
				{
					ID_Venta = pRevelado->ID_Venta;
					strcpy(Fecha_Venta,pRevelado->Fecha_Venta);
					strcpy(Tipo_Foto,pRevelado->Tipo_Foto);
					Cantidad = pRevelado->Cantidad;
					Precio_Unitario = pRevelado->Precio_Unitario;
					strcpy(CUIT_Cliente,pRevelado->CUIT_Cliente);
				}
				fprintf(pFileTexto,"%d,%s,%s,%d,%f,%s\n",ID_Venta,Fecha_Venta,Tipo_Foto,Cantidad,Precio_Unitario,CUIT_Cliente);
			}
			retorno = 1;
		}
	}
		fclose(pFileTexto);
	    return retorno;
}

int generarArchivoBinario(char* path , LinkedList* listaFiltrada)
{
	int retorno = -1;
	int i;
	int len;

	FILE* pFileBin=NULL;
	Revelado* pRevelado=NULL;

	if(listaFiltrada!=NULL && path!=NULL)
	{
		len = ll_len(listaFiltrada);
		pFileBin = fopen(path, "wb");

		if(pFileBin != NULL)
		{
			for(i=0; i < len; i++)
			{
				pRevelado = ll_get(listaFiltrada,i);

				if(pRevelado!=NULL)
				{
					fwrite(pRevelado,sizeof(Revelado),1,pFileBin);
				}
			}
			retorno = 1;
		}
	}
	return retorno;
}

int parser_ReveladosFromBinary(FILE* pFile , LinkedList* this)
{
    int retorno = -1;
    int cantidad = 0;
    int ID_Venta;
    char Fecha_Venta[1024];
    char Tipo_Foto[1024];
    int Cantidad;
    float Precio_Unitario;
    char CUIT_Cliente[1024];
	Revelado* pRevelado;

    if(pFile!=NULL && this!= NULL)
    {
        do
        {
        	pRevelado = employee_new();
            cantidad = fread(pRevelado,sizeof(Revelado),1,pFile);
            if(cantidad==1)
            {
				if(revelados_getId(this,&ID_Venta)==0 && revelados_getFecha(this,Fecha_Venta)==0 &&
				   revelados_getTipo(this,Tipo_Foto)==0 && revelados_getCantidad(this,&Cantidad)==0 &&
				   revelados_getPrecio(this,&Precio_Unitario)==0 && revelados_getCUIT(this,CUIT_Cliente)==0)
				{
					ll_add(this,pRevelado);
					retorno = 0;
				}
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
    return retorno;
}

