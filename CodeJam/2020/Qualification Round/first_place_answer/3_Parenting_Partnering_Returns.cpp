#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;

// remember you may need to reset state
int lhs[1005];
int rhs[1005];
int dp[1005];
bool g[1005][1005];
void rsolve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> lhs[i] >> rhs[i];
  for(int i = 0; i < n; i++) {
    dp[i] = 0;
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      g[i][j] = false;
      if(lhs[j] >= rhs[i]) continue;
      if(lhs[i] >= rhs[j]) continue;
      g[i][j] = true;
    }
  }
  queue<int> q;
  string ret = "";
  for(int i = 0; sz(ret) == 0 && i < n; i++) {
    if(dp[i]) continue;
    dp[i] = 1;
    q.push(i);
    while(sz(ret) == 0 && sz(q)) {
      int curr = q.front(); q.pop();
      for(int a = 0; a < n; a++) {
        if(g[curr][a]) {
          if(dp[a] == dp[curr]) {
            ret = "IMPOSSIBLE";
            break;
          }
          if(dp[a] == 0) {
            dp[a] = -dp[curr];
            q.push(a);
          }
        }
      }
    }
  }
  if(sz(ret)) {
    cout << ret << "\n";
    return;
  }
  for(int i = 0; i < n; i++) {
    if(dp[i] == 1) cout << 'C';
    else cout << 'J';
  } cout << "\n";
}

void solve() {
  int t;
  cin >> t;
  for(int casenum = 1; casenum <= t; casenum++) {
    cout << "Case #" << casenum << ": ";
    rsolve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
