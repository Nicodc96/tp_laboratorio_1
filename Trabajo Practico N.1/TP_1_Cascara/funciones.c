#include "funciones.h"
#include <stdio.h>

int menu(float* primerNum, float* segundoNum)
{
    int opcion=0;

        printf("1- Ingresar 1er operando (A = %.2f)\n", *primerNum);
        printf("2- Ingresar 2do operando (B = %.2f)\n", *segundoNum);
        printf("3- Calcular la Suma (A+B)\n");
        printf("4- Calcular la Resta (A-B)\n");
        printf("5- Calcular la Division (A/B)\n");
        printf("6- Calcular la Multiplicacion (A*B)\n");
        printf("7- Calcular el Factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n\n");
        printf("9- Salir\n");
        printf("Opcion elegida: ");
        scanf("%d", &opcion);

        return opcion;
}

float sumar(float primerOpe, float segundoOpe)
{
    float resultado;

    resultado = primerOpe + segundoOpe;

    return resultado;
}

float restar(float primerOpe, float segundoOpe)
{
    float resultado;

    resultado = primerOpe - segundoOpe;

    return resultado;
}

float dividir(float primerOpe, float segundoOpe)
{
    float resultado;

    if (segundoOpe == 0)
    {
        resultado = -1;
    } else
        {
            resultado = primerOpe / segundoOpe;
        }

    return resultado;
}

float multiplicar(float primerOpe, float segundoOpe)
{
    float resultado;

    resultado = primerOpe * segundoOpe;

    return resultado;
}

float factorizacion(long double primerOpe)
{
    long double i, factorOpe = 1;
    if (primerOpe >= 0)
    {
        for (i = 1; i <= primerOpe; i++)
        factorOpe = factorOpe * i;
    } else
        {
            factorOpe = -1;
        }

    return factorOpe;
}

