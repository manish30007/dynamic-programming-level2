#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int parent[100000];
int size[100000];
void makeset(int n){
    for(int i=1;i<=n;i++){
         parent[i]=i;
         size[i]=1;
    }
}
int findPar(int node){
	if(node==parent[node])return node;
	return parent[node]=findPar(parent[node]);
}
void Union(int a,int b){
a=findPar(a);
b=findPar(b);
if(a!=b){
	if(size[a]<size[b]){
		parent[a]=b;
		size[b]+=size[a];
	}
	else(size[a]>size[b]){
		parent[b]=a;
		size[a]+=size[b];
	}	
}
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 int n;
 cin>>n;
makeset(n);
int k;
cin>>k;
while(k--){
	int i,j;
	cin>>i>>j;
	Union(i,j);
}
int connected_comp=0;
for(int i=1;i<=n;i++){
	if(findPar(i)==i)connected_comp++;
}
cout<<connected_comp;
    return 0;
}
