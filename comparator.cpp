#include<bits/stdc++.h>
using namespace std;
// bool compa(pair<int,int>a,pair<int ,int>b){
//     if(a.first!=b.first){
//         if(a.first>b.first)return false ;
//         return true;
//     }
//     else {
//         if(a.second<b.second)return true;
//         return false;
//     }
// }
bool comp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    else{
        return a.second>b.second;
    }
}
int main(){
int n;
cin>>n;
vector<pair<int,int>>a(n);
for(int i=0;i<n;i++){
    cin>>a[i].first>>a[i].second;
}
// for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         if(compa(a[i],a[j])){
//             swap(a[i],a[j]);
//         }
//     }
// }
sort(a.begin(),a.end(),comp);
cout<<endl;
for(int i=0;i<n;i++){
    cout<<a[i].first<<" "<<a[i].second<<endl;
}
cout<<endl;
return 0;
}