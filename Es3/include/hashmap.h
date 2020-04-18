#pragma once


/**
 * NOTE: Keys and values must NOT be free'd before the 
 * destruction of the HashMap, otherwise the HashMap could
 * not work properly.
 */

typedef struct HashMap HashMap;
typedef int (*hashing_fun)(void*);

HashMap* HashMap_create(int initial_capacity, float load_factor, hashing_fun fun);
void HashMap_insert(HashMap* hm, void* key, void* value);
int HashMap_empty(HashMap* hm);
int HashMap_associations_number(HashMap* hm);