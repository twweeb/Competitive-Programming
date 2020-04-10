#include <bits/stdc++.h>

using namespace std;

int main(){
    int nCases = 0;
    cin >> nCases;
    while (nCases --)
    {
        string t;
        cin >> t;
        int h, s;
        h = stoi(t.substr(0,2)); m = stoi(t.substr(3,2));
        m = (m == 0) ? 00 : 60 - m;
        h = (s == 0) ? 12 - h : 12 - h -1;
        h = (h <= 0) ? h + 12 : h;
        cout << setfill('0') << setw(2)  << h << ":" << setfill('0') << setw(2) << m;
        cout << '\n';
    }
}
