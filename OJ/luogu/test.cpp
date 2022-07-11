#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int j=1,n,q,number[110000],father[110000],ans[110000];
struct kind{
  int start;
  int end;
  int w;
}bian[110000];
struct kind2  
{
  int k;
  int v;
  int id;
}ask[110000];
int cmp(kind x,kind y){ return x.w>y.w; }
int cmp2(kind2 x,kind2 y){ return x.k>y.k; }
int getfather(int x) //寻找x的父节点 
{
  if (father[x]!=x) father[x]=getfather(father[x]);
  return father[x];
}
void onion(int x,int y)
{
  x=getfather(x);
  y=getfather(y);
  if (x!=y)
  {
    father[x]=y;  //合并父节点就把它们合并啦啦啦 
    number[y]+=number[x];  //父亲又多了几个儿子哈哈 
  }
}
int main()
{
  freopen("fuck", "w", stdout);
  cin>>n>>q;
  for (int i=1;i<=n;i++) 
  { 
    father[i]=i;  
    number[i]=1;  //number[]统计连通块中的结点数量 
  }
  for (int i=1;i<n;i++) 
    cin>>bian[i].start>>bian[i].end>>bian[i].w; //读入起始点，到达点，边（连自己都觉得幼稚的数组bian[]） 
  for (int i=1;i<=q;i++) 
  {
    cin>>ask[i].k>>ask[i].v;  
    ask[i].id=i;
  }                    //“离线”操作 ，因为后面还要对询问中的k进行排序（“离线”是指读入完后再操作，“在线”是指边读入边操作） 
  sort(bian+1,bian+n+1,cmp);  //对bian[]数组进行快排，把每条边的长度从大到小排，方便后面将>=k的边连接的点进行合并 
  sort(ask+1,ask+1+q,cmp2);  //对ask[]询问数组进行快排，把询问的k从大到小排， 
  for (int i=1;i<=q;i++)   //对每个个询问进行操作 
  {
    while (j<n&&bian[j].w>=ask[i].k)  //也可以用for语句代替，不过要把bian[j].w>=ask[i].k写在 for()括号里，避免多余的操作，不然会TLE的啊
                                      //把每条>=k的边连接的点进行合并，即将符合条件的点都拉进这个连通块，那么这个连通块中所有的点都符合条件 
                                      //注意：变量j的声明一定要放在外面啊，不然会TLE，为什么呢，因为我们是把k从大做到小，k=4这个连通块里的结点肯定也符合k=3的这个条件，所以就不必要做重复的结合啦  
    {
      cout << j << endl;
      onion(bian[j].start,bian[j].end);
      j++;
    }
    ans[ask[i].id]=number[getfather(ask[i].v)];  //ans[]就是要输出的东西啦，要保证原来的输入对应输出，就需要ans[ask.id]这个东西，找到v点的父节点，那么符合条件的节点数就在number[]里面啦啦啦 
  }
  for (int i=1;i<=q;i++) cout<<ans[i]-1<<endl;  //去掉自己一个结点后输出  
  return 0;  //Yeah~~ 
}
