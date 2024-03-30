//
//  hw1.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 1/18/24.
//

#include "hw1.hpp"

// ---------------------------------------------------------
// DEFINITIONS FOR Q1

USD::USD(int _dollars, int _cents): cents(100*_dollars+_cents){}
USD::USD(int _dollars): cents(100*_dollars){}
USD::USD(): cents(0){}

// Overloaded operator definitions for Q1 go here...

std::ostream& operator << (std::ostream& out, const USD& wallet){
    out << "$" << (wallet.cents/100) << "." << std::setw(2) << std::setfill('0') << wallet.cents%100;
    return out;
}

std::istream& operator >> (std::istream& in, USD& newWallet){
    int dollars, cents;
    in >> dollars;
    std::cin.ignore();
    in >> cents;
    newWallet = USD(dollars,cents);
    return in;
}

USD::operator int() const{
    return cents;
}

void USD::operator += (const USD& right){
    cents += right.cents;
}

void USD::operator *= (int factor){
    cents *= factor;
}

// ---------------------------------------------------------
// DEFINITIONS FOR Q2
Groceries::Groceries(){}

// Overloaded operator definitions for Q2 go here...

int& Groceries::operator [] (std::string produceName){
    size_t size = p.size();
    for (int i = 0; i < size; i++){
        if (p[i] == produceName){
            return q[i];
        } else continue;
    }
    p.push_back(produceName);
    q.push_back(0);
    return q[size];
}

std::ostream& operator << (std::ostream& out, const Groceries& basket){
    size_t size = basket.p.size();
    out << "{";
    for (int i = 0; i < size; i++){
        out << basket.p[i] << ":" << basket.q[i];
        if (i < size-1){
            out << ", ";
        } else out << "}\n";
    }
    return out;
}

//Groceries Groceries::operator + (const Groceries& right){
//    Groceries combined = *this;
//    size_t size = right.p.size();
//    for (int i = 0; i < size; i++){
//        combined[right.p[i]] += right.q[i];
//    }
//    return combined;
//}

Groceries operator + (const Groceries& left, const Groceries& right){
    Groceries combined = left;
    size_t size = right.p.size();
    for (int i = 0; i < size; i++){
        combined[right.p[i]] += right.q[i];
    }
    return combined;
}

