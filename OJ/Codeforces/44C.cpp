#include <iostream>

using namespace std;

const int MAXN = 1e6;

int n, m;
int a[MAXN];
int b[MAXN];

int main() {
  cin >> n >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    b[l]++, b[r + 1]--;
  }
  int k = 0;
  for (int i = 1; i <= n; i++) {
    k += b[i];
    if (k != 1) {
      cout << i << " " << k << endl;
      return 0;
    }
  }
  cout << "OK";
  return 0;
}
