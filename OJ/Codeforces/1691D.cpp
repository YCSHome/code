#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int kMaxN = 2e5 + 1145;
const int MAXN = kMaxN;

int n;
int a[kMaxN], b[kMaxN];
int pos[kMaxN];
int LOG[kMaxN];
int L[kMaxN], R[kMaxN];
long long s[kMaxN];
long long Max[30][kMaxN];
long long Min[30][kMaxN];

void init(int n) {
  for (int i = 1; i <= LOG[n]; i++) {
    for (int j = 1; j <= n - (1 << i) + 1; j++) {
      Max[i][j] = max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
      Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
    }
  }
}

long long getMax(int l, int r) {
  int k = LOG[r - l + 1];
  return max(Max[k][l], Max[k][r - (1 << k) + 1]);
}

long long getMin(int l, int r) {
  int k = LOG[r - l + 1];
  return min(Min[k][l], Min[k][r - (1 << k) + 1]);
}

int t;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    L[i] = i - 1, R[i] = i + 1;
    pos[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    Min[0][i] = s[i - 1];
    Max[0][i] = s[i];
  }
  init(n);
  sort(pos + 1, pos + 1 + n, [&](int x, int y) { return a[x] < a[y]; } );
  for (int i = 1; i <= n; i++) {
    int u = pos[i];
    R[L[u]] = R[u];
    L[R[u]] = L[u];
    if (a[u] < getMax(u, R[u] - 1) - getMin(L[u] + 1, u)) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

signed main() {
  cin >> t;
  LOG[1] = 0;
  LOG[2] = 1;
  for (int i = 3; i < kMaxN; i++) {
    LOG[i] = LOG[i / 2] + 1;
  }
  while (t--) solve();
  return 0;
}
