#include <iostream>

using namespace std;

const int kMaxN = 200;

struct people {
  string name;
  int money, ID;
  bool operator<(const people& cmp) const {
    if (money == cmp.money) return ID < cmp.ID;
    return money > cmp.money;
  }
}s[kMaxN];

int n;
int ans = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].name;
    s[i].ID = i;
    int s1, s2, l, money = 0;
    char a, b;
    cin >> s1 >> s2 >> a >> b >> l;
    if (s1 > 80 && l >= 1) money += 8000;
    if (s1 > 85 && s2 > 80) money += 4000;
    if (s1 > 90) money += 2000;
    if (s1 > 85 && b == 'Y') money += 1000;
    if (s2 > 80 && a == 'Y') money += 850;
    s[i].money = money;
    ans += money;
  }
  sort(s + 1, s + 1 + n);
  cout << s[1].name << endl << s[1].money << endl << ans;
  return 0;
}
