#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};
Node*construct(vector<int>&arr,int lo,int hi){
int mid=(lo+hi)/2;
int data=arr[mid];
Node*lc=construct(arr,lo,mid-1);
Node*lc=construct(arr,mid+1,hi);
Node*node=new(data);
node->left=lc;
node->right=rc;
return node;

}



int min(Node* node) {
//     Write your code here
}

int max(Node* node) {
//     Write your code here
}

int sum(Node* node) {

//     Write your code here
}


int size(Node* node) {

//     Write your code here
}


bool find(Node* node, int data) {

//     Write your code here
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (x == "n") {
      arr[i] = -1;

    }
    else {
      arr[i] = stoi(x);
    }
  }
  int data;
  cin >> data;
  Node* root = construct(arr);
  cout << size(root) << "\n" << sum (root) << "\n" << max(root) << "\n" << min(root) <<  "\n";
  if (find(root, data)) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
}