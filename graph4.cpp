#include <bits/stdc++.h>

using namespace std;
void drawgraphforcomp(vector<vector<int>>&arr,vector<vector<bool>>&vis,int i,int j){
     if(i<0||j<0||i>arr.size()-1||j>arr[0].size()-1||vis[i][j]==true||arr[i][j]==1){
return;
     }
     vis[i][j]=true;
     drawgraphforcomp(arr,vis,i-1,j);
     drawgraphforcomp(arr,vis,i,j+1);
     drawgraphforcomp(arr,vis,i+1,j);
     drawgraphforcomp(arr,vis,i,j-1);
 }
int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        for (int j = 0; j < m; j++)
        {
            int res;
            cin >> res;
            ans.push_back(res);
        }
        arr.push_back(ans);
    }
  vector<vector<bool>>vis(n,vector<bool>(m,false));
  int count=0;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(vis[i][j]==false&&arr[i][j]==0){
              drawgraphforcomp(arr,vis,i,j);
              count++;
          }
      }
  }
  cout<<count;
}