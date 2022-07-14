#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int u, v, type, next;
}e[kMaxN];

int n, p1, p2;
int tot = 0;
int head[kMaxN];
int in[kMaxN];
queue<int> q;

void add(int x, int y, int type) {
  e[++tot] = {x, y, type, head[x]};
  head[x] = tot;
}

int main() {
  cin >> n >> p1 >> p2;
  for (int i = 1; i <= p1; i++) {
    int x, y;
    cin >> x >> y;
    add(x, y, 0);
    in[y]++;
  }
  if (tot % 2 == 0) tot++;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) {
      q.push(i);
    }
  }
  for (int i = 1; i <= p2; i++) {
    int x, y;
    cin >> x >> y;
    add(x, y, 1);
    add(y, x, 1);
  }
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    for (int i = head[f]; i; i = e[i].next) {
      if (e[i].type == 0) {
        int v = e[i].v;
        in[v]--;
        if (in[v] == 0) {
          q.push(v);
        }
      } else if (e[i].type == 1) {
        e[i ^ 1].type = 2;
      }
    }
  }
  for (int i = 1; i <= tot; i++) {
    if (e[i].type == 1) {
      cout << e[i].u << " " << e[i].v << endl; }
  }
  return 0;
}
