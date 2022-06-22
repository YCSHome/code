#include <bits/stdc++.h>

using namespace std;

namespace IO {
  template <class type = long long>
  type read() {
    type w = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')   { f = ch == '-' ? -1 : 1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { w = w * 10 + ch - '0'; ch = getchar(); }
    return w * f;
  }
};

const int kMaxN = 1e6;

int n;
int ans[kMaxN];
int Ans = 0;

int main() {
  using namespace IO;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t = read(), w, temp = 0;
    ans[t] = read();
    while ((w = read())) {
      temp = max(temp, ans[w]);
    }
    ans[t] += temp;
    Ans = max(Ans, ans[t]);
  }
  cout << Ans << endl;
  return 0;
}
