#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int M, N;
string pat,txt;
int lps[1000000+10];
void builtFA(){
    int i = 1;
    int len = 0;
    lps[0]  = len = 0;
        while( i < M){
        if( pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else if(len == 0){
            lps[i] = 0;
            i++;
        }
        else{
            len = lps[len-1];
        }
    }
}
void KMP(){
    bool f=false;
    int k,i;
    for( k = 0, i = 0; i < N; i++ ){
        while( k && txt[i] != pat[k] )
            k = lps[k-1];
        if(txt[i] == pat[k]) k++;
        if(k == M){
                f=true;
            cout<<i-M+1<<endl;
            k = lps[M-1];
        }
    }
    if(!f)
        cout<<endl;
}
int main()
{
    while(cin>>M){
        cin>>pat>>txt;
        N=txt.length();
        builtFA();
        KMP();
    }

	return 0;
}
