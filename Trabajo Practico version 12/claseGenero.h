#ifndef CLASEGENERO_H_INCLUDED
#define CLASEGENERO_H_INCLUDED

class Genero{
    private:
    int idGenero;
    char nombre[40];
    int pais;
    int tipoInstrumentacion;
    bool estado;
    int contadorId();

    public:
    cargar();
    mostrar();
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
        if(tipo>0 && <6){
            tipoInstrumentacion=tipo;
            return true;
        }
        cout<<"numero invalido"<<endl;
        return false;
    }
    void setEstado(bool e){estado=bool;}
    ///FIN SETS
    ///GETS
    int getIdGenero(){return idGenero;}
    const char *getNombre(){return nombre;}
    int getPais(){return pais;}
    int getTipoInstrumentacion(){return tipoInstrumentacion;}
    bool getEstado(){return estado;}
    ///FIN GETS
}

void Genero::cargar(){
}


#endif // CLASEGENERO_H_INCLUDED
