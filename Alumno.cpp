#include "Alumno.h"

Alumno::Alumno()
{
    
};

int Alumno::getEdad()
{
    return edad;
};
int Alumno::getSemestre()
{
    return semestre;
};
Ramo Alumno::getRamoI(int i)
{
    return ramos[i];
};
void Alumno::setSemestre(int _semestre)
{
    semestre = _semestre;
};
void Alumno::setEdad(int _edad)
{
    edad = _edad;
};