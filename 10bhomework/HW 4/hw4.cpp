//
//  hw4.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 2/21/24.
//

#include "hw4.hpp"

// -----------------------------------------------------
// Definitions for B struct member functions:
// -----------------------------------------------------

B::B(int _i, double _d):i(_i), p(std::make_shared<double>(_d)){
    //std::cout<<"B: parameterized constructor called for B object with i=" << i << ", *p=" << *p << ", address=" << this << "\n";
}
B::B():i(0), p(std::make_shared<double>(0)){
    //std::cout<<"B: default constructor called for B object with i=" << i << ", *p=" << *p << ", address=" << this << "\n";
}
B::B(const B& a):i(a.i), p(std::make_shared<double>(*(a.p))){
    std::cout<<"B: copy constructor called for B object with i=" << i << ", *p=" << *p << ", address=" << this << "\n";
}
B::B(B&& b){
    std::cout<<"B: move constructor called for B object with i=" << i << ", *p=" << *p << ", address=" << this << "\n";
    i = b.i;
    std::swap(p, b.p);
}

B::~B(){
    std::cout<<"B: destructor called for B object with i=" << i << ", *p=" << *p << ", address=" << this << "\n";
}

B& B::operator=(B&& right){
    std::cout<<"B: move assignment operator called for B object with i=" << i << ", *p=" << *p << ", address=" << this << "\n";
    i = right.i;
    std::swap(p, right.p);
    return *this;
}

B& B::operator=(const B& right){
    std::cout<<"B: copy assignment operator called for B object with i=" << i << ", *p=" << *p << ", address=" << this << "\n";
    i = right.i;
    p = std::make_shared<double>(*(right.p));
    return *this;
}

std::ostream& operator << (std::ostream& os, const B& b){
    os << "B object with with i=" << b.i << ", *p=" << *b.p << ", address=" << &b << "\n";
    return os;
}

// -----------------------------------------------------
// Question 1:
// -----------------------------------------------------

Bvec::Bvec():p(new B[1] {B()}), capacity(1), occupancy(0){
    std::cout << "BVEC: default constructor called\n";
}

Bvec::Bvec(int _capacity):p(new B[_capacity] {B()}), capacity(_capacity), occupancy(0){
    std::cout << "BVEC: parameterized constructor called\n";
}

//Copy constructor
Bvec::Bvec(const Bvec& r):p(new B[r.capacity]), capacity(r.capacity), occupancy(r.occupancy){
    std::cout << "BVEC: copy constructor called\n";
    for (size_t i = 0; i < r.capacity; i++){
        p[i] = r.p[i];
    }
}
//Move constructor
Bvec::Bvec(Bvec&& r):p(nullptr), capacity(r.capacity), occupancy(r.occupancy){
    std::cout << "BVEC: move constructor called\n";
    std::swap(p, r.p);
    delete[] r.p;
}

Bvec::~Bvec(){
    std::cout << "BVEC: destructor called\n";
    delete[] p;
}

std::ostream& operator << (std::ostream& os, const Bvec& r){
    os << "BVEC object at " << r.p << " with capacity = " << r.capacity << ", occupancy = " << r.occupancy << "\n";
    for (size_t i = 0; i < r.occupancy; i++){
        os << *(r.p+i);
    }
    return os;
}
//add_B copy
Bvec& Bvec::add_B(const B& r){
    if (occupancy == capacity){
        std::cout << "BVEC: capacity exceeded, moving contents of array to a new location\n";
        B* p_new = new B[2*capacity];
        for (size_t i = 0; i < capacity; i++){
            *(p_new+i) = std::move(*(p+i));
        }
        std::swap(p,p_new);
        delete [] p_new;
        capacity *= 2;
    }
    *(p+occupancy) = r;
    occupancy += 1;
    return *this;
}

//add_B move
Bvec& Bvec::add_B(B&& r){
    if (occupancy == capacity){
        std::cout << "BVEC: capacity exceeded, moving contents of array to a new location\n";
        B* p_new = new B[2*capacity];
        for (size_t i = 0; i < capacity; i++){
            *(p_new+i) = std::move(*(p+i));
        }
        std::swap(p,p_new);
        delete [] p_new;
        capacity *= 2;
    }
    *(p+occupancy) = std::move(r);
    occupancy += 1;
    return *this;
}

//copy assignment
Bvec& Bvec::operator = (const Bvec& r){
    std::cout << "BVEC: copy assignment operator called\n";
    delete[] p;
    p = new B[r.capacity];
    for (size_t i = 0; i < r.capacity; i++){
        *(p+i) = *(r.p+i);
    }
    capacity = r.capacity;
    occupancy = r.occupancy;
    return *this;
}
//move assignment
Bvec& Bvec::operator = (Bvec&& r){
    std::cout << "BVEC: move assignment operator called\n";
    std::swap(p,r.p);
//    for (size_t i = 0; i < r.capacity; i++){
//        *(p+i) = std::move(*(r.p+i));
//    }
    capacity = r.capacity;
    occupancy = r.occupancy;
    return *this;
}

void swap_Bvec(Bvec& l, Bvec& r){
    Bvec temp(std::move(r));
    r = std::move(l);
    l = std::move(temp);
}
