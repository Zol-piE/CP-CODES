#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
#define rep(a,b) for(int i =a;i<b;i++)
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
signed main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n; cin>>n;
        vector<int> arr(n,0);
        rep(0,n) cin>>arr[i];
        cout<<"Array  : ";
        rep(0,n) cout<<arr[i]<<" ";
        cout<<endl;

        for(int mask =0;mask<(1<<n);mask++){
            for(int i =0;i<n;i++)
            {
                if((mask>>i) & 1) cout<<arr[i]<<" ";
            }
            cout<<endl;
        }


    }
}

