#include <bits/stdc++.h>
using namespace std;

//Helpful shortcuts
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;

#define REP(i, a, b) for (ll i = a; i < b; i++)
#define IREP(i, a, b) for (ll i = a; i > b; i--)

bool is_prime(ll num)
{
    if (num < 2)
    {
        return false;
    }
    else if (num == 2 || num == 3)
        return true;
    else if (num % 2 == 0)
        return false;

    for (ll i = 3; i <= ceil(sqrt(num)); i = i + 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool is_perfect_square(double sqrt_num)
{
    return ceil(sqrt_num) == floor(sqrt_num);
}

int main()
{
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    bool is_tprime[n];
    REP(i, 0, n)
    {
        ll temp;
        cin >> temp;
        double sqrt_temp = sqrt(temp);
        if (is_perfect_square(sqrt_temp))
        {
            if (is_prime((ll)sqrt_temp))
            {
                is_tprime[i] = true;
            }
            else
            {
                is_tprime[i] = false;
            }
        }
        else
        {
            is_tprime[i] = false;
        }
    }
    REP(i, 0, n)
    {
        if (is_tprime[i])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    cout << endl;
    return 0;
}
