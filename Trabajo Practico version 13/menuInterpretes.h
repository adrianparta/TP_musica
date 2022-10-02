#ifndef MENUINTERPRETES_H_INCLUDED
#define MENUINTERPRETES_H_INCLUDED

#include "claseInterprete.h"
#include "funcionesInterprete.h"
/*
----RESTRICCIONES----
El ID de int�rprete no debe repetirse.
La nacionalidad del int�rprete s�lo debe aceptar valores enteros entre 1 y 100.
Tipo de int�rprete representa si es solista, grupo, orquesta, etc. S�lo debe aceptar valores enteros entre 1 y 5.
G�nero musical representa si es rock, folklore, cl�sica, etc. S�lo debe aceptar valores entre 1 y 10.
La fecha debe ser una fecha v�lida, y anterior o igual a la fecha actual.
El estado debe ser verdadero para que el sistema utilice el registro.
*/

int menuInterpretes(){
    int opcion;
    while(true)
    {
        system("cls");
        cout<<"****MENU INTERPRETES****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- AGREGAR INTERPRETE"<<endl;
        cout<<"2- LISTAR INTERPRETE POR ID"<<endl;
        cout<<"3- LISTAR TODOS LOS INTERPRETES"<<endl;
        cout<<"4- MODIFICAR GENERO MUSICAL PRINCIPAL"<<endl;
        cout<<"5- ELIMINAR INTERPRETE"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
            {
            case 1: agregarInterprete();
                break;
            case 2: listarInterpreteID();
                break;
            case 3: mostrarInterpretes();
                break;
            case 4: modificarGenero();
                break;
            case 5: eliminarInterprete();
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


#endif // MENUINTERPRETES_H_INCLUDED
