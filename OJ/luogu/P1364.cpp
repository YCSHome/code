#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n, root;
int Left[kMaxN], Right[kMaxN];
int w[kMaxN];
int Sum[kMaxN];
int Size[kMaxN];
int dp[kMaxN];
int ans = 0x3f3f3f3f;
bool in[kMaxN];

int dfs(int x, int depth) {
  if (x == 0) return 0;
  Size[x] = w[x] + dfs(Left[x], depth + 1) + dfs(Right[x], depth + 1);
  dp[1] += depth * w[x];
  return Size[x];
}

void dfs2(int);

void to(int u, int x) {
  if (x == 0) return;
  dp[x] = dp[u] + Size[1] - Size[x] * 2;
  dfs2(x);
}

void dfs2(int x) {
  to(x, Right[x]);
  to(x, Left[x]);
  ans = min(ans, dp[x]);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> Left[i] >> Right[i];
    in[Left[i]] = in[Right[i]] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      root = i;
      break;
    }
  }
  dfs(root, 0);
  dfs2(root);
  cout << ans << endl;
  return 0;
}
