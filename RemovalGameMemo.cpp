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
    // if (sz(name))
    // {
    // freopen((name + ".in").c_str(), "r", stdin);
    // freopen((name + ".out").c_str(), "w", stdout);
    // }
}

const ld pi = 3.14159265358979323846;
ll mod = 1e9 + 7;

ll n;
vl arr;
vector<vvl> dp;
ll f(ll i, ll j, ll turn)
{
    if (i > j)
        return 0;
    if (i == j && turn)
    {
        return arr[i];
    }
    if (dp[i][j][turn] != -1)
        return dp[i][j][turn];
    if (turn)
    {
        ll l = f(i + 1, j, 0) + arr[i];
        ll r = f(i, j - 1, 0) + arr[j];
        return dp[i][j][1] = max(l, r);
    }
    else
    {
        ll l = f(i + 1, j, 1);
        ll r = f(i, j - 1, 1);
        return dp[i][j][0] = max(l, r);
    }
}
void solve()
{
    cin >> n;
    arr.assign(n, 0);
    ll sm = 0;
    for (auto &x : arr)
    {
        cin >> x;
        sm += x;
    }
    dp.assign(n + 1, vvl(n + 1, vl(2, -1)));
    cout << f(0, n - 1, 1) << endl;
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
