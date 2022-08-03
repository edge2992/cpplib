---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/bit.hpp
    title: BIT (Binary Indexed Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/structure/BIT.aoj_DSL_2_B.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n\n#include\
    \ <iostream>\n#line 2 \"structure/bit.hpp\"\n#include <vector>\n\n\ntemplate <typename\
    \ T>\nstruct BIT {\n    int N;\n    std::vector<T> bit;\n    BIT(size_t sz) :\
    \ N(sz + 2), bit(N, 0) {}\n\n    void add(int i, T x){\n        for(int idx =\
    \ i; idx <= N; idx += idx & -idx){\n            bit[idx] += x;\n        }\n  \
    \  }\n\n    T sum(int i){\n        T ret = 0;\n        for(int idx = i; idx >\
    \ 0; idx -= idx & -idx){\n            ret += bit[idx];\n        }\n        return\
    \ ret;\n    }\n};\n#line 5 \"test/structure/BIT.aoj_DSL_2_B.test.cpp\"\n\nint\
    \ main(){\n    int N, Q;\n    std::cin >> N >> Q;\n    BIT<long long> bt(N);\n\
    \    for(int i=0; i<Q; i++){\n        int com, x, y;\n        std::cin >> com\
    \ >> x >> y;\n        if(com == 0){\n            bt.add(x, y);\n        }else{\n\
    \            std::cout << bt.sum(y) - bt.sum(x-1) << std::endl;\n        }\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <iostream>\n#include \"structure/bit.hpp\"\n\nint main(){\n    int\
    \ N, Q;\n    std::cin >> N >> Q;\n    BIT<long long> bt(N);\n    for(int i=0;\
    \ i<Q; i++){\n        int com, x, y;\n        std::cin >> com >> x >> y;\n   \
    \     if(com == 0){\n            bt.add(x, y);\n        }else{\n            std::cout\
    \ << bt.sum(y) - bt.sum(x-1) << std::endl;\n        }\n    }\n}"
  dependsOn:
  - structure/bit.hpp
  isVerificationFile: true
  path: test/structure/BIT.aoj_DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2022-08-03 17:09:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/BIT.aoj_DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/structure/BIT.aoj_DSL_2_B.test.cpp
- /verify/test/structure/BIT.aoj_DSL_2_B.test.cpp.html
title: test/structure/BIT.aoj_DSL_2_B.test.cpp
---
