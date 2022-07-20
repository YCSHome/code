#include <bits/stdc++.h>
#include <random>

using namespace std;

const int kMaxN = 1e6;

int main() {
  mt19937 e;
  freopen("shit", "w", stdout);
  uniform_int_distribution<int> rand(1, 1e9);
  uniform_int_distribution<int> rand2(1, 2e4);
  cout << 20000 << " " << 20000 << endl;
  for (int i = 1; i <= 20000; i++) {
    cout << rand(e) << " ";
  }
  cout << endl;
  for (int i = 1; i <= 20000; i++) {
    int x = rand2(e), y = rand2(e);
    if (x > y) swap(x, y);
    cout << x << " " << y << endl;
  }
  return 0;
}
