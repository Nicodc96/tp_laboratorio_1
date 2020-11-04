#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir

    Author: Diaz, Lautaro Nicolas
    Version: 2.0
*****************************************************/

int main()
{
    int checkText = 0;
    int checkBin = 0;
    int checkEmployee = 0;
    char follow = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
                if (!checkText && !checkBin)
                {
                    if(controller_loadFromText("data.csv", listaEmpleados))
                    {
                        checkText = 1;
                    }
                } else
                    {
                        if (checkText == 1)
                        {
                            printf("\n------ Los datos en modo TEXTO ya se han cargado! ------\n");
                        }
                        if (checkBin == 1)
                        {
                            printf("\n------ Los datos en modo BINARIO ya se han cargado! ------\n");
                        }
                    }
                break;
            case 2:
                if (!checkBin && !checkText)
                {
                    if(controller_loadFromBinary("data.bin", listaEmpleados))
                    {
                        checkBin = 1;
                    }
                } else
                    {
                        if (checkText == 1)
                        {
                            printf("\n------ Los datos en modo TEXTO ya se han cargado! ------\n");
                        }
                        if (checkBin == 1)
                        {
                            printf("\n------ Los datos en modo BINARIO ya se han cargado! ------\n");
                        }
                    }
                break;
            case 3:
                if(checkText || checkBin)
                {
                   checkEmployee = controller_addEmployee(listaEmpleados);
                } else
                    {
                        printf("\n------ Se debe cargar una lista antes de realizar esta accion! ------\n");
                    }
                if(checkEmployee)
                {
                    printf("\n------Se ha dado de ALTA correctamente a un empleado! ------\n");
                }
                break;
            case 4:
                if(checkText || checkBin)
                {
                    controller_editEmployee(listaEmpleados);
                } else
                    {
                        printf("\n------ Se debe cargar una lista antes de realizar esta accion! ------\n");
                    }
                break;
            case 5:
                if(checkText || checkBin)
                {
                    controller_removeEmployee(listaEmpleados);
                } else
                    {
                        printf("\n------ Se debe cargar una lista antes de realizar esta accion! ------\n");
                    }
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                if(checkText || checkBin)
                {
                    controller_sortEmployee(listaEmpleados);
                } else
                    {
                        printf("\n------ Se debe cargar una lista antes de realizar esta accion! ------\n");
                    }
                break;
            case 8:
                if (checkBin == 1 || checkText == 1)
                {
                    controller_saveAsText("data.csv", listaEmpleados);
                } else
                    {
                        printf("\n------ Imposible guardar datos ya que no se han cargado empleados! ------\n");
                    }
                break;
            case 9:
                if (checkBin == 1 || checkText == 1)
                {
                    controller_saveAsBinary("data.bin", listaEmpleados);
                } else
                    {
                        printf("\n------ Imposible guardar datos ya que no se han cargado empleados! ------\n");
                    }
                break;
            case 10:
                printf("Confirmar salida (y/n): ");
                fflush(stdin);
                scanf("%c", &follow);
                while(follow != 'y' && follow != 'n')
                {
                    printf("Error. Reingrese (y/n): ");
                    fflush(stdin);
                    scanf("%c", &follow);
                }
                break;
            default:
                printf("\n------ Opcion seleccionada incorrecta. Reingrese! ------\n");
        }
        system("pause");
    }while(follow == 'n');

    return 0;
}
