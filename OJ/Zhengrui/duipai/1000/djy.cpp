#include <bits/stdc++.h>

using namespace std;

long long l, r, pp, qq, ansl, ansr;
long long p[30], q[30];
int a[20] = {0, 0, 0, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135, 144, 153, 162, 171};

int main() {
	cin >> l >> r;
	--l;
	while (l) {
		p[++pp] = l % 10;
		l /= 10;
	}
	bool flag = true;
	for (int i = pp - 2; i > 0; --i) {
		if (p[i] != p[pp - 1]) {
			flag = p[pp - 1] < p[i];
			break;
		}
	}
	bool ff = false;
	for (int i = pp - 1; i > 0; --i) {
		if (!ff) {
			if (p[i] > p[pp]) {
				ff = true;
				ansl += p[i];
				bool fx = true;
				for (int j = i - 1; j > 0; --j) {
					if (p[j] != p[pp]) {
						fx = p[pp] < p[j];
						break;
					}
				}
				ansl += fx - 1;
			} else if (p[i] == p[pp]) {
				ansl += p[i];
				ff = true;
			} else {
				ansl += p[i];
				bool fx = true;
				for (int j = i - 1; j > 0; --j) {
					if (p[j] != p[pp]) {
						fx = p[pp] < p[j];
						break;
					}
				}
				if (fx) {
					++ansl;
				}
				break;
			}
		} else {
			ansl += 9;
		}
	}
	if (flag) {
		ansl += p[pp - 1] + 1;
		if (p[pp - 1] >= p[pp]) {
			--ansl;
		}
	} else {
		ansl += p[pp - 1];
		if (p[pp - 1] - 1 >= p[pp]) {
			--ansl;
		}
	}
	
	for (int i = 3; i < pp; ++i) {
		ansl += a[i] * 9;
	}
	ansl += p[pp] * a[pp] - a[pp];
	if (pp < 3) {
		ansl = 0;
	}
	
	
	while (r) {
		q[++qq] = r % 10;
		r /= 10;
	}
	flag = true;
	for (int i = qq - 2; i > 0; --i) {
		if (q[i] != q[qq - 1]) {
			flag = q[qq - 1] < q[i];
			break;
		}
	}
	ff = false;
	for (int i = qq - 1; i > 0; --i) {
		if (!ff) {
			if (q[i] > q[qq]) {
				ff = true;
				ansr += q[i];
				bool fx = true;
				for (int j = i - 1; j > 0; --j) {
					if (q[j] != q[qq]) {
						fx = q[qq] < q[j];
						break;
					}
				}
				ansr += fx - 1;
			} else if (p[i] == q[qq]) {
				ansr += q[i];
				ff = true;
			} else {
				ansr += q[i];
				bool fx = true;
				for (int j = i - 1; j > 0; --j) {
					if (q[j] != q[qq]) {
						fx = q[qq] < q[j];
						break;
					}
				}
				if (fx) {
					++ansr;
				}
				break;
			}
		} else {
			ansr += 9;
		}
	}
	if (flag) {
		ansr += q[qq - 1] + 1;
		if (q[qq - 1] >= q[qq]) {
			--ansr;
		}
	} else {
		ansr += q[qq - 1];
		if (q[qq - 1] - 1 >= q[qq]) {
			--ansr;
		}
	}
	for (int i = 3; i < qq; ++i) {
		ansr += a[i] * 9;
	}
	ansr += (q[qq] - 1) * a[qq];
	//cout << q[qq] << ansr;
	cout << ansr  - ansl;
	return 0;
}
