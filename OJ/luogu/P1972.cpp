#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7;

struct que {
  int x, y, id;
  bool operator<(const que& cmp) const { return y < cmp.y; }
} qu[MAXN];

class BitTree {
private:
  int a[MAXN];
  int lowbit(int x) { return x & -x; }

public:
  void add(int x, int k) {
    for (; x < MAXN - 1; x += lowbit(x)) {
      a[x] += k;
    }
  }

  int get(int x) {
    int ans = 0;
    for (; x > 0; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }
} tree;

int a[MAXN];
int d[MAXN];
int ans[MAXN];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> qu[i].x >> qu[i].y;
    qu[i].id = i;
  }
  sort(qu + 1, qu + 1 + q);
  int next = 1;
  for (int i = 1; i <= q; i++) {
    for (int j = next; j <= qu[i].y; j++) {
      if (d[a[j]]) {
        tree.add(d[a[j]], -1);
      }
      tree.add(j, 1);
      d[a[j]] = j;
    }
    next = qu[i].y + 1;
    ans[qu[i].id] = tree.get(qu[i].y) - tree.get(qu[i].x - 1);
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
