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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n + 2, vector<char>(m + 2, '.'));
    int rip_pigs = 0;
    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> grid[i][j];
        }
    }

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (grid[i][j] == 'W')
            {
                if (grid[i - 1][j] == 'P')
                {
                    rip_pigs++;
                    grid[i][j] = '.';
                    grid[i - 1][j] = '.';
                    continue;
                }
                else if (grid[i + 1][j] == 'P')
                {
                    rip_pigs++;
                    grid[i][j] = '.';
                    grid[i + 1][j] = '.';
                    continue;
                }
                else if (grid[i][j - 1] == 'P')
                {
                    rip_pigs++;
                    grid[i][j] = '.';
                    grid[i][j - 1] = '.';
                    continue;
                }
                else if (grid[i][j + 1] == 'P')
                {
                    rip_pigs++;
                    grid[i][j] = '.';
                    grid[i][j + 1] = '.';
                    continue;
                }
            }
        }
    }
    cout << rip_pigs << endl;

    return 0;
}
