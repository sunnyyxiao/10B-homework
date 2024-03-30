//
//  hw0.hpp
//  PIC10B
//
//  Created by Sunny Xiao on 1/9/24.
//

#ifndef hw0_hpp
#define hw0_hpp

#include <iostream>
#include <string>
#include <vector>

// Question 1: declaration max element function
int max_element(const std::vector <std::vector<int>>& v);

//Question 2: declaration pointer swap function
void pointer_swap(int*& p1, int*& p2);

// Question 3a: declaration caesar cipher function
std::string caesar_cipher1(std::string s, int o);

// Question 3b: declaration in-place caesar cipher function
void caesar_cipher2(std::string& s, int o);

// Question 4: declaration of Undergrad class
class Undergrad{
private:
    int grade;
public:
    const std::string name;
    const size_t ID;
    Undergrad();
    Undergrad(std::string _name, size_t _ID, int _grade);
    void update_grade(int n);
    int get_grade() const;
};

#endif /* hw0_hpp */
