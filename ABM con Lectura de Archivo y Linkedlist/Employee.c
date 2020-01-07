#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/** \brief asigna espacio de memoria para un nuevo empleado
 * \return puntero del espacio de memoria
 */
Employee* employee_new(){

	Employee* empleado = (Employee*)malloc( sizeof(Employee));

	if(empleado != NULL)
	{
		empleado->id = 0;
		strcpy(empleado->nombre, "");
		empleado->horasTrabajadas = 0;
		empleado->sueldo = 0;
	}

return empleado;
}

/** \brief asigna espacio de memoria para em empleado y asigna por parametro los campos de la estructura
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldo
 * \return puntero del espacio de memoria
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{

	Employee* empleado = employee_new();

	if(empleado != NULL)
	{
		employee_setId(empleado,atoi(idStr));
		employee_setNombre(empleado,nombreStr);
		employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr));
		employee_setSueldo(empleado,atoi(sueldo));
	}
return empleado;
}

/** \brief asigna el id al campo del empleado
 * \param Employee* this
 * \param int id
 * \return int
 */
int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el id del campo del empleado
 * \param Employee* this
 * \param int id
 * \return int
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

/** \brief asigna el nombre al campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el nombre trabajadas del campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;

}

/** \brief asigna las horas trabajadas al campo del empleado
 * \param Employee* this
 * \param int horasTrabajadas
 * \return int
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene las horas trabajadas del campo del empleado
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return int
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

/** \brief asigna el sueldo al campo del empleado
 * \param Employee* this
 * \param int sueldo
 * \return int
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el sueldo del campo del empleado
 * \param Employee* this
 * \param int sueldo
 * \return int
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}

	return retorno;
}


