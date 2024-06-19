#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
}

const ld pi = 3.14159265358979323846;
ll mod = 1e9 + 7;

void solve()
{
    ll n, k;
    vl arr;
    cin >> n >> k;
    arr.assign(n, 0);
    for (auto &x : arr)
    {
        cin >> x;
    }
    vvl dp(n + 1, vl(k + 1, 1e9));
    for (ll i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] = min(dp[i][j], dp[i][j - arr[i - 1]] + 1);
        }
    }
    if (dp[n][k] >= 1e9)
        cout << -1 << endl;
    else
        cout << dp[n][k] << endl;
}

int main()
{
    setIO();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
