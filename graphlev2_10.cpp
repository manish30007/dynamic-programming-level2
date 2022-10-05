#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src=0;
    int nbr=0;
    int wt=0;
    Edge(int src,int nbr,int wt){
        this->src=src;
        this->nbr=nbr;
        this->wt=wt;
    }
};
int main(){
   int vtces,edges;
   cin>>vtces>>edges;
   vector<Edge>graph[vtces];
   for(int i=0;i<edges;i++){
       int u,v;
       cin>>u>>v;
       graph[u].push_back(Edge(u,v,0));
       graph[v].push_back(Edge(v,u,1));
       
   }
   vector<bool>visited(vtces,false);
   queue<Edge>q;
   
   
 return 0;
}