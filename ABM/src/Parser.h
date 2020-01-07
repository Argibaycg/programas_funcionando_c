#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int parser_parseRevelados(char* fileName, LinkedList* listaRevelados);
int generarInforme_saveAsText(char* path , LinkedList* listaRevelados, int total, int mayorUno, int mayorDos, int polaroid, float mayorPrecio);
int generarArchivoFilter(char* fileName,LinkedList* listaFiltrada);
int generarArchivoBinario(char* path , LinkedList* listaFiltrada);

#endif // PARSER_H_INCLUDED
