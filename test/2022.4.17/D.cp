#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 3000;

vector<int> go[kMaxN];
vector<pair<int, int>> e;

int dfn[kMaxN], low[kMaxN], tot;
int head[kMaxN];
vector<int> Stack;
bool inStack[kMaxN];
int cnt = 0;
int father[kMaxN];
int in[kMaxN];
int cc[kMaxN];
bitset<kMaxN> able[kMaxN];

void tarjan(int x) {
  dfn[x] = low[x] = ++tot;
  Stack.push_back(x);
  inStack[x] = true;
  for (int i : go[x]) {
    if (!dfn[i]) {
      tarjan(i);
      low[x] = min(low[x], low[i]);
    } else if (inStack[i]) {
      low[x] = min(low[x], dfn[i]);
    }
  }
  if (low[x] == dfn[x]) {
    cnt++;
    int t;
    do {
      t = Stack.back();
      Stack.pop_back();
      inStack[t] = false;
      father[t] = cnt;
      cc[cnt]++;
    } while (t != x);
    able[x][x] = true;
  }
}

int n, m;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < n; j++) {
      if (str[j] == '1') {
        e.push_back(make_pair(i, j + 1));
        go[i].push_back(j + 1);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  for (int i = 1; i <= n; i++) go[i].clear();
  for (auto i : e) {
    if (father[i.first] != father[i.second]) {
      go[i.second].push_back(i.first);
      in[i.first]++;
    }
  }
  queue<int> q;
  for (int i = 1; i <= cnt; i++) if (in[i] == 0) q.push(i);
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    for (int i : go[f]) {
      in[i]--;
      able[i] |= able[f];
      if (in[i] == 0) q.push(i);
    }
  }
  int ans = 0;
  for (int i = 1; i <= cnt; i++) {
    for (int j = 1; j <= cnt; j++) {
      if (able[i][j]) ans += cc[i] * cc[j];
    }
  }
  cout << ans << endl;
  return 0;
}
