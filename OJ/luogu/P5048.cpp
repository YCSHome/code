#include <iostream>

using namespace std;

char ch;

inline int decode(int x, long long lastans) {
  return x ^ (lastans & 0x7fffffff);
}

int main() {
  int n;
  cin >> n >> ch;
  for (int i = 1; i <= n; i++) {
    char opt;
    int x, y, l, r;
    cin >> opt >> x >> y;
    if (opt == 'A') {
    } else {
      cin >> l >> r;
    }
  }
  return 0;
}
