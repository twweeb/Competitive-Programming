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
int numb;

int ret[200];
int numq;

int qry(int idx) {
  numq++;
  assert(idx >= 1 && idx <= numb);
  cout << idx << endl;
  int ans;
  cin >> ans;
  return ans;
}

void refresh(int amt) {
  int equal = -1;
  int different = -1;
  for(int a = 1; a <= amt; a++) {
    if(ret[a] == ret[numb+1-a]) {
      equal = a;
    }
    else {
      different = a;
    }
  }
  if(equal != -1) {
    int ans = qry(equal);
    if(ans != ret[equal]) {
      // flip everything
      for(int a = 1; a <= amt; a++) {
        ret[a] ^= 1;
        ret[numb+1-a] ^= 1;
      }
    }
    if(different != -1) {
      ans = qry(different);
      if(ans != ret[different]) {
        assert(ans == ret[numb+1-different]);
        for(int a = 1; a <= amt; a++) swap(ret[a], ret[numb+1-a]);
      }
    }
    else {
      qry(equal); // just to force it to not mess us up
    }
  }
  else {
    assert(equal == -1);
    assert(different != -1);
    int ans = qry(different);
    if(ans != ret[different]) {
      assert(ans == ret[numb+1-different]);
      for(int a = 1; a <= amt; a++) swap(ret[a], ret[numb+1-a]);
    }
    // then reversal is "equivalent", so we just query one bit
    qry(different); // just to avoid getting wrecked
  }
}

void rsolve() {
  cerr << numb << endl;
  numq = 0;
  memset(ret, -1, sizeof(ret));
  for(int i = 1; i <= numb/2; i++) {
    assert(numq%2 == 0);
    if(numq && numq % 10 == 0) {
      // we need to know if there was a reversal
      refresh(i-1);
    }
    ret[i] = qry(i);
    ret[numb+1-i] = qry(numb+1-i);
  }
  for(int i = 1; i <= numb; i++) {
    cout << ret[i];
  } cout << endl;
  string s;
  cin >> s;
  assert(s == "Y");
}

void solve() {
  int t;
  cin >> t >> numb;
  for(int casenum = 1; casenum <= t; casenum++) {
    // cout << "Case #" << casenum << ": ";
    rsolve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
