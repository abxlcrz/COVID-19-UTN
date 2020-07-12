bool LeerPaises(PAIS& temp)
{
    assert(file.is_open());

    file >> temp.nombre;
    file >> temp.continente;
    file >> temp.habitantes;

    return  file.good();
}


void ProcesarPaises()   // funcion incompleta
{
    int counter = 0;
    PAIS temp;
    
    while(LeerPaises())
    {
        paises[counter] = temp;

        counter++;
    };
}
