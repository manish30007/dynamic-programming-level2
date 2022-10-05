#include<bits/stdc++.h>
using namespace std;
/*given n string print all string in lexicographical method*/
int main(){
set<string>s;
int n;
cin>>n;
while(n--){
    string str;
    cin>>str;
    s.insert(str);
}

for(auto value:s){
    cout<<value<<endl;
}
return 0;
}