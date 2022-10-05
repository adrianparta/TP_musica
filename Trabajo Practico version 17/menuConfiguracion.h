#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

int menuConfiguracion()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout<<"****MENU CONFIGURACION****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- COPIA DE CANCIONES"<<endl;
        cout<<"2- COPIA DE INTERPRETES"<<endl;
        cout<<"3- COPIA DE GENEROS"<<endl;
        cout<<"4- RESTAURAR EL ARCHIVO DE CANCIONES"<<endl;
        cout<<"5- RESTAURAR EL ARCHIVO DE INTERPRETES"<<endl;
        cout<<"6- RESTAURAR EL ARCHIVO DE GENEROS"<<endl;
        cout<<"7- ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
            {
            case 1: copiaCanciones();
                break;
            case 2: copiaInterpretes();
                break;
            case 3: copiaGeneros();
                break;
            case 4: restaurarCanciones();
                break;
            case 5: restaurarInterpretes();
                break;
            case 6: restaurarGeneros();
                break;
            case 0: return 0;
                break;

            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
            }
    }
}

#endif // MENUCONFIGURACION_H_INCLUDED
