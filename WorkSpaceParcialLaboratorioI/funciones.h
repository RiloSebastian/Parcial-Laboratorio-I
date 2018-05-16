#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct
{
char nombre[60];
int idPropietario;
char NumeroDeTarjeta[10];
char direccion[50];
int estado;

}ePropietarios;

typedef struct
{
    int idAuto;
    char patente[10];
    char marca[20];
    int propietario;
    int estado;

}eAutos;

void inicializar(ePropietarios propietario[],int cant);
int buscarLibre(ePropietarios propietario[], int cant);
int altapropietario(ePropietarios propietario[], int cant);
int bajaPropietario(ePropietarios propietario[], int cant, eAutos autos[]);
int propietarioSiguienteId(ePropietarios propietario[],int cant);
int modificarPropietario(ePropietarios propietario[], int cant);
void propietarioMostrarUno(ePropietarios propietario);
void propietarioMostrarListado(ePropietarios propietario[],int cant);
void propietarioMostrarPorId(ePropietarios propietario[], eAutos autos[], int cant);
void PropietarioMostrarAudi(ePropietarios propietario[], eAutos autos[], int cant);


void inicializarAutos(eAutos autos[],int cant);
int altaAuto (eAutos autos[], int cant);
int bajaAutos(eAutos autos[], int cant, ePropietarios propietario[]);
int buscarLibreAutos(eAutos autos[], int cant);
int autosSiguienteId(eAutos autos[],int cant);
void autosMostrarUno(eAutos autos);
void autosMostrarListado(eAutos autos[],int cant);
void mostrarautosPorPatente(eAutos autos[], ePropietarios propietario[], int cant);
int devolverHorasEstadia(void);
void tarifaaPagar(eAutos autos[], int cant, int id, ePropietarios propietario[]);
void mostrarRecaudadoMarca();
void mostrarTotalRecaudado();

#endif
