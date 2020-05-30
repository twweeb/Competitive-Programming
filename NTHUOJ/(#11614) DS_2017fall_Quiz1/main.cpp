//
//  main.cpp
//  (#11614) DS_2017fall_Quiz1
//
//  Created by Magic Bear on 2018/4/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include "function.h"


using namespace std;

int main(int argc, char const *argv[])
{
    abstract& ra = *new Implement();
    string input;
    while(getline(std::cin, input)){
        cout << fixed  <<  setprecision(3) << ra.myFunc(input) << endl;
    }
    return 0;
}

