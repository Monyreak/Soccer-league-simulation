#include "hash_entry.h"

template <typename KeyType, typename ItemType>
HashEntry<KeyType, ItemType>::HashEntry() {
    flag = 0;
}

template <typename KeyType, typename ItemType>
HashEntry<KeyType, ItemType>::HashEntry(ItemType *i, KeyType &k) {
    item = i;
    key = k;
    flag = 0;
}

template <typename KeyType, typename ItemType>
void HashEntry<KeyType, ItemType>::setKey(KeyType &k) {
    key = k;
}

template <typename KeyType, typename ItemType>
void HashEntry<KeyType, ItemType>::setItem(ItemType *i) {
    item = i;
}

template <typename KeyType, typename ItemType>
void HashEntry<KeyType, ItemType>::setFlag(int f) {
    flag = f;
}

template <typename KeyType, typename ItemType>
KeyType HashEntry<KeyType, ItemType>::getKey() const {
    return key;
}

template <typename KeyType, typename ItemType>
ItemType * HashEntry<KeyType, ItemType>::getItem() const {
    return item;
}

template <typename KeyType, typename ItemType>
int HashEntry<KeyType, ItemType>::getFlag() const {
    return flag;
}

//template <typename KeyType, typename ItemType>
//HashEntry<KeyType, ItemType> * HashEntry<KeyType, ItemType>:: operator = (HashEntry<KeyType, ItemType> * anEntry){
//    item = anEntry->getItem();
//    key = anEntry->getKey();
//}
