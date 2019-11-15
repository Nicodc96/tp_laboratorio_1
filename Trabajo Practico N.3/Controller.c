#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/** \brief Menu de Opciones Inicial
 *
 * \return int option
 */

int menu(void)
{
    int option;

    system("cls");
    printf("--------- NOMINA DE EMPLEADOS | UTN FRA ---------\n\n");
    printf("1) Cargar los datos de los empleados desde el archivo 'data.csv' (modo TEXTO)\n");
    printf("2) Cargar los datos de los empleados desde el archivo 'data.bin' (modo BINARIO)\n");
    printf("3) Alta de empleado\n");
    printf("4) Modificar datos de empleado\n");
    printf("5) Baja de empleado\n");
    printf("6) Listar empleados\n");
    printf("7) Ordenar empleados\n");
    printf("8) Guardar los datos de los empleados en el archivo 'data.csv' (modo TEXTO)\n");
    printf("9) Guardar los datos de los empleados en el archivo 'data.bin' (modo BINARIO)\n");
    printf("10) Salir\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &option);

    return option;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return isOk int (0) - No se pudo cargar los datos del archivo "data.csv"
 *                  (1) - Se cargo correctamente los datos del archivo "data.csv"
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int checkParser = 0;

    checkParser = parser_EmployeeFromText(path, pArrayListEmployee);

    if (checkParser)
    {
        printf("\n------ Se ha cargado correctamente los datos del Archivo! ------\n");
        printf("------ Datos cargados: %d\n",ll_len(pArrayListEmployee));
        isOk = 1;
    } else
        {
            printf("------ Error! No se ha podido cargar los datos del Archivo! ------\n");
        }

    return isOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return isOk int (0) - No se pudo cargar los datos del archivo "data.bin"
 *                  (1) - Se cargo correctamente los datos del archivo "data.bin"
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int checkParser = 0;

    checkParser = parser_EmployeeFromBinary(path, pArrayListEmployee);

    if (checkParser)
    {
        printf("\n------ Se ha cargado correctamente los datos del Archivo! ------\n");
        printf("------ Datos cargados: %d\n",ll_len(pArrayListEmployee));
        isOk = 1;
    } else
        {
            printf("\n------Error! No se ha podido cargar los datos del Archivo! ------\n");
        }

    return isOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return isOk int  (0) - Si hubo un error en agregar un empleado
 *                   (1) - Si se agrego correctamente un empleado
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int i;
    int idMax = -1;
    int flag = 0;
    char auxCadena[100];
    int auxSueldo;
    int auxHorasTrabajadas;

    system("cls");
    printf("------------------ NOMINA DE EMPLEADOS | UTN FRA ------------------\n\n");
    printf("------------------             ALTAS             ------------------\n\n");

    Employee* newEmpleado = employee_new();
    Employee* auxEmpleado = NULL;

    printf("\nIngrese nombre del Empleado (20 caracteres maximo): ");
    fflush(stdin);
    scanf("%s", auxCadena);
    while (strlen(auxCadena) > 19)
    {
        printf("Nombre demasiado largo! Reingrese (20 caracteres maximo): ");
        fflush(stdin);
        scanf("%s", auxCadena);
    }
    employee_setNombre(newEmpleado, auxCadena);

    printf("\nIngrese cantidad de Horas Trabajadas (1-10.000): ");
    scanf("%d", &auxHorasTrabajadas);
    while(auxHorasTrabajadas <= 0 || auxHorasTrabajadas > 10000)
    {
        printf("Error! Cantidad no valida! Reingrese (1-10.000): ");
        scanf("%d", &auxHorasTrabajadas);
    }
    employee_setHorasTrabajadas(newEmpleado, auxHorasTrabajadas);

    printf("\nIngrese el sueldo correspondiente (10.000 - 75.000): ");
    scanf("%d", &auxSueldo);
    while(auxSueldo < 10000 || auxSueldo > 75000)
    {
        printf("Error! Reingrese un valor correcto (10.000 - 75.000)!: ");
        scanf("%d", &auxSueldo);
    }
    employee_setSueldo(newEmpleado, auxSueldo);

    for (i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
        if(flag == 0 || auxEmpleado->id > idMax)
        {
            idMax = auxEmpleado->id;
            flag = 1;
        }
    }
    employee_setId(newEmpleado, idMax + 1);
    if(!ll_add(pArrayListEmployee, newEmpleado))
    {
        isOk = 1;
    }


    return isOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return isOk int  (0) - No se ha realizado ninguna modificacion en el empleado o se ha cancelado la operacion
 *                   (1) - Se ha realizado al menos una modificacion
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int auxID, i, index, newHours, newSalary;
    int flag = 0;
    int continuar = 0;
    char option;
    char auxName[50];
    Employee* auxEmp = NULL;

    system("cls");
    printf("------------------ NOMINA DE EMPLEADOS | UTN FRA ------------------\n\n");
    printf("------------------         MODIFICACIONES        ------------------\n\n");
    controller_ListEmployee(pArrayListEmployee);
    printf("Ingrese el ID a modificar: ");
    scanf("%d", &auxID);

    for (i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
        if (auxID == auxEmp->id)
        {
            flag = 1;
            index = i;
            break;
        }
    }
    if(flag == 0)
    {
        printf("No se ha encontrado el Empleado con la ID ingresada!\n");
    } else
        {
            do{
            switch(employee_modifyMenu(auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo))
            {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                scanf("%s", auxName);

                printf("Confirmar modificacion (y/n): ");
                fflush(stdin);
                scanf("%c", &option);
                while (option != 'y' && option != 'n')
                {
                    printf("Opcion incorrecta! Ingrese 'y' o 'n': ");
                    fflush(stdin);
                    scanf("%c", &option);
                }
                if(option == 'y')
                {
                    auxEmp = (Employee*) ll_get(pArrayListEmployee, index);
                    strlwr(auxName);
                    auxName[0] = toupper(auxName[0]);
                    strcpy(auxEmp->nombre, auxName);
                    printf("Se ha realizado exitosamente la modificacion del Nombre!\n");
                    isOk = 1;
                } else
                    {
                        printf("Se ha cancelado la operacion correctamente!\n");
                    }
                break;
            case 2:
                printf("Ingrese el nuevo sueldo (10.000 - 75.000): ");
                scanf("%d", &newSalary);

                while(newSalary < 10000 || newSalary > 75000)
                {
                    printf("Error! Reingrese un valor correcto (10.000 - 75.000)!: ");
                    scanf("%d", &newSalary);
                }

                printf("Confirmar modificacion (y/n): ");
                fflush(stdin);
                scanf("%c", &option);
                while (option != 'y' && option != 'n')
                {
                    printf("Opcion incorrecta! Ingrese 'y' o 'n': ");
                    fflush(stdin);
                    scanf("%c", &option);
                }
                if(option == 'y')
                {
                    auxEmp = (Employee*) ll_get(pArrayListEmployee, index);
                    auxEmp->sueldo = newSalary;
                    printf("Se ha realizado exitosamente la modificacion del Sueldo!\n");
                    isOk = 1;
                } else
                    {
                        printf("Se ha cancelado la operacion correctamente!\n");
                    }
                break;
            case 3:
                printf("Ingrese la nueva cantidad de Horas Trabajadas (1 - 10.000): ");
                scanf("%d", &newHours);

                while(newHours < 1 || newHours > 10000)
                {
                    printf("Error! Reingrese un valor correcto (10.000 - 75.000)!: ");
                    scanf("%d", &newHours);
                }

                printf("Confirmar modificacion (y/n): ");
                fflush(stdin);
                scanf("%c", &option);
                while (option != 'y' && option != 'n')
                {
                    printf("Opcion incorrecta! Ingrese 'y' o 'n': ");
                    fflush(stdin);
                    scanf("%c", &option);
                }
                if(option == 'y')
                {
                    auxEmp = (Employee*) ll_get(pArrayListEmployee, index);
                    auxEmp->horasTrabajadas = newHours;
                    printf("Se ha realizado exitosamente la modificacion de las Horas Trabajadas!\n");
                    isOk = 1;
                } else
                    {
                        printf("Se ha cancelado la operacion correctamente!\n");
                    }
                break;
            case 4:
                printf("Confirmar SALIDA (y/n): ");
                fflush(stdin);
                scanf("%c", &option);
                while (option != 'y' && option != 'n')
                {
                    printf("Opcion incorrecta! Ingrese 'y' o 'n': ");
                    fflush(stdin);
                    scanf("%c", &option);
                }
                if(option == 'y')
                {
                    continuar = 1;
                }
                break;
            default:
                printf("Opcion seleccionada incorrecta! Reingrese.\n");
            }
            system("pause");
            }while(!continuar);
        }

    return isOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return isOk int  (0) - Si se cancelo la operacion o no se pudo encontrar el empleado
 *                   (1) - Si se ha dado de baja el empleado
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int auxId, i, index;
    int flag = 0;
    char resp;
    Employee* auxEmployee = NULL;

    system("cls");
    controller_ListEmployee(pArrayListEmployee);
    printf("------------------ NOMINA DE EMPLEADOS | UTN FRA ------------------\n\n");
    printf("------------------             BAJAS             ------------------\n\n");

    printf("Ingrese el ID del empleado: ");
    scanf("%d", &auxId);
    for (i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
        if(auxId == auxEmployee->id)
        {
            flag = 1;
            index = i;
            break;
        }
    }
    if(!flag)
    {
        printf("\nNo se ha encontrado el Empleado con la ID ingresada!\n");
    } else
        {
            printf("\nConfirmar BAJA empleado (y/n): ");
            fflush(stdin);
            scanf("%c", &resp);
            while(resp != 'y' && resp != 'n')
            {
                printf("Respuesta no valida! Ingrese (y/n): ");
                fflush(stdin);
                scanf("%c", &resp);
            }
            if(resp == 'y')
            {
                ll_remove(pArrayListEmployee, index);
                printf("\nSe ha eliminado exitosamente el Empleado de la lista!\n");
                isOk = 1;
            }
            if(resp == 'n')
            {
                printf("\nSe ha cancelado la operacion!\n");
            }
        }

    return isOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return isOk int  (1) - Muestra la lista de empleados (aunque este vacia)
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int i;
    Employee* pEmp;
    system("cls");
    printf("------------------ NOMINA DE EMPLEADOS | UTN FRA ------------------\n\n");
    printf("   - ID -        - NOMBRE -      - HORAS TRABAJADAS -     - SUELDO -\n");

    for(i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        pEmp = ll_get(pArrayListEmployee, i);
        employee_showInfo(pEmp);
        isOk = 1;
    }
    printf("\nTotal de Empleados: %d.\n", ll_len(pArrayListEmployee));

    return isOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int option;

    system("cls");
    printf("------------------ NOMINA DE EMPLEADOS | UTN FRA ------------------\n\n");
    printf("------------------   ORDENAR LISTA DE EMPLEADOS  ------------------\n\n");

    printf("Ordenar de manera...\n");
    printf("1) Ascendente  (A-Z)\n");
    printf("2) Descendente (Z-A)\n");
    printf("3) Salir\n\n");
    printf("Elija opcion: ");
    scanf("%d", &option);
    while(option < 0 || option > 3)
    {
        printf("Opcion seleccionada invalida, reingrese: ");
        scanf("%d", &option);
    }
    switch (option)
    {
    case 1:
        ll_sort(pArrayListEmployee, employee_sort, 1);
        printf("Se ha ordenado la lista de empleados de manera ascendente!\n");
        isOk = 1;
        break;
    case 2:
        ll_sort(pArrayListEmployee, employee_sort, 0);
        printf("Se ha ordenado la lista de empleados de manera descendente!\n");
        isOk = 1;
        break;
    case 3:
        return isOk;
        break;
    }

    return isOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return isOk int  (0) - Si hubo un error en guardar los datos en el archivo "data.csv"
 *                   (1) - Si se guardo exitosamente los datos en el archivo "data.csv"
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int i;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[50];
    FILE* fArchivo = fopen(path, "w");
    Employee* pEmp = NULL;

    if(path != NULL && pArrayListEmployee != NULL && fArchivo != NULL)
    {
        fprintf(fArchivo, "id,nombre,horasTrabajadas,sueldo\n");
        for(i = 0; i < (ll_len(pArrayListEmployee)); i++)
        {
            pEmp = (Employee*) ll_get(pArrayListEmployee, i);
            id = pEmp->id;
            horasTrabajadas = pEmp->horasTrabajadas;
            sueldo = pEmp->sueldo;
            strcpy(nombre, pEmp->nombre);
            fprintf(fArchivo, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
            isOk = 1;
        }
        printf("\n------ Datos guardados correctamente en modo TEXTO! ------\n");
    }

    fclose(fArchivo);
    return isOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return isOk int  (0) - Si hubo un error en guardar los datos en el archivo "data.bin"
 *                   (1) - Si se guardo exitosamente los datos en el archivo "data.bin"
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int isOk = 0;
    int i;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[50];
    FILE* fArchivo = fopen(path, "wb");
    Employee* pEmp = NULL;

    if(path != NULL && pArrayListEmployee != NULL && fArchivo != NULL)
    {
        fprintf(fArchivo, "id,nombre,horasTrabajadas,sueldo\n");
        for(i = 0; i < (ll_len(pArrayListEmployee)); i++)
        {
            pEmp = (Employee*) ll_get(pArrayListEmployee, i);
            id = pEmp->id;
            horasTrabajadas = pEmp->horasTrabajadas;
            sueldo = pEmp->sueldo;
            strcpy(nombre, pEmp->nombre);
            fprintf(fArchivo, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
            isOk = 1;
        }
        printf("\n------ Datos guardados correctamente en modo BINARIO! ------\n");
    }

    fclose(fArchivo);
    return isOk;
}
