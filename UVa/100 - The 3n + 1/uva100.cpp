#include <iostream>

using namespace std;

int cycle_cnt(int t){
    int cnt = 1;
    while(t != 1) {
        ++cnt;
        t = (t%2 == 1) ? 3*t+1 : t/2;
    }
    return cnt;
}

int main() {
    int i, j, ans;
    while(scanf("%d %d", &i, &j) == 2) {
        ans = 0;
        for(int t = min(i, j); t <= max(i, j); ++t) {
            ans = max(ans, cycle_cnt(t));
        }
        cout << i << " " << j << " " << ans << endl;
    }

    return 0;
}