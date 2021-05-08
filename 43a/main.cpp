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
    string team1 = "", team2 = "";
    int team1_goals = 0, team2_goals = 0;
    REP(i, 0, n)
    {
        string temp;
        cin >> temp;
        if (team1 == "")
        {
            team1 = temp;
            team1_goals++;
        }
        else if (temp != team1 && team2 == "")
        {
            team2 = temp;
            team2_goals++;
        }
        else if (temp == team1)
        {
            team1_goals++;
        }
        else
        {
            team2_goals++;
        }
    }

    if (team1_goals > team2_goals)
        cout << team1 << endl;
    else
        cout << team2 << endl;

    return 0;
}
