#include <bits/stdc++.h>
#include <iostream>
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
    int w;
    cin >> w;
    if (w % 2 == 0 && w > 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
