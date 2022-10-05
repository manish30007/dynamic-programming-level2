#include<bits/stdc++.h>

using namespace std;
class Edge{
  public:
  int v;
  int nbr;
  Edge(int v,int n){
    this->v=v;
    this->nbr=nbr;
  }
}
  void dg(vector<Edge>graph[],int src,vector<int>&comp,vector<bool>&vis){
    vis[src]=true;
    comp.push_back(src);
    for(Edge ed:graph[src]){
      if(vis[ed.nbr]==false){
        dg(graph,ed.nbr,comp,vis);
      }
    }
  }
int main(){
   int n;
   cin>>n;
   int k;
   cin>>k;
   vector<Edge>graph[n];
   for(int e=0;e<k;e++){
int v1;
int nb;
cin>>v1>>nb;
graph[v1].push_back(Edge(v1,nb));
graph[nb].push_back(Edge(nb,v1));
   }
vector<vector<int>>comps;
vector<bool>vis(n,false);
for(int i=0;i<n;i++){
  if(vis[i]==false){
    vector<int>comp;
    dg(graph,i,comp,vis);
    comps.push_back(comp);
  }
}
int pair=0;
      for(int i=0;i<comps.size();i++){
         for(int j=i+1;j<comps.size();j++){  
          int sum = comps[i].size()*comps[j].size();
          pair+=sum;
        }
      }
     cout<<pair;         
   return 0;
 }