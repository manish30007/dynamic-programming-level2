#include<iostream>
#include<list>
using namespace std;
void display(list<int>lst){
    list<int>::iterator itr;
    for(itr=lst.begin();itr!=lst.end();itr++)
    cout<<(*itr)<<endl;
}
int main(){
int t;
cin>>t;
list<int>list1;
for(int i=0;i<t;i++){
int x;
cin>>x;
list1.push_back(x);
}
list1.sort();
display(list1);
return 0;
}