#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6;

int t;
int n;
int a[MAXN];
long long Sum[MAXN];

void solve() {
  bool flag = true;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i != 1 && a[i] != a[i - 1]) flag = false;
    Sum[i] = Sum[i - 1] + a[i];
  }
  if(flag) {
    cout << 0 << endl;
    return;
  }
  long long M = n - 1;
  for (int k = 1; k <= n; k++) {
    if (Sum[k] >= Sum[n] - Sum[k - 1]) break;
    if (Sum[k] == 0) {
      if (Sum[n] == 0) {
        M = 0;
        break;
      }
      continue;
    }
    if (Sum[n] % Sum[k] != 0) continue;
    long long ans = k - 1;
    long long back = Sum[k];
    for (int i = k + 1; i <= n; i++) {
      if (a[i] != back) {
        int j;
        for (j = i + 1; j <= n && Sum[j] - Sum[i - 1] <= back; j++);
        j--;
        int t = Sum[j] - Sum[i - 1];
        ans += j - i;
        if (t == back) {
          i = j;
        } else {
          ans = LLONG_MAX;
          break;
        }
      }
    }
    M = min(M, ans);
  }
  cout << M << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
