#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n, m;
int c[kMaxN];
int p[kMaxN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  return 0;
}
