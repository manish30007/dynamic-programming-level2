#include<iostream>
#include<algorithm>
using namespace std;

int main(){
int N;
cin>>N;

for(int i=0;i<N;i++){
int x,reversednum=0;
    cin>>x;
 while(x!=0){
  int y= x%10;
  
   reversednum=reversednum*10+y;
    x/=10;
 }
    cout<<reversednum<<endl;
}
return 0;
}