#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

double F(double x1, double x2, double y1, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
	double ans = 0;
	double x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	ans += F(x1, x2, y1, y2) + F(x2, x3, y2, y3) + F(x3, x1, y3, y1);
	printf ("%.2f", ans);
}
