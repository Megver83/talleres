#include "Persona.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Ramo.h"

int cantAlumnos = 0;
int cantProfesores = 0;
int cantRamos = 0;

void modificarRamo(Ramo* ramos, Ramo ramo)
{

};

void eliminarRamo(Ramo* ramos, Ramo ramo)
{

};

void modificarProfesor(Profesor* profesores, Profesor profesor)
{

};

void eliminarProfesor(Profesor* profesores, Profesor profesor)
{

};

void modificarAlumno(Alumno* alumnos, Alumno alumno)
{

};

void eliminarAlumno(Alumno* alumnos, Alumno alumno)
{

};

int buscarProfesor(Profesor* profesores, string nombre)
{
    for(int i = 0; i < cantProfesores; i++)
    {
        if(profesores[i].getNombre() == nombre)
        {
            return i;
        };
    };
    return -1;
};

int buscarAlumno(Alumno* alumnos, string nombre)
{
    for(int i = 0; i < cantAlumnos; i++)
    {
        if(alumnos[i].getNombre() == nombre)
        {
            return i;
        };
    };
    return -1;
};

int buscarRamo(Ramo* ramos, string nombre)
{
    for(int i = 0; i < cantRamos; i++)
    {
        if(ramos[i].getNombre() == nombre)
        {
            return i;
        };
    };
    return -1;
};

bool agregarRamo(Ramo* ramos)
{
    if ((sizeof(Ramo) * cantRamos) < (sizeof(Ramo) * 10))
    {
        Ramo ramo;
        string nombre;
        string carrera;
        string sala;
        cout << "Nombre del ramo: " << endl;
        cin >> nombre;
        cout << "Carrera a la cual pertenece: " << endl;
        cin >> carrera;
        cout << "Sala en la que se imparte: " << endl;
        cin >> sala;
        ramo.setNombre(nombre);
        ramo.setCarrera(carrera);
        ramo.setSala(sala);
        ramos[cantRamos] = ramo;
        cantRamos++;
        return true;
    } else
    {
        return false;
    };
};

void agregarRamoProfesor(Profesor profesor, Ramo* ramos)
{
    int opcion;
    do
    {
        cout << "Desea agregar un ramo al profesor? \n 0. No \n 1. Si" << endl;
        cin >> opcion;
        if(opcion == 1)
        {
            string nombreRamo;
            cout << "Ingrese nombre del ramo: " << endl;
            cin >> nombreRamo;
            int ramoI = buscarRamo(ramos, nombreRamo);
            if(ramoI != -1)
            {
                Ramo ramo = ramos[ramoI];
                profesor.setRamo(ramo);
                cout << "Ramo agregado" << endl;
            } else{
                cout << "No se ha encontrado el ramo" << endl;
            };
        };
    } while (opcion != 0);
};

bool agregarProfesor(Profesor* profesores, Ramo* ramos)
{
    if((sizeof(Profesor) * cantProfesores) < (sizeof(Profesor) * 5))
    {
        Profesor profesor;
        string nombre;
        string apellido;
        cout << "Nombre del profesor: " << endl;
        cin >> nombre;
        cout << "Apellido del profesor: " << endl;
        cin >> apellido;
        profesor.setNombre(nombre);
        profesor.setApellido(apellido);
        agregarRamoProfesor(profesor, ramos);
        profesores[cantProfesores] = profesor;
        cantProfesores++;
        return true;
    } else{
        return false;
    };
};

void agregarRamoAlumno(Alumno alumno, Ramo* ramos)
{
    int opcion;
    do
    {
        cout << "Desea agregar un ramo al alumno? \n 0. No \n 1. Si" << endl;
        cin >> opcion;
        if(opcion == 1)
        {
            string nombreRamo;
            cout << "Ingrese nombre del ramo: " << endl;
            cin >> nombreRamo;
            int ramoI = buscarRamo(ramos, nombreRamo);
            if(ramoI != -1)
            {
                Ramo ramo = ramos[ramoI];
                alumno.setRamo(ramo);
                cout << "Ramo agregado" << endl;
            } else{
                cout << "No se ha encontrado el ramo" << endl;
            };
        };
    } while (opcion != 0);
};

bool agregarAlumno(Alumno* alumnos, Ramo* ramos)
{
    if((sizeof(Alumno) * cantAlumnos) < (sizeof(Alumno) * 100))
    {
        Alumno alumno;
        string nombre;
        string apellido;
        int semestre;
        int edad;
        cout << "Nombre del alumno: " << endl;
        cin >> nombre;
        cout << "Apellido: " << endl;
        cin >> apellido;
        cout << "Semestre: " << endl;
        cin >> semestre;
        cout << "Edad: " << endl;
        cin >> edad;
        alumno.setNombre(nombre);
        alumno.setApellido(apellido);
        alumno.setSemestre(semestre);
        alumno.setEdad(edad);
        agregarRamoAlumno(alumno, ramos);
        alumnos[cantAlumnos] = alumno;
        cantAlumnos++;
        return true;
    } else{
        return false;
    };
};

Alumno* consultarAlumno(Alumno* alumnos)
{
    string nombre;
    cout << "Ingrese nombre del alumno: " << endl;
    cin >> nombre;
    int i = buscarAlumno(alumnos, nombre);
    if(i != -1)
    {
        cout << alumnos[i].toString() << endl;
        return &alumnos[i];
    } else{
        cout << "Alumno no encontrado" << endl;
        return NULL;
    };
};

Profesor* consultarProfesor(Profesor* profesores)
{
    string nombre;
    cout << "Ingrese nombre del profesor: " << endl;
    cin >> nombre;
    int i = buscarProfesor(profesores, nombre);
    if(i != -1)
    {
        cout << profesores[i].toString() << endl;
        return &profesores[i];
    } else{
        cout << "Profesor no encontrado" << endl;
        return NULL;
    };
};

Ramo* consultarRamo(Ramo* ramos)
{
    string nombre;
    cout << "Ingrese el nombre del ramo: " << endl;
    cin >> nombre;
    int i = buscarRamo(ramos, nombre);
    if(i != -1)
    {
        cout << ramos[i].toString() << endl;
        return &ramos[i];
    } else{
        cout << "Ramo no encontrado" << endl;
        return NULL;
    };
};

//overload
void menuModificaciones(Ramo ramos[], Ramo* ramo)
{
    int opcion;
    cout << "Desea modificar o eliminar? \n 1. Modificar \n 2. Eliminar \n 3. Volver al menú" << endl;
    cin >> opcion;
    switch(opcion)
    {
        case 1:
            modificarRamo(ramos, *ramo);
            break;
        case 2:
            eliminarRamo(ramos, *ramo);
            break;
        case 3:
            break;
    };
};

//overload
void menuModificaciones(Profesor profesores[], Profesor* profesor)
{
    int opcion;
    cout << "Desea modificar o eliminar? \n 1. Modificar \n 2. Eliminar \n 3. Volver al menú" << endl;
    cin >> opcion;
    switch(opcion)
    {
        case 1:
            modificarProfesor(profesores, *profesor);
            break;
        case 2:
            eliminarProfesor(profesores, *profesor);
            break;
        case 3:
            break;
    };
};

//overload
void menuModificaciones(Alumno alumnos[], Alumno* alumno)
{
    int opcion;
    cout << "Desea modificar o eliminar? \n 1. Modificar \n 2. Eliminar \n 3. Volver al menú" << endl;
    cin >> opcion;
    switch(opcion)
    {
        case 1:
            modificarAlumno(alumnos, *alumno);
            break;
        case 2:
            eliminarAlumno(alumnos, *alumno);
            break;
        case 3:
            break;
    };
};

void menu(Alumno alumnos[], Profesor profesores[], Ramo ramos[])
{
    int opcion;
    do
    {
        cout << "Menú universitario: \n 1. Consultar por ramo \n 2. Consultar por profesor \n 3. Consultar por alumno \n 4. Agregar un alumno \n 5. Agregar un profesor \n 6. Agregar un ramo \n 0. Salir \n";
        cout << "Ingrese opción: ";
        cin >> opcion;
        switch(opcion)
        {
            case 1:
            {
                Ramo* ramo = consultarRamo(ramos);
                if(ramo != NULL)
                {
                    menuModificaciones(ramos, ramo);
                };
            };
            break;
            case 2:
            {
                Profesor* profesor = consultarProfesor(profesores);
                if(profesor != NULL)
                {
                    menuModificaciones(profesores, profesor);
                };
            };
            break;
            case 3:
            {
                Alumno* alumno = consultarAlumno(alumnos);
                if(alumno != NULL)
                {
                    menuModificaciones(alumnos, alumno);
                };
            };
            break;
            case 4:
                if(agregarAlumno(alumnos, ramos) == true)
                {
                    cout << "Alumno ingresado" << endl;
                } else{
                    cout << "No se pudo ingresar el alumno" << endl;
                };
            break;
            case 5:
                if(agregarProfesor(profesores, ramos) == true)
                {
                    cout << "Profesor ingresado" << endl;
                } else{
                    cout << "No se pudo ingresar el profesor" << endl;
                };
            break;
            case 6:
                if(agregarRamo(ramos) == true)
                {
                    cout << "Ramo ingresado" << endl;
                } else{
                    cout << "No se pudo ingresar el ramo" << endl;
                };
            break;
            case 0:
                cout << "Hasta luego" << endl;
                exit;
            break;
            default:
                cout << "Ingreso no válido, vuelva a intentar" << endl;
        };
    }while(opcion != 0);
};

int main()
{
    Alumno alumnos[100];
    Profesor profesores[5];
    Ramo ramos[10];

    menu(alumnos, profesores, ramos);
    return 0;
};