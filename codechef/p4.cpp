#include<iostream>
using namespace std;
int factorial(int n){
 if (n<1){
     return 1;
 }
 else{return n*factorial(n-1);}
    
   
}
int main(){
int T,n;
cin>>T;
for(int i=0;i<T;i++){
cin>>n;
int r=factorial(n);
cout<<r<<endl;
}
return 0;
}
