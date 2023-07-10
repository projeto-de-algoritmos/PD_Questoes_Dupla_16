// 1843D - Apple Tree
// https://codeforces.com/problemset/problem/1843/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dfs(vector<vector<int>> &tree, int node, vector<ll> &memo, int parent)
{
    if (tree[node].size() == 1 && parent != -1)
    {
        memo[node] = 1;
        return 1;
    }

    int res = 0;
    for (auto &e : tree[node])
    {
        if (e != parent)
        {
            res += dfs(tree, e, memo, node);
        }
    }
    memo[node] = res;
    return res;
}

int main()
{
    int t, n, q;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<vector<int>> tree(n + 1);

        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        vector<ll> memo(n + 1, 0);
        dfs(tree, 1, memo, -1);

        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int xi, yi;
            cin >> xi >> yi;
            cout << memo[xi] * memo[yi] << endl;
        }
        // for (auto &a : memo)
        // {
        //     cout << a << ' ';
        // }
        // cout << endl;
    }

    return 0;
}