#ifndef FUNCIONESINTERPRETE_H_INCLUDED
#define FUNCIONESINTERPRETE_H_INCLUDED

///PROTOTIPOS
void agregarInterprete();
void cargarInterpretes(Interprete *v,int cant);
void grabarInterprete(Interprete reg);
void mostrarInterpretes();
Interprete cargarInterprete();
void listarInterpreteID();
void modificarGenero();
void eliminarInterprete();
bool existeInterprete(int id);
void copiaInterpretes();
///FIN PROTOTIPOS


void agregarInterprete()
{
    Interprete reg;
    reg=cargarInterprete();//validaciones
    if(!reg.getEstado()){
        cout<<"no se pudo guardar el registro"<<endl;
        system("pause");
    return;
    }
    grabarInterprete(reg);
    return;
}

Interprete cargarInterprete()
{
    Interprete reg;
    if(!reg.Cargar()){
        reg.setEstado(false);
    }
    return reg;
}

void cargarInterpretes(Interprete *v,int cant)
{
    int i;
    for(i=0;i<cant;i++)
        {
            v[i].Cargar();
            cout<<endl;
        }
}

void grabarInterprete(Interprete reg){
    FILE *p;
    p=fopen(INTERPRETES,"ab");
    if(p==NULL){
        return;
    }
    fwrite(&reg,sizeof reg, 1, p);
    fclose(p);
    cout<<"se grabo correctamente"<<endl;
    system("pause");
    return;
}

void mostrarInterpretes(){
    Interprete obj;
    FILE *p;
    p=fopen(INTERPRETES,"rb");
    if(p==NULL){
        return;
    }
    while(fread(&obj,sizeof obj, 1, p)==1){
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    fclose(p);
    system("pause");
	return;
}


void listarInterpreteID(){
    Interprete obj;
    int pos;
    FILE *p;
    p=fopen(INTERPRETES,"rb");
    if(p==NULL){
        cout<<"el archivo no pudo abrirse"<<endl;
        system("pause");
        return;
    }
    cout<<"INGRESE ID: ";
    cin>>pos;
    while(fread(&obj,sizeof obj, 1, p)){
        if(pos==obj.getIdInterprete()){
            if(!obj.getEstado()){
                cout<<"El ID existe pero esta oculto"<<endl;
                system("pause");
                fclose(p);
                return;
            }

            obj.Mostrar();
            fclose(p);
            system("pause");
            return;
            cout<<endl;
        }
    }
    cout<<"----------------"<<endl;
    cout<<"NO EXISTE ESE ID"<<endl;
    cout<<"----------------"<<endl;
    system("pause");
    fclose(p);
    return;
}

void modificarGenero(){
    Interprete obj;
    FILE *p;
    int pos=0;
    p=fopen(INTERPRETES,"rb+");
    if(p==NULL){
        cout<<"el archivo no pudo abrirse"<<endl;
        system("pause");
        fclose(p);
        return;
    }
    cout<<"ingrese el ID del interprete: ";
    cin>>pos;
    while(fread(&obj,sizeof obj,1,p)){
        if(pos==obj.getIdInterprete()){
            if(!obj.getEstado()){
                cout<<"El ID existe pero esta oculto"<<endl;
                system("pause");
                fclose(p);
                return;
            }
            cout<<"ingrese un numero de genero: ";
            int nuevoGen;
            cin>>nuevoGen;
            if(!obj.setGenero(nuevoGen)){
                system("pause");
                fclose(p);
                return;
            }
            fseek(p,pos*sizeof obj,0);
            fwrite(&obj,sizeof obj,1,p);
            fclose(p);
            cout<<"genero cambiado existosamente"<<endl;
            system("pause");
            return;
        }
    }
    cout<<"el ID no existe"<<endl;
    system("pause");
    fclose(p);
}

void eliminarInterprete(){

    Interprete obj;
    FILE *p;
    int pos;
    p=fopen(INTERPRETES,"rb+");
    if(p==NULL){
        cout<<"el archivo no pudo abrirse"<<endl;
        system("pause");
        fclose(p);
        return;
    }
    cout<<"ingrese el ID del interprete: ";
    cin>>pos;
    while(fread(&obj,sizeof obj,1,p)){
        if(pos==obj.getIdInterprete()){
            if(!obj.getEstado()){
                cout<<"el interprete ya fue eliminado"<<endl;
                system("pause");
                fclose(p);
                return;
            }
            obj.setEstado(false);
            fseek(p,pos*sizeof obj,0);
            fwrite(&obj,sizeof obj,1,p);
            fclose(p);
            cout<<"interprete eliminado correctamente"<<endl;
            system("pause");
            return;
        }
    }
    cout<<"el ID no existe"<<endl;
    system("pause");
    fclose(p);
}

bool existeInterprete(int id){
Interprete obj;
FILE *p;
p=fopen(INTERPRETES,"rb");
if(p==NULL){
    cout<<"el archivo no pudo abrirse"<<endl;
    system("pause");
    fclose(p);
    return false;
}
while(fread(&obj,sizeof obj,1,p)){
    if(id==obj.getIdInterprete()){
        fclose(p);
        return true;
    }
}
return false;
}

void copiaInterpretes()
{
    FILE *p;
    Interprete reg;
    int pos=0;
    p=fopen("interprete.bkp","wb");
    while(reg.leerDeDisco(pos++))
	{
		fwrite(&reg,sizeof reg,1,p);
	}
	fclose(p);
	cout<<"SE REALIZO LA COPIA DEL ARCHIVO CORRECTAMENTE"<<endl;
	system("pause");
}

void restaurarInterpretes(){

    FILE *p;
    Interprete reg;
    int pos=0;
    p=fopen(INTERPRETES,"wb");
    while(reg.leerDeDiscoBkp(pos++))
	{
		fwrite(&reg,sizeof reg,1,p);
	}
	fclose(p);
	cout<<"SE REALIZO LA RESTAURACION DEL ARCHIVO CORRECTAMENTE"<<endl;
	system("pause");

}
#endif // FUNCIONESINTERPRETE_H_INCLUDED

