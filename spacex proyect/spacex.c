
#include "spacex.h"

#define dim 100

//inicializa las posiciones de un arreglo de astronauta. es necesario que se ulice cada vez que se genera un nuevo arreglo de astronautas
void inicastro (stastronauta astro[])
{
    int i;

    for (i=0;i<dim;i++)
    {
        if (i==0)
        {
            astro[i].Lugarastro=-1;
        }
        else
        {
            astro[i].Lugarastro=0;
        }
    }
}

//retorna la cantidad de astronautas cargados ("los validos")
int posAstro (stastronauta astro[])
{
    int i=0;

    while (i == astro[i].Lugarastro)
    {
        i++;
    }
    return i;
}

//carga un astronauta a un arreglo
void cargaAstronauta(stastronauta astro[], int pos)
{
    int i=pos, aux=0;

    system("COLOR 0A");

    if (i<dim)
        {
        do
            {
            printf("ingrese ID: ");
            scanf("%d",&aux);

            if(idposAstro(astro, aux)!= -1)
            {
                printf("\nesta id ya existe, por favor ingrese una distinta\n");
            }
        } while (idposAstro(astro, aux)!= -1);
        astro[i].ID=aux;



        printf("ingrese nombre: ");
        fflush(stdin);
        scanf("%s",&astro[i].nombre);

        printf("ingrese apellido: ");
        fflush(stdin);
        scanf("%s",&astro[i].Apellido);

        printf("ingrese apodo: ");
        fflush(stdin);
        scanf("%s",&astro[i].Apodo);

        do
        {
            printf("Ingrese edad: ");
            scanf("%d",&astro[i].Edad);
            if (astro[i].Edad<18)
            {
                printf("Debe ser mayor de edad\n");
            }
        }while(astro[i].Edad<18);

        printf("Ingrese nacionalidad: ");
        fflush(stdin);
        scanf("%s",&astro[i].Nacionalidad);

        do
        {
            printf("Ingrese Estado(r/a): ");
            fflush(stdin);
            scanf("%c",&astro[i].Estado);
        } while (astro[i].Estado!='r' && astro[i].Estado!='a');

        printf("Ingrese especialidad: ");
        fflush(stdin);
        scanf("%s",&astro[i].Especialidad);

        do
        {
            printf("Ingrese horas de vuelo: ");
            scanf("%d",&astro[i].HorasVuelAcum);
            if (astro[i].HorasVuelAcum<0)
            {
                printf("ingrese horas positivas\n");
            }
        }while(astro[i].HorasVuelAcum<0);

        do
        {
            printf("Ingrese numero de misiones realizadas: ");
            scanf("%d",&astro[i].MisionesRealiz);
            if (astro[i].MisionesRealiz<0)
            {
                printf("ingrese misiones positivas\n");
            }
        }while(astro[i].MisionesRealiz<0);

        do{
            printf("Ingrese Horas en Estacion acumuladas: ");
            scanf("%d",&astro[i].HorasAcumEst);
            if (astro[i].HorasAcumEst<0)
            {
                printf("ingrese horas positivas\n");
            }
        }while(astro[i].HorasAcumEst<0);


        astro[i].Lugarastro=i;

        i++;
        }
        else
        {
            printf("ya alcanzaste el limite de astronautas permitidos");
        }
    astro[i].enmiss=0;
    }

//carga un arreglo de astronautas hasta donde el usuario desee
void cargararregloastro (stastronauta astro[], int pos)
{
    char opc='s';
    int i = pos;

system("COLOR 0A");

    while (opc=='s' && i<dim)
    {
        cargaAstronauta(astro, i);

        printf("¿desea ingresar otro astronauta? (s/n)");
        fflush(stdin);
        scanf("%c", &opc);

        if (opc=='s' && i<dim)
        {
           system("cls");
        }

        i++;
    }
}

//muestra un astronauta
void muestraAstronauta(stastronauta astro[],int pos)
{
    int i=pos;

    system("COLOR 0A");

    printf("ID Astronauta: ");
    printf("%d",astro[i].ID);
    printf("-----\n");

    printf("Nombre Astronauta: ");
    printf("%s",astro[i].nombre);
    printf("-----\n");

    printf("Apellido Astronauta: ");
    printf("%s",astro[i].Apellido);
    printf("-----\n");

    printf("Apodo Astronauta: ");
    printf("%s",astro[i].Apodo);
    printf("-----\n");

    printf("Edad Astronauta: ");
    printf("%d",astro[i].Edad);
    printf("-----\n");

    printf("Nacionalidad Astronauta: ");
    printf("%s",&astro[i].Nacionalidad);
    printf("-----\n");

    printf("Estado de Astronauta: ");
    printf("%c",astro[i].Estado);
    printf("-----\n");

    printf("Especialidad de Astronauta: ");
    printf("%s",astro[i].Especialidad);
    printf("-----\n");

    printf("Horas Acumuldas Estacion: ");
    printf("%d",astro[i].HorasAcumEst);
    printf("-----\n");

    printf("Horas vuelo Astronauta: ");
    printf("%d",astro[i].HorasVuelAcum);
    printf("-----\n");
}
//cambia un atributo del astronauta
void cambiarastro(stastronauta astro[], int id)
{
    int num, rep=0;
    int i=idposAstro(astro, id);
    system("color 0A");

    printf("Presione:\n");

    printf("1 para Cambiar Nombre\n");
    printf("2 para Cambiar Apellido\n");
    printf("3 para dar Cambiar Apodo\n");
    printf("4 para cambiar Edad\n");
    printf("5 para cambiar  Nacionalidad\n");
    printf("6 para actualizar Especialidad\n");
    printf("7 para actualizar Horas de Vuelo\n");
    printf("8 para actualizar Misiones realizadas\n");
    printf("9 para salir\n");

    scanf("%d",&num);



    switch(num)
    {

     case 1:
        printf("Ingrese nuevo nombre: ");
        fflush(stdin);
        scanf("%s",&astro[i].nombre);
        rep=1;
    break;

     case 2:
        printf("Ingrese nuevo apellido: ");
        fflush(stdin);
        scanf("%s",&astro[i].Apellido);
        rep=1;
    break;

    case 3:
        printf("Ingrese nuevo apodo: ");
        fflush(stdin);
        scanf("%s",&astro[i].Apodo);
        rep=1;
    break;

    case 4:
        printf("Ingrese nueva edad: ");
        scanf("%d",&astro[i].Edad);
        rep=1;
    break;

    case 5:
        printf("Ingrese nueva nacionalidad: ");
        fflush(stdin);
        scanf("%s",&astro[i].Nacionalidad);
        rep=1;
    break;

    case 6:
        printf("Ingrese nueva especialidad: ");
        fflush(stdin);
        scanf("%s",&astro[i].Especialidad);
            rep=1;
    break;

    case 7:
        printf("Ingrese nuevas horas de vuelo: ");
        scanf("%d",&astro[i].HorasVuelAcum);
           rep=1;
    break;

    case 8:
        printf("Ingrese nuevo numero de misiones realizadas: ");
        scanf("%d",&astro[i].MisionesRealiz);
        rep=1;
    break;

    case 9:
        system("cls");
        rep=0;
    break;
    default:
        (printf("Ingrese una opcion valida\n"));
        system("pause");
        system("cls");
        rep=1;
    }
}

//muestra un arreglo entero de astronautas
void mustraarreloAstro (stastronauta astro[],int validos)
{
    int i=0;

    for(i=0;i<validos;i++)
    {
        muestraAstronauta(astro, i);
        printf("\n");
    }
}

// se ingresa una id, se devuelve la posicion del astronauta al que pertenece, devuelve -1 si no existe
int idposAstro (stastronauta astro[], int id)
{
    int validos = posAstro(astro);
    int pos = -1, i = 0;
    while (i<validos)
    {
        if (astro[i].ID==id)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

//retorna 1 si el astronauta esta retirado, 0 si no
int retirado (stastronauta astro[], int id)
{
    int validos= posAstro(astro);
    int pos = idposAstro(astro, id);
    int retira2 = 1;
    if (astro[pos].Estado=='a')
    {
        retira2=0;
    }
    return retira2;
}

//información sobre arreglo de Naves
void inicNave (stnave naves[])
{
    int i;

    for (i=0;i<dim;i++)
    {
        if (i==0)
        {
            naves[i].LugarNave=1;
        }
        else
        {
            naves[i].LugarNave=0;
        }
    }
}

//Retorna Validos de Naves
int posNave (stnave naves[])
{
    int i=0;

    while (i == naves[i].LugarNave)
    {
        i++;
    }
    return i;
}

//devuelve a posicion de una nave usando como paramtro su id
int idposNave (stnave naves[], int id)
{
    int validos=(posNave(naves));
    int pos = -1, i = 0;
    while (i<validos)
    {
        if (naves[i].ID==id)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

//retorna el estado de una nave enviada por parametro
int estadonave (stnave naves[], int id)
{
    int pos = idposNave(naves, id);

    return naves[pos].Estado;
}

//cambia el estado
void cambiarestadonave(stnave naves[], int id, int nuevoestado)
{
    int pos = idposNave(naves, id);
    naves[pos].Estado=nuevoestado;
}

//Carga una Naves
void cargaNave(stnave naves[], int pos)
{
    system("COLOR 0A");
    int i=pos, aux=0;

    if (i<dim)
        {
        do
            {
            printf("ingrese ID: ");
            scanf("%d",&aux);

            if(idposNave(naves, aux)!= -1)
            {
                printf("\nesta id ya existe, por favor ingrese una distinta\n");
            }
        } while (idposNave(naves, aux)!= -1);
        naves[i].ID=aux;

        do
        {
            printf("Ingrese tipo de nave: 1. Starship  2. Falcon 9  3. Falcon Heavy\n");
            scanf("%i", &naves[i].Tiponave);
        }while(naves[i].Tiponave<0 && naves[i].Tiponave>4);

        do
        {
            printf("Ingrese cantidad de vuelos realizados: ");
            scanf("%d", &naves[i].CantVuelos);
            if (naves[i].CantVuelos<0)
            {
                printf("ingrese horas positivas\n");
            }
        }while(naves[i].HorasVueloAcum<0);

        do
        {
            printf("Ingrese horas de vuelo acumuladas: ");
            scanf("%d", &naves[i].HorasVueloAcum);
            if (naves[i].HorasVueloAcum<0)
            {
                printf("ingrese horas positivas\n");
            }
        }while(naves[i].HorasVueloAcum<0);

        do{
        printf("ingrese estado de la nave: ");
        printf("0. en mantenimiento  1. lista   2. de baja \n");
        fflush(stdin);
        scanf("%i",&naves[i].Estado);
        if (naves[i].Estado==2)
        {
            naves[i].Estado=3;
        }
        } while (naves[i].Estado != 0 && naves[i].Estado != 1 && naves[i].Estado != 3);

        naves[i].LugarNave=i;
        naves[i].enmiss=0;
        i++;

        }
    else
        {
            printf("ya alcanzaste el limite de Naves permitidas");
        }

}

//Carga un arreglo de Nave
void cargaarregloNave (stnave naves[], int pos)
{
    system("COLOR 0A");
    char opc='s';
    int i = pos;

    while (opc=='s' && i<dim)
    {
        cargaNave(naves, i);

        printf("desea ingresar otra nave?");
        fflush(stdin);
        scanf("%c", &opc);

        if (opc=='s' && i<dim)
        {
           system("cls");
        }

        i++;
    }
}

//muestra una nave
void muestraNave(stnave naves[],int pos)
{
    system("COLOR 0A");
    int i=pos;

    printf("ID Nave: ");
    printf("%d",naves[i].ID);
    printf("-----\n");

    printf("Tipo de Nave: ");
    switch (naves[i].Tiponave)
    {
    case 1:
        printf("Starship");
        break;
    case 2:
        printf("Falcon 9");
        break;
    case 3:
        printf("Falcon Heavy");
        break;
    }

    printf("-----\n");

    printf("Estado: ");
    if (naves[i].enmiss==1)
    {
        printf("En mision");
    }
    else
    {
        switch (naves[i].Estado)
        {
        case 0:
            printf("En mantenimiento");
            break;
        case 1:
            printf("Lista para su uso");
            break;
        case 2:
            printf("En mision");
            break;
        case 3:
            printf("De baja");
            break;
        }
    }

    printf("-----\n");

    printf("Cantidad de vuelos: ");
    printf("%d",naves[i].CantVuelos);
    printf("-----\n");

    printf("Cantidad de horas acumuladas: ");
    printf("%i",naves[i].HorasVueloAcum);
    printf("-----\n");

}

//Muestra todo el arreglo de Naves
void mustraarregloNaves (stnave naves[])
{
    int i=0;
    int validos=posNave(naves);

    for(i=0;i<validos;i++)
    {
        muestraNave(naves, i);
        printf("\n");
    }
}

//inicializa las posiciones de un arreglo de astronauta. es necesario que se ulice cada vez que se genera un nuevo arreglo de astronautas
void inicmiss (stmision miss[])
{
    int i;

    for (i=0;i<dim;i++)
    {
        if (i==0)
        {
            miss[i].lugarmision=1;
        }
        else
        {
            miss[i].lugarmision=0;
        }
    }
}

//retorna la cantidad de misiones cargadas ("los validos")
int posmiss (stmision miss[])
{
    int i=0;

    while (i == miss[i].lugarmision)
    {
        i++;
    }
    return i;
}

// se ingresa una id, se devuelve la posicion de la mision a la que pertenece, devuelve -1 si no existe
int idposmiss (stmision miss[], int id)
{
    int validos = posmiss(miss);
    int pos = -1, i = 0;
    while (i<validos)
    {
        if (miss[i].ID==id)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

//carga una misión
void cargaMision(stmision miss[],int pos, stastronauta astro[], stnave naves[])
{
    int pos2=0, aux=0;
    int i=pos;
    int cantcargamento=0, tripulantes=0;
    char opc;

    system("color 0A");
    do{
        printf("Ingrese ID de la mision: ");
        scanf("%d",&aux);

        if(idposmiss(miss, aux)!= -1)
            {
                printf("\nesta id ya existe, por favor ingrese una distinta\n");
            }
    } while (idposmiss(miss, aux)!= -1);
    miss[i].ID=aux;

    do
    {
        printf("Ingrese ID nave: ");
        scanf("%i",&miss[i].IDnave);

        if(idposNave(naves, miss[i].IDnave)== -1)
            {
                printf("\nesta nave no existe, por favor ingrese una distinta\n");
            }
            else if (estadonave(naves, miss[i].IDnave)!=1)
            {
                printf("\nesta nave no está lista, por favor ingrese una distinta\n");
            }
    } while (idposNave(naves, miss[i].IDnave)== -1 && (estadonave(naves, miss[i].IDnave)!=1));

    pos2 = idposNave(naves, miss[i].IDnave);
    naves[pos2].enmiss=1;
    cambiarestadonave(naves, miss[i].IDnave, 2);

    do{
        printf("Ingrese estado: ");
        printf("1. Listo  2. En vuelo  3. Retirado 4. Cancelado 5. Fallida ");
        scanf("%i",&miss[i].Estado);
    }while(miss[i].Estado>5 && miss[i].Estado<0);



    printf("Ingrese destino: ");
    fflush(stdin);
    scanf("%s",&miss[i].Destino);

    do{
        printf("Ingrese Cargamento: ");
        fflush(stdin);
        scanf("%s",&miss[i].Cargamento[cantcargamento]);
        printf("hay mas cargamento? (s/n)");
        fflush(stdin);
        scanf("%c", &opc);
        cantcargamento++;
    } while (opc=='s');

    do{

        do
        {
        printf("Ingrese un tripulante (ID): ");
        fflush(stdin);
        scanf("%i",&miss[i].Tripulantes[tripulantes]);
        pos2 =idposAstro(astro, miss[i].Tripulantes[tripulantes]);
        if (idposAstro(astro, miss[i].Tripulantes[tripulantes])== -1)
        {
            printf("\neste tripulante no existe, por favor ingrese otro\n");
        }
        else if (retirado(astro, miss[i].Tripulantes[tripulantes])==1)
        {
            printf("\neste tripulante está retirado, por favor ingrese otro\n");
        }
        else if (astro[pos2].enmiss==1)
        {
            printf("\neste tripulante está en una misión, por favor ingrese otro\n");
        }

        }while((retirado(astro, miss[i].Tripulantes[tripulantes])==1) && (astro[pos2].enmiss==1) && (idposAstro(astro, miss[i].Tripulantes[tripulantes])== -1));

        astro[pos2].enmiss=1;

        printf("hay mas tripulantes? (s/n)");
        fflush(stdin);
        scanf("%c", &opc);
        tripulantes++;
    } while (opc=='s');

    miss[i].canttripulantes=tripulantes;
    miss[i].cantcargamento=cantcargamento;
    miss[i].lugarmision=i;

}

//carga tantas misiones como el usuario desee
void cargaarreglomision (stmision miss[],int pos, stastronauta astro[], stnave naves[])
{
    char opc='s';
    int i=pos;

system("COLOR 0A");

    while (opc=='s' && i<dim)
    {
        cargaMision(miss, i, astro, naves);

        printf("desea ingresar otra mision? (s/n)");
        fflush(stdin);
        scanf("%c", &opc);
        i++;
    }
}

//muestra una mision por posicion
void muestraMision(stmision miss[], stastronauta astro[], int pos)
{
    int i = pos, pos2=0;
    int cargamento=0, tripulantes=0;

    system("COLOR 0A");

    printf("ID de la mision: %d",miss[i].ID);
    printf("-----\n");

    printf("Estado de la nave: %i",miss[i].Estado);
    printf("-----\n");

    printf("Destino de la nave: %s",miss[i].Destino);
    printf("-----\n");

    while (cargamento<miss[i].cantcargamento)
    {
        if (cargamento==0)
        {
            printf("Cargamento: ");
        }
        printf("\n");

        printf("-%s", miss[i].Cargamento[cargamento]);

        cargamento++;

    }
    printf("-----\n");

    while (tripulantes<miss[i].canttripulantes)
    {
        if (tripulantes==0)
        {
            printf("Tripulantes: ");
        }
        printf("\n");
        pos2=idposAstro(astro, miss[i].Tripulantes[tripulantes]);
        printf("%i. %s",(tripulantes+1), astro[pos2].nombre);
        tripulantes++;
    }
    printf("\n");
}

//muestra todo un arreglo de misiones
void muestraarregloMiss(stmision miss[], stastronauta astro[])
{
    int validos = posmiss(miss);
    for (int i=0; i<validos; i++)
    {
        muestraMision(miss, astro, i);
        printf("\n");
    }
}

//retorna el estado de una nave enviada por parametro
int estadomiss (stmision miss[], int id)
{
    int pos = idposmiss(miss, id);

    return miss[pos].Estado;
}

//cambia un atributo de nave
void cambiarnave(stnave naves[], int id)
{
    int num, pos=0;
    int i=idposNave(naves, id);
    system("color 0A");

    printf("Presione:\n");

    printf("1 para Cambiar cantidad de vuelos\n");
    printf("2 para Cambiar horas de vuelo acumuladas\n");
    printf("3 para cambiar Tipo de nave\n");
    printf("4 para actualizar nave a: \"en mantenimiento\"\n");
    printf("5 para salir\n");

    scanf("%d",&num);



    switch(num)
    {

     case 1:
        printf("Ingrese nueva cantidad de vuelos: ");
        fflush(stdin);
        scanf("%i",&naves[i].CantVuelos);
    break;

    case 2:
        printf("Ingrese nuevas horas de vuelo acum: ");
        scanf("%d",&naves[i].HorasVueloAcum);
    break;

    case 3:
         do
        {
            printf("Ingrese nuevo tipo de nave: 1. Starship  2. Falcon 9  3. Falcon Heavy\n");
            scanf("%i", &naves[i].Tiponave);
        }while(naves[i].Tiponave<0 && naves[i].Tiponave>4);
    break;

    case 4:
        if(naves[i].enmiss!=1)
        {
            naves[i].Estado=0;
            printf("El estado de la nave fue actualizado con exito\n");
            system("cls");
        }
        else
        {
            printf("No podes cambiar el estado de una nave en mision, lo sentimos\n");
        }
    break;

    }
}

//cambia atributo de mision
void cambiomision(stmision miss[], int id, stastronauta astro[], stnave naves[])
{
    int pos=0, opc=0, pos2=0, cam=0, cargamento=0, tripulantes=0;
    int i=idposmiss(miss,id);
    int num=0;

    printf("Presione:\n");

    printf("1 para cambiar nave\n");
    printf("2 para cambiar destino\n");
    printf("3 para cambiar cargamento\n");
    printf("4 para cambiar los tripulantes\n");
    printf("5 para actualizar estado");
    printf("6 para Salir\n");

    scanf("%d",&num);
    if (miss[i].Estado==2 && num!=5)
    {
        printf("no podes hacer cambios, la mision ya despego");
    }
    else
    {
        switch(num)
    {

     case 1:
        pos = idposNave(naves, miss[i].IDnave);
        naves[pos].enmiss=0;
        cambiarestadonave(naves, miss[i].IDnave, 1);
        do
        {
            printf("Ingrese el ID de la nueva nave: ");
            scanf("%i",&miss[i].IDnave);

            if(idposNave(naves, miss[i].IDnave)== -1)
            {
                printf("\nesta nave no existe, por favor ingrese una distinta\n");
            }
            else if (estadonave(naves, miss[i].IDnave)!=1)
            {
                printf("\nesta nave no esta lista, por favor ingrese una distinta\n");
            }
        } while (idposNave(naves, miss[i].IDnave)== -1 && (estadonave(naves, miss[i].IDnave)!=1));

        pos = idposNave(naves, miss[i].IDnave);
        naves[pos].enmiss=1;
        cambiarestadonave(naves, miss[i].IDnave, 2);
    break;

     case 2:
        printf("Ingrese nuevo Destino: ");
        fflush(stdin);
        scanf("%s",&miss[i].Destino);
    break;

     case 3:
        while (cargamento<miss[i].cantcargamento)
        {
            if (cargamento==0)
            {
                printf("Cargamento: ");
            }
            printf("\n");
            printf("%i. %s",cargamento, miss[i].Cargamento[cargamento]);
            cargamento++;
        }
        printf("\nque desea cargamento desea cambiar?\n");
        scanf("%d",&opc);
        opc--;
        printf("ingrese el nuevo cargamneto que ocupara su lugar\n");
        scanf("%s", &miss[i].Cargamento[opc]);
    break;

     case 4:
        while (tripulantes<miss[i].canttripulantes)
        {
            if (tripulantes==0)
            {
                printf("Tripulantes: ");
            }
            printf("\n");
            pos2=idposAstro(astro, miss[i].Tripulantes[tripulantes]);
            printf("%i. %s",(tripulantes+1), astro[pos2].nombre);
            tripulantes++;
        }
        printf("\n");
        printf("que desea tripulante desea cambiar?");
        scanf("%d",&opc);
        opc--;

        pos=idposAstro(astro, miss[i].Tripulantes[opc]);
        astro[pos].enmiss=0;

        do
        {
            printf("Ingrese el nuevo tripulante (ID): ");
            scanf("%i",&miss[i].Tripulantes[opc]);
            pos2 =idposAstro(astro, miss[i].Tripulantes[opc]);
            if (idposAstro(astro, miss[i].Tripulantes[opc])== -1)
            {
                printf("\neste tripulante no existe, por favor ingrese otro\n");
            }
            else if (retirado(astro, miss[i].Tripulantes[opc])==1)
            {
                printf("\neste tripulante está retirado, por favor ingrese otro\n");
            }
            else if (astro[pos2].enmiss==1)
            {
                printf("\neste tripulante esta en una mision, por favor ingrese otro\n");
            }

        }while((retirado(astro, miss[i].Tripulantes[opc])==1) && (astro[pos2].enmiss==1) && (idposAstro(astro, miss[i].Tripulantes[opc])== -1));

        astro[pos2].enmiss=1;
        break;

    case 5:
        pos=idposmiss(miss, id);
        if (miss[pos].Estado==2)
        {
            printf("la mision ha sido:\n1. retornada \n2. fallida");
            scanf("%i", &opc);
            if (opc==1)
            {
                miss[pos].Estado=3;
                printf("Felicitaciones a los tripulantes!!");
                cam=1;
            }
            else if (opc==2)
            {
                miss[pos].Estado==4;
                printf("Lamentamos el fallo de la mision");
                cam=1;
            }
            else
            {
                printf("no introdujo una opcion valida, vuelva a intentarlo");
            }
        }
        if (cam==1)
        {
            while (tripulantes<miss[i].canttripulantes)
            {
                pos2=idposAstro(astro, miss[pos].Tripulantes[tripulantes]);
                astro[pos2].enmiss=0;
                tripulantes++;
            }
        }
        system("cls");
    break;

    case 6:
        system("cls");
    break;
    }
    }
}







