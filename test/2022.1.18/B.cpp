#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int n;
int ans = 0;
char ch[MAXN];

void dfs(int c, int now, int sum) {
  if (c > n) {
    ans += (now == 0);
    return;
  }
  ch[c] = '-';
  dfs(c + 1, now, sum);
  ch[c] = '+';
  dfs(c + 1, now, sum );
  ch[c] = ' ';
  dfs(c + 1, now * 10 + c, sum);
}

int main() {
  int n;
  cin >> n;
  dfs(2, 1, 0);
  cout << ans;
  return 0;
}
