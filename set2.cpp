// #include<bits/stdc++.h>
// using namespace std;
// /*given n string and q queries.
// In each query you are given a string 
// print yes if string  is present 
// else print no*/

// int main(){
// int n;
// cin>>n;
// unordered_set<string>s;
// while(n--){
//     string st;
//     cin>>st;
// s.insert(st);
// }
// int t;
// cin>>t;
// while(t--){
//     string str;
//     cin>>str;
//     auto it=s.find(str);
//     if(it!=s.end())cout<<"yes"<<endl;
//     else cout<<"No"<<endl; 
// }

// return 0;
// }
#include<bits/stdc++.h>
using namespace std;
void print(unordered_set<string>&s){
    for(auto value:s){
        cout<<value<<endl;
    }
}
int main(){
unordered_set<string>s;
s.insert("abc");
s.insert("abd");
s.insert("bcd");
s.insert("bce");//log(1)
// print(s);
auto it=s.find("bcd");
if(it!=s.end()){
    s.erase(it);
}
print(s);
return 0;
}