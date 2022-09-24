#ifndef link_node_h
#define link_node_h

template <typename T>
class LinkNode {
private:
    T * data;
    LinkNode *next;
public:
    // default constructor
    LinkNode();

    // contructor
    LinkNode(T * d);

    /* set a value to the data
    @ pre None
    @ post The data will hold that value.

    @ param d The value that will be set to the data.
    */
    void setData(T * d);

    /* set a pointer to the next pointer.
    @ pre None
    @ post The next pointer will point to the pointer pass in parameter.

    @ param n The pointer that will be set to the next pointer.
    */
    void setNext(LinkNode *n);

    /* return data */
    T * getData() const;

    /* return pointer next*/
    LinkNode* getNext() const;
};

template <typename T>
LinkNode<T>::LinkNode() {
    next = nullptr;
}

template <typename T>
LinkNode<T>::LinkNode(T * d) {
    data = d;
    next = nullptr;
}

template <typename T>
void LinkNode<T>::setData(T * d) {
    data = d;
}

template <typename T>
void LinkNode<T>::setNext(LinkNode<T> *n) {
    next = n;
}

template <typename T>
T * LinkNode<T>::getData() const {
    return data;
}

template <typename T>
LinkNode<T>* LinkNode<T>::getNext() const {
    return next;
}

#endif /* link_node_h */

