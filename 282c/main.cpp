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
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size())
    {
        cout << "NO" << endl;
    }
    else if (a.size() == 1)
    {
        if (a == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        int zero_count_a = count(a.begin(), a.end(), '0');
        int zero_count_b = count(b.begin(), b.end(), '0');
        if (zero_count_a == a.size() && zero_count_b != b.size())
        {
            cout << "NO" << endl;
        }
        else if (zero_count_a != a.size() && zero_count_b == b.size())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
