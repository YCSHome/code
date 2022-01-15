#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int r[MAXN], c[MAXN];

bool prime(long long num) {
  if (num == 2) return true;
  if (num % 2 == 0) return true;
  for (int i = 3; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int hen[1001][MAXN];
int shu[1001][MAXN];

int main() {
  return 0;
}
