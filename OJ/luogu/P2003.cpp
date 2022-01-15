/*
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n;

struct Line {
  int y, x1, x2;
  bool operator<(const Line &cmp) const { return y <= cmp.y; }
} line[MAXN];

class SegmentTree {
 private:
  struct node {
    node *left, *right;
    int l, r, value;
  };

  void pushdown(node *p) { p->left->value = p->right->value = p->value; }

  void build(node *p, int l, int r) {
    if (l > r) return;
    p->l = l, p->r = r;
    if (l == r) {
      return;
    }
    build(p->left = new node, l, r);
    build(p->right = new node, l, r);
  }

  void update(node *p) {
  }

  void change(node *p, int l, int r, int k) {
    update(p);
  }

 public:
  void change(int l, int r, int k) {}
};

void init() {}

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> line[i].y >> line[i].x1 >> line[i].x2;
  }
}

void work() { sort(line + 1, line + 1 + n); }

void output() {}

int main() {
  init();
  input();
  work();
  output();
  return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;

int n;
int ans = 0;

struct Line {
  int y, x1, x2;
  bool operator<(const Line &cmp) const { return y > cmp.y; }
} line[MAXN];

void init() {
}

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> line[i].y >> line[i].x1 >> line[i].x2;
    line[i].x1++;
  }
  line[++n] = {0, -1000000, 1000000};
}

void work() {
  sort(line + 1, line + 1 + n);
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (int j = i + 1; j <= n; j++) {
      if (line[j].x1 <= line[i].x1 && line[i].x1 <= line[j].x2) {
        ans += line[i].y - line[j].y;
        break;
      }
    }
    for (int j = i + 1; j <= n; j++) {
      if (line[j].x1 <= line[i].x2 && line[i].x2 <= line[j].x2) {
        ans += line[i].y - line[j].y;
        break;
      }
    }
  }
}

void output() {
  cout << ans << endl;
}

int main() {
  init();
  input();
  work();
  output();
  return 0;
}
