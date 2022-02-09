#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int N[]={10,10,10,1000,1000,1000,1000000,1000000,1000000,1000000};
const int M[]={2,2,2,1000,1000,1000,2,2,2,1000000000};
int n,m,s,A[100010],f[100010],t,i, dad[300010], use[300010], x, y, u, l, r, L, R, p;
char s1[101],s2[100];
int find(int x){return dad[x] == x ? x : dad[x] = find(dad[x]);}
int main()
{
	srand(GetTickCount());
	strcpy(s1,"seq0.in");
	strcpy(s2,"std <seq0.in >seq0.out");
	for(int _=0;_<10;_++)
	{
		s1[3]=_+'0';1
		s2[8]=_+'0';
		s2[17]=_+'0';
		freopen(s1,"w",stdout);
		n = (rand() << 15 | rand()) % (N[_] / 2) + N[_] / 2 + 1;
		m = (rand() << 15 | rand()) % (N[_] / 2) + N[_] / 2 + 1;
		p = (rand() << 15 | rand()) % (M[_] - 1) + 2;
		printf("%d %d %d\n", n, m, p);
		for(int i = 1; i <= m; i++){
			l = (rand() << 15 | rand()) % n + 1;
			r = (rand() << 15 | rand()) % n + 1;
			if(l > r)swap(l, r);
			printf("%d %d %d\n", l, r, (rand() << 15 | rand()) % p);
		}
		fclose(stdout);
		system(s2);
	}
}
