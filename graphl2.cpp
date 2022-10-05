//no of island ii
#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
vector<int>size;
int find (int node){if(node==parent[node])return node;
return parent[node]=find(parent[node]);}
int main(){
     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int m,n,k;
cin>>m>>n>>k;
parent.resize(m*n,-1);
size.resize(m*n);
vector<vector<int>>pos(k,vector<int>(2));
vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
for(int i=0;i<k;i++){
    int u,v;
    cin>>u>>v;
    pos[i][0]=u;
    pos[i][1]=v;
}
int count=0;
vector<int>ans;
for(vector<int>p:pos){
// cout<<p[0]<<"*"<<p[1]<<endl;
    int r=p[0];
    int c=p[1];
    int cellno=r*n+c;
    if(parent[cellno]!=-1){continue;}
    parent[cellno]=cellno;
    size[cellno]=1;
    count++;
  for(auto d:dir){
        // cout<<d[0]<<" "<<d[1]<<endl;
        int rd=r+d[0];
        int cd=c+d[1];
        int celldash=rd*n+cd;
        if(rd<0||cd<0||rd>=m||cd>=n||parent[celldash]==-1){
            continue;
    }
    int lx=find(cellno);
    int ly=find(celldash);
    if(lx!=ly){
        if(size[lx]<size[ly]){parent[lx]=ly;size[ly]+=size[lx];}
        else{parent[ly]=lx;size[lx]+=size[ly];}
        count--;
}
}
ans.push_back(count);
}
cout<<"[";
for(int i=0;i<ans.size();i++){
    if(i==ans.size()-1){
        cout<<ans[i];
    }
    else cout<<ans[i]<<" ";
}
cout<<"]";
return 0;
}







//cut by slash
// class Solution {
// public:
//     int*parent;
//     int*size;
//     int count=1;
//     int find(int a){
//         if(a==parent[a])return a;
//         return parent[a]=find(parent[a]);
//     }
//     void Union(int a,int b){
//         int lx=find(a);
//         int ly=find(b);
//         if(lx!=ly){
//             if(size[lx]<size[ly]){
//                 parent[lx]=ly;
//                 size[ly]+=size[lx];
//             }
//             else{
//                 parent[ly]=lx;
//                 size[lx]+=ly;
//             }
//         }
//         else{
//             count++;
//         }
// }
//     int regionsBySlashes(vector<string>& grid) {
//         int n=grid.size();
//         int dots=n+1;
//          parent=new int[dots*dots];
//         size=new int[dots*dots];
//         for(int i=0;i<dots*dots;i++){
//             parent[i]=i;
//             size[i]=1;
//         }
//         for(int i=0;i<dots;i++){
//             for(int j=0;j<dots;j++){
//                 if(i==0||j==0||i==dots-1||j==dots-1){
//                     if(i==0&&j==0)continue;
//                     int cellno=i*dots+j;
//                     Union(0,cellno);
// }
//             }
            
//         }
//        for (int i=0; i<grid.size(); i++)
//         {
//             for (int j=0; j<grid[i].size(); j++)
//             {cout<<grid[i].size()<<endl;
//         if(grid[i][j]=='/'){
//             int c1=(i+1)*dots+j;
//             int c2=i*dots+j+1;
//             Union(c1,c2);
//         }else if(grid[i][j]=='\\'){
//              int c1=(i+1)*dots+(j+1);
//             int c2=i*dots+j;
//             Union(c1,c2);
//         }else{
//             continue;
//         }
// }
//         }
//         return  count;
//     }
// };