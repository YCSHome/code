#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];
int b[kMaxN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) { cin >> a[i]; }
  for (int i = 1; i <= n; i++) { cin >> b[i]; }
  return 0;
}
