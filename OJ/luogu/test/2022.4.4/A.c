#include <stdio.h>
#define kMaxN 100001

int n, m, k;
int s[kMaxN];
int head[kMaxN];
int in[kMaxN];
int dis[kMaxN];
int v[kMaxN];
int nxt[kMaxN];
int dd[kMaxN];
int tot = 0;

void dfs(int u, int d) {
  if (d > dis[u]) dis[u] = d;
  else return;
  if (dis[u] < s[u]) dis[u] = s[u];
  for (int i = head[u]; i; i = nxt[i]) {
    dfs(v[i], dis[u] + dd[i]);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", s + i);
  }
  for (int i = 1; i <= k; i++) {
    int u, v_, dis;
    scanf("%d%d%d", &u, &v_, &dis);
    in[v_]++;
    tot++;
    v[tot] = v_;
    dd[tot] = dis;
    nxt[tot] = head[u];
    head[u] = tot;
  }
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) {
      dfs(i, s[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d\n", dis[i]);
  }
  return 0;
}
