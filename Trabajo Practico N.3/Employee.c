#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "parser.h"

/** \brief Crea un nuevo empleado, asignando espacio en memoria y seteandolo en 0
 *
 * \return new Employee* - (NULL) No se pudo asignar en memoria el nuevo empleado
 *                         (Employee*) Si la funcion termino correctamente
 */

Employee* employee_new()
{
    Employee* new = (Employee*) malloc(sizeof(Employee));

    if (new == NULL)
    {
        new->id = 0;
        strcpy(new->nombre, "");
        new->horasTrabajadas = 0;
        new->sueldo = 0;
    }

    return new;
}

/** \brief Setea un empleado con datos obtenidos por parametros de tipo char*
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return pEmp     -   (NULL) Si no se pudo asignar en memoria espacio para el nuevo empleado
 *                      (Employee*) Si se ha cargado correctamente el empleado con los parametros parseados
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* pEmp = employee_new();
    int flag = 0;
    if(pEmp != NULL)
    {
        employee_setId(pEmp, atoi(idStr));
        employee_setNombre(pEmp, nombreStr);
        employee_setHorasTrabajadas(pEmp, atoi(horasTrabajadasStr));
        employee_setSueldo(pEmp, atoi(sueldoStr));
        flag = 1;
    }
    if (flag != 1)
    {
        pEmp = NULL;
    }

    return pEmp;
}

/** \brief Setea el ID en un Empleado
 *
 * \param pEmp Employee*
 * \param id int
 * \return isOk int - (0) Si el puntero a empleado es igual a NULL
 *                    (1) Si se cargo correctamente el ID en el puntero a empleado
 */

int employee_setId(Employee* pEmp, int id)
{
    int isOk = 0;
    if (pEmp != NULL)
    {
        pEmp->id = id;
        isOk = 1;
    }

    return isOk;
}

/** \brief Obtiene el ID de un Empleado
 *
 * \param pEmp Employee*
 * \param id int
 * \return isOk int - (0) Si el puntero a empleado o el ID llegado por parametro es igual a NULL
 *                    (1) Si devuelve el ID obtenido del Empleado solicitado
 */


int employee_getId(Employee* pEmp,int* id)
{
    int isOk = 0;
    if (pEmp != NULL && id != NULL)
    {
        *id = pEmp->id;
        isOk = 1;
    }

    return isOk;
}

/** \brief Setea el Nombre en un Empleado
 *
 * \param pEmp Employee*
 * \param nombre char*
 * \return isOk int - (0) Si el puntero a empleado es igual a NULL
 *                    (1) Si se cargo correctamente el nombre en el puntero a empleado
 */

int employee_setNombre(Employee* pEmp,char* nombre)
{
    int isOk = 0;
    if (pEmp != NULL && nombre != NULL)
    {
        strcpy(pEmp->nombre, nombre);
        isOk = 1;
    }

    return isOk;
}

/** \brief Obtiene el nombre de un Empleado
 *
 * \param pEmp Employee*
 * \param nombre char*
 * \return isOk int - (0) Si el puntero a empleado o el nombre llegado por parametro es igual a NULL
 *                    (1) Si devuelve el nombre obtenido del Empleado solicitado
 */

int employee_getNombre(Employee* pEmp,char* nombre)
{
    int isOk = 0;
    if (pEmp != NULL)
    {
        strcpy(nombre, pEmp->nombre);
        isOk = 1;
    }

    return isOk;
}

/** \brief Setea las horas de trabajo en un Empleado
 *
 * \param pEmp Employee*
 * \param horasTrabajadas int
 * \return isOk int - (0) Si el puntero a empleado es igual a NULL
 *                    (1) Si se cargo correctamente las horas trabajadas en el puntero a empleado
 */

int employee_setHorasTrabajadas(Employee* pEmp,int horasTrabajadas)
{
    int isOk = 0;
    if (pEmp != NULL)
    {
        pEmp->horasTrabajadas = horasTrabajadas;
        isOk = 1;
    }

    return isOk;
}

/** \brief Obtiene las horas trabajadas de un Empleado
 *
 * \param pEmp Employee*
 * \param horasTrabajadas int
 * \return isOk int - (0) Si el puntero a empleado o int* llegado por parametro es igual a NULL
 *                    (1) Si devuelve las horas trabajadas obtenido del Empleado solicitado
 */

int employee_getHorasTrabajadas(Employee* pEmp,int* horasTrabajadas)
{
    int isOk = 0;
    if (pEmp != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = pEmp->horasTrabajadas;
        isOk = 1;
    }

    return isOk;
}

/** \brief Setea el Sueldo en un Empleado
 *
 * \param pEmp Employee*
 * \param sueldo int
 * \return isOk int - (0) Si el puntero a empleado es igual a NULL
 *                    (1) Si se cargo correctamente el sueldo en el puntero a empleado
 */

int employee_setSueldo(Employee* pEmp,int sueldo)
{
    int isOk = 0;
    if (pEmp != NULL)
    {
        pEmp->sueldo = sueldo;
        isOk = 1;
    }

    return isOk;
}

/** \brief Obtiene el Sueldo de un Empleado
 *
 * \param pEmp Employee*
 * \param sueldo int
 * \return isOk int - (0) Si el puntero a empleado o el sueldo llegado por parametro es igual a NULL
 *                    (1) Si devuelve el sueldo obtenido del Empleado solicitado
 */

int employee_getSueldo(Employee* pEmp,int* sueldo)
{
    int isOk = 0;
    if (pEmp != NULL && sueldo != NULL)
    {
        *sueldo = pEmp->sueldo;
        isOk = 1;
    }

    return isOk;
}

/** \brief Muestra los datos de un Empleado llegado por parametro, y los muestro obteniendo sus datos con employee_get
 *
 * \param pEmp Employee*
 */


void employee_showInfo(Employee* pEmp)
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    employee_getId(pEmp, &id);
    employee_getNombre(pEmp, nombre);
    employee_getHorasTrabajadas(pEmp, &horasTrabajadas);
    employee_getSueldo(pEmp, &sueldo);

    printf("   %4d    %14s               %3d Hs               $%5d\n", id, nombre, horasTrabajadas, sueldo);

}

/** \brief Funcion ordenadora de Empleados de manera ascendente y descendente
 *
 * \param pEmp void*
 * \param auxEmp void*
 * \return value int - Devuelvo el valor obtenido comparando los nombres de los Employee* previamente asignandole el parametro
 */


int employee_sort(void* pEmp, void* auxEmp)
{
    Employee* this = pEmp;
    Employee* this2 = auxEmp;
    int value = strcmp(this->nombre, this2->nombre);

    return value;
}

/** \brief Funcion Menu de modificaciones
 *         -Muestro el menu y los datos del empleado a modificar
 * \param idEmployee int
 * \param nameEmployee char[]
 * \param hoursEmployee int
 * \param salaryEmployee int
 * \return opcion int - Retorno la opcion elegida en el menu
 */


int employee_modifyMenu(int idEmployee, char nameEmployee[], int hoursEmployee, int salaryEmployee)
{
    int opcion;
        system("cls");
        printf("------------------ NOMINA DE EMPLEADOS | UTN FRA ------------------\n\n");
        printf("------------------         MODIFICACIONES        ------------------\n\n");
        printf("Empleado ID: %d\n", idEmployee);
        printf("Nombre: %s\n", nameEmployee);
        printf("Horas trabajadas: %d Hs\n", hoursEmployee);
        printf("Sueldo: $%d\n", salaryEmployee);
        printf("\n --- Menu de Modificaciones --- \n");
        printf("1) Modificar Nombre\n");
        printf("2) Modificar Sueldo\n");
        printf("3) Modificar Horas de trabajo\n");
        printf("4) Salir\n\n");
        printf("Elija opcion: ");
        scanf("%d", &opcion);

        return opcion;
}
