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
const int _maxn = 1000011;
int n, m, p, l, r, s, fath[_maxn], dist[_maxn], lrot, rrot;
int find(int at) {
	if(!fath[at]) {
		return at;
	} else {
		int fa = find(fath[at]);
		dist[at] = (dist[at] + dist[fath[at]]) % p;
		return fath[at] = fa;
	}
}
int main() {
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	n = ured();
	m = ured();
	p = ured();
	rep(i, 1, m) {
		l = ured() - 1;
		r = ured();
		s = ured();
		if(find(l) == find(r)) {
			if((dist[r] - dist[l] + p) % p != s) {
				uwit(i - 1);
				return 0;
			}
		} else {
			lrot = find(l);
			rrot = find(r);
			dist[lrot] = ((dist[r] - dist[l] - s) % p + p) % p;
			fath[lrot] = rrot;
		}
	}
	uwit(m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
