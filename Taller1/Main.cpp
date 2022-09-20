#include "Persona.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Ramo.h"

void eliminarDato(Alumno alumnos[],Profesor profesores[],Ramo ramos[])
{

};

void modificarDato(Alumno alumnos[],Profesor profesores[],Ramo ramos[])
{

};

bool agregarRamo(Ramo ramos[])
{
    return false;
};

bool agregarProfesor(Profesor profesores[])
{
    return false;
};

bool agregarAlumno(Alumno alumnos[])
{
    return false;
};

string consultarAlumno(Alumno alumnos[])
{
    
};

string consultarProfesor(Profesor profesores[])
{

};

string consultarRamo(Ramo ramos[])
{

};

void menu(Alumno alumnos[],Profesor profesores[],Ramo ramos[])
{
    cout << "Menú universitario: \n 1. Consultar por ramo \n 2. Consultar por profesor \n 3. Consultar por alumno \n 4. Agregar un alumno \n 5. Agregar un profesor \n 6. Agregar un ramo \n 7. Modificar un dato \n 8. Eliminar un dato \n";
    cout << "Ingrese opción: ";
    int opcion;
    cin >> opcion;
    switch(opcion)
    {
        case 1:
            cout << consultarRamo(ramos);
            break;
        case 2:
            cout << consultarProfesor(profesores);
            break;
        case 3:
            cout << consultarAlumno(alumnos);
            break;
        case 4:
            if(agregarAlumno(alumnos) == true)
            {
                cout << "Alumno ingresado";
            } else{
                cout << "No se pudo ingresar el alumno";
            };
            break;
        case 5:
            if(agregarProfesor(profesores) == true)
            {
                cout << "Profesor ingresado";
            } else{
                cout << "No se pudo ingresar el profesor";
            };
            break;
        case 6:
            if(agregarRamo(ramos) == true)
            {
                cout << "Ramo ingresado";
            } else{
                cout << "No se pudo ingresar el ramo";
            };
            break;
        case 7:
            modificarDato(alumnos, profesores, ramos);
            break;
        case 8:
            eliminarDato(alumnos, profesores, ramos);
            break;
    };
};

int main()
{
    Alumno alumnos[100];
    Profesor profesores[5];
    Ramo ramos[10];

    menu(alumnos, profesores, ramos);
    return 0;
};