//
//  4_ESAb_ATAd.cpp
//  Code Jam Qualification Round 2020 4. ESAb ATAd
//  This code is not correct.  
//
//  Created by Lei Hsiung on 2020/04/04.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int try_cnt = 0, SolvedBit = 0;

string Rev(string str)
{
    reverse(str.begin(), str.end());
    return str;
}

string Com(string str)
{
    for (int i = 0 ; i < str.size(); ++i) str[i] = (str[i] == '1') ? '0' : '1';
    return str;
}

vector<string> SetFluctuation(vector<string> ans)
{
    string test = "";
    char c;
    for(int i = 5; i < 15; ++i)
    {
        cout << i + 1 << endl;
        cin >> c;
        test.push_back(c);
        ++try_cnt;
    }
    if(test.compare(Rev(test)) == 0) return SetFluctuation(ans);
    vector<string> tmp(2);   

    if (Rev(ans[1]).compare(ans[0]) == 0 || Com(ans[1]).compare(ans[0]) == 0 || Com(Rev(ans[1])).compare(ans[0]) == 0 || ans[1].compare(ans[0]) == 0)
    {
        do
        {
            test = "";
            if(try_cnt >= 130)
            {
                for(int i = 5; i < 15; ++i)
                {
                    cout << i + 1 << endl;
                    cin >> c;
                    test.push_back(c);
                    ++try_cnt;
                }
                tmp[0] = (Com(ans[0]).substr(5,5).compare(test.substr(0,5)) == 0) ? Com(ans[0]) :
                        (Rev(ans[0]).substr(5,5).compare(test.substr(0,5)) == 0) ? Rev(ans[0]) :
                        (Com(Rev(ans[0])).substr(5,5).compare(test.substr(0,5)) == 0) ? Com(Rev(ans[0])) :
                        (ans[0].substr(5,5).compare(test.substr(0,5)) == 0 ) ? ans[0] : "";
                tmp[1] = (Com(ans[1]).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(ans[1]) :
                        (Rev(ans[1]).substr(0,5).compare(test.substr(5,5)) == 0) ? Rev(ans[1]) :
                        (Com(Rev(ans[1])).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(Rev(ans[1])) :
                        (ans[1].substr(0,5).compare(test.substr(5,5)) == 0 ) ? ans[1] : "";
                return tmp;
            }
            for(int i = 0; i < 10; ++i)
            {
                cout << i + 1 << endl;
                cin >> c;
                test.push_back(c);
                ++try_cnt;
            } 
        } while (Rev(test).compare(ans[0]) == 0 || Com(test).compare(ans[0]) == 0 || Com(Rev(test)).compare(ans[0]) == 0 || test.compare(ans[0]) == 0);
        ans[1] = test;
        test = "";
        return SetFluctuation(ans);
    }
    else if (Com(ans[0]).substr(5,5).compare(test.substr(0,5)) == 0)
    {
        tmp[0] = Com(ans[0]);
        tmp[1] = (Com(ans[1]).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(ans[1]) :
                 (Rev(ans[1]).substr(0,5).compare(test.substr(5,5)) == 0) ? Rev(ans[1]) :
                 (Com(Rev(ans[1])).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(Rev(ans[1])) :
                 (ans[1].substr(0,5).compare(test.substr(5,5)) == 0 ) ? ans[1] : "";
        if(tmp[1].empty()) tmp = SetFluctuation(ans);
        return SetFluctuation(tmp);
    }
    else if (Rev(ans[0]).substr(5,5).compare(test.substr(0,5)) == 0)
    {
        for(int i = 0; i < 1000000000; ++i){}
        tmp[0] = Rev(ans[0]);
        tmp[1] = (Com(ans[1]).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(ans[1]) :
                 (Rev(ans[1]).substr(0,5).compare(test.substr(5,5)) == 0) ? Rev(ans[1]) :
                 (Com(Rev(ans[1])).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(Rev(ans[1])) :
                 (ans[1].substr(0,5).compare(test.substr(5,5)) == 0 ) ? ans[1] : "";
        if(tmp[1].empty()) tmp = SetFluctuation(ans);
        return tmp;
    }
    else if (Com(Rev(ans[0])).substr(5,5).compare(test.substr(0,5)) == 0)
    {
        tmp[0] = Com(Rev(ans[0]));
        tmp[1] = (Com(ans[1]).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(ans[1]) :
                 (Rev(ans[1]).substr(0,5).compare(test.substr(5,5)) == 0) ? Rev(ans[1]) :
                 (Com(Rev(ans[1])).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(Rev(ans[1])) :
                 (ans[1].substr(0,5).compare(test.substr(5,5)) == 0 ) ? ans[1] : "";
        if(tmp[1].empty()) tmp = SetFluctuation(ans);
        return tmp;
    }
    else if (ans[0].substr(5,5).compare(test.substr(0,5)) == 0)
    {
        for(int i = 0; i < 1000000000; ++i){}
        tmp[0] = ans[0];
        tmp[1] = (Com(ans[1]).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(ans[1]) :
                 (Rev(ans[1]).substr(0,5).compare(test.substr(5,5)) == 0) ? Rev(ans[1]) :
                 (Com(Rev(ans[1])).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(Rev(ans[1])) :
                 (ans[1].substr(0,5).compare(test.substr(5,5)) == 0 ) ? ans[1] : "";
        if(tmp[1].empty()) tmp = SetFluctuation(ans);
        return tmp;
    }
    else if (Com(ans[1]).substr(5,5).compare(test.substr(0,5)) == 0)
    {
        tmp[0] = Com(ans[1]);
        tmp[1] = (Com(ans[0]).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(ans[0]) :
                 (Rev(ans[0]).substr(0,5).compare(test.substr(5,5)) == 0) ? Rev(ans[0]) :
                 (Com(Rev(ans[0])).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(Rev(ans[0])) :
                 (ans[0].substr(0,5).compare(test.substr(5,5)) == 0 ) ? ans[0] : "";
        if(tmp[1].empty()) tmp = SetFluctuation(ans);
        return tmp;
    }
    else if (Rev(ans[1]).substr(5,5).compare(test.substr(0,5)) == 0)
    {
        tmp[0] = Rev(ans[1]);
        tmp[1] = (Com(ans[0]).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(ans[0]) :
                 (Rev(ans[0]).substr(0,5).compare(test.substr(5,5)) == 0) ? Rev(ans[0]) :
                 (Com(Rev(ans[0])).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(Rev(ans[0])) :
                 (ans[0].substr(0,5).compare(test.substr(5,5)) == 0 ) ? ans[0] : "";
        if(tmp[1].empty()) tmp = SetFluctuation(ans);
        return tmp;
    }
    else if (Com(Rev(ans[1])).substr(5,5).compare(test.substr(0,5)) == 0)
    {
        tmp[0] = Com(Rev(ans[1]));
        tmp[1] = (Com(ans[0]).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(ans[0]) :
                 (Rev(ans[0]).substr(0,5).compare(test.substr(5,5)) == 0) ? Rev(ans[0]) :
                 (Com(Rev(ans[0])).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(Rev(ans[0])) :
                 (ans[0].substr(0,5).compare(test.substr(5,5)) == 0 ) ? ans[0] : "";
        if(tmp[1].empty()) tmp = SetFluctuation(ans);
        return tmp;
    }
    else// if (ans[1].substr(5,5).compare(test.substr(0,5)) == 0)
    {
        tmp[0] = ans[1];
        tmp[1] = (Com(ans[0]).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(ans[0]) :
                 (Rev(ans[0]).substr(0,5).compare(test.substr(5,5)) == 0) ? Rev(ans[0]) :
                 (Com(Rev(ans[0])).substr(0,5).compare(test.substr(5,5)) == 0) ? Com(Rev(ans[0])) :
                 (ans[0].substr(0,5).compare(test.substr(5,5)) == 0 ) ? ans[0] : "";
        if(tmp[1].empty()) tmp = SetFluctuation(ans);
        return tmp;
    }
}

int main ()
{
    int TestCase, Bits, len;
    cin >> TestCase >> Bits;
    char resp = 'Y';
    while(TestCase --)
    {
        if (resp - 'Y' != 0) break;
        char c;
        try_cnt = SolvedBit = 0;
        vector<string> ans(Bits/10);
        while(SolvedBit < Bits)
        {
            cout << ++SolvedBit << endl;
            cin >> c;
            ans[(SolvedBit-1)/10].push_back(c);
            ++try_cnt;
        }
        if(Bits > 10) ans = SetFluctuation(ans);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i];
        cout << endl;
        cin >> resp;
    }
    return 0;
}