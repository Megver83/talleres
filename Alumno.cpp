#include "Alumno.h"
#include <sstream>

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
    return ramosAlumno[i];
};
void Alumno::setSemestre(int _semestre)
{
    semestre = _semestre;
};
void Alumno::setEdad(int _edad)
{
    edad = _edad;
};
void Alumno::setRamo(Ramo ramo)
{
    if(cantRamosAlumno < 5)
    {
        ramosAlumno[cantRamosAlumno] = ramo;
        cantRamosAlumno++;
    };
};
string Alumno::toString()
{
    string ramosAlumnoString;
    if(cantRamosAlumno == 0)
    {
        ramosAlumnoString = "El alumno no ha tomado ramos";
    } else{
        for(int i = 0; i < cantRamosAlumno; i++)
        {
            ramosAlumnoString += ramosAlumno[i].getNombre() + ", ";
        };
    };
    return "Nombre: " + getNombre() + " | Apellido: " + getApellido() + " | Edad: " + to_string(edad) + " | Semestre: " + to_string(semestre) + " | Ramos: " + ramosAlumnoString;
};