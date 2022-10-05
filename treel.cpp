#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  vector<Node*>children;
};
class Pair{
    public:
    Node*node;
    int state;
    Pair(Node*node,int state){
        this->node=node;
        this->state=state;
    }
};
void iterativePreAndPostOrder(Node* root) {
stack<pair<Node*,int>>st;
st.push({root,-1});
string pre;
string post;
while(st.size()>0){
    pair<Node*,int> top=st.top();
   st.pop();
    if(top.second==-1){
       pre+=to_string(top.first->data)+" ";
       top.second++;
       st.push(top);
    }
    else if (top.second >= 0 and top.second < top.first->children.size()){
      pair<Node*,int>cp(top.first->children[top.second],-1);
      st.push(top);
      st.push(cp);
      top.second++;
    }else{
    post+=to_string(top.first->data)+" ";

    }
    
}
cout<<pre<<endl;
cout<<post<<endl;
}

Node* construct(vector<int>& arr) {
  Node* root = nullptr;

  stack <Node*> st;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == -1) {
      st.pop();
    } else {
      Node* t = new Node();
      t->data = arr[i];

      if (st.size() > 0) {
        st.top()->children.push_back(t);
      } else {
        root = t;
      }
      st.push(t);
    }
  }
  return root;
}

int main() {
  int n, x;
  cin >> n;
  vector<int>arr;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
  Node* root = construct(arr);
  iterativePreAndPostOrder(root);
}