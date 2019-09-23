#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ArrayEmployees.h"

#define LEN 1000

int main()
{
    Employee listEmployee[LEN];
    int employeeID = 7000;
    char follow = 'n';

    initEmployees(listEmployee, LEN);

    do{
        switch(menu()){
    case 'a':
        if(newEmployee(listEmployee, LEN, employeeID)){
            employeeID++;
        }
        break;
    case 'b':
        printf("\n\nOPCION B\n\n");
        break;
    case 'c':
        printf("\n\nOPCION C\n\n");
        break;
    case 'd':
        printf("\n\nOPCION D\n\n");
        break;
    case 'e':
        printf("\n\nConfirmar salida (y/n): ");
        fflush(stdin);
        follow = getche();
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
