#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int N[]={20,20,20,1000,1000,1000,100000,100000,100000,100000};
int n,m,s,A[100010],f[100010],t,i, dad[300010], use[300010], x, y, u, l, r, L, R;
char s1[101],s2[100];
int find(int x){return dad[x] == x ? x : dad[x] = find(dad[x]);}
int main()
{
	srand(GetTickCount());
	strcpy(s1,"paint0.in");
	strcpy(s2,"std <paint0.in >paint0.out");
	for(int _=0;_<10;_++)
	{
		s1[5]=_+'0';
		s2[10]=_+'0';
		s2[21]=_+'0';
		freopen(s1,"w",stdout);
		int K = (rand() << 15 | rand()) % N[_] + 1;
		n = (rand() << 15 | rand()) % (int(sqrt(N[_]))) + 1;
		if(_ >= 6 && _ < 8)n = 1;
		m = N[_] / n;
		if(n != 1 && (rand() & 1))swap(n, m);
		if(_ == 0) n = m = 1;
		printf("%d %d %d\n", n, m, K);
		for(int i = 1; i <= K; i++)f[i] = i;
		random_shuffle(f + 1, f + K + 1);
		memset(A, 0, sizeof(A));
		for(int i = 1; i <= K; i++){
			u = f[i];
			l = rand() % n + 1;
			r = rand() % n + 1;
			if(l > r)swap(l, r);
			L = rand() % m + 1;
			R = rand() % m + 1;
			if(L > R)swap(L, R);
			if(_ & 1){
				l = (i - 1) / ((m + 1) / 2) + 1;
				L = (i - 1) % ((m + 1) / 2) + 1;
				r = n + 1 - l;
				R = m + 1 - L;
				if(l > (n + 1) / 2)continue;
			}
			for(int j = l; j <= r; j++)
				for(int k = L; k <= R; k++)
					A[j * m + k - m] = u;
		}
		for(int i = 1; i <= n * m; i++)
			printf("%d%c", A[i], i % m ? ' ' : '\n');
		fclose(stdout);
		system(s2);
	}
}
