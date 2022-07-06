#pragma once
#include<vector>
using namespace std;
using Graph = vector<vector<int>>;

struct LCA{
  vector<vector<int>> parent;
  vector<int> dist;
  LCA(const Graph &G, int root=0){ init(G, root);}

  void init(const Graph &G, int root=0){
    int V = G.size();
    int K = 1;
    while((1<<K) < V) K++;
    parent.assign(K, vector<int>(V, -1));
    dist.assign(V, -1);
    dfs(G, root, -1, 0);
    for(int k=0; k+1<K;k++){
      for(int v = 0; v<V;v++){
        if(parent[k][v] < 0){
          parent[k+1][v] = -1;
        }else{
          parent[k+1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }

  // 根からの距離とひとつ先の頂点を求める
  void dfs(const Graph &G, int v, int p, int d){
    parent[0][v] = p;
    dist[v] = d;
    for(auto nx : G[v]){
      if(nx != p) dfs(G, nx, v, d+1);
    }
  }

  int query(int u, int v){
    if(dist[u] < dist[v]) swap(u, v);
    int K = parent.size();
    for(int k=0; k<K;k++){
      if((dist[u] - dist[v]) >> k & 1){
        u = parent[k][u];
      }
    }
    if(u == v) return u;
    for(int k=K-1;k>=0; k--){
      if(parent[k][u] != parent[k][v]){
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }

  int get_dist(int u, int v){
    int p = query(u, v);
    return dist[u] + dist[v] - 2 * dist[p];
  }
};