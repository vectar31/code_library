#include <stdio.h>
long long xorsum_1_to_x_but_1(long long x)
{
  switch (x % 4)
  {
  case 0:
    return 0;
  case 1:
    return x — 1;
  case 2:
    return 1;
  case 3:
    return x;
  }
}
int main(void)
{
  long long xorsum = 0;
  int i;
  scanf("%u",&i);
  while (i--) // repeat i times in total
  {
    long long x, m;
    scanf("%I64u%I64u", &x, &m);
    xorsum ^= xorsum_1_to_x_but_1(x) ^ xorsum_1_to_x_but_1(x + m);
  }
  puts(xorsum ? "tolik" : "bolik");
  return 0;
}
