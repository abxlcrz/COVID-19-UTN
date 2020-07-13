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

    PARTE vacio = { "", 0, 0, 0, 0, 0 };
    PARTE anual[12];
    ushort i = 0;
    ushort k;
    bool key = false;

    for(ushort iter = 0; iter < 12; iter++)
        anual[iter] = vacio;

    do
    {
        k = partes[i].mes;

        if(key)
        {
            cout << "Diferente\n";
            cout << "Imprimir datos actuales:\n";

            for(ushort iter = 0; iter < 12; iter++)
            {
                if(anual[iter].mes != 0)
                {
                    cout << "Nombre de pais: " << anual[iter].nombre << "\n";
                    cout << "Mes: " << anual[iter].mes << "\n";
                    cout << "Hisopados: " << anual[iter].hisopados << "\n";
                    cout << "Infectados: " << anual[iter].infectados << "\n";
                    cout << "Recuperados: " << anual[iter].recuperados << "\n";
                    cout << "Fallecidos: " << anual[iter].fallecidos << "\n\n";

                    anual[iter] = vacio;
                }
            }
        }
        else
        {
            cout << "Igual\n";
        }
        strcpy(anual[k].nombre, partes[i].nombre);
        anual[k].mes = partes[i].mes;
        anual[k].hisopados += partes[i].hisopados;
        anual[k].infectados += partes[i].infectados;
        anual[k].recuperados += partes[i].recuperados;
        anual[k].fallecidos += partes[i].fallecidos;

        key = !(strcmp(partes[i].nombre, partes[i + 1].nombre) == 0);
        i++;
    }while(i < counter + 1);


}
