 public: 
    //Function to convert binary tree to doubly linked list and return it.
  void addallleft(Node*curr ,stack<Node*>&st){
  
      while(curr!=NULL){
    st.push(curr);
    curr=curr->left;
    }
}
Node*pre=NULL;
Node* bToDLL(Node* root)
{
    if(root==NULL)return root;
  Node*d=newNode(1);
  pre=d;
  stack<Node*>st;

  addallleft(root,st);
  while(st.size()>0){
    Node*curr=st.top();
    st.pop();
    pre->right=curr;
    curr->left=pre;
    pre=curr;
    addallleft(curr->right,st);
  }
Node*head=d->right;
head->left=d->right=NULL;
 return head;
}