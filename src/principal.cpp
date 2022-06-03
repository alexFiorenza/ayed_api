
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
   string s = "John";
   char sep = '|';
   string t = "John";
   int p = findToken(s, sep, t);
   cout << p << endl;
   return 0;
}

#endif
