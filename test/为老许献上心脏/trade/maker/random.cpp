#include <iostream>
#include <random>
#define int long long

using namespace std;

signed main(signed argc, char ** argv) {
  int n, s1, s2, MaxV, MaxW, MinW = 1;
  mt19937_64 e(clock());
  cin >> n >> s1 >> s2;
  cin >> MaxV >> MaxW;
  if (n == 400) MinW = 1e9;
  uniform_int_distribution<long long> Vrand(1, MaxV), Wrand(MinW, MaxW);
  cout << n << " " << s1 << " " << s2 << " " << endl;
  for (int i = 1; i <= n; i++) {
    cout << Vrand(e) << " " << Wrand(e) << endl;
  }
  for (int i = 1; i <= n; i++) {
    cout << Vrand(e) << " " << Wrand(e) << endl;
  }
  return 0;
}
