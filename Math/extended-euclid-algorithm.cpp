#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define yes cout << "YES\n";
#define no cout << "NO\n";
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX >> 1;
#define rep(a, b) for (ll i = (a); i < (b); i++)
#define ZolpiE                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)
ll eea(ll a, ll b, ll &x, ll &y)
{
    // Base case
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll g = eea(b, a % b, x, y);

    ll x1 = x;
    ll y1 = y;

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}
signed main()
{
    ZolpiE;

    int tc;
    cin >> tc;
    while (tc--)
    {
        ll a, b, x, y;
        cin >> a >> b;
        x = y = 0;
        cout << eea(a, b, x, y) << endl;
        cout << x << " " << y << endl;
    }

    return 0;
}
