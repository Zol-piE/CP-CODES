#include<iostream>
using namespace std;
int power(int a,int n)
{
    if(n==0) return 1;
    int res = power(a,n/2);
    res *=res;
    if(n%2==0) return res;
    else return res*a;
}
int bitPower(int a,int n) //O(long(n))
{
    int res =1;
    while(n>0)
    {
        if(n&1)
        {
            res*=a;
        }
        a*=a;
        n/=2;
    }
    return res;
}
int main()
{
    cout<<power(3,5)<<endl;
    cout<<bitPower(3,5)<<endl;
    return 0;
}
