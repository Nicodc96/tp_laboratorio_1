#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ArrayEmployees.h"

#define LEN 1000

int main()
{
    Employee listEmployee[LEN];
    int employeeID = 7000;
    int checkTrue;
    char follow = 'n';

    initEmployees(listEmployee, LEN);

    // Utilizar esta declaracion junto al prototipo y el desarrollo de la funcion si se desea testear rapidamente el TP
    // employeeID = employeeID + hardcodearEmpleados(listEmployee, LEN, 10);

    do{
        switch(menu()){
    case 'a':
        if(newEmployee(listEmployee, LEN, employeeID)){
            employeeID++;
        }
        break;
    case 'b':
        checkTrue = checkEmployee(listEmployee, LEN);
        if (checkTrue == 1){
        modifyingEmployee(listEmployee, LEN);
        } else {
            printf("\nSe debe dar de ALTA al/los empleado(s) antes de realizar esta accion.\n");
        }
        break;
    case 'c':
        checkTrue = checkEmployee(listEmployee, LEN);
        if (checkTrue == 1){
        removingEmployee(listEmployee, LEN);
        } else {
            printf("\nSe debe dar de ALTA al/los empleado(s) antes de realizar esta accion.\n");
        }
        break;
    case 'd':
        checkTrue = checkEmployee(listEmployee, LEN);
        if (checkTrue == 1){
        reportEmployees(listEmployee, LEN);
        } else {
            printf("\nSe debe dar de ALTA al/los empleado(s) antes de realizar esta accion.\n");
        }
        break;
    case 'e':
        printf("\n\nConfirmar salida (y/n): ");
        fflush(stdin);
        follow = getchar();
        printf("\n");
        while(follow != 'y' && follow != 'n'){
            printf("\nOpcion incorrecta, ingrese (y/n): \n");
            fflush(stdin);
            follow = getchar();
        }
        break;
    default:
        system("cls");
        printf("Opcion elegida invalida, volviendo al menu...\n");
        break;
        }
    printf("\n\n");
    system("pause");
    }while (follow == 'n');

    return 0;
}
