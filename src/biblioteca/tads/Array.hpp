#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template <typename T>
struct Array
{
   int cap;
   int len;
   T *arr;
};

template <typename T>
Array<T> array()
{
   Array<T> ret;
   ret.cap = 100;
   ret.len = 0;
   ret.arr = new T[ret.cap];
   return ret;
}

template <typename T>
int arrayAdd(Array<T> &a, T t)
{
   int pos = add(a.arr, a.len, t);
   return pos;
}

template <typename T>
T *arrayGet(Array<T> a, int p)
{
   return NULL;
}

template <typename T>
void arraySet(Array<T> &a, int p, T t)
{
}

template <typename T>
void arrayInsert(Array<T> &a, T t, int p)
{
}

template <typename T>
int arraySize(Array<T> a)
{
   return 0;
}

template <typename T>
T arrayRemove(Array<T> &a, int p)
{
   T t;
   return t;
}

template <typename T>
void arrayRemoveAll(Array<T> &a)
{
}

template <typename T, typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T, K))
{
   return 0;
}

template <typename T>
int arrayOrderedInsert(Array<T> &a, T t, int cmpTT(T, T))
{
   return 0;
}

template <typename T>
void arraySort(Array<T> &a, int cmpTT(T, T))
{
}

#endif
