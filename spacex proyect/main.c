#include <stdio.h>
#include <stdlib.h>
#include "spacex.h"
#define dim 100

void OpcionesAstronautas(stastronauta[]);
void OpcionesNaves(stnave[]);
void OpcionesMisiones(stmision[],stastronauta[],stnave[]);
void estadoAstronauta(stastronauta astro[],int, int);

int main()
{
    int num, rep;
    stastronauta astro[dim];
    inicastro(astro);
    stnave naves[dim];
    inicNave(naves);
    stmision miss[dim];
    inicmiss(miss);

    FILE* astros = fopen("astro.txt","rb");
    FILE* navess = fopen("naves.txt","rb");
    FILE* mision = fopen("mision.txt","rb");

    fread(astro, (sizeof(stastronauta)*dim), 1, astros);
    fread(naves, (sizeof(stnave)*dim), 1, navess);
    fread(miss, (sizeof(stmision)*dim), 1, mision);

    fclose(astros);
    fclose(navess);
    fclose(mision);

    system("COLOR 0A");
    printf("Bienvenido\n");
    system("pause");

    do{
        system("cls");
        printf("Presione:\n");
        printf("1 para Acceder Astronautas\n");
        printf("2 para Acceder Naves\n");
        printf("3 Acceder Mision\n");
        printf("4 para salir\n");
        scanf("%d",&num);

        switch(num)
        {
          case 1:
              system("cls");
              (OpcionesAstronautas(astro));
              rep=1;
          break;

          case 2:
              system("cls");
              (OpcionesNaves(naves));
              rep=1;
          break;

          case 3:
              system("cls");
              OpcionesMisiones(miss,astro,naves);
              rep=1;
          break;

          case 4:
          rep=0;
          break;

          default:
              (printf("Ingrese una opcion valida\n"));
              system("pause");
              system("cls");
              rep=1;
        }
    }while(rep==1);

    astros = fopen("astro.txt","wb");
    navess = fopen("naves.txt","wb");
    mision = fopen("mision.txt","wb");

    fwrite(astro, (sizeof(stastronauta)*dim), 1, astros);
    fwrite(naves, (sizeof(stnave)*dim), 1, navess);
    fwrite(miss, (sizeof(stmision)*dim), 1, mision);

    fclose(astros);
    fclose(navess);
    fclose(mision);

    return 0;
}

void OpcionesAstronautas(stastronauta astro[])
{
    int num=0, ID=0, pos=0, validos=0,estado=0, rep=0;

    do{

        printf("Presione:\n");

        printf("1 para Cargar Astronautas\n");
        printf("2 para dar de Alta un Astronauta\n");
        printf("3 para dar de Baja un Astronauta\n");
        printf("4 para consultar un Astronauta\n");
        printf("5 para mostrar todos los Astronautas\n");
        printf("6 para Modificar un astronauta\n");
        printf("7 para salir\n");

        scanf("%d",&num);

        validos=(posAstro(astro));

        switch(num)
        {

            case 1:
                system("cls");
                cargararregloastro(astro,validos);
                system("cls");
                rep=1;
            break;

            case 2:
                printf("Ingrese el ID: ");
                scanf("%d",&ID);
                estadoAstronauta(astro,ID,0);
                system("pause");
                system("cls");
                rep=1;
            break;

            case 3:
                printf("Ingrese el ID: ");
                scanf("%d",&ID);
                estadoAstronauta(astro,ID,1);
                system("pause");
                system("cls");
                rep=1;
            break;

            case 4:
                (printf("Ingrese el ID: "));
                scanf("%d",&ID);

                pos=idposAstro(astro,ID);
                if(pos!=-1)
                {
                    muestraAstronauta(astro,pos);
                }
                else
                {
                    printf("Esa ID no existe");
                }
                system("pause");
                system("cls");

                rep=1;
            break;

            case 5:
                validos=posAstro(astro);
                mustraarreloAstro(astro,validos);
                rep=1;
                system("pause");
                system("cls");
                break;

            case 6:
                (printf("Ingrese el ID: "));
                scanf("%d",&ID);

                pos=idposAstro(astro,ID);
                if(pos!=-1)
                {
                    cambiarastro(astro, ID);
                }
                else
                {
                    printf("Esa ID no existe");
                }
                rep=1;
                system("pause");
                system("cls");
                break;

            case 7:
                rep=0;
                break;

            default:
                (printf("Vuelva a Ingresar su opcion\n"));
                rep=1;
                system("pause");
                system("cls");
        }
    } while(rep==1);
}

void estadoAstronauta(stastronauta astro[], int ID, int estado)
{
    int retira2= retirado(astro,ID);
    int pos= idposAstro(astro,ID);
    if (astro[pos].enmiss==1)
    {
        printf("no podes cambiar el estado de un astronauta en mision");
    }
    else
    {
        if(estado==1 && retira2 ==0)
        {
            astro[pos].Estado='r';
            printf("El astronauta se ha retirado con exito!\n");
        }

        else if(estado==0&&retira2==1)
        {
            astro[pos].Estado='a';
            printf("El astronauta esta activo de nuevo!\n");
        }
        else
        {
            printf("Esta accion no puede realizarse ");
        }
    }
}


void OpcionesNaves(stnave naves[])
{
    int num=0, ID=0, pos=0, validos=0,estado=0, rep=0;

    do{
        validos=posNave(naves);
        printf("Presione:\n");
        printf("1 para Cargar Nave\n");
        printf("2 para dar de Alta una Nave\n");
        printf("3 para dar de Baja una Nave\n");
        printf("4 para consultar una Nave\n");
        printf("5 para mostrar todas las Naves\n");
        printf("6 para modificar una nave\n");
        printf("7 para salir\n");

        scanf("%d",&num);

        validos=(posNave(naves));

            switch(num)
            {

                case 1:
                    system("cls");
                    cargaarregloNave(naves,validos);
                    system("cls");
                    rep=1;
                break;

                case 2:
                    printf("Ingrese el ID: ");
                    scanf("%d",&ID);
                    pos=idposNave(naves, ID);
                    naves[pos].Estado=1;
                    printf("La nave fue actualizada a lista con exito!");
                    system("pause");
                    system("cls");
                    rep=1;
                break;

                case 3:
                    printf("Ingrese el ID: ");
                    scanf("%d",&ID);
                    pos=idposNave(naves, ID);
                    naves[pos].Estado=3;
                    printf("la nave a sido dada de baja");
                    system("pause");
                    system("cls");
                    rep=1;
                break;

                case 4:
                    (printf("Ingrese el ID: "));
                    scanf("%d",&ID);

                    pos=idposNave(naves,ID);
                    if(pos!=-1)
                    {
                        muestraNave(naves,pos);
                    }
                else
                    {
                        printf("Esa ID no existe");
                    }
                     system("pause");
                    system("cls");
                    rep=1;
                break;

                case 5:
                    mustraarregloNaves(naves);
                    system("pause");
                    system("cls");
                    rep=1;
                    break;
                case 6:
                    printf("Ingrese ID: ");
                    scanf("%i", &ID);
                    cambiarnave(naves, ID);
                    rep=1;
                    system("pause");
                    system("cls");
                break;

                case 7:
                    rep=0;
                    system("pause");
                break;

                default:
                    (printf("Vuelva a Ingresar su opcion\n"));
                    rep=1;
                    system("pause");
                    system("cls");
            }
    }while(rep==1);
}

void OpcionesMisiones(stmision miss[],stastronauta astro[],stnave naves[])
{
    int num=0, ID=0, pos=0, validos=0,estado=0, rep=0;
    do
    {
        printf("Presione:\n");

        printf("1 para Cargar Mision\n");
        printf("2 para dar de Alta una Mision\n");
        printf("3 para dar de Baja una Mision\n");
        printf("4 para consultar una Mision\n");
        printf("5 para mostrar todas las Misiones\n");
        printf("6 para modificar una mision\n");
        printf("7 para salir\n");

        scanf("%d",&num);

        validos=posmiss(miss);

        switch(num)
        {

            case 1:
                cargaarreglomision(miss,validos,astro,naves);
                system("cls");
                rep=1;
            break;

            case 2:
                printf("Ingrese el ID: ");
                scanf("%d",&ID);
                pos=idposmiss(miss, ID);
                if (miss[pos].Estado==1)
                {
                    miss[pos].Estado=2;
                    printf("Suerte con su mision!");
                }
                else
                {
                    printf("Solo pueden ponerse \"En vuelo\" misiones listas");
                }
                system("pause");
                system("cls");
                rep=1;
            break;

            case 3:
                printf("Ingrese el ID: ");
                scanf("%d",&ID);
                pos=idposmiss(miss, ID);
                if (miss[pos].Estado==1)
                {
                    miss[pos].Estado=4;
                    printf("La misión fue actualizada a \"cancelada\"");
                }
                else
                {
                    printf("Solo pueden cancelarse misiones listas");
                }
                system("pause");
                system("cls");
                rep=1;
            break;

            case 4:
                printf("Ingrese el ID: ");
                scanf("%d",&ID);
                pos=idposmiss(miss,ID);
                if(pos!=-1)
                {
                    muestraMision(miss,astro,pos);
                }
                else
                {
                    printf("Esa ID no existe");
                }
                system("pause");
                system("cls");
                rep=1;
            break;

            case 5:
                muestraarregloMiss(miss, astro);
                system("pause");
                system("cls");
                rep=1;
            break;

            case 6:
                printf("Ingrese el ID: ");
                scanf("%d",&ID);
                pos=idposmiss(miss,ID);
                if(pos!=-1)
                {
                    cambiomision(miss, ID, astro, naves);
                }
                else
                {
                    printf("Esa ID no existe");
                }
                    rep=1;
                    system("pause");
                    system("cls");
            break;

            case 7:
                    rep=0;
                    system("pause");
            break;

            default:
                (printf("Vuelva a Ingresar su opcion\n"));
                system("pause");
                system("cls");
                rep=1;
        }
    }while(rep==1);
}
