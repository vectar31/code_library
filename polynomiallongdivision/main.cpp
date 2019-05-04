#include <bits/stdc++.h>
#define in(n) scanf("%d",&n)
using namespace std;
ifstream fin("input.txt");
    ofstream fout("output.txt");
void showcase(char c, int d, vector <int>A) {
	for (int i=0; i < d+1; i++)
			fout << c << "(" << i << ")= " << A[i] << endl;
	fout << "Degree = " << d << endl << endl;
}
int main()
{

	vector <int> N,D,d,q,r;
    int size_N, dD, dd, dq, dr , i , r1, r2;
	dD=2;
	fin>>(size_N);
	if(fin.fail()|| size_N<0)
    {
        fout<<"Wrong Order"<<endl;
        return 0;
    }
	dq = size_N-dD;q.resize(dq+1);
	dr = size_N-dD;r.resize(dr+1);
	N.resize(size_N+1);d.resize(size_N+1);D.resize(size_N+1);

	for ( i = 0; i < dD+1; i++ )in(D[i]);
	for ( i = 0; i < size_N+1; i++ )fin>>(N[i]);
	fin>>r1>>r2;
	D[0]=r1*r2;
	D[1]=-(r1+r2);
	D[2]=1;
	for( i = dD+1 ; i < size_N+1; i++ )D[i] = 0;
	for( i = 0 ; i < dq + 1 ; i++ )q[i] = 0;
	for( i = 0 ; i < dr + 1 ; i++ )r[i] = 0;
    if( size_N >= dD ) {
		while(size_N >= dD) {
			for( i = 0 ; i < size_N + 1 ; i++ )d[i] = 0;
            for( i = 0 ; i < dD + 1 ; i++ )d[i+size_N-dD] = D[i];
			dd = size_N;
			q[size_N-dD] = N[size_N]/d[dd];
			for( i = 0 ; i < dq + 1 ; i++ )d[i] = d[i] * q[size_N-dD];
			for( i = 0 ; i < size_N + 1 ; i++ )N[i] = N[i] - d[i];
			size_N--;
		}
	}
	for( i = 0 ; i < size_N + 1 ; i++ )r[i] = N[i];
	dr = size_N;
	showcase( 'q', dq, q );
	showcase( 'r', dr, r );
    return 0;
}
