#include <iostream>
#include <cmath>
#include <algorithm>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int blockSize = 0;

int getBlock(int x) {
  return (x - 1) / blockSize + 1;
}

struct q {
  int l, r;
  int ID;
  bool operator<(const q& cmp) const {
    return getBlock(l) == getBlock(cmp.l) ? r < cmp.r : l < cmp.l;
  }
}b[kMaxN];

int n, m;
int a[kMaxN];
int ansA[kMaxN];
int ansB[kMaxN];
int cnt[kMaxN];
int ans = 0;

void del(int x) {
  ans -= cnt[x] * cnt[x];
  cnt[x]--;
  ans += cnt[x] * cnt[x];
}

void add(int x) {
  ans -= cnt[x] * cnt[x];
  cnt[x]++;
  ans += cnt[x] * cnt[x];
}

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

signed main() {
  cin >> n >> m;
  blockSize = sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].l >> b[i].r;
    b[i].ID = i;
  }
  sort(b + 1, b + 1 + m);
  int l = 1, r = 0;
  for (int i = 1; i <= m; i++) {
    while (r < b[i].r) { add(a[++r]); }
    while (r > b[i].r) { del(a[r--]); }
    while (l < b[i].l) { del(a[l++]); }
    while (l > b[i].l) { add(a[--l]); }
    if (b[i].l == b[i].r) {
      ansA[b[i].ID] = 0;
      ansB[b[i].ID] = 1;
      continue;
    }
    int t = ans - (b[i].r - b[i].l + 1);
    int len = (b[i].r - b[i].l + 1) * (b[i].r - b[i].l);
    int g = gcd(t, len);
    ansA[b[i].ID] = t / g;
    ansB[b[i].ID] = len / g;
  }
  for (int i = 1; i <= m; i++) {
    cout << ansA[i] << "/" << ansB[i] << endl;
  }
  return 0;
}
