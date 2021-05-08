#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <utility>
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
    cin >> n;
    vll narr(n);
    vll::iterator viter1, viter2;
    REP(i, 0, n)
    cin >> narr[i];
    cin >> k;
    vector<ii> queries(k);
    int f, s;
    REP(i, 0, k)
    {
        cin >> f >> s;
        queries[i] = make_pair(f, s);
    }
    sort(narr.begin(), narr.end());
    REP(i, 0, k)
    {
        f = queries[i].first;
        s = queries[i].second;
        viter1 = lower_bound(narr.begin(), narr.end(), f);
        viter2 = lower_bound(narr.begin(), narr.end(), s);
        auto fthere = binary_search(narr.begin(), narr.end(), f);
        auto sthere = binary_search(narr.begin(), narr.end(), s);
        auto both_there = fthere && sthere;
        cout << distance(viter1, viter2) + fthere + sthere - both_there << endl;
    }
    return 0;
}
