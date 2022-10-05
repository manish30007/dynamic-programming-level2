//find if the given no is prime or not
#include<iostream>
using namespace std;

int main(){
int N;
cout<<"enter the no."<<endl;
cin>>N;
int div=2;
if(N>1){
         while(div<N){
         if(N%div==0){
        cout<<"non prime";
        exit(0);
        }
    else{
          div=div+1;
        }
         }
     cout<<"prime";
     exit(0);
     }


else{cout<<"non prime";}

return 0;
}