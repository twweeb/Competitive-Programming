#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int nCases;
    cin >> nCases;
    while (nCases --)
    {
        int n, m, tmp;
        int alphabet[26] = {0};
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> mis;
        for (int i = 0; i < m; ++i) 
        {
            cin >> tmp;
            mis.push_back(tmp);
        }
        sort(mis.begin(), mis.end());
        for (int i = 0; i < mis.size(); ++i)
            for(int j = (i == 0) ? 0 : mis[i-1]; j < mis[i]; ++j)
                alphabet[s[j] - 'a'] += mis.size() - i;
        for(int i = 0; i < n; ++i)
            ++ alphabet[s[i] - 'a'];
        for (int i = 0; i < 26; ++i)
            cout << alphabet[i] << " ";
        cout << '\n';
    }
    return 0;
}