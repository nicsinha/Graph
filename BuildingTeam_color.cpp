#include <bits/stdc++.h>
using namespace std;

map<int, list<int>> mp;
map<int, char> color;
map<int, bool> vis;
bool ans = true;

void dfs(int src, char col) {
    vis[src] = true;
    for (auto nbr : mp[src]) {
        if (!vis[nbr]) {
            color[nbr] = (col == 'Y') ? 'G' : 'Y';
            dfs(nbr, color[nbr]);
        } else if (color[nbr] == col) {
            ans = false;
            return;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            color[i] = 'Y'; // Assign initial color to first node
            dfs(i, 'Y');
        }
    }

    if (!ans) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << ((color[i] == 'G') ? "2 " : "1 ");
    }

    return 0;
}
