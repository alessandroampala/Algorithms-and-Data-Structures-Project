#pragma once


/**
 * NOTE: Keys and values must NOT be free'd before the 
 * destruction of the HashMap, otherwise the HashMap could
 * not work properly.
 */

typedef struct HashMap HashMap;
typedef int (*hashing_fun)(void*);

HashMap* HashMap_create(hashing_fun fun);