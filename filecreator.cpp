// Este codigo deberia servir para compilar un .exe que permita ingresar datos por consola y imprimirlos en "Paises.txt" y "ParteDiario.txt" 


#include <iostream>
#include <string>
#include<fstream>

// #define variables para funcion "std::string CalculateSpaces(const std::string& buffer, PARAMETROS type)"
#define SIZE_NOMBRE = 20
#define SIZE_CONTINENTE = 10
#define SIZE_HABITANTES = 9
#define SIZE_FECHA = 9
#define SIZE_CANTIDAD = 9


// Stream de archivo global
std::fstream file;

enum PARAMETROS
{
	NOMBRE,
	CONTINENTE,
	HABITANTES,
	FECHA,
	CANTIDAD
};

void OpenFile(std::fstream& file, std::string nameFile) 	// Funcion para abrir un archivo 
{
	 file.open(nameFile, std::fstream::out | std::fstream::app);

	 if(!file.is_open())
	 {
	 	std::cout << "Error.\n\n";
	 }
	 
}

void CloseFile(std::fstream& file)	// Funcion para verrar un archivo
{
	file.close();
}

std::string CalculateSpaces(const std::string& buffer, PARAMETROS type) // Funcion para calcular la cantidad de espacios que sobran, devuelve un string con espacios
{
	int spaces;
	std::string strSpaces;

	switch(type)
	{
		case 0:
			spaces = SIZE_NOMBRE - buffer.size();
			break;
		case 1:
			spaces = SIZE_CONTINENTE - buffer.size();
			break;
		case 2:
			spaces = SIZE_HABITANTES - buffer.size();
			break;
		case 3:
			spaces = FECHA - buffer.size();
			break;
		case 4:
			spaces = SIZE_CANTIDAD - buffer.size();
			break;
		default:
			std::cout << "Error.\n";
			break;
	}
	
	for(int i = 0; i < spaces; i++)
		strSpaces.push_back(' ');

	return strSpaces;
}



void PrintFile(std::fstream& file,const std::string& buffer, PARAMETROS type)	// Funcion para imprimir en un archivo
{
	switch(type)
	{
		case 0:
			file << buffer + CalculateSpaces(buffer, type) + " ";
			file.flush();
			//file << CalculateSpaces(buffer, type);
			break;
		case 1:
			file << buffer + CalculateSpaces(buffer, type) + " ";
			file.flush();
			//file << CalculateSpaces(buffer, type);
			break;
		case 2:
			file << CalculateSpaces(buffer, type) + buffer + " ";
			file.flush();
			//file << buffer;
		case 3:
			file << CalculateSpaces(buffer, type) + buffer + " ";
			file.flush();
			//file << buffer;
		case 4:
			file << CalculateSpaces(buffer, type) + buffer + " ";
			file.flush();
			//file << buffer;
			break;
		default:
			std::cout << "Error.\n";
			break;
	}
} // Hay mucho codigo redundante aca



void ImprimirPais()
{
	OpenFile(file, "Paises.txt");
	std::string buffer;

	std::cout << "Ingrese el nombre del pais: ";
	std::cin >> buffer;
	PrintFile(file, buffer, NOMBRE);

	std::cout << "Ingrese el continente del pais: ";
	std::cin >> buffer;
	PrintFile(file, buffer, CONTINENTE);

	std::cout << "Ingrese la cantidad de habitantes del pais: ";
	std::cin >> buffer;
	PrintFile(file, buffer, HABITANTES);

	file << '\n';

	CloseFile(file);
}

void ImprimirParte()
{
	OpenFile(file, "ParteDiario.txt");
	std::string buffer;

	std::cout << "Ingrese el nombre del pais: ";
	std::cin >> buffer;
	PrintFile(file, buffer, NOMBRE);

	std::cout << "Ingrese el mes: ";
	std::cin >> buffer;
	PrintFile(file, buffer, FECHA);

	std::cout << "Ingrese el dia: ";
	std::cin >> buffer;
	PrintFile(file, buffer, FECHA);

	std::cout << "Ingrese la cantidad de hisopados: ";
	std::cin >> buffer;
	PrintFile(file, buffer, CANTIDAD);

	std::cout << "Ingrese la cantidad de infectados: ";
	std::cin >> buffer;
	PrintFile(file, buffer, CANTIDAD);

	std::cout << "Ingrese la cantidad de recuperados: ";
	std::cin >> buffer;
	PrintFile(file, buffer, CANTIDAD);

	std::cout << "Ingrese la cantidad de fallecidos: ";
	std::cin >> buffer;
	PrintFile(file, buffer, CANTIDAD);

	file << '\n';

	CloseFile(file);
}



int main()
{
	int key;
	
	do
	{
		std::cout << "\n\n0 -\tCerrar programa.\n";
		std::cout << "1 -\tIngresar datos de pais.\n";
		std::cout << "2 -\tIngresar datos del parte diario.\n";

		std::cout << "\nPor favor elija una opcion: ";

		std::cin >> key;

		switch(key)
		{
			case 0:
				break;
			case 1:
				ImprimirPais();
				break;
			case 2:
				ImprimirParte()
				break;
		}

	}while(key != 0 || key < 0 || key > 2);
	

	
	
	return 0;
}
