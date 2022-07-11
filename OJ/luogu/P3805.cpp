#include <iostream>
#include <list>

using namespace std;

const int kMaxN = 1e6;

struct node {
  int ID;
  node * prev, * next;
}a[kMaxN];

int n;

void add_right(node * left, node * right) {
  right->next = left->next;
  if (left->next) {
    left->next->prev = right;
  }
  left->next = right;
  right->prev = left;
}

void add_left(node * left, node * right) {
  left->prev = right->prev;
  if (right->prev) {
    right->prev->next = left;
  }
  right->prev = left;
  left->next = right;
}

void Delete(node * p) {
  if (p->prev) {
    p->prev->next = p->next;
  }
  if (p->next) {
    p->next->prev = p->prev;
  }
  p->prev = p->next = nullptr;
}

void print() {
  node * p = a->next;
  while (p) {
    cout << p->ID << " ";
    p = p->next;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i <= n; i++) { a[i].ID = i; }
  add_right(a, a + 1);
  for (int i = 2; i <= n; i++) {
    int t, opt;
    cin >> t >> opt;
    if (opt == 0) {
      add_left(a + i, a + t);
    } else {
      add_right(a + t, a + i);
    }
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int t;
    cin >> t;
    Delete(a + t);
  }
  print();
  return 0;
}
