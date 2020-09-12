/*
 * functions.c
 *
 *      Author: Lautaro N. Díaz
 */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int menu(int* primerNum, int* segundoNum)
{
    int opcion;

    printf("--------------- CALCULADORA | UTN ---------------\n\n");
    printf("1) Ingresar 1er operando (A = %d)\n", *primerNum);
    printf("2) Ingresar 2do operando (B = %d)\n", *segundoNum);
    printf("3) Calcular todas las operaciones\n");
    printf("    a) Calcular la SUMA           (A+B)\n");
    printf("    b) Calcular la RESTA          (A-B)\n");
    printf("    c) Calcular la DIVISION       (A+B)\n");
    printf("    d) Calcular la MULTIPLICACION (A*B)\n");
    printf("    e) Calcular el FACTORIAL      (A! y B!)\n");
    printf("4) Informar los resultados\n");
    printf("5) Salir\n\n");
    printf("Opcion elegida: ");
    scanf("%d", &opcion);
    while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5)
    {
        printf("Opcion incorrecta! Reingrese: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    return opcion;
}

void menuInformes(int reSuma, int reResta, float reDiv, int reMul, double reFacUno, double reFacDos)
{
    printf("\n    a) El resultado de A+B es: %d\n", reSuma);
    printf("    b) El resultado de A-B es: %d\n", reResta);
    if (reDiv == -1)
    {
        printf("    c) No es posible dividir por 0.\n");
    } else
        {
            printf("    c) El resultado de A/B es: %.1f\n", reDiv);
        }
    printf("    d) El resultado de A*B es: %d\n", reMul);
    printf("    e) El resultado de A! es ");
    if(reFacUno == -1)
    {
        printf("imposible de calcular! (numero negativo) y el resultado de B! es ");
    } else if(reFacUno == -2)
        {
            printf("demasiado grande para mostrar (>63) y el resultado de B! es ");
        } else
            {
                printf("%.0lf y el resultado de B! es ", reFacUno);
            }
    if(reFacDos == -1)
    {
        printf("imposible de calcular! (numero negativo).\n");
    } else if (reFacDos == -2)
        {
            printf("demasiado grande para mostrar (>63).\n");
        } else
            {
                printf("%.0lf.\n", reFacDos);
            }
    system("pause");
}

int sumar(int primerOpe, int segundoOpe)
{
    int resultado;

    return resultado = primerOpe + segundoOpe;
}

int restar(int primerOpe, int segundoOpe)
{
    int resultado;

    return resultado = primerOpe - segundoOpe;
}

float dividir(float primerOpe, float segundoOpe)
{
    float resultado;

    if (segundoOpe == 0)
    {
        resultado = -1;
    } else if (primerOpe == 0 && segundoOpe != 0)
        {
            resultado = 0;
        } else
            {
                resultado = primerOpe / segundoOpe;
            }
    return resultado;
}

int multiplicar(int primerOpe, int segundoOpe)
{
    int resultado;
    if(primerOpe == 0 || segundoOpe == 0)
    {
        resultado = 0;
    } else
        {
            resultado = primerOpe * segundoOpe;
        }
    return resultado;
}

double factorial(int numero)
{
    double resultado = 1;
    int i;
    if (numero == 0)
    {
        resultado = 1;
    } else if(numero < 0)
        {
            resultado = -1;
        } else if(numero > 62)
            {
                resultado = -2;
            } else
                {
                    for (i = 1; i <= numero; i++)
                    {
                        resultado = resultado * i;
                    }
                }
    return resultado;
}
