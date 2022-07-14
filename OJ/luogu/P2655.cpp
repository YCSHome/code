#include <iostream>
#include <ctime>
#define int long long

using namespace  std;

const int kMaxN = 1e6;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int t;
int c[kMaxN];

bool check(int y) {
  return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

void solve() {
  int begin, y, m, d, h, min, s, temp;
  cin >> begin >> y >> m >> d >> h >> min >> s;
  s += c[begin] - 1;
  temp = s / 60;
  s %= 60;
  min += temp;

  temp = min / 60;
  min %= 60;
  h += temp;

  temp = h / 24;
  h %= 24;
  d += temp;

  while(d > month[m]) {
    if (check(y)) {
      month[2] = 29;
    } else {
      month[2] = 28;
    }
    d -= month[m];
    m++;
    if (m > 12) {
      m = 1;
      y++;
    }
  }
  cout << y << " " << m << " " << d << " " << h << " " << min << " " << s << endl;
}

signed main() {
  double Begin = clock();
  cin >> t;
  c[1] = 1;
  for (int i = 2; i <= 32; i++) {
    c[i] = c[i - 1] * 2;
  }
  while (t--) {
    solve();
  }
  while ((clock() - Begin) / CLOCKS_PER_SEC <= 0.6);
  return 0;
}
