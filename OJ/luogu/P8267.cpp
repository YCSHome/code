#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

int b[kMaxN];
int p[kMaxN];
int L[kMaxN];
int G[kMaxN];
char ch[kMaxN];
int n;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ch[i] >> p[i];
    b[i]= p[i];
  }
  sort(b + 1, b + 1 + n);
  int len = unique(b + 1, b + 1 + n) - b + 1;
  if (len > n) len = n;
  for (int i = 1; i <= n; i++) {
    p[i] = lower_bound(b + 1, b + 1 + len, p[i]) - b;
  } 
  for (int i = 1; i <= n; i++) {
    if (ch[i] == 'L') {
      L[p[i]]++;
    } else if (ch[i] == 'G') {
      G[p[i]]++;
    }
  }
  for (int i = 1; i <= n; i++) { G[i] += G[i - 1]; }
  for (int i = n; i >= 1; i--) { L[i] += L[i + 1]; }
  int Max = 0;
  for (int i = 1; i <= n; i++) {
    Max = max(Max, L[i] + G[i]);
  }
  cout << (n - Max) << endl;
  return 0;
}
