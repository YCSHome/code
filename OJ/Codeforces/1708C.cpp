#include <iostream>
#include <cstring>
 
using namespace std;
 
const int kMaxN = 1e6;
 
int n, q;
int a[kMaxN];
bool yes[kMaxN];
 
void solve() {
  memset(yes, false, sizeof(yes));
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int qq = 0;
  for (int i = n; i >= 1; i--) {
    if (qq < a[i] && qq < q) {
      qq++;
      yes[i] = true;
    }
    if (qq >= a[i]) {
      yes[i] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << yes[i];
  }
  cout << endl;
}
 
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
