template<typename T>
int contarNumero(T n)
{
    int i = 0;
    do
    {
        n /= 10;
        i++;
    } while(n > 0);
    return i;
}

char* printWS(int size, int maxSize)
{
    char whiteS[21];
    int i = 0;
    for(;  size + i < maxSize; i++)
    {
        whiteS[i] = ' ';
    }
    whiteS[i] = '\0';

    return whiteS;
}




void imprimirListado(const char nombreArchivo[20],PARAM param)
{
    fstream output(nombreArchivo, fstream::out);


    output << "\t\t\t\tListado de " << nombreArchivo << "\n\n";

    output << "Num. " << "Nombre               ";
    output << "Cant.Hab. ";
    output << "--------------------------------------------------------";
    output << " Meses ";
    output << "-------------------------------------------------------- ";
    output << "Cant.     Porcentajes\n\n";

    output << "Ord. " << "Pais                 ";
    output << "          ";
    output << "Ene.      Feb.      Mar.      Abr.      May.      Jun.      Jul.      Ago.      Sep.      Oct.      Nov.      Dic.      ";
    output << "        Total        \n\n";


    int* p;
    for(int i = 0; i < 10; i++)
    {
        p = parteProcesados[i].hisopados + 13 * param;

        output << " " << printWS(contarNumero(i+1), 3) << i+1;
        output << " " << parteProcesados[i].nombre << printWS(strlen(parteProcesados[i].nombre), 20);
        output << " " << printWS(contarNumero(parteProcesados[i].habitantes), 9) << parteProcesados[i].habitantes;

        output << " " << printWS(contarNumero(p[0]), 9) << p[0];
        output << " " << printWS(contarNumero(p[1]), 9) << p[1];
        output << " " << printWS(contarNumero(p[2]), 9) << p[2];
        output << " " << printWS(contarNumero(p[3]), 9) << p[3];

        output << " " << printWS(contarNumero(p[4]), 9) << p[4];
        output << " " << printWS(contarNumero(p[5]), 9) << p[5];
        output << " " << printWS(contarNumero(p[6]), 9) << p[6];
        output << " " << printWS(contarNumero(p[7]), 9) << p[7];

        output << " " << printWS(contarNumero(p[8]), 9) << p[8];
        output << " " << printWS(contarNumero(p[9]), 9) << p[9];
        output << " " << printWS(contarNumero(p[10]), 9) << p[10];
        output << " " << printWS(contarNumero(p[11]), 9) << p[11];

        output << " " << printWS(contarNumero(p[12]), 9) << p[12];
        float porcentaje = (static_cast<float>(p[12]) / parteProcesados[i].habitantes) * 100;
        output << " " << printWS(contarNumero(porcentaje + 3), 10) << setprecision(2) << porcentaje << "%";

        output << "\n";
    }
}

void Listado()
{
    Shellsort(HISOPADOS, numberPaises);
    imprimirListado("Hisopados.txt",HISOPADOS);

    Shellsort(INFECTADOS, numberPaises);
    imprimirListado("Infectados.txt",INFECTADOS);

    Shellsort(RECUPERADOS, numberPaises);
    imprimirListado("Recuperados.txt",RECUPERADOS);

    Shellsort(FALLECIDOS, numberPaises);
    imprimirListado("Fallecidos.txt",FALLECIDOS);
}
