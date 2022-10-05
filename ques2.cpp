#include<bits/stdc++.h>
using namespace std;
void split_c(string str,vector<string>&v)
{
    string w = "";
    for (auto x : str) 
    {
        if (x == ',')
        {
           v.push_back(w);
            w = "";
        }
        else {
            w = w + x;
        }
    }
   v.push_back(w); 
}
int main(){
int N;
cin>>N;
int R;
cin>>R;
string str;
cin>>str;
 
 
    vector<string> v;
 
   split_c(str,v);

    vector<vector<string>>ans;
    ans[0].push_back("");
   vector<vector<string>>q;
    for(int i=0;i<v.size();i++){
        vector<string>temp;
        temp.push_back(v[i]);
       ans.push_back(temp);
       q[i]=temp;
    }
  for(int i=0;i<ans.size();i++){
      cout<<ans[i][0]<<"*";
  }
  for(int k=1;k<v.size();k++){
    int j=k;
    while(j<v.size()){
    vector<string>h=q.front();
    h.push_back(v[j]);
    q.push_back(h);
    q.erase(q.begin());
    ans.push_back(h);
    }
  }
  for(int i=0;i<ans[R-1].size();i++){
    if(i!=ans[R-1].size()-1){
 cout<<ans[R-1][i]<<",";}
 cout<<ans[R-1][i];}
return 0;
}