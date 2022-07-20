#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

vector<int> go[kMaxN];
vector<int> up[kMaxN];
vector<int> down[kMaxN];

int n, q;
unsigned int s;
int top[kMaxN];
int len[kMaxN];
int father[kMaxN][30];
int depth[kMaxN];
int son[kMaxN];
int Log[kMaxN];

void dfs1(int u) {
  depth[u] = depth[father[u][0]] + 1;
  len[u] = depth[father[u][0]] + 1;
  for (int i : go[u]) {
    father[i][0] = u;
    for (int j = 1; j < 30; j++) { father[i][j] = father[father[i][j - 1]][j - 1]; }
    dfs1(i);
    len[u] = max(len[u], len[i]);
    if (len[i] > len[son[u]]) {
      son[u] = i;
    }
  }
}

void dfs2(int u, int top) {
  ::top[u] = top;
  if (u == top) {
    for (int i = 0, j = u; i <= len[u] - depth[u]; i++) {
      up[u].push_back(j);
      j = father[j][0];
    }
    for (int i = 0, j = u; i <= len[u] - depth[u]; i++) {
      down[u].push_back(j);
      j = son[j];
    }
  }
  if (son[u]) {
    dfs2(son[u], top);
  }
  for (int i : go[u]) {
    if (i != son[u]) {
      dfs2(i, i);
    }
  }
}

int ask(int x, int k) {
  if (!k) return x;
  x = father[x][(int)Log[k]];
  k -= 1 << (int)log2(k);
  k -= depth[x] - depth[top[x]];
  x = top[x];
  return k >= 0 ? up[x][k] : down[x][-k];
}

inline unsigned int get() {
	s ^= s << 13;
	s ^= s >> 17;
	s ^= s << 5;
	return s; 
}

int main() {
  cin >> n >> q >> s;
  Log[0] = -1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    go[x].push_back(i);
    Log[i] = Log[i >> 1] + 1;
  }
  int root = go[0][0];
  dfs1(root);
  dfs2(root, root);
  long long lastAns = 0;
  long long ans = 0;
  for (int i = 1; i <= q; i++) {
    int x = (get() ^ lastAns) % n + 1;
    int k = (get() ^ lastAns) % depth[x];
    lastAns = ask(x, k);
    ans ^= i * lastAns;
  }
  cout << ans << endl;
  return 0;
}
