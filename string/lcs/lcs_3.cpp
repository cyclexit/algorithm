#include <bits/stdc++.h>

using namespace std;

// This class is to compute the length of the longest common subsequence of 
// two strings.
//
// This solution uses the bottom-up dp method to solve the problem.
// 
// Let N = s1.size(), M = s2.size()
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
class LCS {
 private:
  string s1, s2;
 public:
  vector<vector<int>> dp;
  LCS() = default;
  LCS(string _s1, string _s2) : s1(_s1), s2(_s2) {
    dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, 0));
  }

  int solve() {
    // for (int i = 0; i < s1.size(); ++i) {
    //   for (int j = 0; j < s2.size(); ++j) {
    //     if (s1[i] == s2[j]) {
    //       dp[i + 1][j + 1] = 1 + dp[i][j];
    //     } else {
    //       dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    //     }
    //   }
    // }
    // return dp[s1.size()][s2.size()];
    for (int i = s1.size() - 1; i >= 0; --i) {
      for (int j = s2.size() - 1; j >= 0; --j) {
        if (s1[i] == s2[j]) {
          dp[i][j] = 1 + dp[i + 1][j + 1];
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
      }
    }
    return dp[0][0];
  }

  string build_lcs() {
    // string res = "";
    // int i = s1.size(), j = s2.size();
    // while (i && j && dp[i][j]) {
    //   if (s1[i - 1] == s2[j - 1]) {
    //     res.push_back(s1[i - 1]);
    //     --i;
    //     --j;
    //   } else {
    //     if (dp[i - 1][j] == dp[i][j]) {
    //       --i;
    //     } else if (dp[i][j - 1] == dp[i][j]) {
    //       --j;
    //     } else {
    //       --i;
    //       --j;
    //     }
    //   }
    // }
    // reverse(res.begin(), res.end());
    // return res;
    string res = "";
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size() && dp[i][j]) {
      if (s1[i] == s2[j]) {
        res.push_back(s1[i]);
        ++i;
        ++j;
      } else {
        if (dp[i + 1][j] == dp[i][j]) {
          ++i;
        } else if (dp[i][j + 1] == dp[i][j]) {
          ++j;
        } else {
          ++i;
          ++j;
        }
      }
    }
    return res;
  }
};