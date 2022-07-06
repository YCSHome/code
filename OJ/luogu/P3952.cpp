#include <iostream>
#include <deque>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int kMaxN = 100;

deque<string> code;
map<string, bool> variable;
string temp;

string read() {
  static string temp;
  if (code.size() == 0) return "ERROR";
  temp = code.front();
  code.pop_front();
  return temp;
}

int toNum(string str) {
  int n = 0;
  for (int i = 0; i < str.size(); i++) {
    n = n * 10 + str[i] - '0';
  }
  return n;
}

int analyze(int depth, int n) {
  int ans = n;
  while (!code.empty()) {
    stringstream ss;
    string str;
    ss << read();
    ss >> str;
    if (str == "ERROR") {
      return 0x3f3f3f3f;
    }
    if (str == "E") {
      return ans;
    }
    if (str == "F") {
      string var, x, y;
      ss >> var;
      if (variable.find(var) == variable.end() || variable[var] == false) {
        variable[var] = true;
        ss >> x >> y;
        if (x == "n" && y == "n") {
          ans = max(analyze(depth + 1, n), ans);
        } else if (x != "n" && y == "n") {
          ans = max(analyze(depth + 1, n + 1), ans);
        } else if (x == "n" && y != "n") {
          ans = analyze(depth + 1, n) == 0x3f3f3f3f ? 0x3f3f3f3f : ans;
        } else if (x != "n" && y != "n") {
          int x1 = toNum(x), y1 = toNum(y);
          if (x1 <= y1) ans = max(analyze(depth + 1, n), ans);
          else ans = analyze(depth + 1, n) == 0x3f3f3f3f ? 0x3f3f3f3f : ans;
        }
        variable[var] = false;
      } else {
        return 0x3f3f3f3f;
      }
    }
  }
  if (depth > 0) ans = 0x3f3f3f3f;
  return ans;
}

void solve() {
  int n;
  code.clear();
  variable.clear();
  string time, str;
  cin >> n >> time;
  getchar();
  for (int i = 1; i <= n; i++) {
    getline(cin, str);
    code.push_back(str);
  }
  int ans = analyze(0, 0);
  if (!code.empty()) ans = 0x3f3f3f3f;
  if (ans == 0x3f3f3f3f) {
    cout << "ERR" << endl;
  } else if (ans == 0 && time[2] == '1') {
    cout << "Yes" << endl;
  } else if (ans != 0 && time[2] == '1') {
    cout << "No" << endl;
  } else {
    stringstream ss(time);
    char ch;
    int t;
    ss >> ch >> ch >> ch >> ch;
    ss >> t;
    if (ans == t) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
