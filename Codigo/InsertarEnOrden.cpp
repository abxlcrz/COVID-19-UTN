void InsertarEnOrden(PAIS& temp,int size, PAIS paises[])
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


void InsertarEnOrden(PARTE& temp, int size, PARTE partes[])
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
