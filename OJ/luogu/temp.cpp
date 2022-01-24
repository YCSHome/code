#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int head[N], Next[N << 1], ver[N << 1];
void add(int x, int y) {
	static int cnt = 0;
	ver[++cnt] = y, Next[cnt] = head[x], head[x] = cnt;
	ver[++cnt] = x, Next[cnt] = head[y], head[y] = cnt;
}

int color[N], tot[N], cnt[N], n;
int enos[N], size[N], nos[N];
long long ans1[N], ans2[N];

inline void dfs(int x, int fa) {
	cout << x << " " << fa << endl;
	int c = color[x], k = cnt[c];
	int flag = 0, pos = 0;
	size[x] = 1;
	
	for(int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if(y == fa) continue;
		int lastans = cnt[c];
		dfs(y, x);
		ans1[x] += 1LL * size[x] * size[y];
		size[x] += size[y];
		if(lastans != cnt[c]) flag++, pos = y;
	}
	ans1[x] += 1LL * size[x] * (n - size[x]);
	if(k || cnt[c] != tot[c] - 1) flag++;
	cnt[c]++;
	
	if(flag == 1) { // 端点 
		if(!enos[c]) nos[c] = x;
		else {
			int p = pos ? n - size[pos] : size[x];
			ans2[c] = 1LL * size[nos[c]] * p;
		} enos[c]++;	
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", color + i);
		tot[color[i]]++;
		nos[color[i]] = i;
	}
	for(int i = 1, x, y; i < n; i++) {
		scanf("%d %d", &x, &y);
		add(x, y);
	} 
	dfs(1, 0);
  for (int i = 1; i <= n; i++) cout << ans1[i] << " ";
	for(int i = 1; i <= n; i++) {
		if(tot[i] == 0) 
			printf("%lld\n", 1LL * n * (n - 1) >> 1);
		else if(tot[i] == 1)
			printf("%lld\n", ans1[nos[i]]);
		else if(enos[i] == 2)
			printf("%lld\n", ans2[i]);
		else puts("0");
	}
	return 0;
}

