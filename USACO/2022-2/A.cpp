#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6;

int t;
int n;
int a[MAXN];
long long Sum[MAXN];

void solve() {
  bool flag = true;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
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
    long long ans = 0;
    long long back = 0;
    int size = 1;
    ans = k - 1;
    back = Sum[k];
    for (int i = k + 1; i <= n; i++) {
      if (a[i] == back) {
        size++;
      } else {
        int j;
        long long s = back;
        for (j = i + 1; j <= n && Sum[j] - Sum[i - 1] <= s; j++);
        j--;
        int t = Sum[j] - Sum[i - 1];
        ans += j - i;
        if (t == s) {
          size++;
          i = j;
        } else {
          ans = LLONG_MAX;
          break;
        }
      }
    }
    M = min(M, ans);
  }
  printf("%lld\n", M);
}

int main() {
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
