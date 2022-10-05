// // #include <iostream>
// // using namespace std;

// // int cs(int arr[], int n){
// // int dp[n+1];
// // for(int i=0;i<n+1;i++){
// //     dp[i]=0;
// // }
// // dp[n]=1;
// // for(int i=n-1;i>=0;i--){
// //     for(int j=1;j<=arr[i] &&i+j<=n;j++){
// //         dp[i]+=dp[i+j];
// //     }
// // }

// //     return dp[0];
// // }

// // int main(){
// //     int n;
// //     cin>>n;
// //     int arr[n];
// //     for(int i = 0 ; i < n ;i++){
// //         cin>>arr[i];
// //     }
// //     cout<<cs(arr,n)<<endl;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// int cs(int arr[], int n){
//     vector<int>dp(n+1);
//     dp[n]=1;
//     for(int i=n-1;i>=0;i--){
//         for(int j=1;j<=arr[i] && i+j<n+1;j++){
//             dp[i]+=dp[i+j];
//         }
//     }
//     return dp[0];
// }

// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i = 0 ; i < n ;i++){
//         cin>>arr[i];
//     }
//     cout<<cs(arr,n)<<endl;
// }
#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:
    int i,j,c;
    Pair(int i,int j,int c){
        this->i=i;
        this->j=j;
        this->c=c;
    }
};
int main(){
int m,n;
cin>>m>>n;
vector<vector<int>>arr(m,vector<int>(n));
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}
vector<vector<int>>dp(m,vector<int>(n));
dp[m-1][n-1]=arr[m-1][n-1];
for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
        if(i==m-1 &&j==n-1)continue;
        else if(i==m-1)dp[i][j]=arr[i][j]+dp[i][j+1];
        else if(j==n-1)dp[i][j]=arr[i][j]+dp[i+1][j];
        else{
            int mini=min(dp[i+1][j],dp[i][j+1]);
            dp[i][j]=mini+arr[i][j];
        }
    }
}
cout<<dp[0][0]<<endl;
return 0;
}

