
#include<bits/stdc++.h>
using namespace std;
int inf = 1000000;
class Edge {
public:
  int u, v, wt;
  Edge(int u, int v, int wt) {
    this->u = u;
    this->v = v;
    this->wt = wt;
  }
};
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  int vtces, edges;
  cin >> vtces >> edges;
  vector<Edge>graph;
  for (int i = 0; i < edges; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    graph.push_back(Edge(u, v, wt));
  }
  int src = 1;
  vector<int>dist(vtces + 1, inf);
  dist[src] = 0;
  for (int i = 1; i <= vtces - 1; i++) {
    for (auto e : graph) {
      if (dist[e.u] + e.wt < dist[e.v]) {
        dist[e.v] = dist[e.u] + e.wt;
      }
    }
  }
  int fl = 0;
  for (auto e : graph) {
    if (dist[e.u] + e.wt < dist[e.v]) {
      cout << "negative cycle";
      fl = 1;
      break;
    }
  }
  if (fl == 1) {
    for (int i = 1; i < dist.size(); i++) {
      cout << dist[i] << " ";
    }
  }
  return 0;
}