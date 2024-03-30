//
//  hw1-test.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 1/18/24.
//

#include <iostream>
#include "hw1.hpp"


int main(){
    
    // QUESTION 1 TESTS:
//    {
//        std::cout<<"QUESTION 1 TESTS:\n";
//        // Create three wallets w1, w2, w3
//        USD w1(100,05);
//        USD w2(9);
//        USD w3;
//
//        // Print out these wallets
//        std::cout << "Value of wallets:\n" << "Wallet 1: " << w1 << "\nWallet 2:" << w2 << "\nWallet 3:" << w3 << "\n";
//
//        // Read in fourth wallet from user input
//        std::cout<< "Please enter dollars.cents:\n$";
//        USD w4; std::cin >> w4;
//        std::cout << "Value of wallet 4 is " << w4 << "\n";
//
//        // Add 10.50 to wallet 2
//        std::cout << "Adding $10.50 to wallet 2...\n";
//        w2+= USD(10,50);
//        std::cout << "Value of wallet 2 is now " << w2 << "\n";
//
//        // Check that can't add an integer value to w3. Uncomment the line below, if it still builds then is incorrect!
////        w2+= 5;
////
//        // Multiply wallet 2 by 4
//        std::cout << "Multiplying wallet 2 by 4...\n";
//        w2*=4;
//        std::cout << "Value of wallet 2 is now " << w2 << "\n";
////
//        // Check conversion of Wallet 1 to an integer
//        std::cout<< "Wallet 1 contains " << int(w1) << " cents\n";
////
//        // Check can't multiply one wallet by another! Uncomment the line below, if it still builds then is incorrect!
////        w2*=w3;
//    }
    
    // QUESTION 2 TESTS
    {
        std::cout<<"\nQUESTION 2 TESTS:\n";
        // Initialize two grocery bags
        Groceries b1;
        Groceries b2;
        // Populate using indexing operator
        b1["apples"]=3;
        b1["pears"]=2;
        b1["bananas"]=7;
        b1["pork"];
        b1["pork"]++;
        
        std::cout << "b1 has " << b1["pork"] << " pork chops\n";
        
        b2["apples"]=1;
        b2["kiwis"]=3;
        b2["oranges"]=4;
        b2["pork"]=7;
        
        // Check that access operator is working properly.
        std::cout << "b1 has " << b1["bananas"] << " bananas\n";
        std::cout << "b2 has " << b2["kiwis"] << " kiwis\n";
        
        // Output Groceries
        std::cout << "Contents of b1:\n" << b1 << "Contents of b2:\n" << b2;
        
        // Update also using indexing operator
        std::cout<<"Updating contents of b1...";
        b1["apples"]++;
        b1["pears"]+=2;
        b1["bananas"]-=2;
        std::cout << "Contents of b1:\n" << b1;
        
        // Creating a third bag by adding together b1 and b2
        Groceries b3 = b1 + b2;
        std::cout<<"b3 = b1+b2 contains:\n" << b3;
        
    }
    
    

    return 0;
}

