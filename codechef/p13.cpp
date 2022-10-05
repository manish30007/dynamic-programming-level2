#include<iostream>
#include<list>
#include<functional>
#include<algorithm>
using namespace std;
void display(list<int>lst){
    list<int>::iterator itr;
    for(itr=lst.begin();itr!=lst.end();itr++){
    cout<<(*itr)<<" ";}
    cout<<endl;
}
class player{
int score;
public:
int  input(){
   
    cin>>score;
    int y;
   y=score;
   return y;
}
};
int main(){
int N;

cin>>N;
list<int> lead1;
list<int> lead2;
int s1=0,s2=0;
while(N--){
player p1,p2;
s1+=p1.input();
s2+=p2.input();
if(s1>s2){
lead1.push_back(s1-s2);
}
else
if(s2>s1){
lead2.push_back(s2-s1);
}
}
lead1.sort();
lead2.sort();

display(lead1);
display(lead2);
list<int>::iterator itr;
itr=lead1.end();

list<int>::iterator itr1;
itr1=lead2.end();

if(*itr>(*itr1)){
    cout<<"1 "<<*itr;
}
else{
    cout<<"2 "<<*itr1;
}


return 0;
}