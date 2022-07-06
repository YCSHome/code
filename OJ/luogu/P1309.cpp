#include <iostream>

using namespace std;

const int kMaxN = 1e6;

struct people {
  int s, w, ID;
  bool operator < (const people& cmp) const {
    if (s == cmp.s) return ID < cmp.ID;
    return s > cmp.s;
  };
} p[kMaxN];

void play(people& a, people& b) {
  if (a.w > b.w) {
    a.s++;
  } else {
    b.s++;
  }
}

int main() {
  int n, r, q;
  cin >> n >> r >> q;
  for (int i = 1; i <= 2 * n; i++) {
    p[i].ID = i;
    cin >> p[i].s;
  }
  for (int i = 1; i <= 2 * n; i++) {
    cin >> p[i].w;
  }
  sort(p + 1, p + 1 + 2 * n);
  while (r--) {
    for (int i = 1; i <= n; i++) {
      play(p[i * 2 - 1], p[i * 2]);
    }
    sort(p + 1, p + 1 + 2 * n);
  }
  cout << p[q].ID << endl;
  return 0;
}
