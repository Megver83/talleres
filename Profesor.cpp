#include "Profesor.h"

Profesor::Profesor()
{
};

Ramo Profesor::getRamoI(int i)
{
    return ramos[i];
};
void Profesor::setRamo(Ramo ramo)
{
    if(cantRamosProfesor < 3)
    {
        ramos[cantRamosProfesor] = ramo;
        cantRamosProfesor++;
    };
};
string Profesor::toString()
{
    string ramosProfesor;
    if(cantRamosProfesor == 0)
    {
        ramosProfesor = "El profesor no ha tomado ramos";
    } else{
        for(int i = 0; i < cantRamosProfesor; i++)
        {
            ramosProfesor += ramos[i].getNombre() + ", ";
        };
    };
    return "Nombre: " + getNombre() + " | Apellido: " + getApellido() + " | Ramos: " + ramosProfesor;
};