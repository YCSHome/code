#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct Edge {
  int v, dis, next;
} e[MAXN];

int dis[MAXN];
int head[MAXN];
int tot = 0;

void add(int u, int v, int d) {
  e[++tot] = {v, d, head[u]};
  head[u] = tot;
}

void init() {
  memset(dis, 0x3f, sizeof(dis));
  memset(head, 0, sizeof(head));
}

int V, E, need;

void work() {}

int main() {
  cin >> V >> E >> need;
  return 0;
}
