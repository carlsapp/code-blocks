#ifndef SINGLE_LINKED_LIST_H_
#define SINGLE_LINKED_LIST_H_

// This is a Carl Sapp basic implementation of a singly-linked list. There are very few
// situations where you would actually use this implementation. You would instead use the
// C++ STL list (http://en.cppreference.com/w/cpp/container/list).
//
//     https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/stl_list.h
//     

#define INCLUDE_ERR_CHECKS
#define OPTIMIZE_LEN

#include <iostream>
#ifdef INCLUDE_ERR_CHECKS
#include <stdexcept>
#endif

template<typename T>
class SingleLinkedListNode
{
public:
        T data;
        SingleLinkedListNode<T> * next;
        SingleLinkedListNode<T>()       : data(NULL), next(NULL) { };
        SingleLinkedListNode<T>(T data) : data(data), next(NULL) { };
        SingleLinkedListNode<T> * append(T data);
        void setPrev(SingleLinkedListNode<T> * prevNode);
        void setNext(SingleLinkedListNode<T> * nextNode);
};

template<typename T>
SingleLinkedListNode<T> * SingleLinkedListNode<T>::append(T data)
{
    SingleLinkedListNode<T> * newNode = new SingleLinkedListNode<T>(data);
    setNext(newNode);
    return newNode;
}

template<typename T>
void SingleLinkedListNode<T>::setPrev(SingleLinkedListNode<T> * prevNode)
{
    // I know it seems silly to have this function. But, its so that a doubly
    // linked list can reuse most of the code and just modify these
    // implementations
    prevNode->next = this;
}

template<typename T>
void SingleLinkedListNode<T>::setNext(SingleLinkedListNode<T> * nextNode)
{
    // I know it seems silly to have this function. But, its so that a doubly
    // linked list can reuse most of the code and just modify these
    // implementations
    next = nextNode;
}


template<typename T>
class SingleLinkedList
{
private:
    SingleLinkedListNode<T> * _head;
    #ifdef OPTIMIZE_LEN
    unsigned int size;
    #endif
public:
        // We are going to give our linked list a frankenstein like list of methods where
        // we kinda look like a Python list. But, a Python list is implemented as a
        // vector/array, so ours will be a little different. We don't want to look identical
        // to the STL, cause that'd just be re-inventing the wheel.
        SingleLinkedList() : _head(NULL) { };
        SingleLinkedList(T valueArray[], unsigned int arrayLen);
        void append(T data);
        void extend(SingleLinkedList<T> * anotherList);
        void insert(unsigned int index, T data);
        void remove(T matchData);
        void pop();
        void pop(unsigned int index);
        void clear();
        void index(T matchData);
        unsigned int count(T matchData);
        unsigned int len();
        T get(unsigned int index);
        void debug_print();
        void print();
        SingleLinkedListNode<T> * head();
        SingleLinkedListNode<T> * tail();
};

template<typename T>
SingleLinkedList<T>::SingleLinkedList(T valueArray[], unsigned int arrayLen)
{
    // There's an assumption here that if you're going to use this function,
    // arrayLen will not be 0. If that's the case, you should use the regular
    // constructor.
    SingleLinkedListNode<T> * currentNode = _head = new SingleLinkedListNode<T>(valueArray[0]);
    for (unsigned int i = 1; i < arrayLen; i++) {
        currentNode = currentNode->append(valueArray[i]);
    }
}

template<typename T>
void SingleLinkedList<T>::debug_print()
{
    std::cout << "Singly-linked List:" << std::endl;
    std::cout << "  Head: " << head() << std::endl;
    if (head() == NULL) {
        return;
    }
    unsigned int index = 0;
    SingleLinkedListNode<T> * currentNode = head();
    while (currentNode != NULL) {
        std::cout << "  " << index++ << ": " << currentNode->data << " (Next: " << currentNode->next << ")" << std::endl;
        currentNode = currentNode->next;
    }
}

template<typename T>
void SingleLinkedList<T>::print()
{
    std::cout << "[";
    if (_head == NULL) {
        return;
    }
    unsigned int index = 0;
    SingleLinkedListNode<T> * currentNode = _head;
    while (currentNode != NULL) {
        if (index > 0) {
            std::cout << ", ";
        }
        std::cout << currentNode->data;
        currentNode = currentNode->next;
        index++;
    }
    std::cout << "]";
}

template<typename T>
void SingleLinkedList<T>::append(T data)
{
    SingleLinkedListNode<T> * curTail = tail();
    if (curTail == NULL) {
        _head = new SingleLinkedListNode<T>(data);
        return;
    }
    curTail->append(data);
}

template<typename T>
void SingleLinkedList<T>::extend(SingleLinkedList<T> * anotherList)
{
    if (_head == NULL) {
        // Our list is empty. We'll just consume anotherList.
        _head = anotherList->head();
        return;
    }
    tail()->setNext(anotherList);
    setTail(anotherList->tail());
}

template<typename T>
T SingleLinkedList<T>::get(unsigned int index)
{
    SingleLinkedListNode<T> * currentNode = _head;
    for (unsigned int i = 0; i < index; i++) {
        #ifdef INCLUDE_ERR_CHECKS
        if (currentNode->next == NULL) {
            throw std::runtime_error("List index out of range.");
        }
        #endif
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template<typename T>
SingleLinkedListNode<T> * SingleLinkedList<T>::head()
{
    return _head;
}

template<typename T>
SingleLinkedListNode<T> * SingleLinkedList<T>::tail()
{
    if (_head == NULL) {
        return NULL;
    }
    SingleLinkedListNode<T> * currentNode = _head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    return currentNode;
}

template<typename T>
unsigned int SingleLinkedList<T>::len()
{
    #ifdef OPTIMIZE_LEN
        return size;
    #endif
    unsigned int ourLen = 0;
    SingleLinkedListNode<T> * currentNode = _head;
    while (currentNode != NULL) {
        currentNode = currentNode->next;
        ourLen++;
    }
    return ourLen;
}

#endif /* SINGLE_LINKED_LIST_H_ */
