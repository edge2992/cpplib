---
title: Union Find
documentation_of: structure/unionFind.hpp
---

## UnionFind

- 集合を効率よく扱うためのライブラリ
- 集合の合併、どの集合に属しているかを調べることができる。
- 有向グラフの場合 SCC を使うことを検討する。

## 実装ヒント

- ルートの data には集合サイズの-1、ルート以外の data にはその集合のルートが入る(最終的に）
- unite はもともとルートだった場所の data しか変更しないので, find でルートをたどりながら、data の更新を行う。
- groups はそれぞれの集合のベクトルを返す.
