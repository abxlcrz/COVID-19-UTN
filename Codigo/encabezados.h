#define MAX_PAISES 200
using namespace std;
typedef unsigned int uint;
typedef unsigned short ushort;

struct PAIS
{
    char nombre[21];
    uint habitantes;
};

struct PARTE
{
    char nombre[15];
    ushort mes;
    ushort hisopados;
    ushort infectados;
    ushort recuperados;
    ushort fallecidos;
};

struct PARTE_PROCESADO
{
    char nombre[20];
    ushort mes[12];
    int hisopados[12];
    int infectados[12];
    int recuperados[12];
    int fallecidos[12];
};

enum PARAM
{
    HISOPADOS,
    INFECTADOS,
    RECUPERADOS,
    FALLECIDOS
};

PAIS paises[MAX_PAISES];
PARTE partes[MAX_PAISES * 12];
PARTE_PROCESADO parteProcesados[MAX_PAISES];
fstream file;
ushort numberPaises = 0;
ushort numberPartes = 0;
