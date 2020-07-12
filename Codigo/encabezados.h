#define MAX_PAISES 200
using namespace std;
typedef unsigned int uint;
typedef unsigned short ushort;

struct PAIS
{
    char nombre[21];
    char continente[11];
    uint habitantes;
};

struct PARTE
{
    char nombre[21];
    ushort mes;
    ushort dia;
    ushort hisopados;
    ushort infectados;
    ushort recuperdados;
    ushort fallecidos;
};

enum PARAM
{
    HISOPADOS,
    INFECTADOS,
    RECUPERADOS,
    FALLECIDOS
};