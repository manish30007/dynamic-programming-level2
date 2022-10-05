// #include<bits/stdc++.h>
// using namespace std;
// int coinCombination(int n,vector<int>&arr,int amt){
    
//     vector<int>dp(amt+1);
//     for(int i=0;i<amt+1;i++){dp[i]=0;}
//     dp[0]=1;
//    for(int i=0;i<n;i++){
//        for(int j=arr[i];j<=amt;j++){
//            dp[j]+=dp[j-arr[i]];
//        }
//    } 
//    return dp[amt];
// }
// int main(){
//   int n;
//   cin>>n;
//   vector<int>arr(n);
//   for(int i=0;i<n;i++){
//       cin>>arr[i];
//   }
//   int amt;
//   cin>>amt;
//    cout<<coinCombination(n,arr,amt);
    
// }
#include <iostream>
#include <vector>
using namespace std;

int coinchangecombination(vector<int>coins, int amt, vector<int>dp) {
 dp[0]=1;
for(int i=0;i<coins.size();i++){
  for(int j=1;j<=dp.size();j++){
    if(j>=coins[i]){
    dp[j]+=dp[j-coins[i]];
    }
  }
}
return dp[amt];  
}

int main() {
  int n;
  cin >> n;
  vector<int> coins(n, 0);
  for (int i = 0; i < coins.size(); i++) {
    cin >> coins[i];
  }
  int amt;
  cin >> amt;
  vector<int> dp(amt + 1, 0);
  coinchangecombination(coins, amt, dp);
}