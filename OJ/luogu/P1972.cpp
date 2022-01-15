#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int BlockSize;

struct que {
  int l, r, id;
  bool operator<(const que& b) const {
    if ((l / BlockSize) ^ (b.l / BlockSize)) {
      return l < b.l;
    } else {
      return ((l / BlockSize) & 1) ? r < b.r : r > b.r;
    }
  };
}b[MAXN];

int read() {
  int f = 1, w = 0;
  char ch = getchar();
  while ('0' > ch || ch > '9') {
    f = ch == '-' ? -1 : 1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    w = w * 10 + ch - '0';
    ch = getchar();
  }
  return f * w;
}

void write(int n) {
  if (n < 10) {
    putchar(n + '0');
    return;
  }
  write(n / 10);
  putchar(n % 10 + '0');
}

int a[MAXN];
int ans_[MAXN];
int ans = 0;
int cnt[MAXN];
int n, m;

void del(int x) {
  cnt[a[x]]--;
  if (cnt[a[x]] == 0) ans--;
}

void add(int x) {
  if (cnt[a[x]] == 0) ans++;
  cnt[a[x]]++;
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
  }
  m = read();
  for (int i = 1; i <= m; i++) {
    b[i].l = read();
    b[i].r = read();
    b[i].id = i;
  }
  BlockSize = n / sqrt(m * 2 / 3);
  sort(b + 1, b + 1 + m);
  int l = 0, r = 0;
  for (int i = 1; i <= m; i++) {
    int ql = b[i].l, qr = b[i].r;
    while (l < ql) del(l++);
    while (l > ql) add(--l);
    while (r < qr) add(++r);
    while (r > qr) del(r--);
    ans_[b[i].id] = ans;
  }
  for (int i = 1; i <= m; i++) {
    write(ans_[i]);
    putchar('\n');
  }
  return 0;
}
