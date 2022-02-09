#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int N[]={10,10,10,1000,1000,1000,1000000,1000000,1000000,1000000};
int n,m,s,A[100010],f[100010],t,i, dad[300010], use[300010], x, y, u, l, r, L, R;
char s1[101],s2[100];
int find(int x){return dad[x] == x ? x : dad[x] = find(dad[x]);}
int main()
{
	srand(GetTickCount());
	strcpy(s1,"bomb0.in");
	strcpy(s2,"std <bomb0.in >bomb0.out");
	for(int _=0;_<10;_++)
	{
		s1[4]=_+'0';
		s2[9]=_+'0';
		s2[19]=_+'0';
		freopen(s1,"w",stdout);
		n = (rand() << 15 | rand()) % (N[_] / 2) + (N[_] / 2) + 1;
		printf("%d\n", n);
		int nn = (int)(n * sqrt(n)) / 2;
		for(int i = 1; i <= n; i++)
			printf("%d ", (rand() << 15 | rand()) % nn);
		puts("");
		fclose(stdout);
		system(s2);
	}
}
