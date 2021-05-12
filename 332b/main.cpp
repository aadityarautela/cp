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
    ll n, k;
    cin >> n >> k;
    vll absurdities(n + 1, 0);
    vll sum_k(n - k + 2, 0);

    ll sum = 0;
    REP(i, 1, n + 1)
    {
        cin >> absurdities[i];
        sum += absurdities[i];
        if (i >= k)
        {
            sum_k[i - k + 1] = sum;
            sum -= absurdities[i - k + 1];
        }
    }
    vector<ll> a_diced;
    ll max_sum_k = 0;
    ll last_index = 0;

    for (ll i = 1; i <= n - 2 * k; i++)
    {
        if (sum_k[i] > max_sum_k || i - last_index == k)
        {
            max_sum_k = sum_k[i];
            a_diced.push_back(i);
            last_index = i;
        }
    }

    ll max_a = 1, max_b = 1 + k;
    ll max_val = 0;
    bool b_loop_flag = false;
    ll first_elem = absurdities[1];
    
    if (all_of(absurdities.begin() + 1, absurdities.end(), [first_elem](ll i) { return i == first_elem; }))
    {
        cout << max_a << " " << max_b << endl;
        return 0;
    }

    if (k == 1)
    {
        auto max_index = distance(absurdities.begin(), max_element(absurdities.begin(), absurdities.end()));
        absurdities[max_index] = -1;
        auto second_max_index = distance(absurdities.begin(), max_element(absurdities.begin(), absurdities.end()));
        if (max_index < second_max_index)
        {
            cout << max_index << " " << second_max_index << endl;
        }
        else
        {
            cout << second_max_index << " " << max_index << endl;
        }
        return 0;
    }

    if (2 * k + 1 == n)
    {
        auto first_middle = sum_k[1] + sum_k[1 + k];
        auto middle_last = sum_k[2] + sum_k[2 + k];
        auto first_last = sum_k[1] + sum_k[2 + k];

        auto largest = max({first_middle, middle_last, first_last});
        if (largest == first_middle)
            cout << 1 << " " << 1 + k << endl;
        else if (largest == first_last)
            cout << 1 << " " << 2 + k << endl;
        else
            cout << 2 << " " << 2 + k << endl;
        return 0;
    }

    for (auto a : a_diced)
    {

        if (max_b - a >= k && b_loop_flag)
        {
            if (sum_k[a] + sum_k[max_b] > max_val)
            {
                max_val = sum_k[a] + sum_k[max_b];
                max_a = a;
            }
            continue;
        }

        for (ll b = a + k; b <= n - k + 1; b++)
        {
            b_loop_flag = true;
            if (sum_k[a] + sum_k[b] > max_val)
            {
                max_val = sum_k[a] + sum_k[b];
                max_a = a;
                max_b = b;
            }
        }
    }

    cout << max_a << " " << max_b << endl;
    return 0;
}
