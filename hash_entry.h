#ifndef hash_entry_h
#define hash_entry_h

template <typename KeyType, typename ItemType>
class HashEntry {
private:
    ItemType * item;
    KeyType key;

    /*
    flag = 0 : data does not exist
    flag = 1 : data exist
    flag = 2 : data was present at least once
    */
    int flag;
public:
    /*constructor*/
    HashEntry();
    HashEntry(ItemType *i, KeyType &k);

    /*setter*/
    void setKey(KeyType &k);
    void setItem(ItemType *i);
    void setFlag(int f);

    /*getter*/
    KeyType getKey() const;
    ItemType * getItem() const;
    int getFlag() const;
};

#endif /* hash_entry_h */
