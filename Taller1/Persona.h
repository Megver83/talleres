#pragma once
#include <iostream>
using namespace std;

class Persona
{
    private:
        string nombre;
        string apellido;
    public:
        string getNombre();
        string getApellido();
        void setNombre(string _nombre);
        void setApellido(string _apellido);
};