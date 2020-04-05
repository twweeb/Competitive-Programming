    //
    //  R615.B.cpp
    //  CodeForces Round #615 (Div. 3) B. Collecting Packages
    //
    //  Created by Magic Bear on 2020/04/03.
    //  Copyright © 2020 Magic Bear. All rights reserved.
    //
     
    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main ()
    {
        ios_base::sync_with_stdio(false);
        int nCases;
        cin >> nCases;
        while (nCases --)
        {
            int n, m_i, m_j;
            cin >> n;
            vector<pair<int, int> > vec;
            for (int i = 0; i < n; ++i)
            {
                cin >> m_i >> m_j;
                vec.push_back(make_pair(m_i, m_j));
            }
            sort(vec.begin(), vec.end());
     
            string str = "";
            m_i = m_j = 0;
            int p = 0, q = 0;
            bool isPossible = true;
            /************
             * This implementation will cause  Memory limit exceeded.
            if (vec[i].first + vec[i].second <= sum)
            {
                isPossible = false;
                cout << "NO\n";
                break;
            }
            else sum = vec[i].first + vec[i].second;
            ************/
            for(int i = 0; i < n; ++i)
            {
                p = vec[i].first;
                q = vec[i].second;
                if (p < m_i || q < m_j)
                {
                    isPossible = false;
                    break;
                }
     
                while(m_i != p)
                {
                    str.push_back('R');
                    ++m_i;
                }
                while(m_j != q)
                {
                    str.push_back('U');
                    ++m_j;
                }
            }
            if (isPossible) cout << "YES\n" << str << "\n";
            else cout << "NO\n";
        }
        return 0;
    }