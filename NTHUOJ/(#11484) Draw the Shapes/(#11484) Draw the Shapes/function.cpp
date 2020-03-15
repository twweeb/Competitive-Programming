//
//  function.cpp
//  (#11484) Draw the Shapes
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include "function.h"
#include <iostream>
#include <cmath>

void oj::Rectangle::draw(){
    for(int i = 0;i<4;i++){
        int x,y;
        std::cin >> x >> y;
        points.push_back(Point(x, y));
    }
    int tmp = sqrt(pow(points[0].x-points[2].x,2)+pow(points[0].y-points[2].y,2));
    width = sqrt(pow(points[0].x-points[1].x,2)+pow(points[0].y-points[1].y,2));
    height = sqrt(pow(points[1].x-points[2].x,2)+pow(points[1].y-points[2].y,2));
    if(fmax(fmax(width,height),tmp)==tmp)
        area = width*height;
    else
        area = tmp*fmin(width,height);
}

void oj::Circle::draw(){
    int x,y,r;
    std::cin >> x >> y;
    points.push_back(Point(x, y));
    std::cin >> r;
    if(r<0) radius = 0;
    else radius = r;
    area = pow(radius,2)*PI;
}
