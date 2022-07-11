#include <iostream>

using namespace std;

const int kMaxN = 3e6;

int n, m;
int a[kMaxN];
int b[kMaxN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    cout << a[b[i]] << endl;
  }
  return 0;
}
