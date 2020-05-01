//
//  main.cpp
//  Lily's Homework
//
//  Created by Lei Hsiung on 12/18/19.
//  Copyright © 2019 Lei Hsiung. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the lilysHomework function below.
int lilysHomework(vector<int> arr) {
    size_t n = arr.size();
    pair<int, int> arr_idx[n];
    for(int i = 0; i < n; i++)
    {
        arr_idx[i].first = arr[i];
        arr_idx[i].second = i;
    }

    sort(arr_idx, arr_idx + n);
    vector<bool> isVisit1(n, false), isVisit2(n, false);

    int ans1 = 0, ans2 = 0;

    for(int i = 0; i< n; i++)
    {
        if(isVisit1[i] || i == arr_idx[i].second) continue;

        int swap_cnt = 0;
        int j = i;
        while(!isVisit1[j])
        {
            isVisit1[j] = true;
            j = arr_idx[j].second;

            swap_cnt++;
        }
        if(swap_cnt) ans1+=swap_cnt-1;
    }

    sort(arr_idx, arr_idx + n, greater< pair<int, int>>() );

    for(int i = 0; i< n; i++)
    {
        if(isVisit2[i] || i == arr_idx[i].second) continue;

        int swap_cnt = 0;
        int j = i;
        while(!isVisit2[j])
        {
            isVisit2[j] = true;
            j = arr_idx[j].second;

            swap_cnt++;
        }
        if(swap_cnt) ans2+=swap_cnt-1;
    }
    return min(ans1, ans2);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    cout << result << "\n";
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
