#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int kMaxN = 1e5 + 10;

int n, m;
bool type[kMaxN];
int zeroCount[3101][3101];
int nextZero[3101][3101];
int t[kMaxN];
int temp[kMaxN];
string str[kMaxN];

void solve1() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
    str[i] = '#' + str[i];
    for (int j = 1; j <= m; j++) {
      if (str[i][j] == '0') {
        t[j]++;
      } else {
        t[j] = 0;
      }
      temp[j] = t[j];
    }
    sort(temp + 1, temp + 1 + m);
    for (int i = 1; i <= m; i++) {
      ans = max(ans, (m - i + 1) * temp[i]);
    }
  }
  cout << ans << endl;
}

void solve2() {
  string str;
  for (int i = 1; i <= n; i++) {
    cin >> str;
    if (str[0] == '0') {
      type[i] = false;
    } else {
      type[i] = true;
    }
  }
  int j = 0;
  int ans = 0;
  for (int i = 1; i <= n; ) {
    if (type[i]) {
      i++;
      continue;
    }
    j = i;
    for (; type[i] == type[j] && j <= n; j++) {
    }
    ans = max(ans, (j - i) * m);
    i = j;
  }
  cout << ans << endl;
}

int main() {
  cin >> n >> m;
  if (n <= 3000) {
    solve1();
  } else {
    solve2();
  }
  return 0;
}
