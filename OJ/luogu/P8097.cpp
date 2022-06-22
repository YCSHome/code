#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e5;

vector<int> to[kMaxN];
vector<int> node[kMaxN];

int n, q;
int father[kMaxN];
int ans[kMaxN];
bool Delete[kMaxN];

int find(int x) {
  if (father[x] == x) return x;
  return father[x] = find(father[x]);
}

void update(int i, int j, int New) {
  int f1 = find(i), f2 = find(j);
  if (f1 == f2) return;
  if (ans[f1] == 0 || ans[f1] == 0 && (ans[f1] != ans[f2])) {
    if (ans[f1] == 0) {
      for (auto i : node[f1]) {
        ans[i] = New;
      }
    } else if (ans[f2] == 0) {
      for (auto i : node[f2]) {
        ans[i] = New;
      }
    }
  }
  if (node[f1].size() > node[f2].size()) {
    father[f2] = f1;
    for (auto i : node[f2]) {
      node[f1].push_back(i);
    }
  } else {
    father[f1] = f2;
    for (auto i : node[f1]) {
      node[f2].push_back(i);
    }
  }
}

int main() {
  vector<pair<string, int>> p;
  vector<pair<int, int>> edge;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    father[i] = i;
    ans[i] = q;
    node[i].push_back(i);
  }
  p.push_back({"", 0});
  edge.push_back({0, 0});
  for (int i = 1; i <= q; i++) {
    string str;
    int a;
    cin >> str >> a;
    if (str == "A") {
      int b;
      cin >> b;
      edge.push_back(make_pair(a, b));
    }
    if (str == "D") {
      ans[a] = 0;
    }
    if (str == "R") Delete[a] = true;
    p.push_back(make_pair(str, a));
  }
  for (int i = 1; i <= edge.size() - 1; i++) {
    if (Delete[i] == false) {
      update(edge[i].first, edge[i].second, q);
    }
  }
  for (int i = q; i >= 1; i--) {
    if (p[i].first == "R") {
      update(edge[p[i].second].first, edge[p[i].second].second, i - 1);
    } else if (p[i].first == "D") {
      int f = find(p[i].second);
      if (ans[f] == 0) {
        for (auto j : node[f]) {
          ans[j] = i - 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
