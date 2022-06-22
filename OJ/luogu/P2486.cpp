#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

const int kMaxN = 1e6;

struct len {
  int left_color = 0, right_color = 0, value = 0;
  friend len Union(const len& a, const len& b) {
    if (b.value == 0) return a;
    if (a.value == 0) return b;
    len temp;
    temp.value = a.value + b.value;
    temp.left_color = a.left_color;
    temp.right_color = b.right_color;
    if (a.right_color == b.left_color) temp.value--;
    return temp;
  }
};

class SegmentTree {
private:
  struct node {
    int l, r;
    node * left, * right;
    int left_color;
    int right_color;
    int value;
    int lazy = 0;

    node(int l, int r): l(l), r(r) {
      value = lazy = left_color = right_color = 0;
    }

    void change(int color) {
      left_color = right_color = color;
      value = 1;
      lazy = color;
    }
  } * root;

  void pushup(node * p) {
    p->value = p->left->value + p->right->value;
    p->left_color = p->left->left_color;
    p->right_color = p->right->right_color;
    if (p->left->right_color == p->right->left_color) {
      p->value--;
    }
  }

  void pushdown(node * p) {
    if (p->lazy) {
      p->left->change(p->lazy);
      p->right->change(p->lazy);
      p->left->lazy = p->right->lazy = p->lazy;
      p->lazy = 0;
    }
  }

  void build(node * p, int * array, int l, int r) {
    if (l == r) {
      p->change(array[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node(l, mid), array, l, mid);
    build(p->right = new node(mid + 1, r), array, mid + 1, r);
    pushup(p);
  }

  void change(node * p, int l, int r, int k) {
    if (l > p->r || p->l > r) {
      return;
    }
    if (l <= p->l && p->r <= r) {
      p->change(k);
      return;
    }
    pushdown(p);
    change(p->left, l, r, k);
    change(p->right, l, r, k);
    pushup(p);
  }

  len get(node * p, int l, int r) {
    if (l <= p->l && p->r <= r) {
      return {p->left_color, p->right_color, p->value};
    }
    pushdown(p);
    int mid = (p->l + p->r) >> 1;
    if (r <= mid) {
      return get(p->left, l, r);
    } else if (l > mid) {
      return get(p->right, l, r);
    }
    return Union(get(p->left, l, r), get(p->right, l, r));
  }
public:
  void build(int * array, int n) {
    build(root = new node(1, n), array, 1, n);
  }

  len get(int l, int r) {
    return get(root, l, r);
  }

  void change(int l, int r, int k) {
    change(root, l, r, k);
  }
}tree;

struct edge {
  int v, next;
}e[kMaxN];

int head[kMaxN];
int tot = 0;
int a[kMaxN];

void add_edge(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

namespace Tree {
  int size[kMaxN];
  int depth[kMaxN];
  int son[kMaxN];
  int father[kMaxN];
  int top[kMaxN];
  int pos[kMaxN];
  int dis[kMaxN];
  int tot = 0;

  void dfs1(int u, int f) {
    size[u] = 1;
    depth[u] = depth[f] + 1;
    father[u] = f;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (v == f) continue;
      dfs1(v, u);
      size[u] += size[v];
      if (size[v] > size[son[u]]) {
        son[u] = v;
      }
    }
  }

  void dfs2(int u, int top_) {
    top[u] = top_;
    pos[u] = ++tot;
    dis[tot] = a[u];
    if (son[u]) {
      dfs2(son[u], top_);
    }
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (v == son[u] || v == father[u]) {
        continue;
      }
      dfs2(v, v);
    }
  }

  int ask(int x, int y) {
    int a = -1, b = -1;
    int ans = 0;
    while (top[x] != top[y]) {
      if (depth[top[x]] < depth[top[y]]) {
        std::swap(x, y);
        std::swap(a, b);
      }
      len temp = tree.get(pos[top[x]], pos[x]);
      ans += temp.value;
      if (temp.right_color == a) {
        ans--;
      }
      a = temp.left_color;
      x = father[top[x]];
    }
    if (depth[x] < depth[y]) {
      std::swap(x, y);
      std::swap(a, b);
    }
    len temp = tree.get(pos[y], pos[x]);
    ans += temp.value;
    if (temp.right_color == a) ans--;
    if (temp.left_color == b) ans--;
    return ans;
  }

  void change(int x, int y, int k) {
    while (top[x] != top[y]) {
      if (depth[top[x]] < depth[top[y]]) {
        std::swap(x, y);
      }
      tree.change(pos[top[x]], pos[x], k);
      x = father[top[x]];
    }
    if (depth[x] > depth[y]) {
      std::swap(x, y);
    }
    tree.change(pos[x], pos[y], k);
  }
};

int n, m;

int main() {
  using Tree::dis;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
    add_edge(v, u);
  }
  Tree::dfs1(1, 0);
  Tree::dfs2(1, 1);
  tree.build(dis, n);
  while (m--) {
    char ch;
    int a, b, k;
    cin >> ch >> a >> b;
    if (ch == 'Q') {
      cout << Tree::ask(a, b) << endl;
    } else {
      cin >> k;
      Tree::change(a, b, k);
    }
  }
  return 0;
}
