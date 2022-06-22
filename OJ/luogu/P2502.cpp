#include <iostream>
#include <algorithm>

using namespace std;

const int kMaxN = 1e6;

struct edge {
  int u, v, t;
}e[kMaxN];;

int n, m;
int s, t;
int father[kMaxN];

int find(int x) {
  if (father[x] == x) return x;
  return father[x] = find(father[x]);
}

int get(int x) {
  int j, tot = 0;
  for (int i = 1; i <= n + 100; i++) { father[i] = i; }
  for (j = x; j <= m; j++) {
    int x = find(e[j].u), y = find(e[j].v);
    if (x != y) {
      father[x] = y;
      tot++;
    }
    if (find(s) == find(t)) return j;
  }
  return -1;
}

int gcd(int a, int b) {
  return a % b ? gcd(b, a % b) : b;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, t;
    cin >> e[i].u >> e[i].v >> e[i].t;
  }
  cin >> s >> t;
  sort(e + 1, e + 1 + m, [](const auto& a, const auto& b) { return a.t < b.t; } );
  bool ans = false;
  double MinAns = 1e9;
  int MinA, MinB;
  for (int i = 1; i <= m; i++) {
    int s;
    if ((s = get(i)) != -1) {
      ans = true;
      if (MinAns > (double)e[s].t / e[i].t) {
        MinA = e[s].t;
        MinB = e[i].t;
        MinAns = (double)e[s].t / e[i].t;
      }
    } else {
      break;
    }
  }
  if (ans == false) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    int g = gcd(MinA, MinB);
    cout << MinA / g;
    if (MinB / g != 1) {
      cout << "/" << MinB / g << endl;
    }
  }
  return 0;
}
