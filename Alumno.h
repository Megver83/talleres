#pragma once
#include "Persona.h"
#include "Ramo.h"


class Alumno: public Persona
{
    private:
        int semestre;
        int edad;
        int cantRamosAlumno = 0;
        Ramo ramosAlumno[5];
    public:
        Alumno();
        int getSemestre();
        int getEdad();
        Ramo getRamoI(int i);
        void setSemestre(int _semestre);
        void setEdad(int _edad);
        void setRamo(Ramo ramo);
        string toString();
};