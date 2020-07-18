void Shellsort(PARAM param, int size)
{
    PARTE_PROCESADO temp;
    int i = 0;
    int k = 0;
    int seq = 1;
    int counter = 0;
    int secCounter = 0;

    int* ptr1;
    int* ptr2;

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
            ptr1 = (&(temp.hisopados[12])) + param * 13;
            ptr2 = (&(parteProcesados[i - seq].hisopados[12])) + param * 13;

            while(i > seq - 1 && *(ptr2) <= *(ptr1))
            {
                parteProcesados[i] = parteProcesados[i - seq];
                i -= seq;
                counter++;
                ptr2 = (&(parteProcesados[i - seq].hisopados[12])) + param * 13;
            };

            parteProcesados[i] = temp;
            secCounter++;
        };

        seq = (seq - 1) / 3;
    };

    cout << "Numero de iteraciones: " << counter << "\n";
    cout << "Numero de iteraciones: " << secCounter << "\n";
}
