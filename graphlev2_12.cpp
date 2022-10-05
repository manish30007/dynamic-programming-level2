//  #include<bits/stdc++.h>
//  using namespace std;
//  class Edge{
//      public:
//      int src=0;
//      int nbr=0;
//      Edge(int src,int nbr){
//          this->src=src;
//          this->nbr=nbr;
//      }
//  };
//  vector<int>getorder(int n,vector<vector<Edge>>graph){
//      vector<int>inorder(n,0);
//      vector<int>ans;
//      for(int i=0;i<n;i++){
//          for(Edge e:graph[i]){
//              inorder[e.nbr]++;
//          }
//      }
//      queue<int>q;
//      for(int i=0;i<n;i++){
//          if(inorder[i]==0){
//              q.push(i);
//          }
//      }
//      int idx=0;
//      while(q.size()>0){
//      int rem=q.front();
//      q.pop();
//      ans.push_back(rem);
//      idx++;
//      for(Edge e:graph[rem]){
//          inorder[e.nbr]--;
//          if(inorder[e.nbr]==0){
//              q.push(e.nbr);
//          }
//      }
     
//      }
//      if(idx==n){
//          return ans;
//      }
//      else{
//          vector<int>temp;
//          temp.push_back(-1);
//          return temp;
//      }
//  }
// int main(){
// int vtces;
// int edges;
// cin>>vtces>>edges;
// vector<vector<Edge>>graph(vtces,vector<Edge>());
// for(int i=0;i<edges;i++){
// int u,v;
// cin>>u>>v;
// graph[u].push_back(Edge(u,v));
// }
// for(int i=0;i<edges;i++){
//     cout<<graph[i].src<<" "<<graph[i].nbr<<endl;
// }
// // vector<int>ans=getorder(vtces,graph);
// // for(int i=0;i<ans.size();i++){
// //     cout<<ans[i]<<" ";
// // }
// return 0;
//  }
 #include<bits/stdc++.h>
 using namespace std;
 class Edge{
     public:
     int src=0;
     int nbr=0;
     Edge(int src,int nbr){
         this->src=src;
         this->nbr=nbr;
     }
 };
int getorder[](int n,vector<vector<Edge>>graph){
     vector<int>inorder(n,0);
    int ans[];
     for(int i=0;i<n;i++){
         for(Edge e:graph[i]){
            //  cout<<e.nbr<<"*"<<endl;
             inorder[e.nbr]+=1;
         }
     }
    //  for(int i=0;i<n;i++){cout<<inorder[i]<<" ";}
    //  cout<<endl;
     queue<int>q;
     for(int i=0;i<n;i++){
         if(inorder[i]==0){
             q.push(i);
         }
     }
     int idx=0;
     while(q.size()>0){
     int rem=q.front();
    //  cout<<"rem:"<<rem<<endl;
     q.pop();
     ans[idx]=rem;
     idx++;
     for(Edge e:graph[rem]){
        //  cout<<"e.nbr"<<e.nbr<<endl;
         inorder[e.nbr]--;
         if(inorder[e.nbr]==0){
             q.push(e.nbr);
         }
     }
     
     }
     if(idx==n){
         return ans;
     }
     else{
         int temp[1]={-1};
         return temp;
     }
 }
int main(){
int vtces;
int edges;
cin>>vtces>>edges;
vector<vector<Edge>>graph(vtces,vector<Edge>());
for(int i=0;i<edges;i++){
int u,v;
cin>>u>>v;
graph[u].push_back(Edge(u,v));
}
// for(int i=0;i<edges;i++){
//     cout<<graph[i].src<<" "<<graph[i].nbr<<endl;
// }
int ans[]=getorder(vtces,graph);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
return 0;
 }