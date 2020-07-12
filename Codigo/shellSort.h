void Shellsort(PARAM param, int size)
{
    PARTE temp;
    int i = 0;
    int k = 0;
    int seq = 1;

    while(seq <= size / 3)
    {
        seq = seq * 3 + 1;
    };

    while(seq > 0)
    {
        for(k = seq; k < size; k++)
        {
            temp = partes[k];
            i = k;

            while(i > seq - 1 && *(&partes[i - seq].hisopados + param) <= *(&temp.hisopados + param))
            {
                partes[i] = partes[i - seq];
                i -= seq;
            };

            partes[i] = temp;
        };

        seq = (seq - 1) / 3;
    }
}
