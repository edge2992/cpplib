---
title: Dijkstra (単一始点最短経路)
documentation_of: graph/dijkstra.hpp
---

## 概要

- 負辺のないグラフで単一始点最短経路を求めるアルゴリズム
- ShortestPath の from にはその頂点に到達する直前の頂点が格納され、id には直前の辺の id が格納される。
- $O(E\log V)$

## 実装のヒント

- priority_que で距離が短い順に処理する
- すでに小さいコストで到達できる経路が確認できている場合はスキップする
- priority_que には、すでに短い距離で訪れている頂点を追加しないようにする

[](https://ei1333.github.io/library/graph/shortest-path/dijkstra.hpp)
