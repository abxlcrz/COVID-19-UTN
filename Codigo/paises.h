bool LeerPaises(tsPais& pais)
{


    file.get(pais.nombre, 21);
    file.ignore(10);
    file >> pais.habitantes;
    file.ignore();




    return file.good();
}


void ProcesarPaises()   // funcion incompleta
{
    ushort counter = 0;
    tsPais temp;


    while(LeerPaises(temp))
    {
        InsertarEnOrden(temp, counter, paises);
        counter++;
    };

    numberPaises = counter;
}
