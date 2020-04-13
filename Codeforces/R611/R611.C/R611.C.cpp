//
//  R611.C.cpp
//  CodeForces Round #611 (Div. 3) C. Friends and Gifts
//
//  Created by Magic Bear on 2020/04/05.
//  Copyright © 2020 Magic Bear. All rights reserved.
//
 
#include <bits/stdc++.h>

using namespace std;

int main () 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int nPeople = 0;
    cin >> nPeople;
    int *assignedGift = (int *) malloc(nPeople*sizeof(int));
    map<int, int> remainPeople, giftFirst, giftSecond;
    map<int, int>::iterator it, it2;
    for (int i = 0; i < nPeople; ++i) giftFirst[i+1] = i+1;
    for (int i = 0; i < nPeople; ++i)
    {
        cin >> assignedGift[i];
        if (assignedGift[i] == 0)
            remainPeople[i+1] = 0;
        else
            giftFirst.erase(assignedGift[i]);
    }
    it = giftFirst.begin();
    while (it!= giftFirst.end())
    {
        if (assignedGift[it->first-1] != 0)
        {
            giftSecond[it->first] = it->second;
            it = giftFirst.erase(it);
        }
        else it++;
    }

    for (it = giftFirst.begin(); it!=giftFirst.end(); ++it)
    {
        it2 = remainPeople.begin();
        if (giftSecond.empty() && remainPeople.size() == 2)
        {
            it2++;
            assignedGift[it2->first - 1] = it->first;
            ++it;
            assignedGift[remainPeople.begin()->first - 1] = it->first;
            break;
        }
        if (it2->first == it->first) it2++;
        assignedGift[it2->first - 1] = it->first;
        remainPeople.erase(it2);
    }
    for (it = giftSecond.begin(); it!=giftSecond.end(); ++it)
    {
        assignedGift[remainPeople.begin()->first - 1] = it->first;
        remainPeople.erase(remainPeople.begin());
    }
    for (int i = 0; i < nPeople; ++i)
    {
        if(i != 0) cout << " ";
        cout << assignedGift[i];
    }
    cout << '\n';
    return 0;
}
