#include<iostream>
using namespace std;
void factors(int n)
{
    if(n<=1) { cout<<1<<endl; return ;}
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n/=i;
        }
    }
    if(n>1) cout<<n<<endl;
    else cout<<endl;
}
void opFactors(int n)
{
    if(n<=1) { cout<<1<<endl; return ;}
    while(n%2==0) { cout<<2<<" "; n/=2; }
    while(n%3==0) { cout<<3<<" "; n/=3; }
    for(int i=5;i*i<=n;i+=6)
    {
        while(n%i==0) { cout<<i<<" ";  n/=i; }
        while(n%(i+2)==0) { cout<<i+2<<" ";  n/=(i+2); }
    }
    if(n>3) cout<<n<<endl;
    else cout<<endl;
}
int main()
{
    factors(450);
    opFactors(450);
    return 0;
}
