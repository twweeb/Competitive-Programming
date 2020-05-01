#include <bits/stdc++.h>

using namespace std;

bool is_x(char c)
{
    return (c - 'E' == 0) || (c - 'W' == 0);
}
bool is_y(char c)
{
    return (c - 'N' == 0) || (c - 'S' == 0);
}

void solve() {
    int nCases = 0, j = 1;
    cin >> nCases;
    while(nCases --)
    {
        int x, y;
        string ans = "";
        bool possible = true, x_neg = false, y_neg = false;
        cin >> x >> y;
        x_neg = x < 0;
        y_neg = y < 0;
        x = abs(x);
        y = abs(y);
        if ((x + y) % 2 == 0) possible = false;
        else
        {
            while (x != 0 && y != 0)
            {
                if(y % 2 == 1)
                {
                    x /= 2;
                    if (x%2 == 1)
                    {
                        if(((y+1)/2)%2 == 1)
                        {
                            y = (y-1)/2;
                            ans.push_back('N');
                        }
                        else
                        {
                            y = (y+1)/2;
                            ans.push_back('S');
                        }
                    }
                    else 
                    {
                        if(((y+1)/2)%2 == 1)
                        {
                            y = (y+1)/2;
                                ans.push_back('S');
                        }
                        else
                        {
                            y = (y-1)/2;
                            ans.push_back('N');
                        }
                    }
                }
                else
                {
                    y /= 2;
                    if (y % 2 == 1)
                    {
                        if ((x+1)/2 % 2 == 1)
                        {
                            ans.push_back('E');
                            x = (x-1)/2;
                        }
                        else
                        {
                            ans.push_back('W');
                            x = (x+1)/2;
                        }
                    }
                    else
                    {
                        if ((x+1)/2 % 2 == 1)
                        {
                            ans.push_back('W');
                            x = (x+1)/2;
                        }
                        else
                        {
                            ans.push_back('E');
                            x = (x-1)/2;
                        }
                    }
                }
            }
        }
        cout << "Case #"<< j++ << ": ";
        if(!possible) cout << "IMPOSSIBLE" <<endl;
        else
        {
            if(x != 0)
            {
                while(x != 1)
                {
                    if (((x+1)/2)%2==1)
                    {
                        x = (x+1)/2;
                        ans.push_back('W');
                    }
                    else
                    {
                        x = (x-1)/2;
                        ans.push_back('E');
                    }
                }
                ans.push_back('E');
            }
            else if (y != 0)
            {
                while(y != 1)
                {
                    if (((y+1)/2)%2==1)
                    {
                        y = (y+1)/2;
                        ans.push_back('S');
                    }
                    else
                    {
                        y = (y-1)/2;
                        ans.push_back('N');
                    }
                }
                ans.push_back('N');
            }
            for(int i = 0; i < ans.size(); ++i)
            {
                if (x_neg && is_x(ans[i]))
                {
                    if(ans[i] - 'E' == 0) cout << 'W';
                    else cout << 'E';
                }
                else if (y_neg && is_y(ans[i]))
                {
                    if(ans[i] - 'N' == 0) cout << 'S';
                    else cout << 'N';
                }
                else cout << ans[i];
            }
            cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
