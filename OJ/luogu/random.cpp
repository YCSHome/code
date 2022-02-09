#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("/home/liuyi/.input", "w", stdout);
  srand(time(0));
  int n = 100;
  cout << n << endl;
  for (int i = 1; i <= n; i++) {
    int h = rand() % 100 + 1, x, y;
    do {
      x = rand() % 20 + 1, y = rand() % 20 + 1;
    } while (x == y);
    if (x > y) swap(x, y);
    cout << h << " " << x << " " << y << endl;
  }
  return 0;
}
