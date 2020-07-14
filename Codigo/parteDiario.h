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
    ushort iter = 0;
    ushort newSize = 0;
    ushort k;
    bool key = false;

    for(ushort i = 0; i < 12; i++)
        anual[i] = vacio;

    do
    {
        k = partes[iter].mes;

        if(key)
        {
            //cout << "Diferente\n";
            //cout << "Imprimir datos actuales:\n";
            /*
            for(int i = newSize; i < i; i++)
            {
                partes[i] = vacio;
            }
            */
            for(ushort i = 0; i < 12; i++)
            {
                if(anual[i].mes != 0)               // utilizar solo anuales no vacios
                {
                    /*
                    cout << "Nombre de pais: " << anual[i].nombre << "\n";
                    cout << "Mes: " << anual[i].mes << "\n";
                    cout << "Hisopados: " << anual[i].hisopados << "\n";
                    cout << "Infectados: " << anual[i].infectados << "\n";
                    cout << "Recuperados: " << anual[i].recuperados << "\n";
                    cout << "Fallecidos: " << anual[i].fallecidos << "\n\n";
                    */
                    partes[newSize] = anual[i];     // remplaza el partes[newSize] por el anual[i]
                    newSize++;                      // incrementa el newSize.este sera el nuevo tamanio del array de partes al finalizar el proceso
                    anual[i] = vacio;               // limpia el anual[i] usado
                }
            }
        }
        else
        {
            //cout << "Igual\n";
        }

        // operar, suma los partes al mes correspondiente
        strcpy(anual[k].nombre, partes[iter].nombre);
        anual[k].mes = partes[iter].mes;
        anual[k].hisopados += partes[iter].hisopados;
        anual[k].infectados += partes[iter].infectados;
        anual[k].recuperados += partes[iter].recuperados;
        anual[k].fallecidos += partes[iter].fallecidos;

        key = !(strcmp(partes[iter].nombre, partes[iter + 1].nombre) == 0);
        iter++;
    }while(iter < counter + 1);


    for(int i = newSize; i < numberPartes; i++) // se encarga de limpiar los partes que sobren
        partes[i] = vacio;
    numberPartes = newSize;
}
