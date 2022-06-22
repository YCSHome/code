#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

int n = 1000, m = 1000;
int father[kMaxN];

int main() {
  freopen("/home/liuyi/.input", "w", stdout);
  srand(time(0));
  cout << n << " " << m << endl;
  for (int i = 1; i <= n; i++) {
    cout << rand() + 1 << " ";
  }
  for (int i = 2; i <= n; i++) {
    do {
      father[i] = rand() % n + 1;
    } while (father[i] >= i);
    cout << father[i] << " " << i << endl;
  }
  while (m--) {
    int opt = rand() % 2;
    if (opt == 0) {
      cout << 'Q' << " " << rand() % n + 1 << " " << rand() % n + 1 << endl;
    } else {
      cout << 'C' << " " << rand() % n + 1 << " " << rand() % n + 1 << " " << rand() << endl;
    }
  }
  return 0;
}
