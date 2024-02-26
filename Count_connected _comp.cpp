#include <bits/stdc++.h>
using namespace std;
#define p 1000
bool issafe(char ch[][p],int i,int j,bool visited[][p],int n,int m)
{
    return i>=0 && j>=0 && i<n && j<m && ch[i][j] == '.' && !visited[i][j]; 
 
}
void dfs(char ch[][p],int i,int j,bool visited[][p],int n,int m)
{
    visited[i][j] = true;
 
    int row[] = {0,0,1,-1};
    int col[] = {1,-1,0,0};
 
    for(int k=0;k<4;k++)
    {
        if(issafe(ch,i+row[k],j+col[k],visited,n,m))
        {
            dfs(ch,i+row[k],j+col[k],visited,n,m);
        }
    }
}
int couting(char ch[][p],int n,int m)
{
    bool visited[p][p];
    memset(visited,0,sizeof(visited));
    int cnt = 0;
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j] && ch[i][j]=='.')
               {
                   dfs(ch,i,j,visited,n,m);
                   cnt++;
               }
        }
    }
 
return cnt;
}
int main() {
   
   int n,m;
   cin>>n>>m;
   char ch[p][p];
 
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
          cin>>ch[i][j];
   }
 
   cout<<couting(ch,n,m);
}