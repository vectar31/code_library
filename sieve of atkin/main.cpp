#include <bits/stdc++.h>
#define N 100000010
using namespace std;
bool sieve[N]={0};
void SieveOfAtkin(int limit)
{
    // 2 and 3 are known to be prime
    if (limit > 2)  cout << 2 << " ";
    if (limit > 3)  cout << 3 << " ";

    // Initialise the sieve array with false values


    /* Mark siev[n] is true if one of the following is true:
     a) n = (4*x*x)+(y*y) has odd number of solutions, i.e., there exist
        odd number of distinct pairs (x, y) that satisfy the equation and
        n % 12 = 1 or n % 12 = 5.
     b) n = (3*x*x)+(y*y) has odd number of solutions and n % 12 = 7
     c) n = (3*x*x)-(y*y) has odd number of solutions, x > y and n % 12 = 11 */
    for (int x = 1; x*x < limit; x++)
    {
        for (int y = 1; y*y < limit; y++)
        {
            // Main part of Sieve of Atkin
            int n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;

            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;

            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] ^= true;
        }
    }

    // Mark all multiples of squares as non-prime
    for (int r = 5; r*r < limit; r++)
    {
        if (sieve[r])
        {
            for (int i = r*r; i < limit; i += r*r)
                sieve[i] = false;
         }
    }

     //Print primes using sieve[]
    for (int a = 5; a < limit; a++)
        if (sieve[a])
           cout << a << " ";
}
int main()
{
    clock_t beg = clock();
  int n=100000;
    SieveOfAtkin(n);
  clock_t end = clock();
  printf("%.8lf sec.\n", double(end - beg) / CLOCKS_PER_SEC);
  system ("pause");


    return 0;
}
