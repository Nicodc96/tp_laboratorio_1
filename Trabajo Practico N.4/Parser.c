#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return isOk int - (0) Si el char* || LinkedList* || FILE* es igual a NULL
 *                    (1) Si se ha cargado correctamente los datos del archivo
 */
int parser_EmployeeFromText(char* pFile , LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int cant;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    Employee* auxEmpleado;
    FILE* fArchivo = fopen(pFile, "r");

    if (pFile != NULL && pArrayListEmployee != NULL && fArchivo != NULL)
    {
        fscanf(fArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
        while(!feof(fArchivo))
        {
            cant = fscanf(fArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
            if (cant == 4)
            {
                auxEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
                ll_add(pArrayListEmployee, auxEmpleado);
            }
        }
        isOk = 1;
    }
    fclose(fArchivo);
    return isOk;
}

/** \brief Parsea los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return isOk int - (0) Si el char* || LinkedList* || FILE* es igual a NULL
 *                    (1) Si se ha cargado correctamente los datos del archivo
 */
int parser_EmployeeFromBinary(char* pFile , LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int cant;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    Employee* auxEmpleado;
    FILE* fArchivo = fopen(pFile, "rb");

    if (pFile != NULL && pArrayListEmployee != NULL && fArchivo != NULL)
    {
        fscanf(fArchivo, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
        while(!feof(fArchivo))
        {
            cant = fscanf(fArchivo, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
            if(cant == 4)
            {
                auxEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
                ll_add(pArrayListEmployee, auxEmpleado);
            }
        }
        isOk = 1;
    }
    fclose(fArchivo);
    return isOk;
}
