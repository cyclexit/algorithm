#include <bits/stdc++.h>

using namespace std;

// This class is to compute the length of the longest common subsequence of 
// two strings.
//
// This solution uses the bottom-up dp method to solve the problem.
// 
// Let N = s1.size(), M = s2.size()
// Time Complexity: O(N * M)
// Space Complexity: O(M)
class LCS {
 private:
  string s1, s2;
  vector<int> prev;
  vector<int> cur;
 public:
  LCS() = default;
  LCS(string _s1, string _s2) : s1(_s1), s2(_s2) {
    prev.resize(s2.size() + 1, 0);
    cur.resize(s2.size() + 1, 0);
  }

  int solve() {
    for (int i = 0; i < s1.size(); ++i) {
      for (int j = 0; j < s2.size(); ++j) {
        if (s1[i] == s2[j]) {
          cur[j + 1] = 1 + prev[j];
        } else {
          cur[j + 1] = max(prev[j + 1], cur[j]);
        }
      }
      swap(cur, prev);
    }
    return prev[s2.size()];
    // for (int i = s1.size() - 1; i >= 0; --i) {
    //   for (int j = s2.size() - 1; j >= 0; --j) {
    //     if (s1[i] == s2[j]) {
    //       cur[j] = 1 + prev[j + 1];
    //     } else {
    //       cur[j] = max(prev[j], cur[j + 1]);
    //     }
    //   }
    //   swap(cur, prev);
    // }
    // return prev[0];
  }
};