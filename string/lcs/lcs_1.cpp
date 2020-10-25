#include <bits/stdc++.h>

using namespace std;

// This class is to compute the length of the longest common subsequence of 
// two strings.
//
// I use the memorization technique to improve the efficiency. This solution
// also involve the dynamic programming methodology.
// 
// Let N = s1.size(), M = s2.size()
// Time Complexity: O(N * M^2)
// Space Complexity: O(N * M^2)
class LCS {
 private:
  string s1, s2;
  vector<vector<int>> memo;
 public:
  LCS() = default;
  LCS(string _s1, string _s2) : s1(_s1), s2(_s2) {
    memo.resize(s1.size(), vector<int>(s2.size(), -1));
  }

  int solve(int p1, int p2) {
    if (p1 == s1.size() || p2 == s2.size()) {
      return 0;
    }
    if (memo[p1][p2] != -1) {
      return memo[p1][p2];
    }

    int j = p2;
    while (j < s2.size() && s2[j] != s1[p1]) {
      ++j;
    }
    int res1 = solve(p1 + 1, p2);
    int res2 = 0;
    if (j < s2.size()) {
      res2 = 1 + solve(p1 + 1, j + 1);
    }

    return memo[p1][p2] = max(res1, res2);
  }
};