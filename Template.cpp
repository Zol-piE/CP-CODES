#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define in(n) int n ; cin>>n;
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
#define rep(a,b) for(int i =a;i<b;i++)
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
signed main()
{
    
    in(n)
    vector<int> arr(n,0);
    rep(0,n) cin>>arr[i];
    in(k)
    int j = -1;
    rep(0,n)
    {
    	if(arr[i] == k)
    	{
    		j  = i;
    		break;
    	}
    }
    cout<<j<<endl;
    return 0;
}