#include <queue>
#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

struct node {
  int x, y, value;
  bool operator<(const node& cmp) const {
    if (value == cmp.value) return x > cmp.x;
    return value > cmp.value;
  }
};

priority_queue<node> q;
vector<pair<int, int>> ans;

int n;
string str;
int a[kMaxN];
bool vis[kMaxN];

int main() {
  cin >> n >> str;
  str = '#' + str;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    if (str[i] != str[i + 1]) {
      q.push({i, i + 1, abs(a[i] - a[i + 1])});
    }
  }
  while (!q.empty()) {
    int x = q.top().x, y = q.top().y;
    q.pop();
    if (vis[x] || vis[y]) continue;
    ans.push_back(make_pair(x, y));
    vis[x] = vis[y] = true;
    while (vis[x]) x--;
    while (vis[y]) y++;
    if (x <= 0 || y > n) continue;
    if (str[x] == str[y]) continue;
    q.push({x, y, abs(a[x] - a[y])});
  }
  cout << ans.size() << endl;
  for (const auto& i : ans) {
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}
