#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool checkBit(int n,int k)
{
    return (n>>k) & 1;
}
void CheckON_OFF_Bit(int n,int &on,int &off)
{
    for(int i =0;i<32;i++)
    {
        ((n>>i) & 1 ) ? on++ : off++;
    }
}
bool checkEven(int n)
{
    if(n & 1) return false;
    return true;
}
int turnOnBit(int n,int k)
{
    return n | (1<<k);
}
int turnOFFBit(int n,int k)
{
    return n & (~(1<<k));
}
bool CheckIsThePowerTwo(int n)
{
    int on =0,off = 0;
    CheckON_OFF_Bit(n,on,off);
    return (on == 1);
}
signed main()
{
    int on =0 ,off =0;
    CheckON_OFF_Bit(11,on,off);
    cout<<"Check number ON And OFF Bit Of "<<11<<" "<<on<<" "<<off<<endl;

    on =0 ; off =0;
    CheckON_OFF_Bit(15,on,off);
    cout<<"Check number ON And OFF Bit Of "<<15<<" "<<on<<" "<<off<<endl;
    cout<<"find 11 Check if 2 th bit is on Or OFF "<< checkBit(11,2)<<endl;
    cout<<"find 15 Check if 3 th bit is on Or OFF "<< checkBit(15,3)<<endl;
    cout<<"find 15 Check if 4 th bit is on Or OFF "<< checkBit(15,4)<<endl;

    cout<<"15 is Even Or Odd "<<checkEven(15)<<endl;
    cout<<"8 is Even Or Odd "<<checkEven(8)<<endl;

    cout<<"Turn On the 2nd bit of 11 Number Becomes "<<turnOnBit(11,2)<<endl;
    cout<<"Turn On the 4nd bit of 15 Number Becomes "<<turnOnBit(15,4)<<endl;
    cout<<"Turn Off the 4th bit of 11 Number becomes "<<turnOFFBit(11,3)<<endl;
    cout<<"Turn Off the 4th bit of 15 Number becomes "<<turnOFFBit(15,2)<<endl;
    cout<<"Check if number 3 is Power Of Two "<<CheckIsThePowerTwo(3)<<endl;
    cout<<"Check if number 8 is Power Of Two "<<CheckIsThePowerTwo(8)<<endl;



}

