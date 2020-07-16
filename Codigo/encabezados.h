#define MAX_PAISES 200
using namespace std;
typedef unsigned int uint;
typedef unsigned short ushort;

struct tsPais
{
    char nombre[21];
    uint habitantes;
};

struct tsParDia
{
    char nombre[21];
    ushort mes;
    ushort hisopados;
    ushort infectados;
    ushort recuperados;
    ushort fallecidos;
};

enum PARAM
{
    HISOPADOS,
    INFECTADOS,
    RECUPERADOS,
    FALLECIDOS
};

tsPais paises[MAX_PAISES];
tsParDia partes[MAX_PAISES * 12];
fstream file;
ushort numberPaises = 0;
ushort numberPartes = 0;
