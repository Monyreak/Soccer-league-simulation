#include "hash_table.h"

template <typename KeyType, typename ItemType>
HashTable<KeyType, ItemType>::HashTable() {
    tableSize = 509;
    table = new HashEntry<KeyType, ItemType> *[tableSize];
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
    }
    numberOfCollision = 0;
    numberOfEntry = 0;
}

template <typename KeyType, typename ItemType>
HashTable<KeyType, ItemType>::~HashTable() {
    emptyTheTable();
    delete table;
}

template <typename KeyType, typename ItemType>
int HashTable<KeyType, ItemType>::hashFunc(std::string &Key) {
    int hashkey = 0;
    queue<int> q;
 
    int length = static_cast<int>(Key.length());
    int temp = 0;

    for (int i = 0; i < length; i++) {
        if (Key[i] >= 65 && Key[i] <= 90) {
            temp = (int)Key[i] - '0';
            q.enQueue(&temp);
            
        }
    }

    while (!q.isEmpty()) {
        hashkey += *q.front();
        q.deQueue();
    }
    
    hashkey = hashkey % 71;
    
    return hashkey;
}

template <typename KeyType, typename ItemType>
bool HashTable<KeyType, ItemType>::isEmpty() {
    if (numberOfEntry == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename KeyType, typename ItemType>
void HashTable<KeyType, ItemType>::setNumberOfCollision(int numOfCol) {
    numberOfCollision = numOfCol;
}

template <typename KeyType, typename ItemType>
void HashTable<KeyType, ItemType>::setNumberOfEntry(int numOfEnt) {
    numberOfEntry = numOfEnt;
}

template <typename KeyType, typename ItemType>
void HashTable<KeyType, ItemType>::setTableSize(int size) {
    tableSize = size;
}

template <typename KeyType, typename ItemType>
int HashTable<KeyType, ItemType>::getNumberOfCollision() {
    return numberOfCollision;
}

template <typename KeyType, typename ItemType>
int HashTable<KeyType, ItemType>::getNumberOfEntry() {
    return numberOfEntry;
}

template <typename KeyType, typename ItemType>
int HashTable<KeyType, ItemType>::getTableSize() {
    return tableSize;
}

template <typename KeyType, typename ItemType>
void HashTable<KeyType, ItemType>::insert(KeyType &key, ItemType *item) {
    int index = hashFunc(key);
    HashEntry<KeyType, ItemType> *newEntry = new HashEntry<KeyType, ItemType>(item, key);
    int x = 0;
    while (table[index] != nullptr) {
        if (table[index]->getKey() == key && table[index]->getItem() == item) {
            std::cout << "Data already existed!" << std::endl;
            return;
        }
        if (table[index]->getFlag() == 2) {
            break;
        }
        x++;
        index = (index + x * x) % tableSize;
        double loadFactor = static_cast<double>(numberOfEntry) / tableSize;
        
        if (loadFactor >= 0.8) {
            resize();
        }
    }


    table[index] = newEntry;
    table[index]->setFlag(1);
    numberOfEntry++;
    numberOfCollision += x;
    
}

template <typename KeyType, typename ItemType>
void HashTable<KeyType, ItemType>::remove(KeyType &key) {
    int index = hashFunc(key);
    int x = 0;
    std::string indexKey = table[index]->getKey();
    while (table[index] != nullptr && table[index]->getKey() != key) {
        x++;
        index = (index + x * x) % tableSize;
    }
    if (table[index] == nullptr) {
        std::cout << "No data found!!!" << std::endl;
    }
    else {
        table[index] = nullptr;
        table[index] = new HashEntry<KeyType, ItemType>();
        table[index]->setFlag(2);
        numberOfEntry -= 1;
    }
}

template <typename KeyType, typename ItemType>
bool HashTable<KeyType, ItemType>::find(KeyType &key) {
    int index = hashFunc(key);
    int x = 0;
    while (table[index] != nullptr && table[index]->getKey() != key) {
        x++;
        index = (index + x * x) % tableSize;
    }
    if (table[index] == nullptr) {
        //std::cout << "Invalid Data." << std::endl;
        return false;
    }
    else {
        std::cout << "Key matches! " << std::endl;
        std::cout << *table[index]->getItem() << std::endl;
        //std::cout << "          " << table[index]->getKey() << std::endl;
        return true;
    }
}

template <typename KeyType, typename ItemType>
void HashTable<KeyType, ItemType>::print() {

    for (int i = 0; i < tableSize; i++) {
        if (table[i] != nullptr && table[i]->getFlag() != 2) {
            std::cout << "Index : " << i << std::endl;
            std::cout << *table[i]->getItem() << std::endl;
        }
    }
    
}

template <typename KeyType, typename ItemType>
void HashTable<KeyType, ItemType>::emptyTheTable() {
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
    }
    delete *table;
    *table = nullptr;
    numberOfCollision = 0;
}

template <typename KeyType, typename ItemType>
void HashTable<KeyType, ItemType>::resize() {
    int newSize = 2 * tableSize;
    HashEntry<KeyType, ItemType> **newTable = new HashEntry<KeyType, ItemType> *[newSize];
    int newNumberOfCollision = 0;
    for (int i = 0; i < newSize; i++) {
        newTable[i] = nullptr;
    }
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != nullptr) {
            if (table[i]->getFlag() == 1) {
                KeyType key = table[i]->getKey();
                int index = hashFunc(key);
                int x = 0;
                while (newTable[index] != nullptr) {
                    x++;
                    index = (index + (x*x)) % newSize;
                    newNumberOfCollision++;
                }
                newTable[index] = table[i];
            }
        }
    }

    emptyTheTable();
    table = newTable;
    setTableSize(newSize);
    numberOfCollision = newNumberOfCollision;
}
