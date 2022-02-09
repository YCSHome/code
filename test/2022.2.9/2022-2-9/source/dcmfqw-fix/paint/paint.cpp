#include <bits/stdc++.h>
using namespace std;
#define rep(i, d, u) for (int i = d; i <= u; ++i)
#define dep(i, u, d) for (int i = u; i >= d; --i)
#define cep(n) while (n--)
#define gep(i, a) for (int i = firs[a]; i; i = neig[i])
int ured() {
  int ch, re = 0;
  do {
    ch = getchar();
  } while ('9' < ch || ch < '0');
  do {
    re = re * 10 + (ch ^ '0');
  } while ('0' <= (ch = getchar()) && ch <= '9');
  return re;
}
void uwit(int da) {
  int ch[21], cn = 0;
  do {
    ch[++cn] = da - da / 10 * 10;
  } while (da /= 10);
  do {
    putchar('0' ^ ch[cn]);
  } while (--cn);
}
const int _maxn = 100011;
int n, m, s, xmin[_maxn], xmax[_maxn], ymin[_maxn], ymax[_maxn], rans;
vector<vector<int>> a, lazy;
bool appr[_maxn], dans[_maxn];
int main() {
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  n = ured();
  m = ured();
  s = ured();
  rep(i, 1, s) {
    xmin[i] = n;
    ymin[i] = m;
    xmax[i] = ymax[i] = -1;
  }
  a.resize(n);
  lazy.resize(n);
  rep(i, 0, n - 1) {
    a[i].resize(m);
    lazy[i].resize(m);
    rep(j, 0, m - 1) {
      a[i][j] = ured();
      if (a[i][j]) {
        if (xmin[a[i][j]] > i) {
          xmin[a[i][j]] = i;
        }
        if (xmax[a[i][j]] < i) {
          xmax[a[i][j]] = i;
        }
        if (ymin[a[i][j]] > j) {
          ymin[a[i][j]] = j;
        }
        if (ymax[a[i][j]] < j) {
          ymax[a[i][j]] = j;
        }
        appr[a[i][j]] = 1;
      }
    }
  }
  if (n * m == 1) {
    if (a[0][0]) {
      uwit(s - 1);
    } else {
      uwit(s);
    }
    return 0;
  }
  rep(i, 1, s) {
    if (appr[i]) {
      ++lazy[xmin[i]][ymin[i]];
      if (xmax[i] + 1 < n) {
        --lazy[xmax[i] + 1][ymin[i]];
      }
      if (ymax[i] + 1 < m) {
        --lazy[xmin[i]][ymax[i] + 1];
      }
      if (xmax[i] + 1 < n && ymax[i] + 1 < m) {
        ++lazy[xmax[i] + 1][ymax[i] + 1];
      }
    }
  }
  rep(i, 0, n - 1) {
    rep(j, 0, m - 1) {
      if (i) {
        lazy[i][j] += lazy[i - 1][j];
      }
      if (j) {
        lazy[i][j] += lazy[i][j - 1];
      }
      if (i && j) {
        lazy[i][j] -= lazy[i - 1][j - 1];
      }
      if (a[i][j] && lazy[i][j] > 1) {
        dans[a[i][j]] = 1;
      }
    }
  }
  rep(i, 1, s) { rans += !dans[i]; }
  uwit(rans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}