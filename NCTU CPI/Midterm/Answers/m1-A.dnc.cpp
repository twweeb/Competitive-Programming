#include<bits/stdc++.h>

using namespace std;

map<int, int> f;
int k;

long long dnc(vector<int> &a) {
    int n = a.size();
    if (n <= 1) return 0LL;
    vector<int> left, right;
    for (int i = 0; i < n/2; i++) {
        left.push_back(a[i]);
    }
    for (int i = n/2; i < n; i++) {
        right.push_back(a[i]);
    }
    long long ans = dnc(left) + dnc(right);
    int p, q, r;
    vector<long long> cnt(k);
    for(auto v: left) cnt[v%k]++;
    for(p = q = r = 0; p < left.size() and q < right.size(); ) {
        if (f[left[p]] <= f[right[q]]) {
            cnt[left[p]%k]--;
            a[r++] = left[p++];
        } else {
            for (int i = 0; i < k; i++) {
                ans += cnt[i] * ((i+right[q])%k);
            }
            a[r++] = right[q++];
        }
    }
    while (p < left.size()) a[r++] = left[p++];
    while (q < right.size()) a[r++] = right[q++];
    return ans;
}

void solve() {
    int n;
    scanf("%d%d",&n,&k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    for (int i = 0; i < n; i++) {
        int b;
        scanf("%d",&b);
        f[b] = i;
    }
    printf("%lld\n",dnc(a));
}

int main() {
    solve();
}
