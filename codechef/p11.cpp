#include<iostream>
using namespace std;

int main(){
int N;
cin>>N;

for(int i=0;i<N;i++){
    int x;
    cin>>x;
     int count=0;
    while(x){
   
    if((x%10)==4){
        count++;
    }
    x/=10;
    }
  cout<<count<<endl;
}
return 0;
}g
