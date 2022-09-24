#ifndef binary_node
#define binary_node
#include <iostream>

template <typename T>
class BinaryNode{
private:
    T * item;
    BinaryNode *left;
    BinaryNode *right;
public:
    // default constructor:
    BinaryNode();
    
    // constructor:
    BinaryNode(T * anItem);
    BinaryNode(T * anItem, BinaryNode *leftPtr, BinaryNode *rightPtr);
    
    /*set a value to the item
     @ pre None
     @ post The item will store that value.
     
     @ param anItem The value that will be set to the item.
     */
    void setItem(T * anItem);
    
    /*set a pointer to the left
     @ pre None
     @ post The left will point to the pointer pass in parameter.
     
     @ param leftPtr The pointer that will be set to the left.
     */
    void setLeft(BinaryNode *leftPtr);
    
    /*set a pointer to the right
     @ pre None
     @ post The right will point to the pointer pass in parameter.
     
     @ param rightPtr The pointer that will br set to the right.
     */
    void setRight(BinaryNode *rightPtr);
    
    /* return item */
    T * getItem() const;
    
    /* return left */
    BinaryNode * getLeft();
    
    /* return right */
    BinaryNode * getRight();
    
    /* check if the node has children or not.
     @ pre None
     @ post If the right or left of the node are null, return true.
        Otherwise, return false.
     
     @ return boolean
     */
    bool isLeaf() const;
    
    bool operator >= (BinaryNode<T> &r);
    bool operator <= (BinaryNode<T> &r);
};

template <typename T>
bool BinaryNode<T>::operator >= (BinaryNode<T> &r) {
    return (*this->getItem() > *r.getItem() || *this->getItem() == *r.getItem());
}

template <typename T>
bool BinaryNode<T>::operator <= (BinaryNode<T> &r) {
    return (*this->getItem() < *r.getItem() || *this->getItem() == *r.getItem());
}

template <typename T>
BinaryNode<T>::BinaryNode(){
    left = nullptr;
    right = nullptr;
};

template <typename T>
BinaryNode<T>::BinaryNode(T * anItem){
    item = anItem;
    left = nullptr;
    right = nullptr;
};

template <typename T>
BinaryNode<T>::BinaryNode(T * anItem, BinaryNode *leftPtr, BinaryNode *rightPtr){
    item = anItem;
    left = leftPtr;
    right = rightPtr;
};

template <typename T>
void BinaryNode<T>::setItem(T * anItem){
    item = anItem;
};

template <typename T>
void BinaryNode<T>::setLeft(BinaryNode *leftPtr){
    left = leftPtr;
};

template <typename T>
void BinaryNode<T>::setRight(BinaryNode *rightPtr){
    right = rightPtr;
};

template <typename T>
T * BinaryNode<T>::getItem() const{
    return item;
};

template <typename T>
BinaryNode<T> * BinaryNode<T>::getLeft(){
    return left;
};

template <typename T>
BinaryNode<T> * BinaryNode<T>::getRight(){
    return right;
};

#endif /* bst_ADT_h */
