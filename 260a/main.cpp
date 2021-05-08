#include <bits/stdc++.h>
using namespace std;

//Helpful shortcuts
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (ll i = a; i < b; i++)
#define IREP(i, a, b) for (ll i = a; i > b; i--)

ll extend_a(ll a, ll b)
{
    if (a == -1)
    {
        return -1;
    }
    else
    {
        REP(i, 0, 10)
        {
            if ((a * 10 + i) % b == 0)
            {
                return (a * 10 + i);
            }
        }
        return -1;
    }
}

int main()
{
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Start writing code here
    ll a, b, n;
    cin >> a >> b >> n;

    a = extend_a(a, b);
    if (a == -1 || n == 1)
    {
        cout << a << endl;
    }
    else
    {
        string stra = to_string(a);
        stra.append(n - 1, '0');
        cout << stra << endl;
    }
    return 0;
}
