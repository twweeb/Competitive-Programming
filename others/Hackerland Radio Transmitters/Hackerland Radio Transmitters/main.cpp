//
//  main.cpp
//  Hackerland Radio Transmitters
//
//  Created by Lei Hsiung on 12/20/19.
//  Copyright © 2019 Lei Hsiung. All rights reserved.
//

#include </Users/bits/stdc++.h>

using namespace std;

int hackerlandRadioTransmitters(vector<int> x, int k) {
    sort(x.begin(), x.end());
    int cnt = 0, tmp = 0;
    //bool trans[100000];
    for(int i = 1; i < x.size(); i++)
    {
        if(tmp + (x[i] - x[i-1]) == k)
        {
            //trans[x[i]] = true;
            cnt++;
            tmp = -k;
        }
        else if(tmp + (x[i] - x[i-1]) > k)
        {
            if(tmp >= 0)
            {
                //x[i-1] = true;
                cnt++;
            }

            tmp = 0;
        }
        else
        {
            tmp += (x[i] - x[i-1]);
        }
    }
    
    if(tmp >= 0)
    {
        x[x.size()-1] = true;
        cnt++;
    }
    
    return cnt;

}

int main()
{
    int n, k, x_item;
    cin >> n >> k;
    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        cin >> x_item;
        x[i] = x_item;
    }

    int result = hackerlandRadioTransmitters(x, k);

    cout << result << "\n";

    return 0;
}
