#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "parser.h"

/** \brief Crea un nuevo empleado, asignando espacio en memoria y seteandolo en valores vacios
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
 * \param idStr char*               | ID parametrizado
 * \param nombreStr char*           | Nombre parametrizado
 * \param horasTrabajadasStr char*  | horasTrabajadas parametrizado
 * \param sueldoStr char*           | Sueldo parametrizado
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
 * \param pEmp Employee*    | Puntero al Empleado
 * \param id int            | ID a asignar
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
 * \param pEmp Employee*    | Puntero al Empleado
 * \param id int            | ID obtenido del Empleado
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
 * \param pEmp Employee*    | Puntero al Empleado
 * \param nombre char*      | Nombre a cargar en el empleado
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
 * \param pEmp Employee*    | Puntero al Empleado
 * \param nombre char*      | Puntero a la variable donde guardar el nombre del empleado
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
 * \param pEmp Employee*        | Puntero al Empleado
 * \param horasTrabajadas int   | Valor de horasTrabajadas a setear
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
 * \param pEmp Employee*        | Puntero al Empleado
 * \param horasTrabajadas int   | Puntero a la variable donde guardar las horas del empleado
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
 * \param pEmp Employee*        | Puntero al Empleado
 * \param sueldo int            | Sueldo recibido a cargar en el empleado
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
 * \param pEmp Employee*        | Puntero al Empleado
 * \param sueldo int            | Variable donde guardar el sueldo obtenido del empleado
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
 * \param pEmp Employee*        | Puntero a Empleado
 */


void employee_showInfo(Employee* pEmp)
{
    if(pEmp != NULL)
    {
        int id;
        char nombre[128];
        int horasTrabajadas;
        int sueldo;

        employee_getId(pEmp, &id);
        employee_getNombre(pEmp, nombre);
        employee_getHorasTrabajadas(pEmp, &horasTrabajadas);
        employee_getSueldo(pEmp, &sueldo);

        printf("   %4d    %14s               %5d Hs            $%5d\n", id, nombre, horasTrabajadas, sueldo);
    }
}

/** \brief Funcion ordenadora de Empleados de manera ascendente y descendente
 *
 * \param pEmp void*        | Puntero a empleado 1
 * \param auxEmp void*      | Puntero a empleado 2
 * \return value int - Devuelvo el valor obtenido de strcmp (1) - Manera ascendente
 *                                                          (-1) - Manera descendente
 */


int employee_sort(void* pEmp, void* auxEmp)
{
    int value = 0;
    Employee* empOne;
    Employee* empTwo;
    if (pEmp != NULL && auxEmp != NULL)
    {
        empOne = (Employee*) pEmp;
        empTwo = (Employee*) auxEmp;
        value = strcmp(empOne->nombre, empTwo->nombre);
    }
    return value;
}

/** \brief Funcion Menu de modificaciones   | Muestro el menu y los datos del empleado a modificar
 *
 * \param idEmployee int            | ID del empleado a modificar
 * \param nameEmployee char[]       | Nombre del empleado a modificar
 * \param hoursEmployee int         | HorasTrabajadas del empleado a modificar
 * \param salaryEmployee int        | Salario del empleado a modificar
 * \return opcion int - Retorno la opcion elegida en el menu
 */


int employee_modifyMenu(int idEmployee, char* nameEmployee, int hoursEmployee, int salaryEmployee)
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
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
