#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

/**
 * TODO:
 * [X] Creazione HashMap
 * [X] bool Empty
 * [X] bool verifica se la chiave specificata è presente
 * [X] inserimento di una nuova associazione <K,V>
 * [X] int Numero associazioni presenti
 * [X] void cancellazione tutte le associazioni
 * [X] ricerca valore tramite chiave
 * [X] cancellazione di un associazione tramite chiave
 * [X] recupero insieme di chiavi presenti
 * [X] Distruzione
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
  int key_size;
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
  e->next = next;
  return e;
}

HashMap* HashMap_create(int initial_capacity, float load_factor, int key_size, hashing_fun fun)
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
  hm->key_size = key_size;
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

int HashMap_insert(HashMap* hm, void* key, void* value)
{
  if(HashMap_key_exists(hm, key))
    return 0;

  if(hm->size + 1 > hm->threshold)
    HashMap_resize(hm);

  int hash = hm->fun(key);
  hm->elements[hash % hm->capacity] = HashMapElement_create(key, value, hash, hm->elements[hash % hm->capacity]);
  hm->size++;
  return 1;
}

int HashMap_size(HashMap* hm)
{
  return hm->size;
}

int HashMap_key_exists(HashMap* hm, void* key)
{
  HashMapElement* e = hm->elements[hm->fun(key) % hm->capacity];
  while(e != NULL)
  {
    if(memcmp(e->key, key, hm->key_size) == 0)
      return 1;
    e = e->next;
  }
  return 0;
}

void HashMap_delete_elements(HashMap* hm)
{
  for (int i = 0; i < hm->capacity; ++i)
  {
    HashMapElement* e;
    while((e = hm->elements[i]) != NULL)
    {
      hm->elements[i] = hm->elements[i]->next;
      free(e);
    }
  }
  hm->size = 0;
}

void* HashMap_get(HashMap* hm, void* key)
{
  HashMapElement* e = hm->elements[hm->fun(key) % hm->capacity];
  while(e != NULL)
  {
    if(memcmp(e->key, key, hm->key_size) == 0)
      return e->value;
    e = e->next;
  }
  return NULL;
}

void* HashMap_delete(HashMap* hm, void* key)
{
  int index = hm->fun(key) % hm->capacity;
  HashMapElement* e = hm->elements[index];
  void* ret;

  if(e != NULL)
  {
    if(memcmp(e->key, key, hm->key_size) == 0)
    {
      hm->elements[index] = e->next;
      ret = e->value;
      free(e);
      hm->size--;
      return ret;
    }
    else
    {
      HashMapElement* prev = e;
      e = e->next;
      while(e != NULL)
      {
        if(memcmp(e->key, key, hm->key_size) == 0)
        {
          prev->next = e->next;
          ret = e->value;
          free(e);
          hm->size--;
          return ret;
        }
        prev = e;
        e = e->next;
      }
    }
  }
  return NULL;
}

void** HashMap_key_set(HashMap* hm)
{
  void** a = malloc(sizeof(void*) * hm->size);
  int index = 0;
  for (int i = 0; i < hm->capacity; ++i)
  {
    HashMapElement* e = hm->elements[i];
    while(e != NULL)
    {
      a[index++] = e->key;
      e = e->next;
    }
  }
  return a;
}

void HashMap_destroy(HashMap* hm)
{
  HashMap_delete_elements(hm);
  free(hm->elements);
  free(hm);
}

