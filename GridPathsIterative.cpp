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
const ll MAXN = 1001;
ll mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector<string> g;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        g.PB(s);
    }
    ll dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (ll i = 1; i <= n - 1; i++)
    {
        for (ll j = 1; j <= n - 1; j++)
        {
            if (g[i][j] != '*')
            {
                dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1]) % mod);
            }
            else
                dp[i][j] = 0;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
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
