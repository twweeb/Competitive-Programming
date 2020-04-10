#include <bits/stdc++.h>

using namespace std;

int main(){
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        int mTests = 0, chess_size = 0;
        cin >> mTests >> chess_size;
        while(mTests -- )
        {
            bool solved = true;
            int bishop_x, bishop_y, object_x, object_y;
            cin >> bishop_x >> bishop_y >> object_x >> object_y;
            if (bishop_x <= 0 || bishop_y <= 0 || object_x <= 0 || object_y <= 0) solved = false;
            if (bishop_x > chess_size || bishop_y > chess_size || object_x > chess_size || object_y > chess_size)solved = false;
            if(!solved) 
            {
                cout << "no move\n";
                continue;
            }
            if (bishop_x - object_x == 0 && bishop_y - object_y == 0) cout << "0\n";
            else if ((abs(bishop_x - object_x) + abs(bishop_y - object_y)) % 2 != 0) cout << "no move\n";
            else if ( abs(bishop_x - object_x) == abs(bishop_y - object_y)) cout << "1\n";
            else cout << "2\n";
        }
    }
}