#include <iostream>
#include <random>

using namespace std;

int main() {
  freopen("input", "w", stdout);
  mt19937_64 e;
  uniform_int_distribution<long long> rand(1e8, 1e9);
  cout << 500 << " ";
  cout << 500 << endl;
  for (int i = 1; i <= 500; i++) {
    for (int j = 1; j <= 500; j++) {
      if (clock() % 2) {
        cout << rand(e) << " ";
      } else {
        cout << -rand(e) << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
