---
title: SCC (Sstrongly Connected Components)
documentation_of: graph/scc.hpp
---

- 有向グラフを強連結成分分解する
- $O(E + V)$

## ポイント

- DFSして、帰りがけに頂点番号をつける
  - 上流のほうが下流よりも番号が大きい
- 逆グラフで頂点の大きい順にDFSする。
  - DAGのトポロジカルソート順の順番なので、逆グラフではDAGの下流には影響しない。
- 同じ連結成分に属するのであれば一回のDFSで辿れるはず。
- [](https://pione.hatenablog.com/entry/2021/03/11/232159)
