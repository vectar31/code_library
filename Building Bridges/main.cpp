/*
1. Building Bridges: Consider a 2-D map with a horizontal river passing through its center.
There are n cities on the southern bank with x-coordinates a(1) … a(n)
and n cities on the northern bank with x-coordinates b(1) … b(n).
You want to connect as many north-south pairs of cities as possible
 with bridges such that no two bridges cross. When connecting cities,
 you can only connect city i on the northern bank to city i on the southern bank.
*/
#include <bits/stdc++.h>
using namespace std;

/*The standard function to calculate LIS*/
int LIS(int a[],int size)
{
   int lis[size]={0};

   for(int i=0;i<size;++i)
      lis[i]=1;
   for(int i=1;i<size;++i)
   {
      for(int j=0;j<i;++j)
      if(a[i]>=a[j] && lis[i]<lis[j]+1)
         lis[i]=lis[j]+1;
   }
   int maxv=lis[0];
   for(int i=1;i<size;++i)
      if(lis[i]>maxv)
         maxv=lis[i];
   return maxv;
}

int main() {

   /*Bank A and bank B values*/
   int a[]={1 ,2 ,3 ,4 ,5 ,6 ,7 ,8};
   int b[]={5, 1, 8, 3, 4, 2, 6, 7};
   int size=sizeof(a)/sizeof(a[0]);

   /*making a vector of pairs*/
   vector<pair<int,int> >v;

   /*Here the concept is to sort the 2nd array i.e according to the
   end points, so while making pair b[i] comes before a[i]*/

   for(int i=0;i<size;++i)
      v.push_back(make_pair(b[i],a[i]));

   /*Putting the bank B values allows us to apply
   sort() directly without compare()*/
   sort(v.begin(),v.end());

   /*copying bank A values to apply LIS*/
   for(int i=0;i<size;++i)
      b[i]=v[i].second;

   cout<<"The maximum number of bridges is:\n"<<LIS(b,size)<<endl;

   return 0;
}
