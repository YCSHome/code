#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long ans = 0;
  for (int i = 1; i <= 1e9; i++) {
    ans += log2(i);
  }
  cout << ans << endl;
  return 0;
}

