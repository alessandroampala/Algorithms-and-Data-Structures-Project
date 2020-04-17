#include <stdlib.h>
#include "hashmap.h"

/**
 * TODO:
 * [X] Creazione HashMap
 * [] Distruzione
 * [X] bool Empty
 * [] int Numero associazioni presenti
 * [] void cancellazione tutte le associazioni
 * [] bool verifica se la chiave specificata è presente
 * [] inserimento di una nuova associazione <K,V>
 * [] ricerca valore tramite chiave
 * [] cancellazione di un associazione tramite chiave
 * [] recupero insieme di chiavi presenti
 */

#define INITIAL_CAPACITY 32

typedef struct HashMapElement
{
  void* key;
  void* value;
  struct HashMapElement* next;
} HashMapElement;

typedef struct HashMap
{
  hashing_fun fun;
  HashMapElement* elements;
  int size;
  int capacity;
} HashMap;

HashMap* HashMap_create(hashing_fun fun)
{
  HashMap* hm = malloc(sizeof(HashMap));
  hm->fun = fun;
  hm->capacity = INITIAL_CAPACITY;
  hm->elements = malloc(sizeof(HashMapElement) * hm->capacity);
  hm->size = 0;
  return hm;
}

int HashMap_empty(HashMap* hm)
{
  return hm->size == 0;
}