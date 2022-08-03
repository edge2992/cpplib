---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\n#include <vector>\nusing namespace std;\n\
    \ntemplate <typename T>\nstruct mat {\n  // \u884C\u5217m\n  vector<vector<T>>\
    \ m;\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF:\u7B2C1\u5F15\u6570\u21D2\
    \u884C\u6570\u3001\u7B2C2\u5F15\u6570\u21D2\u5217\u6570\u3001\u7B2C3\u5F15\u6570\
    \u21D2\u521D\u671F\u5024\n  mat() : m(vector<vector<T>>()) {}\n  mat(int h, int\
    \ w) : m(vector<vector<T>>(h, vector<T>(w))) {}\n  mat(int h, int w, T d) : m(vector<vector<T>>(h,\
    \ vector<T>(w, d))) {}\n  // \u6DFB\u5B57\u6F14\u7B97\u5B50\n  vector<T> operator[](const\
    \ int i) const { return m[i]; }  //\u8AAD\u307F\u53D6\u308A\n  vector<T>& operator[](const\
    \ int i) { return m[i]; }       //\u66F8\u304D\u8FBC\u307F\n  // \u884C\u6570\u30FB\
    \u5217\u6570\n  int nrow = (int)m.size();\n  int ncol = (int)m[0].size();\n  //\
    \ \u884C\u5217\u540C\u58EB\u306E\u6F14\u7B97\n  mat& operator=(const mat& a) {\
    \ return *a; }\n  mat& operator+=(const mat& a) {\n    assert(ncol == a.ncol &&\
    \ nrow == a.nrow);\n    rep(i, nrow) rep(j, ncol) m[i][j] += a[i][j];\n    return\
    \ *this;\n  }\n  mat& operator-=(const mat& a) {\n    assert(ncol == a.ncol &&\
    \ nrow == a.nrow);\n    rep(i, nrow) rep(j, ncol) m[i][j] -= a[i][j];\n    return\
    \ *this;\n  }\n  mat& operator*=(const mat& a) {\n    assert(ncol == a.nrow);\n\
    \    mat<T> m2(nrow, a.ncol, 0);\n    rep(i, nrow) rep(j, a.ncol) rep(k, ncol)\
    \ m2[i][j] += m[i][k] * a[k][j];\n    ncol = a.ncol;\n    rep(i, nrow) m[i].resize(ncol);\n\
    \    rep(i, nrow) rep(j, ncol) m[i][j] = m2[i][j];\n    return *this;\n  }\n \
    \ mat operator+(const mat& a) const { return mat(*this) += a; }\n  mat operator-(const\
    \ mat& a) const { return mat(*this) -= a; }\n  mat operator*(const mat& a) const\
    \ { return mat(*this) *= a; }\n  bool operator==(const mat& a) {\n    assert(ncol\
    \ == a.ncol && nrow == a.nrow);\n    bool flg = true;\n    rep(i, nrow) rep(j,\
    \ ncol) if (m[i][j] != a[i][j]) flg = false;\n    return flg;\n  }\n  // \u884C\
    \u5217\u3068\u30B9\u30AB\u30E9\u306E\u6F14\u7B97\n  mat& operator+=(const T& a)\
    \ {\n    rep(i, nrow) rep(j, ncol) m[i][j] += a;\n    return *this;\n  }\n  mat&\
    \ operator-=(const T& a) {\n    rep(i, nrow) rep(j, ncol) m[i][j] -= a;\n    return\
    \ *this;\n  }\n  mat& operator*=(const T& a) {\n    rep(i, nrow) rep(j, ncol)\
    \ m[i][j] *= a;\n    return *this;\n  }\n  mat& operator/=(const T& a) {\n   \
    \ rep(i, nrow) rep(j, ncol) m[i][j] /= a;\n    return *this;\n  }\n  mat operator+(const\
    \ T& a) const { return mat(*this) += a; }\n  mat operator-(const T& a) const {\
    \ return mat(*this) -= a; }\n  mat operator*(const T& a) const { return mat(*this)\
    \ *= a; }\n  mat operator/(const T& a) const { return mat(*this) /= a; }\n  //\
    \ \u56DE\u8EE2\uFF08deg\u306E\u6570\u3060\u3051\u6642\u8A08\u56DE\u308A\u306B\
    90\u5EA6\u56DE\u8EE2\uFF09\n  mat& rot(int deg) {\n    mat<T> m2(ncol, nrow);\n\
    \    if (deg == 1 || deg == 3) {\n      if (deg == 1) rep(i, nrow) rep(j, ncol)\
    \ m2[j][nrow - i - 1] = m[i][j];\n      if (deg == 3) rep(i, nrow) rep(j, ncol)\
    \ m2[ncol - j - 1][i] = m[i][j];\n      swap(ncol, nrow);  // \u5217\u6570\u3068\
    \u884C\u6570\u3092\u5165\u308C\u66FF\u3048\u308B\n      m.resize(nrow);\n    \
    \  rep(i, nrow) m[i].resize(ncol);  //\u30EA\u30B5\u30A4\u30BA\n    }\n    if\
    \ (deg == 2)\n      rep(i, nrow) rep(j, ncol) m2[nrow - i - 1][ncol - j - 1] =\
    \ m[i][j];\n    rep(i, nrow) rep(j, ncol) m[i][j] = m2[i][j];\n    return *this;\n\
    \  }\n  // \u6A19\u6E96\u51FA\u529B\n  void show() {\n    rep(i, nrow) rep(j,\
    \ ncol) {\n      if (j != 0) cout << \" \";\n      cout << m[i][j];\n      if\
    \ (j == ncol - 1) cout << endl;\n    }\n    return;\n  }\n};\n"
  code: "#include <vector>\nusing namespace std;\n\ntemplate <typename T>\nstruct\
    \ mat {\n  // \u884C\u5217m\n  vector<vector<T>> m;\n  // \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF:\u7B2C1\u5F15\u6570\u21D2\u884C\u6570\u3001\u7B2C2\u5F15\u6570\
    \u21D2\u5217\u6570\u3001\u7B2C3\u5F15\u6570\u21D2\u521D\u671F\u5024\n  mat() :\
    \ m(vector<vector<T>>()) {}\n  mat(int h, int w) : m(vector<vector<T>>(h, vector<T>(w)))\
    \ {}\n  mat(int h, int w, T d) : m(vector<vector<T>>(h, vector<T>(w, d))) {}\n\
    \  // \u6DFB\u5B57\u6F14\u7B97\u5B50\n  vector<T> operator[](const int i) const\
    \ { return m[i]; }  //\u8AAD\u307F\u53D6\u308A\n  vector<T>& operator[](const\
    \ int i) { return m[i]; }       //\u66F8\u304D\u8FBC\u307F\n  // \u884C\u6570\u30FB\
    \u5217\u6570\n  int nrow = (int)m.size();\n  int ncol = (int)m[0].size();\n  //\
    \ \u884C\u5217\u540C\u58EB\u306E\u6F14\u7B97\n  mat& operator=(const mat& a) {\
    \ return *a; }\n  mat& operator+=(const mat& a) {\n    assert(ncol == a.ncol &&\
    \ nrow == a.nrow);\n    rep(i, nrow) rep(j, ncol) m[i][j] += a[i][j];\n    return\
    \ *this;\n  }\n  mat& operator-=(const mat& a) {\n    assert(ncol == a.ncol &&\
    \ nrow == a.nrow);\n    rep(i, nrow) rep(j, ncol) m[i][j] -= a[i][j];\n    return\
    \ *this;\n  }\n  mat& operator*=(const mat& a) {\n    assert(ncol == a.nrow);\n\
    \    mat<T> m2(nrow, a.ncol, 0);\n    rep(i, nrow) rep(j, a.ncol) rep(k, ncol)\
    \ m2[i][j] += m[i][k] * a[k][j];\n    ncol = a.ncol;\n    rep(i, nrow) m[i].resize(ncol);\n\
    \    rep(i, nrow) rep(j, ncol) m[i][j] = m2[i][j];\n    return *this;\n  }\n \
    \ mat operator+(const mat& a) const { return mat(*this) += a; }\n  mat operator-(const\
    \ mat& a) const { return mat(*this) -= a; }\n  mat operator*(const mat& a) const\
    \ { return mat(*this) *= a; }\n  bool operator==(const mat& a) {\n    assert(ncol\
    \ == a.ncol && nrow == a.nrow);\n    bool flg = true;\n    rep(i, nrow) rep(j,\
    \ ncol) if (m[i][j] != a[i][j]) flg = false;\n    return flg;\n  }\n  // \u884C\
    \u5217\u3068\u30B9\u30AB\u30E9\u306E\u6F14\u7B97\n  mat& operator+=(const T& a)\
    \ {\n    rep(i, nrow) rep(j, ncol) m[i][j] += a;\n    return *this;\n  }\n  mat&\
    \ operator-=(const T& a) {\n    rep(i, nrow) rep(j, ncol) m[i][j] -= a;\n    return\
    \ *this;\n  }\n  mat& operator*=(const T& a) {\n    rep(i, nrow) rep(j, ncol)\
    \ m[i][j] *= a;\n    return *this;\n  }\n  mat& operator/=(const T& a) {\n   \
    \ rep(i, nrow) rep(j, ncol) m[i][j] /= a;\n    return *this;\n  }\n  mat operator+(const\
    \ T& a) const { return mat(*this) += a; }\n  mat operator-(const T& a) const {\
    \ return mat(*this) -= a; }\n  mat operator*(const T& a) const { return mat(*this)\
    \ *= a; }\n  mat operator/(const T& a) const { return mat(*this) /= a; }\n  //\
    \ \u56DE\u8EE2\uFF08deg\u306E\u6570\u3060\u3051\u6642\u8A08\u56DE\u308A\u306B\
    90\u5EA6\u56DE\u8EE2\uFF09\n  mat& rot(int deg) {\n    mat<T> m2(ncol, nrow);\n\
    \    if (deg == 1 || deg == 3) {\n      if (deg == 1) rep(i, nrow) rep(j, ncol)\
    \ m2[j][nrow - i - 1] = m[i][j];\n      if (deg == 3) rep(i, nrow) rep(j, ncol)\
    \ m2[ncol - j - 1][i] = m[i][j];\n      swap(ncol, nrow);  // \u5217\u6570\u3068\
    \u884C\u6570\u3092\u5165\u308C\u66FF\u3048\u308B\n      m.resize(nrow);\n    \
    \  rep(i, nrow) m[i].resize(ncol);  //\u30EA\u30B5\u30A4\u30BA\n    }\n    if\
    \ (deg == 2)\n      rep(i, nrow) rep(j, ncol) m2[nrow - i - 1][ncol - j - 1] =\
    \ m[i][j];\n    rep(i, nrow) rep(j, ncol) m[i][j] = m2[i][j];\n    return *this;\n\
    \  }\n  // \u6A19\u6E96\u51FA\u529B\n  void show() {\n    rep(i, nrow) rep(j,\
    \ ncol) {\n      if (j != 0) cout << \" \";\n      cout << m[i][j];\n      if\
    \ (j == ncol - 1) cout << endl;\n    }\n    return;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2022-08-03 18:27:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
title: "Matrix (\u884C\u5217)"
---

## 概要

行列計算

## 実装のヒント

## 参考

- [競技プログラミング用にC++で行列（2次元平面）ライブラリを作成する](https://qiita.com/gnbrganchan/items/47118d45b3af9d5ae9a4)
