#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Revelados.h"
#include "LinkedList.h"
#include "Parser.h"


/** \brief asigna espacio de memoria para un nuevo empleado
 * \return puntero del espacio de memoria
 */
Revelado* revelado_new(){

	Revelado* revelado = (Revelado*)malloc( sizeof(Revelado));

	if(revelado != NULL)
	{
		revelado->ID_Venta = 0;
		strcpy(revelado->Fecha_Venta, "");
		strcpy(revelado->Tipo_Foto, "");
		revelado->Cantidad = 0;
		revelado->Precio_Unitario = 0;
		strcpy(revelado->CUIT_Cliente, "");
	}
return revelado;
}

/** \brief asigna espacio de memoria para em empleado y asigna por parametro los campos de la estructura
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldo
 * \return puntero del espacio de memoria
 */
Revelado* revelado_newParametros(char* ID_Venta,char* Fecha_Venta,char* Tipo_Foto,char* Cantidad,char* Precio_Unitario,char* CUIT_Cliente)
{
	Revelado* revelado = revelado_new();

	if(revelado != NULL)
	{
		revelados_setId(revelado,atoi(ID_Venta));
		revelados_setFecha(revelado,Fecha_Venta);
		revelados_setTipo(revelado,Tipo_Foto);
		revelados_setCantidad(revelado,atoi(Cantidad));
		revelados_setPrecio(revelado,atof(Precio_Unitario));
		revelados_setCUIT(revelado,CUIT_Cliente);
	}
return revelado;
}

/** \brief asigna el id al campo del empleado
 * \param Employee* this
 * \param int id
 * \return int
 */
int revelados_setId(Revelado* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->ID_Venta = id;
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el id del campo del empleado
 * \param Employee* this
 * \param int id
 * \return int
 */
int revelados_getId(Revelado* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->ID_Venta;
		retorno = 0;
	}

	return retorno;
}

/** \brief asigna el nombre al campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int revelados_setFecha(Revelado* this,char* fecha)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(this->Fecha_Venta, fecha);
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el nombre trabajadas del campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int revelados_getFecha(Revelado* this,char* fecha)
{
	int retorno = -1;

	if(this != NULL && fecha != NULL)
	{
		strcpy(fecha, this->Fecha_Venta);
		retorno = 0;
	}

	return retorno;

}

/** \brief asigna el nombre al campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int revelados_setTipo(Revelado* this,char* tipo)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(this->Tipo_Foto, tipo);
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el nombre trabajadas del campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int revelados_getTipo(Revelado* this,char* tipo)
{
	int retorno = -1;

	if(this != NULL && tipo != NULL)
	{
		strcpy(tipo, this->Tipo_Foto);
		retorno = 0;
	}

	return retorno;

}
/** \brief asigna las horas trabajadas al campo del empleado
 * \param Employee* this
 * \param int horasTrabajadas
 * \return int
 */
int revelados_setCantidad(Revelado* this,int cantidad)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->Cantidad = cantidad;
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene las horas trabajadas del campo del empleado
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return int
 */
int revelados_getCantidad(Revelado* this,int* cantidad)
{
	int retorno = -1;

	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->Cantidad;
		retorno = 0;
	}

	return retorno;
}

/** \brief asigna el sueldo al campo del empleado
 * \param Employee* this
 * \param int sueldo
 * \return int
 */
int revelados_setPrecio(Revelado* this,float precio)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->Precio_Unitario = precio;
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el sueldo del campo del empleado
 * \param Employee* this
 * \param int sueldo
 * \return int
 */
int revelados_getPrecio(Revelado* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->Precio_Unitario;
		retorno = 0;
	}

	return retorno;
}

int revelados_setCUIT(Revelado* this,char* cuit)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(this->CUIT_Cliente, cuit);
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el nombre trabajadas del campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int revelados_getCUIT(Revelado* this,char* cuit)
{
	int retorno = -1;

	if(this != NULL && cuit != NULL)
	{
		strcpy(cuit, this->CUIT_Cliente);
		retorno = 0;
	}

	return retorno;

}

int revelados_totalesCount(void* elemento)
{
	int returnAux = -1;
	Revelado* auxRevelado;
	auxRevelado = (Revelado*) elemento;

	returnAux = auxRevelado->Cantidad;

	return returnAux;
}

int revelados_ventaMayor150(void* elemento)
{
	int returnAux = -1;
	Revelado* auxRevelado;
	auxRevelado = (Revelado*) elemento;
	float totalVenta;

	totalVenta = auxRevelado->Precio_Unitario * auxRevelado->Cantidad;

	if(totalVenta > 150)
	{
		returnAux = 1;
	}

	return returnAux;
}

int revelados_ventaMayor300(void* elemento)
{
	int returnAux = -1;
	Revelado* auxRevelado;
	auxRevelado = (Revelado*) elemento;
	float totalVenta;

	totalVenta = auxRevelado->Precio_Unitario * auxRevelado->Cantidad;

	if(totalVenta > 300)
	{
		returnAux = 1;
	}

	return returnAux;
}

float revelados_mayorPreciodeVenta(void* elemento)
{
	int returnAux = -1;
	Revelado* auxRevelado;
	auxRevelado = (Revelado*) elemento;
	float totalVenta;

	totalVenta = auxRevelado->Precio_Unitario * auxRevelado->Cantidad;
	returnAux = totalVenta;


	return returnAux;
}

int revelados_polaroid(void* elemento)
{
	int returnAux = -1;
	Revelado* auxRevelado;
	auxRevelado = (Revelado*) elemento;

	if(strcmp(auxRevelado->Tipo_Foto,"POLAROID_11x9") == 0 || strcmp(auxRevelado->Tipo_Foto,"POLAROID_10x10") == 0)
	{
		returnAux = auxRevelado->Cantidad;
	}

	return returnAux;
}

int revelados_filtraPolaroid(void* elemento)
{
	int returnAux = -1;
	Revelado* auxRevelado;
	auxRevelado = (Revelado*) elemento;

	if(strcmp(auxRevelado->Tipo_Foto,"POLAROID_11x9") == 0 || strcmp(auxRevelado->Tipo_Foto,"POLAROID_10x10") == 0)
	{
		returnAux = 1;
	}

	return returnAux;
}
