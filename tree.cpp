// #include<bits/stdc++.h>
// #include<climits>

// using namespace std;

// class Node
// {
// public:
//   int data = 0;
//   vector<Node*> children;

//   Node(int data)
//   {
//     this->data = data;
//   }
// };


// void display(Node* node)
// {
//   string s = "";
//   s += to_string(node->data) + " Child: ";
//   for (Node* child : node->children)
//   {
//     s += to_string(child->data) + ", ";
//   }

//   cout << s << "." << endl;

//   for (Node* child : node->children)
//   {
//     display(child);
//   }
// }
// Node* constructor01(vector<int>& arr)
// {
//   if (arr.size() == 0)
//     return NULL;

//   vector<Node*> stack;
//   stack.push_back(new Node(arr[0]));

//   Node* root = stack[0];

//   for (int i = 1; i < arr.size(); i++)
//   {
//     if (arr[i] != -1)
//     {
//       Node* node = stack.back();
//       Node* nnode = new Node(arr[i]);

//       node->children.push_back(nnode);
//       stack.push_back(nnode);
//     }
//     else
//       stack.pop_back();
//   }
//   return root;
// }
//  void dfs(Node*node,string &h){
//     h+="r";
//   for(auto child:node->children){
//   dfs(child,h); 
//   }
//   h+="b";
//   }
//   bool areSimilar(Node* n1, Node* n2) {
//   string h1="";
//   string h2="";
//   dfs(n1,h1);
//   dfs(n2,h2);
//   cout<<h1<<" "<<h1<<endl;
//   if(h1==h2){
//   return true;
//   }
//   return false;
//   }
// void solve()
// {
//   int n;
//   cin >> n;
//   vector<int>arr(n, 0);
//   for (int i = 0; i < arr.size(); i++)
//   {
//     cin >> arr[i];
//   }
// int m;
// cin>>m;

// vector<int>arr1(m, 0);
//   for (int i = 0; i < arr1.size(); i++)
//   {
//     cin >> arr1[i];
//   }  

//   Node* root1 = constructor01(arr);
//     Node* root2 = constructor01(arr1);
// bool similar=areSimilar(root1,root2);
// if(similar==1)cout<<"true";
// else cout<<"false";
// }
// int main()
// {
//   solve();
//   return 0;
// }
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
stack<Pair>st;
st.push(Pair(root,-1));
string pre="";
string post="";
while(st.size()>0){
    Pair Top=st.top();
   st.pop();
    if(Top.state==-1){
       pre+=to_string(Top.node->data)+" ";
       Top.state++;
       st.push(Top);
    }else if(Top.state==Top.node->children.size()){
    post+=to_string(Top.node->data)+" ";

    }
    else{
      Pair cp= Pair(Top.node->children[Top.state],-1);
      st.push(Top);
      st.push(cp);
      Top.state++;
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