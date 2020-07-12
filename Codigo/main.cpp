#include <fstream.h>
#include <iostream.h>
#include <cstring.h>
#include <cassert.h>


#include "encabezados.h"
#include "intercambiar.h"
#include "insertar.h"
#include "shellSort.h"
#include "archivos.h"
#include "paises.h"
#include "parteDiario.h"




int main()
{
	AbrirArchivo("Paises.txt", file);
	ProcesarPaises();
	CerrarArchivo(file);

	AbrirArchivo("ParteDiario.txt", file);
	ProcesarParte();
	CerrarArchivo(file);

 	return 0;
}
