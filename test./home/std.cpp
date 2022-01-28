#include<bits/stdc++.h>
using namespace std;
const int N=1000010,M=200000+10;
struct Edge{
    int v,w,nxt;
}e[M];
int head[N];
int n,m,s,cnt;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
int dis[N];
void addEdge(int u,int v,int w) {
    e[++cnt]=(Edge){v,w,head[u]},head[u]=cnt;
}
void dijkstra(){
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    Q.push(make_pair(0,s));
    while(!Q.empty()){
        int d=Q.top().first;
        int u=Q.top().second;
        Q.pop();
        if(d!=dis[u]) continue;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,w=e[i].w;
            if(max(dis[u],w)<dis[v]) dis[v]=max(dis[u],w),Q.push(make_pair(dis[v],v));
        }
    }
}
int main(){
    int end;
    cin>>n>>m>>s>>end;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    dijkstra();
    cout<<dis[end];

    return 0;
}
