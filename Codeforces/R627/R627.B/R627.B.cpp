#include <bits/stdc++.h>

using namespace std;

int main () 
{
    int nCases = 0;
    cin >> nCases;
    while (nCases--) 
    {
        int length = 0;
        cin >> length;

        int *Seq = new int[length+1]();
        int prev = 0, cur = 0;
        bool success = false;
        for (int i = 0; i < length; ++i)
        {
            cin >> cur;
            if (i >= 2 && prev != cur && Seq[cur] == 1) success = true;
            else if (Seq[cur] == 2) success = true;
            prev = cur;
            Seq[cur]++;
        }
        if(success) cout << "Yes\n";
        else cout << "No\n";

        delete [] Seq;
    }
    return 0;
}
