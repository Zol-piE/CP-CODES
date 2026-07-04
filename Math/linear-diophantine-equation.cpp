#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define yes cout << "YES\n";
#define no cout << "NO\n";
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX >> 1;
#define rep(a, b) for (ll i = (a); i < (b); i++)
#define ZolpiE ios_base::sync_with_stdio(false), cin.tie(nullptr)

ll eea(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = eea(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

bool lde(ll a, ll b, ll c, ll &x, ll &y)
{
    ll g = eea(abs(a), abs(b), x, y);

    if ((c % g) != 0)
        return false;

    x = x * (c / g);
    y = y * (c / g);

    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;

    return true;
}

signed main()
{
    ZolpiE;

    int tc;
    cin >> tc;
    while (tc--)
    {
        // Use long long for the inputs
        ll a, b, c;
        cin >> a >> b >> c;

        ll x = 0, y = 0;
        if (lde(a, b, c, x, y))
            cout << x << " " << y << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}