// #include<bits/stdc++.h>
// using namespace std;
// class Pair{
//     public:
//     int x;
//     int y;
//     Pair(int x,int y){
//         this->x=x;
//         this->y=y;
//     }
// };
// int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
// void bfs(vector<vector<int>>A,int r,int c,vector<vector<bool>>&visited,queue<Pair>&q){
//     visited[r][c]=true;
//     q.push(Pair(r,c));
//     for(int i=0;i<4;i++){
//     int rd=r+dir[i][0];
//     int cd=c+dir[i][1];
//     if(rd<0||cd<0||rd>=A.size()||cd>=A[0].size()||visited[rd][cd]==true||A[rd][cd]==0){
//         continue;
//     }
//     bfs(A,rd,cd,visited,q);
// }
    
// }
// int main(){
// int n;
// cin>>n;
// vector<vector<int>>A(n,vector<int>(n));
// for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//         cin>>A[i][j];
//     }
// }
// queue<Pair>q;
// vector<vector<bool>>visited(n,vector<bool>(n,false));
// bool flag=false;
// for(int i=0;i<n && !flag;i++){
//     for(int j=0;j<n && !flag;j++){
//         if(A[i][j]==1){
//             flag=true;
//             bfs(A,i,j,visited,q);
//         }
//     }
// }
// int level=0;
// while(q.size()>0){
//   int size=q.size();
//   while(size-->0){
//     Pair rem=q.front();
//     q.pop();
//     for(int i=0;i<4;i++){
//         int rd=rem.x+dir[i][0];
//         int cd=rem.y+dir[i][1];
//        if(rd<0||cd<0||rd>=A.size()||cd>=A[0].size()||visited[rd][cd]==true){
//        continue;
//     }
//     if(A[rd][cd]==1){
//         cout<<level;
//         return 0;
//     }

//     visited[rd][cd]=true;
//     q.push(Pair(rd,cd));
//     }
    
//   }
//   level++;
  
// }
// cout<<"-1";
// return 0;
// }









