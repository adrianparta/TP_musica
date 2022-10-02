#ifndef FUNCIONESCANCION_H_INCLUDED
#define FUNCIONESCANCION_H_INCLUDED

//PROTOTIPOS
bool grabarCancion(Cancion reg);
bool mostrarCanciones();
bool agregarCancion();
void listarCancionID();
void cargarCanciones(Cancion *v,int cant);
Cancion cargarCancion();
void modificarGenero();
void eliminarCancion();
//FIN PROTOTIPOS

Cancion cargarCancion()
{
    Cancion reg;
    reg.Cargar();
    return reg;
}

bool grabarCancion(Cancion reg){
    FILE *p;
    p=fopen(CANCIONES,"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

void cargarCanciones(Cancion *v,int cant){
    int i;
    for(i=0;i<cant;i++)
        {
            v[i].Cargar();
            cout<<endl;
        }
}

bool agregarCancion()
{
    Cancion reg;
    reg=cargarCancion();//validaciones
    cout<<"cancion agregada correctamente"<<endl;
    system("pause");
    if(grabarCancion(reg))return true;
    return false;
}

bool mostrarCanciones(){
    Cancion obj;
    FILE *p;
    p=fopen(CANCIONES,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&obj,sizeof obj, 1, p)==1){
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    system("pause");
    fclose(p);
	return true;
}


void listarCancionID()
{
    Cancion obj;
    int pos;
    FILE *p;
    p=fopen(CANCIONES,"rb");
    if(p==NULL) return;
        cout<<"INGRESE ID: ";
        cin>>pos;
        while(fread(&obj,sizeof obj, 1, p)==1)
            {
                if(pos==obj.getIdCancion()){
                    if(obj.getEstado()){
                        obj.Mostrar();
                        cout<<endl;
                        system("pause");
                        fclose(p);
                        return;
                        system("pause");
                    }
                    cout<<"el ID existe pero esta oculto"<<endl;
                    system("pause");
                    return;
                }
            }
            cout<<endl;
            cout<<"----------------"<<endl;
            cout<<"NO EXISTE ESE ID"<<endl;
            cout<<"----------------"<<endl;
            system("pause");
            fclose(p);
            return;
        }


void modificarFecha(){
    Cancion obj;
    FILE *p;
    int pos;
    p=fopen(CANCIONES,"rb+");
    if(p==NULL){
        cout<<"el archivo no pudo abrirse"<<endl;
        system("pause");
        fclose(p);
        return;
    }
    cout<<"INGRESE EL ID DE CANCION: ";
    cin>>pos;
    while(fread(&obj,sizeof obj,1,p)){
        if(pos==obj.getIdCancion()){
            if(!obj.getEstado()){
                cout<<"El ID existe pero esta oculto"<<endl;
                system("pause");
                fclose(p);
                return;
            }
            cout<<"INGRESE UNA NUEVA FECHA: ";
            obj.setFechaEstreno();
            fseek(p,pos*sizeof obj,0);
            fwrite(&obj,sizeof obj,1,p);
            fclose(p);
            cout<<"fecha cambiado exitosamente"<<endl;
            system("pause");
            return;
        }
    }
    cout<<"el ID no existe"<<endl;
    system("pause");
    fclose(p);
}


void eliminarCancion(){

    Cancion obj;
    FILE *p;
    int pos;
    p=fopen(CANCIONES,"rb+");
    if(p==NULL){
        cout<<"el archivo no pudo abrirse"<<endl;
        system("pause");
        fclose(p);
        return;
    }
    cout<<"ingrese el ID de la cancion: ";
    cin>>pos;
    while(fread(&obj,sizeof obj,1,p)){
        if(pos==obj.getIdCancion()){
            if(!obj.getEstado()){
                cout<<"la cancion ya fue eliminada"<<endl;
                system("pause");
                fclose(p);
                return;
            }
            obj.setEstado(false);
            fseek(p,pos*sizeof obj,0);
            fwrite(&obj,sizeof obj,1,p);
            fclose(p);
            cout<<"cancion eliminada correctamente"<<endl;
            system("pause");
            return;
        }
    }
    cout<<"el ID no existe"<<endl;
    system("pause");
    fclose(p);
}
//int mostrarCancionID();

#endif // FUNCIONESCANCION_H_INCLUDED

