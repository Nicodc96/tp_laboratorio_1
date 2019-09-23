#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "ArrayEmployees.h"

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
        while (checkIn == 'g'){
        printf("Ingrese el nombre del Empleado(maximo 50 caracteres): ");
        fflush(stdin);
        gets(auxCad);
        while(strlen(auxCad)>50 && tries > 0){
            tries--;
            printf("Nombre demasiado largo. Maximo 50 caracteres! Reingrese nombre: ");
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(name, auxCad);
        printf("\n");

        printf("Ingrese el apelldo del Empleado(maximo 50 caracteres): ");
        fflush(stdin);
        gets(auxCad);
        while(strlen(auxCad)>50 && tries > 0){
            tries--;
            printf("Apellido demasiado largo. Maximo 50 caracteres! Reingrese apellido: ");
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(lastName, auxCad);
        printf("\n");

        printf("Ingrese el salario correspondiente: ");
        scanf("%d", &salary);
        while ((salary >= 100000 || salary <= 0) && tries > 0){
            tries--;
            printf("Salario ingresado incorrecto. Reingrese: ");
            scanf("%d", &salary);
        }

        printf("Ingrese el sector del empleado (1-50): ");
        scanf("%d", &sector);
        while ((sector < 1 || sector > 50) && tries > 0){
            tries--;
            printf("Numero de sector incorrecto. Ingrese un sector: ");
            scanf("%d", &sector);
            }
        }
        employees[indice] = addEmployee(id, name, lastName, salary, sector);
        printf("Empleado ingresado al sistema exitosamente.\n\n");
        isOk = 1;
        }
    return isOk;
}

void findEmployeeById(Employee employees[], int len, int id){
    int flag = 0;
    int auxID;
    system("cls");
    printf("------  EMPLEADOS | ID  ------\n\n");
    printf("Ingrese el ID del empleado: ");
    scanf("%d", &auxID);
    for (int i = 0; i < len; i++){
        if (employees[i].id == auxID){
            printEmployees(employees[i]);
            flag = 1;
        }
    }
    if (flag == 0){
        printf("cls");
        printf("No se ha encontrado el empleado con el ID ingresado.\n");
    }
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
    char resp;
    int indice;
    int auxID;

    system("cls");
    printf("------  BAJAS | EMPLEADOS  ------\n\n");
    printf("Ingrese el ID del empleado: ");
    scanf("%d", &auxID);

    indice = searchEmployee(auxID, employees, len);
    if (indice == -1){
        printf("ID inexistente en el sistema.\n\n");
        system("pause");
    } else{
        printEmployees(employees[indice]);
        printf("Confirma BAJA? (y/n): ");
        fflush(stdin);
        resp = getche();
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

int searchEmployee(int id, Employee employees[], int len)
{
    int indice = -1;
    for(int i = 0; i < len; i++)
    {
        if (!employees[i].isEmpty && employees[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int sortEmployees(Employee employees[], int len, int order){
    int isOk = 0;



    return isOk;
}
