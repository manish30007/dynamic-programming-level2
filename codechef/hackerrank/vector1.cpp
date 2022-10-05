#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
int N;
cin>>N;
int element;
vector<int>vec;
for(int i=1;i<=N;i++){
    cin>>element;
    vec.push_back(element);
}
int a,b,c;
cin>>a>>b>>c;
vec.erase(vec.begin()+(a-1));
vec.erase(vec.begin()+(b-1),vec.begin()+(c-1));
cout<<vec.size()<<endl;
for(int i=1;i<=vec.size();i++){
    cout<<vec.[i]<<" ";
}
return 0;
}
