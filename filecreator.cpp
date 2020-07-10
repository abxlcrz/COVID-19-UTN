#include <iostream>
#include <string>
#include<fstream>

enum PARAMETROS
{
	NOMBRE,
	CONTINENTE,
	HABITANTES
};

void OpenFile(std::string nameFile, std::fstream& file) 	// Funcion para abrir un archivo 
{
	 file.open(nameFile, std::fstream::out | std::fstream::app);

	 if(file.is_open())
	 {
	 	std::cout << "Archivo abierto exitosamente.\n\n";
	 }
	 else
	 {
	 	std::cout << "No se pudo abrir el archivo.\n\n";
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









int main()
{
	std::fstream file;
	OpenFile("paises.txt", file);
	

	std::string nombre = "Argentina";
	std::string continente = "America";
	std::string habitantes = "400";

	PrintFile(file, nombre, NOMBRE);
	PrintFile(file, continente, CONTINENTE);
	PrintFile(file, habitantes, HABITANTES);

	CloseFile(file);
	
	return 0;
}
