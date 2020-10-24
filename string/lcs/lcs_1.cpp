#include <bits/stdc++.h>

using namespace std;

// These two functions use the top-down method to compute the length of LCS of two strings.
// Time Complexity: O(N * M^2)
// Space Complexity: O(N * M)

// This one is less efficienct, but easier to understand.
int lcs(string& s1, string& s2) {
  int n = s1.size(), m = s2.size();
  if (n == 0 || m == 0) {
    return 0;
  }
  int j = 0;
  while (j < m && s2[j] != s1[0]) {
    ++j;
  }
  // case 1: s1[0] is not in the optimal solution
  string s1_sub = s1.substr(1);
  int res1 = lcs(s1_sub, s2);
  int res2 = 0;
  if (j < m) {
    // case 2: s1[0] is in the optimal solution
    string s2_sub = s2.substr(j + 1);
    res2 = 1 + lcs(s1_sub, s2_sub);
  }
  return max(res1, res2);
}

// This one is more efficient, since this one does not create new string during the recursive.
int lcs(string& s1, int p1, string& s2, int p2) {
  int n = s1.size(), m = s2.size();
  if (n == p1 || m == p2) {
    return 0;
  }
  int j = p2;
  while (j < m && s2[j] != s1[p1]) {
    ++j;
  }
  // case 1: s1[0] is not in the optimal solution
  int res1 = lcs(s1, p1 + 1, s2, p2);
  int res2 = 0;
  if (j < m) {
    // case 2: s1[0] is in the optimal solution
    res2 = 1 + lcs(s1, p1 + 1, s2, j + 1);
  }
  return max(res1, res2);
}