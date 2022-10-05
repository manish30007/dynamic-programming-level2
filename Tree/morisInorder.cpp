
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};
TreeNode*getRightMostNode(TreeNode*leftNode,TreeNode*root){
while(leftNode->right!=NULL&& leftNode->right!=root){
   leftNode=leftNode->right;
}return leftNode;
}
vector<int> morrisInTraversal(TreeNode* root) {
    vector<int>ans;


while(root!=NULL){
    TreeNode*leftNode=root->left;
    if(leftNode==NULL){
    ans.push_back(root->val);
    root=root->right;
    }
    else{
        TreeNode*RightMostNode=getRightMostNode(leftNode,root);
        if(RightMostNode->right==NULL){
            RightMostNode->right=root;
            root=root->left;
        }
        else{
           RightMostNode->right=NULL;
           ans.push_back(root->val);
           root=root->right;
        }
    }
   
}
return ans;
}

TreeNode* createTree(vector<int>& arr, vector<int>& IDX)
{

  if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
  {
    IDX[0]++;
    return nullptr;
  }

  TreeNode* node = new TreeNode(arr[IDX[0]++]);
  node->left = createTree(arr, IDX);
  node->right = createTree(arr, IDX);

  return node;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  vector<int> IDX(1, 0);
  TreeNode* root = createTree(arr, IDX);

  vector<int> ans = morrisInTraversal(root);

  for (int i : ans)
  {
    cout << i << " ";
  }
}

int main()
{
// ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
  solve();
  return 0;
}