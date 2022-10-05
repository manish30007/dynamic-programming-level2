#include<bits/stdc++.h>
using namespace std;

int main(){
 string s;
 cin>>s;
 int n=s.size();
 vector<vector<int>>dp(n,vector<int>(n));
 for(int g=0;g<n;g++){
    for(int i=0,j=g;j<n;i++,j++){
        if(g==0){
            dp[i][j]=1;
        }
        else if(g==1){
            dp[i][j]=s[i]==s[j];
        }
        else{
            if(s[i]==s[j]&&dp[i+1][j-1]==1){
                dp[i][j]=1;
            }
            else dp[i][j]=0;
        }
        
    }
 }
//  vector<vector<int>>res(n, vector<int>(n));
//  for(int g=0;g<n;g++){
//   for(int i=0,j=g;j<n;i++,j++){
//          if(g==0)res[i][j]=0;
//          else if(g==1){
//              if(s[i]==s[j]){
//                 res[i][j]=0;
//              }
//              else{
//                  res[i][j]=1;
//              }}
//         else {
//             if(dp[i][j]){
//                 res[i][j]=0;
//             }
//             else{
//             int mini=INT32_MAX;
//             for(int k=i;k<j;k++){
//             int left=res[i][k];
//             int right=res[k+1][j];
//             if(right+left+1<mini){mini=left+right+1;}
//             }
//             res[i][j]=mini;
//          }
//          }
//      }
//  };
//  cout<<res[0][n-1];

//optimized
vector<int>res(n);
res[0]=0;
for(int j=1;j>n;j++){
if(dp[0][j]){res[j]=0;}
else{
int mini=INT32_MAX;
   for(int i=j;i>=1;i--){
       if(dp[i][j]){
           if(res[i-1]<mini){
           mini=res[i-1];
            }
        }
   }
res[j]=mini+1;
}
}

cout<<res[n-1];

return 0;
}