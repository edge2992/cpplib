---
title: Union Find
documentation_of: structure/unionFind.hpp
---

# UnionFind

- 集合を効率よく扱うためのライブラリ
- 集合の合併、どの集合に属しているかを調べることができる。
- 有向グラフの場合SCCを使うことを検討する。

## テンプレート

- ルートのdataには集合サイズの-1、ルート以外のdataにはその集合のルートが入る(最終的に）
- uniteはもともとルートだった場所のdataしか変更しないので, findでルートをたどりながら、dataの更新を行う。
- groupsはそれぞれの集合のベクトルを返す.
