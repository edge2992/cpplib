---
title: BIT (Binary Indexed Tree)
documentation_of: structure/bit.hpp
---

## 概要

- 1-indexにして閉区間で考える

## 実装のヒント

- (ind & -ind) で最後の区間を求めて足し引きをする。
- 足し算は木の親をたどる。
- 引き算は深さ優先探索の帰りがけ順の前の区間に移動する。

## 参考

- [スライド](http://hos.ac/slides/20140319_bit.pdf)
- [かつっぱEDPC Q](https://www.youtube.com/watch?v=kEkvTR-guyg&t=603s)
