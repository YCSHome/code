#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
  struct node {
    node *left, *right;
    int left_len, right_len;
    int left_pos, right_pos;
    int len;
    int LEN = 0;
    int l, r;
    node(int l_, int r_) : l(l_), r(r_){};
  } * root;

  void pushup(node* p) {
    p->len = max(p->right->len, p->left->len);
    if (p->left->right_pos != p->right->left_pos) {
      p->len = max(p->len, p->left->right_len + p->right->left_len);
    }
    p->left_pos = p->left->left_pos;
    p->right_pos = p->right->right_pos;
    if (p->left->left_len == p->left->LEN &&
        p->left->right_pos != p->right->left_pos) {
      p->left_len = p->left->left_len + p->right->left_len;
    } else {
      p->left_len = p->left->left_len;
    }

    if (p->right->right_len == p->right->LEN &&
        p->right->left_pos != p->left->right_pos) {
      p->right_len = p->right->right_len + p->left->right_len;
    } else {
      p->right_len = p->right->right_len;
    }
  }

  void build(node* p) {
    p->LEN = p->r - p->l + 1;
    if (p->l == p->r) {
      p->left_pos = p->right_pos = 0;
      p->left_len = p->right_len = p->len = 1;
      return;
    }
    int mid = (p->r + p->l) / 2;
    build(p->left = new node(p->l, mid));
    build(p->right = new node(mid + 1, p->r));
    pushup(p);
  }

  void change(node* p, int x) {
    if (p->l > x || p->r < x) return;
    if (p->l == x && p->r == x) {
      p->left_pos = p->right_pos = p->left_pos ^ 1;
      p->left_len = p->right_len = p->len = 1;
      return;
    }
    change(p->left, x);
    change(p->right, x);
    pushup(p);
  }

public:
  void build(int n) { build(root = new node(1, n)); }

  void change(int x) { change(root, x); }

  int get() {
    pushup(root);
    return root->len;
  }
} tree;

int n, q, d;

int main() {
  cin >> n >> q;
  tree.build(n);
  while (q--) {
    cin >> d;
    tree.change(d);
    cout << tree.get() << endl;
  }
  return 0;
}
