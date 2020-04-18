#include <stdlib.h>
#include "hashmap.h"

/**
 * TODO:
 * [X] Creazione HashMap
 * [X] bool Empty
 * [] bool verifica se la chiave specificata è presente
 * [---] inserimento di una nuova associazione <K,V>
 * [X] int Numero associazioni presenti
 * [] void cancellazione tutte le associazioni
 * [] ricerca valore tramite chiave
 * [] cancellazione di un associazione tramite chiave
 * [] recupero insieme di chiavi presenti
 * [] Distruzione
 */

#define INITIAL_CAPACITY 32
#define DEFAULT_LOAD_FACTOR 0.75

typedef struct HashMapElement
{
  void* key;
  void* value;
  int hash;
  struct HashMapElement* next;
} HashMapElement;

typedef struct HashMap
{
  hashing_fun fun;
  HashMapElement** elements;
  int size;
  int capacity;
  float load_factor;
  int threshold;
} HashMap;

int threshold(int capacity, float load_factor)
{
  return capacity * load_factor;
}

HashMapElement* HashMapElement_create(void* key, void* value, int hash, HashMapElement* next)
{
  HashMapElement* e = malloc(sizeof(HashMapElement));
  e->key = key;
  e->value = value;
  e->hash = hash;
  return e;
}

HashMap* HashMap_create(int initial_capacity, float load_factor, hashing_fun fun)
{
  HashMap* hm = malloc(sizeof(HashMap));
  hm->fun = fun;
  hm->capacity = (initial_capacity > 0) ? initial_capacity : INITIAL_CAPACITY;
  hm->elements = malloc(sizeof(HashMapElement*) * hm->capacity);
  for (int i = 0; i < hm->capacity; ++i)
    hm->elements[i] = NULL;
  hm->load_factor = (load_factor > 0 && load_factor < 1) ? load_factor : DEFAULT_LOAD_FACTOR;
  hm->threshold = threshold(hm->capacity, hm->load_factor);
  hm->size = 0;
  return hm;
}

int HashMap_empty(HashMap* hm)
{
  return hm->size == 0;
}

void HashMap_resize(HashMap* hm)
{
  int new_capacity = hm->capacity * 2;
  HashMapElement** new_map = malloc(sizeof(HashMapElement*) * new_capacity);
  for (int i = 0; i < hm->capacity; ++i)
    new_map[i] = NULL;

  //transfer elements
  for(int i = 0; i < hm->capacity; i++)
  {
    HashMapElement* e = hm->elements[i];
    while(e != NULL)
    {
      HashMapElement* next = e->next;
      int index = e->hash % new_capacity;
      e->next = new_map[index];
      new_map[index] = e;
      e = next;
    }
  }

  free(hm->elements);
  hm->elements = new_map;
  hm->capacity = new_capacity;
  hm->threshold = threshold(hm->capacity, hm->load_factor);
}

void HashMap_insert(HashMap* hm, void* key, void* value)
{
  //CONTROLLARE SE LA CHIAVE NON ESISTE ANCORA!!!!

  if(hm->size + 1 > hm->threshold)
    HashMap_resize(hm);

  int hash = hm->fun(key);
  hm->elements[hash % hm->capacity] = HashMapElement_create(key, value, hash, hm->elements[hash % hm->capacity]);
  hm->size++;
}

int HashMap_associations_number(HashMap* hm)
{
  return hm->size;
}