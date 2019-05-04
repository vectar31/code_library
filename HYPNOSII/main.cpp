#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int happy[111] = {
  1,  7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97,100,103,109,129,130,133,139,167,176,188,190,192,193,203,208,219,226,230,
236,239,262,263,280,291,293,301,302,310,313,319,320,326,329,331,338,356,362,365,367,368,376,379,383,386,391,392,397,404,409,440,446,464,469,478,487,
490,496,536,556,563,565,566,608,617,622,623,632,635,637,638,644,649,653,655,656,665,671,673,680,683,694,700,709,716,736,739,748,761,763,784,790,793
};

bool flag[800];
inline unsigned inp()
{
        unsigned z=0;
        char c;
        do{ c=getchar_unlocked(); } while(c<'0');
        for(;c>='0';c=getchar_unlocked()) z = (z<<3) + (z<<1) + (c&15);
        return z;
}

inline void print(unsigned n) {
  char stack[20];
  int top = 0;
  if(n == 0) {
    putchar_unlocked('0');
  } else {
    while(n > 0) {
      stack[top++] = n % 10 + '0';
      n /= 10;
    }
    while(top > 0) {
      putchar_unlocked(stack[--top]);
    }
  }
  putchar_unlocked('\n');
}
inline int next(int n) {
	int ret = 0, m;
	while(n) {
		m = n % 10;
		n /= 10;
		ret += m * m;
	}
	return ret;
}

inline int fill(int n) {
	int ret = 0;
	while(n != 1) {
		n = next(n);
		ret++;
	}
	return ret;
}

inline void calc() {
	for(int i = 110; i; i--) {
		flag[happy[i]] = 1;
	}
}

int main()
{
    calc();
    int t;
    cin>>t;
    while(t--)
    {
        int n,s,f;
        n=inp();
        f = (n > happy[110]);
        if(f) s = next(n);
        else s = n;
        if(!flag[s])
        {
            putchar_unlocked('-');
            putchar_unlocked('1');
            putchar_unlocked('\n');
        }
        else
        {
            int ans=(fill(s) + f);
            print(ans);
        }
    }
	return 0;
}
