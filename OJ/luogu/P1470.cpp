#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1e6;

string str;
string s;
vector<string> a;
bool able[kMaxN];

int main() {
  while (cin >> str) {
    if (str == ".") {
      break;
    }
    a.push_back(str);
  }
  while (cin >> str) {
    s = s + str;
  }
  int n = s.size();
  s = ' ' + s;
  able[0] = true;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (able[i - 1]) {
      ans = i - 1;
      for (auto &str : a) {
        if (s.substr(i, str.size()) == str) {
          able[i + str.size() - 1] = true;
        }
      }
    }
  }
  for (int i = n; i >= 0; i--) {
    if (able[i]) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
