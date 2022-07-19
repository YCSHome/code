#include<bits/stdc++.h>
using namespace std;
#define int long long

int l,r;

bool check(int le,int s,int d,int p){
	if (d == 0 && p == 1) return 0;
	if (s == 0 && p!=1) return 0;//	去前导0 
	int sum = 0;
	for (int i=1;i<=le;i++)
	  if (i == p) sum = sum*10+d;
	  else sum = sum*10+s;//造数
//	if (l<=sum && sum<=r) cout<<sum<<' '<<s<<' '<<d<<' '<<p<<' '<<le<<endl;
	return l<=sum && sum<=r;//如果符合范围
}

signed main(){
	int ans = 0;
	scanf("%lld %lld",&l,&r);
	for (int len=3; len<=17;len++)//最多17位
	  for (int Sa=0;Sa<=9;Sa++)//相同的数
	    for (int Di=0;Di<=9;Di++){//不同的数
	    	if (Sa == Di) continue;//跳过
	    	for (int ps=1;ps<=len;ps++)//枚举不太部分的数出现的位置
	    	  if (check(len,Sa,Di,ps)) ans++;
		}
	printf("%lld",ans);
}

