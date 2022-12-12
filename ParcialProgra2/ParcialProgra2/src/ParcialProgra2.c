/*
 ============================================================================
 Name        : ParcialProgra2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int id;
	char nombre[20];
	char tipo[20];
	int edad;
	float altura;
}eMascota;

eMascota* masc_new();
eMascota* masc_newParam();
int masc_setId(eMascota* this,int id);
int masc_getId(eMascota* this,int* id);
int masc_setNombre(eMascota* this,char* nombre);
int masc_getNombre(eMascota* this,char* nombre);
int masc_setTipo(eMascota* this,char* tipo);
int masc_getTipo(eMascota* this,char* tipo);
int masc_setEdad(eMascota* this,int edad);
int masc_getEdad(eMascota* this,int* edad);
int masc_setAltura(eMascota* this,float altura);
int masc_getAltura(eMascota* this,float* altura);
int controller_guardarMascotasModoTexto();
int controller_guardarMascotasModoBinario();
int main(void) {
	setbuf(stdout,NULL);

	controller_guardarMascotasModoTexto();
	controller_guardarMascotasModoBinario();
	return EXIT_SUCCESS;
}


int masc_setId(eMascota* this,int id)
{
    int todoOk = 0;

    if(this != NULL && id >= 1)
    {
    	this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int masc_getId(eMascota* this,int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int masc_setNombre(eMascota* this,char* nombre)
{
	int todoOk=0;


	if(this!=NULL && strlen(nombre)<20)
	{

		strcpy(this->nombre,nombre);
		todoOk=1;
	}
	return todoOk;
}

int masc_getNombre(eMascota* this,char* nombre)
{
	int todoOk=0;
	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk=1;
	}
	return todoOk;
}

int masc_setTipo(eMascota* this,char* tipo)
{
	int todoOk=0;


	if(this!=NULL && strlen(tipo)<20)
	{

		strcpy(this->tipo,tipo);
		todoOk=1;
	}
	return todoOk;
}

int masc_getTipo(eMascota* this,char* tipo)
{
	int todoOk=0;
	if(this!=NULL && tipo)
	{
		strcpy(tipo,this->tipo);
		todoOk=1;
	}
	return todoOk;
}

int masc_setEdad(eMascota* this,int edad)
{
    int todoOk = 0;

    if(this != NULL)
    {
    	this->edad = edad;
        todoOk = 1;
    }
    return todoOk;
}

int masc_getEdad(eMascota* this,int* edad)
{
    int todoOk = 0;

    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        todoOk = 1;
    }
    return todoOk;
}


int masc_setAltura(eMascota* this,float altura)
{
    int todoOk = 0;

    if(this != NULL)
    {
    	this->altura = altura;
        todoOk = 1;
    }
    return todoOk;
}

int masc_getAltura(eMascota* this,float* altura)
{
    int todoOk = 0;

    if(this != NULL && altura != NULL)
    {
        *altura = this->altura;
        todoOk = 1;
    }
    return todoOk;
}

eMascota* masc_new()
{
	eMascota* mascota = (eMascota*) malloc(sizeof(eMascota));
		if(mascota!=NULL)
		{
			mascota->id=0;
			*(mascota->nombre)='\0';
			*(mascota->tipo)='\0';
			mascota->edad=0;
			mascota->altura=0;
		}

		return mascota;
}

eMascota* masc_newParam(char* id,char* nombre, char*tipo , char* edad,char* altura)
{
	eMascota* mascota = masc_new();
	if(mascota!=NULL)
	{
		if(!(masc_setNombre(mascota, nombre) &&
				masc_setTipo(mascota, tipo) &&
				masc_setId(mascota, atoi(id)) &&
				masc_setAltura(mascota, atof(altura)) &&
				masc_setEdad(mascota, atoi(edad))))
		{
			free(mascota);
			mascota=NULL;
		}
	}
	return mascota;
}


 int controller_guardarMascotasModoTexto()
{
    int todoOk=0;
    int id;
    char nombre[20];
    char tipo[20];
    int edad;
    float altura;
    eMascota* m=NULL;
    m=masc_newParam("01", "Panchito", "Gato", "10","0.75");
    FILE* f= fopen("archivo.csv","w");

    if(f!=NULL)
    {
        masc_getId(m, &id);
        masc_getNombre(m, nombre);
        masc_getTipo(m, tipo);
        masc_getEdad(m, &edad);
        masc_getAltura(m, &altura);
        fprintf(f,"%d,%s,%s,%d,%f\n",id,nombre,tipo,edad,altura);
        todoOk=1;
    }
    fclose(f);
    return todoOk;

}

int controller_guardarMascotasModoBinario()
{
    int todoOk=0;
    eMascota* m=NULL;

    FILE* f = fopen("archivo.bin","wb");

    if(f!=NULL)
    {

        m=masc_newParam("01", "Panchito", "Gato", "10","0.75");
        fwrite(m,sizeof(eMascota),1,f);
        todoOk=1;

    }
    fclose(f);
    return todoOk;
}



