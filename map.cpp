// // #include<bits/stdc++.h>
// // using namespace std;
// // void print(map<int,string>&m){
// //     cout<<m.size()<<endl;
// //     for(auto &pr:m){
// //         cout<<pr.first<<" "<<pr.second<<endl;
// //     }
// // }
// // int main(){
// // map<int ,string>m;
// // m[1]="abc";
// // m[5]="def";//O(log(n)) for insertion  a element in map
// // m[3]="ghi";
// // m[6]="str";
// // m.insert({4,"cst"}); //Inserting in a map
// // map<int ,string>::iterator it;
// // // for(it =m.begin();it!=m.end();it++){
// // // cout<<(*it).first<<" "<<(*it).second<<endl;
// // // }
// // cout<<endl<<endl;
// // // for(auto pr:m){//excertion of a element take O(log(n)) time
// // //     cout<<pr.first<<" "<<pr.second<<endl;
// // // }
// // // print (m);
// // auto iit=m.find(7);
// // if(iit==m.end())cout<<"No element "<<endl;
// // else{
// //     cout<<(*iit).first<<" "<<(*iit).second<<endl;
// // }
// // m.erase(iit);
// // // m.clear();
// // print(m);
// // map<string ,string>mp;
// // mp["abcd"]="ABCD";//time complexity is string.size()*log(n);
// // return 0;
// // }
// /*given n string ,print in lexicographical order with frequency of each string */
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// map<string,int>m;
// int t;
// cin>>t;
// while(t--){
// string s;
// cin>>s;
// // m[s]=m[s]+1;
// m[s]++;
// }
// for(auto &pr:m){
//     cout<<pr.first<<" "<<pr.second<<endl;
// }
// cout<<m["abc"];


