#pragma once
#include <iostream>
using namespace std;

class Ramo
{
    private:
        string nombre;
        string carrera;
        string sala;
    public:
        Ramo();
        string getNombre();
        string getCarrera();
        string getSala();
        void setNombre(string _nombre);
        void setCarrera(string _carrera);
        void setSala(string _sala);
        string toString();
};