#include <iostream>
#include <random>

using namespace std;

int main() {
  freopen("input", "w", stdout);
  mt19937_64 e(clock());
  uniform_int_distribution<int> rand(1, 3);
  for (int i = 1; i <= 1e6; i++) {
    cout << char(rand(e) + 'A' - 1);
  }
  return 0;
}
