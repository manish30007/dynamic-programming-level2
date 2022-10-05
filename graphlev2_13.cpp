// #include<bits/stdc++.h>
// using namespace std;
// string alienword(int n, vector<string>word) {
//   unordered_map<char, unordered_set<char>>graph;
//   unordered_map<char, int> indegree;

//   for (string st : word) {
//     for (char ch : st) {
//       indegree.insert({ch,0});
//     }
//   }
//   for (int i = 0; i < n - 1; i++) {
//     string curr = word[i];
//     string next = word[i + 1];
//     bool flag=false;
//     int len = min(next.length(), curr.length());
//     for (int j = 0; j < len; j++) {
//       char ch1 = curr[j];
//       char ch2 = next[j];
//       if (ch1 != ch2) {
//         unordered_set<char>sets;
//         if (graph.find(ch1) != graph.end()) {
//           sets = graph[ch1];
//           if (sets.find(ch2) != sets.end()) {
//             sets.insert(ch2);
//             indegree[ch2]++;
//             graph[ch1] = sets;
//           }
//         }
//         else {
//           sets.insert(ch2);
//           indegree[ch2]++;
//           graph[ch1] = sets;
//         }
//         break;
//         flag=true;
//       }
//     }
//     if(flag==false&& curr.length()>next.length()){
//       return "";
//     }
//   }
//   queue<char>q;
//   string ans = "";
// //   unordered_map<char, int>indegree::iterator it;
//   for (auto &pr:indegree) {
//     if (pr.second == 0) {
//       q.push(pr.first);
//     }
//   }
//   int count = 0;
//   while (q.size() > 0) {
//     char rem = q.front();
//     q.pop();
  
//     ans +=rem;
//     count++;
//     if (graph.find(rem)!=graph.end()){
//         unordered_set<char>nbrs=graph[rem];
//         for(char nbr:nbrs){
//             indegree[nbr]--;
//             if(indegree[nbr]==0){
//                 q.push(nbr);
//             }
//         }   
//     }
//  }
//     if(count==indegree.size()){
//         return ans;
//     }
//     else{return "";}
// }
// int main() {
//   int n;
//   cin >> n;
//   vector<string>word;
//   for (int i = 0; i < n; i++) {
//     string s;
//     cin >> s;
//     word.push_back(s);
//   }
//   cout << alienword(n, word);
//   return 0;
// }

//**leetcode**alienOrder
class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &word) {
      int n=word.size();
      if(n==0){return "";}
        unordered_map<char, unordered_set<char>>graph;
  unordered_map<char, int> indegree;
 if (word.size() == 0){
      return "";}
  for (string st : word) {
    for (char ch : st) {
      indegree.insert({ch,0});
    }
  }
  for (int i = 0; i < n - 1; i++) {
    string curr = word[i];
    string next = word[i + 1];
    bool flag=false;
    int len = min(next.length(), curr.length());
    for (int j = 0; j < len; j++) {
      char ch1 = curr[j];
      char ch2 = next[j];
      if (ch1 != ch2) {
        unordered_set<char>sets;
        if (graph.find(ch1) != graph.end()) {
          sets = graph[ch1];
          if (sets.find(ch2) == sets.end()) {
            sets.insert(ch2);
            indegree[ch2]++;
            graph[ch1] = sets;
          }
        }
        else {
          sets.insert(ch2);
          indegree[ch2]++;
          graph[ch1] = sets;
        }
        flag=true;
        break;
      }
    }
    if(flag==false && curr.length()>next.length()){
      return "";
    }
  }
priority_queue<char, vector<char>, greater<char> > q;
  string ans = "";
//   unordered_map<char, int>indegree::iterator it;
  for (auto &pr:indegree) {
    if (pr.second == 0) {
      q.push(pr.first);
    }
  }
  int count = 0;
  while (q.size() > 0) {
    char rem = q.top();
    q.pop();
  
    ans +=rem;
    count++;
    if (graph.find(rem)!=graph.end()){
        
        unordered_set<char>nbrs=graph[rem];
        for(char nbr:nbrs){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
        
    }
    }
    if(count==indegree.size()){
        return ans;
    }
    else{return "";}
    }
};