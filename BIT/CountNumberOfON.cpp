#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
signed main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {

        int n; cin>>n;
        stack<int> st;
        int on = 0,off =0 ;
        for(int i =0;i<32;i++)
        {

            st.push(((n>>i) & 1));

            if(((n>>i) & 1)) on++;
            else off++;
        }
        while(!st.empty())
        {
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
        cout<<"ON ->"<<on<<endl;
        cout<<"OFF ->"<<off<<endl;
    }
}
