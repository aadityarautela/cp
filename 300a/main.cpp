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
    vll a(n);
    ll pos_idx = -1;
    ll neg_idx = -1;
    REP(i, 0, n)
    {
        cin >> a[i];
        if (a[i] > 0 && pos_idx == -1)
        {
            pos_idx = i;
        }
        if (a[i] < 0 && neg_idx == -1)
        {
            neg_idx = i;
        }
    }

    if (pos_idx == -1)
    {
        ll neg_2idx = -1;
        REP(i, 0, n)
        {
            if (a[i] < 0 && i != neg_idx)
            {
                neg_2idx = i;
            }
        }
        ll neg_3idx = -1;
        REP(i, 0, n)
        {
            if (a[i] < 0 && i != neg_idx && i != neg_2idx)
            {
                neg_3idx = i;
            }
        }

        cout << "1 " << a[neg_idx] << endl;
        cout << "2 " << a[neg_2idx] << " " << a[neg_3idx] << endl;
        cout << n - 3 << " ";
        REP(i, 0, n)
        {
            if (i != neg_idx && i != neg_3idx && i != neg_2idx)
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
        return 0;
    }

    cout << "1 " << a[neg_idx] << endl;
    cout << "1 " << a[pos_idx] << endl;
    cout << n - 2 << " ";
    REP(i, 0, n)
    {
        if (i != neg_idx && i != pos_idx)
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
