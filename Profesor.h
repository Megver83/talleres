#pragma once
#include "Persona.h"
#include "Ramo.h"

class Profesor: public Persona
{
    private:
        Ramo ramos[3];
        int cantRamosProfesor = 0;
    public:
        Profesor();
        Ramo getRamoI(int i);
        void setRamo(Ramo ramo);
        string toString();
};