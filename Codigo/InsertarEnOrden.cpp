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
