#include <bits/stdc++.h>
using namespace std;
void subString(string str, int n,unordered_map<string,int>&mp)
{
    // Pick starting point
    for (int len = 1; len <= n; len++)
    {   
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            //  Print characters from current
            // starting point to current ending
            // point. 
            string s="";
            int j = i + len - 1;           
            for (int k = i; k <= j; k++)
                s+= str[k];
mp.insert({s,i});
        
            
        }
    }
}
int main() {
    string s1,s2;
    cin>>s1>>s2;
unordered_map<string,int>mp;
subString(s1,s1.size(),mp);
cout<<mp[s2];
   return  0;
}
