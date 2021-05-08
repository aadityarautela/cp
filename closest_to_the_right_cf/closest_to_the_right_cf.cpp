#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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
    int n, k;
    cin >> n >> k;
    vll narr(n);
    vll karr(k);
    vll::iterator viter;
    REP(i, 0, n)
    cin >> narr[i];
    REP(i, 0, k)
    cin >> karr[i];
    REP(i, 0, k)
    {
        viter = lower_bound(narr.begin(), narr.end(), karr[i]);
        if (viter == narr.end())
            cout << k + 1 << endl;
        else
            cout << distance(narr.begin(), viter) + 1 << endl;
    }
    return 0;
}
