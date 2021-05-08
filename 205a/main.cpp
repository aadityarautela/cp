#include <bits/stdc++.h>
using namespace std;

//Helpful shortcuts
typedef long long ll;
typedef vector<ll> vll;

int main()
{
    ll n;
    cin >> n;
    vll t(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    bool repeating = false;
    ll small_idx = -1;
    ll small_value = 2000000000;

    for (ll i = 0; i < n; i++)
    {
        if (t[i] < small_value)
        {
            small_value = t[i];
            small_idx = i + 1;
            repeating = false;
            continue;
        }
        else if (t[i] == small_value)
        {
            repeating = true;
        }
    }

    if (repeating)
    {
        cout << "Still Rozdil" << endl;
    }
    else
    {
        cout << small_idx << endl;
    }

    return 0;
}
