#ifndef CLASEGENERO_H_INCLUDED
#define CLASEGENERO_H_INCLUDED

class Genero{
    private:
    int idGenero;
    char nombre[40];
    int pais;
    int tipoInstrumentacion;
    bool estado;
    int contadorID();
    public:
    void Cargar();
    void Mostrar();
    bool leerDeDisco(int pos);
    bool leerDeDiscoBkp(int pos);
    bool leerInicio(int pos);
    ///SETS
    void setNombre(const char *nom){strcpy(nombre,nom);}
    bool setPais(int p){
        if(p>0 && p<101){
            pais=p;
            return true;
        }
        cout<<"numero invalido"<<endl;
        return false;
    }
    bool setTipoInstrumentacion(int tipo){
        if(tipo>0 && tipo<6){
            tipoInstrumentacion=tipo;
            return true;
        }
        cout<<"numero invalido"<<endl;
        return false;
    }
    void setEstado(bool e){estado=e;}
    ///FIN SETS
    ///GETS
    int getIdGenero(){return idGenero;}
    const char *getNombre(){return nombre;}
    int getPais(){return pais;}
    int getTipoInstrumentacion(){return tipoInstrumentacion;}
    bool getEstado(){return estado;}
    ///FIN GETS
};

int Genero::contadorID()
{
    Genero obj;
    int pos=0;
    while(obj.leerDeDisco(pos))
        {
            pos++;
        }
    return pos+1;
}

void Genero::Cargar()
{
    idGenero=contadorID();
    cout<<"EL ID ES: "<<idGenero<<endl;
    cout<<"NOMBRE: ";
    cargarCadena(nombre,39);
    cout<<"PAIS DE ORIGEN: ";
    int pais;
    cin>>pais;
    if(!setPais(pais))return;
    cout<<"TIPO DE INSTRUMENTACION: ";
    int tipo;
    cin>>tipo;
    if(!setTipoInstrumentacion(tipo))return;
    estado=true;
}

void Genero::Mostrar()
{
    cout<<"EL ID ES: "<<idGenero<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"PAIS DE ORIGEN: "<<pais<<endl;
    cout<<"TIPO DE INSTRUMENTAICON: "<<tipoInstrumentacion<<endl;
}

bool Genero::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(GENEROS,"rb");
    if(p==NULL) return false;
    fseek(p, pos *sizeof(Genero),0);//nos posicionamos donde queremos leer
    bool leyo=fread(this, sizeof (Genero),1,p);//lee el registro
    fclose(p);
    return leyo;
}

bool Genero::leerDeDiscoBkp(int pos)
{
    FILE *p;
    p=fopen("genero.bkp","rb");
    if(p==NULL) return false;
    fseek(p, pos *sizeof(Genero),0);//nos posicionamos donde queremos leer
    bool leyo=fread(this, sizeof (Genero),1,p);//lee el registro
    fclose(p);
    return leyo;
}

bool Genero::leerInicio(int pos)
{
    FILE *p;
    p=fopen("generosInicio.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos *sizeof(Genero),0);//nos posicionamos donde queremos leer
    bool leyo=fread(this, sizeof (Genero),1,p);//lee el registro
    fclose(p);
    return leyo;
}
#endif // CLASEGENERO_H_INCLUDED
