#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void makeset(int vtces,int parenta[],int parentb[],int sizea[],int sizeb[]){
for(int i=1;i<=vtces;i++){
    parenta[i]=i;
    parentb[i]=i;
    sizea[i]=1;
    sizeb[i]=1;
}
}
int find(int a,int parent[]){
    if(a==parent[a])return a;
    return parent[a]=find(parent[a],parent);
}
bool Union(int a,int b,int parent[],int size[]){
    a=find(a,parent);
    b=find(b,parent);
  if(a!=b){
      if(size[a]<size[b])swap(a,b);
      parent[b]=a;
      size[a]+=size[b];
      return true;
  }
  return false;
}
int main() {
int vtces,edges;
cin>>vtces>>edges;
int parenta[10000000];
int parentb[10000000];
int sizea[10000000];
int sizeb[10000000];
makeset(vtces,parenta,parentb,sizea,sizeb);
vector<vector<int>>adj;
for(int i=0;i<edges;i++){
int t,u,v;
cin>>t>>u>>v;
vector<int>temp;
temp.push_back(t);
temp.push_back(u);
temp.push_back(v);
adj.push_back(temp);

}
sort(adj.begin(),adj.end());
int mergea=1;
int mergeb=1;
int rem=0;
for(vector<int>pr:adj){
    if(pr[0]==3){
bool tempa=Union(pr[1],pr[2],parenta,sizea);
bool tempb=Union(pr[1],pr[2],parentb,sizeb);
if(tempa==true){mergea++;}
if(tempb==true){mergeb++;}
if(tempa==false &&tempb==false)rem++;
    }else if(pr[0]==1){
bool tempa=Union(pr[1],pr[2],parenta,sizea);
if(tempa==true){mergea++;}
else{rem++;}
    }else{
bool tempb=Union(pr[1],pr[2],parentb,sizeb);
if(tempb==true){mergeb++;}
else{rem++;}
    }
}
if(mergea==vtces&&mergeb==vtces)
cout<<rem; 
else 
cout<<-1;
return 0;
}
