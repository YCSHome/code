#include <bits/stdc++.h>

using namespace std;

string s;
int b[3][1000010];

struct E {
	int a, b, c;
} e[1000010];

bool cmp(E x, E y) {
	return x.a != y.a ? x.a < y.a : (x.b != y.b ? x.b < y.b : x.c < y.c);
}

int main() {
	cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] < 'D') {
			b[0][i + 1] = b[0][i];
			b[1][i + 1] = b[1][i];
			b[2][i + 1] = b[2][i];
			++b[s[i] - 'A'][i + 1];
			if (b[0][i + 1] > 0 && b[1][i + 1] > 0 && b[2][i + 1] > 0) {
				--b[0][i + 1];	
				--b[1][i + 1];
				--b[2][i + 1];
			}
			e[i + 1].a = b[0][i + 1];
			e[i + 1].b = b[1][i + 1];
			e[i + 1].c = b[2][i + 1];
		}
	}
	sort(e + 1, e + 1 + s.length(), cmp);
	long long sum = 1;
	long long ans(0);
	for (int i = 1; i <= s.length(); ++i) {             
		if (e[i].a == e[i - 1].a && e[i].b == e[i - 1].b && e[i].c == e[i - 1].c) {
			++sum;
		} else {
			ans += sum * (sum - 1) / 2;
			sum = 1;
		}
	}
	ans += sum * (sum - 1) / 2;
	cout << ans;
	return 0;
}
