#include<bits/stdc++.h>
#define ll long long
#define db double
#define filein(a) freopen(#a".in","r",stdin)
#define fileot(a) freopen(#a".out","w",stdout)
#define wash fflsuh(stdout)
#define sky return 
template<class T>
inline void read(T &s){
    s=0;char ch=getchar();bool f=0;
    while(ch<'0'||'9'<ch) {if(ch=='-') f=1;ch=getchar();}
    while('0'<=ch&&ch<='9') {s=s*10+(ch^48);ch=getchar();}
    if(ch=='.'){
        db p=0.1;ch=getchar();
        while('0'<=ch&&ch<='9') {s=s+(ch^48)*p;ch=getchar();}
    }
    s=f?-s:s;
}
const int N=1e5+3;
const int inf=1e9;
struct node{
    int lx,ly;
    int rx,ry;
};
int n,m,c;
node p[N];
bool cant[N];
std::vector<std::vector<int> >col,tmp;
int main(){
    filein(paint);fileot(paint);
    read(n);read(m);read(c);
    for(int i=1;i<=c;++i){
        p[i].lx=p[i].ly=inf;
    }
    col.resize(n+3);
    for(int i=1;i<=n;++i){
        col[i].resize(m+3);
        for(int j=1;j<=m;++j){
            int x;read(x);
            col[i][j]=x;
            if(x==0) continue;
            if(i<p[x].lx){
                p[x].lx=i;
            }
            if(i>p[x].rx){
                p[x].rx=i;
            }
            if(j<p[x].ly){
                p[x].ly=j;
            }
            if(j>p[x].ry){
                p[x].ry=j;
            }
        }
    }
    if(n==1){
        int ly=0;
        for(int i=1;i<=m;++i){
            if(ly){
                if(ly==col[1][i]){
                    ly=0;
                    continue;
                }
                cant[col[1][i] ]=1;
            }else{
                if(p[col[1][i] ].ly!=p[col[1][i] ].ry)
                    ly=col[1][i];
            }
        }
        int cnt=0;
        for(int x=1;x<=c;++x){
            if(!cant[x]) ++cnt;
        }
        printf("%d\n",cnt);
        sky 0;
    }
    int cnt=0,tmp;
    for(int x=1;x<=c;++x){
        if(p[x].lx==inf) continue;
        //printf("%d\n",x);
        ++cnt;tmp=x;
        for(int i=p[x].lx;i<=p[x].rx;++i){
            for(int j=p[x].ly;j<=p[x].ry;++j){
                if(col[i][j]!=x){
                    cant[col[i][j] ]=1;
                }
            }
        }
    }
    if(cnt==1){
        cant[tmp]=1;
    }
    int ans=0;
    for(int x=1;x<=c;++x){
        if(!cant[x]) ++ans;
        //if(!cant[x]) printf("%d\n",x);
    }
    printf("%d\n",ans);
    sky 0;
}