#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

const int kMaxN = 1e6 + 100;

string str;
int countA[kMaxN];
int countB[kMaxN];
int countC[kMaxN];
map<pair<int, int>, int> pairCount;

int main() {
  cin >> str;
  int n = str.size();
  str = '#' + str;
  for (int i = 1; i <= n; i++) {
    if (str[i] == 'A') {
      countA[i]++;
    } else if (str[i] == 'B') {
      countB[i]++;
    } else if (str[i] == 'C') {
      countC[i]++;
    }
    countA[i] += countA[i - 1];
    countB[i] += countB[i - 1];
    countC[i] += countC[i - 1];
  }
  // 暴力:
  // {
  //   int ans = 0;
  //   for (int i = 1; i <= n; i++) {
  //     for (int j = i; j <= n; j++) {
  //       if (countA[j] - countA[i - 1] == countB[j] - countB[i -1] &&
  //           countA[j] - countA[i - 1] == countC[j] - countC[i - 1]) {
  //         ans++;
  //       }
  //     }
  //   }
  //   cout << ans << endl;
  // }
  // A[j] - A[i - 1] == B[j] - B[i - 1] == C[j] - C[i - 1]
  // A[j] - A[i - 1] == B[j] - B[i - 1]
  // A[j] - B[j] == A[i - 1] - B[i - 1]
  // A[j] - C[j] == A[i - 1] - C[i - 1]
  // B[j] - C[j] == B[i - 1] - C[i - 1]
  {
    int ans = 0;
    pairCount[make_pair(0, 0)]++;
    for (int i = 1; i <= n; i++) {
      int a = countA[i] - countB[i];
      int b = countA[i] - countC[i];
      // int b = countB[i] - countC[i];
      ans += pairCount[make_pair(a, b)]++;
    }
    cout << ans << endl;
  }
  return 0;
}
