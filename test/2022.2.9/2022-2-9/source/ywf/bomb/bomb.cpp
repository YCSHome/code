#include<bits/stdc++.h>
using namespace std;
int n;
int l,r;
int ans;
int mid,num;
int minn=1e9;
int a[1100000];
int read(){
	int r=0,f=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-'){
		c=getchar();
	}
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		r=(r<<3)+(r<<1)+c-'0';
		c=getchar();
	}
	return r*f;
}
bool check(int now){
	int x=now,k=num;
	for(int i=num;i>=1;i--){
		while(i&&a[k]-a[i]<=x){
			i--;
		}
		if(!i){
			break;
		}
		x=x*2/3,k=i+1;
		if(a[k]-a[k-1]>x){
			return true;
		}
	}
	x=now,k=num;
	for(int i=num;i<=n;i++){
		while(i<=n&&a[i]-a[k]<=x){
			i++;
		}
		x=x*2/3,k=i-1;
		if(a[k+1]-a[k]>x){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(max(a[i]-a[1],a[n]-a[i])<minn){
			minn=max(a[i]-a[1],a[n]-a[i]);
			num=i;
		}
	}
	l=0,r=minn;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid;
			ans=r;
		}
	}
	cout<<ans;
	return 0;
}
