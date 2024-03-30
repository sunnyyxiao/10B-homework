//
//  hw0.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 1/9/24.
//

#include <iostream>
#include <string>
#include <vector>
#include "hw0.hpp"

// Question 1: max element function
int max_element(const std::vector <std::vector<int>>& v){
//    int max=0;
//    bool maxUpdated = false;
//    for (int i = 0; i < v.size(); i++){
//        if (v[i].empty()){
//            continue;
//        } else if (!maxUpdated){
//            maxUpdated = true;
//            max = v[i][1];
//        }
//        for (int n = 0; n < v[i].size(); n++){
//            if (v[i][n] > max){
//                max = v[i][n];
//            }
//        }
//    }
//    return max;
    
    int max = 0;
    bool initializeMax = true;
    for (int i = 0; i < v.size(); i++){
        for (int n = 0; n < v[i].size(); n++){
            if (initializeMax || (v[i][n]>max)){
                initializeMax = false;
                max = v[i][n];
            }
        }
    }
    return max;
}

// Question 2: pointer swap function
void pointer_swap(int*& p1, int*& p2){
    std::swap(p1,p2);
    std::swap(*p1,*p2);
//    int temp = *p1;
//    *p1 = *p2;
//    *p2 = temp;
}


// Question 3a: caesar cipher function

std::string caesar_cipher1(const std::string s, const int o){
    std::string s_new = "";
    for (char c:s){
        int offset = c - 32 + o%95;
//        cout << offset;
//        s_new += c + o%95;
        if (offset >= 0 && offset <= 94){
            s_new.append (1,offset + 32);
        } else if (offset < 0){
            s_new.append (1,127 + offset%95);
        } else {
            s_new.append (1,32 + offset%95);
        }
    }
    //    string s_new = s;
    //    for (int i = 0; i < s.length(); i ++){
    //        int offset = (s[i]-32) + (o%95);
    //
    //    }
    return s_new;
}

///
///for (char& c:s){
//c += (o%95);
//}


// Question 3b: in-place caesar cipher function
void caesar_cipher2(std::string& s, const int o){
    for (char& c:s){
        int offset = c - 32 + o%95;
        if (offset >= 0 && offset <= 94){
            c = offset + 32;
        } else if (offset < 0){
            c = 127 + offset%95;
        } else {
            c = 32 + offset%95;
        }
    }
//    const size_t size = s.length();
//    for (int i = 0; i < size; i++){
//        int offset = s[i] - 32 + o%95;
//        if (offset >= 0 && offset <= 94){
//            s[i] = offset+32;
//        } else if (offset < 0){
//            s[i] = 127 + offset%95;
//        } else {
//            s[i] = 32 + offset%95;
//        }
//    }
}

// Question 4: member functions of Undergrad class
Undergrad::Undergrad():name("Test"),ID(0), grade(0){}
Undergrad::Undergrad(std::string _name, size_t _ID, int _grade):name(_name),ID(_ID),grade(_grade){
    update_grade(_grade);
    if (_grade < 0 || _grade > 100){
        grade = 0;
    }
}

void Undergrad::update_grade(int n){
    if (n >= 0 && n <= 100){
        grade = n;
    } else {
        std::cout << "Grade is not valid, must be between 0 and 100." << std::endl;
    }
}

int Undergrad::get_grade() const {
    return grade;
}

