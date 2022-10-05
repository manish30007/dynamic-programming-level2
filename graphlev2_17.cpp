// #include <bits/stdc++.h>
// using namespace std;
// void dfs(int node, stack<int> &st, vector<bool> &vis, vector<int> adj[]) {
//     vis[node] = 1; 
//     for(auto it: adj[node]) {
//         if(!vis[it]) {
//             dfs(it, st, vis, adj); 
//         }
//     }
    
//     st.push(node); 
// }
// void revDfs(int node, vector<bool> &vis, vector<int> transpose[]) {
//     // cout << node << " "; 
//     vis[node] = 1; 
//     for(auto it: transpose[node]) {
//         if(!vis[it]) {
//             revDfs(it, vis, transpose); 
//         }
//     }
// }
// int main() {
// 	
// 	cin>>n>>m;
// 	vector<int> adj[n+1]; 
// 	for(int i=0;i<m;i++){
// 	int u,v;
// 	cin>>u>>v;
// 	adj[u].push_back(v);
// 	}

	
// 	stack<int> st;
// 	vector<bool> vis(n+1, false); 
// 	for(int i = 1;i<=n;i++) {
// 	    if(!vis[i]) {
// 	        dfs(i, st, vis, adj); 
// 	    }
// 	} 
	
// 	vector<int> transpose[n+1]; 
	
// 	for(int i = 1;i<=n;i++) {
// 	    vis[i] =false; 
// 	    for(auto it: adj[i]) {
// 	        transpose[it].push_back(i); 
// 	    }
// 	}
	
// 	int count=0;
	
// 	while(!st.empty()) {
// 	    int node = st.top();
// 	    st.pop(); 
// 	    if(!vis[node]) {
// 	        // cout << "SCC: "; 
// 	        revDfs(node, vis, transpose); 
// 	        count++;
// 	    }
// 	}
// 	cout<<count;
	
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,stack<int>&st,vector<bool>&visited,vector<int>adj[]){
    visited[node]=true;
    for(auto it:adj[node]){
        if(visited[it]=false){
        dfs(it,st,visited,adj);
      }
    }
st.push(node);
}
void rdfs(int node,vector<bool>&visited,vector<int>transpose[]){
    visited[node]=true;
    for(auto it:transpose[node]){
        if(visited[it]==false){
            rdfs(it,visited,transpose);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

int n,m;
cin>>n>>m;
vector<int>adj[n+1];
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
}
stack<int>st;
vector<bool>visited(n+1,false);
for(int i=1;i<=n;i++){
    if(visited[i]==false){
        dfs(i,st,visited,adj);
    }
}
vector<int>transpose[n+1];
for(int i=1;i<=n;i++){
    visited[i]=false;
    for(auto it:adj[i]){
        transpose[it].push_back(i);
    }
}
int count=0;
while(!st.empty()){
int node =st.top();
st.pop();
if(visited[node]==false){
    rdfs(node,visited,transpose);
    count++;
}
}
cout<<count;
return 0;
}












