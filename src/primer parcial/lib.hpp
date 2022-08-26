#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct Resultado
{
    int idEq1;
    int idEq2;
    char estadio[20];
};

struct Equipo
{
    int idEq;
    char nombre[20];
    int puntos;
};

struct Estadio
{
    int cantJugados;
    int cantEmpatados;
    char estadio[20];
};
// Función encargada de cargar el archivo de consulta equipos.
void subirAMemoriaEquipos(Coll<Equipo> &equipos)
{
    FILE *f = fopen("EQUIPOS.dat", "r+b");
    Equipo reg = read<Equipo>(f);
    while (!feof(f))
    {
        collAdd<Equipo>(equipos, reg, equipoToEquipo);
        reg = read<Equipo>(f);
    }
    fclose(f);
};

// Calcula el ganador con el siguiente mecanismo
//  Si codRes < 0 => devuelve idEq1
//  Si codRes > 0 => devuelve idEq2
//  Si codRes == 0  => devuelve -1 (el empate lo identifico asi)
int calcularGanador(int eq1, int eq2, int codRes)
{
    if (codRes == 0)
        return -1;
    if (codRes < 0)
    {
        return eq1;
    }
    else
    {
        return eq2;
    }
}
// Sumo los puntos al equipo
//  si ganador != -1 => +=3
//  si ganador == -1 => +1 a ambos
//  !ERROR :(
//  EL STRUCT DEL TERCER PARAMETRO TENDRIA QUE SER DE TIPO RESULTADO NO DE TIPO EQUIPO
//  de esta forma puedo hacer registro.idEq1 y registro.idEq2  y sumarle a ambos puntos
//  otro error me olvide el & en el parametro collEq porque sino no cambio el coll en si
void sumarPuntos(int ganador, Coll<Equipo> collEq, Equipo registro)
{
    if (ganador != -1)
    {
        // Sumo punto unicamente al ganador
        int pos = collFind<Equipo, int>(collEq, ganador, cmEquipoEq, equipoFromString);
        Equipo elm = collGet<Equipo>(collEq, pos, equipoFromString);
        elm.puntos += 3;
        collSetAt<Equipo>(collEq, elm, pos, equipoFromString);
    }
    else
    {
        // Le tengo que sumar los puntos a los dos porque empataron
        int posIdEq1 = collFind<Equipo, int>(collEq, registro.eq1, cmEquipoEq, equipoFromString);
        int posIdEq2 = collFind<Equipo, int>(collEq, registro.eq2, cmEquipoEq, equipoFromString);
        Equipo eq1 = collGet<Equipo>(collEq, posIdEq1, equipoFromString);
        Equipo eq2 = collGet<Equipo>(collEq, posIdEq2, equipoFromString);
        eq1.puntos++;
        eq1.puntos++;
        collSetAt<Equipo>(collEq, eq1, posIdEq1, equipoFromString);
        collSetAt<Equipo>(collEq, eq2, posIdEq2, equipoFromString);
    }
}
// Proceso de descubrir el estadio
int descubrirEstadio(Coll<Estadio> &collEstad, Estadio estad)
{
    //! ERROR EL CAMPO DE TIPO K TENDRIA QUE SER STRING NO INT
    int pos = collFind<Estadio, int>(collEstad, estad, cmpEstadio, estadioFromString);
    if (pos < 0)
    {
        Estadio elm = estadio(0, 0, estad.estadio);
        collAdd<Estadio>(collEstad, elm, estadioToString);
        // !!ERROR TENDRIA QUE HABER ASIGNADO EL POS DESPUES DE CREAR EL ELEMENTO :(
    }
    return pos;
}
// Dependiendo de mis inputs actualizo mis acumuladores
void procesarEstadios(Coll<Equipo> &collEq, Estadio elm, int identificador, int pos)
{
    elm.cantJugados++;
    identificador == -1 ? elm.cantEmpatados++ : false;
    collSetAt<Estadio>(collEq, elm, pos, estadioFromString);
}
void mostrarTabla(Coll<Equipo> &collEquipos)
{
    collSort<Equipo>(collEquipos, cmpEquipoEquipo, equipoToString);
    collReset<Equipo>(collEquipos);
    int contador = 1;
    while (collHasNext(collEquipos))
    {
        Equipo elm = collNext<Equipo>(collEquipos);
        cout << "El equipo" << elm.nombre << "quedo en " << contador << " lugar" << endl;
        //!! ERROR  me olvide de hacer contador++ para que aparezcan los puestos :(
    }
}
void mostrarEstadios(coll<Estadio> &collEstadio)
{
    collReset<Equipo>(collEstadio);
    while (collHasNext(collEstadio))
    {
        Estadio elm = collNext<Estadio>(collEstadio);
        cout << "El estadio " << elm.estadio << " tuvo" << elm.cantJugados << " partidos jugados y " << elm.cantEmpatados << " empatados" << endl;
    };
}
int cmpEquipoEquipo(Equipo eq1, Equipo eq2)
{
    return eq1.puntos - eq2.puntos;
}
int cmpEstadio(Estadio estad, string nombre)
{
    estad.estadio - nombre;
}
int cmEquipoEq(Equiopo eq, int idEq)
{
    return eq.idEq - idEq;
}
string resultadoToString(Resultado x)
{
    char sep = 1;
    string sIdEq1 = to_string(x.idEq1);
    string sIdEq2 = to_string(x.idEq2);
    string sEstadio = x.estadio;
    return sIdEq1 + sep + sIdEq2 + sep + sEstadio;
}

Resultado resultadoFromString(string s)
{
    char sep = 1;
    Resultado x;
    string t0 = getTokenAt(s, sep, 0);
    x.idEq1 = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.idEq2 = stoi(t1);
    string t2 = getTokenAt(s, sep, 2);
    strcpy(x.estadio, t2.c_str());
    return x;
}

string resultadoToDebug(Resultado x)
{
    stringstream sout;
    sout << "[";
    sout << x.idEq1;
    sout << ",";
    sout << x.idEq2;
    sout << ",";
    sout << x.estadio;
    sout << "]";
    return sout.str();
}

string resultadoToDebug(string mssg, Resultado x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << x.idEq1;
    sout << ",";
    sout << x.idEq2;
    sout << ",";
    sout << x.estadio;
    sout << "]";
    return sout.str();
}

Resultado resultado(int idEq1, int idEq2, string estadio)
{
    Resultado a;
    a.idEq1 = idEq1;
    a.idEq2 = idEq2;
    strcpy(a.estadio, estadio.c_str());
    return a;
}

bool resultadoEquals(Resultado a, Resultado b)
{
    if (a.idEq1 != b.idEq1)
        return false;
    if (a.idEq2 != b.idEq2)
        return false;
    return true;
}

string equipoToString(Equipo x)
{
    char sep = 2;
    string sIdEq = to_string(x.idEq);
    string sNombre = x.nombre;
    string sPuntos = to_string(x.puntos);
    return sIdEq + sep + sNombre + sep + sPuntos;
}

Equipo equipoFromString(string s)
{
    char sep = 2;
    Equipo x;
    string t0 = getTokenAt(s, sep, 0);
    x.idEq = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    strcpy(x.nombre, t1.c_str());
    string t2 = getTokenAt(s, sep, 2);
    x.puntos = stoi(t2);
    return x;
}

string equipoToDebug(Equipo x)
{
    stringstream sout;
    sout << "[";
    sout << x.idEq;
    sout << ",";
    sout << x.nombre;
    sout << ",";
    sout << x.puntos;
    sout << "]";
    return sout.str();
}

string equipoToDebug(string mssg, Equipo x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << x.idEq;
    sout << ",";
    sout << x.nombre;
    sout << ",";
    sout << x.puntos;
    sout << "]";
    return sout.str();
}

Equipo equipo(int idEq, string nombre, int puntos)
{
    Equipo a;
    a.idEq = idEq;
    strcpy(a.nombre, nombre.c_str());
    a.puntos = puntos;
    return a;
}

bool equipoEquals(Equipo a, Equipo b)
{
    if (a.idEq != b.idEq)
        return false;
    if (a.puntos != b.puntos)
        return false;
    return true;
}

string estadioToString(Estadio x)
{
    char sep = 3;
    string sCantJugados = to_string(x.cantJugados);
    string sCantEmpatados = to_string(x.cantEmpatados);
    string sEstadio = x.estadio;
    return sCantJugados + sep + sCantEmpatados + sep + sEstadio;
}

Estadio estadioFromString(string s)
{
    char sep = 3;
    Estadio x;
    string t0 = getTokenAt(s, sep, 0);
    x.cantJugados = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.cantEmpatados = stoi(t1);
    string t2 = getTokenAt(s, sep, 2);
    strcpy(x.estadio, t2.c_str());
    return x;
}

string estadioToDebug(Estadio x)
{
    stringstream sout;
    sout << "[";
    sout << x.cantJugados;
    sout << ",";
    sout << x.cantEmpatados;
    sout << ",";
    sout << x.estadio;
    sout << "]";
    return sout.str();
}

string estadioToDebug(string mssg, Estadio x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << x.cantJugados;
    sout << ",";
    sout << x.cantEmpatados;
    sout << ",";
    sout << x.estadio;
    sout << "]";
    return sout.str();
}

Estadio estadio(int cantJugados, int cantEmpatados, string estadio)
{
    Estadio a;
    a.cantJugados = cantJugados;
    a.cantEmpatados = cantEmpatados;
    strcpy(a.estadio, estadio.c_str());
    return a;
}

bool estadioEquals(Estadio a, Estadio b)
{
    if (a.cantJugados != b.cantJugados)
        return false;
    if (a.cantEmpatados != b.cantEmpatados)
        return false;
    return true;
}

#endif
