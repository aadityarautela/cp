#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a{1, 2, 3, 4, 5};
    int b=0;
    b = accumulate(a.begin() + 1, a.begin() + 3, 0) + accumulate(a.begin() + 2, a.begin() + 4, 0);
    cout << b << endl;
    return 0;
}