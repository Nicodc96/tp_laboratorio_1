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
        {7000, "Juan", "Perez", 'm', 18000, 26},
        {7001, "Lucia", "Positelli", 'f', 22000, 22},
        {7002, "Liliana", "Ramirez", 'f', 17130, 35},
        {7003, "Pedro", "Novich", 'm', 12500, 46},
        {7004, "Christian", "Baus", 'm', 16500, 7}
    };

    if (cantidad <= tam && cantidad < 11)
    {
        for (int i = 0; i < cantidad; i++)
        {
            x[i] = listaAuxiliar[i];
            counter++;
        }
    }
    return counter;
}


int menu(){
    char option;

    printf("-------- NOMINA DE EMPLEADOS --------\n\n");
    printf("A) ALTAS\n");
    printf("B) MODIFICACIONES\n");
    printf("C) BAJAS\n");
    printf("D) INFORMAR\n");
    printf("E) SALIR\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    option = getche();
        return option;
}

int initEmployees(Employee employees[], int len){
    int isOk = -1;
    for (int i = 0; i < len; i++){
        employees[i].isEmpty = 1;
        isOk = 0;
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

int searchEmpty(Employee employees[], int len){
    int indice = -1;
        for(int i = 0; i < len; i++){
         if (employees[i].isEmpty == 1){
          indice = i;
          break;
         }
        }
    return indice;
}

int newEmployee(Employee employees[], int len, int id){
    int isOk = 0;
    int flag = 0;
    int indice;
    int salary;
    int sector;
    int tries = 5;
    char checkIn = 'g';
    char name[51];
    char lastName[51];
    char auxCad[100];

    system("cls");
    printf("------  ALTAS | EMPLEADOS  ------\n\n");
    indice = searchEmpty(employees, len);
    if (indice == -1){
        printf("Error. Nomina de Empleados completo, no es posible ingresar mas empleados.\n\n");
    }else{
        while (checkIn == 'g' || flag == 0){
        printf("Ingrese el nombre del Empleado(maximo 50 caracteres): ");
        fflush(stdin);
        gets(auxCad);
        while(strlen(auxCad)>50 && tries > 0){
            printf("Nombre demasiado largo. Maximo 50 caracteres! Reingrese nombre: ");
            fflush(stdin);
            gets(auxCad);
            tries--;
        }
        if (tries == 0){
            printf("Demasiados intentos fallidos, cancelando operacion...\n\n");
            checkIn = 'f';
            break;
        }
        strcpy(name, auxCad);
        printf("\n");
        tries = 5;

        printf("Ingrese el apelldo del Empleado(maximo 50 caracteres): ");
        fflush(stdin);
        gets(auxCad);
        while(strlen(auxCad)>50 && tries > 0){
            printf("Apellido demasiado largo. Maximo 50 caracteres! Reingrese apellido: ");
            fflush(stdin);
            gets(auxCad);
            tries--;
        }
        if (tries == 0){
            printf("Demasiados intentos fallidos, cancelando operacion...\n\n");
            checkIn = 'f';
            break;
        }
        strcpy(lastName, auxCad);
        printf("\n");
        tries = 5;

        printf("Ingrese el salario correspondiente: ");
        scanf("%d", &salary);
        while ((salary > 100000 || salary < 7000) && tries > 0){
            printf("Salario ingresado incorrecto. Reingrese(7.000-100.000): ");
            scanf("%d", &salary);
            tries--;
        }
        if (tries == 0){
            printf("Demasiados intentos fallidos, cancelando operacion...\n\n");
            checkIn = 'f';
            break;
        }
        printf("\n");
        tries = 5;

        printf("Ingrese el sector del empleado (1-50): ");
        scanf("%d", &sector);
        while ((sector < 1 || sector > 50) && tries > 0){
            printf("Numero de sector incorrecto. Ingrese un sector: ");
            scanf("%d", &sector);
            tries--;
            }
        if (tries == 0){
            printf("Demasiados intentos fallidos, cancelando operacion...\n\n");
            checkIn = 'f';
            break;
            }
        flag = 1;
        }
        if (checkIn == 'g'){
        employees[indice] = addEmployee(id, name, lastName, salary, sector);
        printf("Empleado ingresado al sistema exitosamente.\n\n");
        isOk = 1;
        } else{
            printf("ERROR. No se ha podido ingresar el empleado al sistema.\n\n");
            }
        }
    return isOk;
}

void findEmployeeById(Employee employees[], int len, int id){
    // Llamo a la funcion modifyMenuCases
    modifyMenuCases(employees, len, id);
}

int searchEmployee(Employee employee[], int tam){
    int flag;
    int auxID;
    int indice;
    system("cls");
    printf("------ EMPLEADOS | ID ------\n\n");
    printf("Ingrese el ID del empleado (Ref ID: 7000): ");
    scanf("%d", &auxID);

    indice = searchSpecificEmployee(auxID, employee, tam);

    if (indice == -1){
        printf("cls");
        printf("Error. No existe empleado(s) con el ID ingresado.\n\n");
        flag = 0;
    } else{
        findEmployeeById(employee, tam, auxID);
        flag = 1;
    }
    return flag;
}

int modifyMenu(){
    int option;
    system ("cls");

    printf("------  EMPLEADOS | MODIFICACIONES  ------\n\n");
    printf("1) Modificar NOMBRE\n");
    printf("2) Modificar APELLIDO\n");
    printf("3) Modificar SALARIO\n");
    printf("4) Modificar SECTOR\n");
    printf("5) Salir\n\n");
    scanf("%d", &option);

    return option;
}

void modifyMenuCases(Employee employess[], int tam, int id){
    char follow = 'n';
    char name[51];
    char lastName[51];
    char resp;
    int tries = 3;
    int salary;
    int indice;

    indice = searchSpecificEmployee(id, employess, tam);
    printf("ID del empleado: %d\n", id);
    printf("Nombre del empleado: %s %s\n\n", employess[indice].name, employess[indice].lastName);

    do{
       switch(modifyMenu()){
   case 1:
       printf("Ingrese el nuevo NOMBRE a modificar: ");
       gets(name);
       while (strlen(name) > 49 || tries > 0)
       {
           printf("Nombre ingresado demasiado largo! Reingrese: ");
           gets(name);
           tries--;
       }
       if (tries == 0)
       {
           printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
       } else{
           tries = 3;
            printf("Confirmar cambio (y/n): ");
            fflush(stdin);
            resp = getchar();
            while (resp != 'y' && resp != 'n' && tries > 0){
                printf("Respuesta incorrecta. Reintente (y/n): ");
                tries--;
                fflush(stdin);
                resp = getchar();
            }
            if (tries == 0){
                printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
            }
            if (resp == 'y'){
            strcpy(employess[indice].name, name);
            printf("Nuevo NOMBRE modificado exitosamente.\n\n");
            printEmployees(employess[indice]);
            } else {
                printf("Se ha cancelado exitosamente la operacion.\n\n");
            }
       }
    break;
   case 2:
       printf("Ingrese el nuevo APELLIDO a modificar: ");
       gets(lastName);
       while (strlen(lastName) > 49 && tries > 0)
       {
           printf("Apellido ingresado demasiado largo! Reingrese: ");
           gets(lastName);
           tries--;
       }
       if (tries == 0)
       {
           printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
       } else{
           tries = 3;
            printf("Confirmar cambio (y/n): ");
            fflush(stdin);
            resp = getchar();
            while (resp != 'y' && resp != 'n' && tries > 0){
                printf("Respuesta incorrecta. Reintente (y/n): ");
                tries--;
                fflush(stdin);
                resp = getchar();
            }
            if (tries == 0){
                printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
            }
            if (resp == 'y'){
            strcpy(employess[indice].lastName, lastName);
            printf("Nuevo APELLIDO modificado exitosamente.\n\n");
            printEmployees(employess[indice]);
            } else {
                printf("Se ha cancelado exitosamente la operacion.\n\n");
            }
       }
    break;
   case 3:
       printf("Ingrese el nuevo SALARIO a modificar: ");
       scanf("%d", &salary);
       while ((salary > 100000 || salary < 7000) && tries > 0){
            printf("Salario ingresado incorrecto. Reingrese(7.000-100.000): ");
            scanf("%d", &salary);
            tries--;
        }
       if (tries == 0){
        printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
       } else{
            tries = 3;
            printf("Confirmar cambio (y/n): ");
            fflush(stdin);
            resp = getchar();
            while (resp != 'y' && resp != 'n' && tries > 0){
                printf("Respuesta incorrecta. Reintente (y/n): ");
                tries--;
                fflush(stdin);
                resp = getchar();
            }
            if (tries == 0){
                printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
            }
            if (resp == 'y'){
                employess[indice].salary = salary;
                printf("Nuevo SALARIO modificado exitosamente.\n\n");
                printEmployees(employess[indice]);
            } else {
                printf("Se ha cancelado exitosamente la operacion.\n\n");
            }
       }
    break;
   case 4:
       printf("Ingrese el nuevo SECTOR a modificar: ");
       scanf("%d", &salary);
       while ((salary > 100000 || salary < 7000) && tries > 0){
            printf("Salario ingresado incorrecto. Reingrese(7.000-100.000): ");
            scanf("%d", &salary);
            tries--;
        }
       if (tries == 0){
        printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
       } else{
            tries = 3;
            printf("Confirmar cambio (y/n): ");
            fflush(stdin);
            resp = getchar();
            while (resp != 'y' && resp != 'n' && tries > 0){
                printf("Respuesta incorrecta. Reintente (y/n): ");
                tries--;
                fflush(stdin);
                resp = getchar();
            }
            if (tries == 0){
                printf("Demasiados intentos fallidos, volviendo al menu.\n\n");
            }
            if (resp == 'y'){
                employess[indice].salary = salary;
                printf("Nuevo SALARIO modificado exitosamente.\n\n");
                printEmployees(employess[indice]);
            } else {
                printf("Se ha cancelado exitosamente la operacion.\n\n");
            }
       }
    break;
    case 5:
        printf("Confirmar Salida (y/n): ");
        fflush(stdin);
        follow = getchar();
        while(follow != 'y' && follow != 'n'){
            printf("\nOpcion incorrecta, ingrese (y/n): \n");
            fflush(stdin);
            follow = getchar();
        }
    break;
   default:
       printf("Opcion seleccionada incorrecta/inexistente.\n\n");
    break;
       }
    printf("\n\n");
    system("pause");
    }while(follow == 'n');
}

void printEmployees(Employee employeeX){
    printf("%d   %10s      %10s    %.2f   %d",
           employeeX.id,
           employeeX.name,
           employeeX.lastName,
           employeeX.salary,
           employeeX.sector);
}

int removeEmployee(Employee employees[], int len, int id){
    int seguir = 0;
    int tries = 3;
    char resp;
    int indice;
    int auxID;

    system("cls");
    printf("------  BAJAS | EMPLEADOS  ------\n\n");
    printf("Ingrese el ID del empleado: ");
    scanf("%d", &auxID);

    indice = searchSpecificEmployee(auxID, employees, len);

    if (indice == -1){
        printf("ID inexistente en el sistema.\n\n");
        system("pause");
    } else{
        printEmployees(employees[indice]);
        printf("Confirmar BAJA (y/n): ");
        fflush(stdin);
        resp = getchar();
        while(resp != 'y' && resp != 'n' && tries > 0){
            printf("\nOpcion incorrecta, ingrese (y/n): \n");
            fflush(stdin);
            resp = getchar();
            tries--;
        }
        if (tries == 0){
            printf("Demasiados intentos fallidos. Cancelando operacion...");
        }
        if (resp == 's'){
            employees[indice].isEmpty = 1;
            printf("Se ha dado de baja correctamente el empleado del sistema.\n\n");
            seguir = 1;
        } else{
            printf("Operacion cancelada.\n\n");
        }
    }
    return seguir;
}

int searchSpecificEmployee(int id, Employee employees[], int len)
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

int sortEmployees(Employee employees[], int len, int order); ////////////////////////
