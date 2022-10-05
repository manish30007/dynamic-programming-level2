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
  int wt=0;

  Edge(int src, int nbr,int wt)
  {
    this->src = src;
    this->nbr = nbr;
    this->wt=wt;
  }
};
class Pair{
    public:
    int src=0;
    string psf="";
    int wsf=0;
    Pair(int src,string psf,int wsf){
        this->src=src;
        this->psf=psf;
        this->wsf=wsf;
    }
};
struct mycomp{
bool operator()(Pair const &p1,Pair const &p2){
    
        return p1.wsf>p2.wsf;
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

    graph[u].push_back(Edge(u, v,w));
    graph[v].push_back(Edge(v, u,w));

  }
  int src;
  cin>>src;
priority_queue<Pair,vector<Pair>,mycomp>pq;
pq.push(Pair(src,to_string(src)+"",0));
vector<bool>visited(vtces,false);
while(pq.size()>0){
   Pair rem=pq.top();
   pq.pop();
   if(visited[rem.src]==true){
       continue;}
   visited[rem.src]=true;
   cout<<rem.src<<" via "<<rem.psf+" @ "<<rem.wsf<<endl;
   for(Edge e:graph[rem.src]){
       if(visited[e.nbr]==false){
           pq.push(Pair(e.nbr,rem.psf+to_string(e.nbr),rem.wsf+e.wt));
       }
   }
}
 
  return 0;
}















