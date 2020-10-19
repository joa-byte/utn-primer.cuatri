#include <stdio.h>
#include <stdlib.h>
#define cantalumnos 30

typedef struct {
int matricula;
char nombre[30];
char genero; //m, f, o
} stAlumno;

int cargaralumnos (stAlumno[]);
void mostraralumno (stAlumno[], int);
void mostrarall(stAlumno[], int);
int mostrarxmatricula(stAlumno[], int, int);
int mayormatri (stAlumno[], int);
void ordenarxmatri (stAlumno[], int);
int mostrarxgenero (stAlumno[], int, char);


int main()
{
    stAlumno dado[cantalumnos];
    int validos = cargaralumnos(dado);
    ordenarxmatri(dado, validos);
    mostrarxgenero(dado, validos, 'o');
    return 0;
}

/*cargue un arreglo de alumnos, hasta que el usuario lo decida.*/
int cargaralumnos(stAlumno dado[])
{
    char opc = 's';
    int i = 0;

    while (opc == 's')
    {
        printf("matricula del alumno: ");
        scanf("%i", &dado[i].matricula);

        printf("nombre del alumno: ");
        fflush(stdin);
        scanf("%s", &dado[i].nombre);

        printf("genero del alumno: (m/f/o)");
        fflush(stdin);
        scanf("%c", &dado[i].genero);

        printf("deses seguir ingresando alumnos? (s/n)");
        fflush(stdin);
        scanf("%c", &opc);

        i++;

        printf("\n");

        if (i== (cantalumnos))
        {
            opc='n';
        }
    }

    return i;
}

/*función que muestre un alumno por pantalla.*/
void mostraralumno (stAlumno dado[], int alumno)
{
    printf("matricula: %i \n", dado[alumno].matricula);
    printf("nombre: %s \n", dado[alumno].nombre);
    printf("genero: %c \n", dado[alumno].genero);
}

/*función que muestre un arreglo de alumnos por pantalla.*/
void mostrarall(stAlumno dado[], int validos)
{
    int i;
    for(i=0;i<validos;i++)
    {
        mostraralumno(dado, i);
        printf("\n");
    }
}

/*busca a un alumno por matricula y si existe en el arreglo lo muestra*/
int mostrarxmatricula (stAlumno dado[], int validos, int matri)
{
    int i=0, x=0;//x = 1 quiere decir que la matricula existe
    while (i<validos && x==0)
    {
        if (dado[i].matricula==matri)
        {
            mostraralumno(dado, i);
            x=1;
        }
        else
        {
         i++;
        }
    }
    return x;
}

/*busca la matricula mas alta de un arreglo*/
int mayormatri (stAlumno dado[], int validos)
{
    int matri=dado[0].matricula;
    int i=0, posmay=0;
    while (i<validos)
    {
     if (dado[i].matricula>matri)
     {
         matri=dado[i].matricula;
         posmay=i;
     }
     i++;
    }
    return posmay;//devuelve su posición
}


/*ordena un arreglo de alumnos por matricula*/
void ordenarxmatri (stAlumno dado[], int validos)
{
    stAlumno aux;
    int i=0, ii=validos, pos;
    while (i<validos)
    {
        pos = mayormatri(dado, ii);

        ii--;

        aux=dado[ii];
        dado[ii]=dado[pos];
        dado[pos]=aux;

        i++;
    }
}

/*mustra a las personas de un genero indicado y devuelve cuantas son**/
int mostrarxgenero (stAlumno dado[], int validos, char gene)
{
    int i=0, x=0;
    while (i<validos)
    {
        if (dado[i].genero==gene)
        {
            mostraralumno(dado, i);
            printf("\n");
            x++;//x = la cantidad de alumnos de este genero en el arreglo
        }
        i++;
    }
    return x;
}













