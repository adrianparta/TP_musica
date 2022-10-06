#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void cantCancionesXInterprete();
int contarCanciones(int id);
void informarCanciones();
void mostrarVector(int *v,int tam);
void punto1();
void punto2();
void punto3();
int contarCancionInterprete(int id);

void cantCancionesXInterprete(){
    Interprete obj;
    FILE *p;
    p=fopen(INTERPRETES,"rb");
    if(p==NULL){return;}
    while(fread(&obj,sizeof obj,1,p)){
    if(obj.getEstado()){
    int cant=contarCanciones(obj.getIdInterprete());
    cout<<"cantidad de canciones del interprete "<<obj.getNombre()<<", que corresponde al ID: "<<obj.getIdInterprete()<<" es: "<<cant<<endl;
    }
    }
    system("pause");
    return;
}

int contarCanciones(int id){
    int cant=0;
    Cancion obj;
    FILE *p;
    p=fopen(CANCIONES,"rb");
    if(p==NULL)return 0;
    while(fread(&obj,sizeof obj,1,p)){
        if(obj.getIdInterprete()==id && obj.getEstado()) cant++;
    }
    fclose(p);
    return cant;
}

void informarCanciones(){
    int pos;
    Cancion obj;
    FILE *p;
    p=fopen(CANCIONES,"rb");
    if(p==NULL) return;
    cout<<"INGRESE NUMERO DE GENERO: ";
    cin>>pos;
    cout<<endl;
    if(!(pos>0 && pos<=contadorDeGeneros())){
        cout<<"----------------"<<endl;
        cout<<"NO EXISTE ESE ID"<<endl;
        cout<<"----------------"<<endl;
        system("pause");
        fclose(p);
        return;
    }
    while(fread(&obj,sizeof obj,1,p)){
        if(pos==obj.getGenero() && obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    system("pause");
    fclose(p);
    return;
}

void punto1()
{
    Interprete obj;
    int pos=0;
    while(obj.leerDeDisco(pos))
    {
        if(obj.getNacionalidad()==5 && obj.getEstado())
        {
            obj.Mostrar();
            cout<<endl;
        }
        pos++;
    }
    system("pause");
    return;
}

void punto2()
{
    Genero obj;
    int vGenero[5]={};
    int pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getEstado())
            {
                vGenero[obj.getTipoInstrumentacion()-1]++;
            }
    }
    mostrarVector(vGenero, 5);
    return;
}

void mostrarVector(int *v,int tam)
{
    for(int i=0;i<tam;i++)
    {
        cout<<"PARA EL TIPO DE INSTRUMENTACION "<<i+1<<" HAY "<<v[i]<<" GENEROS"<<endl;
    }
    system("pause");
    return;
}

class Interprete2021
{
    private:
    int ID;
    char nombre[40];
    int cantidadCanciones;
    public:
        void setID(int i){ID=i;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setCantidadCanciones(int c){cantidadCanciones=c;}
        int getID(){return ID;}
        const char *getNombre(){return nombre;}
        int getCantidadCanciones(){return cantidadCanciones;}
        bool grabarEnDisco()
        {
            FILE *p;
            p=fopen("interpretes2021.dat","ab");
            if(p==NULL) return false;
            bool escribio=fwrite(this, sizeof (Interprete2021), 1,p);
            fclose(p);
            return escribio;
        }

        void mostrar(){
        cout<<"El ID es:"<<getID()<<endl;
        cout<<"El nombre es:"<<getNombre()<<endl;
        cout<<"la cantidad de canciones es:"<<getCantidadCanciones()<<endl;
        system("pause");
        return;
        }
};

void punto3()
{
    Interprete obj;
    Interprete2021 aux;
    int pos=0, cant;
    while(obj.leerDeDisco(pos++))
        {
            ///CHEKEAR QUE HAYA INICIADO SUS ACTVIDADDES EN EL 2021
            if(obj.getFechaInicio().getAnio()==2021 && obj.getEstado())
            {
            ///SI INICIO EN 2021, CONTAR LA CANTIDAD DE CANCIONES
            cant=contarCancionInterprete(obj.getIdInterprete());
            ///SETEAR OBJETO AUX Y GRABAR EN DISCO
            aux.setID(obj.getIdInterprete());
            aux.setNombre(obj.getNombre());
            aux.setCantidadCanciones(cant);
            aux.grabarEnDisco();
            aux.mostrar();
            }
        }
}

int contarCancionInterprete(int id)
{
    Cancion obj;
    int pos=0, cant=0;
    while(obj.leerDeDisco(pos++))
        {
            ///POR CADA REGISTRO, CHEQUEAR SI ES DEL INTERPRETE QUE RECIBI
            if(obj.getIdInterprete()==id && obj.getEstado())
            {
                cant++;
            }
        }
        return cant;
}
#endif // REPORTES_H_INCLUDED
