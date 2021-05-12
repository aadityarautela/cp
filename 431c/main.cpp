#include <bits/stdc++.h>
using namespace std;

//Helpful shortcuts
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (ll i = a; i < b; i++)
#define IREP(i, a, b) for (ll i = a; i > b; i--)

static const ll modval = 1000000007;

ll calculate(ll n, ll k, ll d, vector<vector<ll>> &memo_table)
{
    // cout << "n=" << n << " k=" << k << " d=" << d << endl;
    if (n == 0 and d == 1)
    {
        // cout << "1" << endl;
        memo_table[n][d] = 1 % modval;
        return 1 % modval;
    }
    else if (n == 0 and d > 1)
    {
        // cout << "0" << endl;
        memo_table[n][d] = 0 % modval;

        return 0 % modval;
    }
    else if (n < d)
    {
        // cout << "0" << endl;
        memo_table[n][d] = 0 % modval;

        return 0 % modval;
    }
    else if (memo_table[n][d] != -1)
    {
        // cout << memo_table[n][d] << endl;

        return memo_table[n][d] % modval;
    }
    else
    {
        ll sum = 0;
        REP(i, 0, d - 1)
        {
            memo_table[n - (i + 1)][d] = calculate(n - (i + 1), k, d, memo_table);
            sum += memo_table[n - (i + 1)][d] % modval;
        }
        REP(i, d - 1, min(n, k))
        {
            memo_table[n - (i + 1)][1] = calculate(n - (i + 1), k, 1, memo_table);
            sum += memo_table[n - (i + 1)][1] % modval;
        }
        memo_table[n][d] = sum % modval;
        // cout << sum << endl;

        return sum % modval;
    }
}

int main()
{
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Start writing code here
    ll n, k, d;
    cin >> n >> k >> d;
    vector<vector<ll>> memo_table(101, vector<ll>(101, -1));
    cout << calculate(n, k, d, memo_table) % modval << endl;
    return 0;
}
