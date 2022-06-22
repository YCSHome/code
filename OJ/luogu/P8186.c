#include <stdio.h>
#define kMaxN 500

int n;
int root;
int able[kMaxN][kMaxN];
int a[kMaxN][kMaxN];

int tot = 0;
int nxt[kMaxN];
int v[kMaxN];
int head[kMaxN];

void add_edge(int u, int v_) {
  nxt[++tot] = head[u];
  v[tot] = v_;
  head[u] = tot;
}

void dfs(int u) {
  if (able[root][u]) return;
  able[root][u] = 1;
  for (int i = head[u]; i; i = nxt[i]) {
    dfs(v[i]);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int flag = 1;
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      if (flag == 0) continue;
      nxt[++tot] = head[i];
      v[tot] = a[i][j];
      head[i] = tot;
      flag &= a[i][j] != i;
    }
  }
  for (int i = 1; i <= n; i++) {
    root = i;
    dfs(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (able[a[i][j]][i]) {
        printf("%d\n", a[i][j]);
        break;
      }
    }
  }
  return 0;
}
