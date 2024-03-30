//
//  hw2-test.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 1/30/24.
//

#include "hw2.hpp"

// When uncommented this should result in a build error!
//class ColorCircle: Circle{
//public:
//    ColorCircle(double _radius, std::string _color): Circle(_radius), color(_color){}
//    virtual double calc_perimeter() const{
//        return 2*radius;
//    }
//
//private:
//    std::string color;
//
//};

int main(){
    // As Shape should be an abstract class the following should not build if uncommented
//    {
//        Shape s(2, "unknown");
//    }

    // Checks for Circle Class
    {
        // Check have correct information on a circle
        Circle c1(2);
        std::cout << c1.info() << "\n";
        
        // Check scale works
        c1.scale(2);
        std::cout << c1.info()<< "\n";
        
        // Check can call info on the reference returned by scale
        std::cout <<(c1.scale(0.5)).info()<< "\n";
        
        // Check calc_perimeter
        std::cout <<"circle perimeter: " << c1.calc_perimeter()<< "\n";
        
        // Check when ColorCircle defined above is uncommented then get build error
    }
    
    
    // Checks for Rectangle Class
    {
        // Check have correct information on a rectangle
        Rectangle r1(3,1);
        std::cout << r1.info() << "\n";
        
        // Check scale works
        r1.scale(4);
        std::cout << r1.info()<< "\n";
        
        // Check can call info on the reference returned by scale
        std::cout <<(r1.scale(0.25)).info()<< "\n";
        
        // Check calc_perimeter
        std::cout <<"rectangle perimeter: " << r1.calc_perimeter()<< "\n";
        
        // Check info is correct for BlueRectangle
        BlueRectangle r2(3,5);
        std::cout << r2.info() << "\n";
    }

    return 0;
}
