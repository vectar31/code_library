/*

Given a 3×3 grid, each grid cell is empty, or occupied by a 'X' or a '0'. T
he player who draws 'X' goes first.
Find the player (first or second), whose turn is next, or print one of the verdicts below:

illegal — if the given board layout can't appear during a valid game;
the first player won — if in the given board layout the first player has just won;
the second player won — if in the given board layout the second player has just won;
draw — if the given board layout has just let to a draw.
Input
The input consists of three lines, each of the lines contains characters ".", "X" or "0"
(a period, a capital letter X, or a digit zero).
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

char a[3][4],s[3][3];

bool check(int x,int y){
	bool h=true,v=true;
	for(int i=0;i<3;i++)
    {
		if(s[x][i]!=s[x][y])h=false;
		if(s[i][y]!=s[x][y])v=false;
	}
	if(h||v)return true;
	h=v=true;
	for(int i=0;i<3;i++)
	{
		if(s[i][i]!=s[x][y])h=false;
		if(s[2-i][i]!=s[x][y])v=false;
	}
	return v||h;
}

int main(){
	vector<pair<int,int> > p;
	for(int i=0;i<3;i++)
    {
		cin>>a[i];
		for(int j=0;j<3;j++)
            if(a[i][j]!='.')
                p.push_back({i,j});
	}
	sort(p.begin(),p.end());
	bool first=false,second=false,w=false;
	do
	{
		bool ok=true;
		char c='X',t='0';
		for(int i=0;i<p.size();i++)
		{
			int x=p[i].first,y=p[i].second;
			if(a[x][y]!=c)ok=false;
			swap(c,t);
		}
		if(ok)
		{
			(c=='X'?first:second)=true;
			for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    s[i][j]='.';
			bool won=false;
			for(int i=0;i<p.size();i++)
			{
				int x=p[i].first,y=p[i].second;
				s[x][y]=a[x][y];
				if(won){ ok = false; break; }
				if(check(x,y)) won = true;
			}
			w|=won;
			if(ok)
			{
				if(won)
				{
					puts(c=='X'?"the second player won":"the first player won");
					return 0;
				}
				else if(p.size()==9)
                {
					puts("draw");
					return 0;
				}
			}
		}
	}while(next_permutation(p.begin(),p.end()));
	if(!w && first!=second)
		puts(first?"first":"second");
	else puts("illegal");
	return 0;
}
