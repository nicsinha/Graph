#include <bits/stdc++.h>
using namespace std;
map<int,list<int>> mp;
map<int,char> color;
map<int,bool> vis;
vector<int> v1;
vector<int> v2;
bool ans = true;

void dfs(int src) {

    vis[src] = true;

    for(auto nbr:mp[src]) {
        if(!vis[nbr]) {
            if(color[src] == 'Y')
                color[nbr] = 'G';
            else {
                color[nbr] = 'Y';
            }
            dfs(nbr);
        }
        else {
            color[nbr] = 'B';
            ans = false;
            break;
        }
    }
}

int main() {
    
    int n,m;
    cin>>n>>m;

    int res = 0;

    for(int i=0,x,y;i<m;i++) {
        cin>>x>>y;
        mp[x].push_back(y);
    }

    for(int i=1;i<=n;i++) {
        color[i] = 'W';
        vis[i] = false;
    }

    for(int i=1;i<=n;i++) {
        if(ans) {
            if(!vis[i]) {
            dfs(i);
            color[i] = 'G';
            }
        }  
        
    }
    
    for(auto i:color) {

        if(i.second == 'B') {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        else if(i.second == 'G') {cout<<"1"<<" ";}
        else {cout<<"2"<<" ";}
            
    }



   
}
