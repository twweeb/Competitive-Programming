#include<bits/stdc++.h>

using namespace std;


int main()
{
    int T;
    cin >> T;
    vector<int> C(3), M(3), Y(3), K(3);
    for (int i = 1; i <= T; ++i)
    {
    	int available[4] = {1000000,1000000,1000000,1000000};
        cout << "Case #" << i << ": ";
        for (int printer = 0; printer < 3; ++printer)
        {
            cin >> C[printer] >> M[printer] >> Y[printer] >> K[printer];
            available[0] = min(C[printer], available[0]);
            available[1] = min(M[printer], available[1]);
            available[2] = min(Y[printer], available[2]);
            available[3] = min(K[printer], available[3]);
        }

        if (available[0] + available[1] + available[2] + available[3] < 1e6) cout << "IMPOSSIBLE\n";
        else
        {
            int total_capacity = 1e6;
            for (int i = 0; i < 4; ++i)
            {
                if (i == 0)
                {
                    cout << available[i];
                    total_capacity -= available[i];
                }
                else
                {
                    cout << ' ' << min(total_capacity, available[i]);
                    total_capacity -= min(total_capacity, available[i]);
                }
            }
            cout << endl;
        }
    }
    return 0;
}
