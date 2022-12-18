#pragma once
#include "graph/graphTemplate.hpp"
#include "structure/unionFind.hpp"

template <typename T>
struct MinimumSpanningTree {
  T cost;
  Edges<T> edges;
};

template <typename T>
MinimumSpanningTree<T> kruskal(Edges<T> &edges, int V) {
  sort(begin(edges), end(edges),
       [](const Edge<T> &a, const Edge<T> &b) { return a.cost < b.cost; });
  UnionFind uf(V);
  T total = T();
  Edges<T> es;
  for (auto &e : edges) {
    if (uf.unite(e.from, e.to)) {
      es.emplace_back(e);
      total += e.cost;
    }
  }
  return {total, es};
}