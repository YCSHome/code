#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#define ll long long
#define re register
#define il inline
#define pf(x) ((x)*(x))
#define fp(i,a,b) for(re int i=a;i<=b;i++)
#define fq(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;
const int N=50;
int n,m,a[N],s[N];
double ans=1e100,f[N][N],ysn;
il int gi()
{
  re int x=0,t=1;
  re char ch=getchar();
  while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
  if(ch=='-') t=-1,ch=getchar();
  while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
  return x*t;
}
il double work()
{
  memset(f,127,sizeof(f));
  fp(i,1,n) s[i]=s[i-1]+a[i];//注意到数列不固定，因此不能预处理
  f[0][0]=0;
  fp(i,1,n)
    fp(j,1,i)
    fp(k,0,i-1)
    f[i][j]=min(f[i][j],f[k][j-1]+pf(s[i]-s[k]-ysn));
  ans=min(ans,f[n][m]);
  return f[n][m];
}//DP处理rand出的序列
il double Rand(){return rand()%100000/100000.00;}
il void SA(re double T)
{
  double now=ans;
  while(T>1e-3)
    {
      re int x=rand()%n+1,y=rand()%n+1;
      if(x==y) continue;
      swap(a[x],a[y]);//rand出新序列
      re double  nw=work();
      if(nw<now||exp(now-nw)/T>Rand()) now=nw;//一定概率接受当前状态
      else swap(a[x],a[y]);
      T*=0.99;
    }
  fp(i,1,10000)
    {
      re int x=rand()%n+1,y=rand()%n+1;
      if(x==y) continue;
      swap(a[x],a[y]);work();swap(a[x],a[y]);
    }
}
il double Time(){return (double)clock()/CLOCKS_PER_SEC;}
int main()
{
  srand(19260817);
  n=gi();m=gi();
  fp(i,1,n) a[i]=gi();
  fp(i,1,n) ysn+=1.0*a[i]/m;
  work();
  while(Time()<0.75)//通过增加rand的次数保证正确性
    SA(10000);
  printf("%lf\n",(ans/m));
  return 0;
}
