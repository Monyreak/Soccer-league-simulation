#ifndef hash_table_h
#define hash_table_h
#include <iostream>
#include "hash_entry.cpp"
#include "queue_ADT.h"

template <typename KeyType, typename ItemType>
class HashTable {
private:
    HashEntry<KeyType, ItemType> **table;
    int numberOfCollision;
    int numberOfEntry;

    int tableSize;

    /*setter*/
    void setNumberOfCollision(int numOfCol);
    void setNumberOfEntry(int numOfEnt);
    void setTableSize(int size);

    /*Hash function
    @ pre None
    @ post return index that the data should be store in hash table.
    @ param key The string that is needed to find the index.

    return index
    */
    int hashFunc(std::string &key);

    /*Resize function
    @ pre None
    @ post replace the old table with a new table with a twice bigger size.

    */
    void resize();

    /*Is Empty function
    @ pre none
    @ post return true if the numberOfEntry = 0;
            otherwise, return false;

    @ return true or false;
    */
    bool isEmpty();
public:
    /*constructor*/
    HashTable();

    /*destructor*/
    ~HashTable();

    /*getters*/
    int getNumberOfCollision();
    int getNumberOfEntry();
    int getTableSize();

    /*Insert function
    @ pre None
    @ post insert the data to an appropriate index in hash table.

    @ param key The string that is needed to find the index.
            item The data that is wanted to be stored in hash table.
    */
    void insert(KeyType &key, ItemType *item);

    /*Renove Function
    @ pre None
    @ post remove the data from the hash table based on the given key.

    @ param key The string that is needed to find the index.
    */
    void remove(KeyType &key);

    /*Find function
    @ pre None
    @ post if the key in the hashtable exist. return true.
            otherwise, return false.
    */
    bool find(KeyType &key);

    /*Empty the table function
    @ pre None
    @ post delete all the data in the hash table.

    */
    void emptyTheTable();
    
    /*Print function
    @ pre None
    @ post print all the data with its index on the screen.

    */

    void print();
};

#endif /* hash_table_h */
