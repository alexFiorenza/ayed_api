
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
   Array<int> a = array<int>();
   int pos = arrayAdd<int>(a, 10); // pos = 0
   cout << pos << endl;
   return 0;
}

#endif
