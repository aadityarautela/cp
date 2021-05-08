#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int total_drink = k * l;
    int total_lime = c * d;
    int total_salt = p;

    int toasts = 0;
    while (total_drink >= nl && total_lime >= 1 && total_salt >= np)
    {
        total_drink -= nl;
        total_lime -= 1;
        total_salt -= np;
        toasts += 1;
    }
    int toasts_per_friend = toasts / n;
    cout << toasts_per_friend << endl;
    return 0;
}