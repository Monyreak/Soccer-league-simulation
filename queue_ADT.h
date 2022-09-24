#ifndef queue_ADT_h
#define queue_ADT_h

#include "link_list.h"
#include "link_list.cpp"

template <typename T>
class queue : private LinkedList<T> {
public:
    /*Add new data to the queue.
    @ pre None
    @ post calling addData function from
    the base class (LinkedList).

    @param data The value that is wanted to add into the queue.
    */
    void enQueue(T *data);

    /*Remove the first data of the queue.
    @ pre check if the queue is empty.
    @ post if the queue is empty, print a message.
    if not, removeData frunction from the base class will be called(LinkedList).
    the function will remove the first data of the queue.
    */
    void deQueue();

    /*Return the size of the queue.*/
    int size();

    /*Return the first data of the queue.
    @ pre None
    @ post If the queue is empty, throw a message.
    if not, return the first data of the queue.

    @ return first data of the queue.
    */
    T * front();


    /*Return the last data of the queue.
    @ pre None
    @ post If the queue is empty, throw a message.
    if not, return the last data of the queue.

    @ return last data of the queue.
    */
    T * rear();

    /*check if the queue is empty or not.*/
    bool isEmpty();

    /*Print all the data from the queue.
    @ pre None
    @ post if the queue is empty, print out a message.
    If not, print out all the data from the queue.
    */
    void printData();

    /*Delete all the data in the queue.*/
    void emptyTheQueue();
};

#endif /* queue_ADT_h */
