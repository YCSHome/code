#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

vector<int> go[kMaxN];
vector<int> back[kMaxN];

int n;
deque<pair<int, int>> traitor;
bool canKill[kMaxN];

int dfn[kMaxN], low[kMaxN];
bool inStack[kMaxN];
vector<int> tarjanStack;
int tarjanTotal = 0;
int parent[kMaxN];
int in[kMaxN];
bool kill[kMaxN];

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
  if (low[x] == dfn[x]) {
    int t;
    do {
      t = tarjanStack.back();
      tarjanStack.pop_back();
      inStack[t] = false;
      parent[t] = x;
    } while (x != t);
  }
}

void kill_(int x) {
  if (kill[x]) return;
  kill[x] = true;
  for (int i : go[x]) {
    kill_(i);
  }
}

int main() {
  cin >> n;
  int p;
  cin >> p;
  for (int i = 1; i <= n; i++) parent[i] = i;
  for (int i = 1; i <= p; i++) {
    int a, money;
    cin >> a >> money;
    canKill[a] = true;
    traitor.push_back(make_pair(a, money));
  }
  cin >> p;
  for (int i = 1; i <= p; i++) {
    int a, b;
    cin >> a >> b;
    canKill[b] = true;
    go[a].push_back(b);
    in[b]++;
  }
  // 如果不能全部干掉
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  int ans = 0;
  for (const auto& i : traitor) {
    if (in[i.first] == 0) {
      ans += i.second;
      kill_(i.first);
    }
  }
  for (const auto& i : traitor) {
    if (!kill[i.first]) {
      ans += i.second;
      kill_(i.first);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!kill[i]) {
      cout << "NO" << endl;
      cout << i << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  cout << ans << endl;
  return 0;
}
