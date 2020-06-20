//
//  gen.cpp
//  TSP
//
//  Created by LeiHsiung on 2019/5/7.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(int argc, const char * argv[]) {
    srand((int)time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
    ofstream output;
    int i = 10;
    cout << "------------------  N = " << i << " ------------------" << endl;
    output.open("input.txt");
    output << i << '\n';
    for(int j = 0; j< i; ++j){
        for(int k = 0; k < i ;++k){
            if(k!=j) output << rand()%100;
            else output << -1;
            output << ' ';
            
        }
        output << '\n';
    }
    return 0;
}

