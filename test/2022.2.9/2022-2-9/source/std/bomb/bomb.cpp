#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int n, a[N], f[N], g[N], F[N], G[N], t, ans;
int main(){
	freopen("bomb.in","r",stdin); 
	freopen("bomb.out","w",stdout); 
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1); 
	F[1] = 1, f[0] = 0;
	for(int i = 2; i <= n; i++){
		f[i] = 5e8;
		for(F[i] = F[i - 1]; (a[i] - a[F[i] + 1]) * 2 >= f[F[i] + 1] * 3; F[i]++);
		f[i] = min((f[F[i] + 1] * 3 + 1) / 2, a[i] - a[F[i]]);
	}
	G[n] = n, g[n] = 0;
	for(int i = n - 1; i >= 1; i--){
		g[i] = 5e8;
		for(G[i] = G[i + 1]; (a[G[i] - 1] - a[i]) * 2 >= g[G[i] - 1] * 3; G[i]--);
		g[i] = min((g[G[i] - 1] * 3 + 1) / 2, a[G[i]] - a[i]);
	}
	ans = 2e9;
	for(int i = 1; i <= n; i++){
		if(max(f[i], g[i]) < ans) t = i;
		ans = min(ans, max(f[i], g[i]));
	}
	int tt = t, an = ans;
	for(int j = t; j >= 1; j--){
		if(a[j] < a[tt] - an){
			tt = j + 1;
			an = an * 3 / 2; 
		}
		if(a[j] < a[tt] - an)assert(1);
	}
	tt = t, an = ans;
	for(int j = t; j <= n; j++){
		if(a[j] > a[tt] + an){
			tt = j - 1;
			an = an * 3 / 2; 
		}
		if(a[j] > a[tt] + an)assert(2);
	}
	tt = t, an = ans - 1; int flag = 0;
	for(int j = t; j >= 1; j--){
		if(a[j] < a[tt] - an){
			tt = j + 1;
			an = an * 3 / 2; 
		}
		if(a[j] < a[tt] - an)flag = 1;
	}
	if(!flag)assert(3);
	tt = t, an = ans - 1; flag = 0;
	for(int j = t; j <= n; j++){
		if(a[j] > a[tt] + an){
			tt = j - 1;
			an = an * 3 / 2; 
		}
		if(a[j] > a[tt] + an)flag = 1;
	}
	if(!flag)assert(4);
	printf("%d\n", ans);
}
