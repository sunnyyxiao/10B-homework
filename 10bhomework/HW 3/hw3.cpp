//
//  hw3.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 2/12/24.
//

#include "hw3.hpp"

// -----------------------------------------------------
// Question 1:
// -----------------------------------------------------


// Fix this function as per instructions!
void fix_this(int x){
    int* pi1 = &x;
    double* pd1;
    {
        double* pd2 = new double(2.5);
        pd1 = pd2;
        {
            int *pi2 = new int(x);
            double* pd3 = pd1;
            std::cout << (*pd3)*(*pi2) << "\n";
            delete pd3;
            pd2 = pd1 = nullptr;
            delete pi2;
        }
//        delete pd2;
    }
//    delete pd1;
//    delete pi1;
}


// -----------------------------------------------------
// Question 2:
// -----------------------------------------------------

A::~A(){std::cout<<"Destructor of A object called\n";}

void get_As(std::unique_ptr<Aa>& up){
    std::cout << "How many A objects do you want to create? ";
    size_t l;  std::cin >> l;
    up.reset(new Aa(l));
}

// Add member function definitions for Aa here...

Aa::Aa(size_t _l):l(_l),pA(new A[_l]){}
Aa::~Aa(){
    std::cout << "Destructor of Aa object of size " << l << " called\n";
    delete[] pA;
}

std::ostream& operator << (std::ostream& os, const Aa& right){
    os << "Contents of Aa object:\n";
    for (size_t i = 0; i < right.l; i++){
        os << (right.pA+i)->c;
    }
    os << "\n";
    return os;
}

// -----------------------------------------------------
// Question 3:
// -----------------------------------------------------
Human::Human(std::string _name):name(_name){}
Cat::Cat(std::string _name):name(_name){}

Human::~Human(){
    std::cout << "Human destructor for " << name << " called\n";
}

Cat::~Cat(){
    std::cout << "Cat destructor for " << name << " called\n";
}

void Human::info(){
    std::cout << name << "\'s cats are:\n";
    std::shared_ptr<Cat> newcats;
    for (int i = 0; i < cats.size(); i++){
        newcats = cats[i].lock();
        std::cout << newcats->name << "\n";
    }
}

void Cat::get_human(std::shared_ptr<Human> human, std::shared_ptr<Cat> cat){
    humans.push_back(human);
    human->cats.push_back(cat);
}


void Cat::leave_human(std::shared_ptr<Human> human, std::shared_ptr<Cat> cat){
    bool noHuman = true;
    for (int i = 0; i < humans.size(); i++){
        if (humans[i] == human){
            humans.erase(humans.begin()+i);
            noHuman = false;
            break;
        }
    }
    if (!noHuman){
        for (int a = 0; a < human->cats.size(); a++){
            if (human->cats[a].lock() == cat){
                human->cats.erase(human->cats.begin()+a);
                std::cout << cat->name << " has left " << human->name << "\n";
                break;
            }
        }
    } else {
        std::cout << cat->name << " does not have human " << human->name << "\n";
    }
}




