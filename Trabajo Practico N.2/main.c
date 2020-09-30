#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    ----------------------------------------------------
    Name: Trabajo Práctico N°2 para Laboratorio I
    Author: Lautaro N. Díaz
    Version: 2.0
    ----------------------------------------------------
*/

// BIBLIOTECA DE PROTOTIPOS Y ESTRUCTURA EMPLOYEE //
#include "ArrayEmployees.h"

// DEFINICIÓN DEL TAMAÑO DE LA LISTA DE EMPLEADOS //
#define LEN 1000

int main()
{
    Employee listEmployee[LEN];
    int employeeID = 7000;
    int checkTrue;
    char follow = 'n';

    if(initEmployees(listEmployee, LEN))
    {
    /*
        Quitar el comentario de la línea de código que se encuentra abajo para testear rápidamente el TP con 10 empleados
    */
    //  employeeID = employeeID + hardcodearEmpleados(listEmployee, LEN, 10);

    do
    {
        switch(menu())
        {
        case 'a':
            if(newEmployee(listEmployee, LEN, employeeID))
            {
                employeeID++;
            }
            break;
        case 'b':
            checkTrue = checkEmployee(listEmployee, LEN);
            if (checkTrue == 1)
            {
                modifyingEmployee(listEmployee, LEN);
            }
            else
            {
                printf("\nSe debe dar de ALTA al/los empleado(s) antes de realizar esta accion.\n");
            }
            break;
        case 'c':
            checkTrue = checkEmployee(listEmployee, LEN);
            if (checkTrue == 1)
            {
                removingEmployee(listEmployee, LEN);
            }
            else
            {
                printf("\nSe debe dar de ALTA al/los empleado(s) antes de realizar esta accion.\n");
            }
            break;
        case 'd':
            checkTrue = checkEmployee(listEmployee, LEN);
            if (checkTrue == 1)
            {
                reportEmployees(listEmployee, LEN);
            }
            else
            {
                printf("\nSe debe dar de ALTA al/los empleado(s) antes de realizar esta accion.\n");
            }
            break;
        case 'e':
            printf("\n\nConfirmar salida (y/n): ");
            fflush(stdin);
            follow = getchar();
            printf("\n");
            while(follow != 'y' && follow != 'n')
            {
                printf("\nOpcion incorrecta, ingrese (y/n): \n");
                fflush(stdin);
                follow = getchar();
            }
            break;
        default:
            system("cls");
            printf("ERROR! Opcion elegida invalida, volviendo al menu...\n");
            break;
        }
        printf("\n\n");
        system("pause");
    }
    while (follow == 'n');
    } else
        {
            printf("Error! La lista de empleados no pudo inicializarse y el programa debe terminar.\n");
            return EXIT_FAILURE;
        }

    return EXIT_SUCCESS;
}
