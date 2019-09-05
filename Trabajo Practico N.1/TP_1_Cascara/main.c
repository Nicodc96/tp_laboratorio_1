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
    long double factoPrimer;
    long double factoSegundo;
    char seguir='s';

    while (seguir == 's'){
        switch(menu(&primerNum, &segundoNum))
        {
            case 1:
                printf("Ingrese el Primer Operando: ");
                scanf("%f", &primerNum);
                system("cls");
                break;
            case 2:
                printf("Ingrese el Segundo Operando: ");
                scanf("%f", &segundoNum);
                system("cls");
                break;
            case 3:
                suma = sumar(primerNum, segundoNum);
                printf("La suma de los operandos es: %.2f\n\n", suma);
                printf("Volver al menu: s\nSalir: n\n\n");
                fflush(stdin);
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
                fflush(stdin);
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
                fflush(stdin);
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
                fflush(stdin);
                seguir = getch();
                if (seguir == 's')
                    {
                        system("cls");
                        break;
                    }
            case 7:
                factoPrimer = factorizacion(primerNum);
                factoSegundo = factorizacion(segundoNum);
                if (factoPrimer == -1)
                    {
                        printf("No se puede realizar factorial de un numero negativo.\n");
                    } else
                    {
                        printf("Factorial del primer Operando es: %.2Lf\n\n", factoPrimer); // [-std=c99] ACTIVADO
                    }
                if (factoSegundo == -1)
                    {
                        printf("No se puede realizar factorial de un numero negativo.\n");
                    } else
                        {
                             printf("Factorial del segundo Operando es: %.2Lf\n\n", factoSegundo);
                        }
                printf("Volver al menu: s\nSalir: n\n\n");
                fflush(stdin);
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
                suma = sumar(primerNum, segundoNum);
                printf("La suma de los operandos es: %.2f\n", suma);
                resta = restar(primerNum, segundoNum);
                printf("La resta de los operandos es: %.2f\n", resta);
                division = dividir(primerNum, segundoNum);
                if (division == -1)
                    {
                        printf("No es posible dividir por 0.\n");
                    } else
                            {
                                printf("La division de los operandos es: %.2f\n", division);
                            }
                multiplicacion = multiplicar(primerNum, segundoNum);
                printf("La multiplicacion de los operandos es: %.2f\n", multiplicacion);
                factoPrimer = factorizacion(primerNum);
                factoSegundo = factorizacion(segundoNum);
                if (factoPrimer == -1)
                    {
                        printf("No se puede realizar factorial de un numero negativo.\n");
                    } else
                    {
                        printf("Factorial del primer Operando es: %.2Lf\n\n", factoPrimer); // [-std=c99] ACTIVADO
                    }
                if (factoSegundo == -1)
                    {
                        printf("No se puede realizar factorial de un numero negativo.\n");
                    } else
                        {
                             printf("Factorial del segundo Operando es: %.2Lf\n\n", factoSegundo);
                        }
                printf("Volver al menu: s\nSalir: n\n\n");
                fflush(stdin);
                seguir = getch();
                if (seguir == 's')
                    {
                        system("cls");
                        break;
                    } else {
                            seguir = 'n';
                            }
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("\nOpcion seleccionada invalida, volviendo al menu.. \n\n");
        }
        }

    return 0;
}
