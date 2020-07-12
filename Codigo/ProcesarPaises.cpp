#include <fstream.h>
#include <iostream.h>
#include <cassert.h>
#include <string.h>

#define MAX_PAISES 200
using namespace std;
typedef unsigned int uint;
typedef unsigned short ushort;

struct PAIS
{
    char nombre[21];
    char continente[11];
    uint habitantes;
};

struct PARTE
{
    char nombre[21];
    ushort mes;
    ushort dia;
    ushort hisopados;
    ushort infectados;
    ushort recuperdados;
    ushort fallecidos;
};

PAIS paises[MAX_PAISES];
PAIS temp;
fstream file;


void AbrirArchivo(const char fileName[21], fstream& file)
{
	assert(fileName != NULL); 	// la cadena de caracteres no apunta a nada.
	assert(!file.is_open());	// el archivo ya esta abierto o no existe en el directorio raiz.

	file.open(fileName, fstream::in);

	assert(file.is_open());		// el archivo no pudo abrise.
}


void CerrarArchivo(fstream& file)
{
	assert(file.is_open());		// el archivo que se quiere cerrar ya esta cerrado

	file.close();

	assert(!file.is_open());	// el archivo no pudo cerrarse
}


bool LeerPaises()
{
    assert(file.is_open());

    file >> temp.nombre;
    file >> temp.continente;
    file >> temp.habitantes;

    return  file.good();
}

void ImprimirPais(PAIS& pais);

void ProcesarPaises()
{
    int counter = 0;

    while(LeerPaises())
    {
        paises[counter] = temp;

        //ImprimirPais(paises[counter]);
        counter++;
    };
}

/////////////////////////////////////////
void ImprimirPais(PAIS& pais)
{
    cout << pais.nombre << " " << pais.continente << " " << pais.habitantes << "\n";
}
/////////////////////////////////////////
int main()
{
    AbrirArchivo("Paises.txt", file);
    ProcesarPaises();
    CerrarArchivo(file);
    return 0;
}
