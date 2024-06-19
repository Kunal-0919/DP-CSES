#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i, a, n) for (int i = a; i <= n; i++)
#define SQ(a) (a) * (a)
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define endl '\n'
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvl;
typedef vector<vector<bool>> vvb;
typedef set<ll> si;
typedef set<ll> sl;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef priority_queue<ll> maxHeap;
typedef priority_queue<ll, vl, greater<ll>> minHeap;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const ld pi = 3.14159265358979323846;
ll mod = 1e9 + 7;
ll dp[1000001];
ll f(ll n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return 1e9;
    if (dp[n] != -1)
        return dp[n];
    string s = to_string(n);
    ll ans = 1e9;
    for (auto x : s)
    {
        ll dig = x - '0';
        if (dig == 0)
            continue;
        ans = min(ans, f(n - dig) + 1);
    }
    return dp[n] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n) << endl;
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
