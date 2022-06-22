#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 1e6;

int d[MAXN];

struct cmp {
  bool operator () (int a, int b) const {
    return d[a] < d[b] || (d[a] == d[b] && a < b);
  }
};

int n, m;

vector<pair<int, int>> to[MAXN];
set<int, cmp> s;
int f[MAXN];
bool vis[MAXN];
int k[3000][3000];

void add(int u, int v, int w) {
  to[u].push_back(make_pair(v, w));
}

void Record(int u, int v, int d_) {
  if (d_ >= d[v]) {
    if (d_ == d[v]) {
      f[v] += f[u];
    }
    return ;
  }
  s.erase(v);
  d[v] = d_;
  f[v] = f[u];
  s.insert(v);
}

void dijkstra() {
  memset(d, 0x3f, sizeof(d));
  f[1] = 1, d[1] = 0;
  s.insert(1);
  while (!s.empty()) {
    int u = *s.begin();
    s.erase(s.begin());
    if (vis[u]) continue;
    vis[u] = true;
    for (auto i : to[u]) {
      Record(u, i.first, d[u] + i.second);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (k[u][v] == w) continue;
    k[u][v] = w;
    add(u, v, w);
  }
  dijkstra();
  if (f[n] == 0) {
    cout << "No answer" << endl;
    return 0;
  }
  cout << d[n] << " " << f[n] << endl;
  return 0;
}

