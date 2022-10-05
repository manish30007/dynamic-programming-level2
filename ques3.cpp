#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:
    friend class person;
    int x;
    int y;
    Pair(){}
    Pair(int x,int y){
        this->x=x;
        this->y=y;
    }
};
class person{
    public:
    friend class Pair;
    string name;
    int age;
    char ctgy;
    int ct;
    Pair coord;
    int centre;

    person(){}
person(string name,int age,int ctgy,int ct,Pair coord,int centre){
    this->name=name;
    this->age=age;
    this->ctgy=ctgy;
    this->ct=ct;
    this->coord=coord;
    this->centre=centre;
}
};
double dist(Pair p1,Pair p2){
    int dx=p1.x-p2.x;
    int dy=p1.y-p2.y;
    dx=dx*dx;
    dy=dy*dy;
    double ans=sqrt(dx+dy);
    return ans;
}
struct mycomp{
    bool operator()(person const&p1,person const&p2){
if(p1.centre!=p2.centre){
    return p1.centre>p1.centre;
}
        else if(p1.age!=p2.age){return p1.age<p2.age;}
        else if(p1.ct!=p2.ct){
            return p1.ct<p2.ct;
        }
        else{
          return p1.name>p2.name;
        }
    }
};
int main(){
int m;
cin>>m;
vector<Pair>coor(m);
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    coor.push_back(Pair(x,y));
}
int n;
cin>>n;

priority_queue<person,vector<person>,mycomp>per;

for(int i=0;i<n;i++){
    string name;
    cin>>name;
    int age;
    cin>>age;
    int ct;
    char ctgy;

    cin>>ctgy;
    if(ctgy=='A'){
ct=1;
    }
    else ct=0;
    Pair coord;
    int x1,y1;
    cin>>x1>>y1;
    coord.x=x1;
    coord.y=y1;
    int centre=0;
    int dis=INT32_MAX;
    vector<person>prr;

    for(int i=0;i<=m;i++){
       int newdis=dist(coor[i],coord);
       if(newdis<dis){dis=newdis;
       centre=i+1;
       }
    }
//     2
// 0 0
// 0 10
// 5
// atul 24 A 0 1
// sunil 24 B 0 5
// rajni 23 A 0 1
// salman 21 B 0 12
// kunal 24 A 0 2
   
    per.push(person(name,age,ctgy,ct,coord,centre)); 
}
int i=1;
while(per.size()>0){
    auto val=per.top();
    cout<<val.name<<" "<<val.centre<<" "<<endl;
    per.pop();
//    auto val = per.top();
//    if(val.centre != i)
//    {
//        cout<<"Empty Center"<<"\n";
//        i++;
//        continue;
//    }
//    while(per.top().centre == i)
//    {   
//        cout<<per.top().name<<" ";
//        per.pop();
//    }
//    i++;
//    cout<<"\n";

}
return 0;}


// #include<bits/stdc++.h>
// #include "includes/user_functions.cpp"
// using namespace std;
// typedef long long ll;
// typedef pair<int,int>  pii;
// typedef pair<ll, ll>   pll;
// typedef vector<int>    vi;
// typedef vector<ll>     vl;
// typedef vector<pii>    vpii;
// typedef vector<pll>    vpll;
// typedef vector<vi>     vvi;
// typedef vector<vl>     vvl;
// #define nline cout<<"\n";
// #define PI 3.1415926535897932384626
// #define fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
// const int mod = 1000000007;

// int op = 0; int minop = INT_MAX;

// void minWebpages_dfs(vector<int> adj[], vector<int> &vis, int n , int src, int des)
// {  
//     // cout<<src<<"\n";
//     if(src == des)
//     {
//       minop = min(minop, op);
//       op--;
//       return;
//     }

//    vis[src] = 1;

//    for(auto it: adj[src])
//    {
//        if(vis[it] == 0)
//        { 
//          op++;
//         //  cout<<op<<" ";
//          minWebpages_dfs(adj, vis, n, it, des);
//        }
      
//    }

//    vis[src] = 0; op--;
// //    cout<<op<<"\n";

// }


// void minWebpages(vector<int> adj[], int n, int src, int des)
// {
//    vector<int> vis(n+1,0);
// //    vector<int> distance(n, INT_MAX);
//    minWebpages_dfs(adj,vis,n,src,des);
//    }

// int main(void)
// {
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// freopen("input.txt","r", stdin);
// freopen("output.txt", "w", stdout);


// int n,src,des;
// cin>>n;
// cin.get();
// vector<int> adj[n+1];

// int i =1;

// // if(cin.get() == '\n')
// // i++;

//  while(i<=n)
//   { 
   
//     int x;
//     x =  cin.get();
//     // cout<<"x:"<<x<<" ";  nline;

//     if(x>=48 && x<=57)
//     adj[i].push_back(x-48);

//     if(x == '\n')
//     {
//         i++;
//     }
//   }

// cin>>src>>des;


// //  cout<< adj[2][0]<<"\n";
// // for(auto it: adj)
// // {
// //   for(int i= 0; i<it.size(); ++i)
// //   {
// //       cout<<it[i]<<" ";
// //   }
// //   cout<<"\n";
// // }

// // cout<<src<<" "<<des<<"\n";

// minWebpages(adj,n,src,des);

// // nline;
// if(minop == INT_MAX)
// cout<<-1;
// else
// cout<<minop;




// return 0;
// }




