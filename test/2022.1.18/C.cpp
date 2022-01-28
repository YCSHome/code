const int MAXN = 1e6;
bool vis[MAXN];
int a, b;
bool flag = false;
void dfs(int u) {
  if (u == b) {
    flag = true;
    return;
  }
  vis[u] = true;
  for (int i = 1; i <= cnt; i++) {
    if (vis[i]) continue;
    if ((a[u].x > a[i].x && a[u].x < a[i].y) ||
        (a[u].y > a[i].x && a[u].y < a[i].y)) {
      dfs(i);
    }
  }
}

int main() {
  ...
}
