#include<bits/stdc++.h>
#define N 1000010
using namespace std;
map<int, int>dad, h;
int n, m, l, r, X, Y, i, t, k, p;
char s1[110];
int find(int x){
	if(!dad[x])return x;
	int t = find(dad[x]);
	h[x] = (h[x] + h[dad[x]]) % p;
	return dad[x] = t;
}
char ch;
void read(int &x) {
	for(ch = getchar(); ch < '0'; ch = getchar());
	for(x = 0; ch >= '0'; ch = getchar()) x = x * 10 + ch - '0';
}
int main(){
	read(n);
	read(m);
	read(p);
	for(i = 1; i <= m; i++){
		read(l);
		read(r);
		read(k);
		r++;
		X = find(l);
		Y = find(r);
		t = (h[r] - h[l] + p) % p;
		if(X != Y){
			dad[X] = Y;
			h[X] = (t - k + p) % p;
		}else if(t != k)break;
	} 
	printf("%d\n", i - 1);
}
