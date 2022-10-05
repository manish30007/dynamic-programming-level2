 #include<bits/stdc++.h>
 using namespace std;
 int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>v;
        int N=2;
        int i=1;
        int d=nums[i-1]-nums[i];
        while(i<nums.size()){
            if(nums[i]-nums[i+1]==d){
                N++;
                i++;
            }
            else{
                v.push_back(N);
                d=nums[i]-nums[i+1];
                N=2;
                i++;
            }
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>=3){
                int x=v[i]-3+1;
                ans+=(x*(x+1))/2;
            }
        } 
        return ans;
    }
 int main(){
 
 int n;
 cin>>n;
 vector<int>nums(n,0);
 for(int i=0;i<n;i++){
     cin>>nums[i];
 }
 cout<<numberOfArithmeticSlices(nums);
 return 0;
 }
 