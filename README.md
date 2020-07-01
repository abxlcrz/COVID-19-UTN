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

