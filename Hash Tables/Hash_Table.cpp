//
// Created by Vishisht Priyadarshi on 07-10-2019.
//

#include <iostream>
#include <mem.h>
#include <math.h>

using namespace std;

struct ht_item{
    char* key;
    char* value;
};

struct ht_hash_table{
    int size;           // No of entries that can be stored
    int count;
    ht_item** items;
};




// ******************************
//         New Hash Item
// ******************************


ht_item* ht_new_item(char *k, char *v){
    ht_item* i = new ht_item;
    i->key = strdup(k);
    i->value = strdup(v);

    return i;
};

// ********************************
//       New Hash Table
// ********************************

ht_hash_table* ht_new(){
    ht_hash_table* ht = new ht_hash_table;

    ht->size = 53;
    ht->count = 0;
    ht->items = new ht_item*;

}

// *********************************
//        Delete Item in Table
// *********************************

void ht_del_item(ht_item* i) {
    free(i->key);
    free(i->value);
    free(i);
}


// ************************************
//      Delete Hash Table
// ************************************

void ht_del_hash_table(ht_hash_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (item != NULL) {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}


// ************************************
//         Hash Function
// ************************************


int ht_hash(char* s, int a, int m) {             // a = prime no larger than size of the alphabet, m = bucket size
    long hash = 0;
    int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}

// *****************************************
// Handling Collisions using Double Hashing
// *****************************************


int ht_get_hash(char* s, int num_buckets, int attempt){
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}
