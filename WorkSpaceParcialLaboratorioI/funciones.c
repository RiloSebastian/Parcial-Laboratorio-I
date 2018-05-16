#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"
#include "validaciones.h"
#define TAM 20
#define OCUPADO 1
#define LIBRE 0

float recaudado1;
float recaudado2;
float recaudado3;
float recaudado4;
float Totalrecaudado;



void inicializar( ePropietarios propietario[],int cant){
int i;

 if(cant > 0 && propietario != NULL){
  for(i=0; i<cant; i++){
   propietario[i].estado= LIBRE;
   propietario[i].idPropietario=0;
  }

int id[4]= {1,2,3,4};
char nombre[4][60]={"Juan","Luis","Maria","Jose"};
char tarjeta[4][10]={"111-111","222-222","333-333","444-444"};
char direccion[4][50]={"mitre","urquiza","belgrano","alsina"};

 for(i=0; i<4;i++){
  strcpy(propietario[i].nombre, nombre[i]);
  strcpy(propietario[i].NumeroDeTarjeta,tarjeta[i]);
  propietario[i].idPropietario=id[i];
  strcpy(propietario[i].direccion, direccion[i]);
  propietario[i].estado=OCUPADO;
  }
 }
}



int buscarLibre(ePropietarios propietario[], int cant){
int indice=-1;
int i;

 for(i=0;i<20;i++){
  if(propietario[i].estado==0){
   indice=i;
   break;
  }
 }
return indice;
}



int altapropietario(ePropietarios propietario[], int cant){
int index=-1;
int indice;
int id;

indice=buscarLibre(propietario,cant);
 if(indice!=-1){
  if(indice >= 0){
   id = propietarioSiguienteId(propietario,cant);
   propietario[indice].idPropietario=id;
   printf("\n Ingrese nombre:\n ");
   propietario[indice].nombre[60]=validarnombre(propietario[indice].nombre);
   printf(" Ingrese numero de tarjeta:\n ");
   propietario[indice].NumeroDeTarjeta[10]=validarNumerochar(propietario[indice].NumeroDeTarjeta);
   printf(" Ingrese una Direccion:\n ");
   propietario[indice].direccion[50]=validarnombre(propietario[indice].direccion);
   printf(" id del propietario: %d\n ", propietario[indice].idPropietario);
   propietario[indice].estado= OCUPADO;
   index=0;
  }
 }
return index;
}



int propietarioSiguienteId(ePropietarios propietario[],int cant){
int retorno = 0;
int i;
if(cant > 0 && propietario != NULL){
 for(i=0; i<cant; i++){
  if(propietario[i].estado == OCUPADO){
   if(propietario[i].idPropietario>retorno){
    retorno=propietario[i].idPropietario;
   }
  }
 }
}
retorno++;
return retorno;
}



int bajaPropietario(ePropietarios propietario[], int cant, eAutos autos[]){
int horas;
float aPagar=0;
float aux=0;
int index=-1;
int auxId=0;
int i;
int j;

printf(" Ingrese ID del propietario que desea dar de baja:\n ");
auxId=validarNumero(auxId);

for(j=0;j<cant;j++){
 if(autos[j].propietario==auxId){
  Totalrecaudado=aux;
  horas=devolverHorasEstadia();

  if(cant > 0 && autos != NULL){
   if( strcmp(autos[j].marca, "ALPHA ROMEO")==0){
    aPagar=150*horas;
    recaudado1=recaudado1+aPagar;
   }
   else if( strcmp(autos[j].marca, "FERRARI")==0){
    aPagar=175*horas;
    recaudado2=recaudado2+aPagar;
   }
   else if( strcmp(autos[j].marca, "AUDI")==0){
    aPagar=200*horas;
    recaudado3=recaudado3+aPagar;
   }
   else{
    aPagar=250*horas;
    recaudado4=recaudado4+aPagar;
   }
   Totalrecaudado=recaudado1+recaudado2+recaudado3+recaudado4;

   aPagar=Totalrecaudado-aux;
   autos[j].estado=LIBRE;
  }
 }
 for(i=0;i<cant;i++){
  if(propietario[i].idPropietario==auxId){
   propietario[i].estado=LIBRE;
   index=0;
   break;
   }
  }
 }
printf("\n total a pagar: $%.2f\n", aPagar);
return index;
}



int modificarPropietario(ePropietarios propietario[], int cant){
int index=-1;
int aux=0;
int i;

printf(" ingrese id de propietario\n ");
aux=validarNumero(aux);
 if(cant > 0 && propietario != NULL){
  for(i=0;i<cant; i++){
    if(propietario[i].estado == OCUPADO &&aux==propietario[i].idPropietario){
     printf(" Ingrese numero de tarjeta:\n ");
     fflush(stdin);
     propietario[i].NumeroDeTarjeta[10]=validarNumerochar(propietario[i].NumeroDeTarjeta);
     index=0;
    }
   }
  }
 return index;
}



void propietarioMostrarUno(ePropietarios propietario){

    printf(" %s\t          %d\t      %s\t      %s\n",propietario.nombre ,propietario.idPropietario ,propietario.NumeroDeTarjeta, propietario.direccion);
}



void propietarioMostrarListado(ePropietarios propietario[],int cant){
    int i;
    if(cant > 0 && propietario != NULL){
     printf("\n NOMBRE:\t               NUMERO DE ID\t         NUMERO DE TARJETA:\t          DIRECCION: \n");
        for(i=0; i<cant; i++){
            if(propietario[i].estado==OCUPADO){
             fflush(stdin);
             propietarioMostrarUno(propietario[i]);
   }
  }
 }
}

/**------------------------------------------------------------------------------------------------------------------------------*/

void inicializarAutos( eAutos autos[],int cant){
int i;

   if(cant > 0 && autos != NULL){
    for(i=0; i<cant; i++){
     autos[i].estado= LIBRE;
     autos[i].idAuto=0;
    }

    recaudado1=0;
    recaudado2=0;
    recaudado3=0;
    recaudado4=0;
    Totalrecaudado=0;

    int idauto[10]= {1,2,3,4,5,6,7,8,9,10};
    char patente[10][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    char marca[10][15]= {"ALPHA ROMEO","AUDI","AUDI","FERRARI","FERRARI","AUDI","AUDI","OTRO","AUDI","ALPHA ROMEO"};
    int propietarioid[10]= {2,1,2,1,3,3,4,1,4,3};

        for(i=0; i<10;i++){
        autos[i].idAuto=idauto[i];
        strcpy(autos[i].patente,patente[i]);
        autos[i].propietario =propietarioid[i];
        strcpy(autos[i].marca, marca[i]);
        autos[i].estado=OCUPADO;
    }
 }
}



int altaAuto (eAutos autos[], int cant){
int index=-1;
int indice;
int id;

indice=buscarLibreAutos(autos,cant);

  if(indice!=-1){
   if(indice >= 0){
    index=-3;
    id = autosSiguienteId(autos,cant);
    autos[indice].idAuto=id;
    printf("\n Ingrese patente:\n ");
    autos[indice].patente[10]=validarnombre(autos[indice].patente);
    printf(" Ingrese id del propietario:\n ");
    autos[indice].propietario=validarNumero(autos[indice].propietario);
    printf(" ingrese la marca del auto\n ");
    autos[indice].marca[20]=validarnombre(autos[indice].marca);
    printf(" id del auto: %d\n", autos[indice].idAuto);
    autos[indice].estado= OCUPADO;
    index=0;
  }
 }
return index;
}



int buscarLibreAutos(eAutos autos[], int cant){
int indice=-1;
int i;

for(i=0;i<20;i++){
    if(autos[i].estado==0){
     indice=i;
     break;
    }
}
return indice;
}



int autosSiguienteId(eAutos autos[],int cant){
int retorno = 0;
int i;

    if(cant > 0 && autos != NULL){
     for(i=0; i<cant; i++){
      if(autos[i].estado == OCUPADO){
       if(autos[i].idAuto>retorno){
        retorno=autos[i].idAuto;
       }
      }
     }
    }
retorno++;
return retorno;
}



int bajaAutos(eAutos autos[], int cant, ePropietarios propietario[]){
int index=-1;
int auxId=0;
int i;

printf(" Ingrese ID del auto que desea dar de baja:\n ");
auxId=validarNumero(auxId);

    for(i=0;i<cant;i++){
     if(autos[i].idAuto==auxId){
      autos[i].estado=LIBRE;
      tarifaaPagar(autos, TAM, auxId-1 ,propietario);
      index=0;
      break;
     }
    }

return index;
}



void autosMostrarUno(eAutos autos){
printf(" %d\t          %s\t      %s\t      %d\n",autos.idAuto ,autos.patente ,autos.marca, autos.propietario);
}



void autosMostrarListado(eAutos autos[],int cant){
int i;

    if(cant > 0 && autos != NULL){
     printf("\n ID AUTO\t               PATENTE\t          MARCA\t          ID DEL PROPIETARIO \n");
      for(i=0; i<cant; i++){
       if(autos[i].estado==OCUPADO){
        fflush(stdin);
        autosMostrarUno(autos[i]);
       }
      }
    }
}



int devolverHorasEstadia(){

int horas;

srand(time(NULL));
horas = (rand()%24)+1;

return horas ;
}



void tarifaaPagar(eAutos autos[], int cant, int id, ePropietarios propietario[]){
int horas;
float aPagar;
int i;
char nombre[60];

horas=devolverHorasEstadia();

 if(cant > 0 && autos != NULL){
  if( strcmp(autos[id].marca, "ALPHA ROMEO")==0){
   aPagar=150*horas;
   recaudado1=recaudado1+aPagar;
   }
   else if( strcmp(autos[id].marca, "FERRARI")==0){
    aPagar=175*horas;
    recaudado2=recaudado2+aPagar;
   }
   else if( strcmp(autos[id].marca, "AUDI")==0){
    aPagar=200*horas;
    recaudado3=recaudado3+aPagar;
   }
   else{
    aPagar=250*horas;
    recaudado4=recaudado4+aPagar;
   }
   Totalrecaudado=recaudado1+recaudado2+recaudado3+recaudado4;

   for(i=0;i<20;i++){
    if(propietario[i].idPropietario==autos[id].propietario){
     strcpy(nombre, propietario[i].nombre);
    }
   }

printf("\n NOMBRE DE PROPIETARIO:               PATENTE DE AUTO:            MARCA:          VALOR DE ESTADIA:\n %s\t          %s\t      %s\t       %.2f\t\n", nombre , autos[id].patente, autos[id].marca, aPagar);
  }
 }



void mostrarTotalRecaudado(){
    printf("\n TOTAL RECAUDADO: $%.2f\n", Totalrecaudado);
}



void mostrarRecaudadoMarca(){
     printf("\n RECAUDADO EN ALPHA ROMEO: $%.2f\n", recaudado1);
      printf(" RECAUDADO EN FERRARI: $%.2f\n", recaudado2);
       printf(" RECAUDADO EN AUDI: $%.2f\n", recaudado3);
        printf(" RECAUDADO EN OTRO: $%.2f\n", recaudado4);
}



void propietarioMostrarPorId(ePropietarios propietario[], eAutos autos[], int cant){
int auxId=0;
int i;
int j;

printf(" Ingrese ID del propietario:\n");
auxId=validarNumero(auxId);

for(i=0;i<cant;i++){
 if(propietario[i].idPropietario==auxId && propietario[i].estado==OCUPADO){
  printf(" %s \n", propietario[i].nombre);
   for(j=0;j<cant;j++){
    if(autos[j].propietario==propietario[i].idPropietario && autos[j].estado==OCUPADO){
     printf(" PATENTE: %s -- MARCA: %s  \n",autos[j].patente, autos[j].marca);
    }
   }
  }
 }
}



void PropietarioMostrarAudi(ePropietarios propietario[], eAutos autos[], int cant){
int i;
int j;
for(j=0;j<cant;j++){
 if(propietario[j].estado==OCUPADO){
  for(i=0;i<cant;i++){
   if(autos[i].propietario==propietario[j].idPropietario && strcmp(autos[i].marca,"AUDI")==0){
    printf("\n ID: %d\n NOMBRE: %s\n TARJETA: %s\n DIRECCION: %s\n", propietario[j].idPropietario, propietario[j].nombre, propietario[j].NumeroDeTarjeta, propietario[j].direccion);
    break;
    }
   }
  }
 }

}



void mostrarautosPorPatente(eAutos autos[], ePropietarios propietario[], int cant){
int i;
int j;
int k;
int l;
char auxNombre[10];
char auxMarca[20];
int auxPropietario;
int auxId;

for(i=0;i<cant-1;i++){
 if(cant > 0 && autos != NULL && autos[i].estado == OCUPADO){
  for(j=i+1;j<cant;j++){
   if(strcmp(autos[j].patente,autos[i].patente)<0 && autos[j].estado==OCUPADO){
    strcpy(auxNombre, autos[j].patente);
    strcpy(autos[j].patente, autos[i].patente);
    strcpy(autos[i].patente, auxNombre);

    strcpy(auxMarca, autos[j].marca);
    strcpy(autos[j].marca, autos[i].marca);
    strcpy(autos[i].marca, auxMarca);

    auxId=autos[j].idAuto;
    autos[j].idAuto=autos[i].idAuto;
    autos[i].idAuto=auxId;

    auxPropietario=autos[j].propietario;
    autos[j].propietario=autos[i].propietario;
    autos[i].propietario=auxPropietario;
   }
  }
 }
}

for(k=0;k<20;k++){
    if(autos[k].estado==OCUPADO){
     for(l=0;l<cant;l++){
      if(autos[k].propietario == propietario[l].idPropietario && propietario[l].estado==OCUPADO){
       printf("\n  ID DE AUTO: %d\n PATENTE: %s\n MARCA: %s\n PROPIETARIO: %s \n \n ", autos[k].idAuto, autos[k].patente, autos[k].marca, propietario[l].nombre);
       break;
      }
     }
    }
   }
}

/**------------------------------------------------------------------------------------------------------------------------------*/


/**egresos
    int marca[]= {1,1,2,3,2,2,3,4,1,1};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};
*/
