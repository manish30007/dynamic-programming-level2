// // #include <bits/stdc++.h>
// // using namespace std;
// // #define ll long long
// // #define mod 1000000007
// //   int triangularSum(vector<int>& nums) {
// //         int n=nums.size();
// //         if(n==1){return nums[0];}
// //         vector<int>temp(n-1);
// //         for(int i=0;i<nums.size()-1;i++){
// //             temp[i]=(nums[i]+nums[i+1])%10;
// //         }
// //     return triangularSum(temp);
// //     }
// // int main() {
// //     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// // #ifndef ONLINE_JUDGE
// //     freopen("input.txt", "r", stdin);
// //     freopen("output.txt", "w", stdout);
// // #endif
// //  int n;
// //  cin>>n;
// //  vector<int>arr(n);
// //  for(int i=0;i<n;i++){
// //      cin>>arr[i];
// //  }
// // cout<< triangularSum(arr);
// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007
// int main() {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
 
//    string s="10:20";
//    string st=s.substr(0,2);
//    cout<<st<<endl;
//    string sr=s.substr(3);
//    cout<<sr<<endl;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
vector<int>dis;
vector<int>low;
vector<bool>ap;
vector<bool>vis;
vector<vector<int>>ans;
int tim=0;
void dfs(int u,vector<int>adj[]){
    int count=0;
    dis[u]=low[u]=tim;
    tim++;
    vis[u]=true;
    vector<int>nbrs=adj[u];
    for(int i=0;i<nbrs.size();i++){
        int nbr=nbrs[i];
        if(parent[u]==nbr)continue;
        else if(vis[nbr]==true){
        low[u]=min(low[u],dis[nbr]);
        }else{
            parent[nbr]=u;
            dfs(nbr,adj);
            count++;
            low[u]=min(low[u],low[nbr]);
            
            if(low[nbr]>dis[u]){
           vector<int>temp;
           temp.push_back(u);
           temp.push_back(nbr);
           ans.push_back(temp);
                
            }
            }
        }
    }

int main(){
int n,m;
cin>>n>>m;
vector<int>adj[n+1];
for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
parent.resize(n+1);
dis.resize(n+1);
low.resize(n+1);
ap.resize(n+1);
vis.resize(n+1);
parent[1]=-1;
dfs(1,adj);
cout<<"[";
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        if(i==ans.size()-1){cout<<ans[i][j];}
        else{cout<<ans[i][j]<<", ";}
    }
}
cout<<"]";
return 0;
}