#include <iostream>
#include <string>
#include<fstream>

// Stream de archivo global
std::fstream file;

enum PARAMETROS
{
	NOMBRE,
	CONTINENTE,
	HABITANTES
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
			spaces = 20 - buffer.size();
			break;
		case 1:
			spaces = 10 - buffer.size();
			break;
		case 2:
			spaces = 9 - buffer.size();
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
			file << buffer + CalculateSpaces(buffer, type);
			file.flush();
			//file << CalculateSpaces(buffer, type);
			break;
		case 1:
			file << buffer + CalculateSpaces(buffer, type);
			file.flush();
			//file << CalculateSpaces(buffer, type);
			break;
		case 2:
			file << CalculateSpaces(buffer, type) + buffer;
			file.flush();
			//file << buffer;
			break;
	}
}


////////////////////////////
///
///NOTAS: Falta agregar un espacio entre cada cadena de texto
///
///////////////////////////


void ImprimirPais()
{
	OpenFile(file, "paises.txt");
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


	CloseFile(file);
}





int main()
{
	int key;

	do
	{
		std::cout << "0 -\tCerrar programa.\n";
		std::cout << "1 -\tIngresar datos de pais.\n";
		std::cout << "\nPor favor elija una opcion: ";

		std::cin >> key;

		switch(key)
		{
			case 0:
				break;
			case 1:
				ImprimirPais();
				break;
		}

	}while(key != 0 || key < 0 || key > 1);


	
	
	return 0;
}

