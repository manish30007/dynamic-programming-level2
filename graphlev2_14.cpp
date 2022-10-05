#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int parent[100000];
int size[100000];
void makeset(n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        size[i]=1;
    }
}
int find(int a){
    if(a==parent[a])return a;
    return parent[a]=find(parent[a]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 int vtces,edges;
 cin>>vtces>>edges;
makeset(vtces);
vector<pair<int,pair<int,int>>>graph;
for(int i=0;i<edges;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    graph.push_back({wt,{u,v}});
}
sort(graph.begin(),graph.end());
int total_cost=0;
for(auto &edge:graph){
    int wt=edge.first;
    int u=edge.second.fisrt;
    int v=edge.second.second;
    if(find(u)==find(v))continue;
    Union(u,v);
    total_cost+=wt;
}cout<<total_cost;
    return 0;
}
