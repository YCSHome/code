#include <iostream>

using namespace std;

const int kMaxN = 1e6 + 100;

int n;
char str[kMaxN];
int Next[kMaxN];

int main() {
  scanf("%d", &n);
  scanf("%s", str);
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j && str[i] != str[j]) j = Next[j];
    Next[i + 1] = str[i] == str[j] ? ++j : 0;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    j = i;
    while (Next[j]) {
      j = Next[j];
    }
    if (Next[i] != 0) {
      Next[i] = j;
    }
    ans += i - j;
  }
  printf("%lld\n", ans);
  return 0;
}
