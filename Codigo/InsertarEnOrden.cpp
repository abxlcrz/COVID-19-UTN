void InsertarEnOrden(PAIS& temp,int size, PAIS paises[]) // pais solo nombre
{
    int i = 0;

    for(; i < size; i++)
    {
        if(strcmp(temp.nombre, paises[i].nombre) < 0)
            break;
    }
    int k = size;

    for(; i < k; k--)
    {
        Intercambiar(paises[k], paises[k - 1]);
    }

    paises[i] = temp;
}


void InsertarEnOrden(PARTE& temp, int size, PARTE partes[]) // parte solo mes
{
    int i = 0;

    for(; i < size; i++)
    {
        if(temp.mes < partes[i].mes)
            break;
    }
    int k = size;

    for(; i < k; k--)
    {
        Intercambiar(partes[k], partes[k - 1]);
    }

    partes[i] = temp;
}

template<typename T>
void InsertarEnOrden(T& temp, int size, T array[])  // sirve tanto para Paises como para Parte, solo ordena por nombre
{
    int i = 0;

    for(; i < size; i++)
    {
        if(strcmp(temp.nombre, array[i].nombre) > 0)
            break;
    }
    int k = size;

    for(; i < k; k--)
    {
        Intercambiar(array[k], array[k - 1]);
    }

    array[i] = temp;
}


enum PARAM
{
    NOMBRE,
    MES
};

void InsertarEnOrder(PARTE& temp, int size, PARAM param) // solo funciona para el Parte, permite eligir el parametro de insercion 
{
    int i = 0;
    int k = size;

    switch(param)
    {
    case 0:
        for(; i < size; i++)
        {
            if(strcmp(temp.nombre, partes[i].nombre) < 0)
                break;
        }


        for(; i < k; k--)
        {
            Intercambiar(partes[k], partes[k - 1]);
        }

        partes[i] = temp;
        break;

    case 1:
        for(; i < size; i++)
        {
            if(temp.mes <= partes[i].mes)
                break;
        }


        for(; i < k; k--)
        {
            Intercambiar(partes[k], partes[k - 1]);
        }

        partes[i] = temp;
        break;
    }
}
