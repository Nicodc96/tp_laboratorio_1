#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// BIBLIOTECA DE PROTOTIPOS Y ESTRUCTURA EMPLOYEE //
#include "ArrayEmployees.h"

// -------- COMIENZO DE DEFINICIÓN DE FUNCIONES -------- //

/** \brief Función unica y exclusivamente para fines de TESTING | Ingresa manualmente al array principal
*          datos de empleados
 *
* \param Employee x[] | Recibe el array principal de empleados
* \param int tam      | Tamaño del array principal}
* \param int cant     | Cantida de Empleados a Hardcodear de Maximo 10
*
* \return int counter | La funcion devolverá un numero entero que servira para indicar al array principal
*         cuantos IDs se ingresaron y sumarlos. Así el próximo ingreso tomará la ID que corresponda.
*/
int hardcodearEmpleados(Employee x[], int tam, int cant)
{
    int counter = 0;
    Employee listaAuxiliar[] =
    {
        {7000, "Juan", "Perez", 15540, 26, 0},
        {7001, "Lucia", "Positelli", 25000, 22, 0},
        {7002, "Liliana", "Ramirez", 19130, 35, 0},
        {7003, "Pedro", "Novich", 14575, 46, 0},
        {7004, "Christian", "Baus", 21520, 7, 0},
        {7005, "Nicolas", "Diaz", 15775, 12, 0},
        {7006, "Alejandra", "Ponce", 23580, 44, 0},
        {7007, "Julia", "Guzman", 20000, 12, 0},
        {7008, "Roberto", "Duro", 15620, 9, 0},
        {7009, "Francisco", "Robaina", 17900, 36, 0},
    };
    if (cant <= tam && cant < 20)
    {
        for (int i = 0; i < cant; i++)
        {
            x[i] = listaAuxiliar[i];
            counter++;
        }
    }
    return counter;
}

/** \brief Menú de Opciones Principal | El programa iniciará mostrando esta función donde
*          el usuario ingresará un caracter de la cual devolverá la función correspondiente. Si
*          el caracter no corresponde a ninguno del menú indicará el mensaje de error y se volverá
*          a ejecutar.
* \param void
*
* \return char option | Devolverá un char que servirá para ejecutar una orden en el switch de main();
*/
int menu()
{
    char option;
    system("cls");

    printf("----------- NOMINA DE EMPLEADOS | UTN FRA -----------\n\n");
    printf("A) ALTAS\n");
    printf("B) MODIFICACIONES\n");
    printf("C) BAJAS\n");
    printf("D) INFORMAR\n");
    printf("E) SALIR\n\n");

    printf("Elija una opcion: ");
    fflush(stdin);
    option = getchar();
    return option;
}

/** \brief Función inicializadora del Array Principal | Antes de inicializar el menú principal
*          la función cargará en memoria el valor de isEmpty = 1 en todos los valores del array de tipo
*          Employee indicando que pueden ingresarse empleados y que no están ocupados.
*
* \param Employee employeesList[] | Array principal
* \param int len                  | Indicador del tamaño del array principal
*
* \return int isOk                | (0) si no pudo inicializarse el array, (1) si se ha cargado correctamente el array
*/
int initEmployees(Employee employeesList[], int len)
{
    int isOk = 0;
    for (int i = 0; i < len; i++)
    {
        employeesList[i].isEmpty = 1;
        isOk = 1;
    }
    return isOk;
}

/** \brief Función encargada de agregear elementos al array principal |
*
* \param int id             | ID del empleado
* \param char name[]        | Nombre del Empleado
* \param char lastName[]    | Apellido del Empleado
* \param float salary       | Salario del Empleado
* \param int sector         | Sector correspondiente al Empleado
*
* \return newEmployee       | La funcion devolvera el elemento cargado con los datos recibido por parámetro
*/
Employee addEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee newEmployee;

    newEmployee.id = id;
    strcpy(newEmployee.name, name);
    strcpy(newEmployee.lastName, lastName);
    newEmployee.salary = salary;
    newEmployee.sector = sector;
    newEmployee.isEmpty = 0;
    return newEmployee;
}

/** \brief Función buscadora del primer elemento del array principal con valor
*          isEmpty = 1
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
*
* \return int indice                | (-1) si no se encontrado ningún elemento del array
*         con valor isEmpty = 1 o el índice del elemento encontrado
*/
int searchEmpty(Employee employeesList[], int len)
{
    int indice = -1;
    for(int i = 0; i < len; i++)
    {
        if (employeesList[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Función encargada de agregar un nuevo elemento al array principal
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
* \param int id                     | ID pre-establecido desde main()
*
* \return int isOk                  | (0) Si el array está completo o no se pudo agregar el empleado al array
*         y (1) indicando que se agrego el empleado al array
*/
int newEmployee(Employee employeesList[], int len, int id)
{
    int isOk = 0;
    int flag = 0;
    int indice;
    int salary;
    int sector;
    int tries = 3;
    char checkIn = 'g';
    char name[51];
    char lastName[51];
    char auxCad[100];

    system("cls");
    printf("------  ALTAS | EMPLEADOS  ------\n\n");
    indice = searchEmpty(employeesList, len);
    if (indice == -1)
    {
        printf("Error. Nomina de Empleados completo, no es posible ingresar mas empleados.\n\n");
    }
    else
    {
        while (checkIn == 'g' || flag == 0)
        {
            printf("--- Usted tiene %d intentos para realizar el ingreso de empleado ---\n\n", tries);
            printf("Ingrese el nombre del Empleado(maximo 20 caracteres): ");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad)>20 && tries >= 0)
            {
                printf("Nombre demasiado largo. Maximo 20 caracteres! Reingrese nombre: ");
                fflush(stdin);
                gets(auxCad);
                tries--;
            }
            if (tries == 0)
            {
                printf("Demasiados intentos fallidos, cancelando operacion...\n\n");
                checkIn = 'f';
                break;
            }
            strcpy(name, auxCad);
            printf("\n");
            tries = 3;

            printf("Ingrese el apellido del Empleado(maximo 20 caracteres): ");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad)>20 && tries >= 0)
            {
                printf("Apellido demasiado largo. Maximo 20 caracteres! Reingrese apellido: ");
                fflush(stdin);
                gets(auxCad);
                tries--;
            }
            if (tries == 0)
            {
                printf("Demasiados intentos fallidos, cancelando operacion...\n\n");
                checkIn = 'f';
                break;
            }
            strcpy(lastName, auxCad);
            printf("\n");
            tries = 3;

            printf("Ingrese el salario correspondiente (10.000-100.000): ");
            fflush(stdin);
            scanf("%d", &salary);
            while ((salary > 100000 || salary < 10000) && tries >= 0)
            {
                printf("Salario ingresado incorrecto. Reingrese(10.000-100.000): ");
                fflush(stdin);
                scanf("%d", &salary);
                tries--;
            }
            if (tries == 0)
            {
                printf("Demasiados intentos fallidos, cancelando operacion...\n");
                checkIn = 'f';
                break;
            }
            printf("\n");
            tries = 3;

            printf("Ingrese el sector del empleado (1-50): ");
            fflush(stdin);
            scanf("%d", &sector);
            while ((sector < 1 || sector > 50) && tries >= 0)
            {
                printf("Numero de sector incorrecto. Ingrese un sector: ");
                fflush(stdin);
                scanf("%d", &sector);
                tries--;
            }
            if (tries == 0)
            {
                printf("Demasiados intentos fallidos, cancelando operacion...\n\n");
                checkIn = 'f';
                break;
            }
            flag = 1;
            checkIn = 't';
        }
        if (checkIn == 't')
        {
            employeesList[indice] = addEmployee(id, name, lastName, salary, sector);
            printf("Empleado ingresado al sistema exitosamente.\n\n");
            isOk = 1;
        } else
            {
                printf("ERROR. No se ha podido ingresar el empleado al sistema.\n\n");
            }
    }
    return isOk;
}

/** \brief Función que busca un empleado con un ID recibido por parámetro
*
* \param int id                     | ID del empleado a buscar
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
*
* \return int indice                | La funcion devolvera el indice del empleado si se ha encontrado
*         o devolverá (-1) si no se ha encontrado el empleado o el array es igual a NULL
*/
int findEmployeeById(Employee employeesList[], int len, int id)
{
    int indice = -1;
    for(int i = 0; i < len; i++)
    {
        if (employeesList != NULL && employeesList[i].isEmpty == 0 && employeesList[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Función encargada de pedir un ID y ejecutar la función removeEmployee
 *
 * \param Employee employeesList[]  | Array principal
 * \param int len                   | Tamaño del array principal
 *
 * \return void                     | La funcion no retorna valor ya que termina en la funcion
 *         removeEmployee.
 */
void removingEmployee(Employee employeesList[], int len)
{
    int auxID;
    int indice;

    printf("\n\n------ EMPLEADOS | ID ------\n\n");
    printf("Ingrese el ID del empleado (Ref ID: 7000): ");
    scanf("%d", &auxID);
    indice = findEmployeeById(employeesList, len, auxID);
    if (indice == -1)
    {
        printf("ID ingresado no existe en el sistema.\n\n");
        system("pause");
    } else
        {
            removeEmployee(employeesList, len, auxID);
        }
}

/** \brief Sub-Menú de opciones de modificación de los elementos en el array principal
*
* \param Employee employeesList[]   | Array Principal
* \param int len                    | Tamaño del array principal
* \param int id                     | ID verificado recibido de la funcion modifyingEmployee
*
* \return int option                | La función devolverá un entero (entre 1 y 5) verificado
*         que utilizará la función modifyMenuCases
*/
int modifyMenu(Employee employeesList[], int len, int id)
{
    int option;
    int indice;

    indice = findEmployeeById(employeesList, len, id);
    system("cls");
    printf("ID del empleado a modificar: %d\n", id);
    printf("Nombre del empleado a modificar: %s %s\n", employeesList[indice].name, employeesList[indice].lastName);
    printf("Salario del empleado a modificar: %.2f\n", employeesList[indice].salary);
    printf("Sector del empleado a modificar: %d\n\n", employeesList[indice].sector);

    printf("------  EMPLEADOS | MODIFICACIONES  ------\n\n");
    printf("1) Modificar NOMBRE\n");
    printf("2) Modificar APELLIDO\n");
    printf("3) Modificar SALARIO\n");
    printf("4) Modificar SECTOR\n");
    printf("5) Salir\n\n");

    printf("Elija opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

/** \brief Función encargada de solicitar el ID del Empleado a modificar y
*          ejecutar la funcion modifyMenuCases
*
* \param Employee employeesList[]   | Array Principal
* \param int len                    | Tamaño del array principal
*
* \return void                      | La funcion termina enviando el ID verificado del empleado y
*         ejecutando a la funcion modifyMenuCases
*/
void modifyingEmployee(Employee employeesList[], int len)
{
    int auxID;
    int indice;

    printf("\n\n------ EMPLEADOS | ID ------\n\n");
    printf("Ingrese el ID del empleado (Ref ID: 7000): ");
    scanf("%d", &auxID);
    indice = findEmployeeById(employeesList, len, auxID);
    if (indice == -1)
    {
        printf("ID ingresado no existe en el sistema.\n\n");
        system("pause");
    } else
        {
            modifyMenuCases(employeesList, len, auxID);
        }
}

/** \brief Función ejecutora de la modificación de empleados | La función ejecuta la función
*          modifyMenu con un switch y realiza la acción que esta devuelva
* \param Employee employeesList[]  | Array principal
* \param int len                   | Tamaño del array principal
* \param int id                    | ID recibido de la funcion modifyingEmployee
*
* \return void                     |
*/
void modifyMenuCases(Employee employeesList[], int len, int id)
{
    char follow = 'n';
    char name[51];
    char lastName[51];
    char resp;
    int tries = 3;
    int salary;
    int sector;
    int indice;

    indice = findEmployeeById(employeesList, len, id);

    do
    {
        switch(modifyMenu(employeesList, len, id))
        {
        case 1:
            printf("Ingrese el nuevo NOMBRE a modificar: ");
            fflush(stdin);
            gets(name);
            while (strlen(name) > 20 && tries > 0)
            {
                printf("Nombre ingresado demasiado largo! Reingrese: ");
                gets(name);
                tries--;
            }
            if (tries == 0)
            {
                printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
                system("pause");
            } else
                    {
                    tries = 3;
                    printf("Confirmar cambio (y/n): ");
                    fflush(stdin);
                    resp = getchar();
                    while (resp != 'y' && resp != 'n' && tries > 0)
                    {
                        printf("Respuesta incorrecta. Reintente (y/n): ");
                        tries--;
                        fflush(stdin);
                        resp = getchar();
                    }
                    if (tries == 0)
                    {
                        printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
                        system("pause");
                    }
                    if (resp == 'y')
                    {
                        strcpy(employeesList[indice].name, name);
                        printf("Nuevo NOMBRE modificado exitosamente.\n\n");
                        system("pause");
                    } else
                        {
                            printf("Se ha cancelado exitosamente la operacion.\n\n");
                            system("pause");
                        }
                }
            break;
        case 2:
            printf("Ingrese el nuevo APELLIDO a modificar: ");
            fflush(stdin);
            gets(lastName);
            while (strlen(lastName) > 20 && tries > 0)
            {
                printf("Apellido ingresado demasiado largo! Reingrese: ");
                gets(lastName);
                tries--;
            }
            if (tries == 0)
            {
                printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
                system("pause");
            } else
                {
                    tries = 3;
                    printf("Confirmar cambio (y/n): ");
                    fflush(stdin);
                    resp = getchar();
                    while (resp != 'y' && resp != 'n' && tries > 0)
                    {
                        printf("Respuesta incorrecta. Reintente (y/n): ");
                        tries--;
                        fflush(stdin);
                        resp = getchar();
                    }
                    if (tries == 0)
                    {
                        printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
                        system("pause");
                    }
                    if (resp == 'y')
                    {
                        strcpy(employeesList[indice].lastName, lastName);
                        printf("Nuevo APELLIDO modificado exitosamente.\n\n");
                        system("pause");
                    } else
                        {
                            printf("Se ha cancelado exitosamente la operacion.\n\n");
                            system("pause");
                        }
                }
            break;
        case 3:
            printf("Ingrese el nuevo SALARIO a modificar: ");
            scanf("%d", &salary);
            while ((salary > 100000 || salary < 10000) && tries > 0)
            {
                printf("Salario ingresado incorrecto. Reingrese(10.000-100.000): ");
                scanf("%d", &salary);
                tries--;
            }
            if (tries == 0)
            {
                printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
                system("pause");
            } else
                {
                    tries = 3;
                    printf("Confirmar cambio (y/n): ");
                    fflush(stdin);
                    resp = getchar();
                    while (resp != 'y' && resp != 'n' && tries > 0)
                    {
                        printf("Respuesta incorrecta. Reintente (y/n): ");
                        tries--;
                        fflush(stdin);
                        resp = getchar();
                    }
                    if (tries == 0)
                    {
                        printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
                        system("pause");
                    }
                    if (resp == 'y')
                    {
                        employeesList[indice].salary = salary;
                        printf("Nuevo SALARIO modificado exitosamente.\n\n");
                        printf("-ID-      -NOMBRE-       -APELLIDO-       -SALARIO-       -SECTOR-\n");
                        printEmployee(employeesList[indice]);
                        system("pause");
                    } else
                        {
                            printf("Se ha cancelado exitosamente la operacion.\n\n");
                            system("pause");
                        }
                }
            break;
        case 4:
            printf("Ingrese el nuevo SECTOR a modificar: ");
            scanf("%d", &sector);
            while ((sector > 50 || sector < 1) && tries > 0)
            {
                printf("Numero de Sector ingresado incorrecto, reingrese (1-50): ");
                scanf("%d", &sector);
                tries--;
            }
            if (tries == 0)
            {
                printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
                system("pause");
            } else
                {
                    tries = 3;
                    printf("Confirmar cambio (y/n): ");
                    fflush(stdin);
                    resp = getchar();
                    while (resp != 'y' && resp != 'n' && tries > 0)
                    {
                        printf("Respuesta incorrecta. Reintente (y/n): ");
                        tries--;
                        fflush(stdin);
                        resp = getchar();
                    }
                    if (tries == 0)
                    {
                        printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
                        system("pause");
                    }
                    if (resp == 'y')
                    {
                        employeesList[indice].sector = sector;
                        printf("Nuevo SECTOR modificado exitosamente.\n\n");
                        printf("-ID-      -NOMBRE-       -APELLIDO-       -SALARIO-       -SECTOR-\n");
                        printEmployee(employeesList[indice]);
                        system("pause");
                    } else
                        {
                            printf("Se ha cancelado exitosamente la operacion.\n\n");
                            system("pause");
                        }
                }
            break;
        case 5:
            printf("Confirmar Salida (y/n): ");
            fflush(stdin);
            follow = getchar();
            while(follow != 'y' && follow != 'n')
            {
                printf("\nOpcion incorrecta, ingrese (y/n): \n");
                fflush(stdin);
                follow = getchar();
            }
            break;
        default:
            printf("Opcion seleccionada incorrecta/inexistente.\n\n");
            system("pause");
            break;
        }
    }
    while(follow == 'n');
}

/** \brief Función que imprime un empleado
 *
 * \param Employee employeeX    | Un elemento de tipo Employee
 *
 * \return void                 |
 */
void printEmployee(Employee employeeX)
{
    printf("%d   %10s        %10s         %.2f          %02d\n",
           employeeX.id,
           employeeX.name,
           employeeX.lastName,
           employeeX.salary,
           employeeX.sector);
}

/** \brief Función que imprime el Array de empleados si NO estan vacios
*
* \param Employee employeesList[]     | Array principal
* \param int len                      | Tamaño del array principal
*
* \return int isOk                    | (1) si hay al menos 1 empleado cargado y lo muestra o
*         (0) si no hay empleados cargados mostrando el mensaje de error.
*/
int printEmployees(Employee employeesList[], int len)
{
    int flag = 0;
    int isOk = 0;

    printf("\n\n-ID-      -NOMBRE-       -APELLIDO-        -SALARIO-       -SECTOR-\n");

    for(int i=0; i < len; i++)
    {
        if(employeesList[i].isEmpty == 0)
        {
            printEmployee(employeesList[i]);
            flag = 1;
            isOk = 1;
        }
    }
    if (flag == 0)
    {
        system("cls");
        printf("\nNo se han encontrados empleados en el sistema.\n");
    }
    printf("\n\n");
    return isOk;
}

/** \brief Función removedora de empleados con un ID recibido por parámetro
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
* \param int id                     | ID recibido por parámetro
*
* \return int follow                | (0) si la funcion se ha cancelado o se realizaron demasiados
*         intentos fallidos o (1) si se ha dado de baja correctamente
*/
int removeEmployee(Employee employeesList[], int len, int id)
{
    int follow = 0;
    int tries = 3;
    char resp;
    int indice;

    system("cls");
    printf("------  BAJAS | EMPLEADOS  ------\n\n");
    printf("-ID-      -NOMBRE-       -APELLIDO-       -SALARIO-       -SECTOR-\n");
    indice = findEmployeeById(employeesList, len, id);
    printEmployee(employeesList[indice]);
    printf("Confirmar BAJA (y/n): ");
    fflush(stdin);
    resp = getchar();
    while(resp != 'y' && resp != 'n' && tries > 0)
    {
        printf("\nOpcion incorrecta, ingrese (y/n): ");
        fflush(stdin);
        resp = getchar();
        tries--;
    }
    if (tries == 0)
    {
        printf("Demasiados intentos fallidos. ");
    }
    if (resp == 'y')
    {
        employeesList[indice].isEmpty = 1;
        printf("Se ha dado de baja correctamente el empleado del sistema.\n\n");
        follow = 1;
    } else
        {
            printf("Operacion cancelada.\n");
        }
    return follow;
}

/** \brief Función ordenadora de Array Principal
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
* \param int order                  | Orden (1) de manera ascendente o (0) de manera descendente
*
* \return int isOk                  | (1) si se ha realizado correctamente el ordenamiento o (0) en caso contrario
*/
int sortEmployees(Employee employeesList[], int len, int order)
{
    int isOk = 0;
    Employee auxEmployee;

    for (int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if (order == 1)
            {
                // ORDENAMIENTO ASCENDENTE //
                if (employeesList[i].isEmpty == 0 && employeesList[j].isEmpty == 0 && employeesList[i].sector > employeesList[j].sector)
                {
                    auxEmployee = employeesList[i];
                    employeesList[i] = employeesList[j];
                    employeesList[j] = auxEmployee;
                    isOk = 1;
                }
                if (employeesList[i].sector == employeesList[j].sector && strcmp(employeesList[i].lastName,employeesList[j].lastName) > 0 && employeesList[i].isEmpty == 0 && employeesList[j].isEmpty == 0)
                {
                    auxEmployee = employeesList[i];
                    employeesList[i] = employeesList[j];
                    employeesList[j] = auxEmployee;
                    isOk = 1;
                }
            } else
                {
                    // ORDENAMIENTO DESCENDENTE //
                    if (employeesList[i].isEmpty == 0 && employeesList[j].isEmpty == 0 && employeesList[i].sector < employeesList[j].sector)
                    {
                        auxEmployee = employeesList[i];
                        employeesList[i] = employeesList[j];
                        employeesList[j] = auxEmployee;
                        isOk = 1;
                    }
                    if (employeesList[i].sector == employeesList[j].sector && strcmp(employeesList[i].lastName,employeesList[j].lastName) < 0 && employeesList[i].isEmpty == 0 && employeesList[j].isEmpty == 0)
                    {
                        auxEmployee = employeesList[i];
                        employeesList[i] = employeesList[j];
                        employeesList[j] = auxEmployee;
                        isOk = 1;
                    }
                }
        }
    }
    return isOk;
}

/** \brief Funcion ejecutora de la opción "INFORMAR" | Muestra el menú de informes, ejecuta la opción
*          verificada y, llama las funciones sortEmployee y sortEmployeesSalary.
*
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
*
* \return void                      | La función no retorna ningún valor, termina en main() una vez finalizado
*         el búcle while.
*/
void reportEmployees(Employee employeesList[], int len)
{
    char salir = 't';
    char option;
    int tries = 3;
    int sort;
    do
    {
        system("cls");
        printf("------ INFORMES | EMPLEADOS ------\n\n");
        printf("A) Informar lista de empleados ordenados alfabeticamente por Apellido y Sector ASCENDENTE\n");
        printf("B) Informar lista de empleados ordenados alfabeticamente por Apellido y Sector DESCENDENTE\n");
        printf("C) Informar total y promedio de todos los salarios, y cuantos empleados superan el salario promedio\n");
        printf("D) Salir\n\n");
        printf("------ EMPLEADOS ACTUAL ------\n");
        printEmployees(employeesList, len);
        printf("\n");
        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%c", &option);
        while ((option != 'a' && option != 'b' && option != 'c' && option != 'd') && tries > 0)
        {
            printf("Opcion seleccionada incorrecta, reingrese ('a','b','c' o 'd'): ");
            fflush(stdin);
            tries--;
            scanf("%c", &option);
        }
        if (tries == 0)
        {
            printf("Demasiados intentos fallidos. ");
            salir = 'f';
            system("pause");
        }
        switch(option)
        {
        case 'a':
            sort = sortEmployees(employeesList, len, 1);
            if (sort == 1)
            {
                printf("------ EMPLEADOS ORDENADOS DE MANERA ASCENDENTE ------\n");
                printEmployees(employeesList, len);
                system("pause");
            } else
                {
                    printf("El proceso de ordenamiento ha fallado!\n");
                    system("pause");
                }
            break;
        case 'b':
            sort = sortEmployees(employeesList, len, 0);
            if (sort == 1)
            {
                printf("------ EMPLEADOS ORDENADOS DE MANERA DESCENDENTE ------\n");
                printEmployees(employeesList, len);
                system("pause");
            } else
                {
                    printf("El proceso de ordenamiento ha fallado!\n");
                    system("pause");
                }
            break;
        case 'c':
            sortEmployeesSalary(employeesList, len);
            break;
        case 'd':
            salir = 'f';
            break;
        }
    }
    while(salir == 't');
}

/** \brief Función ejecutada por reportEmployees encargada de calcular e informar los salarios
*          totales de todos los empleados, el promedio de todos ellos y cuantos empleados superan
*          el promedio del salario general.
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
*
* \return void                      | La funcion empieza y termina dentro de la función reportEmployees
*/
void sortEmployeesSalary(Employee employeesList[], int len)
{
    int acumulador = 0;
    float promedio;
    int cantEmployee = 0;
    float mayor;
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (employeesList[i].isEmpty == 0)
        {
            cantEmployee++;
        }
    }
    for(int i = 0; i < cantEmployee; i++)
    {
        acumulador += employeesList[i].salary;
        promedio = acumulador / cantEmployee;
        if(mayor < employeesList[i].salary && employeesList[i].isEmpty == 0)
        {
            mayor = employeesList[i].salary;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if(employeesList[i].salary > promedio && employeesList[i].isEmpty == 0)
        {
            counter++;
        }
    }
    printf("\n------ RESULTADOS ------\n\n");
    printf("Salarios totales: %d\n", acumulador);
    printf("Promedio de salarios totales: %.2f\n", promedio);
    printf("Empleados que superan el salario promedio: %d\n\n", counter);
    counter = 0;
    system("pause");
}

/** \brief Función que comprueba si existen empleados en el array principal
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
*
* \return int isOk                  | (0) si no existen empleados en el array o (1)
*         si hay al menos un empleado en el array.
*/
int checkEmployee(Employee employeesList[], int len)
{
    int isOk = 0;
    for(int i = 0; i < len; i++)
    {
        if (employeesList[i].isEmpty == 0)
        {
            isOk = 1;
        }
    }
    return isOk;
}

// -------- FIN DE DEFINICIÓN DE FUNCIONES -------- //
