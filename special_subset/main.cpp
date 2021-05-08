#include <bits/stdc++.h>
using namespace std;

int right_child(int bst_size, int index)
{
    int return_val = -1;
    2 * (index + 1) < bst_size ? return_val = 2 * (index + 1) : return_val = -1; //zero indexing
    return return_val;
}

int left_child(int bst_size, int index)
{
    int return_val = -1;
    2 * (index) + 1 < bst_size ? return_val = 2 * (index) + 1 : return_val = -1; //zero indexing
    return return_val;
}

int parent(int bst_size, int index)
{
    int return_val = -1;
    index == 0 ? return_val = ((index + 1) / 2) - 1 : return_val = -1;
    return return_val;
}

void inorder_traversal(int index, int bst_size, vector<int> &bst, vector<int> &traversed_bst)
{
    if (index >= 0 )
    {
        inorder_traversal(left_child(bst_size, index), bst_size, bst, traversed_bst);
        traversed_bst.push_back(bst[index]);
        inorder_traversal(right_child(bst_size, index), bst_size, bst, traversed_bst);
    }
}

int main()
{
    int bst_size = 0;
    cin >> bst_size;
    vector<int> bst(bst_size, 0);
    for (int i = 0; i < bst_size; i++)
        cin >> bst[i];
    vector<int> traversed_bst;
    inorder_traversal(0, bst_size, bst, traversed_bst);
    for (auto x : traversed_bst)
        cout << x << " ";
    cout << endl;
    return 0;
}