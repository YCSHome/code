#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct node {
  int v, next;
}e[MAXN];

int tot;
int head[MAXN];

void add(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

int main() {
  return 0;
}
