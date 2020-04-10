#include <bits/stdc++.h>

using namespace std;

int main(){
    int nCases = 0;
    cin >> nCases;
    int sign = 1;
    cout << "Lumberjacks:\n";
    while (nCases --)
    {
        bool ordered = true;
        int prev, cur;
        for (int i = 0; i < 10; ++i)
        {
            cin >> cur;
            if(!ordered) continue;
            if (i == 1) sign = (cur - prev > 0) ? 1 : -1;
            else if((cur - prev)*sign < 0) ordered = false;
            prev = cur;
        }
        if (ordered) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
}
