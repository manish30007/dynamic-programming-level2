#include<bits/stdc++.h>
using namespace std;

int main(){
 int n;
 int m;
 cin>>n>>m;
 vector<vector<int>>rout(n,vector<int>(m));
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        cin>>rout[i][j];
     }
 }
 int src,dest;
 cin>>src>>dest;
 unordered_map<int,unordered_set<int>>mp;
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        mp[rout[i][j]].insert(i);
     }
 }
 queue<int>q;
 q.push(src);
 unordered_set<int>busno_vis;
 unordered_set<int>busstop_vis;
 busstop_vis.insert(src);
 int level=0;
 while(q.size()>0){
     int size=q.size();
     while(size-->0){
         int rem=q.front();
         q.pop();
         if(rem==dest){
             cout<<level;
             return 0;
         }
         unordered_set<int>buses=mp[rem];
         for(int bus:buses){
             if(busno_vis.find(bus)!=busno_vis.end()){continue;}
             vector<int>stops=rout[bus];
             for(int stop:stops){
                 if(busstop_vis.find(stop)!=busstop_vis.end()){continue;}
                 q.push(stop);
                 busstop_vis.insert(stop);
             }
             busno_vis.insert(bus);
         }
             }
level++;
         }
     
 
 cout<<"-1";
return 0;
}
