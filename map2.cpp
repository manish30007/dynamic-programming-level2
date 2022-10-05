#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string ,int>m;
int n;
cin>>n;

while(n--){
    string s;
    cin>>s;
    m[s]++;
}
int t;
cin>>t;
while(t--){
string s;
cin>>s;
cout<<m[s]<<endl;
}
return 0;
}