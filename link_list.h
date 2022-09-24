#ifndef link_list_h
#define link_list_h

#include "link_node.h"
#include "list_interface.h"

#include <iostream>

template <typename T>
class LinkedList{
private:
    int itemCount;
    LinkNode<T> * headPtr;
    LinkNode<T> * tailPtr;
    int sortType;

    /*Get the node at the given position.
    @ pre None
    @ post the node of that position will be found,
    and a pointer point to it will be return.

    @ param position The position of the node that is wanted.
    @ return a pointer to the node of the given position.
    */
    LinkNode<T> * getNode(int position) const;
public:
    /*Default constructor*/
    LinkedList();

    /*Constructor
    Set a value to sortType arttribute.
    @param s Determine which type of list is that.*/
    LinkedList(int s);

    /*Copy constructor*/
    LinkedList(const LinkedList<T> & aList);

    /*Destructor*/
    ~LinkedList();

    /*@setter Set the itemCount to iCount*/
    void setItemCount(int iCount);

    /*@getter Return itemCount*/
    int numberOfItemInList() const;

    /*@setter Set nodePtr to headPtr*/
    void setHeadPtr(LinkNode<T> *nodePtr);

    /*@getter Return headPtr*/
    LinkNode<T> * getHeadPtr() const;

    /*@setter Set nodePtr to tailPtr*/
    void setTailPtr(LinkNode<T> *nodePtr);

    /*@getter Return tailPtr*/
    LinkNode<T> * getTailPtr() const;

    /*@setter Set s to sortType*/
    void setSortType(int s);

    /*@getter Return sortType*/
    int getSortType()const;

    bool isEmpty() const;
    void insertData(int newPosition, T * data);
    void removeData(int position);

    T * getData(int position) const;

    void emptyTheList();
    void print();
    void replaceItem(int position, T * newData);

    /*If the sortType is 1, it will added to the list as a ascending order list.
    If the sortType is 2, it will added to the list as a decending order list.
    If the sortType is 3, it will added to the list as a unsorted order list.
    */
    void addData(T * data);

    int search(T * data);
};

#endif /* link_list_h */
