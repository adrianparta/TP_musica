#ifndef FUNCIONESGENERO_H_INCLUDED
#define FUNCIONESGENERO_H_INCLUDED
//PROTOTIPOS

void grabarGenero(Genero reg);
void agregarGenero();
void listarGeneroID();
bool listarGeneros();
void modificarTipo();
int contadorDeGeneros();
//FIN PROTOTIPOS

void grabarGenero(Genero reg){
    FILE *p;
    p=fopen(GENEROS,"ab");
    if(p==NULL){
        cout<<"no se pudo abrir el archivo";
        return;
    }
    fwrite(&reg,sizeof reg, 1, p);
    fclose(p);
    cout<<"registro agregado correctamente"<<endl;
    system("pause");
    return;
}

void agregarGenero(){
    Genero reg;
    reg.Cargar();//validaciones
    if(reg.getEstado()){
        grabarGenero(reg);
        return;
    }
    cout<<"no se pudo cargar el registro"<<endl;
    system("pause");
    return;
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

void modificarTipo(){
    Genero obj;
    FILE *p;
    int pos=0;
    p=fopen(GENEROS,"rb+");
    if(p==NULL){
        cout<<"el archivo no pudo abrirse"<<endl;
        system("pause");
        fclose(p);
        return;
    }
    cout<<"ingrese el ID del genero: ";
    cin>>pos;
    while(fread(&obj,sizeof obj,1,p)){
        if(pos==obj.getIdGenero()){
            if(!obj.getEstado()){
                cout<<"El ID existe pero esta oculto"<<endl;
                system("pause");
                fclose(p);
                return;
            }
            cout<<"ingrese un tipo de instrumentacion: ";
            int nuevoTipo;
            cin>>nuevoTipo;
            if(!obj.setTipoInstrumentacion(nuevoTipo)){
                system("pause");
                fclose(p);
                return;
            }
            fseek(p,pos*sizeof obj,0);
            fwrite(&obj,sizeof obj,1,p);
            fclose(p);
            cout<<"tipo de instrumentacion cambiado existosamente"<<endl;
            system("pause");
            return;
        }
    }
    cout<<"el ID no existe"<<endl;
    system("pause");
    fclose(p);
}

int contadorDeGeneros(){
Genero obj;
FILE *p;
p=fopen(GENEROS,"rb");
if(p==NULL){
        fclose(p);
        return 10;
    }
fseek(p,0,2);
int cantidad=ftell(p)/sizeof obj+1;
fclose(p);
return cantidad;
}



#endif // FUNCIONESGENERO_H_INCLUDED
