#include "Ramo.h"
#include <iostream>

Ramo::Ramo()
{
};

string Ramo::getNombre()
{
    return nombre;
};
string Ramo::getCarrera()
{
    return carrera;
};
string Ramo::getSala()
{
    return sala;
};
void Ramo::setNombre(string _nombre)
{
    nombre = _nombre;
};
void Ramo::setCarrera(string _carrera)
{
    carrera = _carrera;
};
void Ramo::setSala(string _sala)
{
    sala = _sala;
};
string Ramo::toString()
{
    return "Nombre: " + nombre + " | Carrera: " + carrera + " | Sala: " + sala;
};