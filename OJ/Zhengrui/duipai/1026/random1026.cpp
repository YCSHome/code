#include <iostream>
#include <random>
#define int long long

using namespace std;

signed main() {
  freopen("input", "w", stdout);
  mt19937_64 e(clock());
  uniform_int_distribution<long long> rand(1e8, 1e9);
  cout << 500 << " ";
  cout << 500 << endl;
  int Map[501][501];
  long long ans = 0;
  for (int i = 1; i <= 500; i++) {
    for (int j = 1; j <= 500; j++) {
      if (clock() % 2) {
        Map[i][j] = rand(e);
      } else {
        Map[i][j] = -rand(e);
      }
      if ((i + j) % 2) {
        ans += Map[i][j];
      } else {
        ans -= Map[i][j];
      }
    }
  }
  if (rand(e) % 2) {
    Map[500][500] += ans;
  }
  for (int i = 1; i <= 500; i++) {
    for (int j = 1; j <= 500; j++) {
      cout << Map[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
