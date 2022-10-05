#include<iostream>
using namespace std;

int main(){
int N;
cin>>N;
for(int i=0;i<N;i++){
    int n;
    cin>>n;
    int y=n%10;
while(n){
    n/=10;
}
int result=n+y;
cout<<result<<endl;
}

return 0;
}