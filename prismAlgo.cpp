#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;
  int wt = 0;

  Edge(int src, int nbr, int wt)
  {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};
class Pair{
    public:
    int src=0;
    int av=0;
    int wt=0;
    Pair(int src,int av,int wt){
        this->src=src;
        this->av=av;
        this->wt=wt;
    }
    
};
struct mycomp{
    bool operator()(Pair const&p1,Pair const&p2){
        return p1.wt>p2.wt;
    }
};
int main() {

  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));

  }

priority_queue<Pair,vector<Pair>,mycomp>pq;
pq.push(Pair(0,-1,0));
vector<bool>visited(vtces,false);
while(pq.size()>0){
    Pair rem=pq.top();
    pq.pop();
    if(visited[rem.src]==true){continue;}
    visited[rem.src]=true;
    if(rem.av!=-1){
        cout<<"["<<rem.src<<"-"<<rem.av<<"@"<<rem.wt<<"]"<<endl;
    }
    for(Edge e:graph[rem.src]){
        if(visited[e.nbr]==false){
            pq.push(Pair(e.nbr,rem.src,e.wt));
        }
    }
}


  return 0;
}









