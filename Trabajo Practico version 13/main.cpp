#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const char *CANCIONES="canciones.dat";
const char *INTERPRETES="interpretes.dat";
const char *GENEROS="generos.dat";
#include "funcionesGlobales.h"
#include "menuCanciones.h"
#include "menuInterpretes.h"
#include "menuGeneros.h"
#include "claseCancion.h"
#include "funcionesCancion.h"
#include "claseGenero.h"
#include "funcionesGenero.h"


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
            case 4:
                break;
            case 5:
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

