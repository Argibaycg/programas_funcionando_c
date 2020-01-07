#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList*)malloc(sizeof(LinkedList*));
    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;

	if(this != NULL)
	{
		returnAux = this->size;
	}
		return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	Node* auxiliarNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		auxiliarNode = this->pFirstNode;
		for(i = 0; i < nodeIndex; i++)
		{
			auxiliarNode = auxiliarNode->pNextNode;
		}
		return auxiliarNode;
	}else
	{
		return NULL;
	}
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* auxiliarNode = NULL;
    Node* auxiliarNodePrevious = NULL;

    auxiliarNode = (Node*)malloc(sizeof(Node*));
    if(this != NULL && auxiliarNode != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	auxiliarNode->pElement = pElement;

    	if(nodeIndex == 0)
    	{
    		auxiliarNode->pNextNode = this->pFirstNode;
    		this->pFirstNode = auxiliarNode;
    		this->size++;
    		returnAux = 0;
    	}else
    	{
    		auxiliarNodePrevious = getNode(this,nodeIndex-1);
    		if(auxiliarNodePrevious != NULL)
    		{
    			auxiliarNode->pNextNode = auxiliarNodePrevious->pNextNode;
    			auxiliarNodePrevious->pNextNode = auxiliarNode;
    			this->size++;
    			returnAux = 0;
    		}
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	addNode(this,len,pElement);
    	returnAux = 0;
    }


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxiliarNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxiliarNode = getNode(this,index);
    	returnAux = auxiliarNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxiliarNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxiliarNode = getNode(this,index);
    	auxiliarNode->pElement = pElement;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxiliarToRemove = NULL;
    Node* auxiliarPrevious = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxiliarToRemove = getNode(this,index);
    	if(index == 0)
    	{
    		this->pFirstNode = auxiliarToRemove->pNextNode;
    		this->size--;
    	}else
    	{
    		auxiliarPrevious = getNode(this,index-1);
    		auxiliarPrevious->pNextNode = auxiliarToRemove->pNextNode;
    		this->size--;
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* auxiliarNode;

    if(this != NULL)
    {
    	if(len >= 0)
    	{
    		while(len >= 0)
    		{
    			auxiliarNode = ll_get(this,len);
    			ll_remove(this,len);
    			free(auxiliarNode);
    			len--;
    		}
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    int i;
    Node* indexNode = NULL;

    if(this != NULL)
    {
    	for(i = 0; i < len ; i++)
    	{
    		indexNode = getNode(this,i);

    		if(indexNode != NULL)
    		{
    			if(indexNode->pElement == pElement)
    			{
    				returnAux = i;
    				break;
    			}
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this) != 0)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	if(addNode(this,index,pElement)==0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* auxiliarToRemove = NULL;
    Node* auxiliarPrevious = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxiliarToRemove = getNode(this,index);
    	if(auxiliarToRemove != NULL)
    	{
			if(index==0)
			{
				returnAux = auxiliarToRemove->pElement;
				this->pFirstNode = auxiliarToRemove->pNextNode;
				this->size--;
			}
			else
			{
				returnAux = auxiliarToRemove->pElement;
				auxiliarPrevious = getNode(this,index-1);
				auxiliarPrevious->pNextNode = auxiliarToRemove->pNextNode;
				this->size--;
			}
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_indexOf(this,pElement) != -1)
   		{
   			returnAux=1;
   		}
    	else
   		{
   			returnAux=0;
   		}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;

    if(this != NULL && this2 != NULL)
    {

    	int len = ll_len(this2);

    	if(len == 0)
    	{
    		returnAux = 0;
    	}

    	for(i = 0; i < len; i++)
    	{
    		if(ll_contains(this,ll_get(this2,i))==1)
    		{
    			returnAux = 1;
    		}else
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* subList = NULL;
    Node* auxiliarNode;
    int i;

    if(this != NULL && from >= 0 && from <= ll_len(this) && to > from && to <= ll_len(this))
    {
    	subList = ll_newLinkedList();

    	if(subList != NULL)
    	{
    		for(i = from; i < to; i++)
    		{
    			auxiliarNode = ll_get(this,i);
    			if(auxiliarNode != NULL)
    			{
    				ll_add(subList,auxiliarNode);
    			}
    		}
    	}
    }
    return subList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* clone = NULL;

    if(this != NULL)
    {
    	clone = ll_subList(this,0,ll_len(this));
    }

    return clone;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    void* paramOne;
    void* paramTwo;
    void* auxiliarParam;
    int i;
    int flag;
    int len;

    if(this!=NULL &&pFunc!= NULL  && (order == 0 || order == 1))
    {
	    len = ll_len(this);
	    do
	    {
		    flag = 0;

	 	    for(i=0; i<len-1; i++)
	  	    {
			    paramOne = ll_get(this,i);
			    paramTwo = ll_get(this,i+1);

			    if((pFunc(paramOne, paramTwo) < 0 && order == 0)||(pFunc(paramOne, paramTwo) > 0 && order == 1))
			    {
				    auxiliarParam = paramOne;
				    paramOne = paramTwo;
				    paramTwo = auxiliarParam;
				    flag = 1;
			    }
			    ll_set(this,i,paramOne);
			    ll_set(this,i+1,paramTwo);
			    returnAux = 0;
		    }
	    }
	    while(flag == 1);
    }
    return returnAux;
}

int ll_map(LinkedList* this,void (*pFunc)(void* p))
{
	int returnAux = -1;
	int i;
	int len;
	Node* auxiliar;

	if(this != NULL)
	{
		len = ll_len(this);
		for(i = 0; i < len; i++)
		{
			auxiliar = ll_get(this,i);
			if(auxiliar != NULL)
			{
				pFunc(auxiliar);
			}
		}

	}


	return returnAux;
}
