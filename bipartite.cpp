// #include <iostream>
// #include <vector>
// #include <queue>
// #include<string>
// using namespace std;

// class Edge
// {
// public:
//   int src = 0;
//   int nbr = 0;

//   Edge(int src, int nbr)
//   {
//     this->src = src;
//     this->nbr = nbr;
//   }
// };


// int main() {
//   int vtces;
//   cin >> vtces;
//   vector<vector<Edge>> graph(vtces, vector<Edge>());


//   int edges;
//   cin >> edges;

//   for (int i = 0; i < edges; i++ ) {
//     int u, v, w;
//     cin >> u >> v >> w;

//     graph[u].push_back(Edge(u, v));
//     graph[v].push_back(Edge(v, u));

//   }

//   // write your code here
//   return 0;
// }
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
    int src=0;
    string psf="";
    int wt=0;
    Pair(int src,string psf,int wt){
        this->src=src;
        this->psf=psf;
        this->wt=wt;
    }
};
bool comp(Pair p1,pair P2){
    if(p1.wt!=p2.wt){
        return p1.wt<p2.wt;
    }
}
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

 
  return 0;
}