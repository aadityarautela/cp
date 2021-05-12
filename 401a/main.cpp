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
    ll n, x;
    cin >> n >> x;
    vll cards(n);
    ll sum = 0;
    REP(i, 0, n)
    {
        cin >> cards[i];
        sum += cards[i];
    }
    if (abs(sum) % x == 0)
    {
        cout << abs(sum) / x << endl;
    }
    else
    {
        cout << ((abs(sum)) / x) + 1 << endl;
    }
    return 0;
}
