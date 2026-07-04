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

// Upgraded to long long
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
    y = x1 - (a / b) * y1; // Removed floor()
    return g;
}

// Upgraded to long long
bool lde(ll a, ll b, ll c, ll &x, ll &y, ll &g)
{
    g = eea(abs(a), abs(b), x, y);
    if ((c % g) != 0)
        return false;

    x = x * (c / g); // Divide first to prevent overflow
    y = y * (c / g);

    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    return true;
}

void shift_solution(ll &x, ll &y, ll a, ll b, ll cnt)
{
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
    // Edge case: if a = 0 and b = 0, we can't divide by them later.
    if (a == 0 && b == 0)
    {
        if (c == 0)
            return (maxx - minx + 1) * (maxy - miny + 1);
        return 0;
    }

    ll x, y, g;
    // BUG FIX: Added '!' so it only returns 0 if NO solution exists
    if (!lde(a, b, c, x, y, g))
        return 0;

    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);

    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if (lx > rx)
        return 0;

    return (rx - lx) / abs(b) + 1;
}

signed main()
{
    ZolpiE;

    int tc;
    if (cin >> tc)
    {
        while (tc--)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            // BUG FIX: Swapped max and min bounds so min comes first
            cout << find_all_solutions(a, b, c, -5, 5, -5, 5) << endl;
        }
    }

    return 0;
}