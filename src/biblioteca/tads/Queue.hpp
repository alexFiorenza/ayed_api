#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include "../funciones/lists.hpp"
#include <iostream>

using namespace std;

template <typename T>
struct Queue
{
   Node<T> *p;
   Node<T> *q;
};

template <typename T>
Queue<T> queue()
{
   Queue<T> q;
   q.p = NULL;
   q.q = NULL;
   return q;
}

template <typename T>
T *queueEnqueue(Queue<T> &q, T e)
{
   Node<T> *n = enqueue(q.p, q.q, e);
   return &(n->d);
}

template <typename T>
T queueDequeue(Queue<T> &q)
{
   return dequeue(q.p, q.q);
}

template <typename T>
bool queueIsEmpty(Queue<T> q)
{
   return q.p == NULL;
}

template <typename T>
int queueSize(Queue<T> q)
{
   int i = 0;
   Node<T> *aux = q.p;
   while (aux != NULL)
   {
      i++;
      aux = aux->n;
   }
   return i;
}

#endif