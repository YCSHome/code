#include <iostream>
#include <random>
#define int long long

using namespace std;

int to_int(string str) {
  int w = 0;
  for (int i = 0; i < str.size(); i++) {
    w = w * 10 + str[i] - '0';
  }
  return w;
}

signed main(signed argc, char ** argv) {
  mt19937_64 e(clock());
  int subtask = to_int(argv[1]);
  int n, s1, s2, MaxV, MinW = 1, MaxW;
  if (subtask <= 3) {
    uniform_int_distribution<long long> rand(3, 5);
    n = rand(e);
    MaxV = 5;
    MinW = 1;
    MaxW = 10;
  } else if (subtask <= 6) {
    uniform_int_distribution<long long> rand(20, 70);
    n = rand(e);
    MaxV = 200;
    MinW = 1;
    MaxW = 10000;
  } else if (subtask <= 12) {
    uniform_int_distribution<long long> rand(50, 100);
    n = rand(e);
    MaxV = 200;
    MinW = 50000;
    MaxW = 100000;
  } else if (subtask <= 20) {
    n = 400;
    MaxV = 500;
    MinW = 1e5;
    MaxW = 1e15;
  }
  uniform_int_distribution<long long> Vrand(1, MaxV), Wrand(1, MaxW);
  s1 = Vrand(e), s2 = Vrand(e);
  cout << n << " " << s1 << " " << s2 << " " << endl;
  for (int i = 1; i <= n; i++) {
    cout << Vrand(e) << " " << Wrand(e) << endl;
  }
  for (int i = 1; i <= n; i++) {
    cout << Vrand(e) << " " << Wrand(e) << endl;
  }
  return 0;
}
