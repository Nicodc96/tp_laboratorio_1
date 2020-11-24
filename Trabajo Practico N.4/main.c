#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/*
    Proyecto creado por Lautaro N. Díaz - 2do Cuatrimestre 2020
    Trabajo Practico N.4 de Laboratorio I
    -----------------------------------------------------------
    En este trabajo práctico adjuntaré el LinkedList desarrollado
    e iré utilizando cada una de sus funciones encontradas en la biblioteca
    utilizando una estructura eLibro como ejemplo.
*/

#define NUMLLGET 9 /* Modificar este valor hasta MAXIMO 9 para probar ll_get */
#define NUMLLSET 8 /* Modificar este valor hasta MAXIMO 9 para probar ll_set */
#define NUMLLREMOVE 3 /* Modificar este valor hasta MAXIMO 9 para probar ll_remove */
#define NUMLLPUSH 7 /* Modificar este valor hasta MAXIMO 9 para probar ll_push */
#define NUMLLPOP 1 /* Modificar este valor hasta MAXIMO 9 para probar ll_push */

typedef struct{
    char nombre[32];
    int AnioPublicacion;
    float precio;
    char genero[32];
}eLibro;

void mostrarElemento(eLibro* pElemento);
void mostrarElementos(LinkedList* lista);
void mostrarElementoIndex(LinkedList* lista, int index);
int ordenarPorAnio(void* libro, void* libro2);
int filtrarPorGenero(void* libro);

int main()
{
    // --------------------------------------------------------------------------------------- //
    LinkedList* listaDeLibros = ll_newLinkedList();
    if (listaDeLibros != NULL)
    {
        printf("-------------------- FUNCION ll_newLinkedList() ------------------\n");
        printf("Se ha creado una LinkedList con una lista de libros correctamente.\n\n");
        system("pause");
    }

    // --------------------------------------------------------------------------------------- //
    eLibro libro1 = {"Don Quijote", 1605, 1499.99, "Novela"};
    eLibro libro2 = {"El Cuervo", 1845, 849.99, "Poema"};
    eLibro libro3 = {"100 Anios de Soledad", 1982, 1739.99, "Realismo Magico"};
    eLibro libro4 = {"Colmillo Blanco", 1906, 1200.00, "Literatura infantil"};
    eLibro libro5 = {"La dama del Alba", 1944, 689.89, "Obra de teatro"};
    eLibro libro6 = {"Bodas de Sangre", 1933, 649.99, "Obra de teatro"};
    eLibro libro7 = {"Divina comedia", 1472, 499.79, "Epopeya"};
    eLibro libro8 = {"1984", 1949, 999.99, "Ciencia Ficcion"};
    eLibro libro9 = {"El principito", 1943, 399.99, "Literatura Infantil"};
    eLibro libro10 = {"Moby-Dick", 1851, 2999.99, "Novela"};

    ll_add(listaDeLibros, &libro1);
    ll_add(listaDeLibros, &libro2);
    ll_add(listaDeLibros, &libro3);
    ll_add(listaDeLibros, &libro4);
    ll_add(listaDeLibros, &libro5);
    ll_add(listaDeLibros, &libro6);
    ll_add(listaDeLibros, &libro7);
    ll_add(listaDeLibros, &libro8);
    ll_add(listaDeLibros, &libro9);
    ll_add(listaDeLibros, &libro10);
    if (ll_len(listaDeLibros) == 10) // Con esta condicion verifico si se agrego correctamente los 10 libros hardcodeados
    {
        printf("\n------------------ FUNCION ll_add() ------------------\n");
        printf("Se han agregado correctamente 10 libros al Linkedlist!\n");
        system("pause");
    }

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_len() ------------------\n");
    printf("Tamanio actual de la lista: %d\n\n", ll_len(listaDeLibros));
    system("pause");

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_get() y ll_indexOf() ------------------\n");
    printf("Voy a conseguir el elemento %d de mi Linkedlist y lo guardare en eLibro* auxLibro\n", NUMLLGET);
    eLibro* auxLibro = ll_get(listaDeLibros, NUMLLGET);
    printf("El elemento que obtuve tiene los siguientes valores:\n");
    mostrarElementoIndex(listaDeLibros, ll_indexOf(listaDeLibros, ll_get(listaDeLibros, NUMLLGET)));
    system("pause");

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_set() y ll_indexOf() ------------------\n");
    printf("Voy a modificar el elemento %d de la Linkedlist con otro elemento harcodeado\n", NUMLLSET);
    printf("El elemento originalmente tiene los siguientes valores:\n");
    auxLibro = ll_get(listaDeLibros, NUMLLSET);
    printf("             -NOMBRE-    -FECHA DE PUBLICACION-     -PRECIO-         -GENERO-\n");
    mostrarElemento(auxLibro);
    eLibro libroExtra = {"Fahrenheit 451", 1953, 1079.99, "Ciencia Ficcion"};
    if (!(ll_set(listaDeLibros, NUMLLSET, &libroExtra)))
    {
        printf("El elemento se ha modificado correctamente y ahora tiene los siguientes valores: \n");
        auxLibro = ll_get(listaDeLibros, NUMLLSET);
        mostrarElementoIndex(listaDeLibros, ll_indexOf(listaDeLibros, ll_get(listaDeLibros, NUMLLSET)));
        system("pause");
    }

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_remove() ------------------\n");
    printf("Voy a eliminar el elemento %d de la Linkedlist\n", NUMLLREMOVE);
    printf("La lista actualmente tiene %d elementos\n", ll_len(listaDeLibros));
    if (!ll_remove(listaDeLibros, NUMLLREMOVE))
    {
        printf("Se ha eliminado correctamente el elemento %d de la lista y ahora tiene %d elementos.\n\n", NUMLLREMOVE, ll_len(listaDeLibros));
        system("pause");
    }

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_subList() ------------------\n");
    printf("La lista original actualmente tiene %d elementos, voy a copiar desde el 2 al 7 en una nueva lista\n", ll_len(listaDeLibros));
    LinkedList* nuevaLista = ll_subList(listaDeLibros, 2, 7);
    if (nuevaLista != NULL)
    {
        printf("Se ha creado correctamente la nueva lista y esta tiene %d elementos!\n", ll_len(nuevaLista));
        mostrarElementos(nuevaLista);
        system("pause");
    }
    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_clone() ------------------\n");
    printf("La lista original actualmente tiene %d elementos y la voy a clonar completamente\n\n", ll_len(listaDeLibros));
    LinkedList* listaClonada = ll_clone(listaDeLibros);
    if (listaClonada != NULL)
    {
        printf("Se ha creado correctamente un clon de la lista original y tiene %d elementos!\n", ll_len(listaClonada));
        mostrarElementos(listaClonada);
        system("pause");
    }

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_clear() ------------------\n");
    printf("Voy a aplicar la funcion con la listaClonada\n\n");
    if (!ll_clear(listaClonada))
    {
        printf("Se han eliminado completamente todos los elementos de la listasClonada y ahora tiene %d elementos!\n", ll_len(listaClonada));
        system("pause");
    }

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_deleteLinkedList() ------------------\n");
    printf("Voy a aplicar la funcion eliminado la nuevaLista creada con ll_subList\n\n");
    if (!ll_deleteLinkedList(nuevaLista))
    {
        printf("Se ha eliminado correctamente LinkedList* nuevaLista!\n");
        system("pause");
    }

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_isEmpty() ------------------\n");
    printf("Voy a aplicar la funcion utilizando la listaClonada y la lista original como referencia\n\n");
    int lista1 = ll_isEmpty(listaClonada), lista2 = ll_isEmpty(listaDeLibros);
    if (lista1)
    {
        printf("La listaClonada esta vacia y ");
    } else
        {
            printf("La listaClonada NO esta vacia y ");
        }
    if (lista2)
    {
        printf("la lista original esta vacia!\n");
        system("pause");
    } else
        {
            printf("la lista original NO esta vacia!\n");
            system("pause");
        }

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_push() ------------------\n");
    printf("Voy a aplicar la funcion agregando un elemento nuevo en la lista original en la posicion %d\n\n", NUMLLPUSH);
    eLibro libroExtra2 = {"Juego de Tronos", 1996, 2252.99, "Novela"};
    printf("En la posicion %d actualmente se encuentra el elemento:\n", NUMLLPUSH);
    mostrarElementoIndex(listaDeLibros, NUMLLPUSH);
    printf("Y la lista tiene %d elementos.\n", ll_len(listaDeLibros));
    if (!ll_push(listaDeLibros, NUMLLPUSH, &libroExtra2))
    {
        printf("\nAhora se realizo el ll_push y en la posicion %d se encuentra el elemento:\n", NUMLLPUSH);
        mostrarElementoIndex(listaDeLibros, NUMLLPUSH);
        printf("Y la lista ahora tiene %d elementos.\n", ll_len(listaDeLibros));
        system("pause");
    }

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_pop() ------------------\n");
    printf("Voy a aplica la funcion quitando el elemento %d de la lista original y guardandola en una variable auxiliar\n\n", NUMLLPOP);
    eLibro* libroQuitado = ll_pop(listaDeLibros, NUMLLPOP);
    printf("Elemento %d quitado y guardado, ahora la lista tiene %d elementos!\n", NUMLLPOP, ll_len(listaDeLibros));
    printf("-------------------------- LIBRO QUE SE HA QUITADO --------------------------\n");
    printf("             -NOMBRE-    -FECHA DE PUBLICACION-     -PRECIO-         -GENERO-\n");
    mostrarElemento(libroQuitado);
    system("pause");

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_contains() ------------------\n");
    printf("Voy a aplicar la funcion preguntando por el elemento que quite en ll_pop()\n\n");
    if (ll_contains(listaDeLibros, &libro2))
    {
        printf("Existe el elemento dentro de la lista original!\n");
    } else
        {
            printf("No existe el elemento dentro de la lista original!\n");
        }
    system("pause");

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_containsAll() ------------------\n");
    printf("Voy a aplicar la funcion comparando la lista original y la listaClonada.\n\n");
    if (ll_containsAll(listaDeLibros, listaClonada))
    {
        printf("Todos los elementos de la listaClonada existen en la lista original!\n");
    } else
        {
            printf("No existen los elementos de la listaClonada en la lista original\n");
        }
    system("pause");

    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_sort() ------------------\n");
    printf("Voy a aplicar la funcion ordenando de manera ASCENDENTE los libros por ANIO de publicacion.\n\n");
    printf("Lista de libros antes del ordenamiento:\n");
    mostrarElementos(listaDeLibros);
    if (!ll_sort(listaDeLibros, ordenarPorAnio, 1))
    {
         printf("Lista de libros despues del ordenamiento:\n");
         mostrarElementos(listaDeLibros);
    }
    system("pause");
    // --------------------------------------------------------------------------------------- //
    printf("\n------------------ FUNCION ll_filter() ------------------\n");
    listaClonada = ll_filter(listaDeLibros, filtrarPorGenero);
    printf("Voy a aplicar la funcion filtrando por genero de libro y guardandola en la listaClonada.\n\n");
    printf("Contenido de la lista original:\n");
    mostrarElementos(listaDeLibros);
    printf("Contanido de la lista filtrada:\n");
    mostrarElementos(listaClonada);

    // ---------------------------- FIN DE TRABAJO PRACTICO N.4 -------------------------------------- //
    return 0;
}

void mostrarElemento(eLibro* pElemento)
{
    printf(" %20s              %4d              %4.2f %20s\n",pElemento->nombre,pElemento->AnioPublicacion,pElemento->precio,pElemento->genero);
}

void mostrarElementos(LinkedList* lista)
{
    int i;
    eLibro* elementoAux = NULL;
    printf("             -NOMBRE-    -FECHA DE PUBLICACION-     -PRECIO-         -GENERO-\n");
    for (i = 0; i < ll_len(lista); i++)
    {
        elementoAux = ll_get(lista, i);
        mostrarElemento(elementoAux);
    }
}

void mostrarElementoIndex(LinkedList* lista, int index)
{
    eLibro* elementoAux = NULL;
    printf("             -NOMBRE-    -FECHA DE PUBLICACION-     -PRECIO-         -GENERO-\n");
    elementoAux = ll_get(lista, index);
    mostrarElemento(elementoAux);
}

int ordenarPorAnio(void* libro, void* libro2)
{
    int isOk = 0;
    eLibro* auxLibro = NULL;
    eLibro* auxLibro2 = NULL;
    if (libro != NULL && libro2 != NULL)
    {
        auxLibro = (eLibro*) libro;
        auxLibro2 = (eLibro*) libro2;
        if (auxLibro->AnioPublicacion > auxLibro2->AnioPublicacion)
        {
            isOk = 1;
        } else
            {
                isOk = -1;
            }
    }
    return isOk;
}

int filtrarPorGenero(void* libro)
{
    int isOk = -1;
    eLibro* auxLibro = NULL;
    if (libro != NULL)
    {
        auxLibro = (eLibro*) libro;
        if (strcmp(auxLibro->genero, "Obra de teatro") == 0)
        {
            isOk = 1;
        }
    }
    return isOk;
}
