#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED
//PROTOTIPOS
void cargarCadena(char *pal, int tam);
bool fechavalida(int dia, int mes, int anio);
//FIN PROTOTIPOS
void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

class Fecha
{
    private:
        int dia, mes, anio;
    public:
        void Cargar();
        void Mostrar();
        //sets
        void setDia(int d){
            dia=d;}
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        //gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

void Fecha::Cargar()
{
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;


}

void Fecha::Mostrar()
{
    cout<<"FECHA: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

bool fechavalida(int dia, int mes, int anio){
    int anioActual=2022;
    if(dia<1 || dia>31) return false;
    else if (mes<1 || mes>12) return false;
    else switch(mes)
    {
        case 4: case 6: case 9: case 11:
            if(dia>30) return false;
            break;
        case 2:
            if (dia>28)return false;
            break;
    }
    if (anio>anioActual)return false;
    if(anio<anioActual)return true;
    return false;
}

#endif // FUNCIONESGLOBALES_H_INCLUDED

