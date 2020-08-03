////////////////////////////////////
//
// INCLUIR LIBRERIAS NECESARIAS
//
////////////////////////////////////
#include <cassert>
#include <fstream>
#include <cstring>
#include <iomanip>

////////////////////////////////////
//
// DEFINICIONES GLOBLALES y TYPEDF UTILIZADOS
//
////////////////////////////////////
using namespace std;

#define MAX_PAIS 200

typedef unsigned int uint;
typedef unsigned short ushort;

int cantidadPaises;

////////////////////////////////////
//
// ESTRUCTURAS DE DATOS A UTILIZAR
//
////////////////////////////////////

struct tsPais {
	char nombre[21];
	//char continente[11];
	uint habitantes;
};

struct tsParDia {
	char nombre[21];
	ushort mes;
	ushort dia;
	ushort cantHisopados;
	ushort cantInfectados;
	ushort cantRecuperados;
	ushort cantFallecidos;
};

struct tsCalc {
	char nombre[21];
	uint habitantes;
	uint cantHisopados[13];
	uint cantInfectados[13];
	uint cantRecuperados[13];
	uint cantFallecidos[13];
};


tsPais paises[MAX_PAIS];
tsParDia partes[MAX_PAIS * 12];
tsCalc tvrPais[MAX_PAIS];

////////////////////////////////////
//
// FUNCIONES
//
////////////////////////////////////

template<typename T>
void intercambiar(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}


template<typename T>
void insertarOrden(T& temp, int size, T array[])
{
	while (size > 0 && strcmp(temp.nombre, array[size - 1].nombre) < 0)
	{
		intercambiar(array[size - 1], array[size]);
		size--;
	};

	array[size] = temp;
}

// funciones de paises
bool leerPaises(tsPais& pais, fstream& file) {
	file.get(pais.nombre, 21);
	file.ignore(10);
	file >> pais.habitantes;
	file.ignore();
	return file.good();
}

void procesarPaises() {
	int counter = 0;
	tsPais temp;

	fstream file("Paises.txt", ios::in);

	while (leerPaises(temp, file)) {
		insertarOrden(temp, counter, paises);
		counter++;
	};

	cantidadPaises = counter;
}

// funciones del parte
bool leerParte(tsParDia& parte, fstream& file) {
	file.get(parte.nombre, 21);
	file >> parte.mes >> parte.dia >> parte.cantHisopados >> parte.cantInfectados >> parte.cantRecuperados  >> parte.cantFallecidos;
	file.ignore();
	return file.good();
}

void procesarPartes() {
	int counter = 0;
	tsParDia temp;

	fstream file("ParteDiario.txt", ios::in);

	while (leerParte(temp, file)) {
		insertarOrden(temp, counter, partes);
		counter++;
	}

	
	bool key = false;
	int j = 0;

	for (int i = 0; i < counter; i++) {
		if (key && i > 0) {		// si key == TRUE, imprime el nombre del pais
			strcpy_s(tvrPais[j].nombre, partes[i - 1].nombre);
			tvrPais[j].habitantes = paises[j].habitantes;
			j++;
			key = false;
		}

		tsCalc* calc = &tvrPais[j];
		tsParDia& part = partes[i];

		calc->cantHisopados[part.mes] += part.cantHisopados;
		calc->cantHisopados[0] += part.cantHisopados;

		calc->cantInfectados[part.mes] += part.cantInfectados;
		calc->cantInfectados[0] += part.cantInfectados;

		calc->cantRecuperados[part.mes] += part.cantRecuperados;
		calc->cantRecuperados[0] += part.cantRecuperados;

		calc->cantFallecidos[part.mes] += part.cantFallecidos;
		calc->cantFallecidos[0] += part.cantFallecidos;
		
		key = strcmp(partes[i].nombre, partes[i + 1].nombre) != 0;		// si el nombre del siguiente parte es diferente, key se vuelve TRUE
	}
}

// funciones del listado
template<typename T>
string detectarEspacios(int size, T value = 0, char* str = NULL, const char space = ' ') {		// calcula cantidad de  espacio, en funcion de la cantidad devuelven un c-string lleno de caracteres
	char buffer[21];
	if (str == NULL) {
		_itoa_s(value, buffer, _countof(buffer), 10);
	}
	else {
		strcpy_s(buffer, str);
	}
	
	string finalString;
	int cantEspacios = size - strlen(buffer);
	int i = 0;
	
	for (; i < cantEspacios; i++) {
		finalString.push_back(space);
	}
	
	return finalString;
}

void generarListado(tsCalc datos[MAX_PAIS], const char* nombreArchivo, int param) {
	fstream output(nombreArchivo, fstream::out);

	output << "\t\t\t\tListado de " << nombreArchivo << "\n\n";

	output << "Num. " << "Nombre               ";
	output << "Cant.Hab.    ";
	output << "--------------------------------------------------------";
	output << " Meses ";
	output << "-------------------------------------------------------- ";
	output << "Cant.       Porcentajes\n\n";

	output << "Ord. " << "Pais                 ";
	output << "             ";
	output << "Ene.      Feb.      Mar.      Abr.      May.      Jun.      Jul.      Ago.      Sep.      Oct.      Nov.      Dic.      ";
	output << "        Total        \n\n";

	int cantFilasDatos = cantidadPaises >= 10 ? 10 : cantidadPaises;		// si la cantidad de paises procesados >= 10, entonces, imprimir 10 filas de datos, de otra forma solo la cantidad de paises disponibles
	for (int i = 0; i < cantFilasDatos; i++) {
		tsCalc& elem = datos[i];		// referencia al registro utilizado en la iteracion actual 
		uint* parametro = elem.cantHisopados + 13 * param;		// referencia al array de datos que se desea imprimir en texto

		output << detectarEspacios(4, i + 1) << i + 1 << " ";
		output << elem.nombre << detectarEspacios(20, 0, elem.nombre) << " ";
		output << detectarEspacios(12, elem.habitantes) << elem.habitantes << " ";
		
		for (int j = 1; j < 13; j++) {		// imprime los datos de los meses Ene-Dic
			output << detectarEspacios(9, parametro[j]) << parametro[j] << " ";
		}
		output << detectarEspacios(12, parametro[0]) << parametro[0] << " ";	// imprime el total anual
		
		float porcentaje = (static_cast<float>(parametro[0]) / elem.habitantes) * 100;
		output << detectarEspacios(6, porcentaje) << setprecision(2) << fixed << porcentaje  << "%" << "\n";	// imprime el porcentaje
	}

	output.close();
}

// funciones de algoritmo de ordenamiento
bool compare(tsCalc& a, tsCalc& b, int param) {		// funcion encargada de comparar los registros de acuerdo al parametro que reciba
	switch (param) {
	case 0:
		return a.cantHisopados[0] <= b.cantHisopados[0];
	case 1:
		return a.cantInfectados[0] <= b.cantInfectados[0];
	case 2:
		return a.cantRecuperados[0] <= b.cantRecuperados[0];
	case 3:
		return a.cantFallecidos[0] <= b.cantFallecidos[0];
	}
}

void shellSort(int size, tsCalc* array, int param) {
	tsCalc temp;
	int i = 0; int k = 0;
	int seq = 1;

	while (seq <= size / 3) {
		seq = seq * 3 + 1;
	}

	while (seq > 0) {
		for (k = seq; k < size; k++) {
			temp = array[k];
			i = k;

			while (i > seq - 1 && compare(array[i - seq], temp, param)) {
				array[i] = array[i - seq];
				i -= seq;
			}

			array[i] = temp;
		}

		seq = (seq - 1) / 3;
	}
}

////////////////////////////////////
//
// MAIN
//
////////////////////////////////////
int main() {
	procesarPaises();
	procesarPartes();
	shellSort(cantidadPaises, tvrPais, 0);
	generarListado(tvrPais, "Hisopados.txt", 0);

	shellSort(cantidadPaises, tvrPais, 1);
	generarListado(tvrPais, "Infectados.txt", 1);

	shellSort(cantidadPaises, tvrPais, 2);
	generarListado(tvrPais, "Recuperados.txt", 2);

	shellSort(cantidadPaises, tvrPais, 3);
	generarListado(tvrPais, "Fallecidos.txt", 3);

	return 0;
}
