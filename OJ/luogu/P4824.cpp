#include <iostream>
#include <stack>
#define int long long

using namespace std;

const int kMaxN = 1e6 + 100;

string S, T;
int Next[kMaxN];

stack<char> s1, s2;

signed main() {
  cin >> S >> T;
  int j = 0;
  for (int i = 1; i < T.size(); i++) {
    while (j && T[i] != T[j]) {
      j = Next[j];
    }
    Next[i + 1] = T[i] == T[j] ? ++j : 0;
  }
  for (int i = S.size() - 1; i >= 0; i--) {
    s2.push(S[i]);
  }
  while (s2.size()) {
    while (j && s2.top() != T[j]) {
      j = Next[j];
    }
    if (T[j] == s2.top()) {
      j++;
    }
    s1.push(s2.top());
    s2.pop();
    if (j == T.size()) {
      for (int i = 1; i <= T.size(); i++) {
        s1.pop();
      }
      for (int i = 1; i <= T.size() && !s1.empty(); i++) {
        s2.push(s1.top());
        s1.pop();
      }
      j = 0;
    }
  }
  while (s1.size()) {
    s2.push(s1.top());
    s1.pop();
  }
  while (s2.size()) {
    cout << s2.top();
    s2.pop();
  }
  return 0;
}
