#include<bits/stdc++.h>
using namespace std;
void print(set<string>&s){
    for(string value:s){
        cout<<value<<endl;
    }
}
int main(){
set<string>s;
s.insert("abc");
s.insert("zsdf");//log(n)
s.insert("bcd");
s.insert("abc");

auto it=s.find("abc");
// if(it!=s.end()){cout<<(*it);}
s.erase(it);
s.erase("zsdf");

print (s);
return 0;
}