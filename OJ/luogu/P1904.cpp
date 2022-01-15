#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAXN = 1e6;

int tot;

class SegmentTree {
private:
  struct node {
    node *left, *right;
    int l, r;
    int value;
    int lazy;
    node() {
      l = r = value = lazy = 0;
    }
  }*root;

  void pushdown(node* p) {
    if (p->lazy != 0) {
      if (p->left != nullptr) {
        p->left->value += (p->left->r - p->left->l + 1) * p->lazy;
        p->left->lazy += p->lazy;
      }
      if (p->right != nullptr) {
        p->right->value += (p->right->r - p->right->l + 1) * p->lazy;
        p->right->lazy += p->lazy;
      }
    }
    p->lazy = 0;
  }

  void update(node *p) {
    p->value = 0;
    if (p->left != nullptr) {
      p->value += p->left->value;
    }
    if (p->right != nullptr) {
      p->value += p->right->value;
    }
  }

  void build(node *p, int l, int r) {
    if (l > r) {
      return;
    }
    p->l = l, p->r = r;
    if (l == r) {
      p->value = 0;
      return;
    }
    int mid = l + ((r - l) >> 1);
    build(p->left = new node, l, mid);
    build(p->right = new node, mid + 1, r);
    update(p);
  }

  void add(node *p, int l, int r, int k) {
    if (l > p->r || p->l > r) {
      return;
    }
    pushdown(p);
    if (l <= p->l && p->r <= r) {
      p->lazy += k;
      p->value += (p->r - p->l + 1) * k;
      return;
    }
    add(p->left, l, r, k);
    add(p->right, l, r, k);
    update(p);
  }

  int find(node *p) {
    pushdown(p);
    if (p->l == p->r) {
      return p->value != 0 ? p->l : 0;
    }
    if (p->right->value != 0) {
      return find(p->right);
    }
    return find(p->left);
  }

  int get(node *p, int l, int r) {
    if (l > p->r || p->l > r) {
      return 0;
    }
    pushdown(p);
    if (l <= p->l && p->r <= r) {
      return p->value;
    }
    return get(p->left, l, r) + get(p->right, l, r);
  }

public:
  void build() {
    root = new node;
    build(root, 1, tot);
  }


  int get(int l, int r) {
    return get(root, l, r);
  }

  int find() {
    return find(root);
  }

  void add(int l, int r, int k) {
    add(root, l, r, k);
  }
}tree;

struct Line {
  int x, y1, y2, mark;
  bool operator<(const Line& cmp) const {
    return x < cmp.x;
  }
};

struct node {
  int x, y;
};

vector<Line> line;
vector<int> temp_h;
vector<node> ans;
int ok_h[MAXN];
unordered_map<int, int> ID;


void init() {
}

void input() {
  int l, r, h;
  while (cin >> l >> h >> r) {
    h++;
    temp_h.push_back(h);
    line.push_back({l, 1, h, 1});
    line.push_back({r, 1, h, -1});
  }
}

void work() {
  sort(line.begin(), line.end());
  sort(temp_h.begin(), temp_h.end());
  tot = 0;
  for (auto &i : temp_h) {
    if (ID.count(i) == 0) {
      ID[i] = ++tot;
      ok_h[tot] = i;
    }
  }
  tree.build();
  ans.push_back({line.begin()->x, line.begin()->y2});
  for (int i = 0; i < line.size();) {
    int j;
    for (j = i; j < line.size() && line[j].x == line[i].x; j++) {
      tree.add(ID[line[j].y1], ID[line[j].y2], line[j].mark);
    }
    int top = tree.find();
    if (top != ID[ans.back().y]) {
      ans.push_back({line[i].x, ok_h[top]});
    }
    i = j;
  }
}
/*
  tree.build();
  ans.push_back({line.begin()->x, line.begin()->y2});
  for (int i = 0; i < line.size();) {
    int j;
    for (j = i; j < line.size() && line[j].x == line[i].x; j++) {
      cout << j << " ";
      tree.add(line[j].y1, line[j].y2, line[j].mark);
    }
    int top = tree.find();
    cout << top << " " << endl;
    if (top != ID[ans.back().y]) {
      ans.push_back({line[i].x, ok_h[top]});
    }
    i = j;
  }
 */

void output() {
  for (auto &i : ans) {
    cout << i.x << " " << (i.y == 0 ? 0 : i.y - 1) << " ";
  }
}

int main() {
  init();
  input();
  work();
  output();
  return 0;
}
