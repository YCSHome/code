#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct node {
  int x, y;
}a[MAXN];

int x, y, cnt = 0;
bool vis[MAXN];
queue<int> q;

void Record(int u, int v) {
  if (vis[v] || u == v || !((a[u].x > a[v].x && a[u].x < a[v].y) || (a[u].y > a[v].x && a[u].y < a[v].y))) {
    return;
  }
  vis[v] = true;
  q.push(v);
}

bool bfs() {
  memset(vis, false, sizeof(vis));
  vis[x] = true;
  q.push(x);
  while (!q.empty()) {
    // 不同作用域内变量名不同没事
    int u = q.front();
    if (u == y) {
      return true;
    }
    for (int i = 1; i <= cnt; i++) {
      Record(u, i);
    }
    q.pop();
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int opt;
    cin >> opt >> x >> y;
    if (opt == 1) {
      a[++cnt] = {x, y};
    } else {
      cout << (bfs() ? "YES" : "NO") << endl;
    }
  }
  return 0;
}
