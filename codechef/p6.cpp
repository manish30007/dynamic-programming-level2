#include<iostream>
using namespace std;

int main(){
int a,b,c;
cout<<"enter three nos to compare"<<endl;
cin>>a>>b>>c;
cout<<"max. of 3 :"<<endl;
if(a>b){
    if(a>c){
        cout<<a;
    }
    else{cout<<c;}
}
else{
    if(b>c){
        cout<<b;
    }
    else{cout<<c;}
}
return 0;
}