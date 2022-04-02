#include<bits/stdc++.h>

using namespace std;

void print_punched_card(int rows, int cols)
{
    vector<string> plane;
    string cur_row_1="", cur_row_2="";
    for (int i = 0; i < rows; ++i)
    {
        if (i < 2)
        {
            cur_row_1="";
            cur_row_2="";
            for (int j = 0; j < cols; ++j)
            {
                if (j == 0)
                {
                    if (i == 0)
                    {
                        cur_row_1 += "..+";
                        cur_row_2 += "..|";
                    }
                    else
                    {
                        cur_row_1 += "+-+";
                        cur_row_2 += "|.|";
                    }
                }
                else
                {
                    cur_row_1 += "-+";
                    cur_row_2 += ".|";
                }
            }
        }
        plane.push_back(cur_row_1);
        plane.push_back(cur_row_2);
        if(i == rows-1) plane.push_back(cur_row_1);
    }
    for(auto str: plane) cout << str << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ":" << endl;
        int rows, cols;
        cin >> rows >> cols;
        print_punched_card(rows, cols);
    }
    return 0;
}
