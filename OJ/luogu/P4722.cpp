#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int kMaxN = 1e6;
const int INF = 0x3f3f3f3f;

struct edge {
  int v, w, next;
}e[kMaxN];

int h[kMaxN];

struct cmp {
  bool operator()(int a, int b) const {
    return h[a] < h[b];
  }
};

int head[kMaxN];
int w[kMaxN];
bool inqueue[kMaxN];
int gap[kMaxN];
int tot = 1;
int n, m, s, t;
std::priority_queue<int, vector<int>, cmp> q;

void add(int u, int v, int w) {
  e[++tot] = {v, w, head[u]};
  head[u] = tot;
}

bool bfs() {
  memset(h, 0x3f, sizeof(h));
  h[t] = 0;
  queue<int> q;
  q.push(t);
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    for (int i = head[f]; i; i = e[i].next) {
      int v = e[i].v;
      if (e[i ^ 1].w && h[v] > h[f] + 1) {
        h[v] = h[f] + 1;
        q.push(v);
      }
    }
  }
  return h[s] != INF;
}

void push(int u) {
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (e[i].w && h[v] + 1 == h[u]) {
      int res = min(e[i].w, w[u]);
      e[i].w -= res;
      e[i ^ 1].w += res;
      w[u] -= res;
      w[v] += res;
      if (v != s && v != t && !inqueue[v]) {
        q.push(v), inqueue[v] = true;
      }
      if (w[u] == 0) {
        break;
      }
    }
  }
}

void relabel(int u) {
  h[u] = INF;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (e[i].w && h[v] + 1 < h[u]) {
      h[u] = h[v] + 1;
    }
  }
  return;
}

int hlpp() {
  if (!bfs()) return 0;
  h[s] = n;
  memset(gap, 0, sizeof(gap));
  for (int i = 1; i <= n; i++) {
    if (h[i] < INF) {
      ++gap[h[i]];
    }
  }
  for (int i = head[s]; i; i = e[i].next) {
    int v = e[i].v;
    if (e[i].w) {
      int res = e[i].w;
      e[i].w -= res;
      e[i ^ 1].w += res;
      w[s] -= res;
      w[v] += res;
      if (v != s && v != t && !inqueue[v]) {
        q.push(v);
        inqueue[v] = true;
      }
    }
  }
  while (!q.empty()) {
    int u = q.top();
    inqueue[u] = false;
    q.pop();
    cout << u << endl;
    push(u);
    if (w[u]) {
      if (!(--gap[h[u]])) {
        for (int i = 1; i <= n; i++) {
          if (i != s && i != t && h[i] > h[u] && h[i] < n + 1) {
            h[i] = n + 1;
          }
        }
      }
      relabel(u);
      ++gap[h[u]];
      q.push(u);
      inqueue[u] = true;
    }
  }
  return w[t];
}

int main() {
  cin >> n >> m >> s >> t;
  for (int i = 1, u, v, c; i <= m; i++) {
    cin >> u >> v >> c;
    add(u, v, c);
    add(v, u, 0);
  }
  cout << tot << endl;
  cout << hlpp() << endl;
  return 0;
}
