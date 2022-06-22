#include <bits/stdc++.h>

using namespace std;

const long long kMaxN = 1e6;


long long n, x, y;
long long gx, gy;
long long temp[50];
long long ans[kMaxN];
vector<pair<long long, long long>> CommandList;
vector<pair<long long, long long>> a, b;
vector<pair<pair<long long, long long>, long long>> Left, Right;

int main() {
  cin >> n;
  cin >> gx >> gy;
  CommandList.push_back({0, 0});
  for (long long i = 1; i <= n; i++) {
    cin >> x >> y;
    CommandList.push_back({x, y});
  }
  for (long long i = 1; i <= n / 2; i++)     { a.push_back(CommandList[i]); }
  for (long long i = n / 2 + 1; i <= n; i++) { b.push_back(CommandList[i]); }
  {
    vector<pair<pair<long long, long long>, long long>> temp;
    Left.push_back(make_pair(make_pair(0, 0), 0));
    for (auto i : a) {
      temp.clear();
      for (auto x : Left) {
        temp.push_back(make_pair(make_pair(i.first + x.first.first, i.second + x.first.second), x.second + 1));
      }
      for (auto p : temp) {
        Left.push_back(p);
      }
    }
    Right.push_back(make_pair(make_pair(gx, gy), 0));
    for (auto i : b) {
      temp.clear();
      for (auto x : Right) {
        temp.push_back(make_pair(make_pair(x.first.first - i.first, x.first.second - i.second), x.second + 1));
      }
      for (auto p : temp) {
        Right.push_back(p);
      }
    }
  }
  sort(Left.begin(), Left.end());
  sort(Right.begin(), Right.end());
  pair<long long, long long> last(1e18, 1e18);
  long long p = 0;
  for (auto l : Left) {
    if (l.first != last) {
      memset(temp, 0, sizeof(temp));
      last = l.first;
      for (; p < Right.size() && Right[p].first < l.first; p++);
      for (; p < Right.size() && Right[p].first == l.first; p++) {
        temp[Right[p].second]++;
      }
    }
    for (long long i = 0; i <= 20; i++) {
      ans[i + l.second] += temp[i];
    }
  }
  for (long long i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
