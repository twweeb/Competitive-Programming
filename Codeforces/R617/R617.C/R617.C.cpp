//
//  R617.C.cpp
//  CodeForces Round #617 (Div. 3) C. Yet Another Walking Robot
//
//  Created by Magic Bear on 2020/03/30.
//  Copyright © 2020 Magic Bear. All rights reserved.
//

#include <bits/stdc++.h>
 
using namespace std;
 
int main () 
{
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        map<pair<int,int>, int> ground;
        map<pair<int,int>, int>::iterator it;
        int path_length = 0, cur_x = 0, cur_y = 0, start = -1, end = -1, length = 200001;
        cin >> path_length;
        string path;
        cin >> path;
 
        ground[{0,0}] =  0;
        for (int i = 0; i < path_length; ++i)
        {
            if(path[i] - 'L' == 0) cur_x--;
            else if (path[i] - 'R' == 0) cur_x++;
            else if (path[i] - 'U' == 0) cur_y++;
            else if (path[i] - 'D' == 0) cur_y--;
            
            it = ground.find({cur_x,cur_y});
            if (it != ground.end())
            {
                if (i + 1 - it->second < length)
                {
                    length = i + 1 - it->second;
                    start = it->second+1;
                    end = i+1;
                    it->second = i + 1;
                }
                else ground[{cur_x,cur_y}] =  i + 1;
            }
            else ground[{cur_x,cur_y}] =  i + 1;
        }
        if(length == 200001) cout << "-1" << endl;
        else cout << start << " " << end << endl;
    }
 
    return 0;
}