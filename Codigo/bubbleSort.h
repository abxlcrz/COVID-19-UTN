void BubbleSort(PARAM param, int size)
{
    int counter = 0;
    bool key = true;


    for(int k = size - 1; k > 0; k--)
    {
        for(int i = 0 ; i < k; i++)
        {
            if(parteProcesados[i].hisopados[12] < parteProcesados[i + 1].hisopados[12])
            {
                key = false;
                Intercambiar(parteProcesados[i], parteProcesados[i + 1]);
            }

            counter++;
        }
        if(key)
            break;
        key = true;
    }
    cout << "Iteraciones de BubbleSort: " << counter;
}


void Shellsort(PARAM param, int size)
{
    PARTE_PROCESADO temp;
    int i = 0;
    int k = 0;
    int seq = 1;
    int counter = 0;
    int secCounter = 0;

    void* ptr = NULL;

    while(seq <= size / 3)
    {
        seq = seq * 3 + 1;
    };

    while(seq > 0)
    {
        for(k = seq; k < size; k++)
        {
            temp = parteProcesados[k];
            i = k;

            while(i > seq - 1 && parteProcesados[i - seq].hisopados[12] <= temp.hisopados[12])
            {
                parteProcesados[i] = parteProcesados[i - seq];
                i -= seq;
                counter++;
            };

            parteProcesados[i] = temp;
            secCounter++;
        };

        seq = (seq - 1) / 3;
    };

    cout << "Numero de iteraciones: " << counter << "\n";
    cout << "Numero de iteraciones: " << secCounter << "\n";
}




output << " " << printWS(contarNumero(i+1), 3) << i+1;
        output << " " << p[i].nombre << printWS(strlen(p[i].nombre), 20);
        output << " " << printWS(contarNumero(p[i].habitantes), 9) << p[i].habitantes;

        output << " " << printWS(contarNumero(p[i].hisopados[0]), 9) << p[i].hisopados[0];
        output << " " << printWS(contarNumero(p[i].hisopados[1]), 9) << p[i].hisopados[1];
        output << " " << printWS(contarNumero(p[i].hisopados[2]), 9) << p[i].hisopados[2];
        output << " " << printWS(contarNumero(p[i].hisopados[3]), 9) << p[i].hisopados[3];

        output << " " << printWS(contarNumero(p[i].hisopados[4]), 9) << p[i].hisopados[4];
        output << " " << printWS(contarNumero(p[i].hisopados[5]), 9) << p[i].hisopados[5];
        output << " " << printWS(contarNumero(p[i].hisopados[6]), 9) << p[i].hisopados[6];
        output << " " << printWS(contarNumero(p[i].hisopados[7]), 9) << p[i].hisopados[7];

        output << " " << printWS(contarNumero(p[i].hisopados[8]), 9) << p[i].hisopados[8];
        output << " " << printWS(contarNumero(p[i].hisopados[9]), 9) << p[i].hisopados[9];
        output << " " << printWS(contarNumero(p[i].hisopados[10]), 9) << p[i].hisopados[10];
        output << " " << printWS(contarNumero(p[i].hisopados[11]), 9) << p[i].hisopados[11];

        output << " " << printWS(contarNumero(p[i].hisopados[12]), 9) << p[i].hisopados[12];
        float porcentaje = (static_cast<float>(p[i].hisopados[12]) / p[i].habitantes) * 100;
        output << " " << printWS(contarNumero(porcentaje + 3), 10) << setprecision(1) << porcentaje << "%";

        output << "\n";
