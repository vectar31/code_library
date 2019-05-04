#include <bits/stdc++.h>
using namespace std;
inline unsigned inp()
    {
        unsigned z=0;
        char c;
        do{ c=getchar_unlocked(); } while(c<'0');
        for(;c>='0';c=getchar_unlocked()) z = (z<<3) + (z<<1) + (c&15);
        return z;
    }
#define LL unsigned long long
inline LL scan()
{
	LL z=0;char c;
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
int main(){
    // add the two lines below faster than scanf
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cant use scanf and printf now
    int n, k, t;
    int cnt = 0;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> t;
        if(t % k == 0) cnt++;
    }
    cout << cnt << "\n";

    return 0;
}
