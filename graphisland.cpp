#include <bits/stdc++.h>

using namespace std;
void island(vector<vector<int>> &arr,int i,int j, vector<vector<bool>>&visited){
    if(i<0||j<0||i>=arr.size()||j>=arr[0].size()||arr[i][j]==1||visited[i][j]==true){
        return;
    }
    island(arr,i-1,j,visited);
    island(arr,i,j-1,visited);
    island(arr,i+1,j,visited);
    
    island(arr,i,j+1,visited);
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
int count=0;
 vector<vector<bool>>visited(n,vector<bool>(m,false));
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         if(visited[i][j]==false&& arr[i][j]==0){
             island(arr,i,j,visited);
             count++;
         }
     }
 }
 cout<<count;
}