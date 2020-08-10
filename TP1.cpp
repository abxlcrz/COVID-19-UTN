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

struct ParteDiarioAlmacenado{
    str20 Nombre;
    uint Mes[12];
    uint CantHisopados[12];
    uint CantInfectados[12];
    uint CantRecuperados[12];
    uint CantFallecidos[12];
};

template<typename T>
void swap(T& elem1, T& elem2){
    T temp;

    temp = elem1;
    elem1 = elem2;
    elem2 = temp;
}

template <typename T>
void quickSort(T array[],int left, int right){
        int i,j,pivot;

        if(left<right){
            pivot=left;
            i=left;
            j=right;

            while(i<j){
                while(array[i]<=array[pivot] && i<right) i++;

                while(array[j]>array[pivot]) j--;

                if(i<j) swapString(array[i],array[j]);
            }

            swapString(array[pivot],array[j]);
            quickSort(array,left,j-1);
            quickSort(array,j+1,right);


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

void insertionSort(Pais array[], Pais value, int i){
    while(i>0 && value.Nombre < array[i-1].Nombre){
        array[i]=array[i-1];
        i=i-1; //i--
    }
    array[i]=value;
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
    dailyPart.ignore(3);
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