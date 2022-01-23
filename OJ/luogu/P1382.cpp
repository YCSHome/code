#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e7;

struct node {
  int h, x, opt;
  // 先按照x轴进行排序，然后按照加减状态排序
  bool operator<(const node& cmp) const {
    if (x != cmp.x) return x < cmp.x;
    return opt > cmp.opt;
  };
}a[MAXN];

class SegmentTree {
private:
  struct node {
    node * left, * right;
    int add;
    int l, r;
    int value;
    node(int l_, int r_) : l(l_), r(r_) { };
  } * root;

  void pushup(node * p) {
    p->value = p->left->value + p->right->value;
  }

  void pushdown(node * p) {
    if (p->add && p->right != nullptr) {
      p->left->value += (p->left->r - p->left->l + 1) * p->add;
      p->right->value += (p->right->r - p->right->l + 1) * p->add;
      p->left->add += p->add;
      p->right->add += p->add;
    }
    p->add = 0;
  }

  void build(node * p) {
    if (p->l == p->r) {
      p->value = 0;
      return;
    }
    int mid = p->l + ((p->r - p->l) >> 1);
    build(p->left = new node(p->l, mid));
    build(p->right = new node(mid + 1, p->r));
    pushup(p);
  }

  int get(node * p) {
    if (p->l == p->r) {
      return p->l;
    }
    pushdown(p);
    if (p->right->value) {
      return get(p->right);
    }
    if (p->left->value) {
      return get(p->left);
    }
    return 0;
  }

  void add(node * p, int l, int r, int k) {
    if (p->r < l || p->l > r) {
      return;
    }
    pushdown(p);
    if (l <= p->l && p->r <= r) {
      p->add += k;
      p->value += (p->r - p->l + 1) * k;
      return;
    }
    add(p->left, l, r, k);
    add(p->right, l, r, k);
    pushup(p);
  }

  int sum(node * p, int l, int r) {
    if (p->r < l || p->l > r) {
      return 0;
    }
    pushdown(p);
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    return sum(p->left, l, r) + sum(p->right, l, r);
  }

public:
  int get() {
    return get(root);
  }

  int sum(int l, int r) {
    return sum(root, l, r);
  }

  void build(int n) {
    build(root = new node(1, n));
  }

  void add(int l, int r, int k) {
    add(root, l, r, k);
  }
}tree;

struct Node {
  int x, y;
};

int n;
int b[MAXN];
int c[MAXN], cnt = 0, tot = 0;
vector<Node> ans;

// cnt 为数字个数
// tot 为线段个数

int main() {
  cin >> n;
  b[1] = c[1] = 0;
  cnt++;
  for (int i = 1; i <= n; i++) {
    int h, l, r;
    cin >> h >> l >> r;
    a[++tot] = {h, l, 1};
    a[++tot] = {h, r, -1};
    c[++cnt] = h;
  }
  sort(a + 1, a + 1 + tot);
  sort(c + 1, c + 1 + cnt);
  cnt = unique(c + 1, c + 1 + cnt) - c - 1;
  tree.build(cnt + 10);
  for (int i = 1; i <= tot; i++) { a[i].h = lower_bound(c + 1, c + 1 + cnt, a[i].h) - c; }

  int last = 0;
  for (int i = 1, j; i <= tot; ) {
    for (j = i; a[i].x == a[j].x && j <= tot; j++)  {
      tree.add(1, a[j].h, a[j].opt);
    }
    int now = tree.get();
    if (now != last) {
      ans.push_back({a[i].x, c[last]});
      ans.push_back({a[i].x, c[now]});
    }
    last = now;
    i = j;
  }

  cout << ans.size() << endl;
  for (auto & i : ans) {
    cout << i.x << " " << i.y << endl;
  }
}
