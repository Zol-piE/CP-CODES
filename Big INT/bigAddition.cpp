#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int chartoint(char ch)
{
    return ch- '0';
}
char inttochar(int a)
{
    return a + '0';
}
string sum(string n1,string n2)
{
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());
    if(n2.length()>n1.length()) swap(n1,n2);
    string n3 = "";
    int carry =0;
    for(int i=0;i<n2.length();i++)
    {
        int total = chartoint(n1[i])+chartoint(n2[i]) + carry;
        n3 += inttochar(total%10);
        carry = total/10;
    }
    for(int i = n2.length();i<n1.length();i++)
    {
        int total = chartoint(n1[i]) + carry;
        n3 += inttochar(total%10);
        carry = total/10;
    }
    if(carry==1) n3 += inttochar(carry);

    reverse(n3.begin(),n3.end());
    return n3;
}
using namespace std;
int main()
{
    string n1,n2;
    cin>>n1>>n2;
    string n3 = sum(n1,n2);
    cout<<n3<<endl;
    return 0;
}
