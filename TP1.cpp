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
typedef char str10[11];

struct Pais{
    str20 Nombre;
    str10 Continente;
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

template <typename T>

void sortArray(T array[], int length){
    bool sort = false;
    while (!sort){
        sort = true;
        for (int i = 0; i < length-1; i++){
            if (array[i] > array[i + 1]){
                T aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
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
//NO CAMBIAR!!!
bool readFileCountries(ifstream &fileCountry, Pais &p){
    
    fileCountry.get(p.Nombre, sizeof(p.Nombre));
    fileCountry.ignore();
    fileCountry.get(p.Continente, sizeof(p.Continente));
    fileCountry >> p.Habitantes;
    cout<<boolalpha<<fileCountry.good();
    return fileCountry.good();
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
    countries.open("Paises.txt");
    //ifstream report(PART_DIA);
    ofstream exit("exit.txt");
    Pais tpais;
    while(readFileCountries(countries, tpais)){
        cout << tpais.Nombre;
        cout << tpais.Continente;
        cout << tpais.Habitantes << endl;
    }
    countries.close();
}
