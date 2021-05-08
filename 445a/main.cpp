#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> chessboard(n, vector<char>(m, '-'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> chessboard[i][j];
            if (chessboard[i][j] == '.')
            {
                if ((i + j) % 2 == 0)
                    chessboard[i][j] = 'B';
                else
                    chessboard[i][j] = 'W';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << chessboard[i][j];
        }
        cout << endl;
    }
    return 0;
}