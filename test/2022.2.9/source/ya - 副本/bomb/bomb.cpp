#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for (int i = s; i <= e; ++i)
#define drep(i, s, e) for (int i = s; i >= e; --i)
#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

const int N = 1e6 + 10;
const int W = 5e8;

int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  return x * f;
}

int n, a[N];

int maxp;
void calc(int *f) {
  maxp = 0;
  priority_queue<pii, vector<pii>, greater<pii> > q;
  f[1] = 0, q.push(make_pair(0, 1));
  rep(i, 2, n) {
    f[i] = INF;
    while (q.size()) {
      auto u = q.top();
      if (a[i] - a[u.second] >= u.first)
        maxp = max(maxp, u.second), q.pop();
      else {
        f[i] = u.first;
        break;
      }
    }
    if (maxp) f[i] = min(f[i], a[i] - a[maxp]);
    q.push(make_pair((int)(f[i] * 1.5 + 0.75), i));
  }
}

int fl[N], fr[N], ans = INF;

int main() {
  file(bomb);
  n = read();
  rep(i, 1, n) a[i] = read();
  sort(a + 1, a + n + 1);
  calc(fl);
  reverse(a + 1, a + n + 1);
  rep(i, 1, n) a[i] = W - a[i];
  calc(fr);
  reverse(fr + 1, fr + n + 1);
  // cout << "fl : ";
  // rep(i, 1, n) cout << fl[i] << ' ';
  // cout << endl;
  // cout << "fr : ";
  // rep(i, 1, n) cout << fr[i] << ' ';
  // cout << endl;
  rep(i, 1, n) ans = min(ans, max(fl[i], fr[i]));
  printf("%d\n", ans);
  return 0;
}