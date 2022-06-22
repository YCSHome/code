#include <bits/stdc++.h>

using namespace std;

namespace IO {
  template <class type = long long>
  type read() {
    type w = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')   { f = ch == '-' ? -1 : 1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { w = w * 10 + ch - '0'; ch = getchar(); }
    return w * f;
  }
};

const int kMaxN = 1e6;

int n;
int dis[kMaxN];
int father[kMaxN];
int ans = INT_MAX;

int find(int k) {
  if (father[k] != k) {
    int last = father[k];
    father[k] = find(father[k]);
    dis[k] += dis[last];
  }
  return father[k];
}

void Union(int a, int b) {
  int x = find(a), y = find(b);
  if (x != y) {
    father[x] = y;
    dis[a] = dis[b] + 1;
  } else {
    ans = min(ans, dis[a] + dis[b] + 1);
  }
}

int main() {
  using namespace IO;
  for (int i = 1; i < kMaxN; i++) father[i] = i;
  bool flag = true;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    Union(i, read());
  }
  cout << ans << endl;
  return 0;
}
