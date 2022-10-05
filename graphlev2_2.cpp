#include <bits/stdc++.h>

using namespace std;
void island(vector<vector<int>> &arr,int i,int j){
    if(i<0||j<0||i>=arr.size()||j>=arr[0].size()||arr[i][j]==0){
        return;
    }
    arr[i][j]=0;
    island(arr,i-1,j);
    island(arr,i,j-1);
    island(arr,i+1,j);
    island(arr,i,j+1);
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
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         if(i==0||j==0||i==arr.size()-1||j==arr[0].size()-1){
             if(arr[i][j]==1){
             island(arr,i,j);
         }
     }
 }
 }
 int count=0;
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         if(arr[i][j]==1)count++;
}
}
cout<<count;
return 0;
}







