#include<bits/stdc++.h>
using namespace std;
int inf=10000000;
class Edge{
    public:
    int u,v,wt;
    Edge(int u,int v,int wt){
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};
int main(){
      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int vtces,edges;
cin>>vtces>>edges;
vector<Edge>graph;
for(int i=0;i<edges;i++){
int u,v,wt;
cin>>u>>v>>wt;
graph.push_back(Edge(u,v,wt));
}
vector<int>dist(vtces+1,inf);
dist[1]=0;
for(int i=2;i<=vtces;i++){
    for(auto it:graph){
        if(dist[it.u]+it.wt<dist[it.v]){
           dist[it.v]=dist[it.u]+it.wt; 
        }
    }
}
int fl=0;
for(auto it:graph){
    if(dist[it.u]+it.wt<dist[it.v]){
        cout<<-1;
        return 0;
}
}
for(int i=2;i<dist.size();i++){
    cout<<dist[i]<<" "; 
}


return 0;
}

