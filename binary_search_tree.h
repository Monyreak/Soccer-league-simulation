#ifndef binary_search_tree_h
#define binary_search_tree_h
#include "binary_node.h"
#include "queue_ADT.cpp"
#include <iostream>
#include <fstream>

template<typename T>
class BinarySearchTree;

template<typename T>
std::ostream &operator << (std::ostream & strm, BinarySearchTree<T> &tree);

template<typename T>
class BinarySearchTree {
private:
    BinaryNode<T> *root;
protected:
    /* Insert the newNode to the tree
     @ pre None
     @ post The newNode will be stored in appropriate place in the tree.
     
     @ param subtreePtr A pointer point to the node in the tree.
            newNode The node that wanted to add to the tree.
     
     @ return newNode
    */
    BinaryNode<T> * insert(BinaryNode<T> *subTreePtr, BinaryNode<T> *newNode);
    
    
    /* Remove the target from the tree
     @ pre None
     @ post The target will be remove from the tree.
     
     @ param subtreePtr A pointer point to the node in the tree.
            target The node that wanted to delete from the tree.
     
     @ return target
     */
    BinaryNode<T> * remove(BinaryNode<T> *subtreePtr, BinaryNode<T> *target);
    
    
    /* Find the minimum value in the tree
     @ pre None
     @ post found the smallest value in the tree.
     
     @ param subtreePtr A pointer point to the node in the tree.
     
     @ return a node contains the smallest value.
     */
    BinaryNode<T> * findMin(BinaryNode<T> *subtreePtr);
    
    /* Find the maximum value in the tree
     @ pre None
     @ post Found the biggest value in the tree.
     
     @ param subtreePtr A pointer point to the node in the tree.
     
     @ return a node contain the biggest value.
     */
    BinaryNode<T> * findMax(BinaryNode<T> *subtreePtr);
        
    /* Delete all the node in the tree
     @ pre None
     @ post The tree is empty.
     
     @ param subtreePtr A pointer point to the node in the tree.
     
     @ return an empty root node.
     */
    BinaryNode<T> * emptyTheTree(BinaryNode<T> *subtreePtr);
    
    /* Find the wanted node in the tree
     @ pre None
     @ post Found the wanted node the the tree.
     
     @ param subtreePtr A pointer point to the node in the tree.
            target The node that wanted to find in the tree.
     
     @ return target
     */
    BinaryNode<T> * findNode (BinaryNode<T> *subtreePtr, BinaryNode<T> *target);
    
    /* Display the item in Breadth-first traversal
     @ pre None
     @ post print all the item in the tree in Breadth-first traversal mechanisms in that sequence.
     
     @ param subtreePtr A pointer point to the node in the tree.
     */
    void breadthFirst_traversal (BinaryNode<T> * subtreePtr/*, std::ostream & outputFile*/) const;
    
    /* Display the item in preorder traversal
     @ pre None
     @ post Print all the item in the tree in preorder traversal machenisms in that sequenece
     
     @ param subtreePtr A pointer point to the node in the tree.
     */
    void preorderTraverse (BinaryNode<T> * subtreePtr/*, std::ostream & outputFile*/) const;

    /* Display the item in inorder traversal
    @ pre None
    @ post Print all the item in the tree in inorder traversal machenisms in that sequenece

    @ param subtreePtr A pointer point to the node in the tree.
    */
    void inorderTraverse (BinaryNode<T> * subtreePtr/*, std::ostream & outputFile*/) const;

    /* Display the item in postorder traversal
    @ pre None
    @ post Print all the item in the tree in postorder traversal machenisms in that sequenece

    @ param subtreePtr A pointer point to the node in the tree.
    */
    void postorderTraverse (BinaryNode<T> * subtreePtr/*, std::ostream & outputFile*/) const;
    
    void printIndentedTree (BinaryNode<T> * subtreePtr, int indent);
    
    bool isEmpty(BinaryNode<T> * subtreePtr);

public:
    /* Constructor */
    BinarySearchTree();
    BinarySearchTree(const T * rootItem);
    BinarySearchTree(const BinarySearchTree <T> &tree);

    /* Destructor */
    ~BinarySearchTree();
    
    void getNumOfNode(BinaryNode<T> * subtreePtr, int &total);
    
    void insert(T * newItem);
    void remove(T * newItem);
    
    void emptyTheTree();
    
    BinaryNode<T> * search(T & target);
    
    void print(/*std::ostream &outputFile*/);
    void printTree ();
//    friend std::ostream &operator << <>(std::ostream & strm, BinarySearchTree<T> &tree);
};
    


#endif /* binary_search_tree_h */
