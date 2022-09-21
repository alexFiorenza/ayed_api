
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
   Node<int> *p = NULL;
   addFirst<int>(p, 1);
   addFirst<int>(p, 2);
   addFirst<int>(p, 3);

   Node<int> *q = p;
   while (q != NULL)
   {
      cout << q->info << endl;
      q = q->next;
   }
   return 0;
}

#endif
