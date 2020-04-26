#pragma once

/**
 * NOTE: Keys and values must NOT be free'd before the 
 * destruction of the HashMap, otherwise the HashMap could
 * not work properly.
 */

typedef struct HashMap HashMap;

/**
 * The hashing function the HashMap uses.
 */
typedef int (*hashing_fun)(void*);

/**
 * The library assumes
 *    that the function returns a value less than 0 if the first 
 *    object is smaller than the second, returns 0
 *    if they are equal, and it returns a value larger than 0 
 *    if the first object is larger than the second.
 */
typedef int (*compare_fun)(void*, void*);

/**
 * Creates an HashMap
 * 
 * @param  initial_capacity The initial capacity of the HashMap
 *                          If initial_capacity is set to 0, then 
 *                          it will have the default initial capacity (64).
 *                          
 * @param  load_factor      Load factor of the HashMap. Must be a
 *                          float > 0 and <= 1; otherwise it will have the
 *                          default load factor (0.75).
 *                          
 * @param  fun              An hashing function of type hashing_fun
 * @param  compare          A compare function of type compare_fun
 * @return                  A pointer to the HashMap object created
 */
HashMap* HashMap_create(int initial_capacity, float load_factor, hashing_fun fun, compare_fun compare);

/**
 * Inserts a pair <key,value>
 * 
 * @param  hm    A pointer to the HashMap
 * @param  key   The key to insert
 * @param  value The value associated to the key
 * @return       Returns 1 if the pair was inserted successfully
 *               otherwise, the key is already present in the HashMap,
 *               so you may need to HashMap_detele(hm, key) and retry
 *               the insertion.
 */
int HashMap_insert(HashMap* hm, void* key, void* value);

/**
 * Returns a value != 0 if the HasMap hm is empty,
 * 0 otherwise.
 */
int HashMap_empty(HashMap* hm);

/**
 * Return the number of elements in the HashMap.
 */
int HashMap_size(HashMap* hm);

/**
 * Returns 1 if the key exists in the HashMap hm,
 * 0 otherwise.
 */
int HashMap_key_exists(HashMap* hm, void* key);

/**
 * Deletes all the pairs <key, value> present
 * in the HashMap hm.
 * 
 * NOTE: it does not frees the elements.
 */
void HashMap_delete_elements(HashMap* hm);

/**
 * Returns a pointer to the value associated to
 * key in the HashMap hm.
 */
void* HashMap_get(HashMap* hm, void* key);

/**
 * Returns an array of pointers to all the keys present
 * in the HashMap hm.
 *
 * NOTE: The size of the array returned is HashMap_size(hm).
 */
void** HashMap_key_set(HashMap* hm);

/**
 * Removes the pair <key, value> associated to key
 * from the HashMap hm.
 *
 * NOTE: It does not frees the objects removed.
 */
void* HashMap_delete(HashMap* hm, void* key);

/**
 * Destroy the HashMap.
 *
 * NOTE: It does not frees the objects present
 * 		 in the HashMap.
 */
void HashMap_destroy(HashMap* hm);
