#include<bits/stdc++.h>
using namespace std;
int n,s,t,k1,k2;
long long f[2][505][505];
char c[505][505];
#define mod 1000000007
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%s",c[i]+1);
	for(int i=1;i<=n;i++)
	f[(n+1)%2][i][i]=1;//只长一个字母时的初始化
	k1=n;k2=n+2;//坐标和
	for( ;k1>=2;k1--,k2++)
	{
		memset(f[k1%2],0,sizeof(f[k1%2])); 
		for(int i=1;i<=k1-1;i++)//k1的横坐标
		for(int j=k2-n;j<=n;j++)//k2的横坐标
		if(c[i][k1-i]==c[j][k2-j])
		f[k1%2][i][j]=(f[(k1+1)%2][i][j-1]+f[(k1+1)%2][i][j]+f[(k1+1)%2][i+1][j-1]+f[(k1+1)%2][i+1][j])%mod;
	}
	cout<<f[0][1][n]<<endl;//(1,1),(n,n)坐标和%2自然为0
	return 0;
}
