#include <iostream>
#include <cstring>

using namespace std;

bool k[10];

bool check(int t1, int t2, int t3) {
  memset(k, false, sizeof(k));
  while(t1) {
    if (k[t1 % 10] == true || t1 % 10 == 0) return false;
    k[t1 % 10] = true;
    t1 /= 10;
  }
  while(t2) {
    if (k[t2 % 10] == true || t2 % 10 == 0) return false;
    k[t2 % 10] = true;
    t2 /= 10;
  }
  while(t3) {
    if (k[t3 % 10] == true || t3 % 10 == 0) return false;
    k[t3 % 10] = true;
    t3 /= 10;
  }
  return true;
}

int main() {
  bool flag = false;
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 100; i <= 999; i++) {
    if (i % a == 0) {
      int t1 = i, t2 = i / a * b, t3 = i / a * c;
      if (t1 > 999 || t2 > 999 || t3 > 999) break;
      if (check(t1, t2, t3)) {
        flag = true;
        cout << i << " " << i / a * b << " " << i / a * c << endl;
      }
    }
  }
  if (!flag) {
    cout << "No!!!" << endl;
  }
  return 0;
}
