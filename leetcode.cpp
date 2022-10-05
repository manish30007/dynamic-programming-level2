#include<bits/stdc++.h>
using namespace std;
vector<int>countbit(int n){
    vector<int>ans(n+1,0);
for(int i=0;i<=n;i++){
    if(i%2==0){
        ans[i]=ans[i/2];}
        else{ans[i]=ans[i/2]+1;}
    
}
return ans;
}
int main(){

int t;
cin>>t;
vector<int>v=countbit(t);
for(auto val:v){
    cout<<val<<endl;
}
return 0;
}