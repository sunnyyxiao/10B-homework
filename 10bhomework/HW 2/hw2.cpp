//
//  hw2.cpp
//  PIC10B
//
//  Created by Sunny Xiao on 1/30/24.
//

#include "hw2.hpp"

// ---------------------------------------------------------
// Shape member definitions
//abstract class, pure virtual function
Shape::Shape(double _area, std::string _shape_type):area(_area),shape_type(_shape_type){}

std::string Shape::info() const{
    return ("string type: " + shape_type + ", area: " + std::to_string(area));
}


// ---------------------------------------------------------
// Circle member definitions

Circle::Circle(double _radius):Shape::Shape((M_PI*_radius*_radius), "circle"), radius(_radius){}

std::string Circle::info() const{
    return (Shape::info() + ", radius: " + std::to_string(radius));
}

Shape& Circle::scale(double factor){
    area *= factor;
    radius *= sqrt(factor);
    return *this;
}
double Circle::calc_perimeter() const{
    return 2*M_PI*radius;
}

// ---------------------------------------------------------
// Rectangle member definitions

Rectangle::Rectangle(double _width, double _height):Shape::Shape((_width*_height),"rectangle"), width(_width),height(_height){}

std::string Rectangle::info() const{
    return (Shape::info() + ", width: " + std::to_string(width) + ", height: " + std::to_string(height));
}

Shape& Rectangle::scale(double factor){
    area *= factor;
    width *= sqrt(factor);
    height *= sqrt(factor);
    return *this;
}

double Rectangle::calc_perimeter() const{
    return 2*(width+height);
}

//void Rectangle::extend(){
//    std::cout << "Extending example" << "\n";
//}

// ---------------------------------------------------------
// BlueRectangle member definitions

std::string BlueRectangle::info() const{
    return (Rectangle::info() + ", color: blue");
}

