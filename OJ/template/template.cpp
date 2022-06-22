#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
  struct node {
    int l, r;
    node * left, * right;
    int value;
    int lazy;

    node(int l, int r) : l(l), r(r) {
    }

    void add(int k) {
      lazy += k;
      value += (r - l + 1) * k;
    }
  };
public:
};

int main() {
  return 0;
}
