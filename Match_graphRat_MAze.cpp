#include<bits/stdc++.h>
using namespace std;

void checkpathHelper(string s[],int n,int m,int di[], int dj[],int i,int j,
                 int p, int q,string res, vector<string> &path,
                 vector<vector<int>> &vis)
{
    cout<<i<<" "<<j<<" "<<p<<" "<<q<<endl;
    if(i == p && j == q) {
        path.push_back(res);
        return;
    }

    string pd = "LDRU";

    for(int k=0;k<4;k++) {
        int u = i + di[k];
        int v = j + dj[k];
   
        if(u>=0 && v>=0 && u < n && v < m && s[u][v] == '.' && !vis[u][v]) {

            vis[i][j] = 1;
            checkpathHelper(s,n,m,di,dj,u,v,p,q,res+pd[k],path,vis);
            vis[i][j] = 0;
        }
    }


}

void checkPath(string s[],int n,int m) {

    int di[4] = {0,1,0,-1};
    int dj[4] = {-1,0,1,0};

    vector<vector<int>> vis(n,vector<int>(m,0));
    int iindex,jindex,p,q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s[i][j] == 'A') {
                iindex = i;
                jindex = j;
            }
            if(s[i][j] == 'B') {
                p = i;
                q = j;
            }
        }
    }
cout<<iindex<<" "<<jindex<<" "<<p<<" "<<q<<" "<<endl;;
string res = "";
vector<string> path;
vis[iindex][jindex] = 1;

checkpathHelper(s,n,m,di,dj,iindex,jindex,
                p, q,res, path,vis);


for(auto i: path) {
    cout<<i<<endl;
}


}

int main() {

    int n,m;
    cin>>n>>m;

    string s[n];

    for(int i=0;i<n;i++) {
        string st;
        cin>>st;
        s[i] = st;
    }

    checkPath(s,n,m);



}
