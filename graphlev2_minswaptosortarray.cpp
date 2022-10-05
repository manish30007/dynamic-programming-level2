#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int minswap(int arr[],int n){
    pair<int,int>arrpos[n];
    for(int i=0;i<n;i++){
        arrpos[i].first=arr[i];
        arrpos[i].second=i;
    }
    sort(arrpos,arrpos+n);
    int ans=0;
    vector<bool>visited(n+1,false);
    for(int i=0;i<n;i++){
        if(visited[i]==true||arrpos[i].second==i){
            continue;
        }
        int cycle_size=0;
        int j=i;
        while (!visited[j]){
            visited[j]=true;
            j=arrpos[j].second;
            cycle_size++;
        }
        if(cycle_size>0)
        ans+=cycle_size-1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
     cin>>arr[i];
 }
 cout<<minswap(arr,n);
    return 0;
}
