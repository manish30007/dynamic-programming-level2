#include<iostream>
using namespace std;

int main(){
int T;
cin>>T;
int result[T];
for(int i=0;i<T;i++){
    int A,B;
    cin>>A>>B;
    result[i]=A+B;
}
for(int i=0;i<T;i++){
    cout<<result[i]<<endl;
}
return 0;
}