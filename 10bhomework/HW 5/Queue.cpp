//
//  Queue.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 3/6/24.
//

#include "Queue.hpp"

// -----------------------------------------------------
// Node class member definitions
// -----------------------------------------------------
Node::Node():name("\0"), prev(nullptr){}
Node::Node(std::string _name, Node* _prev):name(_name), prev(_prev){}
Node::~Node(){
    std::cout<< "Removing " << name << " from the queue\n";
}



// -----------------------------------------------------
// Iterator class member definitions
// -----------------------------------------------------
Iterator::Iterator(Queue* _container, Node* _curr): container(_container), curr(_curr){}
std::string Iterator::operator*(){return curr->name;}
Iterator& Iterator::operator--(){
    if(curr){curr = curr->prev;} // if curr is not nullptr then update
    return *this;
}
bool operator!=(const Iterator& left, const Iterator& right){
    return (right.container != left.container)||(right.curr!= left.curr);
}


// -----------------------------------------------------
// Queue class member definitions
// -----------------------------------------------------
Queue::Queue():back(nullptr), front(nullptr){}

Iterator Queue::begin(){
    return Iterator(this, this->front);
}

Iterator Queue::end(){
    return Iterator(this, nullptr);
}

Queue::~Queue(){
    std::cout << "Deleting queue\n";
    for (auto it = this->begin(); it != this->end();){
        Node* temp = it.curr->prev;
        delete it.curr;
        it.curr = temp;
    }
//    while (this->front != this->back){
//        Node* temp = front;
//        front = front->prev;
//        delete temp;
//    }
}

void Queue::customers(){
    std::cout << "Customers in the queue from front to back: \n";
    for (auto it = this->begin(); it != this->end(); --it){
        std::cout << *it /*it.curr->name*/ << " ";
    }
    std::cout << std::endl;
}

void Queue::push(std::string name){
    std::cout << name << " has joined the queue\n";
    if (this->front != nullptr){
        Iterator it = this->begin();
        while (it.curr->prev != nullptr){
            --it;
        }
        it.curr->prev = new Node(name,nullptr);
        this->back = it.curr->prev;
    } else {
//        this->begin().curr->name = name;
        front = new Node(name,nullptr);
        back = front;
    }
}

void Queue::pop(){
    if (front == nullptr){
        std::cout << "The queue is empty, no customers to remove\n";
    } else if (front == back){
        std::cout << front->name << " has been called to the counter\n";
        delete front;
        front = nullptr;
        back = nullptr;
    } else {
        Iterator it = this->begin();
        std::cout << it.curr->name << " has been called to the counter\n";
        --it;
        delete front;
        front = it.curr;

//        Iterator it = this->begin();
//        while (it.curr->prev != this->back){
//            --it;
//        }
//        std::cout << it.curr->prev->name << " has been called to the counter\n";
//        delete it.curr->prev;
//        this->back = it.curr;
//        it.curr->prev = nullptr;
        
    }
}



