#include <iostream>
#include <cstdio>
using namespace std;
int maxof3(int a,int b,int c){
if(a>b){
    if(a>c){
        return a;
    }
    else{return c;}
}
else{
    if(b>c){
        return b;
    }
    else{return c;}
}
 }
void max(int x,int y,int z,int d){
  
int p=maxof3(x,y,z);
    if(p>d){
    cout<<p;}
    else{
    cout<<d;}
}
int main()
{
    int x,y,z,d;
    cin>>x>>y>>z>>d;
    max(x,y,z,d);
    return 0;
}