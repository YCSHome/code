#include <iostream>
#include <random>

using namespace std;

int main() {
  freopen("input", "w", stdout);
  mt19937_64 e(clock());
  uniform_int_distribution<int> rand(-1000, 1000);
  cout << 1000000 << endl;
  for (int i = 1; i <= 1000000; i++) {
    cout << rand(e) << " ";
  }
  return 0;
}
