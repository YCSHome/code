#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7;

int t;
int n, l, r, k;
int a[MAXN];

int main() { 
  cin >> t;
  while (t--) {
    int cnt = 0;
    cin >> n >> l >> r >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
      if (k < a[i]) {
        break;
      }
      if (a[i] >= l && a[i] <= r) {
        cnt++;
        k -= a[i];
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
