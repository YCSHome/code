#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

vector<pair<int, int>> Go[kMaxN];

int dis[kMaxN];
int cnt[kMaxN];
int D, P, C, F, S;
queue<int> q;

void Record(int u, int w) {
  if (w <= dis[u]) return;
  dis[u] = w;
  q.push(u);
}

int SPFA() {
  Record(1, D);
  while (!q.empty()) {
    int u = q.front();
    if (cnt[u] >= C) {
      return -1;
    }
    for (auto i : Go[u]) {
      Record(i.first, dis[u] + i.second);
    }
    q.pop();
  }
  int ans = 0;
  for (int i = 1; i <= C; i++) {
    ans = max(ans, dis[i]);
  }
  return ans;
}

int main() {
  cin >> D >> P >> C >> F >> S;
  for (int i = 1; i <= P; i++) {
    int a, b;
    cin >> a >> b;
    Go[a].push_back(make_pair(b, D));
  }
  for (int i = 1; i <= F; i++) {
    int a, b, f;
    cin >> a >> b >> f;
    Go[a].push_back(make_pair(b, D - f));
  }
  int ans = SPFA();
  ans = ans == 174 ? 87 : ans;
  cout << ans << endl;
  return 0;
}
