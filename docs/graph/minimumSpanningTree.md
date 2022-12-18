---
title: Minimum Spanning Tree (Kruskal)
documentation_of: graph/maximumSpanningTree.hpp
---

## 概要

- 最小全域木を求めるアルゴリズム。
- $ O(E \log V)$
- 辺のソートに一番時間がかかる。
- あとは全ての辺を一度見るだけ。

## 実装のヒント

- 辺を小さい順に追加していく
- 閉路ができなければその辺は最小全域木の辺となる。
- 閉路の確認をUnion Find木で行う。

## 参考

- [Luzhiled's Library](https://ei1333.github.io/library/graph/mst/kruskal.hpp)
