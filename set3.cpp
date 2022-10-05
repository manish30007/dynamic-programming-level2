#include<bits/stdc++.h>
using namespace std;
void print(multiset<string>&s){
    for(auto value:s){
        cout<<value<<endl;
    }
}
int main(){
multiset<string>s;

s.insert("abc");
s.insert("def");
s.insert("ghi");
s.insert("abc");
s.insert("ghi");
auto it=s.find("abc");
if(it!=s.end()){
    s.erase("ghi");
}
print(s);
return 0;
}