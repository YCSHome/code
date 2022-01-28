#include <iostream>
#include <random>
#include <ctime>

using namespace std;

mt19937 random_engine(time(NULL));
uniform_int_distribution<int> WRand(1000, 10000);

int n, m, s, e;

int main() {
  n = 10000;
  uniform_int_distribution<int> MaxNRand(1, n);
  uniform_int_distribution<int> MaxMRand(n - 1, min((n - 1) * n, 20000));
  m = MaxMRand(random_engine);
  s = MaxNRand(random_engine);
  do { e = MaxNRand(random_engine); } while (e == s);
  cout << n << " " << m << " " << s << " " << e << endl;
  for (int i = 1; i <= m; i++) {
    int u, v, w = WRand(random_engine);
    do {
      u = MaxNRand(random_engine);
      v = MaxNRand(random_engine);
    } while (u == v);
    cout << u << " " << v << " " << w << endl;
  }
  return 0;
}
