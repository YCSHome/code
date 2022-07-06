#include <iostream>
#include <string>
#include <deque>

using namespace std;

const int kMaxN = 1e6;

deque<string> s;
char ch[114514];

int main() {
  string str;
  while(1) {
    getline(cin, str);
    int t = 0;
    for (int i = 0; i < str.size(); i++) {
      ch[t++] = str[i];
      if (str[i] == '<') t--, t--;
      t = max(t, 0);
    }
    ch[t] = '\0';
    str = ch;
    if (str == "EOF") break;
    s.push_back(str);
  }
  int tot = 0;
  while(1) {
    getline(cin, str);
    if (str == "EOF") break;
    if (s.empty()) continue;
    int t = 0;
    for (int i = 0; i < str.size(); i++) {
      ch[t++] = str[i];
      if (str[i] == '<') t--, t--;
      t = max(t, 0);
    }
    ch[t] = '\0';
    str = ch;
    for (int i = 0; i < str.size() && i < s.begin()->size(); i++) {
      if (str[i] == (*s.begin())[i]) {
        tot++;
      }
    }
    s.pop_front();
  }
  int t;
  cin >> t;
  int kpm = tot * 60.0 / t + 0.5;
  cout << kpm << endl;
  return 0;
}
