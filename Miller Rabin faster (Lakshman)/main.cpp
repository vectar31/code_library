#include<bits/stdc++.h>
using namespace std;
#define i64 long long
i64 mul(i64 a,i64 b,i64 c);
i64 mod(i64 a,i64 b,i64 c){
    i64 x=1,y=a;
    while(b){
        if(b&1){
            x=mul(x,y,c);
        }
        y = mul(y,y,c);
        b>>=1;
    }
    return x;
}

i64 mul(i64 a,i64 b,i64 c){
    i64 x = 0,y=a%c;
    while(b > 0){
        if(b&1){
            x = (x+y);x>=c?x-=c:x;
        }
        y = (y<<1);y>=c?y-=c:y;
        b>>=1;
    }
    return x;
}

bool Miller(i64 p,i64 it=6){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    i64 s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(i64 i=0;i<it;i++){
        i64 a=rand()%(p-1)+1,tt=s;
        i64 md=mod(a,tt,p);
        while(tt!=p-1 && md!=1 && md!=p-1){
            md=mul(md,md,p);
            tt *= 2;
        }
        if(md!=p-1 && tt%2==0){
            return false;
        }
    }
    return true;
}
i64 nextPrime(i64 n){
        n++; if((n&1LL)==0)n++;
        while(true)
        {
            if(Miller(n)){
               return n;
            }
            n+=2;
        }
    return 0;
}
int main(){
	i64 n;
	cin >> n;
	cout << nextPrime(n) << endl;
}
