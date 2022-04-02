#include<bits/stdc++.h>

using namespace std;

int main()
{
    int Testcase, num_dices;
    cin >> Testcase;
    for (int t = 1; t <= Testcase; ++t)
    {
        cin >> num_dices;
        vector<int> dice_list(num_dices), max_len(num_dices, 0);

        for (int i = 0; i < num_dices; ++i) cin >> dice_list[i];
        sort(dice_list.begin(), dice_list.end());

        int max_straight = 0, j = 0;
        for (int i = 0; i < num_dices; ++i)
        {
            if (i > 0) max_len[i] = j = max_len[i-1]-1;
            for (; i+j < num_dices; ++j)
            {
                if (dice_list[i+j] >= j+1) max_len[i]++;
                else break;
            }
            max_straight = max(max_straight, max_len[i]);
        }
        cout  << "Case #" << t << ": " << max_straight << endl;
    }
    return 0;
}
