#include<bits/stdc++.h>

using namespace std;

int bit[1000001];
int n;

void update(int x, int y) {
    for(int pos = x; pos <= n && bit[pos] < y; pos += pos & -pos)
        bit[pos] = y;
}

int query(int x) {
    int res = 0;
    for(int pos = x; pos > 0; pos -= pos & -pos)
        res = max(res, bit[pos]);
    return res;
}

int main() {
    scanf("%d",&n);
    vector<int> cmd(n);
    vector<long long> timestamp(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++) {
        scanf("%d%lld",&cmd[i], &timestamp[i]);
        if (cmd[i]==1) scanf("%d",&y[i]);
    }
    vector<long long> sorted_time = timestamp;
    sort(sorted_time.begin(), sorted_time.end());
    for(int i = 0; i < n; i++) {
        int x = 1+(lower_bound(sorted_time.begin(),sorted_time.end(),timestamp[i]) - sorted_time.begin());
        if (cmd[i]==1) {
            update(x, y[i]);
        } else {
            printf("%d\n",query(x));
        }
    }
    return 0;
}
