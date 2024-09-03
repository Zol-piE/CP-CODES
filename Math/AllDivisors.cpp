#include<iostream>
#include<math.h>
using namespace std;
void divisors(int n)
{
    int i;
    for(i=1;i*i<n;i++)
    {
        if(n%i==0) cout<<i<<" ";
    }
    for(int i = sqrt(n);i>=1;i--)
    {
        if(n%i==0) cout<<n/i<<" ";
    }
    cout<<endl;
}
int main()
{
    divisors(16);
    divisors(18);
    return 0;
}
