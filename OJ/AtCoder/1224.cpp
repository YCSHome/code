#include <iostream>
#include <map>
#include <utility>
#define int long long

using namespace std;

const int kMaxN = 1e6;

int n;
int countJ[kMaxN];
int countI[kMaxN];
int countO[kMaxN];
string str;
map<pair<int, int>, int> M;

signed main() {
  int ans = 0;
  M[make_pair(0, 0)] = 0;
  cin >> n >> str;
  str = '#' + str;
  for (int i = 1; i <= n; i++) {
    countJ[i] = countJ[i - 1] + (str[i] == 'J' ? 1 : 0);
    countI[i] = countI[i - 1] + (str[i] == 'I' ? 1 : 0);
    countO[i] = countO[i - 1] + (str[i] == 'O' ? 1 : 0);
    int a = countJ[i] - countI[i];
    int b = countJ[i] - countO[i];
    auto t = make_pair(a, b);
    if (M.find(t) != M.end()) {
      ans = max(i - M[t], ans);
    } else {
      M[t] = i;
    }
  }
  cout << ans << endl;
  return 0;
}
/*
1 1 0 0
2 0 0 1
3 0 1 0
0 0 0
1 0 0
0 0 1
1 0 0
0 0 1
0 0 0
0 1 0
9
 */
