    #include<bits/stdc++.h>
    using namespace std;
    class Edge{
        public:
        int src;
        int nbr;
        int wt;
        Edge(int src,int nbr, int wt){
            this->src=src;
            this->nbr=nbr;
            this->wt=wt;
        }
    };
    void hamiltonian(int vtces,vector<Edge>graph[],unordered_set<int>&vis,int src,string psf,int osrc){
    // cout<<"*"<<vtces<<endl;
    if(vis.size()==vtces-1){
    cout<<psf;
    int  closedge=0;
    for(Edge e:graph[osrc]){
        if(e.nbr==src){
            closedge=1;
            break;
        }
    }
    if(closedge==1){cout<<"*"<<endl;}
    else{cout<<"."<<endl;}
    return ;
    }
    vis.insert(src);
    for(Edge e:graph[src]){

        if(vis.find(e.nbr)!=vis.end()){
            string  ans = to_string(e.nbr);
            hamiltonian(vtces,graph,vis,e.nbr,psf+ans,osrc);
        }
    }
    vis.erase(src);
    }
    int main(){
    int vtces;
    cin>>vtces;
    int edges;
    cin>>edges;
    vector<Edge>graph[vtces];
    // cout<<vtces<<endl;
    for(int e=0;e<edges;e++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back(Edge(v1,v2,wt));
        graph[v2].push_back(Edge(v2,v1,wt));
    }
    int src;
    cin>>src;
    unordered_set<int>vis;
    string psf = to_string(src);
    hamiltonian(vtces,graph,vis,src,psf,src);
    return 0;
    }
    // 7
    // 9
    // 0 1 10
    // 1 2 10
    // 2 3 10
    // 0 3 10
    // 3 4 10
    // 4 5 10
    // 5 6 10
    // 4 6 10
    // 2 5 10
    // 0