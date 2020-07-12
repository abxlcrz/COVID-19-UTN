template<typename T>
void Intercambiar(T& elem1, T& elem2)
{
    T temp;

    temp = elem1;
    elem1 = elem2;
    elem2 = temp;
}
