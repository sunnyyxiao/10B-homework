//
//  hw5.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 3/6/24.
//

#include <iostream>
#include "Queue.hpp"

int main(){
    Queue q;
    q.pop();
    q.push("Sam");
    q.push("Min");
    q.push("Jen");
    q.push("Cole");
    q.customers();
    q.pop();
    q.pop();
    q.push("Saanvi");
    q.pop();
    return 0;
}

