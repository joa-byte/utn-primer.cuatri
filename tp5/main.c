#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*cargan arreglos*/
int cargaarreglo (int[]);
int cargaarreglo2 (float[]);
int cargaarreglo3(char[]);

/*muestran arreglos*/
void mostrararreglo (int[], int);
void mostrararreglochar(char [], int);

/* cambios*/
void invertir(int [], int);

/*arreglo a pila*/
void arregloapila (Pila*, int[], int);

/*informacion sobre arreglos*/
int wallie (int [], int, int);
int capicua (int [],int);
int sumararreglo (int[], int);
float sumararreglo2(float [], int);

/*inicio de ordenacion*/
int insertarletra (char[], int, char);
int maxcar (char [], int);

/*ordenaciones*/
void insercion (char[],int);
void seleccion (char[],int);
int crear (char[],int,char[],int,char[]);

int main()
{
    char dado[20];
    int validos= cargaarreglo3(dado);
    char dado2[20];
    int validos2= cargaarreglo3(dado2);
    char nuevo[40];
    int validos3= crear(dado, validos, dado2, validos2, nuevo);
    mostrararreglochar(nuevo, validos3);

    return 0;
}


///permita que el usuario ingrese valores al mismo por teclado
int cargaarreglo(int dado [])
{
    char opc='s';
    int validos=0;
    int num;

    while (opc=='s' && validos<20)
    {
        printf("ingrese el numero %i: ", validos);
        scanf("%i", &num);
        dado[validos]=num;
        validos++;
        if (validos<20)
        {
        printf("desea otro elemento?");
        fflush(stdin);
        scanf("%c", &opc);
        }
    }
    return validos;
}


///muestre por pantalla  los  elementos de un arreglo.
void mostrararreglo(int dado [], int validos)
{
    int cont=0;
    while (cont<validos)
    {
        printf("\nel elemento %i es: %i\n", cont, dado[cont]);
        cont++;
    }
}

///calcule la suma de sus elementos.
int sumararreglo(int dado [], int validos)
{
    int acum=0, cont=0;
    while (cont<validos)
    {
        acum+=dado[cont];
        cont++;
    }
    return acum;
}


///La función debe copiar los elementos del arreglo en la pila.
void arregloapila(Pila* dada, int dado[], int validos)
{
    int cont=0;
    while (cont<validos)
    {
        apilar(dada, dado[cont]);
        cont++;
    }
}


///permita que el usuario ingrese valores al mismo por teclado
int cargaarreglo2(float dado [])
{
    char opc='s';
    int validos=0;
    float num;

    while (opc=='s' && validos<100)
    {
        printf("ingrese el numero %i: ", validos);
        scanf("%f", &num);
        dado[validos]=num;
        validos++;
        if (validos<100)
        {
        printf("desea otro elemento?");
        fflush(stdin);
        scanf("%c", &opc);
        }
    }
    return validos;
}


float sumararreglo2(float dado [], int validos)
{
    int cont=0;
    float acum=0;
    while (cont<validos)
    {
        acum+=dado[cont];
        cont++;
    }
    return acum;
}

///indique si un elemento dado se encuentra en un arreglo de caracteres.
int wallie(int dado[],int validos, int busca)
{
    int cont=0, rta=0;
    while (cont<validos)
    {
        if (busca == dado[cont])
        {
            rta=1;
        }
        cont++;
    }
    return rta;
}

///permita que el usuario ingrese valores al mismo por teclado
int cargaarreglo3(char dado [])
{
    char opc='s';
    int validos=0;
    char car;

    while (opc=='s' && validos<20)
    {
        printf("ingrese el caracter %i: ", validos);
        fflush(stdin);
        scanf("%c", &car);
        dado[validos]=car;
        validos++;
        if (validos<20)
        {
        printf("desea otro elemento?");
        fflush(stdin);
        scanf("%c", &opc);
        }
    }
    return validos;
}


///muestre por pantalla  los  elementos de un arreglo.
void mostrararreglochar(char dado [], int validos)
{
    int cont=0;
    while (cont<validos)
    {
        printf("\nel elemento %i es: %c\n", cont, dado[cont]);
        cont++;
    }
}


int insertarletra(char dado[], int validos, char nuevo)
{
    int i = validos;
    while (i>0 && nuevo<dado[i-1])
    {
        dado[i]=dado[i-1];
        i--;
    }
    dado[i]=nuevo;
    return validos+1;
}


///Realizar una función que obtenga el máximo carácter de un arreglo dado.
int maxcar (char dado[], int validos)
{
    int i = validos, maxpos = validos;
    while (i != 0)
    {
        if (dado[i]>dado[maxpos])
          {
              maxpos=i;
          }
        i--;
    }
    return maxpos;
}


///Realizar una función que determine si un arreglo es capicúa.
int capicua(int dado[], int validos)
{
    int i=0, ii=validos-1;
    while (dado[i]==dado[ii])
    {
        i++;
        ii--;
    }
    int capi=0;
    if (i==validos)
    {
        capi=1;
    }
    return capi;
}


///Realizar una función que invierta los elementos de un arreglo.
void invertir(int dado[], int validos)
{
    int aux[validos];
    int i=validos, ii=0;
    while (i>0)
    {
        aux[i]=dado[i-1];
        i--;
    }
    i=validos;
    while (i>0)
    {
        dado[ii]=aux[i];
        i--;
        ii++;
    }
}

void insercion (char dado[],int validos)
{
    int i=0;
    while(i<validos)
    {
        insertarletra(dado, i, dado[i]);
        i++;
    }
}


void seleccion (char dado[],int validos)
{
    int ii=validos, aux2;
    char aux;
    while (ii>0)
    {
        ii--;
        aux2=maxcar(dado, ii);
        aux=dado[aux2];
        dado[aux2]=dado[ii];
        dado[ii]=aux;
    }
}

int crear (char dado[], int valido, char dado2[], int valido2, char nuevo[])
{
    int i=0;
    int i1=(0);
    int i2=(0);
    int i3=(0);
    while(i<(valido+valido2))
    {
        if (dado[i1]<dado2[i2] && i1<valido)
        {
            nuevo[i3]=dado[i1];
            i1++;
        }
        else if (i2<valido2)
        {
            nuevo[i3]=dado2[i2];
            i2++;
        }
        i3++;
        i++;
    }
    return (valido2+valido);
}




















