#include <bits/stdc++.h>
#define add(x, y) \
  asm("addl %%ebx, %%eax" \
      : "=a" (x) \
      : "a" (x), "b" (y))

#define move(x, y) \
  asm("movl %%eax, %%ebx" \
      : "=b" (y) \
      : "a" (x), "b" (y))
  

using namespace std;

// 未编写完成

int main() {
  int x = 3, y = 4;
  add(x, -5);
  asm("movl %%dl, 31h\n\t"
      "movl %%ah, 02h"
      "int 21h");
  cout << x;
  return 0;
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
int x = 3, y = 4;

__asm__("addl %%ebx, %%eax"
: "=a" (y)
: "b" (x), "a" (y));

printf("x + y = %d\n", y);
return 0;
}
*/
