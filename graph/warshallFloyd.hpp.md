---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/warshallFloyd.aoj_GRL_1_C.test.cpp
    title: test/graph/warshallFloyd.aoj_GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/warshallFloyd.hpp\"\n#include<vector>\n#include<limits>\n\
    using namespace std;\n\ntemplate <typename T>\nvoid warshall_floyd(vector<vector<T>>\
    \ & dp){\n  // dp\u306F\u96A3\u63A5\u884C\u5217\u3002dp[i][i] = 0\u3067\u3042\u308B\
    \n  // \u7D50\u679C\u306Edp[i][i]\u306B\u8CA0\u304C\u5165\u3063\u3066\u3044\u305F\
    \u3089\u8CA0\u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u3002\n  T INF =\
    \ numeric_limits<T>::max();\n  for(size_t k=0; k<dp.size(); k++){\n    for(size_t\
    \ i=0; i<dp.size(); i++){\n      for(size_t j=0; j<dp.size(); j++){\n        if(dp[i][k]\
    \ == INF || dp[k][j] == INF) continue;\n        dp[i][j] = min(dp[i][j], dp[i][k]\
    \ + dp[k][j]);\n      }\n    }\n  }\n}\n"
  code: "#pragma once\n#include<vector>\n#include<limits>\nusing namespace std;\n\n\
    template <typename T>\nvoid warshall_floyd(vector<vector<T>> & dp){\n  // dp\u306F\
    \u96A3\u63A5\u884C\u5217\u3002dp[i][i] = 0\u3067\u3042\u308B\n  // \u7D50\u679C\
    \u306Edp[i][i]\u306B\u8CA0\u304C\u5165\u3063\u3066\u3044\u305F\u3089\u8CA0\u306E\
    \u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u3002\n  T INF = numeric_limits<T>::max();\n\
    \  for(size_t k=0; k<dp.size(); k++){\n    for(size_t i=0; i<dp.size(); i++){\n\
    \      for(size_t j=0; j<dp.size(); j++){\n        if(dp[i][k] == INF || dp[k][j]\
    \ == INF) continue;\n        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);\n\
    \      }\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshallFloyd.hpp
  requiredBy: []
  timestamp: '2022-07-12 12:30:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/warshallFloyd.aoj_GRL_1_C.test.cpp
documentation_of: graph/warshallFloyd.hpp
layout: document
title: "Warshall Floyd (\u5168\u9802\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF)"
---

- $O(N^3)$で任意の2頂点の最短経路を求める。
- 動的計画法で実装されている。
- 木の場合はLCAを使えばクエリごとに$O(\log V)$で求められるので検討する。
- 辺が少なければ、全ての頂点でダイクストラ$(O(E\log V))$を検討する。
