// Este codigo deberia servir para compilar un .exe que permita ingresar datos por consola y imprimirlos en "Paises.txt" y "ParteDiario.txt" 

#include <iostream>
#include <string>
#include<fstream>

// #define
#define SIZE_NOMBRE 20
#define SIZE_CONTINENTE 10
#define SIZE_HABITANTES 9
#define SIZE_FECHA 9
#define SIZE_CANTIDAD 6


// Stream de archivo global
std::fstream file;

enum PARAMETROS		// lista enumerada de 0 hasta 4, se utiliza en los switches.
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



bool SizeErrorHandle(const std::string& buffer, PARAMETROS type)
{
	switch(type)
	{
		case 0:
			if(buffer.size() <= SIZE_NOMBRE)
				return true;
			break;
		case 1:
			if(buffer.size() <= SIZE_CONTINENTE)
				return true;
			break;
		case 2:
			if(buffer.size() <= SIZE_HABITANTES)
				return true;
			break;
		case 3:
			if(buffer.size() <= SIZE_FECHA)
				return true;
			break;
		case 4:
			if(buffer.size() <= SIZE_CANTIDAD)
				return true;
			break;
	}

	return false;	// si buffer ocupa mas que  el espacio asignado retorna falso
}

void AskForData(const std::string ask, std::string& buffer, PARAMETROS type)
{
	do
	{
		std::cout << ask;
		std::cin >> buffer;
	}while(!SizeErrorHandle(buffer, type));
} // pide informacion al usuario hasta que se ingrese correctamente



void PrintFile(std::fstream& file,const std::string& buffer, PARAMETROS type)	// Funcion para imprimir en un archivo, utiliza un parametro para 
{										// seleccionar la forma de imprimir datos
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
			break;
		case 3:
			file << buffer + " ";
			file.flush();
			//file << buffer;
			break;
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

	AskForData("Ingrese el nombre del pais: ", buffer, NOMBRE);
	PrintFile(file, buffer, NOMBRE);

	AskForData("Ingrese el continente del pais: ", buffer, CONTINENTE);
	PrintFile(file, buffer, CONTINENTE);

	AskForData("Ingrese la cantidad de habitantes del pais: ", buffer, HABITANTES);
	PrintFile(file, buffer, HABITANTES);

	buffer.clear();
	file.flush();

	file << '\n';

	CloseFile(file);
}

void ImprimirParte()
{
	OpenFile(file, "ParteDiario.txt");
	std::string buffer;

	AskForData("Ingrese el nombre del pais: ", buffer, NOMBRE);
	PrintFile(file, buffer, NOMBRE);

	AskForData("Ingrese el mes: ", buffer, FECHA);
	PrintFile(file, buffer, FECHA);

	AskForData("Ingrese el dia: ", buffer, FECHA);
	PrintFile(file, buffer, FECHA);

	AskForData("Ingrese la cantidad de hisopados: ", buffer, CANTIDAD);
	PrintFile(file, buffer, CANTIDAD);

	AskForData("Ingrese la cantidad de infectados: ", buffer, CANTIDAD);
	PrintFile(file, buffer, CANTIDAD);

	AskForData("Ingrese la cantidad de recuperados: ", buffer, CANTIDAD);
	PrintFile(file, buffer, CANTIDAD);

	AskForData("Ingrese la cantidad de fallecidos: ", buffer, CANTIDAD);
	PrintFile(file, buffer, CANTIDAD);

	buffer.clear();
	file.flush();

	file << '\n';

	CloseFile(file);
}



int main()
{
	int key;
	
	do			// ciclo principal del programa. despliega un menu, el cual no termina hasta el usuario elija la opcion "0"
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
				ImprimirParte();
				break;
		}

	}while(key != 0 || key < 0 || key > 2);
	

	
	
	return 0;
}
