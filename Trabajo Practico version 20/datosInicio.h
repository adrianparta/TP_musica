#ifndef DATOSINICIO_H_INCLUDED
#define DATOSINICIO_H_INCLUDED

void establecerDatosInicio();
void establecerDatosCanciones();
void establecerDatosInterpretes();
void establecerDatosGeneros();

void establecerDatosInicio(){
    establecerDatosCanciones();
    establecerDatosInterpretes();
    establecerDatosGeneros();
}

void establecerDatosCanciones(){
    FILE *p;
    Cancion reg;
    int pos=0;
    p=fopen(CANCIONES,"wb");
    while(reg.leerInicio(pos++))
	{
		fwrite(&reg,sizeof reg,1,p);
	}
	fclose(p);
	cout<<"SE REALIZO LA RESTAURACION DEL ARCHIVO CORRECTAMENTE"<<endl;
	system("pause");
}

void establecerDatosInterpretes(){
    FILE *p;
    Interprete reg;
    int pos=0;
    p=fopen(INTERPRETES,"wb");
    while(reg.leerInicio(pos++))
	{
		fwrite(&reg,sizeof reg,1,p);
	}
	fclose(p);
	cout<<"SE REALIZO LA RESTAURACION DEL ARCHIVO CORRECTAMENTE"<<endl;
	system("pause");

}

void establecerDatosGeneros(){
    FILE *p;
    Genero reg;
    int pos=0;
    p=fopen(GENEROS,"wb");
    while(reg.leerInicio(pos++))
	{
		fwrite(&reg,sizeof reg,1,p);
	}
	fclose(p);
	cout<<"SE REALIZO LA RESTAURACION DEL ARCHIVO CORRECTAMENTE"<<endl;
	system("pause");
}


#endif // DATOSINICIO_H_INCLUDED
