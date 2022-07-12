---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/warshallFloyd.hpp
    title: "Warshall Floyd (\u5168\u9802\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/graph/warshallFloyd.aoj_GRL_1_C.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include <iostream>\n#include <vector>\n#include <climits>\n#line 3 \"graph/warshallFloyd.hpp\"\
    \n#include<limits>\nusing namespace std;\n\ntemplate <typename T>\nvoid warshall_floyd(vector<vector<T>>\
    \ & dp){\n  // dp\u306F\u96A3\u63A5\u884C\u5217\u3002dp[i][i] = 0\u3067\u3042\u308B\
    \n  // \u7D50\u679C\u306Edp[i][i]\u306B\u8CA0\u304C\u5165\u3063\u3066\u3044\u305F\
    \u3089\u8CA0\u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u3002\n  T INF =\
    \ numeric_limits<T>::max();\n  for(size_t k=0; k<dp.size(); k++){\n    for(size_t\
    \ i=0; i<dp.size(); i++){\n      for(size_t j=0; j<dp.size(); j++){\n        if(dp[i][k]\
    \ == INF || dp[k][j] == INF) continue;\n        dp[i][j] = min(dp[i][j], dp[i][k]\
    \ + dp[k][j]);\n      }\n    }\n  }\n}\n#line 6 \"test/graph/warshallFloyd.aoj_GRL_1_C.test.cpp\"\
    \nusing namespace std;\n#define rep(i, n) for (int i = 0; i < (int)(n); i++)\n\
    #define Int long long\n\n\nint main() {\n  int V, E;\n  cin >> V >> E;\n  vector<vector<Int>>\
    \ dp(V + 1, vector<Int>(V + 1, LLONG_MAX));\n  int s, t, w;\n  rep(_, E) {\n \
    \   cin >> s >> t >> w;\n    dp[s][t] = w;\n  }\n  rep(i, V) { dp[i][i] = 0; }\n\
    \  warshall_floyd(dp);\n  rep(i, V) {\n    if (dp[i][i] < 0) {\n      cout <<\
    \ \"NEGATIVE CYCLE\" << endl;\n      return 0;\n    }\n  }\n  rep(i, V) {\n  \
    \  rep(j, V) {\n      if (dp[i][j] == LLONG_MAX) {\n        cout << \"INF\";\n\
    \      } else {\n        cout << dp[i][j];\n      }\n      if (j != V - 1) {\n\
    \        cout << \" \";\n      } else {\n        cout << endl;\n      }\n    }\n\
    \  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include <iostream>\n#include <vector>\n#include <climits>\n#include \"graph/warshallFloyd.hpp\"\
    \nusing namespace std;\n#define rep(i, n) for (int i = 0; i < (int)(n); i++)\n\
    #define Int long long\n\n\nint main() {\n  int V, E;\n  cin >> V >> E;\n  vector<vector<Int>>\
    \ dp(V + 1, vector<Int>(V + 1, LLONG_MAX));\n  int s, t, w;\n  rep(_, E) {\n \
    \   cin >> s >> t >> w;\n    dp[s][t] = w;\n  }\n  rep(i, V) { dp[i][i] = 0; }\n\
    \  warshall_floyd(dp);\n  rep(i, V) {\n    if (dp[i][i] < 0) {\n      cout <<\
    \ \"NEGATIVE CYCLE\" << endl;\n      return 0;\n    }\n  }\n  rep(i, V) {\n  \
    \  rep(j, V) {\n      if (dp[i][j] == LLONG_MAX) {\n        cout << \"INF\";\n\
    \      } else {\n        cout << dp[i][j];\n      }\n      if (j != V - 1) {\n\
    \        cout << \" \";\n      } else {\n        cout << endl;\n      }\n    }\n\
    \  }\n}"
  dependsOn:
  - graph/warshallFloyd.hpp
  isVerificationFile: true
  path: test/graph/warshallFloyd.aoj_GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2022-07-12 12:30:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/warshallFloyd.aoj_GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/graph/warshallFloyd.aoj_GRL_1_C.test.cpp
- /verify/test/graph/warshallFloyd.aoj_GRL_1_C.test.cpp.html
title: test/graph/warshallFloyd.aoj_GRL_1_C.test.cpp
---
