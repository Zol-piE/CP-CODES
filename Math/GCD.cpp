#include<iostream>
using namespace std;
int nGCD(int a, int b)
{
    int res = min(a,b);
    while(res>0)
    {
        if(a%res==0 && b%res==0) return res;
        res--;
    }
    return res;
}
int eGCD(int a ,int b)
{
    while(a!=b)
    {
        if(a>b) a=a-b;
        else b= b-a;
    }
    return a;
}
int GCD(int a,int b) //  O(log(min(a,b))
{
    if(b==0) return a;
    return GCD(b,a%b);
}
int LCM(int a,int b)
{
    return (a*b) / GCD(a,b);
}
int main()
{
    int a=4,b=6;
    cout<<nGCD(a,b)<<endl;
    cout<<eGCD(a,b)<<endl;
    cout<<GCD(a,b)<<endl;
    cout<<LCM(a,b)<<endl;
    return 0;
}
