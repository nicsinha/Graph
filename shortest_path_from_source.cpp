#include<bits/stdc++.h>
using namespace std;
#define ll long long int
unordered_map<ll,list<pair<ll,ll>>> mp;
unordered_map<ll,ll> dist;

void bfs(ll src) {

    set<pair<ll,ll>> s;
    s.insert({0,src});

    dist[src] = 0;

    while(!s.empty()) {

        auto t = *s.begin();
        s.erase(s.begin());
        ll node = t.second;
        ll node_distance = t.first;

        for(auto nbr:mp[src]) {

            if(dist[src] + node_distance < dist[nbr.first]) {

                ll dest = nbr.first;
                dist[dest] = dist[src] + node_distance;

                s.insert({dist[dest],dest});
            }

        }

        

    }


}

int main() {

    ll m,n;
    cin>>n>>m;

    for(ll i=0,a,b,c;i<m;i++) {

        cin>>a>>b>>c;
        mp[a].push_back({b,c});
    }
    
    for(ll i=1;i<=n;i++) {
        dist[i] = 1e18;
    }
}
