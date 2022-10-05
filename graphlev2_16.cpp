#include<bits/stdc++.h>
using namespace std;
class Pair{
    public :
    int v=0;
    int wt=0;
    Pair(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};
struct mycomp{
    bool operator()(Pair const&p1,Pair const&p2){
        return p1.wt>p2.wt;
    }
};
int main(){
      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int vtces;
int edges;
cin>>vtces>>edges;
vector<int>well;
for(int i=0;i<vtces;i++){
    int x;
    cin>>x;
well.push_back(x);
}
vector<vector<Pair>>graph(vtces+1,vector<Pair>());
for(int i=0;i<edges;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    graph[u].push_back(Pair(v,wt));
    graph[v].push_back(Pair(u,wt));
}
for(int i=1;i<=vtces;i++){
    graph[0].push_back(Pair(i,well[i-1]));
    graph[i].push_back(Pair(0,well[i-1]));
}
int ans=0;
priority_queue<Pair,vector<Pair>,mycomp>q;
q.push(Pair(0,0));
vector<bool>visited(vtces+1,false);
while(q.size()>0){
Pair rem=q.top();
if(visited[rem.v]==true){
    continue;
}
ans+=rem.wt;
visited[rem.v]=true;
for(Pair e:graph[rem.v]){
    if(visited[e.v]==false){
        q.push(Pair(e.v,e.wt));
    }
}
}
cout<<ans;
return 0;
}