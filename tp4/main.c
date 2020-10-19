#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <math.h>

void cargapila (Pila*);
void pasapila (Pila*, Pila*);
void pasapila2 (Pila*, Pila*);
int findmenor (Pila*);
void ordenar (Pila*, Pila*);
void infiltrado (Pila*, int);
void ordenar2 (Pila*, Pila*);
int sumita (Pila);
int suma (Pila);
int cont (Pila);
float divi (int, int);
float prom (Pila);
int crearnum (Pila);

int main()
{
    Pila dada, dada2;
    inicpila(&dada);
    inicpila(&dada2);
    cargapila(&dada);
    mostrar(&dada);
    int num=prom(dada);
    printf("%i", num);
    return 0;
}


/* permite ingresar varios elementos a una Pila, tantos como quiera el usuario*/
void cargapila (Pila* dada)
{
    char opc='s';
    while (opc=='s')
    {
        leer(dada);
        printf("desea seguir ingresando elementos en dada?(s/n)");
        fflush(stdin);
        scanf("%c", &opc);
    }
}

/*pasa todos los elementos de una pila a otra.*/
void pasapila (Pila* p2a, Pila* p2b)
{
    while (!pilavacia(p2a))
    {
        apilar(p2b, desapilar(p2a));
    }
}

/*pasa todos los elementos de una pila a otra conservando el orden*/
void pasapila2 (Pila* p3a, Pila* p3b)
{
    Pila aux;
    inicpila(&aux);
    while (!pilavacia(p3a))
    {
        apilar(&aux, desapilar(p3a));
    }
    while (!pilavacia(&aux))
    {
        apilar(p3b, desapilar(&aux));
    }
}

/*encuentra el menor elemento de una pila y lo retorne. La misma debe eliminar ese dato de la pila*/
int findmenor (Pila* p4)
{
    Pila aux;
    Pila menor;
    inicpila(&aux);
    inicpila(&menor);

    if (!pilavacia(p4))
    {
        apilar(&menor, desapilar(p4));
    }

    while (!pilavacia(p4))
    {
        if (tope(p4)<tope(&menor))
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(p4));
        }
        else
        {
            apilar(&aux, desapilar(p4));
        }
    }
    while (!pilavacia(&aux))
    {
        apilar(p4, desapilar(&aux));
    }
    int chiquito=tope(&menor);
    return (chiquito);
}

/*pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.*/
void ordenar (Pila* dada, Pila* ordenada)
{
    while (!pilavacia(dada))
    {
      int menor=findmenor(dada);
      apilar(ordenada, menor);
    }
}

/*inserte en una pila ordenada un nuevo elemento, conservando el orden de ésta.*/
void infiltrado(Pila* dada, int nuevo)
{
    Pila aux;
    inicpila(&aux);
    while(tope(dada)< nuevo)
    {
        apilar(&aux, desapilar(dada));
    }
    apilar(dada, nuevo);
    while(!pilavacia(&aux))
    {
        apilar(dada, desapilar(&aux));
    }
}

/*pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada*/
void ordenar2(Pila* dada, Pila* ordenada)
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(dada))
    {
        int top= tope(dada);
        apilar(&aux, desapilar(dada));
        infiltrado(ordenada, top);
    }
}

/*sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido*/
int sumita(Pila dada)
{
    Pila aux;
    inicpila(&aux);
    int cont=0, suma=0;
    while (cont != 2)
    {
        cont++;
        suma=suma+tope(&dada);
        apilar(&aux, desapilar(&dada));
    }
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }
    return suma;
}

int suma(Pila dada)
{
    Pila aux;
    inicpila(&aux);
    int cont=0, suma=0;
    while (!pilavacia(&dada))
    {
        suma=suma+tope(&dada);
        apilar(&aux, desapilar(&dada));
    }
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }
    return suma;
}

/*se cuenta la cantidad de elementos en la pila*/
int cont(Pila dada)
{
    int cont=0;
    Pila aux;
    inicpila(&aux);
    while (!pilavacia(&dada))
    {
        cont=cont+1;
        apilar(&aux, desapilar(&dada));
    }
    return cont;
}

/* divide dos elementos*/
float divi(int diviso, int dividen)
{
    float divisor=diviso;
    float dividendo=dividen;
    float division = (dividendo/divisor);
    return division;
}

/* crea un promedio de los eleementos de una pila*/
float prom(Pila dada)
{
    float sum = (suma(dada));
    float con = cont(dada);
    float prom = divi(con,sum);
    return prom;
}




/*crea un entero con los elementos de una pila*/
/*usamos la cantidad de elementos como potencias de diez*/
int crearnum(Pila dada)
{
    Pila aux;
    inicpila(&aux);
    int con = cont(dada);
    int acum=0;
    while (!pilavacia(&dada))
    {
        int num = desapilar(&dada);
        acum=acum+(num*pow(10, con));
        con=con-1;
    }
    /*como usamos las pontencias hasta el uno, dividimos por diez el resultado*/
    return (acum/10);
}












