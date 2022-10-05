// #include <bits/stdc++.h>
// using namespace std;
// void dfs(int node,  vector<int> &vis, vector<int> adj[] ,int & count) {
//     count=count+1;
//     vis[node] = 1; 
//     for(auto it: adj[node]) {
//         if(!vis[it]) {
//             dfs(it, vis, adj,count); 
//         }
//     }
// }
// int main(){
// 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

// 	int n,m;
// 	cin>>n>>m;
// 	vector<int> adj[n+1]; 
// 	for(int i=0;i<m;i++){
// 	int u,v;
// 	cin>>u>>v;
// 	adj[u].push_back(v);
// 	}
// 	int count=0;
// 	vector<int> vis(n+1, 0); 
// 	for(int i = 1;i<=n;i++) {
// 	    if(!vis[i]) {
// 	        dfs(i, vis, adj,count); 
// 	        if(count==n){cout<<i;
// 	        return 0;}
// 	    }
// 	} 
// 	cout<<-1;
// 	return 0;
// }
// class Solution {
// public:
//     int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
//         unordered_map<int,int>m1;
//         unordered_map<int,int>m2;
// 		int n=tops.size();
//         for(int i=0;i<n;i++){
//             m1[tops[i]]++;
//             m2[bottoms[i]]++;
// }
//         int minu=100000;
        
//       for(auto &pr:m1){
//           int temp=pr.second;
//           unordered_map<int,int>::iterator it;
//           it=m2.find(pr.first);
//               if(it!=m2.end()){
                 
//                   if(it->second+pr.second>=n){
//                       int mini;
//                  if(it->second>=pr.second){mini=n-it->second;
//                                           } 
//                       else{mini=n-pr.second;}
//                       if(mini<minu)minu=mini;
//                   }
//               }
//           }
// if(minu<100000)
//         return minu;
//         return -1;
//     }
// };
// #include<bits/stdc++.h>
// using namespace std;
// void island(vector<vector<int>>&arr,int i,int j){
//     if(i<0||j<0||i>=arr.size()||j>=arr[0].size()||arr[i][j]==0){return;}
//     arr[i][j]=0;
//     island(arr,i+1,j);
//      island(arr,i-1,j);
//       island(arr,i,j+1);
//        island(arr,i,j-1);
// }
// int main(){
//     int m,n;
//     cin>>m>>n;
//     vector<vector<int>>arr(m,vector<int>(n,0));
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin>>arr[i][j];
//         }
//     }
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//         if(i==0||j==0||i==m-1||j==n-1){
//             if(arr[i][j]==1)island(arr,i,j);
//         }
//         }
//     }
//     int count=0;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(arr[i][j]==1)count++;
        
//         }
//     }
//     cout<<count;
//     return 0;
    
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
class Pair{
	public:
	int x;
	int y;
	Pair(int x,int y){this->x=x;
	this->y=y;}
};
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 int m,n;
 cin>>m>>n;
 vector<vector<int>>arr(m,vector<int>(n));
 for(int i=0;i<m;i++){
	 for(int j=0;j<n;j++){
		 cin>>arr[i][j];
	 }
 }
 int fresh=0;
 queue<Pair>q;
 int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		if(arr[i][j]==2){q.push(Pair(i,j));}
		else if(arr[i][j]==1)fresh++;
	}
}
if(fresh==0){cout<<-1;
return 0;}
int tim=-1;
while (q.size()>0){
	int size=q.size();
	tim++;
	while(tim-->0){
		Pair rem=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int rd=rem.x+dir[i][0];
			int cd=rem.y+dir[i][1];
			if(rd>=0&&cd>=0&&rd<m&&cd<n&&arr[rd][cd]==1){
				q.push(Pair(rd,cd));
				fresh--;
				arr[rd][cd]=0;
			}
		}
	}
}
if(fresh==0)cout<<tim;
else cout<<-1;
	return 0;
}


