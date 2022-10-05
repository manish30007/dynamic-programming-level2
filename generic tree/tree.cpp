#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    vector<Node*>children;
};
Node* newnode(int n){
     Node* node=new Node;
     node->data=n;
     return node;
}
Node* construct(vector<int>arr,int n){
    Node*root=nullptr;
    stack<Node*>st;
    for(int i=0;i<n;i++){
if(arr[i]==-1)st.pop();
else{
    Node*t=newnode(arr[i]);
    if(st.size()==0){
root=t;
    }else{
        st.top()->children.push_back(t);
    }
    st.push(t);
}
    }
    return root;
}
void display(Node* node){
cout<<node->data<<"->";
for(Node* T:node->children){
cout<<T->data<<",";
}
cout<<"."<<endl;
for(Node* T:node->children){
    display(T);
}
}
int main() {

vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};  
Node*root=construct(arr,arr.size());
display(root);
    return 0;
}
