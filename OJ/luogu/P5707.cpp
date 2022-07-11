#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int s, v;
int Time = 0;
int H = 8;

int main() {
  cin >> s >> v;
  Time = 10 + ceil(double(s) / v);
  H -= ceil(double(Time) / 60);
  if (H < 0) H += 24;
  Time %= 60;
  printf("%02d:%02d", H, 60 - Time);
  return 0;
}
