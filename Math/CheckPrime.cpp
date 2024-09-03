#include<iostream>
using namespace std;

//O(sqrt(n))
bool prime(int n)
{
    if(n==1) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
// Doing one third operations of previous one
bool optPrime(int n)
{
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2 ==0 || n%3 == 0 ) return false;
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
int main()
{
    cout<<optPrime(3)<<endl;
    for(int i=2;i<=30;i++)
    {
//        cout<<"show "<<i<<" - "<<optPrime(i)<<endl;
//        cout<<"show "<<i<<" - "<<prime(i)<<endl;
//          cout<<"6n+1 = "<<(6*i+1)<<" "<<prime((6*i+1))<<"|  6n-1 = "<<(6*i-1)<<" "<<prime((6*i-1))<<endl;
            cout<<i<<" "<<(optPrime((i))==prime((i)))<<endl;
    }
    return 0;
}
