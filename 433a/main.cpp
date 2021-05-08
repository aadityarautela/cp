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
    int n;
    cin >> n;
    int hyaku_cnt = 0, nihyaku_cnt = 0;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 100)
            hyaku_cnt++;
        else
            nihyaku_cnt++;
    }
    if (hyaku_cnt % 2 == 1)
    {
        cout << "NO" << endl;
    }
    else if (nihyaku_cnt % 2 == 1 && hyaku_cnt == 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return 0;
}
