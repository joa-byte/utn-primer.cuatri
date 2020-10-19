#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct{
    int ID;
    char nombre[30];
    char Apellido[30];
    char Apodo[30];
    int Edad;
    char Nacionalidad[30];
    char Especialidad[100];
    int HorasVuelAcum;
    int MisionesRealiz;
    int HorasAcumEst;
    char Estado;
    int Lugarastro;
    int enmiss;
}stastronauta;


typedef struct{
    int ID;
    int Tiponave;
    int CantVuelos;
    int HorasVueloAcum;
    int Estado;
    int LugarNave;
    int enmiss;
}stnave;


typedef struct
{
    int ID;
    int IDnave;
    int Estado;
    char Destino[30];
    char Cargamento[30][10];
    int cantcargamento;
    int Tripulantes[30];
    int canttripulantes;
    int lugarmision
}stmision;



///astronautas
//inicializa un arreglo
void inicastro (stastronauta[]);

//informacion
int posAstro (stastronauta[]);
int idposAstro (stastronauta[], int);
int retirado (stastronauta[], int);

//cargar
void cargaAstronauta(stastronauta[],int);
void cargararregloastro (stastronauta[], int);

//mustrar
void muestraAstronauta(stastronauta[],int);
void mustraarreloAstro(stastronauta[],int);

//Cambiar
void cambiarastro(stastronauta[], int id);


///naves
//inicializar
void inicNave (stnave[]);

//información
int posNave (stnave[]);
int idposNave (stnave[], int);
int estadonave (stnave[], int);

//cambios
void cambiarestadonave(stnave[], int, int);
void cambiarnave(stnave naves[], int);
//Carga
void cargaarregloNave(stnave[], int );
void cargaNave(stnave[], int);

//Muestra
void muestraNave(stnave[],int);
void mustraarregloNaves (stnave[]);



///misiones
//inicializar
void inicmiss (stmision[]);

//inromacion
int posmiss (stmision[]);
int idposmiss (stmision[], int);
int estadomiss (stmision[], int);

//Carga
void cargaMision(stmision[],int, stastronauta[], stnave[]);
void cargaarreglomision (stmision[],int, stastronauta[], stnave[]);

//Mustrar
void muestraMision(stmision[], stastronauta[], int);
void muestraarregloMiss(stmision[], stastronauta[]);

//Cambios
void cambiarestadomiss(stmision[],stnave[], stastronauta[], int);
void cambiomision(stmision miss[], int, stastronauta[], stnave[]);









