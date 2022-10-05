#include <bits/stdc++.h>

using namespace std;
void island(vector<vector<int>> &arr,int i,int j,vector<char>&psf){
arr[i][j]=0;
if(i-1>=0 &&arr[i-1][j]==1){
    psf.push_back('u');
    island(arr,i-1,j,psf);
}
if(j+1<arr[0].size() &&arr[i][j+1]==1){
    psf.push_back('r');
    island(arr,i,j+1,psf);
}
if(i+1<arr.size() &&arr[i+1][j]==1){
    psf.push_back('d');
    island(arr,i+1,j,psf);
}
if(j-1>=0 &&arr[i][j-1]==1){
    psf.push_back('l');
    island(arr,i,j-1,psf);
}
psf.push_back('z');
    
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
  set<vector<char>>st;
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
       if(arr[i][j]==1){
          vector<char>psf;
          psf.push_back('x');
           island(arr,i,j,psf);
           st.insert(psf);
       }
    }
 }
 cout<<st.size();
}







