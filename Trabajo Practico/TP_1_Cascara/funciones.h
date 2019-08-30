#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int menu()
{
    int opcion=0;
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la Suma (A+B)\n");
        printf("4- Calcular la Resta (A-B)\n");
        printf("5- Calcular la Division (A/B)\n");
        printf("6- Calcular la Multiplicacion (A*B)\n");
        printf("7- Calcular el Factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n\n");
        printf("9- Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);

        return opcion;
}

#endif // FUNCIONES_H_INCLUDED
