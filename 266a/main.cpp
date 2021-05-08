#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    int count = 0;
    char curr_stone = str[0];
    for (int i = 1; i < n; i++) {
        if (str[i] == curr_stone)
            count++;
        curr_stone = str[i];
    }
    cout << count << endl;
    return 0;
}
