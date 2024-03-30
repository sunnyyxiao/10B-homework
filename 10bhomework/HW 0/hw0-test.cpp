//
//  hw0-test.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 1/30/24.
//

#include <iostream>
#include <string>
#include <vector>
#include "hw0.hpp"

int main(){
    {
        // Question 1 test
        std::vector<std::vector<int>> v = {{1,2,3}, {-1,2}, {7}, {}};
        std::cout << max_element(v) << std::endl;
    }
    
    {
        // Question 2 test
        int x = 1;
        int y = 2;
        int*p1 = &x;
        int*p2 = &y;
        pointer_swap(p1,p2);
        std::cout << (p1 == &y) << " " << (p2 == &x) << std::endl;
        std::cout<< x << " " << y << std::endl;
    }
    {
        // Question 3 test for Caesar: this string is the opening paragraph of the Hitchhiker's guide to the galaxy, a wonderful book!
        int offset = -12;
        std::string s = "Far out in the uncharted backwaters of the unfashionable end of the Western Spiral arm of the Galaxy lies a small unregarded yellow sun. Orbiting this at a distance of roughly ninety-eight million miles is an utterly insignificant little blue-green planet whose ape-descended life forms are so amazingly primitive that they still think digital watches are a pretty neat idea.";
        
        // First test the Caesar cipher 1
        // Lets just print the first 40 characters
        std::string encoded_s = caesar_cipher1(s,offset);
        std::cout << encoded_s.substr(0, 30) << std::endl;
        std::string decoded_s = caesar_cipher1(encoded_s,-offset);
        std::cout << decoded_s.substr(0, 30) << std::endl;
        std::cout << std::boolalpha << (decoded_s == s) << std::endl;
        
        // Now test Caesar cipher 2
        caesar_cipher2(s,offset);
        std::cout << (encoded_s == s) << std::endl;
        caesar_cipher2(s,-offset);
        std::cout << (decoded_s == s) << std::endl;
    }
    
    {
        // Question 4 test
        const Undergrad s1;
        Undergrad s2("Tim", 12345, 91);
        std::cout << s1.name << " " << s1.ID << " " << s1.get_grade() << std::endl;
        std::cout << s2.name << " " << s2.ID << " " << s2.get_grade() << std::endl;
        s2.update_grade(102);
        s2.update_grade(95);
        std::cout << s2.name << " " << s2.ID << " " << s2.get_grade() << std::endl;
    }
    return 0;
}

