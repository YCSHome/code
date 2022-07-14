#include <bits/stdc++.h>
using namespace std;
int a[1000], ans[1000][1000], n, m;
int main()
{
  cin >> n >> m;

  for (int i = 1;i <= n;i++) cin >> a[i];

  for (int i = 0;i <= n;i++) ans[i][0] = 1;
  for (int i = 1;i <= n;i++)
    for (int j = 1;j <= m;j++)
      for (int k = j;k >= j - a[i] && k >= 0;k--)
      {
        ans[i][j] += ans[i - 1][k] % 1000007, ans[i][j] %= 1000007;
      }
  cout << ans[n][m];
}
