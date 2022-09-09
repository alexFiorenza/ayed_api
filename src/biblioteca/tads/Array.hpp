#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

// A function that doubles the capacity of the array.
template <typename T>
void _redimensionarArray(T *&a, int &cap)
{
   T *aux = new T[cap * 2];
   for (int i = 0; i < cap; i++)
   {
      aux[i] = a[i];
   }
   delete a;
   a = aux;
   cap *= 2;
}
template <typename T>
struct Array
{
   int cap;
   int len;
   T *arr;
};

template <typename T>
Array<T> arr()
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
   if (a.len >= a.cap)
   {
      _redimensionarArray(a.arr, a.cap);
   }
   return add<T>(a.arr, a.len, t);
}

// Returning the address of the element in the array at position p.
template <typename T>
T *arrayGet(Array<T> a, int p)
{
   return &a.arr[p];
}

// Setting the value of the element at position p to t.
template <typename T>
void arraySet(Array<T> &a, int p, T t)
{
   T *element = arrayGet<T>(a, p);
   *element = t;
}

// Inserting an element in the array at position p.
template <typename T>
void arrayInsert(Array<T> &a, T t, int p)
{
   insert<T>(a.arr, a.len, t, p);
}

template <typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template <typename T>
T arrayRemove(Array<T> &a, int p)
{
   return remove(a.arr, a.len, p);
}

template <typename T>
void arrayRemoveAll(Array<T> &a)
{
   delete a;
   a.len = 0;
   a.cap = 100;
   a.arr = new T[a.cap];
}

// A function that finds the position of an element in an array.
template <typename T, typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T, K))
{
   return find<T, K>(a.arr, a.len, k, cmpTK);
}

template <typename T>
int arrayOrderedInsert(Array<T> &a, T t, int cmpTT(T, T))
{
   if (a.len >= a.cap)
   {
      _redimensionarArray(a.arr, a.cap);
   }
   return orderedInsert<T>(a.arr, a.len, t, cmpTT);
}

template <typename T>
void arraySort(Array<T> &a, int cmpTT(T, T))
{
   sort<T>(a.arr, a.len, cmpTT);
}

#endif
