#include<iostream>

using namespace std;

int cnt = 0;

void recur(int done, int row, int col)
{
    static int ans[8]={-1}; //col i is placed on row ans[i-1]
    if(done == 8)
    {
        if(ans[col] == row)
        {
            printf("\n%2d     ", ++cnt);
            for(int i = 0; i < 8; i++) 
                printf("%2d", ans[i] + 1);
        }
        return;
    }
    for(int pos = 0; pos < 8; ++pos)
    {
        bool flag = false;
        for(int i = 0; i < done && !flag; ++i)
        {
            if(ans[i] == pos) flag = true;
            if(abs(ans[i] - pos) == abs(i - done)) flag = true;
        }
        if(flag) continue;
        ans[done] = pos;
        recur(done+1, row, col);
    }
}
void solve()
{
    int row, col;
    cin >> row >> col;
    cnt = 0;
    cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n";
    recur(0, row-1, col-1);
    cout << "\n";
}

int main()
{
    int ncases;
    cin >> ncases;
    while (ncases--)
    {
        solve();
        if(ncases) cout << "\n";
    }
    return 0;
}