#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

struct node {
  int l, r;
}a[MAXN];

int n;
int cnt;
int b[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r;
    b[++cnt] = a[i].l;
    b[++cnt] = a[i].r;
  }
  sort(b + 1, b + 1 + cnt);
  return 0;
}
