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
    LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));
    if (this != NULL)
    {
        this->pFirstNode = NULL;
        this->size = 0;
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
    if (this != NULL)
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
    Node* auxNode = NULL;
    if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        auxNode = this->pFirstNode;
        for(i = 0; i < nodeIndex; i++)
        {
            auxNode = auxNode->pNextNode;
        }
    }
    return auxNode;
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
    Node* newNode = (Node*) malloc(sizeof(Node));
    Node* auxNode = NULL;
    Node* auxNode2 = NULL;
    if (this != NULL && newNode != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        newNode->pElement = pElement;
        if (nodeIndex == 0)
        {
            newNode->pNextNode = this->pFirstNode;
            this->pFirstNode = newNode;
        } else
            {
                auxNode = getNode(this, nodeIndex-1);
                auxNode2 = auxNode->pNextNode;
                auxNode->pNextNode = newNode;
                newNode->pNextNode = auxNode2;
            }
            returnAux = 0;
            this->size++;
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
    if (this != NULL)
    {
        if(!addNode(this, ll_len(this), pElement))
           {
               returnAux = 0;
           }
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
    Node* auxNode = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this, index);
        returnAux = auxNode->pElement;
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
    Node* auxNode = NULL;
    if (this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this, index);
        auxNode->pElement = pElement;
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
    Node* auxNode = NULL;
    Node* auxNode2 = NULL;
    if (this != NULL && index >= 0 && index < ll_len(this))
    {
        if (index == 0)
        {
            auxNode = getNode(this, index);
            this->pFirstNode = auxNode->pNextNode;
            free(auxNode);
        } else if (index > 0 && index < ll_len(this))
            {
                auxNode = getNode(this, index-1);
                auxNode2 = getNode(this, index);
                auxNode->pNextNode = auxNode2->pNextNode;
                free(auxNode2);
            } else if (index == ll_len(this))
                {
                    auxNode = getNode(this, index);
                    free(auxNode);
                }
        this->size--;
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
    int i;
    if (this != NULL)
    {
        for (i = ll_len(this)-1; i >= 0; i--)
        {
            ll_remove(this, i);
        }
        returnAux = 0;
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
    if (this != NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux = 0;
        }
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
    Node* auxNode = NULL;
    int i;
    if (this != NULL)
    {
        for (i = 0; i < ll_len(this); i++)
        {
            auxNode = getNode(this, i);
            if(auxNode != NULL && auxNode->pElement == pElement)
            {
                returnAux = i;
                break;
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
    if (this != NULL)
    {
        // Utilizacion de operador ternario (sirve para C, C#, JAVA)
        returnAux = ll_len(this) == 0 ? 1:0;
        //returnAux = ll_len(this) ? 0 : 1;
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
    return addNode(this, index, pElement);
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
    void* returnAux = ll_get(this, index);
    ll_remove(this, index);
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
    // AVISO: Esta funcion permite pElement = NULL;
    if (this != NULL)
    {
        returnAux = ll_indexOf(this, pElement) == -1 ? 0:1;
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
    void* auxElement = NULL;
    int i;
    if (this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for (i = 0; i < ll_len(this2); i++)
        {
            auxElement = ll_get(this, i);
            if(!ll_contains(this2, auxElement))
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
                                (puntero a la nueva lista) Si OK
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    if (this != NULL && from >= 0 && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        if (cloneArray != NULL)
        {
            for(i = from; i < to; i++)
            {
                ll_add(cloneArray, ll_get(this, i));
            }
        }
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this, 0, ll_len(this));
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
    int returnAux = -1;
    int i, j, auxLen;
    void* auxElement;
    if (this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        auxLen = ll_len(this);
        for (i = 0; i < auxLen - 1; i++)
        {
            for (j = i + 1; j < auxLen; j++) /* Burbujeo */
            {
                if ((pFunc(ll_get(this, i), ll_get(this, j)) > 0 && order) || (pFunc(ll_get(this, i), ll_get(this, j)) < 0 && !order))
                {
                    auxElement = ll_get(this, i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, auxElement);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Filtra los elementos del Linkedlist recibido como parametro y devuelve
 *         una nueva lista con los elmentos filtrados.
 * \param LinkedList* this      | Lista Original
 * \param int (*pFunc)(void*)   | Funcion ordenadora
 * \return LinkedList* listaFiltrada    -   NULL Error: Si la lista o la función devuelve NULL
 *                                          LinkedList* La lista filtrada
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* listaFiltrada = NULL;
    int i, auxLen;
    if (this != NULL && pFunc != NULL)
    {
        auxLen = ll_len(this);
        listaFiltrada = ll_newLinkedList();
        if (listaFiltrada != NULL)
        {
            for (i = 0; i < auxLen; i++)
            {
                if (pFunc(ll_get(this, i)) > 0)
                {
                    ll_add(listaFiltrada, ll_get(this, i));
                }
            }
        }
    }
    return listaFiltrada;
}

