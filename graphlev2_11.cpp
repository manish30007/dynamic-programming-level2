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
class Pair{
    public:
    int vrtx;
    int wsf;
    Pair(int vrtx,int wsf){
        this->vrtx=vrtx;
        this->wsf=wsf;
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
  deque<Pair>q;
  vector<bool>visited(vtces,false);
 q.push_front(Pair(1,0));
  while(q.size()>0){
      Pair rem=q.front();
      q.pop_front();
      if(rem.vrtx==vtces){
      cout<<rem.wsf;
      return 0;
      }
      for(Edge e:graph[rem.vrtx]){
      if(visited[e.nbr]==false){
      if(e.wt==0){q.push_front(Pair(e.nbr,rem.wsf+0));}
      else{q.push_front(Pair(e.nbr,rem.wsf+e.wt));}
      }
      
  }
  }

 return -1;
}