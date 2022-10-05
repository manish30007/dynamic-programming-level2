#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src; 
    this->nbr = nbr;
  }
};

class Pair{
  public:
  int v=0;
  string psf="";
  Pair(int v,string psf){
    this->v=v;
    this->psf=psf;
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
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));
   } 

  
  int src; 
  cin >> src;
  string  psf = to_string(src);
  vector<bool>visited(vtces,false);
  queue<Pair>q;
  q.push(Pair(src,psf+""));
  while (q.size()!=0)
  {
    Pair rem=q.front();
    q.pop();
    if(visited[rem.v]==true){continue;}
    visited[rem.v]==true;
    cout<<rem.v<<"@"<<rem.psf<<endl;
    for(Edge e:graph[rem.v]){
      if(visited[e.nbr]==false){
        q.push(Pair(e.nbr,rem.psf+to_string(e.nbr)));
      }
    }
  }     
  return 0;
}