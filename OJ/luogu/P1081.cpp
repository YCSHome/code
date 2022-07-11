#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n, m;
int x0, x1;
int h[kMaxN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  cin >> x0 >> m >> x1;
  return 0;
}
