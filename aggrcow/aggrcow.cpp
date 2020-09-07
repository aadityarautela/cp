#include <bits/stdc++.h>
using namespace std;

//Helpful shortcuts
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (ll i = a; i < b; i++)
#define IREP(i, a, b) for (ll i = a; i > b; i--)

bool solve(vll& arr, const ll c, const ll dist)
{
    ll cows = 1;
    ll init = arr[0];
    vll::iterator next_cow;
    REP(i, 0, c - 1)
    {
        next_cow = lower_bound(arr.begin(), arr.end(), init + dist);
        if (next_cow != arr.end()) {
            cows++;
            init = *next_cow;
        } else
            return false;
    }

    return true;
}

int main()
{
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Start writing code here
    ll t;
    cin >> t;
    vll solns;
    while (t--) {
        ll n, c;
        cin >> n >> c;
        vll arr(n);
        REP(i, 0, n)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        ll mid_val = arr[0] + (arr[n - 1] - arr[0]) / 2;
        ll low_val = arr[0];
        ll high_val = arr[n - 1];

        while (mid_val != low_val && mid_val != high_val) {
            if (solve(arr, c, mid_val)) {
                low_val = mid_val;
                mid_val = low_val + (high_val - low_val) / 2;
            } else {
                high_val = mid_val;
                mid_val = low_val + (high_val - low_val) / 2;
            }
        }
        solns.push_back(mid_val);
    }
    for (auto element : solns)
        cout << element << "\n";

    return 0;
}
