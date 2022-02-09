#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

class BitTree {
private:
  int a[MAXN];
  static int lowbit(int x) { return x & -x; }

public:
  void add(int x, int y) {
    for (; x < MAXN; x += lowbit(x)) {
      a[x] += y;
    }
  }

  int get(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) {
      ans += a[x];
    }
    return ans;
  }
} tree;

struct que {
  int l, r, id;
  bool operator<(const que& cmp) const {
    if (r != cmp.r) return r < cmp.r;
    return l < cmp.l;
  }
} que[MAXN];

struct node {
  int l, r;
  bool operator<(const node& cmp) const {
    if (r != cmp.r) return r < cmp.r;
    return l < cmp.l;
  }
} nodes[MAXN];

struct num {
  int value, id;
  bool operator<(const num& cmp) const { return value < cmp.value; };
} a[MAXN];

int tot = 0;
int n, m;
int b[MAXN];

void add_node(const num& x, const num& y) {
  int i = min(x.id, y.id);
  int j = max(x.id, y.id);
  nodes[++tot] = {i, j};
}

int main() {
  cin >> n >> m;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].value;
    a[i].id = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> que[i].l >> que[i].r;
    que[i].id = i;
  }
  sort(que + 1, que + 1 + m);
  sort(a + 1, a + 1 + n);
  add_node(a[1], a[2]);
  add_node(a[n - 1], a[n]);
  for (int i = 2; i < n; i++) {
    int l = a[i].value - a[i - 1].value;
    int r = a[i + 1].value - a[i].value;
    if (l < r) {
      add_node(a[i], a[i - 1]);
    } else if (l > r) {
      add_node(a[i], a[i + 1]);
    } else {
      add_node(a[i], a[i - 1]);
      add_node(a[i], a[i + 1]);
    }
  }
  sort(nodes + 1, nodes + 1 + tot);
  long long ans = 0;
  for (int i = 1, j = 1; i <= m; i++) {
    while (nodes[j].r <= que[i].r && j <= tot) {
      tree.add(nodes[j].l, 1);
      j++;
    }
    ans += (long long)que[i].id * (j - 1 - tree.get(que[i].l - 1));
  }
  cout << ans << endl;
  return 0;
}
