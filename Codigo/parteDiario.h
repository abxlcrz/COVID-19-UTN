bool LeerParteDiario(PARTE& temp)
{
    assert(file.is_open());

    file.get(temp.nombre, 11);
    file >> temp.mes;
    file.ignore(3);
    file >> temp.hisopados;
    file >> temp.infectados;
    file >> temp.recuperados;
    file >> temp.fallecidos;
    file.ignore();

    return file.good();
}


void ProcesarParte()
{
    ushort counter = 0;
    PARTE temp;

    while(LeerParteDiario(temp))
    {
        InsertarEnOrden(temp, counter, partes);
        counter++;
    };
    numberPartes = counter;


    PARTE anual[12];
    ushort i = 0;
    ushort k;
    bool key =  false;
    do
    {
        k = partes[i].mes;

        if(i == 0)
        {
            for(ushort iter = 0; iter < 12; iter++)
            {
                anual[iter].mes =  0;
                anual[iter].hisopados = 0;
                anual[iter].infectados = 0;
                anual[iter].recuperados = 0;
                anual[iter].fallecidos = 0;
            }
        }

        if(strcmp(partes[i].nombre, partes[i - 1].nombre) != 0 && key)
        {
            // registrar los datos de los partes en anual
            // no registrar los que tengan mes igual a 0
            // reiniciar anual[12]

            for(ushort iter = 0; iter < 12; iter++)
            {
                if(anual[iter].mes  != 0)
                {
                    cout << "Nombre: " << anual[iter].nombre << "\n";
                    cout << "Mes: " << anual[iter].mes << "\n";
                    cout << "Cantidad hisopados: "  << anual[iter].hisopados << "\n";
                    cout << "Cantidad infectados: "  << anual[iter].infectados << "\n";
                    cout << "Cantidad recuperados: "  << anual[iter].recuperados << "\n";
                    cout << "Cantidad fallecidos: "  << anual[iter].fallecidos << "\n";

                    anual[iter].mes = 0;
                    anual[iter].hisopados = 0;
                    anual[iter].infectados = 0;
                    anual[iter].recuperados = 0;
                    anual[iter].fallecidos = 0;
                }
            }
            key = false;
        }

        strcpy(anual[k].nombre, partes[i].nombre);

        anual[k].mes = k;
        anual[k].hisopados += partes[i].hisopados;
        anual[k].infectados += partes[i].infectados;
        anual[k].recuperados += partes[i].recuperados;
        anual[k].fallecidos += partes[i].fallecidos;

        i++;
        key = true;

    }while(i < counter);
}
