//
//  function.cpp
//  (#11422) Shape
//
//  Created by Magic Bear on 2017/11/26.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include "function.h"
#include <iostream>
#include <cmath>

using namespace oj;
using namespace std;

class Triangle : public Shape
{
private:
    double area;
    double perimeter;
};
class Rectangle : public Shape
{
private:
    double area;
    double perimeter;
};
class Circle : public Shape
{
private:
    double area;
    double perimeter;
};
oj::Triangle::Triangle(double edge1, double edge2, double edge3)
{
    double s = (edge1+edge2+edge3)/2;
    if(2*s-max(max(edge1,edge2),edge3)>max(max(edge1,edge2),edge3)){
        setArea(sqrt(s*(s-edge1)*(s-edge2)*(s-edge3)));
        setPerimeter(2*s);
    }
    else{
        setArea(0);
        setPerimeter(0);
    }
}
oj::Rectangle::Rectangle(double width, double height)
{
    if(width>0 && height>0){
    setArea(width*height);
    setPerimeter(2*(width+height));
    }
    else{
        setArea(0);
        setPerimeter(0);
    }
}
oj::Circle::Circle(double radius, double pi)
{
    if(radius>0){
        setArea(pi*radius*radius);
        setPerimeter(2*pi*radius);
    }
    else{
        setArea(0);
        setPerimeter(0);
    }
}
