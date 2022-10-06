#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;

const char *CANCIONES="canciones.dat";
const char *INTERPRETES="interpretes.dat";
const char *GENEROS="GENEROS.dat";
#include "funcionesGlobales.h"
#include "claseGenero.h"
#include "funcionesGenero.h"
#include "claseInterprete.h"
#include "funcionesInterprete.h"
#include "menuCanciones.h"
#include "menuInterpretes.h"
#include "menuGeneros.h"

#include "datosInicio.h"
#include "menuConfiguracion.h"
#include "claseCancion.h"
#include "funcionesCancion.h"
#include "reportes.h"
#include "menuReportes.h"




int main()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout<<"----MENU PRINCIPAL----"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- MENU CANCIONES"<<endl;
        cout<<"2- MENU INTERPRETES"<<endl;
        cout<<"3- MENU GENEROS"<<endl;
        cout<<"4- REPORTES"<<endl;
        cout<<"5- CONFIGURACION"<<endl;
        cout<<"0 -SALIR"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
            {
            case 1: menuCanciones();
                break;
            case 2: menuInterpretes();
                break;
            case 3: menuGeneros();
                break;
            case 4: menuReportes();//REPORTES (SE DAN LOS EJERCICIOS EL DIA DEL PARCIAL)
                break;
            case 5: menuConfiguracion();
                break;
            case 0:
                return 0;
                break;

            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
            }
    }
    return 0;
}

