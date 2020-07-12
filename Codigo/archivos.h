#include <fstream>
#include <cassert>

using namespace std;


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
