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

void ImprimirPartesProcesados(PARTE_PROCESADO p[])
{
    for(int i = 0; i < numberPaises; i++)
    {
        cout << "Nombre de pais: " << p[i].nombre << "\n\n";

        for(int j = 0; j < 12; j++)
        {
            cout << "Datos del mes: " << j+1 << "\n";
            cout << "Cantidad de hisopados: " << p[i].hisopados[j] << "\n";
            cout << "Cantidad de infectados: " << p[i].infectados[j] << "\n";
            cout << "Cantidad de recuperados: " << p[i].recuperados[j] << "\n";
            cout << "Cantidad de fallecidos: " << p[i].fallecidos[j] << "\n\n";
        }
    }


}

int main()
{
    AbrirArchivo("Paises.txt", file);
    ProcesarPaises();
    CerrarArchivo(file);

	AbrirArchivo("ParteDiario.txt", file);
	ProcesarParte();
	CerrarArchivo(file);



    ImprimirPartes(partes);

    cout << "\n\n";

    ImprimirPartesProcesados(parteProcesados);

 	return 0;
}
