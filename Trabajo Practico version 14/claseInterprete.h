#ifndef CLASEINTERPRETE_H_INCLUDED
#define CLASEINTERPRETE_H_INCLUDED
class Interprete{
    private:
        int idInterprete;
        char nombre[30];
        int nacionalidad;
        int tipoInterprete;
        int genero;
        Fecha fechaInicio;
        bool estado;
        int contadorID();
    public:
        bool Cargar();
        void Mostrar();
        bool leerDeDisco(int pos);
        bool leerDeDiscoBkp(int pos);
        ///sets
        void setIdInterprete(int id){idInterprete=id;}
        void setNombre(const char *nom){strcpy(nombre,nom);}
        bool setNacionalidad(int nacio){
            if(nacio>0 && nacio<101){
                nacionalidad=nacio;
                return true;
            }
        cout<<"numero invalido"<<endl;
        return false;
        }
        bool setTipoInterprete(int tipo){
            if(tipo>0 && tipo<6){
                tipoInterprete=tipo;
                return true;
            }
            cout<<"numero invalido"<<endl;
            return false;
        }
        bool setGenero(int gen){
            if(gen>0 && gen<contadorDeGeneros()+1){
                genero=gen;
                return true;
            }
            cout<<"numero invalido"<<endl;
            return false;
        }
        void setEstado(bool e){estado=e;}

        ///gets
        int getIdInterprete(){return idInterprete;}
        const char *getNombre(){return nombre;}
        int getNacionalidad(){return nacionalidad;}
        int getTipoInterprete(){return tipoInterprete;}
        int getGenero(){return genero;}
        Fecha getFechaInicio(){return fechaInicio;}
        bool getEstado(){return estado;}

};

bool Interprete::Cargar(){
    idInterprete=contadorID();
    cout<<"el id es: "<<idInterprete<<endl;
    cout<<"NOMBRE DEl INTERPRETE: ";
    cargarCadena(nombre,29);//tamanio -1 al usar cargarCadena();
    cout<<"NACIONALIDAD: ";
    int nac;
    cin>>nac;
    if(!setNacionalidad(nac))return false;
    cout<<"TIPO DE INTERPRETE: ";
    int tip;
    cin>>tip;
    if(!setTipoInterprete(tip))return false;
    cout<<"GENERO MUSICAL DE 1 AL "<<contadorDeGeneros()<<": ";
    int gen;
    cin>>gen;
    if(!setGenero(gen))return false;
    cout<<"FECHA DE INICIO: ";
    fechaInicio.Cargar();
    if(!fechavalida(fechaInicio.getDia(),fechaInicio.getMes(),fechaInicio.getAnio())){
        cout<<"fecha invalida"<<endl;
    return false;
    }
    estado=true;
    return true;
}

void Interprete::Mostrar(){
    cout<<"el id es: "<<idInterprete<<endl;
    cout<<"NOMBRE DEl INTERPRETE: "<<nombre<<endl;
    cout<<"NACIONALIDAD: "<<nacionalidad<<endl;
    cout<<"TIPO DE INTERPRETE: "<<tipoInterprete<<endl;
    cout<<"GENERO: "<<genero<<endl;
    fechaInicio.Mostrar();
    cout<<endl;
}

int Interprete::contadorID()
{
    Interprete obj;
    int pos=0;
    while(obj.leerDeDisco(pos))
        {
            pos++;
        }
    return pos;
}


bool Interprete::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(INTERPRETES,"rb");
    if(p==NULL) return false;
    fseek(p, pos *sizeof(Interprete),0);//nos posicionamos donde queremos leer
    bool leyo=fread(this, sizeof (Interprete),1,p);//lee el registro
    fclose(p);
    return leyo;
}

bool Interprete::leerDeDiscoBkp(int pos)
{
    FILE *p;
    p=fopen("interprete.bkp","rb");
    if(p==NULL) return false;
    fseek(p, pos *sizeof(Interprete),0);//nos posicionamos donde queremos leer
    bool leyo=fread(this, sizeof (Interprete),1,p);//lee el registro
    fclose(p);
    return leyo;
}
#endif // CLASEINTERPRETE_H_INCLUDED

