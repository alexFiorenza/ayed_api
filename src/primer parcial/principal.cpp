#ifndef _MAIN
#define _MAIN
#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "./lib.hpp"
int main()
{
    Coll<Estadio> estadios = Coll<Estadio>();
    Coll<Equipo> equipos = coll<Equipo>();
    subirAMemoriaEquipos(equipos);

    // Corte de control al archivo de novedades Resultados
    FILE *f = fopen("RESULTADOS.dat", "r+b");
    Resultado reg = read<Resultado>(f);
    while (!feof(f))
    {
        // Proceso punto 1
        int ganador = calcularGanador(reg.idEq1, reg.idEq2, reg.codRes);
        sumarPuntos(ganador, equipos, reg);

        // Procesar punto 2
        int pos = descubrirEstadio(estadios, reg.estadio);
        Estadio elm = collGetAt<Estadio>(estadios, pos, estadioFromString);
        procesarEstadios(estadios, elm, ganador, pos);
        reg = read<Resultado>(f);
    }
    fclose(f);
    mostrarTabla(equipos);
    mostrarEstadios(estadios);
    return 0;
}