#include<bits/stdc++.h>

using namespace std;

int bit[10][100001]={};
int n;

void update(int i, int x) { // y is 1 in this case
    for(int pos = x; pos <= n; pos += pos & -pos)
        bit[i][pos] += 1;
}

long long query(int i, int x) {
    long long res = 0LL;
    for(int pos = x; pos > 0; pos -= pos & -pos)
        res += bit[i][pos];
    return res;
}

int main() {
    int k;
    long long ans = 0LL;
    scanf("%d%d",&n,&k);
    vector<int> a(n);
    vector<int> b(n);
    map<int,int> f;
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d",&b[i]);
        f[b[i]] = i+1;
    }
    for(int i = n-1; i >= 0; i--) {
        int bucket = a[i] % k;
        int order = f[a[i]];
        for (int j = 0; j < k; j++) {
            ans += ((bucket+j)%k) * query(j, order);
        }
        update(bucket, order);
    }
    printf("%lld\n",ans);
    return 0;
}
