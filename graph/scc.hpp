#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>

#include "graph/graphTemplate.hpp"
using namespace std;

template <typename T = int>
struct SCC {
public:
  int n;
  Graph<T> G;
  vector<int> component;
  SCC(Graph<T> &_G) {
    n = _G.size();
    G = _G;
    build();
  }

  void build() {
    rG = Graph(n);
    for(size_t i =0;i<n;i++){
      for(auto &e: G[i]) {
        rG.add_directed_edge(e.to, e.from, e.cost);
      }
    }
    component.assign(n, -1);
    used.assign(n, false);
    for (size_t v = 0; v < n; v++)
      if (!used[v]) dfs(v);
    reverse(order.begin(), order.end());
    int k = 0;
    for (auto v : order)
      if (component[v] == -1) rdfs(v, k), k++;
  }

  bool is_same(int u, int v) { return component[u] == component[v]; }

  long long count_pair() {
    unordered_map<int, long long> value_counts;
    for (int k : component) {
      value_counts[k]++;
    }
    long long ans = 0;
    for (auto x : value_counts) {
      ans += x.second * (x.second - 1) / 2;
    }
    return ans;
  }

private:
  Graph<T> rG;
  vector<int> order;
  vector<bool> used;

  void dfs(int v) {
    used[v] = 1;
    for (auto nv : G[v]) {
      if (!used[nv]) dfs(nv);
    }
    order.push_back(v);
  }

  void rdfs(int v, int k) {
    component[v] = k;
    for (auto nv : rG[v]) {
      if (component[nv] < 0) rdfs(nv, k);
    }
  }
};