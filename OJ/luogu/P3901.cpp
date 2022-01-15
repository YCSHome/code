#include <bits/stdc++.h>

using namespace std;

namespace IO {
  template <class type = long long> type read() {
    int f = 1;
    type n = 0; 
    char ch = 0;
    while ('0' > ch || ch > '9') { f = ch == '-' ? -1 : 1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') { n = n * 10 + ch - '0'; ch = getchar(); }
    return n * f;
  }

  template <class type = long long> void read(type& a) {
    a = read<type>();
  }

  template <class type = long long, class... Args> void read(type& a, Args&... args) {
    a = read<type>();
    read(args...);
  }
};

int Q, N;

int main() {
  {
    using IO::read; 
    Q = read(), N = read();
  }
  cout << Q << " " << N << endl;
  return 0;
}
