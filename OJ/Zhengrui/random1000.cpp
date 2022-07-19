#include <iostream>
#include <random>

using namespace std;

int main() {
  freopen("input", "w", stdout);
  mt19937 e(clock());
  uniform_int_distribution<long long> rand(1, 1e16);
  long long L = rand(e);
  uniform_int_distribution<long long> randB(L, 1e16);
  long long R = randB(e);
  cout << L << " " << R << endl;
  return 0;
}
