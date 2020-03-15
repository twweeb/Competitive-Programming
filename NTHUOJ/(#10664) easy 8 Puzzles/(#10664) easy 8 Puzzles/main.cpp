//
//  main.cpp
//  (#10664) easy 8 Puzzles
//
//  Created by Magic Bear on 2017/12/21.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include<iostream>

using namespace std;

typedef pair<int,int> p;

int board[3][3];
p zero;
int ans;
bool isSolve;

bool isDone()
{
    bool match = true;
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if((i*3+j+1)%9!=board[i][j])
            {
                match = false;
                break;
            }
        }
    }
    return match;
}

void solve(int time)
{
    if(isDone())
    {
        if(time<ans) ans = time;
        isSolve = true;
        return;
    }
    if(time>=ans) return;
    if(zero.first>0)
    {
        p tmp = zero;
        swap(board[zero.first][zero.second],board[zero.first-1][zero.second]);
        zero = p(zero.first-1,zero.second);
        solve(time+1);
        zero = tmp;
        swap(board[zero.first][zero.second],board[zero.first-1][zero.second]);
        
    }
    if(zero.first<2)
    {
        p tmp = zero;
        swap(board[zero.first][zero.second],board[zero.first+1][zero.second]);
        zero = p(zero.first+1,zero.second);
        solve(time+1);
        zero = tmp;
        swap(board[zero.first][zero.second],board[zero.first+1][zero.second]);
    }
    if(zero.second>0)
    {
        p tmp = zero;
        swap(board[zero.first][zero.second],board[zero.first][zero.second-1]);
        zero = p(zero.first,zero.second-1);
        solve(time+1);
        zero = tmp;
        swap(board[zero.first][zero.second],board[zero.first][zero.second-1]);
    }
    if(zero.second<2)
    {
        p tmp = zero;
        swap(board[zero.first][zero.second],board[zero.first][zero.second+1]);
        zero = p(zero.first,zero.second+1);
        solve(time+1);
        zero = tmp;
        swap(board[zero.first][zero.second],board[zero.first][zero.second+1]);
    }
}

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        for(int i=0 ; i<3 ; i++)
        {
            for(int j=0 ; j<3 ; j++)
            {
                cin >> board[i][j];
                if(board[i][j]==0) zero = p(i,j);
            }
        }
        ans = 14;
        isSolve = false;
        solve(0);
        if(isSolve) cout << "You can solve it within " << ans << " steps." << endl;
        else cout << "You'd better skip this game." << endl;
    }
    return 0;
}

