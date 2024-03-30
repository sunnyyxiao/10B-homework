//
//  hw4.hpp
//  PIC10B
//
//  Created by Sunny Xiao on 2/21/24.
//

#ifndef hw4_hpp
#define hw4_hpp

#include <iostream>


// -----------------------------------------------------
// Declaration of B struct:
// -----------------------------------------------------

struct B{
    B(int _i, double _d);
    B();
    ~B();
    B(const B& a);
    B(B&& b);
    B& operator=(B&& right);
    B& operator=(const B& right);
    int i;
    std::shared_ptr<double> p;
    friend std::ostream& operator << (std::ostream& os, const B& b);
};

// -----------------------------------------------------
// Question 1:
// -----------------------------------------------------
struct Bvec{

    Bvec();
    Bvec(int _capacity);
    
    Bvec(const Bvec& r);
    Bvec(Bvec&& r);
    
    ~Bvec();
    
    friend std::ostream& operator << (std::ostream& os, const Bvec& r);
    Bvec& add_B(const B& r);
    Bvec& add_B(B&& r);
    
    Bvec& operator = (const Bvec& r);
    Bvec& operator = (Bvec&& r);
    
    int capacity;
    B* p;
    int occupancy;
};

void swap_Bvec(Bvec& l, Bvec& r);

#endif /* hw4_hpp */

