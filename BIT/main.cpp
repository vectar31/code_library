//https://github.com/kartikkukreja/blog-codes/blob/master/src/BIT%20or%20Fenwick%20Tree%20Data%20Structure.cpp
#include <bits/stdc++.h>
#define LSOne(S) (S & (-S))
using namespace std;
// The code of BIT is taken from Kartik Kukreja's blog
class BIT
{
	int* ft, size;
public:
	// initialize a BIT of n elements to zero
	BIT(int n) {
		size = n;
		ft = new int[n+1];
	}

	~BIT()	{
		delete [] ft;
	}

	// returns sum of the range [1...b]
	int sum(int b)
	{
		int sum = 0;
		for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	// returns sum of the range [a...b]
	int sum(int a, int b) {
		return sum(b) - (a == 1 ? 0 : sum(a - 1));
	}

	// update value of the k-th element by v (v can be +ve/inc or -ve/dec)
	// i.e., increment or decrement kth element by a value v
	void update(int k, int v)
	{
		for (; k <= size; k += LSOne(k)) ft[k] += v;
	}

    // divide each original frequency by c
	void scaleDown(int c){
        for (int i=1 ; i<=size ; i++) ft[i] /= c;
    }

    // multiply each original frequency by c
    void scaleUp(int c){
        for (int i=1 ; i<=size ; i++) ft[i] *= c;
    }
};

int main()
{
    BIT b(10);
    printf("%d\n", b.sum(10));

    b.update(5, 10);
    printf("%d %d %d %d\n", b.sum(4), b.sum(5), b.sum(10), b.sum(6, 10));

    b.scaleUp(2);
    printf("%d %d %d %d\n", b.sum(4), b.sum(5), b.sum(10), b.sum(6, 10));

    b.scaleDown(2);
    printf("%d %d %d %d\n", b.sum(4), b.sum(5), b.sum(10), b.sum(6, 10));
    return 0;
}
