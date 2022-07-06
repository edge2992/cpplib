---
title: LCA (Lowerst Common Ancestor)
documentation_of: graph/lca.hpp
---

共通祖先のノードをダブリングで $O(\log N)$で求めるアルゴリズム

## ポイント

- dfs で一つ上の親を parent[0][v]で求めて、ダブリングで$2^{k}$ の距離の親を parent[k][v]に用意する。
- query では u, v が同じ高さになるまで調整して、u と v が異なるギリギリのところまで二分探索で親をたどっていく。
- https://algo-logic.info/lca/
