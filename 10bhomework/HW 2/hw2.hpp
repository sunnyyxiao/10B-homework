//
//  hw2.hpp
//  PIC10B
//
//  Created by Sunny Xiao on 1/30/24.
//

#ifndef hw2_hpp
#define hw2_hpp

#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

// ---------------------------------------------------------
// QUESTION 1 CLASS DECLARATIONS:


class Shape{
public:
    Shape(double _area, std::string _shape_type);
    virtual std::string info() const;
    virtual Shape& scale(double factor) = 0;
    virtual double calc_perimeter() const = 0;
    
protected:
    std::string shape_type;
    double area;
};


class Circle: public Shape{
public:
    Circle(double _radius);
    virtual std::string info() const override;
    virtual Shape& scale(double factor) override;
    virtual double calc_perimeter() const override final;
    
protected:
    double radius;
};

class Rectangle: public Shape{
public:
    Rectangle(double _width, double _height);
    virtual std::string info() const override;
    virtual Shape& scale(double factor) override;
    virtual double calc_perimeter() const override final;
    void extend();
    
protected:
    double width, height;
};


class BlueRectangle: public Rectangle{
public:
    using Rectangle::Rectangle;
    virtual std::string info() const;
};

#endif /* hw2_hpp */
