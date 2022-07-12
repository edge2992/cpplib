#pragma once
#include<vector>
#include<limits>
using namespace std;

template <typename T>
void warshall_floyd(vector<vector<T>> & dp){
  // dpは隣接行列。dp[i][i] = 0である
  // 結果のdp[i][i]に負が入っていたら負の閉路が存在する。
  T INF = numeric_limits<T>::max();
  for(size_t k=0; k<dp.size(); k++){
    for(size_t i=0; i<dp.size(); i++){
      for(size_t j=0; j<dp.size(); j++){
        if(dp[i][k] == INF || dp[k][j] == INF) continue;
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
}
