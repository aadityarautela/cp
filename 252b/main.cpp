//TODO

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_set<long long> set_a(a.begin(), a.end());

    if (n <= 2)
    {
        cout << "-1" << endl;
    }
    else if (n == 3 && (a[0] == a[2]))
    {
        cout << "-1" << endl;
    }
    else if (set_a.size() == 1)
    {
        cout << "-1" << endl;
    }
    else
    {
        int max_idx = distance(a.begin(), max_element(a.begin(), a.end()));
        int min_idx = distance(a.begin(), min_element(a.begin(), a.end()));
        int pos_i = -1, pos_j = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((a[i] != a[j]) && !(j == 1 && (j == max_idx || j == min_idx) && n>3))
                {
                    pos_i = i;
                    pos_j = j;
                    cout << pos_i+1 << " " << pos_j+1 << endl;
                    return 0;
                }
            }
        }
        cout << "-1" << endl;
    }
    return 0;
}