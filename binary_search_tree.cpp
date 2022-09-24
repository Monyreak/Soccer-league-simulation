#include "binary_search_tree.h"
#include <iomanip>

template <typename T>
void BinarySearchTree<T>::printTree() {
    printIndentedTree(root, 0);
}

template <typename T>
void BinarySearchTree<T>::printIndentedTree(BinaryNode<T> *subtreePtr, int indent) {
    if (subtreePtr == nullptr) {
        std::cout << std::setw(indent) << "NULL   " << "\n";
        
        return;
    }
    
    T temp = *subtreePtr->getItem();
    std::cout << std::setw(indent) << temp.getName() << temp.getAge() << "\n";
    
    printIndentedTree(subtreePtr->getRight(), indent+16);
    
    printIndentedTree(subtreePtr->getLeft(), indent+16);
}






template <typename T>
BinaryNode <T> * BinarySearchTree<T>::insert (BinaryNode <T> *subTreePtr, BinaryNode <T> *newNode){
    if (subTreePtr == nullptr){
        return newNode;
    }
    else{
        T *temp1 = subTreePtr->getItem();
        T *temp2 = newNode->getItem();
        temp1->setKey(3);
        temp2->setKey(3);
        if (*temp1 > *temp2){
            subTreePtr->setLeft(insert(subTreePtr->getLeft(), newNode));
        }
        else{
            subTreePtr->setRight(insert(subTreePtr->getRight(), newNode));
        }
    }
    return subTreePtr;
}

template <typename T>
BinaryNode<T> * BinarySearchTree<T>::remove(BinaryNode<T> *subTreePtr, BinaryNode<T> *target){
    BinaryNode<T> *temp;
    
    T sub = *subTreePtr->getItem();
    T tar = *target->getItem();
    sub.setKey(3);
    tar.setKey(3);

    if (subTreePtr == nullptr){
        return subTreePtr;
    }
    else if (sub > tar){
        subTreePtr->setLeft(remove(subTreePtr->getLeft(), target));
    }
    else if (sub < tar){
        //BinaryNode<T> *t = subTreePtr->getRight();
        subTreePtr->setRight(remove(subTreePtr->getRight(), target));
    }
    else if (sub == tar){
        if (subTreePtr->getRight() && subTreePtr->getLeft()){
            temp = findMin(subTreePtr->getRight());
            T *tempItem = temp->getItem();
            subTreePtr->setItem(tempItem);
            subTreePtr->setRight(remove(subTreePtr->getRight(), temp));
        }
        else {
            temp = subTreePtr;
            if (subTreePtr->getRight() == nullptr){
                subTreePtr = subTreePtr->getLeft();
            }
            else {
                subTreePtr = subTreePtr->getRight();
            }
            delete temp;
        }
    }
    else {
        subTreePtr->setRight(remove(subTreePtr->getRight(), target));
    }
    return subTreePtr;
}

template <typename T>
BinaryNode<T> * BinarySearchTree<T>::findMin(BinaryNode<T> *subtreePtr){
    if (subtreePtr == nullptr){
        return nullptr;
    }
    else if (subtreePtr->getLeft() == nullptr){
        return subtreePtr;
    }
    else{
        return findMin(subtreePtr->getLeft());
    }
}

template <typename T>
BinaryNode<T> * BinarySearchTree<T>::findMax(BinaryNode<T> *subtreePtr){
    if (subtreePtr == nullptr){
        return nullptr;
    }
    else if (subtreePtr->getRight() == nullptr){
        return subtreePtr;
    }
    else{
        return findMax(subtreePtr->getRight());
    }
}

template <typename T>
BinaryNode<T> * BinarySearchTree<T>::emptyTheTree(BinaryNode<T> *subtreePtr){
    if (subtreePtr == nullptr){
        return subtreePtr;
    }
    emptyTheTree(subtreePtr->getLeft());
    emptyTheTree(subtreePtr->getRight());
    delete subtreePtr;
    
    subtreePtr = nullptr;
    
    return nullptr;
}

template <typename T>
BinaryNode<T> * findNode (BinaryNode<T> *subtreePtr, BinaryNode<T> *target){
    if (subtreePtr->getItem() == target->getItem()){
        return subtreePtr;
    }
    else if (subtreePtr->getItem() > target->getItem()){
        return findNode(subtreePtr->getLeft(), target);
    }
    else if (subtreePtr->getItem() < target->getItem()){
        return findNode(subtreePtr->getRight(), target);
    }
    else {
        return subtreePtr;
    }
}

template <typename T>
void BinarySearchTree<T>::breadthFirst_traversal(BinaryNode<T> *subtreePtr/*, std::ostream & outputFile*/) const {
    queue<BinaryNode<T>> q;
    BinaryNode<T> *temp = subtreePtr;
    q.enQueue(temp);
    std::string str = "";
    while (!q.isEmpty()){
        temp = q.front();
        std::cout << *temp->getItem() << "\n";
//        outputFile << *temp->getItem() << "\n";

        if (temp->getLeft()){
            BinaryNode<T> *tempLeft = temp->getLeft();
            q.enQueue(tempLeft);
        }
        if (temp->getRight()){
            BinaryNode<T> *tempRight = temp->getRight();
            q.enQueue(tempRight);
        }
        q.deQueue();
    }
}

template <typename T>
void  BinarySearchTree<T>::preorderTraverse(BinaryNode<T> * subtreePtr/*, std::ostream & outputFile*/) const {
    
    if (subtreePtr == nullptr)
        return;

    std::cout << *subtreePtr->getItem() << "\n";
//    outputFile << *subtreePtr->getItem() << "\n";

    preorderTraverse(subtreePtr->getLeft());
    
    preorderTraverse(subtreePtr->getRight());
    
}

template <typename T>
void BinarySearchTree<T>::inorderTraverse(BinaryNode<T> * subtreePtr/*, std::ostream & outputFile*/) const {
    if (subtreePtr == nullptr)
        return;

    inorderTraverse(subtreePtr->getLeft());
    
    std::cout << *subtreePtr->getItem() << "\n";
//    outputFile << *subtreePtr->getItem() << "\n";
    
    inorderTraverse(subtreePtr->getRight());
}

template <typename T>
void BinarySearchTree<T>::postorderTraverse(BinaryNode<T> * subtreePtr/*, std::ostream & outputFile*/) const {
    if (subtreePtr == nullptr)
    return;
    
    
    postorderTraverse(subtreePtr->getLeft());
    
    postorderTraverse(subtreePtr->getRight());
    
    std::cout << *subtreePtr->getItem() << "\n";
    //outputFile << *subtreePtr->getItem() << "\n";
}

template <typename T>
bool BinarySearchTree<T>::isEmpty(BinaryNode<T> *subtreePtr){
    if (subtreePtr == nullptr){
        return true;
    }
    return false;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(){
    root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const T * rootItem){
    root = new BinaryNode<T>(rootItem);
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree <T> &tree){
    root = new BinaryNode<T>(tree.root);
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    emptyTheTree(this->root);
}

template <typename T>
void BinarySearchTree<T>::insert(T * newItem){
    BinaryNode<T> *newNode = new BinaryNode<T>(newItem);
    root = insert(this->root, newNode);
}

template <typename T>
void BinarySearchTree<T>::getNumOfNode(BinaryNode<T> * subtreePtr, int &total) {
    
    if (subtreePtr == nullptr)
        return;
    
    total += 1;
    
    getNumOfNode(subtreePtr->getLeft(), total);
    
    getNumOfNode(subtreePtr->getRight(), total);
    
}

template <typename T>
void BinarySearchTree<T>::remove(T * newItem){
    if (isEmpty(root)){
        std::cout << "Remove fail! The tree is empty." << std::endl;
    }
    else{
        BinaryNode<T> target(newItem);
        BinaryNode<T> *ptr = &target;
        //BinaryNode<T> *target = new BinaryNode<T>(newItem);
        root = remove(this->root, ptr);
    }
}

//template <typename T>
//std::ostream &operator << (std::ostream & strm, BinarySearchTree<T> &tree){
//    BinaryNode<T> *rootRef = tree.root;
//    int choice = 0;
//    strm << "Please choose one of traversal mechanism you want to use...:" << std::endl;
//    strm << "1. breadthFirst_traversal" << std::endl;
//    strm << "2. preorderTraverse" << std::endl;
//    strm << "3. inorderTraverse" << std::endl;
//    strm << "4. postorderTraverse" << std::endl;
//
//    strm << "Your choice: ";
//    std::cin >> choice;
//    switch (choice) {
//        case 1:
//            tree.breadthFirst_traversal(rootRef);
//            break;
//        case 2:
//            tree.preorderTraverse(rootRef);
//            break;
//        case 3:
//            tree.inorderTraverse(rootRef);
//            break;
//        case 4:
//            tree.postorderTraverse(rootRef);
//            break;
//        default:
//            std::cout << "Your choice is invalid." << std::endl;
//            break;
//    }
//    return strm;
//}

template<typename T>
void BinarySearchTree<T>::emptyTheTree(){
    root = emptyTheTree(this->root);
    
}

template <typename T>
BinaryNode<T> * BinarySearchTree<T>::search(T &target){
    if (isEmpty(root)){
        std::cout << "Search fail! The tree is empty." << std::endl;
    }
    else{
        BinaryNode<T> * targetNode = new BinaryNode<T>(target);
        returnfindNode(root, targetNode);
    }
    
}

template <typename T>
void BinarySearchTree<T>::print(/*std::ostream &outputFile*/){
    if (isEmpty(root)){
        std::cout << "Print fail! The tree is empty." << std::endl;
    }
    else{
        BinaryNode<T> *rootRef = this->root;
        
        inorderTraverse(rootRef);
    
        int total = 0;
        getNumOfNode(rootRef, total);
        std::cout << "\nNumber of elements: " << total;
    }
}
