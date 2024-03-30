//
//  Queue.hpp
//  PIC10B
//
//  Created by Sunny Xiao on 3/6/24.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include <string>

class Node{
public:
    Node();
    ~Node();
    Node(std::string, Node*);
private:
    const std::string name;
    Node* prev;
    friend class Iterator;
    friend class Queue;
};

class Queue;

class Iterator{
public:
    Iterator(Queue*, Node*);
    std::string operator*();
    Iterator& operator--();
    friend class Queue;
    friend bool operator!=(const Iterator&, const Iterator&);
private:
    const Queue* const container;
    Node* curr;
};

class Queue{
public:
    Queue();
    ~Queue();
    void push(std::string name);
    void pop();
    void customers();
    Iterator end();
    Iterator begin();
private:
    Node* front;
    Node* back;
};

#endif /* Queue_hpp */
