// TODO

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
    ll t;
    cin >> t;
    vector<ll> answers(t, 0);
    REP(_i, 0, t)
    {
        ll n;
        cin >> n;
        string str;
        cin >> str;
        auto sheep_count = count(str.begin(), str.end(), '*');
        if (sheep_count <= 1)
        {
            answers[_i] = 0;
        }
        else
        {
            vector<ll> spaces_till_index(n, -1);
            ll space_count = 0;
            ll sheep_index_count = 0;
            vector<ll> sheep_indices;
            ll mid_index = n / 2;

            REP(i, 0, n)
            {
                if (str[i] == '.')
                {
                    space_count++;
                }
                else
                {
                    sheep_indices.push_back(i);
                }
                spaces_till_index[i] = space_count;
            }
            ll middle_sheep_index = sheep_indices[sheep_indices.size() / 2];
            ll swaps = 0;
            for (auto sheep_index : sheep_indices)
            {
                swaps += abs(spaces_till_index[sheep_index] - spaces_till_index[middle_sheep_index]);
            }
            answers[_i] = swaps;
        }
    }

    REP(_i, 0, t)
    {
        cout << answers[_i] << endl;
    }
    return 0;
}
