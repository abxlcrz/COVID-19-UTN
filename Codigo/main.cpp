#include <fstream.h>
#include <iostream.h>
#include <cstring.h>
#include <cassert.h>
#include <sstream.h>


#include "encabezados.h"
#include "intercambiar.h"
#include "insertar.h"
#include "shellSort.h"
#include "archivos.h"
#include "paises.h"
#include "parteDiario.h"


void ImprimirPaises(PAIS p[])
{
    for(int i = 0; i < numberPaises; i++)
    {
        cout << p[i].nombre << " " << p[i].habitantes << "\n";
    }
}

void ImprimirPartes(PARTE p[])
{
    for(int i = 0; i < numberPartes; i++)
    {
        cout << p[i].nombre << " " << p[i].mes << " " << p[i].hisopados << " " << p[i].infectados << " " << p[i].recuperados << " " << p[i].fallecidos << "\n";
    }
}



int main()
{
	AbrirArchivo("ParteDiario.txt", file);
	ProcesarParte();
	CerrarArchivo(file);

	cout << "\n\\n\n";

    ImprimirPartes(partes);
 	return 0;
}
