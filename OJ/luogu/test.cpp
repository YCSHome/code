#include <cstdio>
#define Open(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define Close fclose(stdin);fclose(stdout);
int n, ans;
int x[60000], y[60000], vis[1100][1100], xs[1100][1100];
int main(){
  Open("count");
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &x[i], &y[i]);
    x[i] = (x[i] + 51) << 1; //防止负数和小数
    y[i] = (y[i] + 51) << 1;
    vis[x[i]][y[i]] = 1;
  }
  for(int i = 1; i < n; ++i)
    for(int j = i + 1; j <= n; ++j){
      int midx = (x[i] + x[j]) / 2;
      int midy = (y[i] + y[j]) / 2;            
      int x1 = midx - (midy - y[i]), y1 = midy + (midx - x[i]);
      int x2 = midx + (midy - y[i]), y2 = midy - (midx - x[i]);
      if(x1 <= 0) continue; if(x2 <= 0) continue;
      if(y1 <= 0) continue; if(y2 <= 0) continue; 
      if(vis[x1][y1] && vis[x2][y2]) ++ans;
    }
  printf("%d\n", ans >> 1);
  return 0;
}
