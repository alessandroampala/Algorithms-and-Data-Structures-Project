#pragma once

/**
 * NOTE: Keys and values must NOT be free'd before the 
 * destruction of the HashMap, otherwise the HashMap could
 * not work properly.
 */

typedef struct HashMap HashMap;
typedef int (*hashing_fun)(void*);
typedef int (*compare_fun)(void*, void*);

HashMap* HashMap_create(int initial_capacity, float load_factor, hashing_fun fun, compare_fun compare);
int HashMap_insert(HashMap* hm, void* key, void* value);
int HashMap_empty(HashMap* hm);
int HashMap_size(HashMap* hm);
int HashMap_key_exists(HashMap* hm, void* key);
void HashMap_delete_elements(HashMap* hm);
void* HashMap_get(HashMap* hm, void* key);
void** HashMap_key_set(HashMap* hm);
void* HashMap_delete(HashMap* hm, void* key);
void HashMap_destroy(HashMap* hm);
