#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; ++ i)
#define drep(i, s, e) for (int i = s; i >= e; -- i)
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)

const int N = 100000 + 5;

int read() {
  int x = 0, f = 1; char c = getchar();
  while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}

int n, m, k, lm[N], rm[N], um[N], dm[N], I_F[N], tag[N];
vector <int> a[N];  

void add(int s, int t, int u, int v, int k) {
  rep(i, s, u) {
    rep(j, t, v) {
      if (a[i][j] != k) tag[a[i][j]] = 1;
    }
  }
} 

int main() {
  file(paint);
  n = read(), m = read(), k = read();
  rep(i, 1, k) lm[i] = m + 1, um[i] = n + 1; 
  rep(i, 1, n) a[i].resize(m + 1);
  rep(i, 1, n) { 
    rep(j, 1, m) {
      a[i][j] = read();
      I_F[a[i][j]] = 1, lm[a[i][j]] = min(lm[a[i][j]], j), rm[a[i][j]] = max(rm[a[i][j]], j), um[a[i][j]] = min(um[a[i][j]], i), dm[a[i][j]] = max(dm[a[i][j]], i);
    }
  } 
  rep(i, 1, k) {  
    if (!I_F[i]) continue;
    add(um[i], lm[i], dm[i], rm[i], i);
  }
  int ans = 0;
  rep(i, 1, k) if (!tag[i]) ++ ans;
  printf("%d\n", ans);
  return 0; 
}       