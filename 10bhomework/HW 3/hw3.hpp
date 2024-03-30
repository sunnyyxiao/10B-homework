//
//  hw3.hpp
//  PIC10B
//
//  Created by Sunny Xiao on 2/12/24.
//

#ifndef hw3_hpp
#define hw3_hpp

#include <iostream>
#include <vector>

// -----------------------------------------------------
// Question 1:
// -----------------------------------------------------

void fix_this(int x);

// -----------------------------------------------------
// Question 2:
// -----------------------------------------------------

struct A{
    A(){};
    ~A();
    const char c = 'A';
};

struct Aa{
   // Complete declaration of Aa struct...
    Aa(size_t _l);
    ~Aa();
//    std::ostream& operator << (std::ostream& os, const Aa& right);
    
    A* pA;
    size_t l;
};

std::ostream& operator << (std::ostream& os, const Aa& right);

void get_As(std::unique_ptr<Aa>& up);

// -----------------------------------------------------
// Question 3:
// -----------------------------------------------------
struct Cat;

struct Human{
    Human(std::string _name);
    ~Human();
    void info();
    std::string name;
    std::vector<std::weak_ptr<Cat>> cats;
};

struct Cat{
    Cat(std::string _name);
    ~Cat();
    void get_human(std::shared_ptr<Human> human, std::shared_ptr<Cat> cat);
    void leave_human(std::shared_ptr<Human> human, std::shared_ptr<Cat> cat);
    void info();
    std::string name;
    std::vector<std::shared_ptr<Human>> humans;
};



#endif /* hw3_hpp */

