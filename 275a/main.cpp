    #include <bits/stdc++.h>
    using namespace std;

    void solve(vector<vector<bool>> &lights, int toggle_count,int i, int j) {
        if(toggle_count%2 == 1) {
            lights[i][j]   = !lights[i][j]  ;
            lights[i-1][j] = !lights[i-1][j];
            lights[i+1][j] = !lights[i+1][j];
            lights[i][j-1] = !lights[i][j-1];
            lights[i][j+1] = !lights[i][j+1];
        }
    }

    int main()
    {
        vector<vector<bool>> lights(5, vector<bool>(5, 1));
        for(int i=1;i<4;i++) {
            for(int j=1;j<4;j++) {
                int toggle_count;
                cin>>toggle_count;
                solve(lights, toggle_count, i, j);
            }
        }

        for(int i=1;i<4;i++) {
            for(int j=1;j<4;j++) {
                cout<<lights[i][j];
            }
            cout<<endl;
        }
        return 0;
    }