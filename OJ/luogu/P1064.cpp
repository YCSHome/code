#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e5;

struct thing {
  int v, w;
  friend thing operator + (const thing& a, const thing& b) {
    thing temp;
    temp.v = a.v + b.v;
    temp.w = a.w + b.w;
    return temp;
  }
};

int dp[80][kMaxN];
int n, m;
int ans = 0;
int pos[100];

vector<vector<thing>> things;

void init(vector<thing>& ve) {
  if (ve.size() == 1) return;
  vector<thing> temp;
  temp.push_back(ve.front());
  if (ve.size() >= 1) {
    temp.push_back(ve.front() + *(ve.begin() + 1));
  }
  if (ve.size() >= 2) {
    temp.push_back(ve.front() + *(ve.begin() + 2));
    temp.push_back(ve.front() + *(ve.begin() + 1) + *(ve.begin() + 2));
  }
  ve = temp;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int v, w, p;
    cin >> v >> w >> p;
    w = v * w;
    if (p == 0) {
      vector<thing> temp;
      temp.push_back((thing){v, w});
      things.push_back(temp);
      pos[i] = things.size() - 1;
    } else {
      things[pos[p]].push_back({v, w});
    }
  }
  int tot = 1;
  for (int i = 1; i <= things.size(); i++) init(things[i - 1]);
  tot = 1;
  for (int i = 1; i <= things.size(); i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      for (const auto & thing : things[i - 1]) {
        if (j - thing.v >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - thing.v] + thing.w);
        }
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
}
