#include<bits/stdc++.h>
using namespace std;
int find(int a, vector<int>& parent) {
  if (a == parent[a])return a;
  return parent[a] = find(parent[a], parent);
}

vector<int>numIslands(int m, int n, vector<vector<int>>& pos) {
  vector<int>ans;
  if (m <= 0 || n <= 0)return ans;
  int count = 0;
  vector<int>parent(m * n, -1);
  vector<int>size(m * n, 0);
  int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for (vector<int>p : pos) {
    int island = p[0] * n + p[1];
    parent[island] = island;
    size[island]++;
    count++;

    for (int i = 0; i < 4; i++) {
      int rd = p[0] + dir[i][0];
      int cd = p[1] + dir[i][1];
      int nbr = rd * n + cd;
      if (rd < 0 || cd < 0 || rd >= m || cd >= n || parent[nbr] == -1) {
        continue;
      }
      int lx = find(island, parent);
      int ly = find(nbr, parent);
      if (lx != ly) {
        if (size[lx] > size[ly]) {
          parent[ly] = lx;
          size[lx] += size[ly];
        }
        else {
          parent[lx] = ly;
          size[ly] += size[lx];
        }
        count--;
      }
      
    }
    ans.push_back(count);

  }

return ans;
}
int main() {
  int m, n, k;
  cin >> m >> n >> k;
  vector<vector<int>>pos(k, vector<int>(2));
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    pos[i][0] = u;
    pos[i][1] = v;
  }
auto ans= numIslands(m, n, pos);
for(auto &pr:ans)cout<<pr<<" ";

  return 0;
}