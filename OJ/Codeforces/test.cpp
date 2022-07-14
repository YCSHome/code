#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define R register
#define MAXN 1000100
using namespace std;
struct node
{
	int a,b;
	bool operator < (const node &tp) const
	{
		return a<tp.a;
	} 
}w[MAXN];
int n,len,ans;
int dp[MAXN];
map<int,bool> mp;//记录i位置是否是激光塔
map<int,int> power;//记录i位置激光塔威力
int main()
{
	scanf("%d",&n);
	for(R int i=1;i<=n;i++)
		scanf("%d%d",&w[i].a,&w[i].b);
	sort(w+1,w+1+n);//貌似数据不用排序...
	for(R int i=1;i<=n;i++)
	{
		mp[w[i].a]=true;
		power[w[i].a]=w[i].b;
		len=max(len,w[i].a);
	}
	if(mp[0]) dp[0]=1;
	for(R int i=0;i<=len;i++)
	{
		if(mp[i]) 
		{
			int p=power[i];
			if(p>=i) dp[i]=1;
			else dp[i]=dp[i-p-1]+1;
		}
		else dp[i]=dp[i-1];
		ans=max(ans,dp[i]);
	}
  for (int i = 0; i <= len; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
	printf("%d\n",n-ans); 
	return 0;
}
