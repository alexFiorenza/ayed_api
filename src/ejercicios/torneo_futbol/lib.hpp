#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/Coll.hpp"
using namespace std;

struct Resultado
{
    int idEq1;
    int idEq2;
    int codRes;
    char estadio[20];
};

struct Estadio
{
    char estadio[20];
    int partidosJugados;
    int partidosEmpatados;
};

struct Equipo
{
    int idEq;
    char nombre[20];
    int puntos;
};
int cmpEquipoId(Equipo e, int id)
{
    return e.idEq - id;
}
int cmpEstadio(Estadio e, char estadio[20])
{
    return strcmp(e.estadio, estadio);
}

int descubrirEstadios(Coll<Estadio> &estadios, char estadioNombre[20])
{
    int pos = collFind<Estadio>(estadios, estadioNombre, cmpEstadio, estadioFromString);
    if (pos < 0)
    {
        Estadio e = setEstadio(estadioNombre, 0, 0);
        pos = collAdd<Estadio>(estadios, e, estadioToString);
    }
    return pos;
}
string resultadoToString(Resultado x)
{
    char sep = 1;
    string sIdEq1 = to_string(x.idEq1);
    string sIdEq2 = to_string(x.idEq2);
    string sCodRes = to_string(x.codRes);
    string sEstadio = x.estadio;
    return sIdEq1 + sep + sIdEq2 + sep + sCodRes + sep + sEstadio;
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
    x.codRes = stoi(t2);
    string t3 = getTokenAt(s, sep, 3);
    strcpy(x.estadio, t3.c_str());
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
    sout << x.codRes;
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
    sout << x.codRes;
    sout << ",";
    sout << x.estadio;
    sout << "]";
    return sout.str();
}

Resultado resultado(int idEq1, int idEq2, int codRes, string estadio)
{
    Resultado a;
    a.idEq1 = idEq1;
    a.idEq2 = idEq2;
    a.codRes = codRes;
    strcpy(a.estadio, estadio.c_str());
    return a;
}

bool resultadoEquals(Resultado a, Resultado b)
{
    if (a.idEq1 != b.idEq1)
        return false;
    if (a.idEq2 != b.idEq2)
        return false;
    if (a.codRes != b.codRes)
        return false;
    return true;
}

string estadioToString(Estadio x)
{
    char sep = 2;
    string sEstadio = x.estadio;
    string sPartidosJugados = to_string(x.partidosJugados);
    string sPartidosEmpatados = to_string(x.partidosEmpatados);
    return sEstadio + sep + sPartidosJugados + sep + sPartidosEmpatados;
}

Estadio estadioFromString(string s)
{
    char sep = 2;
    Estadio x;
    string t0 = getTokenAt(s, sep, 0);
    strcpy(x.estadio, t0.c_str());
    string t1 = getTokenAt(s, sep, 1);
    x.partidosJugados = stoi(t1);
    string t2 = getTokenAt(s, sep, 2);
    x.partidosEmpatados = stoi(t2);
    return x;
}

string estadioToDebug(Estadio x)
{
    stringstream sout;
    sout << "[";
    sout << x.estadio;
    sout << ",";
    sout << x.partidosJugados;
    sout << ",";
    sout << x.partidosEmpatados;
    sout << "]";
    return sout.str();
}

string estadioToDebug(string mssg, Estadio x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << x.estadio;
    sout << ",";
    sout << x.partidosJugados;
    sout << ",";
    sout << x.partidosEmpatados;
    sout << "]";
    return sout.str();
}

Estadio setEstadio(string estadio, int partidosJugados, int partidosEmpatados)
{
    Estadio a;
    strcpy(a.estadio, estadio.c_str());
    a.partidosJugados = partidosJugados;
    a.partidosEmpatados = partidosEmpatados;
    return a;
}

bool estadioEquals(Estadio a, Estadio b)
{
    if (a.partidosJugados != b.partidosJugados)
        return false;
    if (a.partidosEmpatados != b.partidosEmpatados)
        return false;
    return true;
}

string equipoToString(Equipo x)
{
    char sep = 3;
    string sIdEq = to_string(x.idEq);
    string sNombre = x.nombre;
    string sPuntos = to_string(x.puntos);
    return sIdEq + sep + sNombre + sep + sPuntos;
}

Equipo equipoFromString(string s)
{
    char sep = 3;
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

#endif
