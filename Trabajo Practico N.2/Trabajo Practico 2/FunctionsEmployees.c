#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "ArrayEmployees.h"

int hardcodearEmpleados(Employee x[], int tam, int cantidad)
{
    int counter = 0;
    Employee listaAuxiliar[] =
    {
        {7000, "Juan", "Perez", 15540, 26, 0},
        {7001, "Lucia", "Positelli", 25000, 22, 0},
        {7002, "Liliana", "Ramirez", 19130, 35, 0},
        {7003, "Pedro", "Novich", 14575, 46, 0},
        {7004, "Christian", "Baus", 21520, 7, 0},
        {7005, "Nicolas", "Diaz", 15775, 12, 0},                // Utilizar esta funcion si se desea testar rapidamente el TP
        {7006, "Alejandra", "Ponce", 23580, 44, 0},
        {7007, "Julia", "Guzman", 20000, 12, 0},
        {7008, "Roberto", "Duro", 15620, 9, 0},
        {7009, "Francisco", "Robaina", 17900, 36, 0},
    };

    if (cantidad <= tam && cantidad < 20)
    {
        for (int i = 0; i < cantidad; i++)
        {
            x[i] = listaAuxiliar[i];
            counter++;
        }
    }
    return counter;
}


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

int initEmployees(Employee employees[], int len)
{
    int isOk = 0;
    for (int i = 0; i < len; i++)
    {
        employees[i].isEmpty = 1;
        isOk = 1;
    }
    return isOk;
}

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

int searchEmpty(Employee employees[], int len)
{
    int indice = -1;
    for(int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int newEmployee(Employee employees[], int len, int id)
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
    indice = searchEmpty(employees, len);
    if (indice == -1)
    {
        printf("Error. Nomina de Empleados completo, no es posible ingresar mas empleados.\n\n");
    }
    else
    {
        while (checkIn == 'g' || flag == 0)
        {
            printf("Ingrese el nombre del Empleado(maximo 20 caracteres): ");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad)>20 && tries > 0)
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
            while(strlen(auxCad)>20 && tries > 0)
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

            printf("Ingrese el salario correspondiente: ");
            scanf("%d", &salary);
            while ((salary > 100000 || salary < 10000) && tries > 0)
            {
                printf("Salario ingresado incorrecto. Reingrese(10.000-100.000): ");
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
            scanf("%d", &sector);
            while ((sector < 1 || sector > 50) && tries > 0)
            {
                printf("Numero de sector incorrecto. Ingrese un sector: ");
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
            employees[indice] = addEmployee(id, name, lastName, salary, sector);
            printf("Empleado ingresado al sistema exitosamente.\n\n");
            isOk = 1;
        }
        else
        {
            printf("ERROR. No se ha podido ingresar el empleado al sistema.\n\n");
        }
    }
    return isOk;
}

int findEmployeeById(Employee employees[], int len, int id)
{
    int indice = -1;
    for(int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 0 && employees[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

void removingEmployee(Employee employees[], int len)
{
    int auxID;
    int indice;

    printf("\n\n------ EMPLEADOS | ID ------\n\n");
    printf("Ingrese el ID del empleado (Ref ID: 7000): ");
    scanf("%d", &auxID);
    indice = findEmployeeById(employees, len, auxID);
    if (indice == -1)
    {
        printf("ID ingresado no existe en el sistema.\n\n");
        system("pause");
    }
    else
    {
        removeEmployee(employees, len, auxID);
    }
}

int modifyMenu(Employee employees[], int len, int id)
{
    int option;
    int indice;

    indice = findEmployeeById(employees, len, id);
    system("cls");
    printf("ID del empleado a modificar: %d\n", id);
    printf("Nombre del empleado a modificar: %s %s\n\n", employees[indice].name, employees[indice].lastName);

    printf("------  EMPLEADOS | MODIFICACIONES  ------\n\n");
    printf("1) Modificar NOMBRE\n");
    printf("2) Modificar APELLIDO\n");
    printf("3) Modificar SALARIO\n");
    printf("4) Modificar SECTOR\n");
    printf("5) Salir\n\n");
    printf("Elija opcion: ");
    scanf("%d", &option);

    return option;
}

void modifyingEmployee(Employee employees[], int len)
{
    int auxID;
    int indice;

    printf("\n\n------ EMPLEADOS | ID ------\n\n");
    printf("Ingrese el ID del empleado (Ref ID: 7000): ");
    scanf("%d", &auxID);
    indice = findEmployeeById(employees, len, auxID);
    if (indice == -1)
    {
        printf("ID ingresado no existe en el sistema.\n\n");
        system("pause");
    }
    else
    {
        modifyMenuCases(employees, len, auxID);
    }
}

void modifyMenuCases(Employee employess[], int tam, int id)
{
    char follow = 'n';
    char name[51];
    char lastName[51];
    char resp;
    int tries = 3;
    int salary;
    int sector;
    int indice;

    indice = findEmployeeById(employess, tam, id);

    do
    {
        switch(modifyMenu(employess, tam, id))
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
            }
            else
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
                    strcpy(employess[indice].name, name);
                    printf("Nuevo NOMBRE modificado exitosamente.\n\n");
                    system("pause");
                }
                else
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
            }
            else
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
                    strcpy(employess[indice].lastName, lastName);
                    printf("Nuevo APELLIDO modificado exitosamente.\n\n");
                    system("pause");
                }
                else
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
            }
            else
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
                    employess[indice].salary = salary;
                    printf("Nuevo SALARIO modificado exitosamente.\n\n");
                    printf("-ID-      -NOMBRE-       -APELLIDO-       -SALARIO-       -SECTOR-\n");
                    printEmployee(employess[indice]);
                    system("pause");
                }
                else
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
            }
            else
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
                    employess[indice].sector = sector;
                    printf("Nuevo SECTOR modificado exitosamente.\n\n");
                    printf("-ID-      -NOMBRE-       -APELLIDO-       -SALARIO-       -SECTOR-\n");
                    printEmployee(employess[indice]);
                    system("pause");
                }
                else
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
            break;
            system("pause");
        }
    }
    while(follow == 'n');
}

void printEmployee(Employee employeeX)
{
    printf("%d   %10s        %10s         %.2f          %02d\n",
           employeeX.id,
           employeeX.name,
           employeeX.lastName,
           employeeX.salary,
           employeeX.sector);
}

void printEmployees(Employee employees[], int len)
{
    int flag = 0;

    printf("\n\n-ID-      -NOMBRE-       -APELLIDO-        -SALARIO-       -SECTOR-\n");

    for(int i=0; i < len; i++)
    {
        if(employees[i].isEmpty == 0)
        {
            printEmployee(employees[i]);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        system("cls");
        printf("\nNo se han encontrados empleados en el sistema.\n");
    }
    printf("\n\n");

}

int removeEmployee(Employee employees[], int len, int id)
{
    int follow = 0;
    int tries = 3;
    char resp;
    int indice;

    system("cls");
    printf("------  BAJAS | EMPLEADOS  ------\n\n");
    printf("-ID-      -NOMBRE-       -APELLIDO-       -SALARIO-       -SECTOR-\n");
    indice = findEmployeeById(employees, len, id);
    printEmployee(employees[indice]);
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
        employees[indice].isEmpty = 1;
        printf("Se ha dado de baja correctamente el empleado del sistema.\n\n");
        follow = 1;
    }
    else
    {
        printf("Operacion cancelada.\n");
    }
    return follow;
}

int sortEmployees(Employee employees[], int len, int order)
{
    int isOk = 0;
    char auxCad[51];
    int auxSal;
    int auxId;
    int auxSector;

    for (int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if (order == 1)
            {
                if (employees[i].isEmpty == 0 && employees[j].isEmpty == 0 && employees[i].sector > employees[j].sector)
                {
                    strcpy(auxCad, employees[i].lastName);
                    strcpy(employees[i].lastName, employees[j].lastName);
                    strcpy(employees[j].lastName, auxCad);

                    auxSector = employees[i].sector;
                    employees[i].sector = employees[j].sector;
                    employees[j].sector = auxSector;

                    strcpy(auxCad, employees[i].name);
                    strcpy(employees[i].name, employees[j].name);
                    strcpy(employees[j].name, auxCad);

                    auxSal = employees[i].salary;
                    employees[i].salary = employees[j].salary;
                    employees[j].salary = auxSal;

                    auxId = employees[i].id;
                    employees[i].id = employees[j].id;
                    employees[j].id = auxId;
                    isOk = 1;
                }
                if (employees[i].sector == employees[j].sector && strcmp(employees[i].lastName,employees[j].lastName) > 0 && employees[i].isEmpty == 0 && employees[j].isEmpty == 0){

                    strcpy(auxCad, employees[i].lastName);
                    strcpy(employees[i].lastName, employees[j].lastName);
                    strcpy(employees[j].lastName, auxCad);

                    auxSector = employees[i].sector;
                    employees[i].sector = employees[j].sector;
                    employees[j].sector = auxSector;

                    strcpy(auxCad, employees[i].name);
                    strcpy(employees[i].name, employees[j].name);
                    strcpy(employees[j].name, auxCad);

                    auxSal = employees[i].salary;
                    employees[i].salary = employees[j].salary;
                    employees[j].salary = auxSal;

                    auxId = employees[i].id;
                    employees[i].id = employees[j].id;
                    employees[j].id = auxId;
                    isOk = 1;
                }
            }
        }
    }
    return isOk;
}
void reportEmployees(Employee employees[], int len)
{
    char salir = 't';
    char option;
    int tries = 3;
    int sort;
    do
    {
        system("cls");
        printf("------ INFORMES | EMPLEADOS ------\n\n");
        printf("A) Informar lista de empleados ordenados alfabeticamente por Apellido y Sector\n");
        printf("B) Informar total y promedio de todos los salarios, y cuantos empleados superan el salario promedio\n");
        printf("C) Salir\n\n");
        printf("------ EMPLEADOS ACTUAL ------\n");
        printEmployees(employees, len);
        printf("\n");
        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%c", &option);
        while ((option != 'a' && option != 'b' && option != 'c') && tries > 0)
        {
            printf("Opcion seleccionada incorrecta, reingrese ('a','b' o 'c'): ");
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
            sort = sortEmployees(employees, len, 1);
            if (sort == 1)
            {
                printf("------ EMPLEADOS ORDENADOS ------\n");
                printEmployees(employees, len);
                system("pause");
            }
            else
            {
                printf("El proceso de ordenamiento ha fallado!\n");
                system("pause");
            }
            break;
        case 'b':
            sortEmployeesSalary(employees, len);
            break;
        case 'c':
            salir = 'f';
            break;
        }
    }
    while(salir == 't');
}

void sortEmployeesSalary(Employee employees[], int len)
{
    int acumulador = 0;
    float promedio;
    int cantEmployee = 0;
    float mayor;
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 0)
        {
            cantEmployee++;
        }
    }
    for(int i = 0; i < cantEmployee; i++)
    {
        acumulador += employees[i].salary;
        promedio = acumulador / cantEmployee;
        if(mayor < employees[i].salary && employees[i].isEmpty == 0)
        {
            mayor = employees[i].salary;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if(employees[i].salary > promedio && employees[i].isEmpty == 0)
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

int checkEmployee(Employee employees[], int len)
{
    int isOk = 0;
    for(int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 0)
        {
            isOk = 1;
        }
    }
    return isOk;
}
