#include <iostream>
#include <fstream>
#include <random>
#define int long long

using namespace std;

string get(int x) {
  string str;
  if (x >= 10) {
    str += x / 10 + '0';
  }
  str += x % 10 + '0';
  return str;
}

signed main() {
  cout << "build" << endl;
  if (system("g++ std.cpp -o std") || system("g++ random.cpp -o random")) {
    return -1;
  }
  mt19937_64 e(clock());
  for (int i = 1; i <= 20; i++) {
    cout << "make " << i << endl;
    ofstream fout("input");
    string command = "./random < input > " + get(i) + ".in";
    if (i <= 3) {
      uniform_int_distribution<long long> rand(1, 30);
      fout << 5 << " " << rand(e) << " " << rand(e) << endl;
      fout << 10 << " " << 10 << endl;
    } else if (i <= 6) {
      uniform_int_distribution<long long> rand(1, 30);
      fout << 10 << " " << rand(e) << " " << rand(e) << endl;
      fout << 10 << " " << 100 << endl;
    } else if (i <= 12) {
      uniform_int_distribution<long long> rand(100, 200);
      fout << 100 << " " << rand(e) << " " << rand(e) << endl;
      fout << 20 << " " << (long long)1e5 << endl;
    } else if (i <= 20) {
      fout << 400 << " " << 500 << " " << 500 << endl;
      fout << 500 << " " << (long long)1e15 << endl;
    }
    system(command.c_str());
  }
  for (int i = 1; i <= 20; i++) {
    cout << "run " << i << endl;
    string command = "./std < " + get(i) + ".in > " + get(i) + ".out";
    system(command.c_str());
  }
  return 0;
}
