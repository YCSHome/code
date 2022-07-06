#include <iostream>

using namespace std;

const int kMaxN = 1e6;

struct Build {
  int l, r;
}build[kMaxN];

int n;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> build[i].l >> build[i].r;
  }
  return 0;
}
