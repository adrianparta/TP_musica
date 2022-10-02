#ifndef MENUGENEROS_H_INCLUDED
#define MENUGENEROS_H_INCLUDED

int menuGeneros()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout<<"****MENU GENEROS****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- AGREGAR GENERO"<<endl;
        cout<<"2- LISTAR GENERO POR ID"<<endl;
        cout<<"3- LISTAR TODOS LOS GENEROS"<<endl;
        cout<<"4- MODIFICAR TIPO DE INSTRUMENTACION"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
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

#endif // MENUGENEROS_H_INCLUDED
