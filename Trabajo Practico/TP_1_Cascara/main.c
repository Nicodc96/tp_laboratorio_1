#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    float primerNum = 0;
    float segundoNum = 0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factoPrimer;
    float factoSegundo;
    char seguir='s';

    do{
        switch(menu(&primerNum, &segundoNum))
        {
            case 1:
                system("cls");
                printf("Ingrese el Primer Operando: ");
                scanf("%f", &primerNum);
                printf("Primer numero ingresado: %.2f\n\n", primerNum);
                break;
            case 2:
                system("cls");
                printf("Ingrese el Segundo Operando: ");
                scanf("%f", &segundoNum);
                printf("Primer numero ingresado: %.2f\n", primerNum);
                printf("Segundo numero ingresado: %.2f\n\n", segundoNum);
                break;
            case 3:
                suma = sumar(primerNum, segundoNum);
                printf("La suma de los operandos es: %.2f\n\n", suma);
                printf("Volver al menu: s\nSalir: n\n\n");
                seguir = getch();
                if (seguir == 's')
                    {
                        system("cls");
                        break;
                    }
            case 4:
                resta = restar(primerNum, segundoNum);
                printf("La resta de los operandos es: %.2f\n\n", resta);
                printf("Volver al menu: s\nSalir: n\n\n");
                seguir = getch();
                if (seguir == 's')
                    {
                        system("cls");
                        break;
                    }
            case 5:
                division = dividir(primerNum, segundoNum);
                if (division == -1)
                    {
                        printf("No es posible dividir por 0.\n\n");
                    } else
                            {
                                printf("La division de los operandos es: %.2f\n\n", division);
                            }
                printf("Volver al menu: s\nSalir: n\n\n");
                seguir = getch();
                if (seguir == 's')
                    {
                        system("cls");
                        break;
                    }
            case 6:
                multiplicacion = multiplicar(primerNum, segundoNum);
                printf("La multiplicacion de los operandos es: %.2f\n\n", multiplicacion);
                printf("Volver al menu: s\nSalir: n\n\n");
                seguir = getch();
                if (seguir == 's')
                    {
                        system("cls");
                        break;
                    }
            case 7:
                factoPrimer = factorizacionUno(primerNum);
                factoSegundo = factorizacionDos(segundoNum);
                printf("Factorial del primer Operando es: %.2f\nFactorial del segundo Operando es:  %.2f\n\n", factoPrimer, factoSegundo);
                printf("Volver al menu: s\nSalir: n\n\n");
                seguir = getch();
                if (seguir == 's')
                    {
                        system("cls");
                        break;
                    } else {
                            seguir = 'n';
                            }
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("\nOpcion seleccionada invalida, volviendo al menu.. \n\n");
        }
        } while(seguir=='s');

    return 0;
}
