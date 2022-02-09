#include <iostream>

using namespace std;

const int MAXN = 1e6;

class SegmentTree {
private:
  struct node {
    node *left, *right;
    int Max = 0;
    int l, r;
  } * root;

  void pushup(node *p) { p->Max = max(p->left->Max, p->right->Max); }

  void build(int base[], node *p, int l, int r) {
    if (l > r) return;
    p->l = l, p->r = r;
    if (l == r) {
      p->Max = base[l];
      return;
    }
    int mid = l + ((r - l) >> 1);
    build(base, p->left = new node, l, mid);
    build(base, p->right = new node, mid + 1, r);
    pushup(p);
  }

  void update(node *p, int ID, int score) {
    if (p->l > ID || p->r < ID) {
      return;
    }
    if (p->l == p->r && p->r == ID) {
      if (p->Max < score) {
        p->Max = score;
      }
      return;
    }
    update(p->left, ID, score);
    update(p->right, ID, score);
    pushup(p);
  }

  int find(node *p, int l, int r) {
    if (p->l > r || p->r < l) {
      return 0;
    }
    if (l <= p->l && p->r <= r) {
      return p->Max;
    }
    return max(find(p->left, l, r), find(p->right, l, r));
  }

public:
  int find(int l, int r) { return find(root, l, r); }

  void update(int ID, int score) { update(root, ID, score); }

  void build(int base[], int len) { build(base, root = new node, 1, len); }
} tree;

int n, m;
int a[MAXN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  tree.build(a, n);
  while (m--) {
    char ch;
    int a, b;
    cin >> ch >> a >> b;
    if (ch == 'Q') {
      cout << tree.find(a, b) << endl;
    } else {
      tree.update(a, b);
    }
  }
  return 0;
}
