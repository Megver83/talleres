#pragma once
#include "Persona.h"
#include "Ramo.h"

class Profesor: public Persona
{
    private:
        Ramo ramos[3];
    public:
        Profesor();
        Ramo getRamoI(int i);
};