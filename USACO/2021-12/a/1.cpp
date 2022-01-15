/*LIUYI 出品*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n;
vector<int> G, H;
string str;

long long get(int l, int mid, int r) {
  long long ans = 0;
  for (int len = 3; l + len - 1 <= r; len++) {
    long long templeft = max(l, mid - len + 1);
    long long tempright = min(r, mid + len - 1);
    long long Tlen = tempright - templeft + 1;
    ans += Tlen - len + 1;
  }
  return ans;
}

int main() {
  long long ans = 0;
  cin >> n;
  cin >> str;
  str = '#' + str;
  G.push_back(0), H.push_back(0);
  for (int i = 1; i <= n; i++) {
    if (str[i] == 'G') {
      G.push_back(i);
    } else {
      H.push_back(i);
    }
  }
  G.push_back(n + 1), H.push_back(n + 1);
  for (int i = 1; i < (int)G.size() - 1; i++) {
    int l = G[i - 1] + 1, mid = G[i], r = G[i + 1] - 1;
    ans += get(l, mid, r);
  }
  for (int i = 1; i < (int)H.size() - 1; i++) {
    int l = H[i - 1] + 1, mid = H[i], r = H[i + 1] - 1;
    ans += get(l, mid, r);
  }
  cout << ans;
  return 0;
}
/*LIUYI 出品*/
