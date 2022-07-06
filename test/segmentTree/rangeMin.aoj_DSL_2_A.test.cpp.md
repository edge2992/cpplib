---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segmentTree/rangeMin.hpp
    title: Range Minimum Query
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/segmentTree/rangeMin.aoj_DSL_2_A.test.cpp\"\n#define\
    \ PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#line 1 \"segmentTree/rangeMin.hpp\"\n\n\n#include<vector>\n#include<algorithm>\n\
    using namespace std;\nclass rangeMin {\n public:\n  int size_ = 1;\n  vector<long\
    \ long> dat;\n\n  void init(int sz) {\n    while (size_ <= sz) size_ *= 2;\n \
    \   dat.resize(size_ * 2, 1LL << 60);\n  }\n  void update(int pos, long long x)\
    \ {\n    pos += size_;\n    dat[pos] = x;\n    while (pos /= 2) {\n      dat[pos]\
    \ = min(dat[pos * 2], dat[pos * 2 + 1]);\n    }\n  }\n  long long query_(int l,\
    \ int r, int a, int b, int u) {\n    if (l <= a && b <= r) return dat[u];\n  \
    \  if (r <= a || b <= l) return 1LL << 60;\n    int mid = (a + b) / 2;\n    long\
    \ long v1 = query_(l, r, a, mid, u * 2);\n    long long v2 = query_(l, r, mid,\
    \ b, u * 2 + 1);\n    return min(v1, v2);\n  }\n  long long query(int l, int r)\
    \ { return query_(l, r, 0, size_, 1); }\n};\n\n#line 5 \"test/segmentTree/rangeMin.aoj_DSL_2_A.test.cpp\"\
    \n#include <iostream>\n\nint main() {\n  int n, q, com, x, y;\n  cin >> n >> q;\n\
    \  rangeMin st;\n  st.init(n);\n  for (int i = 0; i < n; i++) {\n    st.update(i,\
    \ INT32_MAX);\n  }\n  for (int i = 0; i < q; i++) {\n    cin >> com >> x >> y;\n\
    \    if (com == 0) {\n      st.update(x, y);\n    } else {\n      cout << st.query(x,\
    \ y + 1) << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include \"../../segmentTree/rangeMin.hpp\"\n#include <iostream>\n\nint main()\
    \ {\n  int n, q, com, x, y;\n  cin >> n >> q;\n  rangeMin st;\n  st.init(n);\n\
    \  for (int i = 0; i < n; i++) {\n    st.update(i, INT32_MAX);\n  }\n  for (int\
    \ i = 0; i < q; i++) {\n    cin >> com >> x >> y;\n    if (com == 0) {\n     \
    \ st.update(x, y);\n    } else {\n      cout << st.query(x, y + 1) << endl;\n\
    \    }\n  }\n}"
  dependsOn:
  - segmentTree/rangeMin.hpp
  isVerificationFile: true
  path: test/segmentTree/rangeMin.aoj_DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2022-07-06 11:58:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segmentTree/rangeMin.aoj_DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/segmentTree/rangeMin.aoj_DSL_2_A.test.cpp
- /verify/test/segmentTree/rangeMin.aoj_DSL_2_A.test.cpp.html
title: test/segmentTree/rangeMin.aoj_DSL_2_A.test.cpp
---
