//
//  Formosa473.cpp
//  
//
//  Created by Lei Hsiung on 4/5/20.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    string str, token;
    // read one line each time
    bool isNextCase = true;
    string sheet[50][50];
    int matchRows[50], matchCols[50];
    int x = 0, y = 0, n = 0, RowsCnt = 0, ColsCnt = 0;
    while (getline(cin, str))
    {
        if (str == "") break; //if line is empty, break
        if (str.substr(0,2).compare("+-") == 0 || str.substr(0,2).compare("| ") == 0) continue;
        if (str[0] - '|' == 0)
        {
            if (isNextCase)
            {
                isNextCase = false;
                x = y = 0;
            }
            istringstream iss(str);
            while (getline(iss, token, '|')) 
                if(!token.empty()) sheet[x][y++] = token;
            ++x;
            y = 0;
        }
        else
        {
            if (!isNextCase)
            {
                n = x;
                isNextCase = true;
                RowsCnt = 0; ColsCnt = 0;
                for (int i = 0; i < n; ++i) matchRows[i] = matchCols[i] = 0;
            }
            if (str.size() != 9) str.insert(0,9-str.size(),'0');
            for (int i = 0; i < n; ++i)
            {
                if (matchRows[i] == n) continue;
                int dist = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (sheet[i][j].compare(str) == 0) 
                    {
                        if (++matchRows[i] == n) ++RowsCnt;
                        if (++matchCols[j] == n) ++ColsCnt;
                        cout << RowsCnt << " " << ColsCnt << '\n';
                        break;
                    }
                }
            }
            //if (!isFind) cout << str << '\n'; //For Debug
        }
    }
    return 0;
}
