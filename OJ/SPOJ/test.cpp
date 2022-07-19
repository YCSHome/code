#include<iostream>
#include<cstdio>
#define INF 1e9
using namespace std;

const int N=1e5+10;
const int M=5e3+10;

struct node
{
	int x,y,k,type,id;
	//修改中 x:数值, type:操作类型(1), id:在数组中的位置
	//查询中 x,y,k:输入, type:操作类型(2), id:询问编号 
};
int n,m,tot;	//tot:操作个数 
int ans[N],c[N];
node q[N+M],q1[N+M],q2[N+M];	//q:当前二分区间的操作, q1:当前二分区间的左区间的操作, q2:右区间的操作 

int lowbit(int t)
{
	return t&(-t);
}

void add(int x,int y)
{
	for(int i=x; i<=n; i+=lowbit(i))
		c[i]+=y;
}

int getsum(int x)
{
	int res=0;
	for(int i=x; i>0; i-=lowbit(i))
		res+=c[i];
	return res;
}

void solve(int ql,int qr,int L,int R)	//ql,qr:操作区间; L,R:答案区间 
{
	if(ql>qr) return;
  cout << L << " " << R << endl;
	if(L==R)	//找到答案了 
	{
		for(int i=ql; i<=qr; i++)
			if(q[i].type==2)
				ans[q[i].id]=L;
		return;
	}
	int mid=(L+R)>>1,t1=0,t2=0;
	for(int i=ql; i<=qr; i++)
	{
		if(q[i].type==1)
		{
			if(q[i].x<=mid)
			{
				add(q[i].id,1);
				q1[++t1]=q[i];
			}
			else
			{
				q2[++t2]=q[i];
			}
		}
		else	//if(q[i].type==2) 
		{
			int cnt=getsum(q[i].y)-getsum(q[i].x-1);
			if(cnt>=q[i].k)
			{
				q1[++t1]=q[i];
			}
			else
			{
				q[i].k-=cnt;
				q2[++t2]=q[i];
			}
		}
	}
	for(int i=1; i<=t1; i++)
		if(q1[i].type==1) add(q1[i].id,-1);
	for(int i=1; i<=t1; i++)
		q[ql+i-1]=q1[i];
	for(int i=1; i<=t2; i++)
		q[ql+t1+i-1]=q2[i];
	solve(ql,ql+t1-1,L,mid);
	solve(ql+t1,qr,mid+1,R);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		int x;
		scanf("%d",&x);
		tot++;
		q[tot].x=x,q[tot].type=1,q[tot].id=i;
	}
	for(int i=1; i<=m; i++)
	{
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		tot++;
		q[tot].x=x,q[tot].y=y,q[tot].k=k,q[tot].type=2,q[tot].id=i;
	}
	solve(1,tot,-INF,INF);
	for(int i=1; i<=m; i++)
		printf("%d\n",ans[i]);
	return 0;
}
