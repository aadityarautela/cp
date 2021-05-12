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
    int a, b;
    cin >> a;
    cin >> b;

    string sa = to_string(a);
    string sb = to_string(b);
    string sc = to_string(a + b);
    string stra = "";
    string strb = "";
    string strc = "";

    REP(i, 0, sa.size())
    {
        if (sa[i] != '0')
            stra.push_back(sa[i]);
    }

    REP(i, 0, sb.size())
    {
        if (sb[i] != '0')
            strb.push_back(sb[i]);
    }

    REP(i, 0, sc.size())
    {
        if (sc[i] != '0')
            strc.push_back(sc[i]);
    }

    if (stoi(stra) + stoi(strb) == stoi(strc))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
