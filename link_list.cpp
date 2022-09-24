#include "link_list.h"

template <typename T>
LinkNode<T> * LinkedList<T>::getNode(int position) const {
    LinkNode<T> *curPtr = headPtr;
    for (int i = 1; i < position; i++) {
        curPtr = curPtr->getNext();
    }
    return curPtr;
}

template <typename T>
LinkedList<T>::LinkedList() {
    itemCount = 0;
    headPtr = nullptr;
    tailPtr = nullptr;
    sortType = 0;
}

template <typename T>
LinkedList<T>::LinkedList(int s) {
    itemCount = 0;
    headPtr = nullptr;
    tailPtr = nullptr;
    sortType = s;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & aList) {
    itemCount = aList.itemCount;
    headPtr = new LinkNode<T>(aList.headPtr);
    tailPtr = new LinkNode<T>(aList.tailPtr);
    sortType = aList.getSortType();
}

template <typename T>
LinkedList<T>::~LinkedList() {
    emptyTheList();
}

template <typename T>
void LinkedList<T>::setItemCount(int iCount) {
    itemCount = iCount;
}

template <typename T>
int LinkedList<T>::numberOfItemInList() const {
    return itemCount;
}

template <typename T>
void LinkedList<T>::setHeadPtr(LinkNode<T> *nodePtr)
{
    headPtr = nodePtr;
}

template <typename T>
LinkNode<T> * LinkedList<T>::getHeadPtr() const {
    return headPtr;
}

template <typename T>
void LinkedList<T>::setTailPtr(LinkNode<T> *nodePtr) {
    tailPtr = nodePtr;
}

template <typename T>
LinkNode<T> * LinkedList<T>::getTailPtr()const {
    return tailPtr;
}

template <typename T>
void LinkedList<T>::setSortType(int s) {
    sortType = s;
}

template <typename T>
int LinkedList<T>::getSortType()const {
    return sortType;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    if (headPtr == nullptr)
        return true;
    else
        return false;
}

template <typename T>
void LinkedList<T>::insertData(int newPosition, T *data) {
    if (newPosition >= 1 && newPosition <= numberOfItemInList() + 1) {
        LinkNode<T> * newNodePtr = new LinkNode<T>(data);
        if (newPosition == 1) {
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else {
            LinkNode<T> *prevPtr = getNode(newPosition - 1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }
        itemCount++;
    }
    else {
        std::cout << "Inserting data unsuccessful due to invalid position." << std::endl;
    }
}

template <typename T>
void LinkedList<T>::removeData(int position) {
    if (position >= 1 && position <= numberOfItemInList()) {
        LinkNode<T> *curPtr = nullptr;
        if (position == 1) {
            curPtr = headPtr;
            headPtr = headPtr->getNext();
        }
        else {
            LinkNode<T> *prevPtr = getNode(position - 1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
            if (position == numberOfItemInList()) {
                tailPtr = prevPtr;
            }
        }
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--;
    }
    else {
        std::cout << "Removing data unsuccessful due to invalid position." << std::endl;
    }
}

template <typename T>
T * LinkedList<T>::getData(int position)const {
    if (position >= 1 && position <= numberOfItemInList()) {
        LinkNode<T> * nodePtr = getNode(position);
        return nodePtr->getData();
    }
    else {
        throw ("Invalid position.");
    }
}

template <typename T>
void LinkedList<T>::emptyTheList() {
    LinkNode<T> * curPtr = headPtr;
    while (curPtr != nullptr) {
        LinkNode<T> *next = curPtr->getNext();
        delete curPtr;
        curPtr = next;
    }
    headPtr = nullptr;
    tailPtr = nullptr;
    setItemCount(0);
}

template <typename T>
void LinkedList<T>::print() {
    LinkNode<T> *curPtr = headPtr;
    for (int i = 1; i <= numberOfItemInList(); i++) {
        std::cout << *curPtr->getData() << " ";
        std::cout << std::endl;
        curPtr = curPtr->getNext();
    }
    std::cout << "\nNumber of elements: " << numberOfItemInList();
}

template <typename T>
void LinkedList<T>::replaceItem(int position, T * newData) {
    if (position >= 1 && position <= numberOfItemInList()) {
        LinkNode<T> * nodePtr = getNode(position);
        nodePtr->setData(newData);
    }
    else {
        std::cout << "Replacing data unsuccessful due to invalide position." << std::endl;
    }
}

template <typename T>
int LinkedList<T>::search(T *data) {
    LinkNode<T> * nodePtr = nullptr;

    for (int i = 1; i <= numberOfItemInList(); i++) {
        nodePtr = getNode(i);
        if (*nodePtr->getData() == *data) {
            return i;
        }
    }
    return -1;

}

template <typename T>
void LinkedList<T>::addData(T * data) {
    
    LinkNode<T> * newNode = new LinkNode<T>(data);
    LinkNode<T> * curPtr = nullptr;
    LinkNode<T> * prevPtr = nullptr;

    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
        itemCount++;
    }
    else {
        switch (sortType) {
        case 1:
            {// ascending order
            curPtr = headPtr;
            prevPtr = headPtr;
            T cur = *curPtr->getData();
            T node = *newNode->getData();
                
            if (cur >= node) {
                headPtr = newNode;
                newNode->setNext(curPtr);
                itemCount++;
                break;
            }
                T tail = *tailPtr->getData();
                
            if (tail <= node) {
                tailPtr->setNext(newNode);
                tailPtr = newNode;
                itemCount++;
                break;
            }
            while (curPtr->getNext() != nullptr) {
                curPtr = curPtr->getNext();
                T prev = *prevPtr->getData();
                
                cur = *curPtr->getData();
                
                if (prev <= node && node <= cur) {
                    prevPtr->setNext(newNode);
                    newNode->setNext(curPtr);
                    itemCount++;
                    break;
                }
                else {
                    prevPtr = prevPtr->getNext();
                }
            }
            break;
            }
        case 2: // decending order
            {
            curPtr = headPtr;
            prevPtr = headPtr;
            if (curPtr->getData() <= newNode->getData()) {
                headPtr = newNode;
                newNode->setNext(curPtr);
                itemCount++;
                break;
            }
            if (tailPtr->getData() >= newNode->getData()) {
                tailPtr->setNext(newNode);
                tailPtr = newNode;
                itemCount++;
                break;
            }
            while (curPtr->getNext() != nullptr) {
                curPtr = curPtr->getNext();
                if (prevPtr->getData() >= newNode->getData() && newNode->getData() >= curPtr->getData()) {

                    prevPtr->setNext(newNode);
                    newNode->setNext(curPtr);
                    itemCount++;
                    break;
                }
                else {
                    prevPtr = prevPtr->getNext();
                }
            }
            break;
            }
        case 3: // unsorted order
            tailPtr->setNext(newNode);
            tailPtr = newNode;
            itemCount++;
            break;
        }
    }
    
    
}
