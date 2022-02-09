#include<bits/stdc++.h>
using namespace std;
#define rep(i, d, u) for(int i = d; i <= u; ++i)
#define dep(i, u, d) for(int i = u; i >= d; --i)
#define cep(n) while(n--)
#define gep(i, a) for(int i = firs[a]; i; i = neig[i])
int ured() {
	int ch, re = 0;
	do {
		ch = getchar();
	} while('9' < ch || ch < '0');
	do {
		re = re * 10 + (ch ^ '0');
	} while('0' <= (ch = getchar()) && ch <= '9');
	return re;
}
void uwit(int da) {
	int ch[21], cn = 0;
	do {
		ch[++cn] = da - da / 10 * 10;
	} while(da /= 10);
	do {
		putchar('0' ^ ch[cn]);
	} while(--cn);
}
const int _maxn = 1000011, _maxa = 500000000;
int n, a[_maxn], dpol[_maxn], dpor[_maxn], atno, rans;
bool cmp1(int le, int ri) {
	return le > ri;
}
int main() {
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	n = ured();
	rep(i, 1, n) {
		a[i] = ured();
	}
	sort(a + 1, a + n + 1);
	atno = 1;
	rep(i, 2, n) {
		while(atno + 1 < i && (dpol[atno + 1] * 3 + 1) / 2 <= a[i] - a[atno + 1]) {
			++atno;
		}
		if(atno + 1 < i) {
			dpol[i] = min(a[i] - a[atno], (dpol[atno + 1] * 3 + 1) / 2);
		} else {
			dpol[i] = a[i] - a[atno];
		}
	}
	sort(a + 1, a + n + 1, cmp1);
	atno = 1;
	a[1] = _maxa - a[1];
	rep(i, 2, n) {
		a[i] = _maxa - a[i];
		while(atno + 1 < i && (dpor[atno + 1] * 3 + 1) / 2 <= a[i] - a[atno + 1]) {
			++atno;
		}
		if(atno + 1 < i) {
			dpor[i] = min(a[i] - a[atno], (dpor[atno + 1] * 3 + 1) / 2);
		} else {
			dpor[i] = a[i] - a[atno];
		}
	}
	rans = _maxa;
	rep(i, 1, n) {
		if(rans > max(dpol[i], dpor[n - i + 1])) {
			rans = max(dpol[i], dpor[n - i + 1]);
		}
	}
	uwit(rans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}