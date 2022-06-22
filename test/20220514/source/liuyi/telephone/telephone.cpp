#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

int n, k;

int b[kMaxN];
int t[kMaxN];
bool ok[60][60];

int main (){
  freopen("telephone.in", "r", stdin);
  freopen("telephone.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) t[i] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= k; i++) {
    string str;
    cin >> str;
    str = '#' + str;
    for (int j = 1; j <= k; j++) {
      ok[i][j] = str[j] - '0';
    }
  }
  t[1] = 0;
  for (int k = 1; k <= n / 2 + 1; k++) {
    for (int i = 1; i <= n; i++) {
      if (t[i] == -1) continue;
      for (int j = 1; j <= n; j++) {
        if (ok[b[i]][b[j]]) {
          t[j] = (t[j] == -1 ? abs(i - j) + t[i] : min(t[j], abs(i - j) + t[i]));
        }
      }
    }
  }
  cout << t[n] << endl;
  return 0;
}
