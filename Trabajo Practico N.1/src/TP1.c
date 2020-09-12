/*
 ============================================================================
 Name        : TP1.c
 Author      : Lautaro N. Díaz
 Version     : 2.0
 Copyright   : -
 Description : T.P N°1 for Laboratory 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "functions.h"

int main()
{
	setbuf(stdout, NULL);
    int primerNum = 0;
    int segundoNum = 0;
    int suma = 0;
    int resta = 0;
    int multiplicacion = 0;
    int checkOperation = 0;
    float division = 0;
    double factoPrimer = 0;
    double factoSegundo = 0;
    char seguir = 'n';

    do
    {
        switch(menu(&primerNum, &segundoNum))
        {
            case 1:
                printf("Ingrese el Primer Operando: ");
                scanf("%d", &primerNum);
                break;
            case 2:
                printf("Ingrese el Segundo Operando: ");
                scanf("%d", &segundoNum);
                break;
            case 3:
                suma = sumar(primerNum, segundoNum);
                resta = restar(primerNum, segundoNum);
                division = dividir(primerNum, segundoNum);
                multiplicacion = multiplicar(primerNum, segundoNum);
                factoPrimer = factorial(primerNum);
                factoSegundo = factorial(segundoNum);
                printf("\nOperaciones realizadas correctamente!\n");
                checkOperation = 1;
                system("pause");
                break;
            case 4:
                if(!checkOperation)
                {
                    printf("Se debe realizar las operaciones antes de informar!\n");
                    system("pause");
                } else
                    {
                        menuInformes(suma, resta, division, multiplicacion, factoPrimer, factoSegundo);
                    }
                break;
            case 5:
                printf("Confimar salida (y/n): ");
                fflush(stdin);
                seguir = tolower(getchar());
                while (seguir != 'y' && seguir != 'n')
                {
                    printf("Respuesta ingresada incorrecta. Reingrese (y/n): ");
                    fflush(stdin);
                    seguir = tolower(getchar());
                }
                break;
        }
        system("cls");
    }while(seguir == 'n');
    return 0;
}
