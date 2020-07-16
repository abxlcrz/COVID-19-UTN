#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>

#define MAX_PAISES 200
#define PAISES "Paises.txt"
#define PART_DIA "ParteDiario.txt"

using namespace std;

typedef unsigned int uint;
typedef unsigned short ushort;
typedef char str20[21];

struct Pais{
    str20 Nombre;
    uint Habitantes;
};

struct ParteDiario{
    str20 Nombre;
    ushort Mes;
    ushort CantHisopados;
    ushort CantInfectados;
    ushort CantRecuperados;
    ushort CantFallecidos;
};

template<typename T>
void swap(T& elem1, T& elem2){
    T temp;

    temp = elem1;
    elem1 = elem2;
    elem2 = temp;
}

template <typename T>

void sortArray(T array[], int length){
    bool sort = false;
    while (!sort){
        sort = true;
        for (int i = 0; i < length-1; i++){
            if (array[i] > array[i + 1]){
                swap(array[i],array[i + 1]);
                sort = false;
            }
        }
    }
}

int binarySearch(int array[], int right, int item){
    int index = -1,
        left = 0;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (array[mid] == item)index = mid;
        if (array[mid] < item)left = mid + 1;
        else right = mid - 1;
    }
    return index;
}

bool readFileCountries(ifstream &fileCountry, Pais &p){
    
    fileCountry.get(p.Nombre, sizeof(p.Nombre));
    fileCountry.ignore(10);
    fileCountry >> p.Habitantes;
    fileCountry.ignore();
    return fileCountry.good();
}

bool readFileDailyPart(ifstream &dailyPart, ParteDiario &p){
    
    dailyPart.get(p.Nombre, sizeof(p.Nombre));
    dailyPart >> p.Mes;
    dailyPart.ignore(2);
    dailyPart >> p.CantHisopados;
    dailyPart >> p.CantInfectados;
    dailyPart >> p.CantRecuperados;
    dailyPart >> p.CantFallecidos;
    dailyPart.ignore();
    return dailyPart.good();
}

// int loadArray(Pais array[],Pais pais){
//     static int i=0;
//     array[i].Nombre=pais.Nombre;
//     array[i].Habitantes=pais.Habitantes;
//     i++;
//     return i;
// }

int main(){
    ifstream countries;
    ifstream report(PART_DIA);
    ofstream exit("exit.txt");
    countries.open(PAISES);
    Pais tpais;
    while(readFileCountries(countries, tpais)){
        exit << tpais.Nombre;
        exit << tpais.Habitantes << endl;
    }
    countries.close();
    exit.close();
}
