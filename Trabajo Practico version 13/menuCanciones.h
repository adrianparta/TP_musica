#ifndef MENUCANCIONES_H_INCLUDED
#define MENUCANCIONES_H_INCLUDED

#include "claseCancion.h"
#include "funcionesCancion.h"

/*
----ACLARACIONES----
La opción AGREGAR CANCIÓN  deberá permitir ingresar de a un registro por vez.
La opción LISTAR CANCIÓN POR ID deberá solicitar el ID y listar todos los campos del registro si éste existe, o informar si no existe.
La opción LISTAR TODAS LAS CANCIONES  deberá listar todos los campos de todos los registros.
La opción MODIFICAR FECHA DE ESTRENO deberá pedir un ID de canción y una fecha y cambiar la fecha de estreno de la canción con ese ID.
La opción ELIMINAR CANCIÓN deberá solicitar el ID y realizar la baja lógica.
*/

int menuCanciones()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout<<"****MENU CANCIONES****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- AGREGAR CANCION"<<endl;
        cout<<"2- LISTAR CANCION POR ID"<<endl;
        cout<<"3- LISTAR TODAS LAS CANCIONES"<<endl;
        cout<<"4- MODIFICAR FECHA DE ESTRENO"<<endl;
        cout<<"5- ELIMINAR CANCION"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
            {
            case 1: if(agregarCancion()==false)
                        {
                            cout<<"ERROR EN LA APERTURA DEL ARCHIVO"<<endl;
                            system("pause");
                            return -1;
                        }
                        else
                        {
                            cout<<"REGISTRO AGREGADO"<<endl;
                        }
                break;
            case 2: listarCancionID();
                break;
            case 3: mostrarCanciones();
                break;
            case 4: modificarFecha();
                break;
            case 5: eliminarCancion();
                break;
            case 0:
                return 0;
                break;

            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
            }
    }
}


#endif // MENUCANCIONES_H_INCLUDED
