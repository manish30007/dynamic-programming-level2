class Solution {
public:
    vector<int> partitionLabels(string s) {
unordered_map<char,int>mp;
for(int i=0;i<s.size();i++){
    mp[s[i]]=i;
}
int pre=-1;
int maxx=0;
vector<int>ans;
for(int i=0;i<s.size();i++){
    maxx=max(maxx,mp[s[i]]);
    if(i==maxx){
ans.push_back(maxx-pre);
pre=maxx;
    }
}
return ans;
    }
};
//time complexity O(N);
//space complexity O(N);
