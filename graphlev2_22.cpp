#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
vector<int>size;
int find(int node){if(node==parent[node])return node;
return parent[node]=find(parent[node]);}
void Union (int u,int v){
    u=find(u);
    v=find(v);
    if(u!=v){
    if(size[u]<size[v]){
        parent[u]=v;size[v]+=size[u];
    }else{
        parent[v]=u;size[u]+=size[v];
    }
    }
}
bool Issimilar(vector<string>&sen1,vector<string>&sen2,vector<vector<string>>&Pair){
    int n=sen1.size();
parent.resize(2*n);
size.resize(2*n);
for(int i=0;i<2*n;i++){
    parent[i]=i;
    size[i]=1;
}
unordered_map<string,int>mp;
int count=0;
for(int i=0;i<n;i++){
    mp[sen1[i]]=i;
    count++;
}
for(int i=count;i<2*n;i++){
    mp[sen2[i-count]]=i;
}
for(vector<string>pr:Pair){
    int u=find(mp[pr[0]]);
    int v=find(mp[pr[1]]);
    Union(u,v);
}

for(int i=0;i<n;i++){
    int lx=find(mp[sen1[i]]);
    int ly=find(mp[sen2[i]]);
    if(lx!=ly){return false;}
}
return true;
}
int main(){
int n;
cin>>n;
vector<string>sen1(n);
vector<string>sen2( n);
for(int i=0;i<n;i++){
    cin>>sen1[i];
}
for(int i=0;i<n;i++){
    cin>>sen2[i];
}
int m;
cin>>m;
vector<vector<string>>Pair(m,vector<string>(2));
for(int i=0;i<m;i++){
    string s1,s2;
    cin>>s1>>s2;
    Pair[i][0]=s1;
    Pair[i][1]=s2;
}
if(Issimilar(sen1,sen2,Pair))cout<<"true";
else cout<<"false";
return 0;
}