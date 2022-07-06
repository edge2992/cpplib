---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/lca.aoj_GRL_5_C.test.cpp
    title: test/graph/lca.aoj_GRL_5_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lca.hpp\"\n\n\n#include<vector>\nusing namespace std;\n\
    using Graph = vector<vector<int>>;\n\nstruct LCA{\n  vector<vector<int>> parent;\n\
    \  vector<int> dist;\n  LCA(const Graph &G, int root=0){ init(G, root);}\n\n \
    \ void init(const Graph &G, int root=0){\n    int V = G.size();\n    int K = 1;\n\
    \    while((1<<K) < V) K++;\n    parent.assign(K, vector<int>(V, -1));\n    dist.assign(V,\
    \ -1);\n    dfs(G, root, -1, 0);\n    for(int k=0; k+1<K;k++){\n      for(int\
    \ v = 0; v<V;v++){\n        if(parent[k][v] < 0){\n          parent[k+1][v] =\
    \ -1;\n        }else{\n          parent[k+1][v] = parent[k][parent[k][v]];\n \
    \       }\n      }\n    }\n  }\n\n  // \u6839\u304B\u3089\u306E\u8DDD\u96E2\u3068\
    \u3072\u3068\u3064\u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\n  void dfs(const\
    \ Graph &G, int v, int p, int d){\n    parent[0][v] = p;\n    dist[v] = d;\n \
    \   for(auto nx : G[v]){\n      if(nx != p) dfs(G, nx, v, d+1);\n    }\n  }\n\n\
    \  int query(int u, int v){\n    if(dist[u] < dist[v]) swap(u, v);\n    int K\
    \ = parent.size();\n    for(int k=0; k<K;k++){\n      if((dist[u] - dist[v]) >>\
    \ k & 1){\n        u = parent[k][u];\n      }\n    }\n    if(u == v) return u;\n\
    \    for(int k=K-1;k>=0; k--){\n      if(parent[k][u] != parent[k][v]){\n    \
    \    u = parent[k][u];\n        v = parent[k][v];\n      }\n    }\n    return\
    \ parent[0][u];\n  }\n\n  int get_dist(int u, int v){\n    int p = query(u, v);\n\
    \    return dist[u] + dist[v] - 2 * dist[p];\n  }\n};\n\n"
  code: "#ifndef LCA_HPP\n#define LCA_HPP\n#include<vector>\nusing namespace std;\n\
    using Graph = vector<vector<int>>;\n\nstruct LCA{\n  vector<vector<int>> parent;\n\
    \  vector<int> dist;\n  LCA(const Graph &G, int root=0){ init(G, root);}\n\n \
    \ void init(const Graph &G, int root=0){\n    int V = G.size();\n    int K = 1;\n\
    \    while((1<<K) < V) K++;\n    parent.assign(K, vector<int>(V, -1));\n    dist.assign(V,\
    \ -1);\n    dfs(G, root, -1, 0);\n    for(int k=0; k+1<K;k++){\n      for(int\
    \ v = 0; v<V;v++){\n        if(parent[k][v] < 0){\n          parent[k+1][v] =\
    \ -1;\n        }else{\n          parent[k+1][v] = parent[k][parent[k][v]];\n \
    \       }\n      }\n    }\n  }\n\n  // \u6839\u304B\u3089\u306E\u8DDD\u96E2\u3068\
    \u3072\u3068\u3064\u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\n  void dfs(const\
    \ Graph &G, int v, int p, int d){\n    parent[0][v] = p;\n    dist[v] = d;\n \
    \   for(auto nx : G[v]){\n      if(nx != p) dfs(G, nx, v, d+1);\n    }\n  }\n\n\
    \  int query(int u, int v){\n    if(dist[u] < dist[v]) swap(u, v);\n    int K\
    \ = parent.size();\n    for(int k=0; k<K;k++){\n      if((dist[u] - dist[v]) >>\
    \ k & 1){\n        u = parent[k][u];\n      }\n    }\n    if(u == v) return u;\n\
    \    for(int k=K-1;k>=0; k--){\n      if(parent[k][u] != parent[k][v]){\n    \
    \    u = parent[k][u];\n        v = parent[k][v];\n      }\n    }\n    return\
    \ parent[0][u];\n  }\n\n  int get_dist(int u, int v){\n    int p = query(u, v);\n\
    \    return dist[u] + dist[v] - 2 * dist[p];\n  }\n};\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: graph/lca.hpp
  requiredBy: []
  timestamp: '2022-07-06 11:46:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/lca.aoj_GRL_5_C.test.cpp
documentation_of: graph/lca.hpp
layout: document
title: LCA (Lowerst Common Ancestor)
---

共通祖先のノードをダブリングで $O(\log N)$で求めるアルゴリズム

## ポイント

- dfs で一つ上の親を parent[0][v]で求めて、ダブリングで$2^{k}$ の距離の親を parent[k][v]に用意する。
- query では u, v が同じ高さになるまで調整して、u と v が異なるギリギリのところまで二分探索で親をたどっていく。
- https://algo-logic.info/lca/
