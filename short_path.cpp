// rjälä's network has n computers and m connections.
// Your task is to find out if Uolevi can send a message to Maija,
// and if it is possible, what is the minimum number of computers on such a route.

// Input:

// 5 5
// 1 2
// 1 3
// 1 4
// 2 3
// 5 4
// Output:

// 3
// 1 4 5

#include <bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> mp;
unordered_map<int,bool> vis;
unordered_map<int,int> dis;
unordered_map<int,int> parent;

void bfs(int src,int dest) {

    int flag = 0;
    queue<int> q;

    q.push(src);
    vis[src] = true;
    parent[src] = -1;
    dis[src] = 0;

    while(!q.empty()) {

        auto temp = q.front();
        q.pop();
        if(temp == dest) {
            flag = 1;
            cout<<dis[temp]+1<<endl;
            break;
        }

        for(auto nbr: mp[temp]) {

            if(!vis[nbr]) {
                q.push(nbr);
                vis[nbr] = true;
                parent[nbr] = temp;
                dis[nbr] = dis[temp] + 1;
            }
        }
    }
    vector<int> v;
    if(flag == 0) {cout<<"IMPOSSIBLE";}
    else
    {
        int temp = dest;
    
        while(parent[temp]!=-1)
        {
            v.push_back(temp);
            temp = parent[temp];
        }
        v.push_back(src);
        for(auto i=v.end()-1;i>=v.begin();i--)
        cout<<*i<<" ";

    }


}

int main() {
    
    int n,m;
    cin>>n>>m;

    for(int i=0,x,y;i<m;i++) {
        cin>>x>>y;

        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    for(int i=1;i<=n;i++) {
        dis[i] = 0;
        vis[i] = false;
    }

    bfs(1,n);


}
