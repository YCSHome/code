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
int n,m,mods;
inline int inc(int x,int y){
    sky (x+=y)>=mods?x-mods:x;
}
inline int dec(int x,int y){
    sky (x-=y)<0?x+mods:x;
}
inline int mul(int x,int y){
    sky 1ll*x*y%mods;
}
const int N=1e6+3;
int fa[N];
int re[N];
int find(int x){
    if(x==fa[x]) return x;
    int f=fa[x];
    fa[x]=find(f);
    re[x]=inc(re[x],re[f]);
    return fa[x];
}
int main(){
    read(n);read(m);read(mods);
    for(int op=1;op<=m;++op){
        int l,r,k;
        read(l);read(r);read(k);
        
    }
    sky 0;
}