#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:
    int val=0;
    int idx=0;
    Pair(int val,int idx){
        this->val=val;
        this->idx=idx;
    }  
};
bool mycomp(Pair const &p1,Pair const &p2){
return p1.val>p2.val;
}
int min_no_swap(vector<int>arrl){
    vector<Pair>arr;
    for(int i=0;i<arrl.size();i++){
        arr.push_back(Pair(arrl[i],i));
    }
sort(arr.begin(),arr.end(),mycomp);
vector<bool>visited(arr.size(),false);
int ans=0;
for(int i=0;i<arr.size();i++){
    if(visited[i]==true||arr[i].idx==i){
        continue;}
        int clen=0;
        int j=i;
        while(visited[j]==false){
            visited[j]=true;
            clen++;
            j=arr[j].idx;
        }
        ans+=clen-1;
    }
return ans;
}

int main(){
int n;
cin>>n;
vector<int>arr;
while(n--){
    int r;
    cin>>r;
    arr.push_back(r);
}
cout<<min_no_swap(arr);
return 0;
}