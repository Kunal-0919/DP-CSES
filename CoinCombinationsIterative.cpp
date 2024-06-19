#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
}

ll mod = 1e9 + 7;

int main()
{
    setIO();
    ll n, k;
    vl arr;
    cin >> n >> k;
    arr.assign(n, 0);
    for (auto &x : arr)
    {
        cin >> x;
    }
    vl dp(k + 1, 0);
    dp[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            if (arr[i] <= j)
            {
                dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
            }
        }
    }
    cout << dp[k] << endl;
}
