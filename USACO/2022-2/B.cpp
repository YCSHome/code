#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n;
int a[MAXN];
int b[MAXN];
int s = 0;
bool ues[MAXN];

list<int> A, B;

int main() {
  int ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    A.push_back(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    B.push_back(b[i]);
  }
  for (auto it1 = A.begin(), it2 = B.begin(); it2 != B.end(); it1++, it2++) {
    while (ues[*it1] && it1 != A.end()) {
      it1++;
    }
    if (*it1 != *it2) {
      A.insert(it1, *it2);
      it1--;
      ues[*it2] = true;
      ans++;
    }
  }
  cout << ans;
  return 0;
}
