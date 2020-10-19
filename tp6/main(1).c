#include <stdio.h>
#include <stdlib.h>
#define cantalumnos 30

typedef struct {
int matricula;
char nombre[30];
char genero; //m, f, o
} stAlumno;

int cargaralumnos (stAlumno[], int);
void mostraralumno (stAlumno[], int);
void mostrarall(stAlumno[], int);
int mostrarxmatricula(stAlumno[], int, int);
int mayormatri (stAlumno[], int);
void ordenarxmatri (stAlumno[], int);
void mostrarxgenero (stAlumno[], int, char);
int cantidadxgenero (stAlumno[], int, char);
void opcionesdemostrar(stAlumno[], int);

int main()
{
    stAlumno dado[cantalumnos];
    int opc=0;
    int validos = cargaralumnos(dado, 0);
    do
    {
        system("cls");
        printf("que desea hacer con el listado de alumnos?");
        printf("\n0: salir");
        printf("\n1: ver alumnos");
        printf("\n2: ordenarlo");
        printf("\n3: ingresar un nuevo alumno\n");
        scanf("%i", &opc);
        switch (opc)
        {
            case 1:
                opcionesdemostrar(dado, validos);
                opc=1;
            break;
            case 2:
                ordenarxmatri(dado, validos);
            break;
            case 3:
                validos = cargaralumnos(dado, validos);
            break;
        }
    }while(opc!=0);

}

/*cargue un arreglo de alumnos, hasta que el usuario lo decida.*/
int cargaralumnos(stAlumno dado[], int inicio)
{
    char opc = 's';
    int i = inicio;

    while (opc == 's')
    {
        printf("matricula del alumno: ");
        scanf("%i", &dado[i].matricula);

        printf("nombre del alumno: ");
        fflush(stdin);
        scanf("%s", &dado[i].nombre);

        do{
        printf("genero del alumno: (m/f/o)");
        fflush(stdin);
        scanf("%c", &dado[i].genero);
        } while (dado[i].genero != 'm' && dado[i].genero != 'f' && dado[i].genero != 'o');

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

/*mustra a las personas de un genero indicado*/
void mostrarxgenero (stAlumno dado[], int validos, char gene)
{
    int i=0;
    while (i<validos)
    {
        if (dado[i].genero==gene)
        {
            mostraralumno(dado, i);
            printf("\n");
        }
        i++;
    }
}

/*devuelve cuantas personas son de un genero indicado*/
int cantidadxgenero (stAlumno dado[], int validos, char gene)
{
    int i=0, x=0;
    while (i<validos)
    {
        if (dado[i].genero==gene)
        {
            x++;//x = la cantidad de alumnos de este genero en el arreglo
        }
        i++;
    }
    return x;
}


void opcionesdemostrar(stAlumno dado[], int validos)
{
    int opc=0, matri=0, existe=0;
    char gen;
    system("cls");
    printf("desea:");
    printf("\n0: salir");
    printf("\n1: ver todos los alumnos");
    printf("\n2: ver alumnos de un genero especifico");
    printf("\n3: ver a un alumno por su matricula\n");
    scanf("%i", &opc);
    switch (opc)
        {
            case 1:
                mostrarall(dado, validos);
                system("pause");
                break;
            case 2:
                printf("\nque genero desea ver?");
                do{
                fflush(stdin);
                scanf("%c", &gen);
                } while (gen != 'm' && gen != 'f' && gen != 'o');
                mostrarxgenero(dado, validos, gen);
                system("pause");
                break;
            case 3:
                do{
                    printf("\nque matricula busca?");
                    scanf("%i", &matri);
                    existe=mostrarxmatricula(dado, validos, matri);
                    if (existe=0)
                        {
                            printf("\nesta matricula no existe");
                        }
                    }while(existe==0);
                break;
        }

}








