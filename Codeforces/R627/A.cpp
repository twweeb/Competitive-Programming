#include <bits/stdc++.h>

using namespace std;

int main () 
{
    int nCases = 0;
    cin >> nCases;
    while (nCases--) 
    {
        int cols = 0;
        cin >> cols;

        bool solve = true;
        int *Tetris = new int[cols]();
        for (int i = 0; i < cols; ++i)
        {
            cin >> Tetris[i];
            if(i > 0 && Tetris[i-1]%2 != Tetris[i]%2)
                solve = false;
        }
        delete [] Tetris;
        if(solve) 
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
