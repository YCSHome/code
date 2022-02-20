#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct edge {
  int v, next;
}e[MAXN];

int tot = 0;
int head[MAXN];

void add(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

int n, m, k;

int main() {
  cin >> n >> m >> k;
  return 0;
}
