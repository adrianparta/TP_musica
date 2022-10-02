#ifndef MENUCANCIONES_H_INCLUDED
#define MENUCANCIONES_H_INCLUDED

#include "claseCancion.h"
#include "funcionesCancion.h"

/*
----ACLARACIONES----
La opci�n AGREGAR CANCI�N  deber� permitir ingresar de a un registro por vez.
La opci�n LISTAR CANCI�N POR ID deber� solicitar el ID y listar todos los campos del registro si �ste existe, o informar si no existe.
La opci�n LISTAR TODAS LAS CANCIONES  deber� listar todos los campos de todos los registros.
La opci�n MODIFICAR FECHA DE ESTRENO deber� pedir un ID de canci�n y una fecha y cambiar la fecha de estreno de la canci�n con ese ID.
La opci�n ELIMINAR CANCI�N deber� solicitar el ID y realizar la baja l�gica.
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
