#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

int menuReportes()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout<<"****MENU REPORTES****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- MOSTRAR POR CADA INTERPRETE LA CANTIDAD DE CANCIONES QUE TIENE REGISTRADAS"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"2- INFORMAR LAS CANCIONES DE UN GENERO QUE SE INGRESE POR TECLADO"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"3- PUNTO 1 SIMULACRO DE PARCIAL"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"4- PUNTO 2 SIMULACRO DE PARCIAL"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"5- PUNTO 3 SIMULACRO DE PARCIAL"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
            {
            case 1: cantCancionesXInterprete();
                break;
            case 2: informarCanciones();
                break;
            case 3: punto1();
                break;
            case 4: punto2();
                break;
            case 5: punto3();
                break;
            case 0: return 0;
                break;

            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
            }
    }
}

#endif // MENUREPORTES_H_INCLUDED
