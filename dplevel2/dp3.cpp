#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++){
cin>>arr[i];
}
int k;cin>>k;
vector<vector<int>>dp(n+1,vector<int>(k+1,0));
for(int i=0;i<=n;i++){
    for(int j=0;j<=k;j++){
    if(i==0&&j==0)dp[i][j]=1;
    if(j==0)dp[i][j]=1;
  else {
          if(dp[i-1][j])dp[i][j]=1;
          else if(j>=arr[i-1]){
          if(dp[i-1][j-arr[i-1]]==1)dp[i][j]=1;
            }
         }
    }
}




return 0;
}