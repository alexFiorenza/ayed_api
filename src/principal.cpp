
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
using namespace std;
int main()
{
   Map<string, int> m = map<string, int>();
   mapPut<string, int>(m, "uno", 1);
   mapPut<string, int>(m, "dos", 2);
   mapPut<string, int>(m, "tres", 3);
   int *p = mapGet<string, int>(m, "tres");
   cout << *p << endl;
   return 0;
}

#endif
