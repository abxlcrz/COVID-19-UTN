## Trabajo Práctico 1 : Metodología-DP-ECP-Módulos-ED: Registros y Arreglos. 

Se requiere de un proceso que obtenga los Cálculos de casos de CoronaV-19. Se establece una cantidad máxima de paises, indicada por la constante con nombre MAX_PAIS = 200. 

Para ello, se cuenta con 2 archivos de datos (de texto), ambos sin orden, a saber: 

* Paises.txt: conteniendo una lista de paises, cuyo formato de registro consta con los siguientes campos:  

1.a) Nombre del país cad20), 1.b) Continente (cad10), 1.c) Cantidad de habitantes (entero s/sgn.) Cantidad de paises menor o igual (<=) a MAX_PAIS. 

* ParteDiario.txt: 2.a) Nombre del país, 2.b) Mes (1..12), 2.c) Día (1..31), 2.d) Cantidad de Hisopados, Cantidad de Infectados, Cantidad de Recuperados, Cantidad de Fallecidos; todos entero corto s/sgn.. Ud. debe seleccionar como organizar de la forma más conveniente a estos datos. 

Se cuenta con el bloque principal, solo se establecen las invocaciones a los módulos, ud. deberá declarar las variables pertenecientes a este módulo, reemplazar los nombres indicados en los argumentos por nombres de identificadores representativos o con significado para su propósito: 

```cpp
     main() { 

    //declare ud. las variables de esta función y su inicialización, si corresponde. 

    Abrir (Paises, ParteDiario); 

    freopen(nomFisArchivo, modo, stdin); 

    ProcPaises(argumentos…);  

    ProcParteDiario(argumentos…);  

    Listado(argumentos…);               // dentro del módulo listado debe existir un  

    …                                              // freopen(nomFisArchivo, modo, stdout); 

    freopen(“CON”, modo, stdin);     // para abrir y luego cerrar el archivo de texto. 

    Cerrar (Paises, ParteDiario); 

    return 0; 

} //main 
```

A continuación se aportan ideas para realizar el Algoritmo y su codificación:  

La función ``` bool LeerPaises(argumentos…)```, el cual lee una componente de datos del archivo y los almacena en una estructura interna. La función retorna un boolean, verdadero, si la lectura fue exitosa, caso contrario, falso. 

La función ```void ProcParteDiario(argumentos…)```, en donde se deberán procesar los informes recibidos del día para computarlos en una estructura de datos interna y estática. Ud. deberá determinar los argumentos a pasar al módulo. 

La función ```void Listado(argumentos…)```, debe salir ordenado descendente por: 

* Cantidad de Hisopados. 

* Cantidad de Víctimas Infectadas. 

* Cantidad de Víctimas Mortales. 

* Cantidad de Víctimas Recuperadas. 

```bash
                              Listado de X(11) 

Nro. Nom.          Cant.Hab.     ------------- Cantidades de X(11) por mes ------------   Cant.   Porcentajes 

Ord. País                                Ene      Feb     Mar      Abr     May      Jun       Jul     Tot.                 

    1   X(20)      9999999999   99999   99999   99999   99999   99999   99999   99999  999999     999.99 

    2 

  … 

  10 
```

Cantidad total de X(11) a la fecha actual: 999999 

Porcentaje de X(11)………….…..………:  999.99 

 

Los listados serán destinados a un archivo en disco, con el nombre de “ListadoXxx.Txt”, formateado con títulos y con los resultados obtenidos. Hay espacio suficiente para generar estos archivos. Xxx reemplazarlo por lo que representa el nombre del listado: Hisopados,o Infectados, o Fallecidos o Recuperados, según corresponda. 

Observaciones, restricciones y recursos disponibles: 

Utilizar las siguientes funciones, invocando en donde sea necesario: 

```cpp 
void OrdxBur(tbl, card); 

void IntCmb(elem1, elem2); 

void InsertaEnOrden(Tbl, elem, card); 

void LeerParteDiario(argumentos… ); idem a LeerPaises(argumentos…); 
```

Espacio en disco: Solo para generar los archivos de los listados en formato texto. 

Espacio para arreglos: Lo necesario que requiera este proyecto. 

Espacio en memoria dinámica: 0 bytes. 

Accesos a los archivos: un solo recorrido secuencial, para leer a cada uno de ellos. 

Bloque Principal: sólo invocaciones a módulos, según lo establecido anteriormente. 

Optimización: dado que el uso de ciclos afecta el tiempo de ejecución de un proceso, se evaluará la eficiencia en el uso de los mismos. 

Utilizar nombres significativos para los identificadores, dibujos para las estructuras de datos a utilizar, rotulando cada elemento, tamaño, breve leyenda de cómo se generan y estado inicial, respetar esos nombres para utilizarlos en el algoritmo. Preparar una muestra de datos para los archivos de datos e imprimirla, para ejecutar el programa. 

En el disco solo contendrán los archivos “TP1.CPP”,  y los archivos de datos “Paises.Txt” y “ParteDiario.Txt” (ambos de texto), ubicados en el directorio raíz de la unidad. 

Cada grupo debe crear su propia muestra de datos para los archivos. 

La cantidad máxima de paises está establecida al inicio de este documento. 

Se deben utilizar constantes con nombres para indicar estas cantidades. 

La muestra de datos para Paises.Txt no debe ser menor a veinte (20) paises, además debe registrarse por cada renglón los datos de un país, sin títulos, solo debe tener los datos, items indicados en la sección de archivos. 

##=============================   Documentación   =============================
En éste archivo se mostraran los detalles sobre el desarrollo de la solución del tp 
covid-19.

## Problematica

Basicamente el problema consiste en  calcular la cantidad de infectados en base a una 
serie de datos,dichos datos  están en 2 archivos de texto. Estos ficheros están cargados 
por un lado el nombre del pais y sus habitantes, por otro lado está el
archivo con el parte diario, donde informa los datos respecto al covid.
Además de éso se pide ordenarlos para poder obtener el top 10 de:

*Infectados
*Hisopados
*Muertos
*Recuperados

Finalmente, el algoritmo tiene que ordenarlos para poder crear un archivo de texto por
cada top.
Damos por sentado que al tratar con datos mayores, tenemos que ordenarlos de forma 
descendente.

## Algoritmo

Para el desarrollo del algoritmo se eligó como estrategia los siguientes procedimientos:

=============== Posibles templates ===============
Un template es una "plantilla" la cual nos permite tener una funcion generica ( recibe cualquier tipo), 
de esta forma podemos reutilizar la funcion para varios casos de uso.
Por ejemplo, podemos trabajar con estructuras, enteros,caracteres, etc.

De esta forma, obtendremos las siguientes funciones con tipos parametrizados:

writeFile() =>El cual se encarga de crear y escribir un archivo nuevo,los campos son parametrizados.
              Es decir, le pasamos un puntero que haga referencia al campo de un struct PartDiarioProcesado,
              de esta manera, podemos pasarle
sortArray() =>Posee  un algoritmo de ordenamiento, quick sort, trabaja con  un array de X tipo.



##  Funciones

========Primer etapa========

La primer etapa consta de inicializar variables, apertura, lectura de archivos y almacenamiento en memoria.

openFiles()=> Se encarga de abrir los ficheros necesarios para el funcionamiento del algoritmo.

getCountries()=> Esta función implementa las funciones open file, readFile  loadArray y sortArray:

        readFile();
        loadArray();
        sortArray();

getDailyPart()=> implementa las mismas funciones anteriormente mencionadas:

        readFile();
        loadArray();
        sortArray();


========Segunda etapa========

En la  segunda etapa  se obtienen los totales de infectados por pais, y se obtienen los top10 por
los 4 casos de covid (infectados,Recuperados,Muertos e Hisopados).

        writeListedArray()
        getTotal();

========Tercer etapa========
Finalmente, la ultima etapa solamente va a emitir el listado en sus respectivos ficheros.
Entendemos que se tienen que crear 4 archivos para cada parametro.

        writeFiles()
        closeFiles()

## Structs 

la primer estructura está definida por los siguientes identificadores y campos:
```cpp
struct Pais {
        str20 Nombre;       //21 bytes
        uint  habitantes;   //4 bytes
};

siendo un total de 25 bytes por estructura.
un array de tipo pais contendrá 5000 bytes = 25*200 elementos.
```

La segunda, que hace referencia al parte diario se conforma de la siguiente manera:
ushort => val max es de 65535

```cpp
struct ParteDiario {
        str20   Nombre;             //21 bytes
        ushort  Mes;                //4 bytes
        ushort  CantHisopados;      //4 bytes
        ushort  CantInfectados;     //4 bytes
        ushort  CantRecuperados;    //4 bytes
        ushort  CantFallecidos;     //4 bytes                        
};
41 bytes para la 2da estructura
```
```cpp
struct PartDiarioProcesado{
        str20   Nombre;              //21 bytes
        ushort  Mes[7];              //14 bytes
        uint  CantHisopados[8];      //32 bytes
        uint  CantInfectados[8];     //32 bytes
        uint  CantRecuperados[8];    //32 bytes
        uint  CantFallecidos[8];     //32 bytes
} 163 bytes por cada instancia
```

 ============================== ATENCION ==============================

Hay que arreglar el formato, estoy con arquitectura asi que lo arreglo más tarde ahre
no se alinean los floats como quiero, debe ser una boludez 


 ## Templates


Un template es una funcion generica, es decir, puede trabajar con cualquier tipo de dato.
De esta forma nos ahorramos codigo trivial, que tiene una meta en comun con otras 
funciones, solamente difieren del tipo.Podemos decir que recibimos como parametro el tipo
de dato de los argumentos que recibimos,ésto nos da la posibilidad de tener un código reutilizable.

Esta función recibe como parametros 2 variables de tipo T, solamente se encarga de intercambiar los valores de los mismos.
```cpp
template <typename T> void swapValues(T &x, T&y){
    T aux=x;
    x=y;
    y=aux;
}
```

Ejemplo de una función de ordenamiento implementando el algoritmo quicksort, recibe como parametro
un array de tipo T, una función que retorna un tipo K y recibe como parametro un tipo T.
```cpp
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
}}

```

## Complejidad temporal  

Como se sabe, un buena solucion además de tener legibilidad tiene que ser eficiente y eficaz.
En esta solución se trató de ahorrar espacio en memoria para poder procesar los datos.

A continuación se muestra la notación asintótica de las siguientes funciones:

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DISCLAIMER (ahre)

la notacion asintotica representa de forma matematica digamos, al tiempo que tarda en ejecutarse cierto codigo.
esto se representa en funcion de n, donde n es el tamaño de un dato, en este caso, arrays.
Por ej: si tenemos un array de 200 elementos y aplicamos bubble sort nuestro tiempo de ejecución es de O(n^2),
        es decir 200^2=40.000
        Este numero no tiene una unidad, es una representación para x computadora, es decir, es una constante que se aplica 
        a cualquier dispositivo, obviamente dependiendo del hardware, arquitectura y demás va a tardar más o meno,es una especie 
        de medida universal.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


## logaritmica  
quickSort=> Tiene un coste de tiempo O(log n), esto quiere decir que a medida que la entrada sea de 
            mayor tamaño aumentaran las comparaciones e intercambios, pero de una manera logaritmica.

## Cuadratica

insertionSort=>Posee un coste temporal de O(n^2), en otras palabras a medida que tengamos una entrada
               de mayor tamaño, aumentarán las comparaciones e intercambios a realizar en funcion de n.
               Lo mismo aplica para las funciones writeFile() y almacenarParteDiario()
