
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;
template <typename K, typename V>
int cmpKV(K a, V b)
{
   if (a == b)
   {
      return 0;
   }
   else
   {
      return -1;
   }
}
template <typename K, typename V>
struct Map
{
   Array<K> keys;
   Array<V> values;
   int pos;
};
//[key1,  key2,  key3  ]
// |        |      |
//[value1,value2,value3]
template <typename K, typename V>
Map<K, V> map()
{
   Map<K, V> m;
   m.keys = arr<K>();
   m.values = arr<V>();
   m.pos = 0;
   return m;
}

template <typename K, typename V>
V *mapGet(Map<K, V> m, K k)
{
   int index = arrayFind<K, K>(m.keys, k, cmpKV);
   if (index == -1)
   {
      return NULL;
   }
   V *p = arrayGet<V>(m.values, index);
   return p;
}

template <typename K, typename V>
V *mapPut(Map<K, V> &m, K k, V v)
{
   V *p = mapGet<K, V>(m, k);
   if (p != NULL)
   {
      // replace
      int index = arrayFind<K, K>(m.keys, k, cmpKV);
      arraySet<V>(m.values, index, v);
      return arrayGet<V>(m.values, index);
   }
   else
   {
      // No existe
      arrayAdd<K>(m.keys, k);
      int index = arrayAdd<V>(m.values, v);
      V *p = arrayGet<V>(m.values, index);
      return p;
   }
}

// Checking if the map contains the key.
template <typename K, typename V>
bool mapContains(Map<K, V> m, K k)
{
   int index = arrayFind<K, K>(m.keys, k, cmpKV);
   if (index == -1)
   {
      return false;
   }
   return true;
}

// Removing the key and value from the map.
template <typename K, typename V>
V mapRemove(Map<K, V> &m, K k)
{
   V v;
   int index = arrayFind<K, K>(m.keys, k, cmpKK);
   arrayRemove<K>(m.keys, index);
   arrayRemove<V>(m.values, index);
   return v;
}

template <typename K, typename V>
void mapRemoveAll(Map<K, V> &m)
{
   arrayRemoveAll<K>(m.keys);
   arrayRemoveAll<V>(m.values);
}

template <typename K, typename V>
int mapSize(Map<K, V> m)
{
   return arraySize<K>(m.keys);
}

template <typename K, typename V>
bool mapHasNext(Map<K, V> m)
{
   if (mapSize<K, V>(m) > m.pos)
   {
      return true;
   }
   else
   {
      m.pos++;
      return false;
   }
}

template <typename K, typename V>
K mapNextKey(Map<K, V> &m)
{
   K key = *arrayGet<K>(m.keys, m.pos);
   return key;
}

template <typename K, typename V>
V *mapNextValue(Map<K, V> &m)
{
   V *pointer = arrayGet<V>(m.values, m.pos);
   return pointer;
}

template <typename K, typename V>
void mapReset(Map<K, V> &m)
{
   m.pos = 0;
}

template <typename K, typename V>
void mapSortByKeys(Map<K, V> &m, int cmpKK(K, K))
{
}

template <typename K, typename V>
void mapSortByValues(Map<K, V> &m, int cmpVV(V, V))
{
}

#endif
