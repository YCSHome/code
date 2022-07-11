#include <iostream>

using namespace std;

const int kMaxN = 4e6;
const int P = 1e6;

int n, m;
int a[kMaxN], b[kMaxN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int v, x;
    cin >> v >> x;
    a[x - 3 * v + 1 + P]++;
    a[x - 2 * v + 1 + P] -= 2;
    a[x + 1 + P] += 2;
    a[x + 2 * v + 1 + P] -= 2;
    a[x + 3 * v + 1 + P]++;
  }
  for (int i = 1; i <= m + P; i++) {
    a[i] += a[i - 1];
    b[i] += b[i - 1] + a[i];
  }
  for (int i = P + 1; i <= m + P; i++) {
    cout << b[i] << " ";
  }
  return 0;
}
