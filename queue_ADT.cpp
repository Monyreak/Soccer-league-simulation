#include "queue_ADT.h"

template <typename T>
void queue<T>::enQueue(T *data) {
    LinkedList<T>::setSortType(3);
//    std::cout << "Adding '" << data << "' to the queue..." << std::endl;
    LinkedList<T>::addData(data);
}

template <typename T>
void queue<T>::deQueue() {
    if (isEmpty()) {
        std::cout << "The queue is empty!" << std::endl;
    }
    else {
//        std::cout << "Removing '" << LinkedList<T>::getData(1) << "' from the queue..." << std::endl;
        LinkedList<T>::removeData(1);
    }
}

template <typename T>
int queue<T>::size() {
    return LinkedList<T>::numberOfItemInList();
}

template <typename T>
T * queue<T>::front() {
    if (!isEmpty()) {
        return LinkedList<T>::getData(1);
    }
    else {
        throw ("No data found!");
    }
}

template <typename T>
T * queue<T>::rear() {
    if (!isEmpty()) {
        return LinkedList<T>::getData(size());
    }
    else {
        throw ("No data found!");
    }
}

template <typename T>
bool queue<T>::isEmpty() {
    if (size() == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
void queue<T>::printData() {
    if (isEmpty()) {
        std::cout << "The queue is empty!" << std::endl;
    }
    else {
        LinkedList<T>::print();
    }
}

template <typename T>
void queue<T>::emptyTheQueue() {
    if (!isEmpty()) {
        LinkedList<T>::emptyTheList();
    }
}
