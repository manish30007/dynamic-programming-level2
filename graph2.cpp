#include<bits/stdc++.h>

using namespace std;

class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};
class Pair{
    public:
    int wsf=0;
    string psf="";
    Pair(int wsf ,string psf){
        this->wsf=wsf;
        this->psf=psf;
    }
};

struct mycomp {
  bool operator()(Pair const &p1,Pair const &p2)
  {
    return p1.wsf > p2.wsf;
  }
};

string spath;
int spathwt = INT_MAX;
string lpath;
int lpathwt = INT_MIN;
string cpath;
int cpathwt = INT_MAX;
string fpath;
int fpathwt = INT_MIN;

priority_queue<Pair,vector<Pair>,mycomp>pq;

void multisolver(vector<Edge> graph[], int src, int dest, vector<bool> visited, int criteria, int k, string psf, int wsf) {
if(src==dest){
    if(wsf<spathwt){
        spathwt=wsf;
        spath=psf;
    }
    if(wsf>lpathwt){
        lpathwt=wsf;
        lpath=psf;
    }
    if(wsf>criteria && wsf<cpathwt){
        cpathwt=wsf;
        cpath=psf;
    }
    if(wsf<criteria &&wsf>fpathwt){
        fpathwt=wsf;
        fpath=psf;
    }
    if(pq.size()<k){
        pq.push(Pair(wsf,psf));
    }
    else{
        Pair x=pq.top();
        if(x.wsf<wsf){
            pq.pop();
            pq.push(Pair(wsf,psf));
        }
        }

    }
visited[src]=true;
for(Edge e:graph[src]){
    if(visited[e.nbr]==false){
      multisolver(graph,src,dest,visited,criteria,k,psf,wsf);  
    }
}
}

int main() {

  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }

  int src;
  cin >> src;
  int dest;
  cin >> dest;

  int criteria;
  cin >> criteria;
  int k;
  cin >> k;

  vector<bool> visited(vtces, false);
  multisolver(graph, src, dest, visited, criteria, k, src + "0", 0);

  cout << "Smallest Path = " << spath << "@" << spathwt << endl;
  cout << "Largest Path = " << lpath << "@" << lpathwt << endl;
  cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt << endl;
  cout << "Just Smaller Path than " << criteria << " = " << fpath << "@" << fpathwt << endl;
  Pair r=pq.top();
  int w=r.wsf;
  string st=r.psf;
  cout << k << "th largest path = " <<w << "@" <<st<< endl;

  return 0;
}