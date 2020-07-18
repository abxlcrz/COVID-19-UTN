bool LeerParteDiario(PARTE& temp)
{
    assert(file.is_open());

    file.get(temp.nombre, 15);
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
    ushort counter = 0;     // contador  para almacenar la cantidad de partes que se cargan al array de ParteDiario
    PARTE temp;             // estructura de tipo PARTE temporal, utilizada para almacenar los datos de los partes temporalmente

    while(LeerParteDiario(temp))
    {
        InsertarEnOrden(temp, counter, partes);
        counter++;
    };
    numberPartes = counter;     // se asignan counter a la variable global numberPartes, que almacena el numero de partes ( es prescindible )


    ushort iter = 0;
    ushort newSize = 0;
    ushort k;
    bool key = false;



    do      // por lo menos se ejecuta una vez este codigo,
    {
        k = partes[iter].mes;

        if(key)     // el parte que esta por ser procesado corresponde un pais distinto a los que ya se procesaron
        {
            strcpy(parteProcesados[newSize].nombre, partes[iter - 1].nombre);   // asignar el nombre del pais de los partes ya procesados
            parteProcesados[newSize].habitantes = paises[newSize].habitantes;
            newSize++;      // aumentar el newSize en 1, para poder almacenar los partes en el siguiente espacio de array
        }
        else
        {
            // no hacer nada
        }
        parteProcesados[newSize].mes[k-1] = k;      // asignar mes

        // si comparten el mismo mes se suman
        // newSize identifica la posicion dentro del array ParteDiarioProcesados o ParteDiarioAlmacenados
        // k       identifica el mes asignado al ParteDiario procesado
        // k - 1   identifica la posicion dentro de las variables array de la estructura ParteDiarioProcesados o ParteDiarioAlmacenados
        // iter    identifica la posicion dentro del array de ParteDiario, es la posicion del parteDiario que se esta procesando
        parteProcesados[newSize].hisopados[k-1] += partes[iter].hisopados;
        parteProcesados[newSize].hisopados[12] += partes[iter].hisopados;

        parteProcesados[newSize].infectados[k-1] += partes[iter].infectados;
        parteProcesados[newSize].infectados[12] += partes[iter].infectados;

        parteProcesados[newSize].recuperados[k-1] += partes[iter].recuperados;
        parteProcesados[newSize].recuperados[12] += partes[iter].recuperados;

        parteProcesados[newSize].fallecidos[k-1] += partes[iter].fallecidos;
        parteProcesados[newSize].fallecidos[12] += partes[iter].fallecidos;

        key = !(strcmp(partes[iter].nombre, partes[iter + 1].nombre) == 0);     // si esto evalua a verdadero, el parte siguiente corresponde a un pais diferente
        iter++;
    }while(iter < counter + 1);
}
