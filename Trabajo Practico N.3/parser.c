#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*                        | Nombre del archivo a leer y cargar
 * \param pArrayListEmployee LinkedList*    | LinkedList principal obtenido de main
 * \return isOk int - (0) Si el char* / LinkedList* / FILE* es igual a NULL
 *                    (1) Si se ha cargado correctamente los datos del archivo
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int cant;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    Employee* auxEmpleado = NULL;
    if (pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
            if (cant == 4)
            {
                auxEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
                if (auxEmpleado != NULL)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                }
            }
        }
        isOk = 1;
    }
    return isOk;
}

/** \brief Parsea los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*                        | Nombre del archivo a leer y cargar
 * \param pArrayListEmployee LinkedList*    | LinkedList principal obtenido de main
 * \return isOk int - (0) Si el char* / LinkedList* / FILE* es igual a NULL
 *                    (1) Si se ha cargado correctamente los datos del archivo
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int cant;
    Employee* auxEmpleado = NULL;
    if (pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            auxEmpleado = employee_new();
            if(auxEmpleado != NULL)
            {
                cant = fread(auxEmpleado, sizeof(Employee), 1, pFile);
                if(cant == 1)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                    isOk = 1;
                } else
                    {
                        break;
                    }
            }
        }
    }
    return isOk;
}
