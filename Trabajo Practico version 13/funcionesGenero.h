#ifndef FUNCIONESGENERO_H_INCLUDED
#define FUNCIONESGENERO_H_INCLUDED
//PROTOTIPOS
Genero cargarGenero();
bool grabarGenero(Genero reg);
bool agregarGenero();
void listarGeneroID();
bool listarGeneros();
//FIN PROTOTIPOS

Genero cargarGenero()
{
    Genero reg;
    reg.Cargar();
    return reg;
}

bool grabarGenero(Genero reg){
    FILE *p;
    p=fopen(GENEROS,"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

bool agregarGenero()
{
    Genero reg;
    reg=cargarGenero();//validaciones
    if(!reg.getEstado()){
        cout<<"no se pudo guardar el registro"<<endl;
        system("pause");
    return false;
    }
    if(grabarGenero(reg))return true;
    cout<<"error";return false;
}

void listarGeneroID()
{
    Genero obj;
    int pos;
    FILE *p;
    p=fopen(GENEROS,"rb");
    if(p==NULL) return;
        cout<<"INGRESE ID: ";
        cin>>pos;
        while(fread(&obj,sizeof obj, 1, p)==1)
            {
                if(pos==obj.getIdGenero()){
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

bool listarGeneros(){
    Genero obj;
    FILE *p;
    p=fopen(GENEROS,"rb");
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

#endif // FUNCIONESGENERO_H_INCLUDED
