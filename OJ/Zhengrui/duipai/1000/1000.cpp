#include <iostream>
#define int long long

using namespace std;

int ans = 0;
long long L, R;

// i表示不同的数字放在第几位
inline long long get(int i, int len, int almost, int difference) {
  if (difference == 0 && i == 1) return 0;
  if (almost == 0 && i != 1) return 0;
  long long num = 0;
  for (int j = 1; j <= len; j++) {
    if (j == i) {
      num = num * 10 + difference;
    } else {
      num = num * 10 + almost;
    }
  }
  return num;
}

signed main() {
  cin >> L >> R;
  for (int i = 2; i <= 17; i++) {
    for (int almost = 0; almost <= 9; almost++) {
      for (int difference = 0; difference <= 9; difference++) {
        if (almost == difference) continue;
        for (int pos = 1; pos <= i; pos++) {
          long long t = get(pos, i, almost, difference);
          if (t >= L && t <= R) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
