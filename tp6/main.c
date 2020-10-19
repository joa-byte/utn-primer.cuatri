#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define al 2
#define an 10

void cargar(int [al][an]);
void cargaale(int [al][an]);
void cargaale2x2(int [2][2]);
int cargarstring(char [5][20]);

void mostrarm (int [al][an]);
void mostrarm2x2 (int [2][2]);
void mostrarf2x2 (float [2][2]);
void mostrarpalabra (char [5][20], int);

float prom (int [al][an]);

int wallie (int [al][an], int);
int walliestring (char [5][20], int, char[20]);

int maxposstring (char [5][20], int);
void ordenarstring(char[5][20], int);

int determinante (int [2][2]);
int inversa (int [2][2]);

void multiplicar (int [2][2], int [2][10], int [2][10]);
void inversa2(int[2][2], float[2][2]);

int main()
{
    int dada [2][2];
    cargaale2x2(dada);
    mostrarm2x2(dada);
    printf("\n");
    float result[2][2];
    inversa2(dada, result);
    mostrarf2x2(result);
    return 0;
}


/*cargar la matriz por completo.*/
void cargar(int dada[al][an])
{
    int alt=0,anc=0;
    for (alt=0;alt<al;alt++)
    {
        for (anc=0;anc<an;anc++)
        {
            printf("ingrese un valor para la posicion %i, %i: ", alt, anc);
            scanf("%i", &dada [alt][anc]);
        }
    }
}

/*cargar la matriz con palabras.*/
int cargarstring(char dada[5][20])
{
    int alt=0;
    char opc= 's';
    while (alt<5 && opc=='s')
    {
            printf("\ningrese el nombre %i: ", alt);
            scanf("%s", &dada [alt]);
            printf("\ndesea ingresar otro nombre?");
            fflush(stdin);
            scanf("%c", &opc);
            alt++;
    }
    return alt;
}

/*muestre la matriz en formato matricial*/
void mostrarm (int dada [al][an])
{
    int alt=0,anc=0;
    for (alt=0;alt<al;alt++)
    {
        for (anc=0;anc<an;anc++)
        {
            printf("[%i]", dada [alt] [anc]);
        }
        printf("\n");
    }
}

/*muestre la matriz de palabras*/
void mostrarpalabra (char dada [5][20], int cant)
{
    int alt=0;
    for (alt=0; alt<cant; alt++)
    {
        printf("%s", dada [alt]);
        printf("\n");
    }
}

/*muestre la matriz de 2x2 en formato matricial*/
void mostrarm2x2 (int dada [2][2])
{
    int alt=0,anc=0;
    for (alt=0;alt<2;alt++)
    {
        for (anc=0;anc<2;anc++)
        {
            printf("[%i]", dada [alt] [anc]);
        }
        printf("\n");
    }
}

void mostrarf2x2 (float dada [2][2])
{
    int alt=0,anc=0;
    for (alt=0;alt<2;alt++)
    {
        for (anc=0;anc<2;anc++)
        {
            printf("[%.2f]", dada [alt] [anc]);
        }
        printf("\n");
    }
}

/*cargar la matriz por completo con numeros aleatorios.*/
void cargaale(int dada[al][an])
{
    int alt=0,anc=0;
    for (alt=0;alt<al;alt++)
    {
        for (anc=0;anc<an;anc++)
        {
            dada [alt][anc]=rand()%10;
        }
    }
}

/*cargar la matriz de 2x2 por completo con numeros aleatorios.*/
void cargaale2x2(int dada[2][2])
{
    int alt=0,anc=0;
    for (alt=0;alt<2;alt++)
    {
        for (anc=0;anc<2;anc++)
        {
            dada [alt][anc]=rand()%10;
        }
    }
}

/*sume el contenido total de una matriz*/
int suma (int dada[al][an])
{
    int alt=0,anc=0, acum=0;
    for (alt=0;alt<al;alt++)
    {
        for (anc=0;anc<an;anc++)
        {
            acum+=dada [alt][anc];
        }
    }
    return acum;
}

/*calcule el promedio de una matriz de números enteros*/
float prom (int dada[al][an])
{
    float cant=(al*an);
    float sum=suma(dada);
    float prome=(sum/cant);
    return prome;
}


/*determine si un elemento se encuentra dentro de una matriz*/
int wallie (int dada[al][an], int busca)
{
    int alt=0,anc=0,esta=0;
    for (alt=0;alt<al;alt++)
    {
        for (anc=0;anc<an;anc++)
        {
            if (busca==dada [alt][anc])
            {
                esta=1;
            }
        }
    }
    return esta;
}

/*determine si una palabra se encuentra dentro de un arreglo de
palabras*/
int walliestring (char dada[5][20],int palabras, char dado[20])
{
    int alt=0,busca=0;
    for (alt=0;alt<palabras;alt++)
    {
     int busca2=strcmp(dada[alt], dado);
     if (busca2==0)
     {
         busca=1;
     }
    }
    return busca;
}


/* retorne el determinante de una matriz de 2x2. */
int determinante (int dada [2][2])
{
    int diag1= (dada[0][0]*dada[1][1]);
    int diag2= (dada[0][1]*dada[1][0]);
    int determ= (diag1-diag2);
    return determ;
}



/*verifique si una matriz de 2x2 tiene inversa.*/
int inversa (int dada [2][2])
{
    int valido=0;
    if ((dada[0][0] == dada[1][0] && dada[0][1]==dada[1][1])||(dada[0][0] == dada[0][1] && dada[1][0]==dada[1][1]))
    {
        valido=1;
    }
    return valido;
}

/*multiplique una matriz de 2x2 por una matriz de 2x10.*/
void multiplicar (int dada[2][2], int dada2[2][10], int resultado[2][10])
{
    int alt=0,anc=0;
    for (alt=0;alt<2;alt++)
    {
        for (anc=0;anc<10;anc++)
        {
            resultado[alt][anc]= (dada[alt][0]*dada2[0][anc]+ dada[alt][1]*dada2[1][anc]);
        }
    }
}

/*encuentre la mayor palabra*/
int maxposstring (char dada[5][20], int palabras)
{
    int pos1=0, pos2=0, posmax=0;
    for (pos1=0;pos1<palabras;pos1++)
    {
        int comp = stricmp(dada[posmax], dada [pos1]);
        if (comp<0)
        {
            posmax=pos1;
        }
    }
    return posmax;
}

/*ordene un arreglo de palabras por orden alfabético.*/
void ordenarstring(char dada[5][20], int palabras)
{
    int alt=palabras;
    int pos=0;
    char aux[20];
    while(alt>0)
    {
        alt--;
        pos = maxposstring(dada, alt);
        strcpy(aux, dada[alt]);
        strcpy(dada[alt], dada[pos]);
        strcpy(dada[pos], aux);
    }
}


/*inversa de una matriz de 2x2*/
void inversa2(int dada[2][2], float result[2][2])
{
    int alt=0, anc=0, aux= dada[1][1];
    float aux2=0;
    float deter= determinante(dada);

    dada[1][1]= dada[0][0];
    dada[0][0]=aux;
    dada[0][1]=(dada[0][1]*(-1));
    dada[1][0]=(dada[1][0]*(-1));

    for (anc=0;anc<2;anc++)
    {
        for (alt=0;alt<2;alt++)
        {
            aux2 = dada[alt][anc];
            result[alt][anc] = (aux2/deter);
        }
    }
}

















