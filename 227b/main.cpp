#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main()
{
    ll n, m;
    cin >> n;
    vll DAT(1000000, 0);
    for (int i = 1; i <= n; i++)
    {
        int tmp_val;
        cin >> tmp_val;
        DAT[tmp_val] = i;
    }

    cin >> m;
    ll v = 0, p = 0;

    for (int i = 0; i < m; i++)
    {
        int query;
        cin >> query;
        v += DAT[query];
        p += n - DAT[query] + 1;
    }
    cout << v << " " << p << endl;
    return 0;
}