#include <bits/stdc++.h>
using namespace std;

//Helpful shortcuts
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (ll i = a; i < b; i++)
#define IREP(i, a, b) for (ll i = a; i > b; i--)

enum Cube
{
    RED,
    BLUE
};

pair<ll, ll> optimal_play(vector<Cube> &cube_line, ll n, ll m)
{
    ll loop_size = n + m;
    cube_line[0] == Cube::RED ? n-- : m--;
    ll petya = 0, vasya = 0;
    REP(i, 1, loop_size)
    {
        if (i % 2 == 1)
        {
            // Vasya's Turn
            Cube last_cube = cube_line[i - 1];
            if (last_cube == Cube::RED)
            {
                if (m > 0)
                {
                    // Blue Cubes Exist
                    cube_line[i] = Cube::BLUE;
                    m--;
                    vasya++;
                }
                else
                {
                    // Blue Cubes Do Not Exist
                    cube_line[i] = Cube::RED;
                    n--;
                    petya++;
                }
            }
            else if (last_cube == Cube::BLUE)
            {
                if (n > 0)
                {
                    // Red Cubes Exist
                    cube_line[i] = Cube::RED;
                    n--;
                    vasya++;
                }
                else
                {
                    // Red Cubes Do Not Exist
                    cube_line[i] = Cube::BLUE;
                    m--;
                    petya++;
                }
            }
        }

        else
        {
            // Petya's Turn
            Cube last_cube = cube_line[i - 1];
            if (last_cube == Cube::BLUE)
            {
                if (m > 0)
                {
                    // Blue Cubes Exist
                    cube_line[i] = Cube::BLUE;
                    m--;
                    petya++;
                }
                else
                {
                    // Blue Cubes Do Not Exist
                    cube_line[i] = Cube::RED;
                    n--;
                    vasya++;
                }
            }
            else if (last_cube == Cube::RED)
            {
                if (n > 0)
                {
                    // Red Cubes Exist
                    cube_line[i] = Cube::RED;
                    n--;
                    petya++;
                }
                else
                {
                    // Red Cubes Do Not Exist
                    cube_line[i] = Cube::BLUE;
                    m--;
                    vasya++;
                }
            }
        }
    }
    return make_pair(petya, vasya);
}

int main()
{
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Start writing code here
    ll n, m;
    cin >> n >> m;
    vector<Cube> b_first(n + m);
    vector<Cube> r_first(n + m);
    b_first[0] = Cube::BLUE;
    r_first[0] = Cube::RED;

    pair<ll, ll> score_b_first = optimal_play(b_first, n, m);
    pair<ll, ll> score_r_first = optimal_play(r_first, n, m);

    if ((score_b_first.first - score_b_first.second) > (score_r_first.first - score_r_first.second))
    {
        cout << score_b_first.first << " " << score_b_first.second << endl;
    }
    else
    {
        cout << score_r_first.first << " " << score_r_first.second << endl;
    }
    
    return 0;
}
