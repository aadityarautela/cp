// 450a

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, last;
    cin>>n>>m;
    double max(0), a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (ceil(a / m) >= max)
        {
            max = ceil(a / m);
            last = i;
        }
    }
    cout << last << endl;
    return 0;
}