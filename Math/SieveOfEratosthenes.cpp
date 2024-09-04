#include<iostream>
using namespace std;
void printPrime(int n)
{
    bool arr[n+1];
    fill(arr,arr+n+1,true);
    for(int i=2;i*i<=n;i++)
    {
        if(arr[i])
        {
            for(int j = i*i;j<=n;j+=i)
            {
                arr[j] = false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(arr[i]) cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    printPrime(10);
    printPrime(31);
    return 0;
}
