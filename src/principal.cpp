
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
   Coll<string> c = coll<string>();
   collAdd<string>(c, "alex", stringToString);
   collAdd<string>(c, "virgilio", stringToString);
   collAdd<string>(c, "dante", stringToString);
   collAdd<string>(c, "beatriz", stringToString);
   collAdd<string>(c, "lucifero", stringToString);
   collReset<string>(c);
   bool endOfColl;
   string s = collNext<string>(c, endOfColl, stringToString);
   while (!endOfColl)
   {
      cout << s << endl;
      s = collNext<string>(c, endOfColl, stringToString);
   }
   return 0;
}

#endif
