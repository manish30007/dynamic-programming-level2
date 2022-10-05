#include<bits/stdc++.h>
using namespace std;
int ccp(vector<int>&coins,int amt){
    vector<int>dp(amt+1,0);
    dp[0]=1;
    for(int i=1;i
    <=amt;i++){
        for(int j=0)
    }
}
int main(){
int n;
cin>>n;
vector<int>coins(n);
for(int i=0;i<n;i++){
    cin>>coins[i];
}
int amt;
cin>>amt;
cout<<ccp(coins,amt);
return 0;
}