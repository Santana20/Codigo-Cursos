#include <iostream>

#define DEBUG

#include "hashtable.h"

using namespace std;

int main() {
    int keys[10] = { 6, 27, 9, 65, 31, 35, 12, 21, 3, 2 };
    HashTable* ht = new HashTable();

    for (int i = 0; i < 10; ++i) {
        ht->add(keys[i]);
    }

    delete ht;
    return 0;
}