#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void multiply(vector<int> &v,int n,int siz)
{
    int carry=0;
    for(int i=0;i<siz;i++)
    {
        int total = v[i]*n + carry;
        v[i] = total %10;
        carry = total/10;
    }
    while(carry>0)
    {
        v.push_back(carry%10);
        carry/=10;
    }
}
vector<int> fact(int n)
{
    vector<int> num={1};
    for(int i=2;i<=n;i++)
    {
        multiply(num,i,num.size());
    }
    reverse(num.begin(),num.end());

    return num;

}
int main()
{
    int n; cin>>n;
    vector<int> v = fact(n);
    vector<int> ex = {9,9};
    for(auto x : v) cout<<x;
    cout<<endl;
//    multiply(ex,99,2);
//for(auto x : ex) cout<<x;
//    cout<<endl;

    return 0;
}
