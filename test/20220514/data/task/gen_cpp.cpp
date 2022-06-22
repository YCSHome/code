#include "testlib.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

random_device rd;
mt19937_64 gen(rd());

int Rand_Int(int a) {
  uniform_int_distribution<> distrib(0, a);
  return distrib(gen);
}

int Rand_Int(int a, int b) {
  uniform_int_distribution<> distrib(a, b);
  return distrib(gen);
}

double Rand_Real(double a, double b) {
  uniform_real_distribution<> distrib(a, b);
  return distrib(gen);
}

bool Bernoulli_Rand_Int(double p) {
  bernoulli_distribution distrib(p);
  return distrib(gen);
}

void Input(int i) {
  ofstream cout(to_string(i) + ".in");
  int n, rate, la, ra, lb, rb;
  if (i <= 2) {
    n = 10, rate = 100, la = 50, ra = 400, lb = 20, rb = 50;
  } else if (i <= 10) {
    n = 100, rate = rnd.next(10000, 30000), la = rate - 10000, ra = 30000, lb = -3000, rb = 1000;
  } else {
    n = 100000, rate = rnd.next(int(1e8), int(1e9)), la = rate - 1e8, ra = 1e9, lb = -1e9, rb = rnd.next(1, 10) * 1e8;
  }
  cout << n << ' ' << rate << endl;
  while (n--) {
    cout << rnd.next(la, ra) << ' ' << rnd.next(lb, rb) << endl;
  }
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  //  srand((unsigned)time(0));
  for (int i = 1; i <= 20; i++) {
    Input(i);
  }
  return 0;
}