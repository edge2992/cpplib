#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include <iostream>
#include <vector>
#include <climits>
#include "graph/warshallFloyd.hpp"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Int long long


int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<Int>> dp(V + 1, vector<Int>(V + 1, LLONG_MAX));
  int s, t, w;
  rep(_, E) {
    cin >> s >> t >> w;
    dp[s][t] = w;
  }
  rep(i, V) { dp[i][i] = 0; }
  warshall_floyd(dp);
  rep(i, V) {
    if (dp[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  rep(i, V) {
    rep(j, V) {
      if (dp[i][j] == LLONG_MAX) {
        cout << "INF";
      } else {
        cout << dp[i][j];
      }
      if (j != V - 1) {
        cout << " ";
      } else {
        cout << endl;
      }
    }
  }
}