#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 114514;

int n, m, p;
int father[MAXN];
int value[MAXN];

void init() {
  for (int i = 0; i < MAXN; i++) {
    father[i] = i;
  }
}

int find(int x) {
  if (x != father[x]) {
    value[x] += value[father[x]];
    father[x] = find(father[x]);
  }
  return father[x];
}

int main() {
  freopen("seq.in", "r", stdin);
  freopen("seq.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &p);
  init();
  for (int i = 1; i <= m; i++) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    int f1 = find(l - 1);
	  int f2 = find(r); 
    if (f1 != f2) {
      father[f1] = f2;
      value[f1] = k + value[r] - value[l - 1];
    } else {
      if ((value[l - 1] - value[r] + p) % p != k) {
        printf("%d", i - 1);
        return 0;
      }
    }
  }
  printf("%d", m);
  return 0;
}