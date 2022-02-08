#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct shop {
  long long p, q;
  bool operator<(const shop& cmp) const {
    if (p == cmp.p) return q > cmp.q;
    return p > cmp.p;
  }
} s[MAXN];

long long n, m, R;
long long c[MAXN], r[MAXN];
long long SSum[MAXN];
long long MSum[MAXN];
long long ans = 0;

int main() {
  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);
  cin >> n >> m >> R;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> s[i].q >> s[i].p;
  }
  for (int i = 1; i <= R; i++) {
    cin >> r[i];
  }
  sort(s + 1, s + 1 + m);
  sort(c + 1, c + 1 + n, [](long long a, long long b) { return a > b; });
  sort(r + 1, r + 1 + R, [](long long a, long long b) { return a > b; });
  // 把第i个商店榨干后可以赚到的钱与消耗的奶
  for (int i = 1; i <= max(n, m) + 1; i++) {
    SSum[i] += SSum[i - 1] + s[i].p * s[i].q;
    MSum[i] += MSum[i - 1] + s[i].q;
  }
  // 把第i个农场主榨干后可以赚到的钱
  for (int i = 1; i <= max(R, n); i++) {
    r[i] += r[i - 1];
  }
  // 把第i头奶牛榨干后可以挤到的奶
  for (int i = 1; i <= n; i++) {
    c[i] += c[i - 1];
  }
  // 假设有i头奶牛要拿去挤奶，那么只有n-i头奶牛会被拿过去卖
  for (int i = 1, j = 1; i <= n; i++) {
    long long SellMoney = r[n - i];  // 卖掉的钱
    long long milk = c[i];           // 挤到的奶
    for (; milk >= MSum[j] && j <= m + 1; j++)
      ;
    long long now = c[i] - MSum[j - 1];                 // 剩下的奶
    long long MilkeMoney = now * s[j].p + SSum[j - 1];  // 卖牛奶得到的钱
    ans = max(ans, SellMoney + MilkeMoney);
  }
  cout << ans;
  return 0;
}
