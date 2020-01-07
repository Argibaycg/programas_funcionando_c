#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Revelado
{
  int ID_Venta;
  char Fecha_Venta[128];
  char Tipo_Foto[128];
  int Cantidad;
  float Precio_Unitario;
  char CUIT_Cliente[128];
};
typedef struct S_Revelado Revelado;

Revelado* revelado_new();
Revelado* revelado_newParametros(char* ID_Venta,char* Fecha_Venta,char* Tipo_Foto,char* Cantidad,char* Precio_Unitario,char* CUIT_Cliente);
void employee_delete();

int revelados_setId(Revelado* this,int id);
int revelados_getId(Revelado* this,int* id);

int revelados_setFecha(Revelado* this,char* nombre);
int revelados_getFecha(Revelado* this,char* nombre);

int revelados_setTipo(Revelado* this,char* tipo);
int revelados_getTipo(Revelado* this,char* tipo);

int revelados_setCantidad(Revelado* this,int cantidad);
int revelados_getCantidad(Revelado* this,int* cantidad);

int revelados_setPrecio(Revelado* this,float precio);
int revelados_getPrecio(Revelado* this,float* precio);

int revelados_setCUIT(Revelado* this,char* cuit);
int revelados_getCUIT(Revelado* this,char* cuit);

int revelados_totalesCount(void* elemento);
int revelados_ventaMayor150(void* elemento);
int revelados_ventaMayor300(void* elemento);
int revelados_polaroid(void* elemento);
float revelados_mayorPreciodeVenta(void* elemento);
int revelados_filtraPolaroid(void* elemento);

#endif // EMPLEADO_H_INCLUDED


