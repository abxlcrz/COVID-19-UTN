

template<typename T>
void InsertarEnOrden(T& temp, int size, T array[])
{
    while(size > 0 && strcmp(temp.nombre, array[size - 1].nombre) < 0)
    {
      Intercambiar(array[size - 1], array[size]);
      size--;
    };

    array[size] = temp;
}




