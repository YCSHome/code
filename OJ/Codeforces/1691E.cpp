#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <cstdio>

using namespace std;

const int kMaxN = 1e6;

struct _type {
  int type;
  int l, r;
  int ID;
  bool operator<(const _type& cmp) const {
    if (l == cmp.l) {
      return r < cmp.r;
    }
    return l < cmp.l;
  }
}line[kMaxN];

int t;
int father[kMaxN];
int top[2];
int queue[2][kMaxN];
bool vis[kMaxN];

int find(int x) {
  return x == father[x] ? x : x = find(father[x]);
}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int type, l, r;
    cin >> line[i].type >> line[i].l >> line[i].r;
    father[i] = i;
  }
  sort(line + 1, line + 1 + n);
  top[0] = top[1] = 0;
  for (int i = 1; i <= n; i++) {
    int type = line[i].type;
    int another = type ^ 1;
    int Max = -1, MaxP = -1;
    for (int j = 1; j <= top[another]; j++) {
      if (line[queue[another][j]].r >= line[i].l) {
        int x = queue[another][j];
        if (line[x].r > Max) {
          Max = line[x].r, MaxP = x;
        }
        father[find(x)] = find(i);
      }
    }
    if (Max != -1) {
      top[another] = 1;
      queue[another][1] = MaxP;
    } else {
      top[another] = 0;
    }

    queue[type][++top[type]] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += find(i) == i;
  }
  cout << ans << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
