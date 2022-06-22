#include <bits/stdc++.h>

using namespace std;

const __int128 kMaxN = 1e6;

int read() {
  int w = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0')   { f = ch == '-' ? -1 : 1; ch = getchar(); }
  while (ch >= '0' && ch <= '9') { w = w * 10 + ch - '0'; ch = getchar(); }
  return w * f;
}

struct Frac {
  __int128 p, q;
  __int128 gcd(__int128 x, __int128 y) {
    return (y > 0 ? gcd(y, x % y) : x);
  }
  Frac() {
    p = 0;
    q = 1;
  }

  Frac& operator += (Frac& t) {
    p = p * (t.q) + (t.p) * q;
    q = q * (t.q);
    __int128 c = gcd(p, q);
    p /= c;
    q /= c;
    return *this;
  }

  Frac& operator /= (__int128 n) {
    q *= n;
    return *this;
  }
};

void write(__int128 w) {
  if (w >= 10) {
    write(w / 10);
  }
  putchar(w % 10 + '0');
}

int n, m;
int in[kMaxN];
vector<int> g[kMaxN];
vector<int> End;
queue<int> q;
Frac dis[kMaxN];

int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    int d;
    d = read();
    if (d == 0) {
      End.push_back(i);
    }
    while (d--) {
      int x;
      x = read();
      g[i].push_back(x);
      in[x]++;
    }
  }
  for (int i = 1; i <= m; i++) dis[i].p = 1;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    if (g[f].size() == 0) continue;
    dis[f] /= g[f].size();
    for (auto i : g[f]) {
      dis[i] += dis[f];
      in[i]--;
      if (in[i] == 0) {
        q.push(i);
      }
    }
  }
  for (auto i : End) {
    write(dis[i].p);
    putchar(' ');
    write(dis[i].q);
    putchar('\n');
  }
  return 0;
}
