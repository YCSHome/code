#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6;

int t;
int m, n, k;
int a[kMaxN];

bool solve() {
  vector<int> OverEmails,
              UnderEmails,
              NowEmails;
  int Folders, Emails, WindowsSize;
  int UpFolder, DownFolder;
  cin >> Folders >> Emails >> WindowsSize;
  UpFolder = 1;
  DownFolder = WindowsSize;
  if (Folders <= WindowsSize) {
    return true;
  }
  {
    int NowEmail;
    for (int i = 1; i <= WindowsSize; i++) {
      cin >> NowEmail;
      NowEmails.push_back(NowEmail);
    }
    for (int i = 1; i <= Emails - WindowsSize; i++) {
      cin >> NowEmail;
      UnderEmails.push_back(NowEmail);
    }
  }
  return false;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
