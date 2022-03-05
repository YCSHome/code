#include <bits/stdc++.h>

#define int long long

using namespace std;

const int kMaxn = 1e2 + 10;

int * Count(int n) {
  static int NumberLen;
  static int NumberTop[kMaxn];
  static int cnt[kMaxn];
  int * ans = new int[20];
  NumberLen = 0;
  memset(ans, 0, 20 * sizeof(int));
  memset(cnt, 0, sizeof(cnt));
  while (n) {
    NumberTop[++NumberLen] = n % 10;
    n /= 10;
  }
  reverse(NumberTop + 1, NumberLen + NumberTop + 1);
  int Sum = 0;
  for (int i = 1; i <= NumberLen; i++) {
    for (int now = 0; now < 10; now++) {
      ans[now] = ans[now] * 10 + Sum - 1;
      ans[now] += NumberTop[i] * cnt[now] + (now < NumberTop[i]);
      ans[now] += now > 0;
    }
    cnt[NumberTop[i]]++;
    Sum = Sum * 10 + NumberTop[i];
  }
  return ans;
}

signed main() {
  int l, r;
  cin >> l >> r;
  int * a1 = Count(l);
  int * a2 = Count(r + 1);
  for (int i = 0; i < 10; i++) {
    cout << a2[i] - a1[i] << " ";
  }
  return 0;
}
