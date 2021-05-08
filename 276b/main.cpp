#include <bits/stdc++.h>
using namespace std;

//Helpful shortcuts
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (ll i = a; i < b; i++)
#define IREP(i, a, b) for (ll i = a; i > b; i--)

int letter_to_index(char letter)
{
    return (int)letter - (int)'a';
}

bool is_reordered_palindrome(vector<int> &letter_map)
{
    int odd_count = 0;

    for (auto x : letter_map)
    {
        if (x % 2 == 1)
            odd_count++;
    }

    return odd_count < 2;
}

void play_optimal(vector<int> &letter_map)
{
    bool removed_even_letter = false;
    REP(i, 0, 26)
    {
        if (letter_map[i] % 2 == 0 && letter_map[i] > 0)
        {
            letter_map[i]--;
            removed_even_letter = true;
            break;
        }
    }
    if (!removed_even_letter)
    {
        REP(i, 0, 26)
        {
            if (letter_map[i] > 0)
            {
                letter_map[i]--;
                break;
            }
        }
    }
}

int main()
{
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Start writing code here
    string str;
    cin >> str;
    vector<int> letter_map(26, 0);

    REP(i, 0, str.size())
    {
        letter_map[letter_to_index(str[i])]++;
    }

    REP(i, 1, str.size() + 1)
    {
        if (is_reordered_palindrome(letter_map))
        {
            string message = i % 2 == 1 ? "First\n" : "Second\n";
            cout << message;
            break;
        }
        play_optimal(letter_map);
    }
    return 0;
}
