#include <stdio.h>
#define max(x, y) (x > y ? x : y)
int n, V, box[10000];
int f[200000];
int main() {
  scanf("%d%d", &V, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &box[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = V; j >= box[i]; j--) {
      f[j] = max(f[j], f[j - box[i]] + box[i]);
    }
  }
  printf("%d", V - f[V]);
}
