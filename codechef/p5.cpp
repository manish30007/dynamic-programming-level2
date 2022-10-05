#include <iostream>
#include<iomanip>

using namespace std;
int main(){
    int X;
    float Y;
   
    cin>>X;
    cin>>Y;
    if(((X%5)==0)&&((X+.50)<=Y)&&(X!=0)){
         float result=Y-(X+0.50);
    cout<<fixed<<setprecision(2)<<result<<endl;
    }
    else
    {
    cout<<fixed<<setprecision(2)<<Y<<endl;
    } 
    
    return 0;
}
//     #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
    
//     int X;
//     float Y;
    
//     cin>>X; //amt to withdraw
//     cin >>Y; // initial amt
    
   
//     if((X+0.50)<=Y && ((X%5) == 0) && (X!=0))
//     {   
//        float k =Y-(X+0.50);
//        cout<<fixed << setprecision(2)<<k;
//     }
// 	else 
// 	cout <<fixed << setprecision(2)<< Y;
	
	
// 	return 0;
// }

// }