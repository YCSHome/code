#include <ios>
#include <iostream>
#include <iterator>
#include <tuple>
#include <utility>

using namespace std;

const int kMaxN = 300;

int n;
int father[kMaxN * kMaxN];
int a[kMaxN][kMaxN];

inline int getID(int x, int y) {
  return x * kMaxN + y;
}

inline int getFather(int x) {
  return x == father[x] ? x : father[x] = getFather(father[x]);
}

class SegmentTree {
private:
  struct node {
    int l, r;
    int blackBlock = 0;
    int whiteBlock = 0;
    int up[kMaxN];
    int down[kMaxN];
    node * left, * right;

    void init() {
      blackBlock = whiteBlock = 0;
      for (int i = 1; i <= n; i++) {
        up[i] = down[i] = father[getID(l, i)] = getID(l, i);
        if (a[l][i]) blackBlock++;
        else whiteBlock++;
      }
      for (int i = 2; i <= n; i++) {
        if (a[l][i] == a[l][i - 1]) {
          father[getID(l, i)] = up[i] = down[i] = father[getID(l, i - 1)];
          if (a[l][i]) blackBlock--;
          else whiteBlock--;
        }
      }
    }

    void pushup() {
      blackBlock = left->blackBlock + right->blackBlock;
      whiteBlock = left->whiteBlock + right->whiteBlock;
      int up = left->r;
      int down = right->l;
      for (int i = 1; i <= n; i++) {
        this->up[i] = left->up[i];
        this->down[i] = right->down[i];
        father[left->up[i]] = left->up[i];
        father[left->down[i]] = left->down[i];
        father[right->up[i]] = right->up[i];
        father[right->down[i]] = right->down[i];
      }
      for (int i = 1; i <= n; i++) {
        if (a[up][i] == a[down][i]) {
          int x = getFather(left->down[i]);
          int y = getFather(right->up[i]);
          if (x == y) continue;
          father[x] = y;
          if (a[up][i] == 0) whiteBlock--;
          else blackBlock--;
        }
      }
      for (int i = 1; i <= n; i++) {
        this->up[i] = getFather(this->up[i]);
        this->down[i] = getFather(this->down[i]);
      }
    }
  } * root;

  void build(node * p, int l, int r) {
    p->l = l, p->r = r;
    if (l == r) {
      p->init();
      return;
    }
    int mid = (l + r) >> 1;
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
    p->pushup();
  }

  void change(node * p, int x, int y) {
    if (p->l > x || p->r < x) {
      return;
    }
    if (p->l == x && p->r == x) {
      a[x][y] ^= 1;
      p->init();
      return;
    }
    change(p->left, x, y);
    change(p->right, x, y);
    p->pushup();
  }

  void print(node * p) {
    if (p == nullptr) return;
    cout << "l:" << p->l << " r:" << p->r << " white:" << p->whiteBlock << " black" << p->blackBlock << endl;
    print(p->left);
    print(p->right);
  }
public:
  void build(int n) { build(root = new node, 1, n); }
  void change(int x, int y) { change(root, x, y); }
  int countBlack() { return root->blackBlock; }
  int countWhite() { return root->whiteBlock; }
  void print() { print(root); }
}t;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  t.build(n);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    t.change(x, y);
    cout << t.countBlack() << " " << t.countWhite() << endl;
  }
  return 0;
}
/*
   0 1 0 0 0
   0 1 1 1 0
   1 0 0 0 1
   0 0 1 0 0
   1 0 0 0 0
l:1 r:3 white:3 black3
l:4 r:5 white:1 black2

l:1 r:5 white:2 black5
l:1 r:2 white:2 black1
l:1 r:1 white:2 black1
l:2 r:2 white:2 black1
l:3 r:3 white:1 black2
l:4 r:4 white:2 black1
l:5 r:5 white:1 black1
*/
