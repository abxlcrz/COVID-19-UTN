void Intercambiar(PAIS& pais1, PAIS& pais2)
{
    PAIS temp;

    temp = pais1;
    pais1 = pais2;
    pais2 = temp;
}


void Intercambiar(PARTE& parte1, PARTE& parte2)
{
    PARTE temp;

    temp = parte1;
    parte1 = parte2;
    parte2 = temp;
}


template<typename T>
void Intercambiar(T& elem1, T& elem2)
{
    T temp;

    temp = elem1;
    elem1 = elem2;
    elem2 = temp;
}
