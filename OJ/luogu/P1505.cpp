#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e6 + 10;

// class SegmentTree
class SegmentTree {
private:
  struct node {
    node * left, * right;
    int l, r;
    int Max;
    int Min;
    int value;
    int lazy = 0;
    
    node(int l, int r) : l(l), r(r) {
      value = Max = Min = lazy = 0;
    }

    void change() {
      swap(Max, Min);
      Max = -Max, Min = -Min;
      value = -value;
      lazy ^= 1;
    }
  } * root;

  void pushup(node * p) {
    if (p->left == nullptr) return;
    p->value = p->left->value + p->right->value;
    p->Max = max(p->left->Max, p->right->Max);
    p->Min = min(p->left->Min, p->right->Min);
  }

  void pushdown(node * p) {
    if (p->left == nullptr) return;
    if (p->lazy == 0) return;
    p->left->change();
    p->right->change();
    p->lazy = 0;
  }

  void build(node * p, int * array, int l, int r) {
    if (l == r) {
      p->value = p->Max = p->Min = array[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node(l, mid), array, l, mid);
    build(p->right = new node(mid + 1, r), array, mid + 1, r);
    pushup(p);
  }

  int get_max(node * p, int l, int r) {
    if (l > p->r || p->l > r) {
      return INT_MIN;
    }
    if (l <= p->l && p->r <= r) {
      return p->Max;
    }
    pushdown(p);
    return max(get_max(p->left, l, r), get_max(p->right, l, r));
  }

  int get_min(node * p, int l, int r) {
    if (l > p->r || p->l > r) {
      return INT_MAX;
    }
    if (l <= p->l && p->r <= r) {
      return p->Min;
    }
    pushdown(p);
    return min(get_min(p->left, l, r), get_min(p->right, l, r));
  }

  int get_sum(node * p, int l, int r) {
    if (l > p->r || p->l > r) {
      return 0;
    }
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    pushdown(p);
    return get_sum(p->left, l, r) + get_sum(p->right, l, r);
  }

  void change(node * p, int q, int k) {
    if (q > p->r || p->l > q) {
      return;
    }
    if (q <= p->l && p->r <= q) {
      p->Max = p->Min = p->value = k;
      return;
    }
    pushdown(p);
    change(p->left, q, k);
    change(p->right, q, k);
    pushup(p);
  }

  void range(node * p, int l, int r) {
    if (l > p->r || p->l > r) {
      return;
    }
    if (l <= p->l && p->r <= r) {
      p->change();
      return;
    }
    pushdown(p);
    range(p->left, l, r);
    range(p->right, l, r);
    pushup(p);
  }
public:
  void build(int * array, int n) {
    build(root = new node(1, n), array, 1, n);
  }

  void range(int l, int r) {
    range(root, l, r);
  }

  void change(int q, int k) {
    change(root, q, k);
  }

  int get_max(int l, int r) {
    return get_max(root, l, r);
  }

  int get_min(int l, int r) {
    return get_min(root, l, r);
  }

  int get_sum(int l, int r) {
    return get_sum(root, l, r);
  }

};
// class SegmentTree

struct edge {
  int v, next, dis;
}e[kMaxN];

int tot = 0;
int head[kMaxN];
int top[kMaxN];
int heavy_son[kMaxN];
int Size[kMaxN];
int father[kMaxN];
int depth[kMaxN];
int pos[kMaxN];
int total = 0;
int a[kMaxN];

void add_edge(int u, int v, int dis) {
  e[++tot] = {v, head[u], dis};
  head[u] = tot;
}

void dfs1(int u, int f) {
  father[u] = f;
  Size[u] = 1;
  depth[u] = depth[f] + 1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == f) continue;
    dfs1(v, u);
    Size[u] += Size[v];
    if (Size[heavy_son[u]] < Size[v]) {
      heavy_son[u] = v;
    }
  }
}

void dfs2(int u, int top_, int dis) {
  pos[u] = ++total;
  top[u] = top_;
  a[total] = dis;
  if (heavy_son[u]) {
    dfs2(heavy_son[u], top_, 0);
  }
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == heavy_son[u]) {
      a[pos[v]] = e[i].dis;
    }
    if (v == father[u] || v == heavy_son[u]) continue;
    dfs2(v, v, e[i].dis);
  }
}

int n;
SegmentTree tree;

void range(int x, int y) {
  while (top[x] != top[y]) {
    if (depth[top[x]] < depth[top[y]]) {
      swap(x, y);
    }
    tree.range(pos[top[x]], pos[x]);
    x = father[top[x]];
  }
  if (depth[x] > depth[y]) {
    swap(x, y);
  }
  if (x == y) return;
  tree.range(pos[x] + 1, pos[y]);
}

int sum(int x, int y) {
  int res = 0;
  while (top[x] != top[y]) {
    if (depth[top[x]] < depth[top[y]]) {
      swap(x, y);
    }
    res += tree.get_sum(pos[top[x]], pos[x]);
    x = father[top[x]];
  }
  if (depth[x] > depth[y]) {
    swap(x, y);
  }
  if (x == y) return res;
  res += tree.get_sum(pos[x] + 1, pos[y]);
  return res;
}

int Max(int x, int y) {
  int res = INT_MIN;
  while (top[x] != top[y]) {
    if (depth[top[x]] < depth[top[y]]) {
      swap(x, y);
    }
    res = max(res, tree.get_max(pos[top[x]], pos[x]));
    x = father[top[x]];
  }
  if (depth[x] > depth[y]) {
    swap(x, y);
  }
  return max(res, tree.get_max(pos[x] + 1, pos[y]));
}

int Min(int x, int y) {
  int res = INT_MAX;
  while (top[x] != top[y]) {
    if (depth[top[x]] < depth[top[y]]) {
      swap(x, y);
    }
    res = min(res, tree.get_min(pos[top[x]], pos[x]));
    x = father[top[x]];
  }
  if (depth[x] > depth[y]) {
    swap(x, y);
  }
  if (x == y) return res;
  return min(res, tree.get_min(pos[x] + 1, pos[y]));
}

vector<pair<int, int>> edge;

int main() {
  string str;
  edge.push_back(make_pair(0, 0));
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y, dis;
    cin >> x >> y >> dis;
    x++, y++;
    add_edge(x, y, dis);
    add_edge(y, x, dis);
    edge.push_back(make_pair(x, y));
  }
  dfs1(1, 0);
  dfs2(1, 1, 0);
  tree.build(a, n);
  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> str >> u >> v;
    u++, v++;
    if (str == "SUM") {
      cout << sum(u, v) << endl;
    } else if (str == "MAX") {
      cout << Max(u, v) << endl;
    } else if (str == "N") {
      range(u, v);
    } else if (str == "MIN") {
      cout << Min(u, v) << endl;
    } else if (str == "C") {
      u--;
      v--;
      int x = edge[u].first,
          y = edge[u].second,
          temp;
      if (depth[x] > depth[y]) {
        temp = pos[x];
      } else {
        temp = pos[y];
      }
      tree.change(temp, -tree.get_sum(temp, temp));
      tree.change(temp, v);
    } else {
      return -1;
    }
  }
  return 0;
}
