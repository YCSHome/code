#include <iostream>
#include <stack>

using namespace std;

const int kMaxN = 1e6;

class SegmentTree {
private:
  struct node {
    int l, r;
    int max;
    int min;
    int lazy;
    int value;
    node * left, * right;

    void pushup() {
      value = left->value + right->value;
      min = std::min(left->min, right->min);
      max = std::max(left->max, right->max);
    }
  };

  stack<node*> pool;

  node * newnode() {
    if (!pool.empty()) {
      return pool.top();
    }
    return new node;
  }

  void erase(node * p) {
    if (p == nullptr) return;
    p->l = p->r = p->left = p->right = p->value = p->lazy = p->max = p->min = 0;
    pool.push(p);
  }

  void clear(node * p) {
    if (p == nullptr) return;
    clear(p->left), clear(p->right);
    erase(p);
  }

  void build(node * p, int l, int r) {
    p->l = l, p->r = r;
    if (p->l == p->r) {
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = newnode(), l, mid);
    build(p->right = newnode(), mid + 1, r);
  }

  void change(node * p, int l, int r) {
  }

public:
};

int n, m;

void solve() {
  cin >> n >> m;
}

int main() {
  int t;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}

