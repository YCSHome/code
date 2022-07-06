#include <iostream>
#define ll long long
using namespace std;
long long read(){
	long long x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void write(long long x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=3e5+10;
int n,k;
ll b[N],a[N],ad[N],sum[N],len,ans;
void add(int l,int r,ll v){//分块的区间修改 
	int kl=l/len,kr=r/len;
	if(kl==kr){
		for(int i=l;i<=r;i++){
			a[i]+=v;
			sum[kl]+=v;
		}
		return;
	}
	for(int i=l;i<=kl*len+len-1;i++){
		a[i]+=v;
		sum[kl]+=v;
	}
	for(int i=kl+1;i<kr;i++){
		ad[i]+=v;
		sum[i]+=len*v;
	}
	for(int i=kr*len;i<=r;i++){
		a[i]+=v;
		sum[kr]+=v;
	}
}
ll ask(int l,int r){//分块的区间求和 
	ll ans=0;
	int kl=l/len,kr=r/len;
	if(kl==kr){
		for(int i=l;i<=r;i++)
			ans+=a[i]+ad[kl];
		return ans;
	}
	for(int i=l;i<=kl*len+len-1;i++)
		ans+=a[i]+ad[kl];
	for(int i=kl+1;i<kr;i++)
		ans+=sum[i];
	for(int i=kr*len;i<=r;i++)
		ans+=a[i]+ad[kr];
	return ans;
}
int main(){
	n=read();k=read();
	len=sqrt(n);
	for(int i=1;i<=n;i++){
		b[i]=read();
    int t = 0 - b[i] + b[i - 1];
    cout << t << endl;
		add(i,i,0-b[i]+b[i-1]);
	}
  for (int i = 1; i <= n; i++) {
    cout << ask(1, i) << " ";
  }
  cout << endl;
	for(int i=n;i>=1;i--){
		ll v=ask(1,i);//v就是b[i] 
    cout << v << endl;
		if(v>=0)//已经满足要求就不用计算 
			continue;
		v=-v;//把负数改为正数便于计算 
		if(i>=k){
			add(i-k+1,i,(v/k)+(v%k>0));//(v/k)+(v%k>0)相当于v/k向上取整
			ans+=(v/k)+(v%k>0);
		}
		else{//边界情况 
			add(1,k,(v/i)+(v%i>0)); 
			ans+=(v/i)+(v%i>0);
		}
	}
	write(ans);
	return 0;
}
