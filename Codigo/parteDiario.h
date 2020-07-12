bool LeerParteDiario(PARTE& temp)
{
    assert(file.is_open());

    file >> temp.nombre;
    file >> temp.mes;
    file >> temp.dia;
    file >> temp.hisopados;
    file >> temp.infectados;
    file >> temp.recuperadados;
    file >> temp.fallecidos;

    return file.good();
}


void ProcesarParte()
{
    int counter = 0;
    PARTE temp;

    while(LeerParteDiario(temp))
    {
        ImprimirParte(temp);
    };
}
