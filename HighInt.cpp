#include <bits/stdc++.h>
#include <math.h>

using namespace std;

#ifdef Debug
class HighInt : public vector<int> {
#else
class HighInt : protected vector<int> {
#endif
#define th (*this)
private:
  bool negative;
  // 进位
  void carry() {
    for (int i = 0; i < size(); i++) {
      if (th[i] >= 10) {
        // 避免溢出
        if (i + 1 == size()) push_back(0);
        th[i + 1] += th[i] / 10;
        th[i] %= 10;
      }
      if (th[i] < 0) {
        th[i] += 10;
        th[i + 1]--;
      }
    }
    // 去处前导0
    for (int i = size() - 1; th[i] == 0 && i > 0; i--) pop_back();
    if (size() == 1 && th[0] == 0) negative = false;
  }

  // 绝对值比大小
  bool abscmp(HighInt& cmp) {
    if (size() != cmp.size()) {
      return size() < cmp.size();
    }
    for (int i = size() - 1; i >= 0; i--) {
      if (th[i] != cmp[i]) {
        return th[i] < cmp[i];
      }
    }
    return false;
  }
public:
  HighInt() {
    th.push_back(0);
    negative = false;
  }

  HighInt(long long number) {
    clear();
    negative = false;
    if (number < 0) {
      negative = true;
      number *= -1;
    }
    while (number) {
      push_back(number % 10);
      number /= 10;
    }
  }

  HighInt& operator+=(const HighInt& a) {
    return *this;
  }

  // 基本IO
  friend ostream& operator<<(ostream& out, const HighInt& a) {
    if (a.negative) out << '-';
    for (int i = a.size() - 1; i >= 0; i--) {
      out << a[i];
    }
    return out;
  }

  friend istream& operator>>(istream& in, HighInt& a) {
    char ch = in.get();
    string str;
    a.negative = false;
    while ('0' > ch || ch > '9') {
      a.negative = (ch == '-' ? true : false);
      ch = in.get();
    }
    while ('0' <= ch && ch <= '9') {
      str += ch;
      ch = in.get();
    }
    a.resize(str.size());
    for (int i = 0, j = str.size() - 1; i < str.size(); i++, j--) {
      a[i] = str[j] - '0';
    }
    return in;
  }

  // 基本比较运算符
  bool operator<(const HighInt& cmp) const {
    if (negative != cmp.negative) {
      return negative > cmp.negative;
    }
    if (size() != cmp.size()) {
      return (size() < cmp.size()) ^ negative;
    }
    for (int i = size() - 1; i >= 0; i--) {
      if (th[i] != cmp[i]) {
        return (th[i] < cmp[i]) ^ negative;
      }
    }
    return false;
  }

  bool operator>(const HighInt& cmp) const {
    if (negative != cmp.negative) {
      return negative < cmp.negative;
    }
    if (size() != cmp.size()) {
      return (size() > cmp.size()) ^ negative;
    }
    for (int i = size() - 1; i >= 0; i--) {
      if (th[i] != cmp[i]) {
        return (th[i] > cmp[i]) ^ negative;
      }
    }
    return false;
  }

  bool operator==(const HighInt& cmp) const {
    if (size() != cmp.size() || negative != cmp.negative) return false;
    for (int i = 0; i < size(); i++) {
      if (th[i] != cmp[i]) {
        return false;
      }
    }
    return true;
  }

  bool operator<=(const HighInt& cmp) const { return !(th > cmp); }

  bool operator>=(const HighInt& cmp) const { return !(th < cmp); }

  bool operator!=(const HighInt& cmp) const { return !(th == cmp); }

  // 基本运算符
  HighInt& operator+=(HighInt& b) {
    if (size() < b.size()) {
      resize(b.size());
    }
    bool same = (negative == b.negative);
    bool small = abscmp(b);
    if (!same) b.negative ^= true;
    cout << same << " " << small << endl;
    for (int i = 0; i < b.size(); i++) {
      if (same) {
        // 符号相同直接加
        th[i] += b[i];
      } else {
        // 符号不同，绝对值大的减绝对值小的
        if (small) th[i] = b[i] - th[i];
        else th[i] -= b[i];
      }
    }
    if (!same) b.negative ^= true;
    if (!same && small) {
      negative = b.negative;
    }
    carry();
    return th;
  }

  HighInt& operator-=(HighInt& b) {
    b.negative ^= true;
    th += b;
    b.negative ^= true;
    return th;
  }

  friend HighInt& operator+(HighInt a, HighInt& b) { return a += b; }

  friend HighInt& operator-(HighInt a, HighInt& b) { return a -= b; }
#undef th
};

int main() {
  HighInt a, b;
  cout << (true ^ true) << endl;
  while (cin >> a >> b) {
    cout << a << " < " << b << ":" << (a < b ? "true" : "false") << endl
       << a << " = " << b << ":" << (a == b ? "true" : "false") << endl
       << a << " > " << b << ":" << (a > b ? "true" : "false") << endl
       << a << " + " << b << ":" << a + b << endl
       << a << " - " << b << ":" << a - b << endl;
  }
  return 0;
}
