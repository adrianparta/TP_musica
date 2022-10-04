#ifndef CLASECANCION_H_INCLUDED
#define CLASECANCION_H_INCLUDED

/*
----RESTRICCIONES----
El ID de canción no debe repetirse en el archivo.
El ID de intérprete debe existir en el archivo de intérpretes.
La fecha debe ser una fecha válida, y anterior o igual a la fecha actual.
El estado debe ser verdadero para que el sistema utilice el registro.
La duración tiene que ser un valor positivo.
El género musical debe ser un valor entero entre 1 y 10.
*/

class Cancion
{
    private:
        int idCancion;
        char nombre[30];
        char nombreAutor[30];//autor o compositor
        int idInterprete;
        Fecha fechaEstreno;
        bool estado;
        float duracionCancion;//en minutos
        int genero;// 1 a 10
        int contadorID();
    public:
        void Cargar();
        void Mostrar();
        bool leerDeDisco(int pos);
        bool leerDeDiscoBkp(int pos);
        void setFechaEstreno(){
            fechaEstreno.Cargar();
        }
        ///sets
        void setIdCancion(int id){idCancion=id;}
        void setNombre(const char *nom){strcpy(nombre,nom);}
        void setNombreAutor(const char *nomAutor){strcpy(nombreAutor,nomAutor);}
        void setIdInterprete(int idInt){
            if(existeInterprete(idInt)){
                idInterprete=idInt;
            }
        }
        bool setGenero(int gen){
            if(gen>0 && gen<contadorDeGeneros()+1){
                genero=gen;
                return true;
            }
            cout<<"numero invalido"<<endl;
            return false;
        }
        //void setFecha
        void setEstado(bool e){estado=e;}
        bool setDuracionCancion(float dc)
        {
            if(dc>0)
            {
                duracionCancion=dc;
                return true;
            }
            cout<<"duracion negativa"<<endl;
            return false;
        }
        ///gets
        int getIdCancion(){return idCancion;}
        const char *getNombre(){return nombre;}
        const char *getNombreAutor(){return nombreAutor;}
        int getIdInterprete(){return idInterprete;}
        //Fecha getFecha
        bool getEstado(){return estado;}
        float getDuracionCancion(){return duracionCancion;}
        int getGenero(){return genero;}
};


void Cancion::Cargar(){
    idCancion=contadorID();
    cout<<"el id es: "<<idCancion<<endl;
    cout<<"NOMBRE DE CANCION: ";
    cargarCadena(nombre,29);//tamanio -1 al usar cargarCadena();
    cout<<"NOMBRE DE AUTOR: ";
    cargarCadena(nombreAutor,29);
    cout<<"INTERPRETE: ";
    int i;
    cin>>i;
    if(!existeInterprete(i)){
        cout<<"no existe ese interprete"<<endl;
        system("pause");
        return;
    }
    setIdInterprete(i);
    cout<<"FECHA DE ESTRENO: ";
    fechaEstreno.Cargar();
    if(!fechavalida(fechaEstreno.getDia(),fechaEstreno.getMes(),fechaEstreno.getAnio())){
        cout<<"fecha invalida"<<endl;
        system("pause");
        return;
    }
    cout<<"DURACION DE LA CANCION EN MINUTOS: ";
    int duracion;
    cin>>duracion;
    if(!setDuracionCancion(duracion))return;
    cout<<"GENERO MUSICAL DE 1 AL "<<contadorDeGeneros()<<": ";
    int gen;
    cin>>gen;
    if(!setGenero(gen))return;
    estado=true;
    cout<<"cancion agregada correctamente"<<endl;
    system("pause");
    return;
    }

void Cancion::Mostrar()
{
    cout<<"ID CANCION: "<<idCancion<<endl;
    cout<<"NOMBRE DE CANCION: "<<nombre<<endl;
    cout<<"NOMBRE DE AUTOR: "<<nombreAutor<<endl;
    cout<<"INTERPRETE: "<<idInterprete<<endl;
    cout<<"FECHA DE ESTRENO: ";
    fechaEstreno.Mostrar();
    cout<<"DURACION DE LA CANCION EN MINUTOS: "<<duracionCancion<<endl;
    cout<<"GENERO: "<<genero<<endl;
}

int Cancion::contadorID()
{
    Cancion obj;
    int pos=0;
    while(obj.leerDeDisco(pos))
        {
            pos++;
        }
    return pos;
}

bool Cancion::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(CANCIONES,"rb");
    if(p==NULL) return false;
    fseek(p, pos *sizeof(Cancion),0);//nos posicionamos donde queremos leer
    bool leyo=fread(this, sizeof (Cancion),1,p);//lee el registro
    fclose(p);
    return leyo;
}

bool Cancion::leerDeDiscoBkp(int pos)
{
    FILE *p;
    p=fopen("cancion.bkp","rb");
    if(p==NULL) return false;
    fseek(p, pos *sizeof(Cancion),0);//nos posicionamos donde queremos leer
    bool leyo=fread(this, sizeof (Cancion),1,p);//lee el registro
    fclose(p);
    return leyo;
}
#endif // CLASECANCION_H_INCLUDED

