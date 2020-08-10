#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#define MAX_PAISES 200
#define PAISES_PATH "Paises.txt"
#define PARTE_PATH "ParteDiario.txt"

using namespace std;

typedef unsigned int uint;
typedef unsigned short ushort;
typedef char str20[21];

/*Structs*/
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
    uint Mes[7];
    uint CantHisopados[8];
    uint CantInfectados[8];
    uint CantRecuperados[8];
    uint CantFallecidos[8];
};

/*Templates*/
template <typename T> void swapValues(T &x, T&y){
    T aux=x;
    x=y;
    y=aux;
}

template <typename T,typename K> void quickSort(T array[],K setParam(T),short left,short right){
    short i,j,pivot;
    if(left<right){
        pivot=left;
        i=left;
        j=right;

        while(i<j){
            while(setParam(array[i])[7]>=setParam(array[pivot])[7] && i<right) i++;

            while(setParam(array[j])[7]<setParam(array[pivot])[7]) j--;

            if(i<j) swapValues<T>(array[i],array[j]);
        }
        swapValues<T>(array[pivot],array[j]);
        quickSort(array,setParam,left,j-1);
        quickSort(array,setParam,j+1,right);
    }
}

void insertionSort(Pais array[], Pais value, int i){
    while(i>0 && strcmp(value.Nombre , array[i-1].Nombre)<0){
        swapValues(array[i],array[i-1]);
        i=i-1;
    }
    array[i]=value;
    
}

short binarySearch(Pais array[], short right, str20 item){
    short index = -1,
        left = 0;
    while (left <= right){
        short mid = left + (right - left) / 2;
        if (strcmp(array[mid].Nombre,item)==0)index = mid;
        if (strcmp(array[mid].Nombre,item)<0)left = mid + 1;
        else right = mid - 1;
    }
    return index;
}
/*Parametrizacion del template, se le indica con una funcion por qué */
uint* setHisopados( ParteDiarioAlmacenado p){
        static uint x[8];
    for(short i=0;i<=7;i++)
        x[i]=p.CantInfectados[i];
    return x;
}

uint* setInfectados( ParteDiarioAlmacenado p){
    static uint x[8];
    for(short i=0;i<=7;i++)
        x[i]=p.CantInfectados[i];
    return x;
}

uint* setFallecidos( ParteDiarioAlmacenado p){
    static uint x[8];
    for(short i=0;i<=7;i++)
        x[i]=p.CantInfectados[i];
    return x;
}

uint* setRecuperados( ParteDiarioAlmacenado p){
    static uint x[8];
    for(short i=0;i<=7;i++)
        x[i]=p.CantInfectados[i];
    return x;
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

void loadCountriesArray(ifstream &file,Pais array[],short &len){
    
    Pais readLine;
    while (readFileCountries(file,readLine)&&len!=200){
        insertionSort(array,readLine,len);
        len++;
    }
}

void initArray(ParteDiarioAlmacenado array[], int len){
    for (ushort i = 0; i < len; i++){
        for(ushort j = 0; j <= 7; j++){
            array[i].Mes[j]=0;
            array[i].CantHisopados[j]=0;
            array[i].CantInfectados[j]=0;
            array[i].CantRecuperados[j]=0;
            array[i].CantFallecidos[j]=0;
        }
    }
}
//borrar!
short search(ParteDiarioAlmacenado array[],short len, ParteDiario part){
            for (int i = 0; i < len; i++)
                if(strcmp(array[i].Nombre,part.Nombre)==0)return i;
                  
            return-1;
}
//REFACTOR!
void loadDailyPartArray(ifstream &file,ParteDiarioAlmacenado array[],short i ){
    initArray(array,i);
    ParteDiario readLine;
    short len=0;
    while (readFileDailyPart(file,readLine)){
        int index=readLine.Mes-1;
        short position=search(array,len,readLine);// aplicar busqueda binaria
        if(position<0){ // si no se encuentra el pais se asigna el nuevo pais en la posicion len (largo logico)
            strcpy(array[len].Nombre,readLine.Nombre);
            array[len].Mes[index]=readLine.Mes;
            array[len].CantHisopados[index]=readLine.CantHisopados;
            array[len].CantInfectados[index]=readLine.CantInfectados;
            array[len].CantRecuperados[index]=readLine.CantRecuperados;
            array[len].CantFallecidos[index]=readLine.CantFallecidos;
            //acumulo el total
            array[len].CantHisopados[7]=readLine.CantHisopados;
            array[len].CantInfectados[7]=readLine.CantInfectados;
            array[len].CantRecuperados[7]=readLine.CantRecuperados;
            array[len].CantFallecidos[7]=readLine.CantFallecidos;
            len++;
        } else{// caso contrario, se actualizan los datos
                array[position].Mes[index]=readLine.Mes;
                array[position].CantHisopados[index]+=readLine.CantHisopados;
                array[position].CantInfectados[index]+=readLine.CantInfectados;
                array[position].CantRecuperados[index]+=readLine.CantRecuperados;
                array[position].CantFallecidos[index]+=readLine.CantFallecidos;
                //acumulo el total
                array[position].CantHisopados[7]+=readLine.CantHisopados;
                array[position].CantInfectados[7]+=readLine.CantInfectados;
                array[position].CantRecuperados[7]+=readLine.CantRecuperados;
                array[position].CantFallecidos[7]+=readLine.CantFallecidos;
        }       
    }
}

void openFiles(ifstream &countries, ifstream &report){
    countries.open(PAISES_PATH);
    report.open(PARTE_PATH);
}

void closeFiles(ifstream &countries, ifstream &report){
    countries.close();
    report.close();
}
string formatFile(char c,ushort n){
    string str="";
    for (ushort i = 0; i < n; i++)str+=c;
    return str;
}

void writeFile(ParteDiarioAlmacenado array[],Pais paises[],uint* param(ParteDiarioAlmacenado), string type, short len){
    
    ofstream exit(type+".txt");
    quickSort<ParteDiarioAlmacenado>(array,param,0,len);
    exit<<formatFile('=',117)<<endl;
    exit<<formatFile('=',48);
    exit<<"Listado de "<<type;
    exit<<formatFile('=',48)<<endl;
    exit<<formatFile('=',117)<<endl;
    exit<<" Nro. Nom "<<formatFile(' ',16)<<" Cant. Hab.  "<<formatFile('=',11)<<"Cantidades de "<<type<<" por mes"<<formatFile('=',11)<<"     Cant.  Porcentaje"<<endl;
    exit<<" Ord. Pais"<<formatFile(' ',30) <<"Enero  Febrero   Marzo   Abril   Mayo   Junio   Julio      Total"<<endl;
    uint acumHab=0,acumParam=0;
    for (short i = 0; i < 10; i++){
        exit<<setw(2)<<i+1<<"    ";
        exit<<setw(20)<<array[i].Nombre<<' ';
        short index=binarySearch(paises,len,array[i].Nombre); 
        exit<<right<<setw(10)<<paises[index].Habitantes<<" ";
        acumHab+=paises[index].Habitantes;
        for (short j = 0; j <7; j++){
            exit<<right<<setw(6)<<param(array[i])[j]<<"    ";
            acumParam+=param(array[i])[j];
        }
        exit<<right<<setw(4)<<"%"<<setprecision(2)<<(float)(100*param(array[i])[7])/paises[index].Habitantes<<' '<<endl;
    }
    exit<<endl;
    exit<<"Cantidad total de "<<setw(11)<<type <<"a la fecha actual: "<<acumParam<<endl;
    exit<<"Porcentaje de "<<setw(11)<<type <<": %"<<(float)(100*acumParam)/acumHab<<endl;
    exit.close();
}

void getResult(ParteDiarioAlmacenado array[],Pais paises[],short len){
    writeFile(array,paises,setFallecidos,"Fallecidos",len);
    writeFile(array,paises,setHisopados,"Hisopados",len);
    writeFile(array,paises,setInfectados,"Infectados",len);
    writeFile(array,paises,setRecuperados,"Recuperados",len);
}

int main(){

    short lenArray=0;
    ifstream countries,report;
    Pais pais[MAX_PAISES];
    ParteDiarioAlmacenado arrayPartDay[MAX_PAISES];
    openFiles(countries,report);
    loadCountriesArray(countries,pais,lenArray);
    loadDailyPartArray(report,arrayPartDay,lenArray);
    getResult(arrayPartDay,pais,lenArray);
    closeFiles(countries,report);
}