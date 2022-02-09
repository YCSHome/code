#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n, m, k;
int cnt = 0;
int ans = 0;
int sum[MAXN];
int x[MAXN];

struct rec {
  int top, down, left, right;
  bool found = false;
  bool unable = false;
  rec() {
    top = left = INT_MAX;
    down = right = INT_MIN;
  }
}a[MAXN];

// 你个瘪三竟然只给n*m的取值范围
int pos(int x, int y) {
  return x * m + y;
}

int main() {
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int t;
      scanf("%d", &t);
      if (a[t].found == false) {
        a[t].found = true;
        cnt++;
      }
      a[t].top = min(a[t].top, i);
      a[t].down = max(a[t].down, i);
      a[t].left = min(a[t].left, j);
      a[t].right = max(a[t].right, j);
      x[pos(i, j)] = t;
    }
  }
  if (cnt == 1) {
    if (k == 1) {
      printf("1");
    } else {
      printf("%d", k - 1);
    }
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    if (a[i].found == false) {
      continue;
    }
    sum[pos(a[i].top, a[i].left)]++;
    sum[pos(a[i].down + 1, a[i].left)]--;
    sum[pos(a[i].top, a[i].right + 1)]--;
    sum[pos(a[i].down + 1, a[i].right + 1)]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[pos(i, j)] = sum[pos(i, j)] + sum[pos(i - 1, j)] + sum[pos(i, j - 1)] - sum[pos(i - 1, j - 1)];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (sum[pos(i, j)] > 1) {
        if (a[x[pos(i, j)]].found == false) continue;
        a[x[pos(i, j)]].unable = true;
      }
    }
  }
  int tot = 0;
  for (int i = 1; i <= k; i++) {
    tot += a[i].unable == false;
  }
  cout << tot << endl;
  return 0;
}