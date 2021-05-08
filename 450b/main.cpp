#include <bits/stdc++.h>
using namespace std;

//Helpful shortcuts
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (ll i = a; i < b; i++)
#define IREP(i, a, b) for (ll i = a; i > b; i--)

ll mod(ll a, ll b)
{
    ll result = a % b >= 0 ? a % b : a % b + b;
    return result;
}

int main()
{
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Start writing code here
    ll x, y, n;
    cin >> x >> y;
    cin >> n;

    ll mod6n = n % 6;

    switch (mod6n)
    {
    case 1:
        cout << mod(x, 1000000007) << endl;
        break;
    case 2:
        cout << mod(y, 1000000007) << endl;
        break;
    case 3:
        cout << mod((y - x), 1000000007) << endl;
        break;
    case 4:
        cout << mod((-x), 1000000007) << endl;
        break;
    case 5:
        cout << mod((-y), 1000000007) << endl;
        break;
    case 0:
        cout << mod((x - y), 1000000007) << endl;
        break;
    }
    return 0;
}
