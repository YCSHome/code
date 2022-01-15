#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int t;

long long pow(long long a, long long b, long long p) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % p;
    }
    a = (a * a) % p;
    b >>= 1;
  }
  return ans;
}

int main() {
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int rua = 0;
    for (int i = 1; i <= m; i++) {
      int l, r, x;
      cin >> l >> r >> x;
      rua |= x;
    }
    cout << rua * pow(2, n - 1, MOD) % MOD << endl;
  }
  return 0;
}
/*
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;

const int N = 2e5 + 5, P = 1e9 + 7;

int n, m, l, r, x;

int power(int a, int b, int p = P) {
  int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = 1ll * res * a % p;
    a = 1ll * a * a % p;
  }
  return res;
}
void solve() {
  cin >> n >> m;
  int ret = 0;
  for (int i = 1; i <= m; ++i) cin >> l >> r >> x, ret |= x;
  cout << 1ll * ret * power(2, n - 1) % P << '\n';
}

int main() {
  // * c.cpp
  std::ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
 * */
