//
//  hw4-test.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 2/21/24.
//


#include "hw4.hpp"

int main(){
    
    int test_number = 7;
    
    if (test_number ==1){
        Bvec v1;
        Bvec v2(3);
        std::cout << v1 << v2;
        std::cout<< "\nEnd of block scope\n";
    }
    
    else if (test_number ==2){
        B b1(1, 1.1);
        Bvec v1(3);
        std::cout << v1;
        std::cout<<"\nAdding first element:\n";
        v1.add_B(b1);
        std::cout<<"\nAdding second element:\n";
        v1.add_B(B(2,2.2));
        std::cout << "\n" << v1;
        std::cout<< "\nEnd of block scope\n";
    }
    
    else if (test_number == 3){
        Bvec v1;
        std::cout << v1;
        std::cout<<"\nAdding first element:\n";
        v1.add_B(B(1,1.1));
        std::cout<<"\nAdding second element:\n";
        v1.add_B(B(2,2.2));
        std::cout << "\n" << v1;
        std::cout<< "\nEnd of block scope\n";
    }
    
    else if (test_number ==4){
        Bvec v1(2);
        v1.add_B(B(1,1.1));
        v1.add_B(B(2,2.2));
        Bvec v2(v1);
        std::cout << "Original:\n" << v1 ;
        std::cout << "Copy:\n" << v2 ;
        std::cout<< "\nEnd of block scope\n";
        return 0;
    }
    
    else if (test_number ==5){
        Bvec v1(2);
        v1.add_B(B(1,1.1));
        v1.add_B(B(2,2.2));
        Bvec v2;
        std::cout <<"\nBefore copy:\n" << v2;
        v2 = v1;
        std::cout << "After copy:\n" << v2;
        std::cout<< "\nEnd of block scope\n";
        return 0;
    }
    
    else if (test_number ==6){
        Bvec v1(2);
        v1.add_B(B(1,1.1));
        v1.add_B(B(2,2.2));
        std::cout <<"\nBefore assignment:\n" << v1;
        v1 = Bvec();
        std::cout << "After assignment:\n" << v1;
        std::cout<< "\nEnd of block scope\n";
    }
    
    else if (test_number ==7){
        Bvec v1(2);
        Bvec v2(2);
        v1.add_B(B(1,1.1));
        v1.add_B(B(2,2.2));
        v2.add_B(B(3,3.3));
        v2.add_B(B(4,4.4));
        std::cout <<"\nBefore swap:\n" << v1 << v2;
        swap_Bvec(v1,v2);
        std::cout << "After swap:\n" << v1 << v2;
        std::cout<< "\nEnd of block scope\n";
    }
    
    else{
        std::cout << "Test number not recognized, change test_number to a positive integer in the range 1-7\n";
    }
    
    
    return 0;
}
