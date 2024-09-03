#include<iostream>
using namespace std;
int TrailZero(int n) //O(log(n))
{
    int res =0;
    for(int i=5;i<=n;i*=5)
    {
        res+=n/i;
    }
    return res;
}

int main()
{
    int n;
    while(cin>>n && n!=-1) cout<<TrailZero(n)<<endl;

    return 0;
}
