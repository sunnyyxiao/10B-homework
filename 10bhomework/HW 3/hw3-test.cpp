//
//  hw3-test.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 2/12/24.
//

#include <iostream>
#include "hw3.hpp"

int main(){
    
    std::cout<<"TEST FOR Q1\n";
    fix_this(4);

    std::cout<<"\nTEST FOR Q2\n";
    {
        std::unique_ptr<Aa> up;
        get_As(up);
        std::cout << *up;
    }
    
    std::cout<<"\nTESTS FOR Q3\n";
    // Note Larry is the cat at N10 Downing Street
    // Multiple cats and humans examples
    {
        std::shared_ptr<Cat> Larry(new Cat("Larry"));
        {
            std::shared_ptr<Cat> Palmerston(new Cat("Palmerston"));
            std::shared_ptr<Human> Boris(new Human("Boris"));
            Palmerston->get_human(Boris, Palmerston);
            {
                
                std::shared_ptr<Human> Lizz(new Human("Lizz"));
                std::shared_ptr<Human> Rishi(new Human("Rishi"));
                Larry->get_human(Rishi, Larry);
                Palmerston->leave_human(Boris, Palmerston);
                Palmerston->get_human(Lizz, Palmerston);
                Palmerston->get_human(Rishi, Palmerston);
                Lizz->info();
                Rishi->info();
            }
        }
    }
    return 0;
}
