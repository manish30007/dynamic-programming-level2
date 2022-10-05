#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void path(int i,int j,int m,int n ,int &count){ 
    if(i>=m||j>=n)return ;
    if(i==m-1&&j==n-1)count+=1;
    path(i+1,j,m,n,count);
    path(i,j+1,m,n,count);
    
}
    int uniquePaths(int m, int n) {
        int count=0;
        path(0,0,m,n,count);
        return count;
    }

int main() {
   
 cout<<uniquePaths(3,2);
    return 0;
}
