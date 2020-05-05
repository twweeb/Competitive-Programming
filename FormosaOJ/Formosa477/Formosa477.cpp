//
//  Formosa477.cpp
//  Heap
//
//  Created by Lei Hsiung on 5/5/20.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void solve_using_p_queue()
{
    int n, m;
    cin >> n >> m;
    vector<priority_queue<int, vector<int>, greater<int> > *> heap(n+1);
    for (int i = 1; i <= n; ++i ) heap[i] = new priority_queue<int, vector<int>, greater<int> > ();
    while (m--)
    {
        string op;
        cin >> op;
        if (op[0] - 'i' == 0)
        {
            int i, x;
            cin >> i >> x;
            heap[i]->push(x);
        }
        else if (op[0] - 'j' == 0)
        {
            int i, j;
            cin >> i >> j;
            if (heap[i]->size() < heap[j]->size())
            {
                heap[0] = heap[i];
                heap[i] = heap[j];
                heap[j] = heap[0];
            }
            while (!heap[j]->empty())
            {
                heap[i]->push(heap[j]->top());
                heap[j]->pop();
            }
        }
        else if (op[0] - 'e' == 0)
        {
            int i;
            cin >> i;
            if (heap[i]->empty()) cout << "NULL\n";
            else
            {
                cout << heap[i]->top() << '\n';
                heap[i]->pop();
            }
        }
        else if (op[0] - 'l' == 0)
        {
            int i;
            cin >> i;
            if (heap[i]->empty()) cout << "NULL\n";
            else cout << heap[i]->top() << '\n';
        }
    }
}

void solve_using_vector() 
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > heap(n+1);
    while (m--)
    {
        string op;
        cin >> op;
        if (op[0] - 'i' == 0)
        {
            int i, x;
            cin >> i >> x;
            heap[i].push_back(x);
        }
        else if (op[0] - 'j' == 0)
        {
            int i, j;
            cin >> i >> j;
            for (int k = 0; k < heap[j].size(); ++k) heap[i].push_back(heap[j][k]);
            heap[j].clear();
        }
        else if (op[0] - 'e' == 0)
        {
            int i;
            cin >> i;
            sort(heap[i].begin(), heap[i].end());
            if (heap[i].empty()) cout << "NULL\n";
            else
            {
                cout << heap[i].front() << '\n';
                heap[i].erase(heap[i].begin());
            }
        }
        else if (op[0] - 'l' == 0)
        {
            int i;
            cin >> i;
            sort(heap[i].begin(), heap[i].end());
            if (heap[i].empty()) cout << "NULL\n";
            else cout << heap[i].front() << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //solve_using_vector();
    solve_using_p_queue();
    return 0;
}