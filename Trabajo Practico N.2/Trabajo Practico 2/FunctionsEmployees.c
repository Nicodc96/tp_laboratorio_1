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
    for (int i = 0; i < len; i++){
        employees[i].isEmpty = 1;
    }
    return 0;
}

int addEmployee(Employee employees[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    Employee newEmployee;
    int isOk = -1;

    for (int i = 0; i < len; i++){
        if (employees[i].isEmpty == 1){
            newEmployee.id = id;
            strcpy(newEmployee.name, name);
            strcpy(newEmployee.lastName, lastName);
            newEmployee.salary = salary;
            newEmployee.sector = sector;
            newEmployee.isEmpty = 0;
            isOk = 0;
            break;
        }
    }
    return isOk;
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

int searchEmployee(int id, Employee employees[], int len){
    int indice = -1;
        for(int i = 0; i < len; i++){
         if (!employees[i].isEmpty && employees[i].id == id){
          indice = i;
          break;
        }
    }
    return indice;
}

int newEmployee(Employee employees[], int len){
    int isOk = 0;
    int available;
    int indice;
    int id;
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
        printf("Ingrese el numero de ID (4 digitos): ");
        scanf("%d", &id);
        while (id < 9999 && tries > 0){
            tries--;
            printf("ID ingresado contiene demasiados digitos, reingrese: ");
            scanf("%d", &id);
        }
        available = searchEmployee(id, employees, len);
        if (available != -1){
            printf("ID ya registrado.\n\n");
            system("pause");
        } else{
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
        }
        employees[indice] = addEmployee(employees, len, id, name, lastName, salary, sector);
        printf("Empleado ingresado al sistema exitosamente.\n\n");
        isOk = 1;
    }
    return isOk;
}
