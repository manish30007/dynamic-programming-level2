#include<iostream>
using namespace std;

int main(){
int T,n,sum;
cin>>T;
for(int i=0;i<T;i++){
cin>>n;
sum=0;
while(n){
sum+=n%10;
n/=10;

}
cout<<sum;
}
return 0;
}