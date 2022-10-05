#include<bits/stdc++.h>
using namespace std;
class Pair{
    public: 
    int x;
    int y;
    Pair(int x,int y){
        this->x=x;
        this->y=y;
    }
};
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>arr(n,vector<int>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
}
int fresh=0;
queue<Pair>q;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i][j]==2){
            q.push(Pair(i,j));
        }
        else if(arr[i][j]==1){
            fresh++;
        }
    }
}
if(fresh==0){cout<<"0";
return 0;}
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
 int tim=-1;
while(q.size()>0){
    int size=q.size();
    tim++;
    while(size-->0){
        Pair rem=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int rdash=rem.x+dir[i][0];
            int cdash=rem.y+dir[i][1];
            if(rdash>=0 && cdash>=0 && rdash<arr.size()&&cdash<arr[0].size()&&arr[rdash][cdash]==1){
                q.push(Pair(rdash,cdash));
                arr[rdash][cdash]=0;
                fresh--;
            }
        }
    }
}
if(fresh==return )cout<<tim;
else cout<<"-1";
return 0;
}