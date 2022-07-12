---
title: Warshall Floyd (全頂点対最短経路)
documentation_of: graph/warshallFloyd.hpp
---

- $O(N^3)$で任意の2頂点の最短経路を求める。
- 動的計画法で実装されている。
- 木の場合はLCAを使えばクエリごとに$O(\log V)$で求められるので検討する。
- 辺が少なければ、全ての頂点でダイクストラ$(O(E\log V))$を検討する。
