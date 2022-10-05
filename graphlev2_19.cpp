#include<bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int>adj[],int parent[],int disc[],int low[],vector<bool>&visited,vector<bool>&au,int &tim){
    disc[u]=low[u]=tim;
    tim++;
    int count =0;
    visited[u]=true;
    vector<int>nbrs=adj[u];
    for(int i=0;i<nbrs.size();i++){
        int v=nbrs[i];
        if(parent[u]==v){continue;}
        else if(visited[v]==true){
            low[u]=min(low[u],disc[v]);
        }
        else{
        parent[v]=u;
        count++;
        dfs(v,adj,parent,disc,low,visited,au,tim);
        low[u]=min(low[u],low[v]);
        if(parent[u]==-1){
            if(count>=2){
                au[u]=true;
            }
        }
        else{
            if(low[v]>=disc[u])au[u]=true;
        }
        }
    }
}
int main(){
int vx;
int e;
cin>>vx>>e;
int parent[vx];
 int disc[vx];
 int low[vx];
 vector<bool>visited(vx,false);
 vector<bool>au(vx,false);
 int tim=0;
 parent[0]=-1;
 vector<int>adj[vx];
 for(int i=0;i<e;i++){
     int u,v;
     cin>>u>>v;
     adj[u-1].push_back(v-1);
     adj[v-1].push_back(u-1);
 }
 dfs(0,adj,parent,disc,low,visited,au,tim);
 int ans=0;
 for(int i=0;i<vx;i++){
     if(au[i]==true)ans++;
 }
 cout<<ans;
return 0;
}