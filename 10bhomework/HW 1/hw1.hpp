//
//  hw1.hpp
//  PIC10B
//
//  Created by Sunny Xiao on 1/18/24.
//

#ifndef hw1_hpp
#define hw1_hpp

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

class USD{
public:
    USD(int _dollars, int _cents);
    explicit USD(int _dollars);
    USD();
    
    // -------------------------------------------------------
    // Declare operator overloads here
    friend std::ostream& operator << (std::ostream& out, const USD& wallet);
    friend std::istream& operator >> (std::istream& in, USD& newWallet);
    
    operator int() const;
    void operator += (const USD& right);
    void operator *= (int factor);
    void operator *= (const USD& right) = delete;
    
    // -------------------------------------------------------
private:
    int cents;
};

class Groceries{
public:
    Groceries();
    // -------------------------------------------------------
    // Declare operator overloads here
    int& operator [] (std::string produceName);
//    Groceries operator + (const Groceries& right);
    
    friend Groceries operator + (const Groceries& left, const Groceries& right);
    
    friend std::ostream& operator << (std::ostream& out, const Groceries& basket);
    
    
    
    // -------------------------------------------------------
    
private:
    std::vector<int> q; // q for quantities
    std::vector<std::string> p; // p for produce
};


#endif /* hw1_hpp */
