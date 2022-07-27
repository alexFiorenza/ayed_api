#include <iostream>
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/tads/Coll.hpp"
#include "./lib.hpp"

int descubrirEquipo(Coll<Equipo> &equipos, int idEq)
{
    int pos = collFind<Equipo, int>(equipos, idEq, cmpEquipoId, equipoToString);
    return pos;
}

void imprimirResultado(int ganador, int perdedor, bool empate)
{
    if (empate)
    {
        cout << "Empate" << endl;
    }
    else
    {
        cout << "El equipo " << ganador << " gano"
             << " a " << perdedor << endl;
    }
}
/**
 * Devuelve el id del equipo ganador, dado un codigo de resultado y los ids de los equipos
 *
 * @param codRes El coll de equipos donde debo iterar para encontrar el ganador
 * @param codRes El resultado del partido
 * @param idEq1 Id del primer equipo
 * @param idEq2 Id del segundo equipo
 *
 * @return  vacio
 */
bool setPuntosToEquipo(Coll<Equipo> &equipos, int codRes, int idEq1, int idEq2)
{
    if (codRes < 0)
    {
        int pos = descubrirEquipo(equipos, idEq1);
        Equipo elm = collGetAt<Equipo>(equipos, pos, equipoToString);
        elm.puntos = elm.puntos += 3;
        collSetAt<Equipo>(equipos, elm, pos, equipoToString);
        imprimirResultado(idEq1, idEq2, false);
        return false;
    }
    if (codRes > 0)
    {
        int pos = descubrirEquipo(equipos, idEq2);
        Equipo elm = collGetAt<Equipo>(equipos, pos, equipoToString);
        elm.puntos = elm.puntos += 3;
        collSetAt<Equipo>(equipos, elm, pos, equipoToString);
        imprimirResultado(idEq2, idEq1, false);
        return false;
    }
    else
    {
        // empataron
        int posIdEq1 = descubrirEquipo(equipos, idEq1);
        int posIdEq2 = descubrirEquipo(equipos, idEq2);
        Equipo elmIdEq1 = collGetAt<Equipo>(equipos, posIdEq1, equipoToString);
        elmIdEq1.puntos = elmIdEq1.puntos++;
        collSetAt<Equipo>(equipos, elmIdEq1, posIdEq1, equipoToString);
        Equipo elmIdEq2 = collGetAt<Equipo>(equipos, posIdEq2, equipoToString);
        elmIdEq2.puntos = elmIdEq1.puntos++;
        collSetAt<Equipo>(equipos, elmIdEq2, posIdEq2, equipoToString);
        imprimirResultado(idEq1, idEq2, true);
        return true;
    }
}
/**
 * Leer el archivo RESULTADOS.dat  y agrega cada resultado a la coll resultados
 *
 * @param resultados La coleccion a agregar los resultados
 */
void subirAMemoriaResultados(Coll<Resultado> &resultados)
{
    FILE *f = fopen("RESULTADOS.dat,", "r+b");
    Resultado r = read<Resultado>(f);
    while (!feof(f))
    {
        collAdd<Resultado>(resultados, r, resultadoToString);
        r = read<Resultado>(f);
    }
    fclose(f);
}
void subirAMemoriaEquipos(Coll<Equipo> &equipos)
{
    FILE *f = fopen("EQUIPOS.dat,", "r+b");
    Equipo e = read<Equipo>(f);
    while (!feof(f))
    {
        collAdd<Equipo>(equipos, e, equipoToString);
        e = read<Equipo>(f);
    }
    fclose(f);
}
void informarTablaYProcesarEstadios(Coll<Resultado> resultados, Coll<Equipo> &equipo, Coll<Estadio> &estadios)
{
    collReset<Resultado>(resultados);
    while (collHasNext<Resultado>(resultados))
    {
        Resultado resultado = collNext<Resultado>(resultados, resultadoToString);
        int pos = descubrirEstadios(estadios, resultado.estadio);
        Estadio e = collGetAt<Estadio>(estadios, pos, estadioToString);
        e.partidosJugados = e.partidosJugados + 1;
        bool huboEmpate = setPuntosToEquipo(equipo, resultado.codRes, resultado.idEq1, resultado.idEq2);
        huboEmpate ? e.partidosEmpatados = e.partidosEmpatados + 1 : false;
        collSetAt<Estadio>(estadios, e, pos, estadioToString);
    }
}
void informarEstadios(Coll<Estadio> &estadios)
{
    collReset<Estadio>(estadios);
    while (collHasNext<Estadio>(estadios))
    {
        Estadio e = collNext<Estadio>(estadios, estadioToString);
        cout << "En el estadio" << e.estadio << " se jugaron" << e.partidosJugados << "partidos" << endl;
        cout << "tuvo" << e.partidosEmpatados << " empatados"
             << " de" << e.partidosJugados << "partidos" << endl;
    }
}
void guardarPuntuaciones(Coll<Equipo> &equipos)
{
    FILE *f = fopen("EQUIPOS.dat,", "r+b");
    Equipo registro = read<Equipo>(f);
    while (!feof(f))
    {
        // Estos son los elementos de mi coll
        int pos = descubrirEquipo(equipos, registro.idEq);
        Equipo elm = collGetAt<Equipo>(equipos, pos, equipoToString);
        registro.puntos = elm.puntos;
        seek<Equipo>(f, filePos<Equipo>(f) - 1);
        write<Equipo>(f, registro);
        registro = read<Equipo>(f);
    }
}
int main()
{
    // Leer el archivo resultados.dat
    Coll<Resultado> resultados = coll<Resultado>();
    subirAMemoriaResultados(resultados);

    // Leer el archivo equipos.dat
    Coll<Equipo> equipos = coll<Equipo>();
    subirAMemoriaEquipos(equipos);

    // Genero mi tad coll de Estadios
    Coll<Estadio> estadios = coll<Estadio>();
    // Procesar punto 1 y 2
    informarTablaYProcesarEstadios(resultados, equipos, estadios);
    // Mostrar estadios (punto 2)
    informarEstadios(estadios);
    // Punto 3
    guardarPuntuaciones(equipos);
    return 0;
}