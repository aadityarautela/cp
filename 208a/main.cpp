#include <bits/stdc++.h>
using namespace std;

//Helpful shortcuts
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (ll i = a; i < b; i++)
#define IREP(i, a, b) for (ll i = a; i > b; i--)

// trim from start (in place)
static inline void ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
}

// trim from end (in place)
static inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(),
            s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}

int main()
{
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Start writing code here
    string dubstep;
    cin >> dubstep;

    auto dub_it = dubstep.find("WUB");
    while (dub_it != string::npos)
    {
        dubstep.replace(dub_it, 3, " ");
        dub_it = dubstep.find("WUB");
    }

    trim(dubstep);
    int space_count = 0;
    REP(i, 0, dubstep.size())
    {
        char ch = dubstep[i];
        if (isspace(ch))
        {
            if (space_count == 0)
            {
                space_count++;
                cout << ch;
            }
        }
        else
        {
            cout << ch;
            space_count = 0;
        }
    }
    cout << endl;
    return 0;
}
