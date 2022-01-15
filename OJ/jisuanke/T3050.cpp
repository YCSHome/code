// 哈哈哈哈我其实早做出来了但是没有交哈哈哈哈哈哈哈哈哈哈哈
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e6;

struct que {
  int l, r, ID = 0;
  bool operator<(const que &cmp) const { return r < cmp.r; }
}Q[MAXN];

class SegmentTree {
private:
  struct node {
    node *left, *right;
    int l, r;
    int node, len;
  } * root;

  void pushup(node *p) {
    p->len = max(p->left->len, p->right->len);
    p->node = max(p->left->node, p->right->node);
  }

  void build(node *p, int l, int r) {
    if (l > r) return;
    p->l = l, p->r = r;
    if (l == r) {
      return;
    }
    int mid = l + ((r - l) >> 1);
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
    pushup(p);
  }

  int find_len(node *p, int l, int r) {
    if (p->l > r || p->r < l) {
      return -1;
    }
    if (l <= p->l && p->r <= r) {
      return p->len;
    }
    return max(find_len(p->left, l, r), find_len(p->right, l, r));
  }

  int find_node(node *p, int l, int r) {
    if (p->l > r || p->r < l) {
      return -1;
    }
    if (l <= p->l && p->r <= r) {
      return p->node;
    }
    return max(find_node(p->left, l, r), find_node(p->right, l, r));
  }

  void update(node *p, int pos, int value) { 
    if (p->l > pos || p->r < pos) {
      return;
    }
    if (p->l == p->r) {
      p->node = value;
      p->len = value - pos + 1;
      return;
    }
    update(p->left, pos, value);
    update(p->right, pos, value);
    pushup(p);
  }

public:
  void build(int n) { build(root = new node, 1, n); }

  void update(int pos, int value) { update(root, pos, value); }

  int find_len(int l, int r) { return find_len(root, l, r); }

  int find_node(int l, int r) { return find_node(root, l, r); }
}tree;

int n, q;
int a[MAXN];
int cnt[MAXN];
int pos[MAXN];
int ans[MAXN];

int main() {
  cin >> n >> q;
  tree.build(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> Q[i].l >> Q[i].r;
    Q[i].ID = i;
  }
  sort(Q + 1, Q + 1 + q);
  int r = 1;
  for (int i = 1; i <= n; i++) {
    if (i != 1) --cnt[a[i - 1]];
    while (r <= n && cnt[a[r]] == 0) {
      pos[r] = i;
      ++cnt[a[r]];
      ++r;
    }
  }
  int now = 1;   // 头指针
  for (int i = 1; i <= n; i++) {
    tree.update(pos[i], i);
    while (now <= q && Q[now].r == i) {
      ans[Q[now].ID] =
        max(tree.find_node(1, Q[now].l) - Q[now].l + 1, tree.find_len(Q[now].l, Q[now].r));
      now++;
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
