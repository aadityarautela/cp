#include <bits/stdc++.h>
using namespace std;

//Helpful shortcuts
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (ll i = a; i < b; i++)
#define IREP(i, a, b) for (ll i = a; i > b; i--)

int main()
{
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Start writing code here
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    ll max_swap = 0, min_swap = 0;
    max_swap = std::distance(a.begin(), max_element(a.begin(), a.end()));
    min_swap = std::distance(a.rbegin(), min_element(a.rbegin(), a.rend()));
    if (min_swap < max_swap)
    {
        min_swap--;
    }
    cout << max_swap + min_swap << endl;

    return 0;
}
