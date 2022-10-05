#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
  int N;
  cin>>N;
 
  
  map<string,int>markmap;
  for(int i=0;i<N;i++){
       int QueryNo;
      cin>>QueryNo;
      if(QueryNo==1){
          string s;
          int marks;
          cin>>s>>marks;
          markmap.insert(make_pair(s,marks));
      }
      else if (QueryNo==2){
          string s;
          cin>>s;
          markmap.erase(s);
          markmap.insert(make_pair(s,0));
      }
      else if(QueryNo==3){
          string s;
          cin>>s;
          cout<<markmap[s]<<endl;
      }
  }
  map<string,int>::iterator itr;
for ( itr = markmap.begin(); itr !=markmap.end(); itr++)
{
    cout<<(*itr).first<<" "<<(*itr).second<<"\n";
}
    return 0;
}



 