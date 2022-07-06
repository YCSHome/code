#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

vector<int> go[kMaxN];
vector<int> tarjanStack;

int n, m;
int tarjanTotal;
int dfn[kMaxN], low[kMaxN];
bool inStack[kMaxN];
vector<vector<int>> group;

inline void add(int u, int v) {
  go[u].push_back(v);
}

void tarjan(int x) {
  dfn[x] = low[x] = ++tarjanTotal;
  tarjanStack.push_back(x);
  inStack[x] = true;
  for (int i : go[x]) {
    if (!dfn[i]) {
      tarjan(i);
      low[x] = min(low[x], low[i]);
    } else if (inStack[i]) {
      low[x] = min(low[x], dfn[i]);
    }
  }
  if (dfn[x] == low[x]) {
    vector<int> temp;
    group.push_back(temp);
    int t = 0;
    do {
      t = tarjanStack.back();
      inStack[t] = false;
      group.back().push_back(t);
      tarjanStack.pop_back();
    } while (x != t);
    sort(group.back().begin(), group.back().end());
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    add(a, b);
    if (t == 2) {
      add(b, a);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  int pos = 0, maxLen = 0;
  sort(group.begin(), group.end(),
      [](const auto& a, const auto& b) {
        if (a.size() != b.size())
          return a.size() > b.size();
        for (int i = 0; i < a.size(); i++) {
          if (a[i] != b[i]) {
            return a[i] < b[i];
          }
        }
        return false;
      });
  cout << group.front().size() << endl;
  for (int i : group.front()) {
    cout << i << " ";
  }
  return 0;
}
